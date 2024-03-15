// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ball.h"
#include "AIPaddle.generated.h"

UCLASS()
class PONGEVELYNODRISCOLL_API AAIPaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAIPaddle();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Paddle")
	class UBoxComponent* AICollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Paddle")
	class UStaticMeshComponent* AIPaddleMesh;

	void AIMove(FVector BallLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class UFloatingPawnMovement* AIPaddleMovement;

	ABall* Ball;

	TArray <AActor*> BallArray;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
