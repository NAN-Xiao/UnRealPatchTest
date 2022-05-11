// Fill out your copyright notice in the Description page of Project Settings.


#include "CookPage/CookPage.h"
#include "SlateOptMacros.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/Layout/SSeparator.h"
#include "Widgets/Layout/SScrollBox.h"
#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"
#include "SCookPackInfoMation.h"
#define LOCTEXT_NAMESPACE "FPackMenuModule"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
static FSlateColorBrush colorbrush =  FSlateColorBrush(FLinearColor(1, 0, 0, 0));
void CookPage::Construct(const FArguments& InArgs)
{

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SCookPackInfoMation)

			]

		]
		
	
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE