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


	//ī�޶� ������Ʈ
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UCameraComponent* compCamera;

	//������ ��Ʈ�ѷ�
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UMotionControllerComponent* rightController;
	//������ ���
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UStaticMeshComponent* rightHand;
	//������ �Է� �α�
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UTextRenderComponent* rightLog;

	//�޼� ��Ʈ�ѷ�
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UMotionControllerComponent* leftController;
	//�޼� ���
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UStaticMeshComponent* leftHand;
	//�޼� �Է� �α�
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UTextRenderComponent* leftLog;

	//�Ӹ� ���
	UPROPERTY(EditAnywhere, Category = "VR_Settings | Compoenets")
	class UStaticMeshComponent* headMesh;

	//ī�޶� ���� ��ġ ����
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
