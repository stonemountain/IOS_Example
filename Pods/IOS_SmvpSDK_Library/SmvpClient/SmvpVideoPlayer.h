//
//  SmvpVideoPlayer.h
//  SmvpClient
//
//  Created by julien on 13-12-30.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <Foundation/Foundation.h>

//extern NSString * const kVideoPlayerVideoChangedNotification;
//extern NSString * const kTrackEventVideoStart;
//extern NSString * const kTrackEventVideoLiveStart;
//extern NSString * const kTrackEventVideoComplete;
extern NSString * const videoStart;
extern NSString * const videoPause;
extern NSString * const videoPlay;
extern NSString * const videoProgress;
extern NSString * const videoComplete;



@protocol SmvpVideoPlayerDelegate <NSObject>

@optional
@property (nonatomic) BOOL fullScreenToggled;
- (void)trackEvent:(NSString *)event videoID:(NSString *)videoID title:(NSString *)title;

@end

@protocol SmvpVideoPlayer <NSObject>

@property (readonly, strong) NSDictionary *currentVideoInfo;
@property (nonatomic, weak) id <SmvpVideoPlayerDelegate> delegate;
@property (readonly) BOOL fullScreenModeToggled;
@property (nonatomic) BOOL showStaticEndTime;
@property (nonatomic) BOOL allowPortraitFullscreen;
@property (nonatomic, readonly) BOOL isPlaying;

- (void)playVideoWithTitle:(NSString *)title URL:(NSURL *)url videoID:(NSString *)videoID isStreaming:(BOOL)streaming playInFullScreen:(BOOL)playInFullScreen;
- (void)showCannotFetchStreamError;
- (void)launchFullScreen;
- (void)minimizeVideo;
- (void)playPauseHandler;

@end
