// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BallSpawner.h"
#include "Ball.h"
#include "PongGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PONGEVELYNODRISCOLL_API APongGameModeBase : public AGameModeBase
{
	GENERATED_BODY()


protected:
	
	APongGameModeBase();

	virtual void BeginPlay() override;


	ABallSpawner* BallSpawner;

	ABall* Ball;

	TArray <AActor*> BallArray;

	TArray <AActor*> SpawnArray;


public:

	virtual void Tick(float DeltaTime) override;

	void Reset();
	
};
