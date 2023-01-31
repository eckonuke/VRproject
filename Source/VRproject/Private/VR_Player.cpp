// Fill out your copyright notice in the Description page of Project Settings.


#include "VR_Player.h"
#include <MotionControllerComponent.h>
#include <Components/StaticMeshComponent.h>
#include <Camera/CameraComponent.h>
#include <Components/SphereComponent.h>
#include <HeadMountedDisplayFunctionLibrary.h>
#include <Components/TextRenderComponent.h>

// Sets default values
AVR_Player::AVR_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//ī�޶� ������Ʈ
	compCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	compCamera->SetupAttachment(RootComponent);

	//�Ӹ� ���
	headMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
	headMesh->SetupAttachment(compCamera);
	headMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	

	//������ ��Ʈ�ѷ�
	rightController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("controllerRight"));
	rightController->SetupAttachment(RootComponent);
	//��� �ҽ� ������
	rightController->MotionSource = "Right";
	//������ ���
	rightHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("rightHand"));
	rightHand->SetupAttachment(rightController);
	rightHand->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	//������ �α�
	rightLog = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Right Log Text"));
	rightLog->SetupAttachment(rightController);
	rightLog->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	rightLog->SetTextRenderColor(FColor::Yellow);
	rightLog->SetHorizontalAlignment(EHTA_Center);
	rightLog->SetVerticalAlignment(EVRTA_TextCenter);

	//�޼�
	leftController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("controllerLeft"));
	leftController->SetupAttachment(RootComponent);
	//��� �ҽ� ����
	leftController->MotionSource = "Left";
	//�޼� ���
	leftHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("leftHand"));
	leftHand->SetupAttachment(leftController);
	leftHand->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//�޼� �α�
	leftLog = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Left Log Text"));
	leftLog->SetupAttachment(leftController);
	leftLog->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	leftLog->SetTextRenderColor(FColor::Yellow);
	leftLog->SetHorizontalAlignment(EHTA_Center);
	leftLog->SetVerticalAlignment(EVRTA_TextCenter);
}

// Called when the game starts or when spawned
void AVR_Player::BeginPlay()
{
	Super::BeginPlay();
	
	//��� ����� ���� ��ġ�� �����Ѵ�.
	UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(trackOrigin.GetValue());

}

// Called every frame
void AVR_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVR_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("TriggerLeft", IE_Pressed, this, &AVR_Player::OnTriggerLeft);
	PlayerInputComponent->BindAction("GripLeft", IE_Pressed, this, &AVR_Player::OnGripLeft);
	PlayerInputComponent->BindAction("TriggerTouchLeft", IE_Pressed, this, &AVR_Player::OnTriggerTouchLeft);
	PlayerInputComponent->BindAction("ThumbStrickTouchLeft", IE_Pressed, this, &AVR_Player::OnThumbStickTouchLeft);

	PlayerInputComponent->BindAxis("ThumbStickHorizontalLeft", this, &AVR_Player::HorizontalLeft);
	PlayerInputComponent->BindAxis("ThumbStickVerticalLeft", this, &AVR_Player::VerticalLeft);

}

void AVR_Player::OnTriggerLeft() {
	leftLog->SetText(FText::FromString(__FUNCTION__));
}

void AVR_Player::OnGripLeft() {
	leftLog->SetText(FText::FromString(__FUNCTION__));
}

void AVR_Player::OnTriggerTouchLeft() {
	leftLog->SetText(FText::FromString(__FUNCTION__));
}

void AVR_Player::OnThumbStickTouchLeft() {
	leftLog->SetText(FText::FromString(__FUNCTION__));
}

void AVR_Player::HorizontalLeft(float value){
	FString msg = FString::Printf(TEXT("%.3f, "), value);
	//FString result = leftLog->Text.ToString() + msg;
	leftLog->SetText(FText::FromString(msg));
}

void AVR_Player::VerticalLeft(float value){
	FString msg = FString::Printf(TEXT("%.3f "), value);
	FString result = leftLog->Text.ToString() + msg;
	leftLog->SetText(FText::FromString(result));
}