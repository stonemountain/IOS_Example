//
//  UploadTableViewCell.m
//  Example
//
//  Created by yangfei on 3/12/15.
//  Copyright (c) 2015 smvp. All rights reserved.
//

#import "UploadTableViewCell.h"

@implementation UploadTableViewCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)setUploader:(SmvpVideoUploader *)uploader
{
    _uploader = uploader;
    self.uploaderView = [[SmvpUploadView alloc] initWithTableView:self message:uploader.status];
}

- (void)awakeFromNib
{
    // Initialization code
}



- (void)uploadCanceled:(SmvpHttpConnection *)connection {
    [self.uploaderView removeFromSuperview];
    self.uploaderView = nil;
}

- (void)uploadFinished:(NSHTTPURLResponse *)response {
    self.uploaderView.progressLabel.text = _uploader.status;
}

- (void)uploadFailed:(NSError *)error InResponse:(NSHTTPURLResponse *)response {
   self.uploaderView.progressLabel.text = _uploader.status;
}

- (void)uploadDidUpdate:(double) progress {
    self.uploaderView.progressLabel.text = _uploader.status;
    [self.uploaderView setProgress:progress];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
