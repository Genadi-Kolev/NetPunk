// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NetGameGameMode.generated.h"

UCLASS(minimalapi)
class ANetGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANetGameGameMode();

	virtual APawn* SpawnDefaultPawnAtTransform_Implementation(AController* NewPlayer, const FTransform& SpawnTransform) override;
};



