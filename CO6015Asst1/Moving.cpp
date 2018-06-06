// Fill out your copyright notice in the Description page of Project Settings.

#include "Moving.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
AMoving::AMoving()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Moving = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MovingAsset(TEXT("/Engine/BasicShapes/Cube.cube"));
	if (MovingAsset.Succeeded())
	{
		Moving->SetStaticMesh(MovingAsset.Object);
		Moving->SetWorldScale3D(FVector(2.0f, 2.0f, 1.0f));
	}

	Velocity = FVector(0.0f, 400.0f, 0.0f);
	
}

// Called when the game starts or when spawned
void AMoving::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMoving::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!Velocity.IsZero())
	{
		FVector MoveTo = GetActorLocation() + (Velocity * DeltaTime);
		SetActorLocation(MoveTo);
	}

	// Create a oscillating motion
	if (GetActorLocation().Y > 800.0f)
	{
		Velocity = FVector(0.0f, -400.0f, 0.0f);
	}
	else if (GetActorLocation().Y < -800.0f)
	{
		Velocity = FVector(0.0f, 400.0f, 0.0f);
	}

	FVector  pos, bounds;
	GetActorBounds(true, pos, bounds);

	MinX = GetActorLocation().X - bounds.X;
	MaxX = GetActorLocation().X + bounds.X;
	MinY = GetActorLocation().Y - bounds.Y;
	MaxY = GetActorLocation().Y + bounds.Y;
}


bool AMoving::Mover(FVector testVector)
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

FVector AMoving::CurrentVelocity()
{
	return Velocity;
}

