// Fill out your copyright notice in the Description page of Project Settings.

#include "SEndGame.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SEndGame::Construct(const FArguments& args)
{
	MainMenuHUD = args._MainMenuHUD;

	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(STextBlock)
			.ColorAndOpacity(FLinearColor::White)
		.ShadowColorAndOpacity(FLinearColor::Black)
		.ShadowOffset(FIntPoint(-1, 1))
		.Font(FSlateFontInfo("Arial", 26))
		.Text(this,&SEndGame::GetText)
		]
		];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION


FText SEndGame::GetText() const
{
	return MainMenuHUD->getText();
}