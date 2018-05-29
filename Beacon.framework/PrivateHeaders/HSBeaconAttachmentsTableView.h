#import <UIKit/UIKit.h>

#import "HSBeaconAttachment.h"
#import "HSBeaconAttachmentTableViewCell.h"
#import "HSBeaconContext.h"

@protocol HSBeaconAttachmentsTableViewDelegate

-(void)attachmentsTableShowError:(NSString *)error;

-(void)attachmentUploadComplete;

-(void)attachmentsTableLayoutChanged:(CGFloat)newHeight;

@end

@interface HSBeaconAttachmentsTableView : UITableView

@property(nonatomic) HSBeaconContext *beaconContext;

@property(nonatomic) NSMutableArray<HSBeaconAttachment *> *attachments;

@property(weak) id<HSBeaconAttachmentsTableViewDelegate> attachmentsTableDelegate;

-(void)addAttachment:(HSBeaconAttachment *)attachment;

-(BOOL)canAddAttachment;

-(BOOL)hasPendingUpload;

-(BOOL)sendPendingUploads;

-(void)clearAttachments;

@end
