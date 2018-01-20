// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BotPawn.generated.h"

UCLASS()
class SLATETUTORIALS1_API ABotPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABotPawn();
	APawn* OwnerCharacter;
	int cpt = 3;
	int frameCpt = 0;
	bool moving = false;
	int energy = 30;
	bool arrived = false;
	bool canPut = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void RayCast();
	bool LineTR();
	void moveForw();
};
