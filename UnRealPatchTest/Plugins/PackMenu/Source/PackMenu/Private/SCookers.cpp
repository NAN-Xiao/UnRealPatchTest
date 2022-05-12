// Fill out your copyright notice in the Description page of Project Settings.


#include "SCookers.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SCookers::Construct(const FArguments& InArgs)
{
	
	ChildSlot
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.Padding(0, 15, 0, 0)
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
				.Font(FCoreStyle::GetDefaultFontStyle("Cook",13))
				.Text(FText::FromString("Cook"))
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				[
				
				]
			
			]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
