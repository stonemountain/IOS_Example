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
//#import "SmvpVideoDownloader.h"

@interface VideoDetailsViewController ()

@end

@implementation VideoDetailsViewController

- (void) setVideo:(SmvpVideo *)video {
    _video = video;
}

- (void)viewDidLoad
{
    UIBarButtonItem *saveButton = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemSave target:self action:@selector(saveVideo)];
	self.navigationItem.rightBarButtonItem = saveButton;
    [super viewDidLoad];
}

-(void)saveVideo
{
    NSError *error = nil;
    SmvpRendition *rendition = [[[SmvpHelper apiClient].entriesHandler getPlayInfor:self.video.entryId error:&error].renditions objectAtIndex:0];
    SmvpVideoDownloader *downLoader = [[SmvpVideoDownloader alloc] initWithRendition:rendition client:[SmvpHelper apiClient] delegate:self];
    [downLoader start];
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
}

-(void)dealloc{
    
}


@end
