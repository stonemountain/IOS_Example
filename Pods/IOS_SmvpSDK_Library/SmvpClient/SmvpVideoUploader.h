//
//  SmvpVideoUploader.h
//  SmvpClient
//
//  Created by julien on 14-1-9.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

/*!
 @header SmvpVideoUploader
 @abstract  视频上传类；
 @author smvp
 @version 1.2.7
 */
#import <Foundation/Foundation.h>
#import "SmvpAPIClient.h"
#import "SmvpHttpConnection.h"

@protocol SmvpVideoUploaderDelegate;

/*!
 @class
 @abstract 主要用于视频上传，并提供相关接口；
 */
@interface SmvpVideoUploader : NSOperation<SmvpHttpConnectionDelegate,NSMutableCopying>

/*!
 @property
 @abstract SmvpVideoUploaderDelegate，上传状态改变时调用的回调
 被取消
 - (void)uploadCanceled:(SmvpHttpConnection *)connection;
 完成
 - (void)uploadFinished:(NSHTTPURLResponse *)response;
 失败
 - (void)uploadFailed:(NSError *)error InResponse:(NSHTTPURLResponse *)response;
 上传进度
 - (void)uploadDidUpdate:(double) progress;
 */
@property(nonatomic, strong) id<SmvpVideoUploaderDelegate> delegate;

/*!
 @property
 @abstract 上传的视频文件地址；
 */
@property(nonatomic, strong) NSURL *fileURL;

/*!
 @property
 @abstract 当前状态；
 */
@property(nonatomic, strong) NSString *status;

/*!
 @property
 @abstract APP和石山sdk的交互主要通过SmvpAPIClient类,首先需要生成SmvpAPIClient对象.
 */
@property(nonatomic, strong) SmvpAPIClient *apiClient;

/*!
 @method
 @abstract	取消当前下载；
 @discussion	取消当前下载；
 */
-(void)cancelUploadVideo;

/*!
 @method
 @abstract	初始化；
 @discussion	初始化视频上传类的实例；
 
 @param file [IN|OUT] 包含视频地址的NSURL实例；
 @param client [IN|OUT] apiClient
 @param uploadDelegate [IN|OUT] 上传代理；
 
 @result 返回SmvpVideoUploader实例；
 */
- (instancetype) initWithFile:(NSURL *) file apiClient:(SmvpAPIClient *)client paramters:(NSDictionary *)parameters delegate:(id<SmvpVideoUploaderDelegate>) uploadDelegate;

@end

@protocol SmvpVideoUploaderDelegate <NSObject>
@optional
- (void)uploadCanceled:(SmvpHttpConnection *)connection;
- (void)uploadFinished:(NSHTTPURLResponse *)response;
- (void)uploadFailed:(NSError *)error InResponse:(NSHTTPURLResponse *)response;
- (void)uploadDidUpdate:(double) progress;
@end