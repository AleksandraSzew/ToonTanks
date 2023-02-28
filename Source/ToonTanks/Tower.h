// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATower();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	class ATank* Tank;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tower")
		float FireRange = 200.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower")
		float TurnRate = 100.f;
};
