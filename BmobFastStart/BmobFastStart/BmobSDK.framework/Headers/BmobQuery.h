//
//  BmobQuery.h
//  BmobSDK
//
//  Created by Bmob on 13-8-1.
//  Copyright (c) 2013年 Bmob. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BmobObject.h"
#import "BmobConfig.h"
#import "BmobGeoPoint.h"

@interface BmobQuery : NSObject





/**
 *	限制得到多少个结果
 */
@property (nonatomic) NSInteger limit;

/**
 *	查询结果跳到第几个
 */
@property (nonatomic) NSInteger skip;

/**
 *	缓存策略
 */
@property(assign)BmobCachePolicy cachePolicy;

/**
 *	缓存有效时间
 */
@property (readwrite, assign) NSTimeInterval maxCacheAge;




/**
 *	查询对象
 *
 *	@param	className	对象名称（数据库表名）
 *
 *	@return	BmobQuery查询对象
 */
+(BmobQuery*)queryWithClassName:(NSString *)className;

/**
 *  查询用户表
 *
 *  @return BmobQuery查询对象
 */
+(BmobQuery*)queryForUser;

/**
 *	通过className初始化BmobQuery对象
 *
 *	@param	className	对象名称（数据库表名）
 *
 *	@return	BmobQuery查询对象
 */
-(id)initWithClassName:(NSString *)className;


#pragma mark 排序



/**
 *	按key进行升序排序
 *
 *	@param	key	列名
 */
- (void)orderByAscending:(NSString *)key ;

/**
 *	按key进行降序排序
 *
 *	@param	key	列名
 */
- (void)orderByDescending:(NSString *)key ;


#pragma mark 查询条件

/**
 *  添加需要返回类型的列名
 *
 *  @param key 列名
 */
- (void)includeKey:(NSString *)key;

/**
 *  设置查询后要返回的key
 *
 *  @param keys key数组
 */
-(void)selectKeys:(NSArray*)keys;

/**
 *	添加key的值等于object的约束条件
 *
 *	@param	key	键
 *	@param	object	提供的值
 */
- (void)whereKey:(NSString *)key equalTo:(id)object;

/**
 *	添加key的值不为object的约束条件
 *
 *	@param	key	键
 *	@param	object	提供的值
 */
- (void)whereKey:(NSString *)key notEqualTo:(id)object;


/**
 *	添加key的值大于object的约束条件
 *
 *	@param	key	键
 *	@param	object	提供的值
 */
- (void)whereKey:(NSString *)key greaterThan:(id)object;

/**
 *	添加key的值大于或等于提供的object的约束条件
 *
 *	@param	key	键
 *	@param	object	提供的值
 */
- (void)whereKey:(NSString *)key greaterThanOrEqualTo:(id)object;

/**
 *	添加key的值小于提供的object的约束条件
 *
 *	@param	key	键
 *	@param	object	提供的值
 */
- (void)whereKey:(NSString *)key lessThan:(id)object;

/**
 *	添加key的值小于或等于提供的object的约束条件
 *
 *	@param	key	键
 *	@param	object	提供的值
 */
- (void)whereKey:(NSString *)key lessThanOrEqualTo:(id)object;

/**
 *	添加key的值包含array的约束条件
 *
 *	@param	key	键
 *	@param	array	提供的数组
 */
- (void)whereKey:(NSString *)key containedIn:(NSArray *)array;

/**
 *	添加key的值不包含array的约束条件
 *
 *	@param	key	键
 *	@param	array	提供的数组
 */
- (void)whereKey:(NSString *)key notContainedIn:(NSArray *)array;

/**
 *  指定的key的值是存在的
 *
 *  @param key 键
 */
- (void)whereKeyExists:(NSString *)key;

/**
 *  指定的key的值是不存在的
 *
 *  @param key 键
 */
- (void)whereKeyDoesNotExist:(NSString *)key;

/**
 *  查询的对象某个列符合另一个查询
 *
 *  @param key   列名
 *  @param query 另一个查询
 */
- (void)whereKey:(NSString *)key matchesQuery:(BmobQuery *)query;

/**
 *  查询的对象某个列不符合另一个查询
 *
 *  @param key   列名
 *  @param query 另一个查询
 */
- (void)whereKey:(NSString *)key doesNotMatchQuery:(BmobQuery *)query;


/**
 *  获取object的关系成员的对象
 *
 *  @param key    object所在表的列名，为Relation类型
 *  @param object Bmobject对象
 */
- (void)whereObjectKey:(NSString *)key relatedTo:(BmobObject*)object;

#pragma mark 地理位置查询
/**
 *
 *
 *	@param	key	键
 *	@param	geopoint	位置信息
 */
- (void)whereKey:(NSString *)key nearGeoPoint:(BmobGeoPoint *)geopoint;

/**
 *
 *
 *	@param	key	键
 *	@param	geopoint	位置信息
 *	@param	maxDistance	最大长度（单位：英里）
 */
- (void)whereKey:(NSString *)key nearGeoPoint:(BmobGeoPoint *)geopoint withinMiles:(double)maxDistance;

/**
 *
 *
 *	@param	key	键
 *	@param	geopoint	位置信息
 *	@param	maxDistance	最大长度（单位：公里）
 */
- (void)whereKey:(NSString *)key nearGeoPoint:(BmobGeoPoint *)geopoint withinKilometers:(double)maxDistance;

/**
 *
 *  
 *	@param	key	键
 *	@param	geopoint	位置信息
 *	@param	maxDistance	最大半径
 */
- (void)whereKey:(NSString *)key nearGeoPoint:(BmobGeoPoint *)geopoint withinRadians:(double)maxDistance;


/**
 *
 *
 *	@param	key	键
 *	@param	southwest	西南方向位置
 *	@param	northeast	东北方向位置
 */
- (void)whereKey:(NSString *)key withinGeoBoxFromSouthwest:(BmobGeoPoint *)southwest toNortheast:(BmobGeoPoint *)northeast;

#pragma mark 组合查询
/**
 *  组合并查询
 *
 *  @param array 约束条件数组
 */
-(void)addTheConstraintByAndOperationWithArray:(NSArray*)array;


/**
 *  组合或查询
 *
 *  @param array 约束条件数组
 */
-(void)addTheConstraintByOrOperationWithArray:(NSArray *)array;





#pragma mark 缓存方面的函数

/**
 *	查看是否有查询的缓存
 *
 *	@return	查询结果 有为YES 没有为NO
 */
- (BOOL)hasCachedResult;

/**
 *	清理查询的缓存
 */
- (void)clearCachedResult;

/**
 *	清理所有查询的缓存
 */
+ (void)clearAllCachedResults;

#pragma mark 得到对象的函数

/**
 *	通过id查找BmobObject对象
 *
 *	@param	objectId	BmobObject对象的id
 *	@param	block	得到的BmobObject对象
 */
- (void)getObjectInBackgroundWithId:(NSString *)objectId
                              block:(BmobObjectResultBlock)block;

/**
 *	查找BmobObject对象数组
 *
 *	@param	block	得到BmobObject对象数组
 */
- (void)findObjectsInBackgroundWithBlock:(BmobObjectArrayResultBlock)block;


/**
 *	查找表中符合条件的个数
 *
 *	@param	block	得到个数
 */
- (void)countObjectsInBackgroundWithBlock:(BmobIntegerResultBlock)block;


@end
