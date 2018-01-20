// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"


#include "SlateTutorials1.h"
#include "MainMenuHUD.h"



AMyGameModeBase::AMyGameModeBase()
{
	HUDClass = AMainMenuHUD::StaticClass();
/*
	APlayerController* MyController = GetWorld()->GetFirstPlayerController();
	
	MyController->bShowMouseCursor = true;
	MyController->bEnableClickEvents = true;
	MyController->bEnableMouseOverEvents = true;*/
}

