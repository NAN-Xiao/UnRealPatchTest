// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "PackMenuStyle.h"

class FPackMenuCommands : public TCommands<FPackMenuCommands>
{
public:

	FPackMenuCommands()
		: TCommands<FPackMenuCommands>(TEXT("PackMenu"), NSLOCTEXT("Contexts", "PackMenu", "PackMenu Plugin"), NAME_None, FPackMenuStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};