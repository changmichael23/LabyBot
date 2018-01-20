// Fill out your copyright notice in the Description page of Project Settings.

#include "BotPawn.h"
#include "Engine/World.h"
#include "Engine.h"
#include "cubeTest.h"
#include "MainMenuHUD.h"
// Sets default values
ABotPawn::ABotPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ABotPawn::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* MyController = GetWorld()->GetFirstPlayerController();
	MyController->bShowMouseCursor = true;
	MyController->bEnableClickEvents = true;
	MyController->bEnableMouseOverEvents = true;
	
	EnableInput(MyController);
	
	//OwnerCharacter = Cast<ACharacter>(GetOwner());
	//OwnerCharacter->InputComponent->BindAction("Raycast", IE_Pressed, this, &ABotPawn::RayCast);
}

// Called every frame
void ABotPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LineTR();
	FVector Movement = FVector(1, 0.0, 0.0);
	if (moving && frameCpt % 30 == 0 && !arrived)
	{
		if (LineTR())
		{
			FRotator ActorRotation = GetActorRotation();
			ActorRotation.Yaw += 90;
			SetActorRotation(ActorRotation);
			if (LineTR())
			{
				ActorRotation.Yaw -= 180;
				SetActorRotation(ActorRotation);
				if (LineTR())
				{
					ActorRotation.Yaw -= 90;
					SetActorRotation(ActorRotation);
					if (LineTR())
					{
						return;
					}
					else
					{
						moveForw();
					}
				}
				else
				{
					moveForw();
				}
			}
			else
			{
				moveForw();
			}
		}
		else
		{
			moveForw();
		}
	}
	if (energy <= 0 || arrived)
	{
		moving = false;
		AMainMenuHUD * hud = Cast<AMainMenuHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		hud->endGame();
	}
		frameCpt++;
}

// Called to bind functionality to input
void ABotPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(InputComponent);
	InputComponent->BindAction("Raycast", IE_Pressed, this, &ABotPawn::RayCast);
	
}

void ABotPawn::RayCast()
{
	APlayerController* MyController = GetWorld()->GetFirstPlayerController();
	//MyController->bShowMouseCursor = true;
	//MyController->bEnableClickEvents = true;
	//MyController->bEnableMouseOverEvents = true;
	
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	
	if (MyController != nullptr && canPut && cpt>0)
	{
		FHitResult TraceResult(ForceInit);
		MyController->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, TraceResult);
		if (TraceResult.GetActor() != nullptr)
		{
			if (GEngine)
			{
				//GetWorld()->SpawnActor(AcubeTest::StaticClass());
				FVector Location(TraceResult.GetActor()->GetActorLocation().X, TraceResult.GetActor()->GetActorLocation().Y, 100.0f);

				GetWorld()->SpawnActor<AcubeTest>(Location, Rotation, SpawnInfo);
				--cpt;
			}
		}

	}

}


bool ABotPawn::LineTR()
{
	FHitResult* hitResult = new FHitResult();
	FVector StartTrace = GetActorLocation();
	FVector ForwardVector = GetActorForwardVector();
	FVector EndTrace = ((ForwardVector*100.0f) + StartTrace);
	StartTrace = ((ForwardVector*50.0f) + StartTrace);

	FCollisionQueryParams* TraceParams = new FCollisionQueryParams();
	DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor(255, 0, 0), true);
	if (GetWorld()->LineTraceSingleByChannel(*hitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams))
	{
		return true;
	}
	return false;

}

void ABotPawn::moveForw()
{

	
	FVector ActorLocation = GetActorLocation();
	FVector ForwardVector = GetActorForwardVector()*100.0f;
	ActorLocation += ForwardVector;
	SetActorLocation(ActorLocation, false);
	--energy;
	// End Game
	if (GetActorLocation().X >= -10 && GetActorLocation().X <= 10 && GetActorLocation().Y>= 1290 && GetActorLocation().Y <= 1310)
	{
		arrived = true;
	}

}