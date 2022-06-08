// Fill out your copyright notice in the Description page of Project Settings.


#include "CookPackWidgetStyle.h"

FCookPackStyle::FCookPackStyle()
{
}

FCookPackStyle::~FCookPackStyle()
{
}

const FName FCookPackStyle::TypeName(TEXT("FCookPackStyle"));

const FCookPackStyle& FCookPackStyle::GetDefault()
{
	static FCookPackStyle Default;
	return Default;
}

void FCookPackStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

