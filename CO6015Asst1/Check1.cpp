// Fill out your copyright notice in the Description page of Project Settings.

#include "Check1.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ACheck1::ACheck1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Checkpoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CheckpointAsset(TEXT("/Engine/BasicShapes/Cube.cube"));
	if (CheckpointAsset.Succeeded())
	{
		Checkpoint->SetStaticMesh(CheckpointAsset.Object);
		Checkpoint->SetWorldScale3D(FVector(15.0f, 1.0f, 0.5f));
	}
}

// Called when the game starts or when spawned
void ACheck1::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACheck1::UpdateBounds()
{
	FVector pos, bounds;
	GetActorBounds(true, pos, bounds);

	MinX = pos.X - bounds.X;
	MaxX = pos.X + bounds.X;
	MinY = pos.Y - bounds.Y;
	MaxY = pos.Y + bounds.Y;
}

bool ACheck1::Checkpoint1(FVector testVector)
{
	if ((testVector.X >= MinX) && (testVector.X <= MaxX) && (testVector.Y >= MinY) && (testVector.Y <= MaxY))
	{
		return true;
	}
	else
	{
		return false;
	}
}
// Called every frame
void ACheck1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

