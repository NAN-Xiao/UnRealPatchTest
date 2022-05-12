// Fill out your copyright notice in the Description page of Project Settings.


#include "SCookers.h"
#include "SlateOptMacros.h"



#include "Widgets/Input/SHyperlink.h"
#include "Widgets/Layout/SSeparator.h"
#include "Widgets/Layout/SExpandableArea.h"

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
				.AutoHeight()
				[
					SNew(SExpandableArea)
					//.AreaTitle(LOCTEXT("CookMaps", "Map(s)"))
					.InitiallyCollapsed(true)
					.Padding(8.0)
					.BodyContent()
					
					[
						SNew(STextBlock)
						.Text(FText::FromString("11"))
					]

				
				]
			
			]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
