#
# Be sure to run `pod lib lint PSTAlertController.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "PSTAlertController"
  s.version          = "1.2.0"
  s.summary          = "API similar to UIAlertController, backwards compatible to iOS 7. Will use the new shiny API when you run iOS 8. "
  s.description      = <<-DESC
                       We cheat a bit by having PSTAlertController superclass be NSObject, but for most use cases it's still a lot more convenient than using UIAlertView/UIActionSheet.
                       DESC
  s.homepage         = "https://github.com/steipete/PSTAlertController"
  s.license          = 'MIT'
  s.author           = { "Peter Steinberger" => "steipete@gmail.com" }
  s.source           = { :git => "https://github.com/steipete/PSTAlertController.git", :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/steipete'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'PSTAlertController'
  s.public_header_files = 'PSTAlertController/**/*.h'
  s.frameworks = 'UIKit'
end