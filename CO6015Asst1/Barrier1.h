// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Barrier1.generated.h"

UCLASS()
class CO6015ASST1_API ABarrier1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrier1();

	enum CFlags
	{
		X = 1,
		Y = 2,
	};

private:
	UStaticMeshComponent* Barrier1;
	float MinX;
	float MaxX;
	float MinY;
	float MaxY;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void UpdateBounds();
	void SetPosition(FVector pos) { SetActorLocation(pos); UpdateBounds(); }
	int Collision(FVector testVector, float radius);

	
	
};
