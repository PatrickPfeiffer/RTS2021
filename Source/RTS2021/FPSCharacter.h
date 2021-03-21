#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"


#include "FPSCharacter.generated.h"

UCLASS()
class RTS2021_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

	UPROPERTY(EditAnywhere, Category = "Weapon")
	float attackRange{ 1000 };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FHitResult FireRaycast();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
