//
//  VideoUploadListViewController.m
//  Example
//
//  Created by yangfei on 3/12/15.
//  Copyright (c) 2015 smvp. All rights reserved.
//

#import "VideoUploadListViewController.h"
#import "SmvpVideoUploader.h"
#import "SmvpHelper.h"
#import "UploadTableViewCell.h"

@interface VideoUploadListViewController ()

@end

@implementation VideoUploadListViewController

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self)
    {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.uploadList count];
}

-(UITableViewCellEditingStyle)tableView:(UITableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return UITableViewCellEditingStyleDelete;
}

-(void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle==UITableViewCellEditingStyleDelete)
    {
        NSInteger row = [indexPath row];
        SmvpVideoUploader *uploader = (SmvpVideoUploader *)[self.uploadList objectAtIndex:row];
        [[SmvpHelper uploaderManager] cancel:uploader];
        [self.uploadList removeObject:uploader];
        [tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath] withRowAnimation:UITableViewRowAnimationAutomatic];
    }
}

- (UploadTableViewCell *)tableView:(UITableView *)tableView
                 cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    static NSString *TableSampleIdentifier = @"uploaderCell";
    
    UploadTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:
                                     TableSampleIdentifier];
    if (cell == nil)
    {
        cell = [[UploadTableViewCell alloc]
                initWithStyle:UITableViewCellStyleDefault
                reuseIdentifier:TableSampleIdentifier];
    }
    NSUInteger row = [indexPath row];
    SmvpVideoUploader *uploader = (SmvpVideoUploader *)[self.uploadList objectAtIndex:row];
    uploader.delegate = cell;
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    cell.uploader = uploader;
    return cell;
}

@end
