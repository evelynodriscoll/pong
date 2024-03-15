// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wall.generated.h"

UCLASS()
class PONGEVELYNODRISCOLL_API AWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWall();

	UPROPERTY(VisibleAnywhere, Category = "Wall")
	class UBoxComponent* WallCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Wall")
	class UStaticMeshComponent* WallMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
