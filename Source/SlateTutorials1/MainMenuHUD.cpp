// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#include "MainMenuHUD.h"
#include "SlateTutorials1.h"
#include <string>
#include "SMainMenuUI.h"
#include "SPhase1UI.h"
#include "Engine.h"
#include "SEnergyBar.h"
#include "SEndGame.h"
#include "BotPawn.h"

void AMainMenuHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SAssignNew(MainMenuUI, SMainMenuUI).MainMenuHUD(this);

	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MainMenuUI.ToSharedRef()));
	}
}

void AMainMenuHUD::PlayGameClicked()
{
	SAssignNew(Phase1UI, SPhase1UI).MainMenuHUD(this);
	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->RemoveAllViewportWidgets();
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(Phase1UI.ToSharedRef()));
		ABotPawn* Pawn = Cast<ABotPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
		Pawn->canPut = true;
	}
}

void AMainMenuHUD::QuitGameClicked()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}

void AMainMenuHUD::StartGameClicked()
{
	// Lancer Bot et UI du bot
	SAssignNew(EnergyBar, SEnergyBar).MainMenuHUD(this);
	GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(EnergyBar.ToSharedRef()));
	ABotPawn* Pawn = Cast<ABotPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	Pawn->moving = true;
	Pawn->canPut = false;
}

float AMainMenuHUD::getEnergy()
{
	ABotPawn* Pawn = Cast<ABotPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	return Pawn->energy / 30.0f;
}


void AMainMenuHUD::endGame()
{
	SAssignNew(EndGame, SEndGame).MainMenuHUD(this);
	GEngine->GameViewport->RemoveAllViewportWidgets();
	GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(EndGame.ToSharedRef()));
}

FText AMainMenuHUD::getText()
{
	ABotPawn* Pawn = Cast<ABotPawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (Pawn->arrived)
	{
		FString s = "Win Score : ";
		s.AppendInt(Pawn->energy + Pawn->cpt * 10);

		return FText::FromString(s);	
	}
	return FText::FromString("Lose");
}