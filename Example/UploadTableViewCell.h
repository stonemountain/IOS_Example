//
//  UploadTableViewCell.h
//  Example
//
//  Created by yangfei on 3/12/15.
//  Copyright (c) 2015 smvp. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SmvpVideoUploader.h"
#import "SmvpUploadView.h"

@interface UploadTableViewCell : UITableViewCell<SmvpVideoUploaderDelegate>
@property (strong, nonatomic)SmvpVideoUploader * uploader;
@property (strong, nonatomic)SmvpUploadView * uploaderView;
@end
