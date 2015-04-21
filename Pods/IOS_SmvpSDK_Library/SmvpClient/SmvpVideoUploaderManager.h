//
//  SmvpVideoUploaderManager.h
//  SmvpClient
//
//  Created by yangfei on 3/12/15.
//  Copyright (c) 2015 smvp. All rights reserved.
//

/*!
 @header  SmvpVideoUploaderManager
 @abstract 视频上传管理类；
 @author smvp
 @version 1.3.1
 */
#import <Foundation/Foundation.h>
#import "SmvpVideoUploader.h"

/*!
 @class
 @abstract 视频上传管理，提供视频上传的相关接口；
 */
@interface SmvpVideoUploaderManager : NSObject<SmvpVideoUploaderDelegate>


/*!
 @method
 @abstract	通过url下载视频；
 @discussion	通过url下载视频
 
 @param file 上传文件地址信息；
 @param client apiClient;
 @param parameters 参数;
 @param error [IN|OUT] 错误信息；
 
 @result SmvpVideoDownloader实例，可用于查看当前下载状态，状态改变回调等；
 */
- (SmvpVideoUploader *) upload:(NSURL *)file paramters:(NSDictionary *)parameters error:(NSError **)error;

/*!
 @method
 @abstract	初始化；
 @discussion	初始化SmvpVideoUploaderManager实例；
 
 @param client [IN|OUT] apiClient;
 
 @result SmvpVideoUploaderManager实例；
 */
-(id)initWithClient:(SmvpAPIClient *)client;

/*!
 @method
 @abstract	暂停所有任务；
 @discussion	暂停所有任务；
 */
-(void)pause;

/*!
 @method
 @abstract	恢复所有任务；
 @discussion	恢复所有任务；
 */
-(void)resume;

/*!
 @method
 @abstract	取消某个上传任务；
 @discussion	取消某个上传任务；
 
 @param uploader [IN|OUT] SmvpVideoUploader实例；
 */
-(void)cancel:(SmvpVideoUploader *)uploader;

/*!
 @method
 @abstract	获得当前所有的上传任务；
 @discussion	获得当前所有的上传任务；
 
 @result 当前所有的上传任务列表；
 */
-(NSMutableArray *)getUploaderList;

@end
