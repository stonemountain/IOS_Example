//
//  VideoListViewController.h
//  Example
//
//  Created by julien on 13-12-26.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MobileCoreServices/UTCoreTypes.h>
#import "SmvpVideoUploader.h"
#import "SmvpUploadView.h"
#import "SmvpHttpConnection.h"
#import "SmvpVideoDownloader.h"

@interface VideoListViewController : UITableViewController <UINavigationControllerDelegate, UIImagePickerControllerDelegate, SmvpVideoUploaderDelegate, SmvpUploadProgressDelegate, SmvpVideoDownloaderDelegate>

@property(nonatomic, strong) NSArray *videos;
@property(nonatomic, strong) SmvpUploadView *uploadView;
@property(nonatomic, strong) SmvpHttpConnection *uploadConnection;

- (IBAction)fetchVideos;
- (void)handleError:(NSError *)error;

@end
