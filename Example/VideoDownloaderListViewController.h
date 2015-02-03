//
//  VideoDownloaderListViewController.h
//  Example
//
//  Created by yangfei on 1/28/15.
//  Copyright (c) 2015 smvp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SmvpVideoDownloader.h"

@interface VideoDownloaderListViewController : UITableViewController<SmvpVideoDownloaderDelegate>
@property(nonatomic,strong)NSMutableArray *downloaderList;
@end
