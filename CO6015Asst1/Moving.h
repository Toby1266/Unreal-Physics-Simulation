// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Moving.generated.h"

UCLASS()
class CO6015ASST1_API AMoving : public AActor
{
	GENERATED_BODY()

private:
	UStaticMeshComponent* Moving;
	float MinX;
	float MaxX;
	float MinY;
	float MaxY;

	FVector Velocity;
	FVector CurrentVelocity();


public:	
	// Sets default values for this actor's properties
	AMoving();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetPosition(FVector pos) { SetActorLocation(pos); }
	bool Mover(FVector TestVector);
	

	
	
};
