//
//  SmvpUploadView.m
//  Example
//
//  Created by julien on 14-1-8.
//  Copyright (c) 2014年 smvp. All rights reserved.
//

#import "SmvpUploadView.h"

@interface SmvpUploadView ()

@property (assign, nonatomic) UITableViewCell *tableViewCell;
@property (strong, nonatomic) UIView *photoborder;
@property (strong, nonatomic) UIImageView *photoImageView;
@property (strong, nonatomic) UIProgressView *progressView;
//@property (strong, nonatomic) UIButton *cancelButton;
@end

@implementation SmvpUploadView

- (id)initWithTableView:(UITableViewCell *)tableViewCell message:(NSString *)uploadMsg
{
    self = [super initWithFrame:CGRectMake(0.0, 0.0, 320.0, 54.0)];
    if (self)
    {
		self.tableViewCell = tableViewCell;
		self.progress = 0.0f;
		
		// Configure the background
		self.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"progress-view-background"]];
		
		// Create the photo border style
		self.photoborder = [[UIView alloc] initWithFrame:CGRectMake(10.0, 7.0, 40.0, 40.0)];
		
		
		// Create the Uploading Label
		self.progressLabel = [[UILabel alloc] initWithFrame:CGRectMake(6.0, 8.0, 275.0, 20.0)];
		self.progressLabel.text = uploadMsg;
		self.progressLabel.opaque = NO;
		self.progressLabel.backgroundColor = [UIColor clearColor];
		self.progressLabel.textColor = [UIColor colorWithRed:0.062 green:0.078 blue:0.156 alpha:1.0];
		self.progressLabel.font = [UIFont boldSystemFontOfSize:15.0];
		
		[self addSubview:self.progressLabel];
		
		// Create the Progress Bar
		self.progressView = [[UIProgressView alloc] initWithProgressViewStyle:UIProgressViewStyleBar];
		
		[self.progressView setFrame:CGRectMake(6.0, 32.0, 275.0, 11.0)];
				
		[self.progressView setProgress:0.0 animated:NO];
		[self.progressView setProgressTintColor:[UIColor colorWithRed:0.431 green:0.753 blue:0.949 alpha:1.0]];
		[self.progressView setTrackTintColor:[UIColor darkGrayColor]];
		
		[self addSubview:self.progressView];
		
//		self.cancelButton = [UIButton buttonWithType:UIButtonTypeCustom];
//        self.cancelButton.frame = CGRectMake(278.0, 5.0, 44.0, 44.0);
//        [self.cancelButton setImage:[UIImage imageNamed:@"upload-cancel-button"] forState:UIControlStateNormal];
//        [self.cancelButton addTarget:self action:@selector(canceledUpload) forControlEvents:UIControlEventTouchUpInside];
//			
//        [self addSubview:self.cancelButton];
		[self.tableViewCell addSubview:self];
    }
    return self;
}

- (void)setProgress:(CGFloat)progress
{
	CGFloat prog = MIN(progress, 1.0);
    
	[self.progressView setProgress:prog animated:YES];
	
	if (prog == 1.0)
    {
//		self.cancelButton.enabled = NO;
	}
}


@end
