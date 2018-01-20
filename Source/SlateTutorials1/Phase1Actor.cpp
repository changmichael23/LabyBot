// Fill out your copyright notice in the Description page of Project Settings.

#include "Phase1Actor.h"


// Sets default values
APhase1Actor::APhase1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APhase1Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhase1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

