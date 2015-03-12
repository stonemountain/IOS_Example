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
@property (strong, nonatomic) UILabel *progressLabel;
- (instancetype)initWithTableView:(UITableViewCell *)tableViewCell message:(NSString *)uploadMsg;
@end