#import <UIKit/UIKit.h>

#import "HSBeaconContext.h"
#import "HSBeaconAttachmentsTableView.h"
#import "HSBeaconContactFormField.h"
#import "HSBeaconEmailMessage.h"

@class HSBeaconContactFormController;

@protocol HSBeaconContactFormControllerDelegate
@required
- (void)contactFormControllerDidChangeAttachmentCount:(HSBeaconContactFormController *)controller;

- (void)contactFormControllerEnableSubmit:(BOOL)enabled;

- (void)showErrorMessage:(NSString *)errorMessage;

@end

#pragma mark -

@interface HSBeaconContactFormController: UIViewController

@property (nonatomic, weak) id<HSBeaconContactFormControllerDelegate> delegate;
@property (strong, nonatomic) HSBeaconContext *beaconContext;


@property (weak, nonatomic) IBOutlet HSBeaconContactFormField *nameField;
@property (weak, nonatomic) IBOutlet HSBeaconContactFormField *subjectField;
@property (weak, nonatomic) IBOutlet HSBeaconContactFormField *emailField;
@property (weak, nonatomic) IBOutlet UITextView *bodyField;

@property (weak, nonatomic) IBOutlet UIView *attachmentsContainer;
@property (weak, nonatomic) IBOutlet UILabel *attachmentsLabel;
@property (weak, nonatomic) IBOutlet UILabel *attachmentsToggleLabel;
@property (weak, nonatomic) IBOutlet HSBeaconAttachmentsTableView *attachmentsTable;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *attachmentsContainerHeight;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *nameHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *subjectHeight;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *emailHeight;

- (BOOL)canAddAttachment;

-(void)addAttachment:(HSBeaconAttachment *)attachment;

/*!
 @brief Check if we have a valid message to send
 
 @return YES if validation passes, NO if there are errors
 */
-(BOOL)validateFieldsWithErrorsDisplayed:(BOOL)showErrors;

/*!
 @brief Upload any pending attachments
 
 @return YES if attachments are pending, NO if it's okay to send the email message
 */
-(BOOL)queueAttachments;

-(HSBeaconEmailMessage *)constructMessage;

- (void)clearForm;

@end
