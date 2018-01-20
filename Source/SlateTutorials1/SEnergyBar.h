// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "MainMenuHUD.h"

/**
*
*/
class SLATETUTORIALS1_API SEnergyBar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SEnergyBar)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, MainMenuHUD)
		SLATE_END_ARGS()

		// Constructs and lays out the Main Menu UI Widget.
		// args Arguments structure th at contains widget-specific setup information.
		void Construct(const FArguments& args);


	// Stores a weak reference to the HUD controlling this class.
	TWeakObjectPtr<class AMainMenuHUD> MainMenuHUD;
	TOptional<float> GetEnergy() const;
};
