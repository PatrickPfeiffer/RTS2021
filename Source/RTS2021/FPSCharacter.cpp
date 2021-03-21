#include "FPSCharacter.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FHitResult AFPSCharacter::FireRaycast()
{
	FVector camLocation;
	FRotator camRotation;
	FVector endTrace = FVector::ZeroVector;
	
	APlayerController* const playerController = GetWorld()->GetFirstPlayerController();
	if (playerController != NULL) {
		playerController->GetPlayerViewPoint(camLocation, camRotation);
		endTrace = camLocation + (camRotation.Vector() * attackRange);
	}

	FCollisionQueryParams traceParams(SCENE_QUERY_STAT(FireRaycast), true, Instigator);
	FHitResult hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(hit, camLocation, endTrace, ECC_Visibility, traceParams);

	return hit;
}