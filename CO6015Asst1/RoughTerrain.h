// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoughTerrain.generated.h"

UCLASS()
class CO6015ASST1_API ARoughTerrain : public AActor
{
	GENERATED_BODY()	

private:
	UStaticMeshComponent* RoughTerrain;
	float MinX;
	float MaxX;
	float MinY;
	float MaxY;

public:	
	// Sets default values for this actor's properties
	ARoughTerrain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void UpdateBounds();
	void SetPosition(FVector pos) { SetActorLocation(pos); UpdateBounds(); }
	bool OnRoughTerrain(FVector TestVector);	
};
