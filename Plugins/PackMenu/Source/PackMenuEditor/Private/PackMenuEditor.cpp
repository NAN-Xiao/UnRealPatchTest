// Copyright Epic Games, Inc. All Rights Reserved.

#include "PackMenuEditor.h"
#include "PackMenuStyle.h"
#include "PackMenuCommands.h"
#include "LevelEditor.h"
#include "Widgets/Input/SHyperlink.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/SBoxPanel.h"
#include "ToolMenus.h"
#include "CookPage/CookPage.h"
static const FName PackMenuTabName("PackMenu");

#define LOCTEXT_NAMESPACE "FPackMenuModule"

void FPackMenuEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FPackMenuStyle::Initialize();
	FPackMenuStyle::ReloadTextures();

	FPackMenuCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FPackMenuCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FPackMenuEditorModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FPackMenuEditorModule::RegisterMenus));

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(PackMenuTabName, FOnSpawnTab::CreateRaw(this, &FPackMenuEditorModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FPackMenuTabTitle", "PackMenu"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FPackMenuEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FPackMenuStyle::Shutdown();

	FPackMenuCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(PackMenuTabName);
}

void FPackMenuEditorModule::OnTabClosed(TSharedRef<SDockTab> InTab)
{
	FPackMenuEditorModule::DockTab.Reset();
}


TSharedRef<SDockTab> FPackMenuEditorModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{

	return SAssignNew(DockTab, SDockTab)
		.TabRole(ETabRole::NumRoles)
		.Label(LOCTEXT("Cook&PackTable", "Cook&Pack"))
		.ToolTipText(LOCTEXT("Cook&PackTableTips", "Cook&Pack Tools"))
		.OnTabClosed(SDockTab::FOnTabClosedCallback::CreateRaw(this, &FPackMenuEditorModule::OnTabClosed))
		.Clipping(EWidgetClipping::ClipToBounds)
		[
			SNew(CookPage)
		];

















	//FText WidgetText = FText::Format(
	//	LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
	//	FText::FromString(TEXT("FPackMenuModule::OnSpawnPluginTab")),
	//	FText::FromString(TEXT("PackMenu.cpp"))
	//);

	//return SNew(SDockTab)
	//	.TabRole(ETabRole::NomadTab)
	//	[
	//		
	//			SNew(SBorder)
	//			.Padding(2)
	//	[
	//		SNew(SHorizontalBox)
	//		+ SHorizontalBox::Slot()
	//	.FillWidth(10.0f)
	//	.VAlign(VAlign_Center)
	//	.Padding(4.0f, 0.0f, 4.0f, 0.0f)
	//	[

	//		SNew(SHorizontalBox)
	//		+ SHorizontalBox::Slot()
	//	.AutoWidth()
	//	.VAlign(VAlign_Center)
	//	[
	//		SNew(SBox)
	//		.WidthOverride(40)
	//	.HeightOverride(40)
	//	[
	//	
	//			SNew(STextBlock)
	//			.Text_Raw(this, &FPackMenuModule::GetTitle)
	//		
	//	]
	//	
	//	]
	//	]
	////// Put your tab content here!
	////SNew(SBox)
	////.HAlign(HAlign_Center)
	////.VAlign(VAlign_Center)
	////[
	////	SNew(STextBlock)
	////	.Text(WidgetText)
	////]
	//		]
	//		];
}

void FPackMenuEditorModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(PackMenuTabName);
}

void FPackMenuEditorModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FPackMenuCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FPackMenuCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPackMenuEditorModule, PackMenu)