// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Check3.generated.h"

UCLASS()
class CO6015ASST1_API ACheck3 : public AActor
{
	GENERATED_BODY()

private:
	UStaticMeshComponent* Checkpoint3;
	float MinX;
	float MaxX;
	float MinY;
	float MaxY;
	
public:	
	// Sets default values for this actor's properties
	ACheck3();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void UpdateBounds();
	void SetPosition(FVector pos) { SetActorLocation(pos); UpdateBounds(); }
	bool CheckpointThree(FVector TestVector);

	
	
};
