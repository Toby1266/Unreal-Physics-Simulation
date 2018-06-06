// Fill out your copyright notice in the Description page of Project Settings.

#include "Check3.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ACheck3::ACheck3()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Checkpoint3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Checkpoint3Asset(TEXT("/Engine/BasicShapes/Cube.cube"));
	if (Checkpoint3Asset.Succeeded())
	{
		Checkpoint3->SetStaticMesh(Checkpoint3Asset.Object);
		Checkpoint3->SetWorldScale3D(FVector(15.0f, 1.0f, 0.5f));
	}

}

// Called when the game starts or when spawned
void ACheck3::BeginPlay()
{
	Super::BeginPlay();

}

void ACheck3::UpdateBounds()
{
	FVector pos, bounds;
	GetActorBounds(true, pos, bounds);

	MinX = pos.X - bounds.X;
	MaxX = pos.X + bounds.X;
	MinY = pos.Y - bounds.Y;
	MaxY = pos.Y + bounds.Y;
}

bool ACheck3::CheckpointThree(FVector testVector)
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
void ACheck3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

