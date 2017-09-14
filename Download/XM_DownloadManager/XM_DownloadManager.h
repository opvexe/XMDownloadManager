//
//  XM_DownloadManager.h
//  Download
//
//  Created by GDBank on 2017/9/14.
//  Copyright © 2017年 com.GDBank.Company. All rights reserved.
//

typedef enum {
    DownloadStateStart = 0,  ///MARK: 下载中
    DownloadStateSuspended,  ///MARK: 下载暂停
    DownloadStateCompleted,  ///MARK: 下载完成
    DownloadStateFailed      ///MARK: 下载失败
}DownloadState;

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NSString+Hash.h"

///MARK: 下载模型
@interface DownloadModel : NSObject
@property(nonatomic, strong)NSOutputStream *stream;   ///MARK:下载流
@property(nonatomic, copy)NSString *url; ///MARK: 下载地址
@property(nonatomic, assign)NSInteger totalLength; ///MARK: 请求服务器，返回的总长度
@property (nonatomic, copy) void(^progressBlock)(NSInteger receivedSize, NSInteger expectedSize, CGFloat progress); ///MARK:下载进度
@property (nonatomic, copy) void(^stateBlock)(DownloadState state);///MARK: 下载状态

@end

///MARK: 下载管理类
@interface XM_DownloadManager : NSObject

+ (instancetype)sharedInstance;   ///MARK: 单利类
/**
 *  开启任务下载资源
 *
 *  @param url           下载地址
 *  @param progressBlock 回调下载进度
 *  @param stateBlock    下载状态
 */
- (void)download:(NSString *)url progress:(void(^)(NSInteger receivedSize, NSInteger expectedSize, CGFloat progress))progressBlock state:(void(^)(DownloadState state))stateBlock;
/**
 *  查询该资源的下载进度值
 *
 *  @param url 下载地址
 *
 *  @return 返回下载进度值
 */
- (CGFloat)progress:(NSString *)url;

/**
 *  获取该资源总大小
 *
 *  @param url 下载地址
 *
 *  @return 资源总大小
 */
- (NSInteger)fileTotalLength:(NSString *)url;

/**
 *  判断该资源是否下载完成
 *
 *  @param url 下载地址
 *
 *  @return YES: 完成
 */
- (BOOL)isCompletion:(NSString *)url;

/**
 *  删除该资源
 *
 *  @param url 下载地址
 */
- (void)deleteFile:(NSString *)url;

/**
 *  清空所有下载资源
 */
- (void)deleteAllFile;


@end
