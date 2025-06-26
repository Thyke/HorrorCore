// Copyright (C) Thyke 2025 All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "HorrorCharacterMovementComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartedMovingOnGroundSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStoppedMovingOnGroundSignature);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HORRORCORE_API UHorrorCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:

	UHorrorCharacterMovementComponent(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(BlueprintAssignable, Category = "Movement|Events")
	FOnStartedMovingOnGroundSignature OnStartedMovingOnGround;
	
	UPROPERTY(BlueprintAssignable, Category = "Movement|Events")
	FOnStoppedMovingOnGroundSignature OnStoppedMovingOnGround;
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
protected:
	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode) override;

private:

	bool bWasMovingLastFrame = false;
};
