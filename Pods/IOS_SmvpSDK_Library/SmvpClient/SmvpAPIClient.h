//
//  SmvpAPIClient.h
//  SmvpClient
//
//  Created by julien on 13-12-10.
//  Copyright (c) 2013年 smvp. All rights reserved.
//
/*!
 @header SmvpAPIClient api交互
 @abstract APP和石山sdk的交互主要通过SmvpAPIClient类,首先需要生成SmvpAPIClient对象.
 @author smvp
 @version 1.3.1
 */
#import <Foundation/Foundation.h>
#import "SmvpBasicMethod.h"
#import "SmvpPostMethod.h"
#import "SmvpMultipartMethod.h"
#import "SmvpVideo.h"
#import "SmvpEntriesHandler.h"
#import "SmvpCategoriesHandler.h"
@class HTTPServer;
@class SmvpEntriesHandler;

/*!
 @class
 @abstract APP和石山sdk的交互主要通过SmvpAPIClient类,首先需要生成SmvpAPIClient对象.
 */

@interface SmvpAPIClient : NSObject

/*!
 @property
 @abstract token信息
 */
@property(readwrite, strong) NSString *token;

@property(readwrite, strong) HTTPServer *httpServer;

/*!
 @property
 @abstract api交互地址，默认为：http://api.alpha.smvp.cn
 */
@property(readwrite, strong) NSString *apiUrl;

@property(readwrite, strong) NSString *scope;

@property(readwrite, strong) NSString *rootPath;

@property(readwrite) UInt16 port;

/*!
 @property
 @abstract 视频管理,用于管理视频的增删改查；
 */
@property(readonly, strong) SmvpEntriesHandler *entriesHandler;

/*!
 @property
 @abstract 分类管理，用于分类信息的增删改查；
 */
@property(readonly, strong) SmvpCategoriesHandler *categoriesHandler;

/*!
 @method
 @abstract 通过token生成SmvpAPIClient实例；
 @discussion 通过token生成SmvpAPIClient实例，务必保证token的有效性；
 @param token token信息；
 @result SmvpAPIClient实例；
 */
- (instancetype) initWithToken:(NSString *)token;

/*!
 @method
 @abstract 接口调用；
 @discussion 接口调用；
 @param methodUrl 基本路径如：http://api.alpha.smvp.cn/
 @param parameters 参数；
 @param error 错误信息；
 @param get get 或者是 post；
 @result 接口调用结果；
 */
- (id) call:(NSURL *) methodUrl with:(NSDictionary *) parameters error:(NSError **)error get:(BOOL) get;

/*!
 @method
 @abstract api接口调用；
 @discussion api接口调用(http://api.alpha.smvp.cn/)；
 @param methodName 调用api名称，如:players_getConfigurations；
 @param parameters 参数；
 @param error 错误信息；
 @result 接口调用结果；
 */
- (id) callAPI:(NSString *) methodName with:(NSDictionary *) parameters error:(NSError **) error;

/*!
 @method
 @abstract 视频上传；
 @discussion 视频上传接口；
 @param fileURL 上传视频的本地地址；
 @param parameters 参数；
 @result SmvpHttpConnection；
 */
- (SmvpHttpConnection *) uploadVideo:(NSURL *) fileURL withParamters:(NSDictionary *)parameters;

@end
