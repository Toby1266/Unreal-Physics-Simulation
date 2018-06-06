// Fill out your copyright notice in the Description page of Project Settings.

#include "Check2.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ACheck2::ACheck2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Checkpoint2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Checkpoint2Asset(TEXT("/Engine/BasicShapes/Cube.cube"));
	if (Checkpoint2Asset.Succeeded())
	{
		Checkpoint2->SetStaticMesh(Checkpoint2Asset.Object);
		Checkpoint2->SetWorldScale3D(FVector(1.0f, 15.0f, 0.5f));
	}

}

// Called when the game starts or when spawned
void ACheck2::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACheck2::UpdateBounds()
{
	FVector pos, bounds;
	GetActorBounds(true, pos, bounds);

	MinX = pos.X - bounds.X;
	MaxX = pos.X + bounds.X;
	MinY = pos.Y - bounds.Y;
	MaxY = pos.Y + bounds.Y;
}

bool ACheck2::CheckpointToo(FVector testVector)
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
void ACheck2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

