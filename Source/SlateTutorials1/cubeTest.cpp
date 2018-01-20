#include "cubeTest.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

#include "Engine.h"

AcubeTest::AcubeTest()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube'"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> cubeMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> Mat(TEXT("Materials'/Game/StarterContent/Materials/M_Wood_Walnut'"));
	//MeshComp->set
	RootComponent = MeshComp;
	MeshComp->SetStaticMesh(cubeMesh.Object);
	MeshComp->SetMaterial(0,Mat.Object);

}

void AcubeTest::BeginPlay()
{
	Super::BeginPlay();
}

void AcubeTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}