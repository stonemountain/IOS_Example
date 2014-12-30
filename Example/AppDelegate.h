//
//  AppDelegate.h
//  Example
//
//  Created by julien on 13-12-26.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SmvpVideoDownloader.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate,SmvpVideoDownloaderDelegate>
@property (strong, nonatomic) UIWindow *window;

@end
