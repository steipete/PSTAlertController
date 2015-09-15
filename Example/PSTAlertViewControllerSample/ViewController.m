//
//  ViewController.m
//  PSTAlertViewControllerSample
//
//  Created by Peter Steinberger on 07/11/14.
//  Copyright (c) 2014 PSPDFKit GmbH. All rights reserved.
//

#import "ViewController.h"
#import "PSTAlertController.h"

@implementation ViewController

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}

- (IBAction)testButtonPressed:(UIButton *)sender {
    PSTAlertController *controller = [PSTAlertController actionSheetWithTitle:nil];
    [controller addAction:[PSTAlertAction actionWithTitle:@"OK" style:PSTAlertActionStyleDestructive handler:nil]];
    // Cancel action on a sheet should be the last action.
    [controller addCancelActionWithHandler:nil];
    [controller showWithSender:sender arrowDirection:UIPopoverArrowDirectionAny controller:self animated:YES completion:nil];
}

- (IBAction)doTheDance:(UIButton *)sender {
    PSTAlertController *gotoPageController = [PSTAlertController alertWithTitle:@"Go to page" message:nil];
    [gotoPageController addTextFieldWithConfigurationHandler:^(UITextField *textField) {
        textField.keyboardType = UIKeyboardTypeNumberPad;
    }];
    [gotoPageController addCancelActionWithHandler:NULL];
    [gotoPageController addAction:[PSTAlertAction actionWithTitle:@"Go to" handler:^(PSTAlertAction *action) {
        NSString *pageLabel = action.alertController.textField.text;
        PSTAlertController *dismissable = [PSTAlertController presentDismissableAlertWithTitle:@"Result" message:[NSString stringWithFormat:@"You entered %@", pageLabel] controller:self];
        [dismissable addDidDismissBlock:^(PSTAlertAction *action) {
            [self doTheDance:nil];
        }];
    }]];
    [gotoPageController addAction:[PSTAlertAction actionWithTitle:@"No" style:PSTAlertActionStyleDestructive handler:^(PSTAlertAction *action) {
        PSTAlertController *sheetController = [PSTAlertController actionSheetWithTitle:@"No?"];
        [sheetController addAction:[PSTAlertAction actionWithTitle:@"I've changed my mind" handler:^(PSTAlertAction *action) {
            [self doTheDance:nil];
        }]];
        // Cancel action on a sheet should be the last action.
        [sheetController addAction:[PSTAlertAction actionWithTitle:@"That's fine." style:PSTAlertActionStyleCancel handler:NULL]];
        [sheetController showWithSender:[NSValue valueWithCGRect:CGRectMake(100.f, 100.f, 1.f, 1.f)] controller:self animated:YES completion:^{
            NSLog(@"Okay, let's do that again...");
        }];
    }]];
    [gotoPageController showWithSender:nil controller:self animated:YES completion:NULL];
}

@end
