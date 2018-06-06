// Fill out your copyright notice in the Description page of Project Settings.

#include "Barrier2.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ABarrier2::ABarrier2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Barrier2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Barrier2Asset(TEXT("/Engine/BasicShapes/Cube.cube"));
	if (Barrier2Asset.Succeeded())
	{
		Barrier2->SetStaticMesh(Barrier2Asset.Object);
		Barrier2->SetWorldScale3D(FVector(25.0f, 25.0f, 1.0f));
	}
}

// Called when the game starts or when spawned
void ABarrier2::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABarrier2::UpdateBounds()
{
	FVector pos, bounds;
	GetActorBounds(true, pos, bounds);

	MinX = pos.X - bounds.X;
	MaxX = pos.X + bounds.X;
	MinY = pos.Y - bounds.Y;
	MaxY = pos.Y + bounds.Y;
}

// Called every frame
void ABarrier2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ABarrier2::SecondCollision(FVector TestVector, float Radius)
{
	int returnFlags = 0;

	if (((TestVector.X + Radius) >= MinX) && ((TestVector.X - Radius) <= MaxX))
	{
		returnFlags |= X;
	}

	if (((TestVector.Y + Radius) >= MinY) && ((TestVector.Y - Radius) <= MaxY))
	{
		returnFlags |= Y;
	}
	return returnFlags;

}

