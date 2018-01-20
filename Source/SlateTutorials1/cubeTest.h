// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "cubeTest.generated.h"

UCLASS()
class SLATETUTORIALS1_API AcubeTest : public AActor
{
	GENERATED_BODY()

public:
	AcubeTest();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime);

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Mesh")
		UStaticMeshComponent *MeshComp;
	
};
