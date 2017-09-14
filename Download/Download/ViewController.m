//
//  ViewController.m
//  Download
//
//  Created by GDBank on 2017/9/14.
//  Copyright © 2017年 com.GDBank.Company. All rights reserved.
//

#import "ViewController.h"
#import "XM_DownloadManager.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [[XM_DownloadManager sharedInstance] download:nil progress:^(NSInteger receivedSize, NSInteger expectedSize, CGFloat progress) {
        dispatch_async(dispatch_get_main_queue(), ^{
        
        });
    } state:^(DownloadState state) {
        dispatch_async(dispatch_get_main_queue(), ^{

        });
    }];
}


@end
