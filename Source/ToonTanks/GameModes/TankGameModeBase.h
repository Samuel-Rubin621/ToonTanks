// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

class APawnTurret;
class APawnTank;
class APlayerControllerBase;

UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	void ActorDied(AActor* DeadActor);

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bPlayerWon);

	// VARIABLES
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop")
	int32 StartDelay = 3.f;

private:
	//VARIABLES
	APawnTank* PlayerTank = nullptr;
	int32 TargetTurrets = 0;

	APlayerControllerBase* PlayerControllerRef;

	// FUNCTIONS
	void HandleGameStart();
	void HandleGameOver(bool bPlayerWon);
	void GetTargetTurretCount();
};
