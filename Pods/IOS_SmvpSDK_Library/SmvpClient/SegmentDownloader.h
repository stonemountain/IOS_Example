//
//  SegmentDownloader.h
//  SmvpClient
//
//  Created by yangfei on 14-12-1.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmvpHttpConnection.h"

@protocol SegmentDownloadDelegate;

@interface SegmentDownloader:NSObject<SmvpHttpConnectionDelegate>

//@property(nonatomic,copy)NSString* fileName;
//@property(nonatomic,copy)NSString* tmpFileName;
//@property(nonatomic,copy)NSString* filePath;
//@property(nonatomic,copy)NSString* downloadUrl;
//@property(nonatomic,copy)NSFileHandle* writeHandle;
//@property(nonatomic,strong)SmvpHttpConnection *connection;
@property(nonatomic,retain)id<SegmentDownloadDelegate>delegate;

-(void)start;
-(void)stop;
-(void)clean;
-(id)initWithUrl:(NSString*)url andFilePath:(NSString*)path  andFileName:(NSString*)fileName;

@end

@protocol SegmentDownloadDelegate <NSObject>
@optional
    -(void)segmentDownloadFinished:(SegmentDownloader *)request;
    -(void)segmentDownloadFailed:(SegmentDownloader *)request;
@end
