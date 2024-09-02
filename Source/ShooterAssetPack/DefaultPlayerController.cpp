// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void ADefaultPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDWidget);
	if (HUD)
	{
		HUD->AddToViewport();
	}
}

void ADefaultPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	HUD->RemoveFromViewport();
	if (bIsWinner) {
		UUserWidget* WinScreen = CreateWidget(this, WinScreenWidget);
		if (WinScreen)
		{
			WinScreen->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenWidget);
		if (LoseScreen)
		{
			LoseScreen->AddToViewport();
		}
	}

	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}