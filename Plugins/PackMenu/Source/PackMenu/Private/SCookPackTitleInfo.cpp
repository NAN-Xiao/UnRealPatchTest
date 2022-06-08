// Fill out your copyright notice in the Description page of Project Settings.


#include "SCookPackTitleInfo.h"
#include "SlateOptMacros.h"
#include "Styling/SlateStyle.h"

static FSlateColorBrush borderBrush = FSlateColorBrush(FLinearColor(0.2, 0.2, 0.2, 1));
static FMargin margin = FMargin(10.0f, 10.0f, 10.0f, 10.0f);



BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SCookPackTitleInfo::Construct(const FArguments& InArgs)
{
	ChildSlot
		[
			SNew(SBorder)
			.BorderImage(&borderBrush)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.VAlign(VAlign_Top)
					[
						SNew(STextBlock)
						.Font(FCoreStyle::GetDefaultFontStyle("Cook&Pack Tools", 13))
						.Text(FText::FromString("Cook&Pack Tools"))
					]
					+ SVerticalBox::Slot()
				
					.VAlign(VAlign_Bottom)
					[
						SNew(STextBlock)

						.Text(FText::FromString("develop @ nan.xiao"))
					]
				]
				//+ SHorizontalBox::Slot()
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Right)
				[
					SNew(SBox).Padding(margin)
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(FText::FromString("version : Test_0.0"))

					]
					
				]
			]

	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
