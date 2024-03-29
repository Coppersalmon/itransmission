//
//  TorrentViewController.h
//  iTransmission
//
//  Created by Mike Chen on 10/3/10.
//  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class Controller;
@class TDBadgeView;
@class Torrent;
@class TorrentCell;
@class StatisticsView;
@class BandwidthController;

@interface TorrentViewController : UIViewController<UITableViewDataSource, UITableViewDelegate, UIActionSheetDelegate, UIAlertViewDelegate> {
    UITableView *fTableView;
    Controller *fController;
    UIActivityIndicatorView *fActivityIndicator;
    UIView *fActivityItemView;
    TDBadgeView *fActivityCounterBadge;
	StatisticsView *fStatisticsView;
	NSTimer *fUIUpdateTimer;
	NSArray *fNormalToolbarItems;
	NSArray *fEditToolbarItems;
	UIBarButtonItem *fEditButton;
	UIBarButtonItem *fDoneButton;
	UIBarButtonItem *fInfoButton;
	NSMutableArray *fSelectedIndexPaths;
	BandwidthController *fBandwidthController;
	UIBarButtonItem *fActivityItem;
}

@property (nonatomic, retain) IBOutlet UITableView *tableView;
@property (nonatomic, retain) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (nonatomic, retain) IBOutlet UIView *activityItemView;
@property (nonatomic, retain) IBOutlet TDBadgeView *activityCounterBadge;
@property (nonatomic, assign) Controller *controller;
@property (nonatomic, retain) IBOutlet StatisticsView *statisticsView;
@property (nonatomic, retain) NSTimer *UIUpdateTimer;
@property (nonatomic, retain) NSArray *normalToolbarItems;
@property (nonatomic, retain) NSArray *editToolbarItems;
@property (nonatomic, retain) UIBarButtonItem *editButton;
@property (nonatomic, retain) UIBarButtonItem *doneButton;
@property (nonatomic, retain) UIBarButtonItem *infoButton;
@property (nonatomic, retain) UIBarButtonItem *activityItem;
@property (nonatomic, retain) NSMutableArray *selectedIndexPaths;
@property (nonatomic, retain) BandwidthController *bandwidthController;

- (void)addButtonClicked:(id)sender;
- (void)prefButtonClicked:(id)sender;

- (void)addFromURLClicked;
- (void)addFromURLWithExistingURL:(NSString*)url message:(NSString*)msg;
- (void)addFromMagnetClicked;
- (void)addFromMagnetWithExistingMagnet:(NSString*)magnet message:(NSString*)msg;
- (void)addFromFilesystemClicked;

- (void)activityCounterDidChange:(NSNotification*)notif;
- (void)newTorrentAdded:(NSNotification*)notif;
- (void)removedTorrents:(NSNotification*)notif;

- (void)controlButtonClicked:(id)sender;
- (void)resumeButtonClicked:(id)sender;
- (void)pauseButtonClicked:(id)sender;
- (void)removeButtonClicked:(id)sender;
- (void)editButtonClicked:(id)sender;
- (void)doneButtonClicked:(id)sender;
- (void)bandwidthButtonClicked:(id)sender;
- (void)infoButtonClicked:(id)sender;

- (void)setupCell:(TorrentCell*)cell forTorrent:(Torrent*)torrent;

- (void)updateUI;
- (void)updateCell:(TorrentCell*)c;

@end
