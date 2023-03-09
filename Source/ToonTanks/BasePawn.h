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


public:	

	/*UPROPERTY(VisibleInstanceOnly)
		int32 VisibleInstanceOnlyInt = 5;

	UPROPERTY(VisibleDefaultsOnly)
		int32 VisibleDefaultOnlyInt = 5;

	UPROPERTY(VisibleAnywhere, Blueprintreadwrite, Category = "Testing", meta = (AllowPrivateAccess = "true"))
		int32 VisibleAnywhere = 10;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Testing", meta = (AllowPrivateAccess = "true"))
		int32 EditAnywhere = 11;
	*/
protected:
	void RotateTuret(FVector LookAtTarget);
	void Fire();
	void HandleDestruction();
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn components", meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* ProjectileSpawnPoint;
	UPROPERTY(EditAnywhere, Category = "Projectile components")
		TSubclassOf<class AProjectile> ProjectileClass;
	UPROPERTY(EditAnywhere, Category = "Pawn components")
		UParticleSystem* DeathParticle;
	UPROPERTY(EditAnywhere, Category = "Pawn components")
		class USoundBase* DeathSound;
	UPROPERTY(EditAnywhere, Category = "Projectile components")
		TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;
};
