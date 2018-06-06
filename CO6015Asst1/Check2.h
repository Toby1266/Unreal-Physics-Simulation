// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Check2.generated.h"

UCLASS()
class CO6015ASST1_API ACheck2 : public AActor
{
	GENERATED_BODY()

private:
	UStaticMeshComponent* Checkpoint2;
	float MinX;
	float MaxX;
	float MinY;
	float MaxY;
	
public:	
	// Sets default values for this actor's properties
	ACheck2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void UpdateBounds();
	void SetPosition(FVector pos) { SetActorLocation(pos); UpdateBounds(); }
	bool CheckpointToo(FVector TestVector);

	
	
};
