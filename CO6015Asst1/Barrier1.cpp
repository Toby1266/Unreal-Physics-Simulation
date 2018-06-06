// Fill out your copyright notice in the Description page of Project Settings.

#include "Barrier1.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ABarrier1::ABarrier1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Barrier1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Barrier1Asset(TEXT("/Engine/BasicShapes/Cube.cube"));
	if (Barrier1Asset.Succeeded())
	{
		Barrier1->SetStaticMesh(Barrier1Asset.Object);
		Barrier1->SetWorldScale3D(FVector(25.0f, 25.0f, 1.0f));
	}
}

// Called when the game starts or when spawned
void ABarrier1::BeginPlay()
{
	Super::BeginPlay();	
}

void ABarrier1::UpdateBounds()
{
	FVector pos, bounds;
	GetActorBounds(true, pos, bounds);

	MinX = pos.X - bounds.X;
	MaxX = pos.X + bounds.X;
	MinY = pos.Y - bounds.Y;
	MaxY = pos.Y + bounds.Y;
}

// Called every frame
void ABarrier1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ABarrier1::Collision(FVector testVector, float radius)
{
	int returnFlags = 0;

		if (((testVector.X + radius) >= MinX) && ((testVector.X - radius) <= MaxX))
	{
		returnFlags |= X;
	}

	if (((testVector.Y + radius) >= MinY) && ((testVector.Y - radius) <= MaxY))
	{
		returnFlags |= Y;
	}
	return returnFlags;

}

