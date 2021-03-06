//
//  NSArray+Collection.h
//  revo-retail
//
//  Created by Badchoice on 25/5/16.
//  Copyright © 2016 Revo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (Collection)

/**
 * @return NSArray with only the elements that pass the truth test
 */
- (NSArray*)filter:(BOOL (^)(id object))condition;

/**
 * @return NSArray removing the elements that pass the truth test
 */
- (NSArray*)reject:(BOOL (^)(id object))condition;

/**
 * @return id first object that passes the truth test or `nil` if any
 */
- (id)first:(BOOL (^)(id object))condition;

/**
 * @return id first object that passes the truth test or `defaultObject` if any passes
 */
- (id)first:(BOOL (^)(id object))condition default:(id)defaultObject;

/**
 * @return id last object that passes the truth test or `nil` if any
 */
- (id)last:(BOOL (^)(id))condition;

/**
 * @return id last object that passes the truth test or `defaultObject` if any passes
 */
- (id)last:(BOOL (^)(id object))condition default:(id)defaultObject;

/**
 * @return BOOL if any object passes the truth test
 */
- (BOOL)contains:(BOOL (^)(id object))checker;

/**
 * @return BOOL if no object passes the truth test
 */
- (BOOL)doesntContain:(BOOL (^)(id object))checker;

/**
 * @return NSArray elements where the keypath contains the value
 */
- (NSArray*)where:(NSString*)keypath like:(id)value;

/**
 * @return NSArray elements where the keypath is equal to the value
 */
- (NSArray*)where:(NSString*)keypath is:(id)value;

/**
 * @return NSArray elements where any of the keypaths is equal to the value
 */
- (NSArray*)whereAny:(NSArray*)keyPaths is:(id)value;

/**
 * @return NSArray elements where any of the keypaths is like the value
 */
- (NSArray*)whereAny:(NSArray*)keyPaths like:(id)value;


/**
 * performs the operation to each element
 * @return void
 */
- (void)each:(void(^)(id object))operation;

/**
 * performs the operation to each element
 * @return void
 */
- (void)eachWithIndex:(void(^)(id object, int index, BOOL *stop))operation;


/**
 * @return NSArray sorted using `compare` function of the elements
 */
- (NSArray*)sort;

/**
 * @return NSArray sorted ascending by the key values
 */
- (NSArray*)sort:(NSString*)key;

/**
 * @return NSArray sorted by the key values
 */
- (NSArray*)sort:(NSString*)key ascending:(BOOL)ascending;

/**
 * @return NSArray sorted using custom callback
 */
- (NSArray*)sortWith:(NSComparisonResult (^)(id a, id b))callback;


/**
 * @return NSArray reverted
 */
- (NSArray*)reverse;

/**
 * @return NSArray starting at howMany position
 */
- (NSArray*)slice   :(int)howMany;

/**
 * @return NSArray from [0 , howMany], if howMany is negative it returns [count - howMany , count]
 */
- (NSArray*)take    :(int)howMany;

/**
 * @return NSArray from [0 , howMany] and removes them from current array
 */
- (NSArray*)splice  :(int)howMany;

/**
 * @return new NSArray from the result of the block performed to each element
 */
- (NSArray*)map:(id (^)(id obj, NSUInteger idx))block;

/**
 * @return new NSArray by flatting it and performing a map to each element
 */
- (NSArray*)flatMap:(id (^)(id obj, NSUInteger idx))block;

/**
 * @return new NSArray by flatting it with the key and performing a map to each element
 */
- (NSArray*)flatMap:(NSString*)key block:(id (^)(id obj, NSUInteger idx))block;

/**
 * @return NSArray of all element.keyPath
 */
- (NSArray*)pluck:(NSString*)keyPath;

/**
 * @return NSDictionary of all element.keyPath with the key
 */
- (NSDictionary*)pluck:(NSString*)keyPath key:(NSString*)keyKeypath;

/**
 * @return NSArray removes one level of arrays so [[1,2,3],[4,5,6]] becomes [1,2,3,4,5,6]
 */
- (NSArray*)flatten;

/**
 * @return NSArray removes one level with key so [{"hola" => [1,2]},{"hola"=>[3,4]}] becomes [1,2,3,4]
 */
- (NSArray*)flatten:(NSString*)keypath;

/**
 * @return reduces the array to a single value, passing the result of each iteration into the subsequent iteration
 * initial carry value is `nil`
 */
- (id)reduce:(id(^)(id carry, id object))block;

/**
 * @return reduces the array to a single value, passing the result of each iteration into the subsequent iteration
 * initial carry value is `carry`
 */
- (id)reduce:(id(^)(id carry, id object))block carry:(id)carry;

/**
 * returns NSDictionary by grouping the array items by a given key:
 */
- (NSDictionary*)groupBy:(NSString*)keypath;

/**
 * returns NSDictionary by grouping the array items by a given key where the new diciontary key is the result of block:
 */
- (NSDictionary*)groupBy:(NSString*)keypath block:(NSString*(^)(id object, NSString* key))block;

/**
 * return NSDictionary copping to keypath all the elements of the keypath so
 *   [
 *       {"groups" => [1,2]   },
 *       {"groups" => [2,3,3] }
 *   ]
 *   becomes
 *   {
 *       1 => [
 *           {"groups" => [1,2]}
 *       ]
 *       2 => [
 *           {"groups" => [1,2]},
 *           {"groups" => [2,3,3]}
 *       ]
 *       3 => [
 *           {"groups" => [2,3,3]}
 *           {"groups" => [2,3,3]}
 *       ]
 *   }
 */
- (NSDictionary*)expand:(NSString*)keypath;

/**
 * return same as expand but with uniques test so dictionary doesn't have duplicated values
 */
- (NSDictionary*)expand:(NSString *)keypath unique:(BOOL)unique;

/**
 * Returns the greatests element in the array
 */
-(id)maxObject;

/**
 * Returns the greatests element.keypath in the array
 */
-(id)maxObject:(NSString*)keypath;

/**
 * Returns the greatests element in the array
 */
-(id)minObject;

/**
 * Returns the greatests element.keypath in the array
 */
-(id)minObject:(NSString*)keypath;


/**
 *zip lets you take one collection, and pair every element in that collection with the
 *corresponding element in another collection.*/
-(NSArray*)zip:(NSArray*)other;

/**
 * Associates 
 */
-(NSDictionary*)mapToAssoc:(NSArray*(^)(id obj, NSUInteger idx))block;

/**
 * Convenience method for creating the counted set
 */
-(NSCountedSet*)countedSet;

/** 
 * Returns an string concatedated with delimiter
 */
-(NSString*)implode:(NSString*)delimiter;


#pragma mark - Operators
- (NSArray*)intersect:(NSArray*)b;
- (NSArray*)union:(NSArray*)b;
- (NSArray*)join:(NSArray*)b;
- (NSArray*)diff:(NSArray*)b;
- (NSArray*)minus:(NSArray*)b;
- (NSArray*)distinct;
- (NSArray*)distinct:(NSString*)keypath;

#pragma mark - Set Operators
- (NSNumber*)sum;
- (NSNumber*)sum:(NSString*)keypath;
- (NSNumber*)sumWith:(NSNumber*(^)(id object))block;
- (NSNumber*)avg;
- (NSNumber*)avg:(NSString*)keypath;
- (NSNumber*)max;
- (NSNumber*)max:(NSString*)keypath;
- (NSNumber*)min;
- (NSNumber*)min:(NSString*)keypath;


@end
