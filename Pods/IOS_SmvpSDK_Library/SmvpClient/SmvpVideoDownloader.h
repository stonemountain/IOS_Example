//
//  SmvpVideoDownloader.h
//  SmvpClient
//
//  Created by julien on 14-5-12.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

/*!
 @header  SmvpVideoDownloader
 @abstract 视频下载类；
 @author smvp
 @version 1.3.1
 */
#import <Foundation/Foundation.h>
#import "SmvpAPIClient.h"
#import "M3u8Handler.h"
#import "VideoDownloader.h"

@protocol SmvpVideoDownloaderDelegate;

/*!
 @class
 @abstract 主要用于视频下载，不要单独调用，可通过SmvpVideoDownloaderManager进行下载管理；
 */
@interface SmvpVideoDownloader : NSOperation <M3u8HandlerDelegate,VideoDownloadDelegate,NSMutableCopying>

/*!
 @property
 @abstract SmvpVideoDownloaderDelegate，下载状态改变时调用的回调
 被取消
 - (void)downloadCanceled:(SmvpVideoDownloader *)loader;
 完成
 - (void)downloadFinished:(SmvpVideoDownloader *)loader;
 失败
 - (void)downloadFailed:(NSError *)error InResponse:(NSHTTPURLResponse *)response;
 下载进度
 - (void)downloadDidUpdate:(double) progress;
 */
@property(nonatomic, strong) id<SmvpVideoDownloaderDelegate> delegate;

/*!
 @property
 @abstract rendition信息；
 */
@property(nonatomic, strong) SmvpRendition * smvpRendition;


/*!
 @method
 @abstract	初始化；
 @discussion	初始化视频下载类，提供视频下载所需要的信息；
 
 @param rendition [IN|OUT] 封装了视频某个rendition信息的实例；
 @param client [IN|OUT] apiClient;
 @param downloadDelegate [IN|OUT] 下载代理；
 
 @result 返回SmvpVideoDownloader的实例；
 */
- (instancetype) initWithRendition:(SmvpRendition *)rendition client:(SmvpAPIClient *) client delegate:(id<SmvpVideoDownloaderDelegate>) downloadDelegate;
/*
     preparing
     loading
     failed
     finished
 */

/*!
 @method
 @abstract	当前的下载状态；
 @discussion	返回当前任务的下载状态（已缓存到本地）；
 
 @result 返回当前任务的下载状态（preparing，
 loading，
 failed，
 finished）；
 */
- (NSString *)status;

/*!
 @method
 @abstract	当前任务的下载进度；
 @discussion	当前任务的下载进度（已缓存到本地）；
 
 @result 当前任务的下载进度
 */
- (double)progress;

/*!
 @method
 @abstract	当前任务的创建时间；
 @discussion	当前任务的创建时间（已经缓存到本地），用于下载任务的排序；
 
 @result 返回当前任务的创建时间；
 */
- (NSString *)createTime;

/*!
 @method
 @abstract	停止当前下载；
 @discussion	停止当前下载
 */
-(void)stopDownloadVideo;

/*!
 @method
 @abstract	取消当前下载；
 @discussion	取消当前下载；
 */
-(void)cancelDownloadVideo;

/*!
 @method
 @abstract	重置某个缓存信息的值；
 @discussion	重置某个缓存信息的值
 
 @param value [IN|OUT] value;
 @param key [IN|OUT] key;
 */
-(void)resetValue:(id)value forKey:(NSString *)key;

@end


@protocol SmvpVideoDownloaderDelegate <NSObject>
@optional
- (void)downloadCanceled:(SmvpVideoDownloader *)loader;
- (void)downloadFinished:(SmvpVideoDownloader *)loader;
- (void)downloadFailed:(NSError *)error InResponse:(NSHTTPURLResponse *)response;
- (void)downloadDidUpdate:(double) progress;
@end
