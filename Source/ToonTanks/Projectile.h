// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	float Damage = 50.f;
private:

	UPROPERTY(VisibleAnywhere, Category = "Projectile components")
	UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(VisibleAnywhere, Category = "Projectile components")
	class UProjectileMovementComponent*  ProjectileMovementComponent;
	UPROPERTY(EditAnywhere, Category = "Projectile components")
	UParticleSystem* HitParticles;
	UPROPERTY(EditAnywhere, Category = "Projectile components")
	class UParticleSystemComponent* TraceParticles;
};
