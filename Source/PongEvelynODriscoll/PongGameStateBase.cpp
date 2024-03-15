// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameStateBase.h"
#include <Kismet/GameplayStatics.h>



void APongGameStateBase::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATextRenderActor::StaticClass(), ScoreArray);

	AIScoreActor = Cast<ATextRenderActor>(ScoreArray[1]);
	PlayerScoreActor = Cast<ATextRenderActor>(ScoreArray[0]);
	

}

void APongGameStateBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void APongGameStateBase::IncrementScore(FString Player) {

	if (Player == "AI") {
		AIScoreNum++;
	} 
	else {
		PlayerScoreNum++;
	}

	AIString = FString::FromInt(AIScoreNum);
	PlayerString = FString::FromInt(PlayerScoreNum);

	AIScoreRender = AIScoreActor->GetTextRender();
	AIScoreRender->SetText(FText::FromString(AIString));

	PlayerScoreRender = PlayerScoreActor->GetTextRender();
	PlayerScoreRender->SetText(FText::FromString(PlayerString));

}




