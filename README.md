PSTAlertController
==================

API similar to `UIAlertController`, backwards compatible to iOS 7. Will use the new shiny API when you run iOS 8.

We cheat a bit by having `PSTAlertController` superclass be `NSObject`, but for most use cases it's still a lot more convenient than using `UIAlertView`/`UIActionSheet`.

Functions that are only possible since `UIAlertController` are not back-ported. This is a simple wrapper to make your life more convenient, not a complete rewrite.

Written for [PSPDFKit, The leading framework for displaying and annotating PDFs in your iOS apps.](https://pspdfkit.com/).
It's a commercial library, but sometimes I just love to share.

## Compatbility

Tested with iOS 7 upwards, Xcode 6.1 and ARC.

## License

MIT, see LICENSE file.
