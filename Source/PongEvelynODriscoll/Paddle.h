// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddle.generated.h"

UCLASS()
class PONGEVELYNODRISCOLL_API APaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddle();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Paddle")
	class UBoxComponent* Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Paddle")
	class UStaticMeshComponent* PaddleMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class UFloatingPawnMovement* PaddleMovement;

	/*The pawns velocity modifier*/
	UPROPERTY(EditAnywhere, Category = "Paddle")
	float Velocity = 300.0f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
	/*The Pawns Move Forward Amount per frame*/
	float MoveForwardAmount = 0;

	/*The Callback function for the MoveForward Input Axis Event*/
	virtual void MoveForward(float Amount);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
