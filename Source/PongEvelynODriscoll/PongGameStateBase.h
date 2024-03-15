// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Components/TextRenderComponent.h"
#include "Engine/TextRenderActor.h"
#include "PongGameStateBase.generated.h"


/**
 * 
 */
UCLASS()
class PONGEVELYNODRISCOLL_API APongGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;

	void IncrementScore(FString Player);

	int PlayerScoreNum;

	int AIScoreNum;

	FString AIString;

	FString PlayerString;

	UTextRenderComponent* AIScoreRender;

	UTextRenderComponent* PlayerScoreRender;

	TArray <AActor*> ScoreArray;

	ATextRenderActor* AIScoreActor;
	ATextRenderActor* PlayerScoreActor;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
