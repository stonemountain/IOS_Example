//
//  VideoDetailsViewController.h
//  Example
//
//  Created by julien on 13-12-27.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SmvpVideo+Image.h"
#import "SmvpVideoDownloader.h"

@interface VideoDetailsViewController : UIViewController <SmvpVideoDownloaderDelegate>
@property (strong, nonatomic) IBOutlet UILabel *description;
@property (strong, nonatomic) IBOutlet UIButton *save;
@property (strong, nonatomic) IBOutlet UILabel *resolution;
@property (strong, nonatomic) IBOutlet UILabel *bitrate;

@property(nonatomic, strong) SmvpVideo *video;

@end
