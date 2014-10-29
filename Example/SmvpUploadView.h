//
//  SmvpUploadView.h
//  Example
//
//  Created by julien on 14-1-8.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SmvpUploadProgressDelegate;

@interface SmvpUploadView : UIControl

@property (weak, nonatomic) id<SmvpUploadProgressDelegate> delegate;
@property (nonatomic) CGFloat progress;

- (instancetype)initWithTableView:(UITableView *)tableView message:(NSString *)uploadMsg;
@end

@protocol SmvpUploadProgressDelegate
- (void)uploadDidCancel:(SmvpUploadView *)progressView;
@end