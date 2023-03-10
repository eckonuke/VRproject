// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <HeadMountedDisplayFunctionLibrary.h>
#include "GameFramework/Character.h"
#include "VR_Player.generated.h"

UCLASS()
class VRPROJECT_API AVR_Player : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVR_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//카메라 컴포넌트
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UCameraComponent* compCamera;

	//오른손 컨트롤러
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UMotionControllerComponent* rightController;
	//오른손 모양
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UStaticMeshComponent* rightHand;
	//오른손 입력 로그
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UTextRenderComponent* rightLog;

	//왼손 컨트롤러
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UMotionControllerComponent* leftController;
	//왼손 모양
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UStaticMeshComponent* leftHand;
	//왼손 입력 로그
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UTextRenderComponent* leftLog;

	//머리 모양
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UStaticMeshComponent* headMesh;

	//카메라 높이 위치 설정
	UPROPERTY(EditAnywhere, Category = "VR_Settings | ModuleSetting")
	TEnumAsByte<enum EHMDTrackingOrigin::Type> trackOrigin;

private: 
	void OnTriggerLeft();
	void OnGripLeft();
	void OnTriggerTouchLeft();
	void OnThumbStickTouchLeft();

	void HorizontalLeft(float value);
	void VerticalLeft(float value);
};
