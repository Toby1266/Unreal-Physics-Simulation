// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Check1.generated.h"

UCLASS()
class CO6015ASST1_API ACheck1 : public AActor
{
	GENERATED_BODY()

private:
	UStaticMeshComponent* Checkpoint;
	float MinX;
	float MaxX;
	float MinY;
	float MaxY;
	
public:	
	// Sets default values for this actor's properties
	ACheck1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void UpdateBounds();
	void SetPosition(FVector pos) { SetActorLocation(pos); UpdateBounds(); }
	bool Checkpoint1(FVector TestVector);	
	
};
