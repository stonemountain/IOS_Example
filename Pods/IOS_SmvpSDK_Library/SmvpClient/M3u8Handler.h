//
//  M3u8Handler.h
//  SmvpClient
//
//  Created by yangfei on 14-12-1.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>
@class M3u8SegmentList;
@class M3u8Handler;
@class SmvpAPIClient;
@class SmvpRendition;
@protocol M3u8HandlerDelegate <NSObject>
@optional
    - (void)praseM3U8Finished:(M3u8Handler*)handler;
    - (void)praseM3U8Failed:(M3u8Handler*)handler;
@end

@interface M3u8Handler : NSObject

@property(nonatomic,weak)id<M3u8HandlerDelegate> delegate;
@property(nonatomic,retain)M3u8SegmentList* segmentList;


- (void) praseRendition:(SmvpRendition*)rendition andClient:(SmvpAPIClient*)client;

@end
