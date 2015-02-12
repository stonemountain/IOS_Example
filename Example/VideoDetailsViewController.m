//
//  VideoDetailsViewController.m
//  Example
//
//  Created by julien on 13-12-27.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import "VideoDetailsViewController.h"
#import "SmvpPlayerViewController.h"
#import "SmvpHelper.h"
#import "SmvpVideoDownloaderManager.h"
#import "VideoDownloaderListViewController.h"
#import "SmvpVideoPlayerConfigurations.h"
#import "SmvpVideoPlayer.h"

@interface VideoDetailsViewController ()

@end

@implementation VideoDetailsViewController
{
    SmvpPlayerViewController *ivc;
}

- (void) setVideo:(SmvpVideo *)video {
    _video = video;
}

- (void)viewDidLoad
{
    _description.text = [NSString stringWithFormat:@"描述：%@",_video.description];
    _resolution.text = [NSString stringWithFormat:@"分辨率：%ldx%ld",(long)_video.width,(long)_video.height];
    _bitrate.text = [NSString stringWithFormat:@"码率：%ldkbs",(long)_video.videoKbps];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(videoStart:)      name:videoStart object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(videoPlay:)       name:videoPlay object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(videoPause:)      name:videoPause object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(videoProgress:)   name:videoProgress object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(videoComplete:)   name:videoComplete object:nil];
    [super viewDidLoad];
    
}

- (IBAction)saveVideo:(id)sender {
    NSError *error = nil;
    SmvpRendition *rendition = [[[SmvpHelper apiClient].entriesHandler getPlayInfor:self.video.entryId error:&error].renditions objectAtIndex:0];
    if(![[SmvpHelper downloaderManager] download:rendition error:&error])
    {
        NSString *errorMessage = [[error userInfo] objectForKey:@"msg"];
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Failed to load videos."
                                                            message:errorMessage
                                                           delegate:nil
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles:nil];
        [alertView show];
    }
}



- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.destinationViewController isKindOfClass:[SmvpPlayerViewController class]]) {
        ivc = (SmvpPlayerViewController *)segue.destinationViewController;
        CGRect region = CGRectMake(0, 0, 320, 240);
        [ivc prepareVideo:self.video withApiClient:[SmvpHelper apiClient] andPlayerId:@"464869259962649779" inRegion:region];
    }
    else if ([segue.destinationViewController isKindOfClass:[VideoDownloaderListViewController class]])
    {
        VideoDownloaderListViewController *idvc = (VideoDownloaderListViewController *)segue.destinationViewController;
        idvc.downloaderList = [[SmvpHelper downloaderManager] getDownloaderList];
    }
}

- (IBAction)play:(id)sender {
    [ivc play];
}

- (IBAction)pause:(id)sender {
    [ivc pause];
}

- (IBAction)seek10:(id)sender {
    [ivc seek:10];
}

- (IBAction)seek1:(id)sender {
    [ivc seek:1];
}


- (void) videoStart:(NSNotification*) notification
{
    id obj = [notification userInfo];
    NSLog(@"videoStart obj:%@",obj);
}

- (void) videoPlay:(NSNotification*) notification
{
    id obj = [notification userInfo];
    NSLog(@"videoPlay obj:%@",obj);
}

- (void) videoPause:(NSNotification*) notification
{
    id obj = [notification userInfo];
    NSLog(@"videoPause obj:%@",obj);
}

- (void) videoComplete:(NSNotification*) notification
{
    id obj = [notification userInfo];
    NSLog(@"videoComplete obj:%@",obj);
}

- (void) videoProgress:(NSNotification*) notification
{
    id obj = [notification userInfo];
    NSLog(@"videoProgress obj:%@",obj);
}

-(void)dealloc{
    
}


@end
