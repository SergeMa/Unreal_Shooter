// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERASSETPACK_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;
	bool IsDead() const;

private:
	AActor* PlayerPawn;

	UPROPERTY(EditAnywhere, Category = "AI")
	class UBehaviorTree* AIBehavior;
};
