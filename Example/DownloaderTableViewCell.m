//
//  DownloaderTableViewCell.m
//  Example
//
//  Created by yangfei on 1/29/15.
//  Copyright (c) 2015 smvp. All rights reserved.
//

#import "DownloaderTableViewCell.h"
#import "SmvpHelper.h"

@implementation DownloaderTableViewCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        
        // Initialization code
    }
    return self;
}

-(void)downloadFinished:(SmvpVideoDownloader *)loader
{
    _progress.progress = 1.0;
    _pauseOrResume.enabled = false;
    _status.text = @"下载完成";
}

- (void)downloadCanceled:(SmvpVideoDownloader *)loader
{
    
}

- (void)downloadDidUpdate:(double)progress
{
    _progress.progress = progress;
    _status.text = @"正在下载";
}

-(void)downloadFailed:(NSError *)error InResponse:(NSHTTPURLResponse *)response
{
    _status.text = @"下载错误";
}

- (void)awakeFromNib
{
    // Initialization code
}

- (IBAction)pauseOrResume:(id)sender
{
    if([(UISwitch *)sender isOn])
    {
        [[SmvpHelper downloaderManager] resume:_loader];
        _status.text = @"正在下载";
    }else
    {
        [[SmvpHelper downloaderManager] pause:_loader];
        _status.text = @"暂停";
    }
}

@end
