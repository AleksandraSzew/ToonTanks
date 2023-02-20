// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleInstanceOnly)
		int32 VisibleInstanceOnlyInt = 5;

	UPROPERTY(VisibleDefaultsOnly)
		int32 VisibleDefaultOnlyInt = 5;

	UPROPERTY(VisibleAnywhere, Blueprintreadwrite)
		int32 VisibleAnywhere = 10;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 EditAnywhere = 11;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed = 20;
private:
	UPROPERTY()
		class UCapsuleComponent* CapsuleComp;

	UPROPERTY()
		UStaticMeshComponent* BaseMesh;

	UPROPERTY()
		UStaticMeshComponent* TurretMesh;

	UPROPERTY()
		USceneComponent* ProjectileSpawnPoint;
	
};
