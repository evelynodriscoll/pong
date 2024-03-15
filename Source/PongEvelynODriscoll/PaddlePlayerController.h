// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaddlePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PONGEVELYNODRISCOLL_API APaddlePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APaddlePlayerController();

	virtual void AcknowledgePossession(class APawn* P) override;

protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

	virtual void SetupInputComponent() override;

	class APaddle* Paddle;
};
