//
//  DownloaderTableViewCell.h
//  Example
//
//  Created by yangfei on 1/29/15.
//  Copyright (c) 2015 smvp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SmvpVideoDownloader.h"

@interface DownloaderTableViewCell : UITableViewCell<SmvpVideoDownloaderDelegate>
@property (strong, nonatomic) IBOutlet UILabel *title;
@property (strong, nonatomic) IBOutlet UILabel *status;
@property (strong, nonatomic) IBOutlet UIProgressView *progress;
@property (strong, nonatomic) IBOutlet UISwitch *pauseOrResume;
@property (strong, nonatomic)SmvpVideoDownloader* loader;
@end
