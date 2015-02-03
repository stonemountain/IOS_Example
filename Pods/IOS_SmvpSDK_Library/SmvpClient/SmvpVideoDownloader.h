//
//  SmvpVideoDownloader.h
//  SmvpClient
//
//  Created by julien on 14-5-12.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpAPIClient.h"
#import "M3u8Handler.h"
#import "VideoDownloader.h"

@protocol SmvpVideoDownloaderDelegate;

@interface SmvpVideoDownloader : NSOperation <M3u8HandlerDelegate,VideoDownloadDelegate,NSMutableCopying>

@property(nonatomic, strong) id<SmvpVideoDownloaderDelegate> delegate;
@property(nonatomic, strong) SmvpRendition * smvpRendition;
- (instancetype) initWithRendition:(SmvpRendition *)rendition client:(SmvpAPIClient *) client delegate:(id<SmvpVideoDownloaderDelegate>) downloadDelegate;
/*
     preparing
     loading
     failed
     finished
 */
- (NSString *)status;

- (double)progress;

- (NSString *)createTime;

-(void)stopDownloadVideo;

-(void)cancelDownloadVideo;

-(void)resetValue:(id)value forKey:(NSString *)key;

@end


@protocol SmvpVideoDownloaderDelegate <NSObject>
@optional
- (void)downloadCanceled:(SmvpVideoDownloader *)loader;
- (void)downloadFinished:(SmvpVideoDownloader *)loader;
- (void)downloadFailed:(NSError *)error InResponse:(NSHTTPURLResponse *)response;
- (void)downloadDidUpdate:(double) progress;
@end
