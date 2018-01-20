// Fill out your copyright notice in the Description page of Project Settings.

/**
* MainMenuUI.h – Provides an implementation of the Slate UI representing the main menu.
*/

#pragma once

#include "SlateBasics.h"
#include "MainMenuHUD.h"

// Lays out and controls the Main Menu UI for our tutorial.
class SLATETUTORIALS1_API SMainMenuUI : public SCompoundWidget
{

public:
	SLATE_BEGIN_ARGS(SMainMenuUI)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, MainMenuHUD)
		SLATE_END_ARGS()

		// Constructs and lays out the Main Menu UI Widget.
		// args Arguments structure th at contains widget-specific setup information.
		void Construct(const FArguments& args);

	// Click handler for the Play Game! button – Calls MenuHUD’s PlayGameClicked() event.
	FReply PlayGameClicked();

	// Click handler for the Quit Game button – Calls MenuHUD’s QuitGameClicked() event.
	FReply QuitGameClicked();

	// Stores a weak reference to the HUD controlling this class.
	TWeakObjectPtr<class AMainMenuHUD> MainMenuHUD;
};