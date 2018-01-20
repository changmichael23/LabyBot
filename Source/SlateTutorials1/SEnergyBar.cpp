#include "SEnergyBar.h"
#include "SlateTutorials1.h"
#include "Engine.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SEnergyBar::Construct(const FArguments& args)
{
	MainMenuHUD = args._MainMenuHUD;
	
	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(SBox)
			.WidthOverride(1000.f)
		.HeightOverride(100.f)
		[
			SNew(SProgressBar)
			.Percent(this,&SEnergyBar::GetEnergy)
		]
		]
		];


}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

TOptional<float> SEnergyBar::GetEnergy() const
{
	//ABotPawn* Pawn;
	//UGameplayStatics::GetPlayerPawn(GEngine->GetWorld(), 0);
	//ABotPawn* Pawn = Cast<ABotPawn>(UGameplayStatics::GetPlayerPawn(GEngine->GetWorld(), 0));
	
	return  MainMenuHUD->getEnergy();

}