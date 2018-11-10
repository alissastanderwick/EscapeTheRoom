// Copyright Daniel Standerwick 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	AController* OwnerController;
	float Reach = 140.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* PawnInput = nullptr;


	void FindPhysicsComponent();
	void SetupInputComponent();

	// Ray-Cast and grab whats in reach 
	void Grab();
	void Release();

	//Return hit of rfirst physics body in reach 
	FHitResult GetFirstPhysicsBodyInReach();

	FVector GetReachLineStart();

	FVector GetReachLineEnd();

};
