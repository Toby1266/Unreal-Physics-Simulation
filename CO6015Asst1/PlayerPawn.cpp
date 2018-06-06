// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawn.h"
#include "CO6015Asst1.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
	//Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Allow pawn to be controlled by lowest-numbered player.
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Create a camera and a visible object
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	PlayerCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerCube"));

	// Attach our camera and visible object to our root component. Offset and rotate the camera.
	Camera->SetupAttachment(RootComponent);
	Camera->SetRelativeLocation(FVector(0.0f, 0.0f, 1200.0f));
	Camera->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlayerCubeAsset(TEXT("/Engine/BasicShapes/Cube.cube"));

	if (PlayerCubeAsset.Succeeded())
	{
		PlayerCube->SetStaticMesh(PlayerCubeAsset.Object);
	}


}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	//Declare initial value for delta time.
	CurrentDeltaTime = 0.0f;

	ABarrier1 *CreateBarrier1 = (ABarrier1*)GWorld->SpawnActor(ABarrier1::StaticClass());
	CreateBarrier1->SetPosition(FVector(3750.0f, -1250.0f, 30.0f));
	ABarrier1 *CreateBarrier2 = (ABarrier1*)GWorld->SpawnActor(ABarrier1::StaticClass());
	CreateBarrier2->SetPosition(FVector(-3750.0f, 1250.0f, 30.0f));
	ABarrier1 *CreateBarrier3 = (ABarrier1*)GWorld->SpawnActor(ABarrier1::StaticClass());
	CreateBarrier3->SetPosition(FVector(-1250.0f, -3750.0f, 30.0f));
	ABarrier1 *CreateBarrier4 = (ABarrier1*)GWorld->SpawnActor(ABarrier1::StaticClass());
	CreateBarrier4->SetPosition(FVector(1250.0f, 3750.0f, 30.0f));

	ABarrier2 *CreateBarrier5 = (ABarrier2*)GWorld->SpawnActor(ABarrier2::StaticClass());
	CreateBarrier5->SetPosition(FVector(3750.0f, 1250.0f, 30.0f));
	ABarrier2 *CreateBarrier6 = (ABarrier2*)GWorld->SpawnActor(ABarrier2::StaticClass());
	CreateBarrier6->SetPosition(FVector(-3750.0f, -1250.0f, 30.0f));
	ABarrier2 *CreateBarrier7 = (ABarrier2*)GWorld->SpawnActor(ABarrier2::StaticClass());
	CreateBarrier7->SetPosition(FVector(-1250.0f, 3750.0f, 30.0f));
	ABarrier2 *CreateBarrier8 = (ABarrier2*)GWorld->SpawnActor(ABarrier2::StaticClass());
	CreateBarrier8->SetPosition(FVector(1250.0f, -3750.0f, 30.0f));

	ABarrier1 *CreateBarrier9 = (ABarrier1*)GWorld->SpawnActor(ABarrier1::StaticClass());
	CreateBarrier9->SetPosition(FVector(0.0f, 0.0f, 30.0f));

	ARoughTerrain *CreateTerrain1 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain1->SetPosition(FVector(2250.0f, 0.0f, 30.0f));
	ARoughTerrain *CreateTerrain2 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain2->SetPosition(FVector(1500.0f, 0.0f, 30.0f));
	ARoughTerrain *CreateTerrain3 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain3->SetPosition(FVector(0.0f, -2250.0f, 30.0f));
	ARoughTerrain *CreateTerrain4 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain4->SetPosition(FVector(0.0f, -1750.0f, 30.0f));
	ARoughTerrain *CreateTerrain5 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain5->SetPosition(FVector(-2250.0f, 0.0f, 30.0f));
	ARoughTerrain *CreateTerrain6 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain6->SetPosition(FVector(-1500.0f, 0.0f, 30.0f));
	ARoughTerrain *CreateTerrain7 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain7->SetPosition(FVector(-1500.0f, -1500.0f, 30.0f));
	ARoughTerrain *CreateTerrain8 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain8->SetPosition(FVector(1400.0f, -1400.0f, 30.0f));
	ARoughTerrain *CreateTerrain9 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain9->SetPosition(FVector(1650.0f, 1650.0f, 30.0f));
	ARoughTerrain *CreateTerrain10 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain10->SetPosition(FVector(-1600.0f, 1300.0f, 30.0f));
	ARoughTerrain *CreateTerrain11 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain11->SetPosition(FVector(-2250.0f, 2000.0f, 30.0f));
	ARoughTerrain *CreateTerrain12 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain12->SetPosition(FVector(-1400.0f, -1800.0f, 30.0f));
	ARoughTerrain *CreateTerrain13 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain13->SetPosition(FVector(-1700.0f, -1300.0f, 30.0f));
	ARoughTerrain *CreateTerrain14 = (ARoughTerrain*)GWorld->SpawnActor(ARoughTerrain::StaticClass());
	CreateTerrain14->SetPosition(FVector(1400.0f, -1700.0f, 30.0f));


	ACheck1 *CreateCheck1 = (ACheck1*)GWorld->SpawnActor(ACheck1::StaticClass());
	CreateCheck1->SetPosition(FVector(1750.0f, -950.0f, -30.0f));
	ACheck2 *CreateCheck2 = (ACheck2*)GWorld->SpawnActor(ACheck2::StaticClass());
	CreateCheck2->SetPosition(FVector(-1000.0f, -1750.0f, -30.0f));
	ACheck3 *CreateCheck3 = (ACheck3*)GWorld->SpawnActor(ACheck3::StaticClass());
	CreateCheck3->SetPosition(FVector(-1750.0f, 950.0f, -30.0f));
	AFinishLine *CreateFinish = (AFinishLine*)GWorld->SpawnActor(AFinishLine::StaticClass());
	CreateFinish->SetPosition(FVector(0.0f, 1750, 30.0f));


	AMoving *CreateMoving1 = (AMoving*)GWorld->SpawnActor(AMoving::StaticClass());
	CreateMoving1->SetPosition(FVector(-1875.0f, 0.0f, 30.0f));
	AMoving *CreateMoving2 = (AMoving*)GWorld->SpawnActor(AMoving::StaticClass());
	CreateMoving2->SetPosition(FVector(1875.0f, 0.0f, 30.0f));


	FlagColl = 0;
	SecondFlagColl = 0;
	CurrentLap = 0;
	PreviousLap = 0;
	BestLap = 0;
	NewLap = false;
	Check1 = false;
	Check2 = false;
	Check3 = false;
	StartLocation = FVector(0.0f, 1750.0f, 30.0f);


	GetWorld()->GetTimerManager().SetTimer(Stopwatch, this, &APlayerPawn::Time, 0.1f, true);
	FoundCheckpoint1 = FindCheckpoint1();
	FoundCheckpoint2 = FindCheckpoint2();
	FoundCheckpoint3 = FindCheckpoint3();
	FoundFinishLine = FindFinishLine();
}

void APlayerPawn::Time()
{
	CurrentLap += 0.1f;
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(1, 0.2f, FColor::Green, TEXT("Current Lap: "));
	GEngine->AddOnScreenDebugMessage(2, 0.1f, FColor::Green, FString::SanitizeFloat(CurrentLap));
	GEngine->AddOnScreenDebugMessage(3, 0.4f, FColor::Green, TEXT("Previous Lap: "));
	GEngine->AddOnScreenDebugMessage(4, 0.3f, FColor::Green, FString::SanitizeFloat(PreviousLap));
	GEngine->AddOnScreenDebugMessage(5, 0.6f, FColor::Green, TEXT("Best Lap: "));
	GEngine->AddOnScreenDebugMessage(6, 0.5f, FColor::Green, FString::SanitizeFloat(BestLap));

	//calculate current delta time.
	CurrentDeltaTime = DeltaTime;

	//Rotator
	FRotator CurrentRotation(0.0f, Steering, 0.0f);
	CurrentVelocity = CurrentRotation.Vector();
	CurrentVelocity *= Acceleration;

	FVector Direction = FVector(CurrentVelocity.X, CurrentVelocity.Y, 0.0f);
	if (Direction.SizeSquared() < 1.0f)
	{
		Direction = FVector(1.0f, 0.0f, 0.0f);
	}
	else
	{
		Direction.Normalize();
	}

	// First derive a rotation matrix from the velocity vector
	FVector Dir = FVector(CurrentVelocity.X, CurrentVelocity.Y, 0.0f);
	FRotator TargetRot = FRotationMatrix::MakeFromX(Dir).Rotator();

	// Now interpolate between the current rotation of the Pawn and the desired one derived from the direction of travel
	FRotator CurrentRot = PlayerCube->GetComponentRotation();
	FRotator NewRot;
	NewRot.Pitch = FMath::FixedTurn(CurrentRot.Pitch, TargetRot.Pitch, 360.0f * DeltaTime);
	NewRot.Yaw = FMath::FixedTurn(CurrentRot.Yaw, TargetRot.Yaw, 360.0f * DeltaTime);

	// Finally, set this new rotation on the Pawn
	PlayerCube->SetWorldRotation(NewRot);


	//Checks if current velocity is 0. If not 0, adjust actor location relevant to velocity.
	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity + CurrentDeltaTime);
		NewLocation.Z = 80.0f;
		if (ClosestBarrier)
		{
			int Flags = ABarrier1::X | ABarrier1::Y;
			int NewFlagColl = ClosestBarrier->Collision(NewLocation, CAPSULERADIUS);

			if (NewFlagColl == Flags)
			{
				int NewFlag = NewFlagColl - FlagColl;

				if (NewFlag & ABarrier1::X)
				{
					NewLocation.X = GetActorLocation().X;
				}

				if (NewFlag & ABarrier1::Y)
				{
					NewLocation.Y = GetActorLocation().Y;
				}

			}
		}

		if (SecondClosestBarrier)
		{
			int SecondFlags = ABarrier2::X | ABarrier2::Y;
			int NewSecondFlagColl = SecondClosestBarrier->SecondCollision(NewLocation, CAPSULERADIUS);

			if (NewSecondFlagColl == SecondFlags)
			{
				int NewSecondFlag = NewSecondFlagColl - SecondFlagColl;

				if (NewSecondFlag & ABarrier2::X)
				{
					NewLocation.X = GetActorLocation().X;
				}

				if (NewSecondFlag & ABarrier1::Y)
				{
					NewLocation.Y = GetActorLocation().Y;
				}

			}
		}

		SetActorLocation(NewLocation);

		if (ClosestBarrier)
		{
			FlagColl = ClosestBarrier->Collision(NewLocation, CAPSULERADIUS);
		}
		else
		{
			FlagColl = 0;
		}
		if (SecondClosestBarrier)
		{
			SecondFlagColl = SecondClosestBarrier->SecondCollision(NewLocation, CAPSULERADIUS);
		}
		else
		{
			SecondFlagColl = 0;
		}

		if (ClosestRoughTerrain)
		{
			if (ClosestRoughTerrain->OnRoughTerrain(NewLocation))
			{
				if (Acceleration >= 6.0f)
				{
					Acceleration *= 0.95f;
				}
			}
		}

		if (FoundCheckpoint1)
		{
			if (FoundCheckpoint1->Checkpoint1(NewLocation))
			{
				Check1 = true;
			}
		}
		if (FoundCheckpoint2)
		{
			if (FoundCheckpoint2->CheckpointToo(NewLocation))
			{
				if (Check1)
				{
					Check2 = true;
				}
			}
		}
		if (FoundCheckpoint3)
		{
			if (FoundCheckpoint3->CheckpointThree(NewLocation))
			{
				if (Check2)
				{
					Check3 = true;
				}
			}
		}
		if (FoundFinishLine)
		{
			if (FoundFinishLine->FinishLine(NewLocation))
			{
				if (Check3)
				{
					Check1 = false;
					Check2 = false;
					Check3 = false;
					PreviousLap = CurrentLap;
					if (BestLap == 0.0f)
					{
						BestLap = PreviousLap;
					}
					else if (PreviousLap <= BestLap)
					{
						BestLap = PreviousLap;
					}
					CurrentLap = 0;
				}
			}
		}

		if (FoundMoving)
		{
			if (FoundMoving->Mover(NewLocation))
			{
				SetActorLocation(StartLocation);
			}
		}

		//Friction
		float Friction = 1.0f - (CurrentDeltaTime * 0.25f);
		Acceleration *= Friction;


		if (ClosestBarrierTimer-- <= 0)
		{
			ClosestBarrier = FindClosestBarrier();
			ClosestBarrierTimer = 5;
		}


		if (SecondClosestBarrierTimer-- <= 0)
		{
			SecondClosestBarrier = FindSecondClosestBarrier();
			SecondClosestBarrierTimer = 5;
		}


		if (RoughTerrainTimer-- <= 0)
		{
			ClosestRoughTerrain = FindClosestRoughTerrain();
			RoughTerrainTimer = 10;
		}


		if (MovingObjectTimer-- <= 0)
		{
			FoundMoving = FindMoving();
			MovingObjectTimer = 5;
		}
	}
}

ABarrier1* APlayerPawn::FindClosestBarrier()
{
	ABarrier1 *ClosestBarrier = NULL;
	float Closest = (float)1e10;

	for (TObjectIterator<ABarrier1> act; act; ++act)
	{
		if (act->GetWorld() != this->GetWorld())
		{
			continue;
		}
		if (act->IsPendingKill())
		{
			continue;
		}
		FVector BarrierDistance = (act->GetActorLocation() - this->GetActorLocation());
		if (BarrierDistance.SizeSquared() < Closest)
		{
			Closest = BarrierDistance.SizeSquared();
			ClosestBarrier = *act;
		}
	}
	return ClosestBarrier;
}

ABarrier2* APlayerPawn::FindSecondClosestBarrier()
{
	ABarrier2 *SecondClosestBarrier = NULL;
	float SecondClosest = (float)1e10;

	for (TObjectIterator<ABarrier2> act; act; ++act)
	{
		if (act->GetWorld() != this->GetWorld())
		{
			continue;
		}
		if (act->IsPendingKill())
		{
			continue;
		}
		FVector SecondBarrierDistance = (act->GetActorLocation() - this->GetActorLocation());
		if (SecondBarrierDistance.SizeSquared() < SecondClosest)
		{
			SecondClosest = SecondBarrierDistance.SizeSquared();
			SecondClosestBarrier = *act;
		}
	}
	return SecondClosestBarrier;
}

ARoughTerrain* APlayerPawn::FindClosestRoughTerrain()
{
	ARoughTerrain *ClosestRoughTerrain = NULL;
	float ClosestTerrain = (float)1e10;

	for (TObjectIterator<ARoughTerrain> act; act; ++act)
	{
		if (act->GetWorld() != this->GetWorld())
		{
			continue;
		}
		if (act->IsPendingKill())
		{
			continue;
		}
		FVector TerrainDistance = (act->GetActorLocation() - this->GetActorLocation());
		if (TerrainDistance.SizeSquared() < ClosestTerrain)
		{
			ClosestTerrain = TerrainDistance.SizeSquared();
			ClosestRoughTerrain = *act;
		}
	}
	return ClosestRoughTerrain;
}

ACheck1* APlayerPawn::FindCheckpoint1()
{
	ACheck1 * FoundCheckpoint1 = NULL;
	float Check1 = (float)1e10;

	for (TObjectIterator<ACheck1> act; act; ++act)
	{
		if (act->GetWorld() != this->GetWorld())
		{
			continue;
		}
		if (act->IsPendingKill())
		{
			continue;
		}
		FVector Check1Dis = (act->GetActorLocation() - this->GetActorLocation());
		if (Check1Dis.SizeSquared() < Check1)
		{
			Check1 = Check1Dis.SizeSquared();
			FoundCheckpoint1 = *act;
		}
	}
	return FoundCheckpoint1;
}

ACheck2* APlayerPawn::FindCheckpoint2()
{
	ACheck2 * FoundCheckpoint2 = NULL;
	float Check2 = (float)1e10;

	for (TObjectIterator<ACheck2> act; act; ++act)
	{
		if (act->GetWorld() != this->GetWorld())
		{
			continue;
		}
		if (act->IsPendingKill())
		{
			continue;
		}
		FVector Check2Dis = (act->GetActorLocation() - this->GetActorLocation());
		if (Check2Dis.SizeSquared() < Check2)
		{
			Check2 = Check2Dis.SizeSquared();
			FoundCheckpoint2 = *act;
		}
	}
	return FoundCheckpoint2;
}

ACheck3* APlayerPawn::FindCheckpoint3()
{
	ACheck3 * FoundCheckpoint3 = NULL;
	float Check3 = (float)1e10;

	for (TObjectIterator<ACheck3> act; act; ++act)
	{
		if (act->GetWorld() != this->GetWorld())
		{
			continue;
		}
		if (act->IsPendingKill())
		{
			continue;
		}
		FVector Check3Dis = (act->GetActorLocation() - this->GetActorLocation());
		if (Check3Dis.SizeSquared() < Check3)
		{
			Check3 = Check3Dis.SizeSquared();
			FoundCheckpoint3 = *act;
		}
	}
	return FoundCheckpoint3;
}

AFinishLine* APlayerPawn::FindFinishLine()
{
	AFinishLine * FoundFinishLine = NULL;
	float Finish = (float)1e10;

	for (TObjectIterator<AFinishLine> act; act; ++act)
	{
		if (act->GetWorld() != this->GetWorld())
		{
			continue;
		}
		if (act->IsPendingKill())
		{
			continue;
		}
		FVector CheckFinishDis = (act->GetActorLocation() - this->GetActorLocation());
		if (CheckFinishDis.SizeSquared() < Finish)
		{
			Finish = CheckFinishDis.SizeSquared();
			FoundFinishLine = *act;
		}
	}
	return FoundFinishLine;
}

AMoving* APlayerPawn::FindMoving()
{
	AMoving * FoundMoving = NULL;
	float Moving = (float)1e10;

	for (TObjectIterator<AMoving> act; act; ++act)
	{
		if (act->GetWorld() != this->GetWorld())
		{
			continue;
		}
		if (act->IsPendingKill())
		{
			continue;
		}
		FVector MovingDis = (act->GetActorLocation() - this->GetActorLocation());
		if (MovingDis.SizeSquared() < Moving)
		{
			Moving = MovingDis.SizeSquared();
			FoundMoving = *act;
		}
	}
	return FoundMoving;
}


// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Responds every fram to values of movmeny axes.
	InputComponent->BindAxis("Accelerate", this, &APlayerPawn::MoveX);
	InputComponent->BindAxis("Steer", this, &APlayerPawn::MoveY);
}

//Pawn Movment.
void APlayerPawn::MoveX(float AxisValue)
{
	//Move pawn 150 units on local X-axis.
	Acceleration += FMath::Clamp(AxisValue, -1.0f, 1.0f) * 10.0f * CurrentDeltaTime;
	Acceleration = FMath::Clamp(Acceleration, 0.0f, 20.0f);

}
void APlayerPawn::MoveY(float AxisValue)
{
	//move pawn 150 units on local Y-axis.
	if (Acceleration >= 1.0f)
	{
		Steering += FMath::Clamp(AxisValue, -1.0f, 1.0f) *200.0f *CurrentDeltaTime;
	}
	else
	{
		Steering = 0.0f;
	}
}
