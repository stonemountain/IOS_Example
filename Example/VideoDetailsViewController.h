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

@property(nonatomic, strong) SmvpVideo *video;

@end
