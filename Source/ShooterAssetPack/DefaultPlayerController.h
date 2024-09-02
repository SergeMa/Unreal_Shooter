// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DefaultPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERASSETPACK_API ADefaultPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	float RestartDelay = 5.f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseScreenWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> WinScreenWidget;

	UPROPERTY(EditAnywhere)	
	TSubclassOf<class UUserWidget> HUDWidget;

	UPROPERTY()
	class UUserWidget* HUD;
	FTimerHandle RestartTimer;


};
