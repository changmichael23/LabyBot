#pragma once

#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

/**
* Provides an implementation of the game’s Main Menu HUD, which will embed and respond to events triggered
* within SMainMenuUI.
*/
UCLASS()
class SLATETUTORIALS1_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()
		// Initializes the Slate UI and adds it as widget content to the game viewport.
		virtual void PostInitializeComponents() override;

	// Reference to the Main Menu Slate UI.
	TSharedPtr<class SMainMenuUI> MainMenuUI;
	TSharedPtr<class SPhase1UI> Phase1UI;
	TSharedPtr<class SEnergyBar> EnergyBar;
	TSharedPtr<class SEndGame> EndGame;
public:
	// Called by SMainMenu whenever the Play Game! button has been clicked.
	//UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Main Menu")
		void PlayGameClicked();

	// Called by SMainMenu whenever the Quit Game button has been clicked.
	//UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Main Menu")
		void QuitGameClicked();


		void StartGameClicked();
		void endGame();
		float getEnergy();

		FText getText();
};