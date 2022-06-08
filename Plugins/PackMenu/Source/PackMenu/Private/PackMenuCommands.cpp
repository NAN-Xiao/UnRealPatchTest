// Copyright Epic Games, Inc. All Rights Reserved.

#include "PackMenuCommands.h"

#define LOCTEXT_NAMESPACE "FPackMenuModule"

void FPackMenuCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "PackMenu", "Bring up PackMenu window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
