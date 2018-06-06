// Fill out your copyright notice in the Description page of Project Settings.

#include "RoughTerrain.h"

#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ARoughTerrain::ARoughTerrain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RoughTerrain = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> RoughTerrainAsset(TEXT("/Engine/BasicShapes/Cube.cube"));
	if (RoughTerrainAsset.Succeeded())
	{
		RoughTerrain->SetStaticMesh(RoughTerrainAsset.Object);
		RoughTerrain->SetWorldScale3D(FVector(5.0f, 5.0f, 0.5f));
	}
}

// Called when the game starts or when spawned
void ARoughTerrain::BeginPlay()
{
	Super::BeginPlay();	
}

void ARoughTerrain::UpdateBounds()
{
	FVector pos, bounds;
	GetActorBounds(true, pos, bounds);

	MinX = pos.X - bounds.X;
	MaxX = pos.X + bounds.X;
	MinY = pos.Y - bounds.Y;
	MaxY = pos.Y + bounds.Y;
}

bool ARoughTerrain::OnRoughTerrain(FVector testVector)
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
void ARoughTerrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

