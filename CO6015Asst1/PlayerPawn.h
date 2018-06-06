// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Barrier1.h"
#include "Barrier2.h"
#include "RoughTerrain.h"
#include "Check1.h"
#include "Check2.h"
#include "Check3.h"
#include "FinishLine.h"
#include "Moving.h"
#include "PlayerPawn.generated.h"

#define CAPSULERADIUS (70.0f)

UCLASS()
class CO6015ASST1_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	//Sets default values for this pawn's properties.
	APlayerPawn();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PlayerCube;

	//declare floats for chracter movement.
	void MoveX(float AxisValue);
	void MoveY(float AxisValue);

	float Steering;
	float Acceleration;
	float CurrentLap;
	float PreviousLap;
	float BestLap;

	bool NewLap;
	bool Check1;
	bool Check2;
	bool Check3;
	
	int ClosestBarrierTimer;
	int SecondClosestBarrierTimer;
	int RoughTerrainTimer;
	int MovingObjectTimer;
	int FlagColl;
	int SecondFlagColl;

	ABarrier1* ClosestBarrier;
	ABarrier2* SecondClosestBarrier;
	ARoughTerrain* ClosestRoughTerrain;
	ACheck1* FoundCheckpoint1;
	ACheck2* FoundCheckpoint2;
	ACheck3* FoundCheckpoint3;
	AFinishLine* FoundFinishLine;
	AMoving* FoundMoving;

	//Function to find closest
	ABarrier1* FindClosestBarrier();
	ABarrier2* FindSecondClosestBarrier();
	ARoughTerrain* FindClosestRoughTerrain();
	ACheck1* FindCheckpoint1();
	ACheck2* FindCheckpoint2();
	ACheck3* FindCheckpoint3();
	AFinishLine* FindFinishLine();
	AMoving* FindMoving();



	//Float of delta time.
	float CurrentDeltaTime;
	//Vector representing pawn's velocity.
	FVector CurrentVelocity;
	FVector StartLocation;
	FTimerHandle Stopwatch;

	void Time();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
