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

@interface SmvpVideoDownloader : NSObject <M3u8HandlerDelegate,VideoDownloadDelegate>

@property(nonatomic, weak) id<SmvpVideoDownloaderDelegate> delegate;
@property(nonatomic, strong) M3u8Handler *m3u8Handler;
@property(nonatomic, strong) VideoDownloader *videoDownloader;
@property(nonatomic, strong) SmvpAPIClient *smvpAPIclient;
@property(nonatomic, strong) SmvpRendition *smvpRendition;
- (instancetype) initWithRendition:(SmvpRendition *)rendition client:(SmvpAPIClient *) client delegate:(id<SmvpVideoDownloaderDelegate>) downloadDelegate;
- (void)start;
@end


@protocol SmvpVideoDownloaderDelegate <NSObject>
@optional
- (void)downloadCanceled:(SmvpVideoDownloader *)loader;
- (void)downloadFinished:(SmvpVideoDownloader *)loader;
- (void)downloadFailed:(NSError *)error InResponse:(NSHTTPURLResponse *)response;
- (void)uploadDidUpdate:(double) progress;
@end
