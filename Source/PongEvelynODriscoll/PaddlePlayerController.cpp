// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePlayerController.h"
#include "Paddle.h"

// Sets default values
APaddlePlayerController::APaddlePlayerController()
{

}

void APaddlePlayerController::AcknowledgePossession(APawn* P)
{
	Super::AcknowledgePossession(P);
	Paddle = Cast<APaddle>(P);
}

void APaddlePlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	//Paddle = Cast<APaddle>(aPawn);

}

void APaddlePlayerController::OnUnPossess()
{
	Super::OnUnPossess();
}

void APaddlePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

}


