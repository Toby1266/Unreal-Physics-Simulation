// Fill out your copyright notice in the Description page of Project Settings.

#include "FinishLine.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
AFinishLine::AFinishLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Finish = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> FinishAsset(TEXT("/Engine/BasicShapes/Cube.cube"));
	if (FinishAsset.Succeeded())
	{
		Finish->SetStaticMesh(FinishAsset.Object);
		Finish->SetWorldScale3D(FVector(3.0f, 15.0f, 0.5f));
	}
}

// Called when the game starts or when spawned
void AFinishLine::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFinishLine::UpdateBounds()
{
	FVector pos, bounds;
	GetActorBounds(true, pos, bounds);

	MinX = pos.X - bounds.X;
	MaxX = pos.X + bounds.X;
	MinY = pos.Y - bounds.Y;
	MaxY = pos.Y + bounds.Y;
}

bool AFinishLine::FinishLine(FVector testVector)
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
void AFinishLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

