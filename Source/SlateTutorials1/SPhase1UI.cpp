#include "SPhase1UI.h"
#include "SlateTutorials1.h"

#include "Engine.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SPhase1UI::Construct(const FArguments& args)
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
		.Text(FText::FromString(""))
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		[
			SNew(SVerticalBox)
	+ SVerticalBox::Slot()
		[
			SNew(SButton)
			.Text(FText::FromString("Start Game"))
		.OnClicked(this, &SPhase1UI::StartGameClicked)
		]
		]
		];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION


FReply SPhase1UI::StartGameClicked()
{
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("StartGameClicked"));
	}
	
	GEngine->GameViewport->RemoveAllViewportWidgets();
	FSlateApplication::Get().SetAllUserFocusToGameViewport();

	// actually the BlueprintImplementable function of the HUD is not called; uncomment if you want to handle the OnClick via Blueprint
	MainMenuHUD->StartGameClicked();
	return FReply::Handled();
}