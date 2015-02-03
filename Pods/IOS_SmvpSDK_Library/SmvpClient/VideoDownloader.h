//
//  VideoDownloader.h
//  SmvpClient
//
//  Created by yangfei on 14-12-2.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SegmentDownloader.h"
@class SmvpRendition;
@class SmvpAPIClient;
@class M3u8SegmentList;
@class SegmentDownloader;

@protocol VideoDownloadDelegate;
@interface VideoDownloader : NSObject<SegmentDownloadDelegate>

@property(nonatomic,strong)id<VideoDownloadDelegate> delegate;
//@property(nonatomic,retain)M3u8SegmentList* segmentList;
//@property(nonatomic,retain)SegmentDownloader* segmentDownloader;
//@property(readwrite,strong)SmvpRendition* smvpRendition;
//@property(readwrite,strong)SmvpAPIClient* smvpAPIClient;
//@property(readwrite,assign) double total;

-(id)initWithSegmentList:(M3u8SegmentList*)list andClient:(SmvpAPIClient*)client andRendition:(SmvpRendition*)rendition;

-(void)startDownloadVideo;

-(void)stopDownloadVideo;

-(void)cancelDownloadVideo;

@end

@protocol VideoDownloadDelegate <NSObject>
@optional
-(void)videoDownloaderFinished:(VideoDownloader*)request;
-(void)videoDownloaderProgress:(double)progress;
-(void)videoDownloaderFailed:(VideoDownloader*)request;
@end
