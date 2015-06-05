//
//  SmvpPlayerViewController.h
//  SmvpClient
//
//  Created by julien on 13-12-31.
//  Copyright (c) 2013年 smvp. All rights reserved.
//


/*!
 @header SmvpPlayerViewController
 @abstract 视频播放控制类；
 @author smvp
 @version 1.3.1
 */
#import <UIKit/UIKit.h>
#import "SmvpVideo.h"
#import "SmvpAPIClient.h"

/*!
 @class
 @abstract 视频播放控制类；
 */
@interface SmvpPlayerViewController : UIViewController

/*!
 @property
 @abstract 视频信息；
 */
@property(nonatomic, strong) SmvpVideo *video;

/*!
 @method
 @abstract	播放；
 @discussion	视频暂停，或者未开始播放时有效；
 */
- (void) play;

/*!
 @method
 @abstract	暂停；
 @discussion	视频正在播放时有效；
 */
- (void) pause;

/*!
 @method
 @abstract	seek；
 @discussion	seek到某一时间点开始播放；
 
 @param time [IN|OUT] 秒为单位的时间点；
 */
- (void) seek:(float) time;

/*!
 @method
 @abstract	初始化视频信息；
 @discussion	初始化视频播放所必要的信息；
 
 @param video [IN|OUT] 视频信息的封装；
 @param apiClient [IN|OUT] apiClient;
 @param playerId [IN|OUT] 播放器ID；
 @param region [IN|OUT] 播放器区域；
 */
- (void) prepareVideo:(SmvpVideo *)video withApiClient:(SmvpAPIClient *) apiClient andPlayerId:(NSString *) playerId inRegion:(CGRect)region;

@end
