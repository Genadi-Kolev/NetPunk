// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "AbilitySystemInterface.h"
#include "SaveLoad/SaveInterface.h"

#include "PlayerCharacter.generated.h"

UCLASS()
class NETGAME_API APlayerCharacter : public ACharacter, public ISaveInterface, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	APlayerCharacter(const FObjectInitializer& ObjectInitializer);
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category="PlayerMovementComponent")
	class UPlayerMovementComponent* GetPlayerMovementComponent() const;
	
	void MoveForward(float InputAxisValue);
	void MoveRight(float InputAxisValue);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Networking")
	bool IsHostCharacter() const;
	
// Saving system
protected:
	UFUNCTION(BlueprintAuthorityOnly, Category="Saved Variables")
	virtual void OnBeforeSave_Implementation() override;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintAuthorityOnly, Category="Saved Variables")
	void LoadSavedParameters();
	
	UPROPERTY(SaveGame)
	FTransform PlayerTransform;

// GameplayAbilities system
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="GAS")
	class UGASAbilitySystemComponent* AbilitySystemComponent;
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/** Called both on OnRep_PlayerState and SetupPlayerInput */
	void BindASCInput();

private:
	bool bIsASCInputBound = false;
	FVector2D InputVector;
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector2D GetInputVector() const { return InputVector; }
};
