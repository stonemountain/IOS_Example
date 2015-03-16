//
//  VideoListViewController.m
//  Example
//
//  Created by julien on 13-12-26.
//  Copyright (c) 2013年 smvp. All rights reserved.
//

#import "VideoListViewController.h"
#import "VideoDetailsViewController.h"
#import "SmvpHelper.h"
#import "SmvpImageDownloader.h"
#import "SmvpVideo+Image.h"
#import "SmvpUploadView.h"
#import "VideoDownloaderListViewController.h"
#import "VideoUploadListViewController.h"

@interface VideoListViewController () <UIScrollViewDelegate>
@property (nonatomic, strong) NSMutableDictionary *imageDownloadsInProgress;
@end

@implementation VideoListViewController
{
    UIBarButtonItem *addButton;
}

@synthesize uploadConnection;

- (void)awakeFromNib
{
    [super awakeFromNib];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	
	addButton = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemAdd target:self action:@selector(selectVideoToUpload)];
	UIBarButtonItem *downloadListButton =[[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemOrganize target:self action:@selector(downloadList)];
    self.navigationItem.rightBarButtonItems = @[addButton,downloadListButton];
    self.imageDownloadsInProgress = [NSMutableDictionary dictionary];
    [self fetchVideos];
}

- (void)selectVideoToUpload {
    [addButton setEnabled:YES];
	UIImagePickerController *imagePicker = [[UIImagePickerController alloc] init];
    imagePicker.delegate = self;
    imagePicker.allowsEditing = YES;
    imagePicker.mediaTypes = [[NSArray alloc] initWithObjects: (NSString *) kUTTypeMovie, nil];
    imagePicker.sourceType = UIImagePickerControllerSourceTypeSavedPhotosAlbum;
    [self presentViewController:imagePicker animated:YES completion:nil];
}

- (void) imagePickerControllerDidCancel: (UIImagePickerController *) picker {    
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void) imagePickerController: (UIImagePickerController *) picker
    didFinishPickingMediaWithInfo: (NSDictionary *) info {
    
    NSString *mediaType = [info objectForKey: UIImagePickerControllerMediaType];
    [self dismissViewControllerAnimated:NO completion:nil];
    
    // Handle a movie capture
    if ([mediaType isEqualToString:(NSString*)kUTTypeMovie]) {
        NSError *error = nil;
        NSURL *movieURL = [info objectForKey:UIImagePickerControllerMediaURL];
        [[SmvpHelper uploaderManager] upload:movieURL paramters:[[NSDictionary alloc] init] error:&error];
        [self performSegueWithIdentifier:@"upload" sender:self];
    }
}



- (void)handleError:(NSError *)error {
    NSString *errorMessage = [error localizedDescription];
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Failed to load videos."
														message:errorMessage
													   delegate:nil
											  cancelButtonTitle:@"OK"
											  otherButtonTitles:nil];
    [alertView show];
}

- (void) setVideos:(NSArray *)videos {
    _videos = videos;
    [self.tableView reloadData];
}

- (IBAction)fetchVideos {
    [self.refreshControl beginRefreshing]; // start the spinner
    SmvpAPIClient *client = [SmvpHelper apiClient];    // create a (non-main) queue to do fetch on
    dispatch_queue_t fetchQ = dispatch_queue_create("smvp video fetcher", NULL);
    // put a block to do the fetch onto that queue
    dispatch_async(fetchQ, ^{
        NSError *error = nil;
        NSDictionary *list = nil;
        @try {
            list = [[client entriesHandler] listWithFilter:nil InCatetory:nil OrderBy:nil error:&error];
        }
        @catch (NSException *exception) {
            NSLog(@"%@",exception);
        }
        @finally {
            
        }
        
        // update the Model (and thus our UI), but do so back on the main queue
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.refreshControl endRefreshing]; // stop the spinner
            if (error) {
                [self handleError:error];
            } else {
                self.videos = [list objectForKey:@"items"];
            }
        });
    });
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    NSArray *allDownloads = [self.imageDownloadsInProgress allValues];
    [allDownloads makeObjectsPerformSelector:@selector(cancelDownload)];
    
    [self.imageDownloadsInProgress removeAllObjects];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    NSUInteger count = [self.videos count];
    if (count == 0) {
        return 1;
    } else {
        return count;
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *loadingCellIdentifier = @"LoadingCell";
    static NSString *videoCellIdentifier = @"VideoCell";
    
    // Configure the cell...
    if ([self.videos count] == 0 && indexPath.row == 0) {
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:loadingCellIdentifier];
		cell.textLabel.text = @"Loading…";
		return cell;
    }
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:videoCellIdentifier forIndexPath:indexPath];
    SmvpVideo *video = self.videos[indexPath.row];
    cell.textLabel.text = [video title];
    cell.detailTextLabel.text = [@"Status: " stringByAppendingString:[video status]];

    if (!video.thumbnailImage) {
        if (video.thumbnailUrl && ![video.thumbnailUrl isKindOfClass:[NSNull class]] && self.tableView.dragging == NO && self.tableView.decelerating == NO) {
            [self startIconDownload:video forIndexPath:indexPath];
        }
        cell.imageView.image = [UIImage imageNamed:@"ThumbnailPlaceHolder"];
    } else {
        cell.imageView.image = video.thumbnailImage;
    }
    
    return cell;
}

- (void)startIconDownload:(SmvpVideo *)video forIndexPath:(NSIndexPath *)indexPath {
    SmvpImageDownloader *imageDownloader = [self.imageDownloadsInProgress objectForKey:indexPath];
    if (imageDownloader == nil) {
        imageDownloader = [[SmvpImageDownloader alloc] init];
        imageDownloader.imageUrl = video.thumbnailUrl;
        [imageDownloader setCompletionHandler:^(UIImage * image){
            video.thumbnailImage = image;
            dispatch_async(dispatch_get_main_queue(), ^{
                UITableViewCell *cell = [self.tableView cellForRowAtIndexPath:indexPath];
                cell.imageView.image = video.thumbnailImage;
                [self.imageDownloadsInProgress removeObjectForKey:indexPath];
            });
            
        }];
        [self.imageDownloadsInProgress setObject:imageDownloader forKey:indexPath];
        [imageDownloader startDownload];
    }
}

- (void)loadImagesForOnscreenRows {
    if ([self.videos count] > 0) {
        NSArray *visiblePaths = [self.tableView indexPathsForVisibleRows];
        for (NSIndexPath *indexPath in visiblePaths) {
            SmvpVideo *video = [self.videos objectAtIndex:indexPath.row];
            if (!video.thumbnailImage) {
                if (video.thumbnailUrl && ![video.thumbnailUrl isKindOfClass:[NSNull class]]) {
                    [self startIconDownload:video forIndexPath:indexPath];
                }
            }
        }
    }
}

// -------------------------------------------------------------------------------
//	scrollViewDidEndDragging:willDecelerate:
//  Load images for all onscreen rows when scrolling is finished.
// -------------------------------------------------------------------------------
- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate {
    if (!decelerate) {
        [self loadImagesForOnscreenRows];
    }
}

// -------------------------------------------------------------------------------
//	scrollViewDidEndDecelerating:
// -------------------------------------------------------------------------------
- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView {
    [self loadImagesForOnscreenRows];
}

-(void)downloadList
{
    [self performSegueWithIdentifier:@"download" sender:self];
}

#pragma mark - Navigation

// In a story board-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    NSIndexPath *indexPath = nil;
    if ([sender isKindOfClass:[UITableViewCell class]]) {
        indexPath = [self.tableView indexPathForCell:sender];
    }
    SmvpVideo *video = self.videos[indexPath.row];
    if ([segue.destinationViewController isKindOfClass:[VideoDetailsViewController class]]) {
        if (![video.status isEqualToString: @"FINISHED"]) {
            UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Failed to load video."
                                                        message:@"The video is not ready to play."
                                                        delegate:nil
                                                        cancelButtonTitle:@"OK"
                                                        otherButtonTitles:nil];
            [alertView show];
            [sender setUserInteractionEnabled:NO];
            return;
        }
        VideoDetailsViewController *ivc = (VideoDetailsViewController *)segue.destinationViewController;
        ivc.video = video;
        ivc.title = video.title;
    }
    else if ([segue.destinationViewController isKindOfClass:[VideoDownloaderListViewController class]])
    {
        VideoDownloaderListViewController *idvc = (VideoDownloaderListViewController *)segue.destinationViewController;
        idvc.downloaderList = [[SmvpHelper downloaderManager] getDownloaderList];
    }
    else if ([segue.destinationViewController isKindOfClass:[VideoUploadListViewController class]])
    {
        VideoUploadListViewController *iuvc = (VideoUploadListViewController *)segue.destinationViewController;
        iuvc.uploadList = [[SmvpHelper uploaderManager] getUploaderList];
    }
}

@end
