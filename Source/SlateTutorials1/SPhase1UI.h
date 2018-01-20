// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "MainMenuHUD.h"

/**
 * 
 */
class SLATETUTORIALS1_API SPhase1UI : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPhase1UI)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, MainMenuHUD)
		SLATE_END_ARGS()

		// Constructs and lays out the Main Menu UI Widget.
		// args Arguments structure th at contains widget-specific setup information.
		void Construct(const FArguments& args);

	// Click handler for the Quit Game button – Calls MenuHUD’s QuitGameClicked() event.
	FReply StartGameClicked();
	
	// Stores a weak reference to the HUD controlling this class.
	TWeakObjectPtr<class AMainMenuHUD> MainMenuHUD;
};
