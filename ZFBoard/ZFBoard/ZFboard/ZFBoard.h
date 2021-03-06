//
//  ZFBoard.h
//  ZFBoard
//
//  Created by 张帆 on 2018/12/19.
//  Copyright © 2018 张帆. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


#define ZFBOARD_GARY_TEXT_COLOR [UIColor colorWithRed:114/255.0 green:98/255.0 blue:98/255.0 alpha:1]
#define ZFBOARD_NOMAL_BUTTON_BACKGROUND_COLOR [UIColor colorWithRed:62/255.0 green:151/255.0 blue:253/255.0 alpha:1]
#define ZFBOARD_UNABLE_BUTTON_BACKGROUND_COLOR [UIColor colorWithRed:179/255.0 green:179/255.0 blue:179/255.0 alpha:1]
#define ZFBOARD_DONE_BUTTON_BACKGROUND_COLOR [UIColor colorWithRed:98/255.0 green:227/255.0 blue:94/255.0 alpha:1]


@interface ZFBoardLabel : UILabel

@end
@interface ZFBoardImageView : UIImageView

@end

typedef NS_ENUM(NSUInteger, ZFBoardButtonType) {
    ZFBoardButtonTypeSTART,
    ZFBoardButtonTypeNOMAL,
    ZFBoardButtonTypeUNABLE,
    ZFBoardButtonTypeLOADING,
    ZFBoardButtonTypeSUCCESS,
    ZFBoardButtonTypeEND,
};

@interface ZFBoardButton : UIButton
@property (nonatomic, assign) ZFBoardButtonType type;
@property (nonatomic, assign) float progress;

@end


@interface ZFBoardItem : NSObject

@property (nonatomic, strong, readonly, nullable) ZFBoardItem *nextItem;
@property (nonatomic, strong, readonly, nullable) ZFBoardItem *perviousItem;
- (ZFBoardItem *(^)(ZFBoardItem *item))next;



@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIColor *titleColor;

@property (nonatomic, copy) NSString *imageName;

@property (nonatomic, copy) NSString *detial1text;
@property (nonatomic, strong) UIFont *detial1textFont;
@property (nonatomic, strong) UIColor *detial1textColor;

@property (nonatomic, copy) NSString *detial2text;
@property (nonatomic, strong) UIFont *detial2textFont;
@property (nonatomic, strong) UIColor *detial2textColor;

@property (nonatomic, copy) NSString *introduceText;
@property (nonatomic, strong) UIFont *introduceTextFont;
@property (nonatomic, strong) UIColor *introduceTextColor;

@property (nonatomic, copy) NSString *actionButtonTitle;
@property (nonatomic, strong) UIColor *actionButtonBackgroundColor;
@property (nonatomic, assign) float actionButtonCornerRadius;
@property (nonatomic, copy) void(^actionButtonAction)(ZFBoardButton *button);

@property (nonatomic, copy) NSString *closeButtonImageName;
@property (nonatomic, assign) BOOL showCloseButton;
@property (nonatomic, copy) void(^closeButtonAction)(ZFBoardButton *button);


@property (nonatomic, copy) void(^willShow)(ZFBoardItem *x);
@property (nonatomic, copy) void(^didShow)(ZFBoardItem *x);
@property (nonatomic, copy) void(^willDimiss)(ZFBoardItem *x);



@end

@interface ZFBoardItemsVC : UIViewController

@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, strong) UIStackView *stackView;
@property (nonatomic, strong) ZFBoardLabel *titleLabel;
@property (nonatomic, strong) UIButton *closeButton;
@property (nonatomic, strong) ZFBoardImageView *imageView;
@property (nonatomic, strong) ZFBoardLabel *detialLabel1;
@property (nonatomic, strong) ZFBoardLabel *detialLabel2;
@property (nonatomic, strong) ZFBoardLabel *introduceLabel;
@property (nonatomic, strong) ZFBoardButton *actionButton;
@property (nonatomic, strong) UIActivityIndicatorView *indicatorView;
@property (nonatomic, strong) UIView *customView;

@property (nonatomic, strong) ZFBoardItem *currentItem;

@end


@interface ZFBoard : NSObject


/**
 Present items in current target
 */

- (void)showItem:(ZFBoardItem *)item;
@property (nonatomic, strong) ZFBoardItemsVC *boardVc;
- (void)loadNext;
- (void)loadPervious;
- (void)hiden;
@end

NS_ASSUME_NONNULL_END
