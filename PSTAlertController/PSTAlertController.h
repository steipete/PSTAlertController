//
//  PSTAlertController.h
//
//  Licensed under the MIT license.
//  Copyright (c) 2014 Peter Steinberger, PSPDFKit GmbH.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PSTAlertControllerStyle) {
    PSTAlertControllerStyleActionSheet = 0,
    PSTAlertControllerStyleAlert
};

typedef NS_ENUM(NSInteger, PSTAlertActionStyle) {
    PSTAlertActionStyleDefault = 0,
    PSTAlertActionStyleCancel,
    PSTAlertActionStyleDestructive
};

@class PSTAlertController;

// Defines a single button/action.
@interface PSTAlertAction : NSObject
+ (nonnull instancetype)actionWithTitle:(nonnull NSString *)title style:(PSTAlertActionStyle)style handler:(void (^ __nullable)(PSTAlertAction * __nonnull action))handler;
+ (nonnull instancetype)actionWithTitle:(nonnull NSString *)title handler:(void (^ __nullable)(PSTAlertAction * __nonnull action))handler;
@property (nonatomic, readonly) PSTAlertActionStyle style;

@property (nonatomic, weak) PSTAlertController *alertController; // weak connection
@end

// Mashup of UIAlertController with fallback methods for iOS 7.
// @note Blocks are generally executed after the dismiss animation is completed.
@interface PSTAlertController : NSObject

// Generic initializer
+ (nonnull instancetype)alertControllerWithTitle:(nullable NSString *)title message:(nullable NSString *)message preferredStyle:(PSTAlertControllerStyle)preferredStyle;
- (nonnull instancetype)init NS_UNAVAILABLE;

// Add action.
- (void)addAction:(nonnull PSTAlertAction *)action;

// Add block that is called after the alert controller will be dismissed (before animation).
- (void)addWillDismissBlock:(void (^ __nonnull)(PSTAlertAction * __nonnull action))willDismissBlock;

// Add block that is called after the alert view has been dismissed (after animation).
- (void)addDidDismissBlock:(void (^ __nonnull)(PSTAlertAction * __nonnull action))didDismissBlock;

@property (nullable, nonatomic, copy, readonly) NSArray<PSTAlertAction *> *actions;

// Text field support
- (void)addTextFieldWithConfigurationHandler:(void (^ __nullable)(UITextField * __nonnull textField))configurationHandler;
@property (nullable, nonatomic, readonly) NSArray<UITextField *> *textFields;

@property (nullable, nonatomic, copy) NSString *title;
@property (nullable, nonatomic, copy) NSString *message;

@property (nonatomic, readonly) PSTAlertControllerStyle preferredStyle;

// Presentation and dismissal
- (void)showWithSender:(nullable id)sender controller:(nullable UIViewController *)controller animated:(BOOL)animated completion:(void (^ __nullable)(void))completion;
- (void)showWithSender:(nullable id)sender arrowDirection:(UIPopoverArrowDirection)arrowDirection controller:(nullable UIViewController *)controller animated:(BOOL)animated completion:(void (^ __nullable)(void))completion;
- (void)dismissAnimated:(BOOL)animated completion:(void (^ __nullable)(void))completion;

+ (BOOL)hasVisibleAlertController;
@property (nonatomic, readonly, getter=isVisible) BOOL visible;

@end

@interface PSTAlertController (Convenience)

// Convenience initializers
+ (nonnull instancetype)actionSheetWithTitle:(nullable NSString *)title;
+ (nonnull instancetype)alertWithTitle:(nullable NSString *)title message:(nullable NSString *)message;

// Convenience. Presents a simple alert with a "Dismiss" button.
// Will use the root view controller if `controller` is nil.
+ (nonnull instancetype)presentDismissableAlertWithTitle:(nullable NSString *)title message:(nullable NSString *)message controller:(nullable UIViewController *)controller;

// Variant that will present an error.
+ (nonnull instancetype)presentDismissableAlertWithTitle:(nullable NSString *)title error:(nullable NSError *)error controller:(nullable UIViewController *)controller;

// From Apple's HIG:
// In a two-button alert that proposes a potentially risky action, the button that cancels the action should be on the right (and light-colored).
// In a two-button alert that proposes a benign action that people are likely to want, the button that cancels the action should be on the left (and dark-colored).
- (void)addCancelActionWithHandler:(void (^ __nullable)(PSTAlertAction * __nonnull action))handler; // convenience

@property (nullable, nonatomic, readonly) UITextField *textField;

@end


@interface PSTAlertController (Internal)

@property (nullable, nonatomic, strong, readonly) UIAlertController *alertController;

@property (nullable, nonatomic, strong, readonly) UIActionSheet *actionSheet;
@property (nullable, nonatomic, strong, readonly) UIAlertView *alertView;

// One if the above three.
@property (nullable, nonatomic, strong, readonly) id presentedObject;

@end
