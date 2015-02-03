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

@interface VideoDetailsViewController ()

@end

@implementation VideoDetailsViewController

- (void) setVideo:(SmvpVideo *)video {
    _video = video;
}

- (void)viewDidLoad
{
    _description.text = [NSString stringWithFormat:@"描述：%@",_video.description];
    _resolution.text = [NSString stringWithFormat:@"分辨率：%ldx%ld",(long)_video.width,(long)_video.height];
    _bitrate.text = [NSString stringWithFormat:@"码率：%ldkbs",(long)_video.videoKbps];
    [super viewDidLoad];
}

- (IBAction)saveVideo:(id)sender {
    NSError *error = nil;
    SmvpRendition *rendition = [[[SmvpHelper apiClient].entriesHandler getPlayInfor:self.video.entryId error:&error].renditions objectAtIndex:0];
    if(![[SmvpHelper downloaderManager] download:rendition])
    {
        NSString *errorMessage = @"视频已下载";
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Failed to load videos."
                                                            message:errorMessage
                                                           delegate:nil
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles:nil];
        [alertView show];
    }
}

-(void)saveVideo
{
    NSError *error = nil;
    SmvpRendition *rendition = [[[SmvpHelper apiClient].entriesHandler getPlayInfor:self.video.entryId error:&error].renditions objectAtIndex:0];
    [[SmvpHelper downloaderManager] download:rendition];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.destinationViewController isKindOfClass:[SmvpPlayerViewController class]]) {
        SmvpPlayerViewController *ivc = (SmvpPlayerViewController *)segue.destinationViewController;
        CGRect region = CGRectMake(0, 0, 320, 240);
        [ivc prepareVideo:self.video withApiClient:[SmvpHelper apiClient] inRegion:region];
    }
    else if ([segue.destinationViewController isKindOfClass:[VideoDownloaderListViewController class]])
    {
        VideoDownloaderListViewController *idvc = (VideoDownloaderListViewController *)segue.destinationViewController;
        idvc.downloaderList = [[SmvpHelper downloaderManager] getDownloaderList];
    }
}

-(void)dealloc{
    
}


@end
