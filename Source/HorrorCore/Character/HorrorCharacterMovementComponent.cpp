// Copyright (C) Thyke 2025 All Rights Reserved.


#include "HorrorCharacterMovementComponent.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(HorrorCharacterMovementComponent)

constexpr float MovementThresholdSq = 25.0f; // (5 cm/s)^2
UHorrorCharacterMovementComponent::UHorrorCharacterMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHorrorCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


void UHorrorCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (!IsMovingOnGround())
	{
		if (bWasMovingLastFrame)
		{
			OnStoppedMovingOnGround.Broadcast();
			bWasMovingLastFrame = false;
		}
		return;
	}
	
	const float VelocitySizeSq = GetLastUpdateVelocity().SizeSquared();
	const bool bIsNowMoving = VelocitySizeSq > MovementThresholdSq;
	if (bIsNowMoving && !bWasMovingLastFrame)
	{
		OnStartedMovingOnGround.Broadcast();
	}
	else if (!bIsNowMoving && bWasMovingLastFrame)
	{
		OnStoppedMovingOnGround.Broadcast();
	}
	bWasMovingLastFrame = bIsNowMoving;
}

void UHorrorCharacterMovementComponent::OnMovementModeChanged(EMovementMode PreviousMovementMode,
	uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);
}

