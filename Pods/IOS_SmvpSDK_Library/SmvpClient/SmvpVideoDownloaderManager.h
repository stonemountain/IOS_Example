//
//  SmvpVideoDownloadManager.h
//  SmvpClient
//
//  Created by yangfei on 1/13/15.
//  Copyright (c) 2015 smvp. All rights reserved.
//

/*!
 @header  SmvpVideoDownloaderManager
 @abstract 视频下载管理类；
 @author smvp
 @version 1.3.1
 */
#import <Foundation/Foundation.h>
#import "SmvpAPIClient.h"
#import "SmvpVideoDownloader.h"

/*!
 @class
 @abstract 视频下载管理，提供视频下载的相关接口；
 */
@interface SmvpVideoDownloaderManager : NSObject<SmvpVideoDownloaderDelegate>

/*!
 @method
 @abstract	通过rendition下载视频；
 @discussion	通过rendition下载视频
 
 @param rendition [IN|OUT] 封装rendition信息的实例；
 @param error [IN|OUT] 错误信息；
 
 @result SmvpVideoDownloader实例，可用于查看当前下载状态，状态改变回调等；
 */
-(SmvpVideoDownloader *)download:(SmvpRendition *)rendition error:(NSError **)error;

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
 @abstract	暂停某个下载任务；
 @discussion	暂停某个下载任务；
 
 @param downloader [IN|OUT] SmvpVideoDownloader实例；
 */
-(void)pause:(SmvpVideoDownloader *)downloader;

/*!
 @method
 @abstract	恢复某个下载任务；
 @discussion	恢复某个下载任务；
 
 @param downloader [IN|OUT] SmvpVideoDownloader实例；
 */
-(void)resume:(SmvpVideoDownloader *)downloader;

/*!
 @method
 @abstract	取消某个下载任务；
 @discussion	取消某个下载任务；
 
 @param downloader [IN|OUT] SmvpVideoDownloader实例；
 */
-(void)cancel:(SmvpVideoDownloader *)downloader;

/*!
 @method
 @abstract	获得当前所有的下载任务；
 @discussion	获得当前所有的下载任务；
 
 @result 当前所有的下载任务列表；
 */
-(NSMutableArray *)getDownloaderList;

/*!
 @method
 @abstract	初始化；
 @discussion	初始化SmvpVideoDownloaderManager实例；
 
 @param client [IN|OUT] apiClient;
 
 @result SmvpVideoDownloaderManager实例；
 */
-(id)initWithClient:(SmvpAPIClient *)client;
@end
