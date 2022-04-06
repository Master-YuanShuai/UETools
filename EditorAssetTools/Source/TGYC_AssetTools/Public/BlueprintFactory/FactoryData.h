// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FactoryData.generated.h"

/**
 * 
 */

struct FAssetData;

//���װ������
USTRUCT()
struct FMakeComponentData
{
	GENERATED_BODY()

	//�����
	UPROPERTY()
	UClass* componentclass;
	 //װ���������
	UPROPERTY()
	FString componentname;
	 
	//�����������
	UPROPERTY()
	FName attachtoname;
	 
	//���Я�����ʲ���Ϣ һ�������һ��������ܹ����һ���ʲ� ������groom����������� ����Я��ӵ�ж���ʲ�����
	UPROPERTY()
	TArray<FAssetData> packagedata;
};

//����������Ľṹ�� ����½��Ĺ������ݲ�ͬ ���Լ̳�����ṹ����ʹ��
USTRUCT()
struct FBaseFactoryData
{
	GENERATED_BODY()

	//װ���Ŀ����ͼ
	UPROPERTY()
	UBlueprint* makebp;
};

//����ΪActor����ͼ�๤������
USTRUCT()
struct FActorBlueprintFactoryData : public FBaseFactoryData
{
	GENERATED_BODY()

	/* 
		���װ��ӳ���� 
		������Դ�ڳ�ʼ�� ����Ҫ���� �̶�ֵ
	*/
	UPROPERTY()
	TMap<FString, UClass*> make_compdata;

	UPROPERTY()
	TArray<FMakeComponentData> makecomponentdata;

	//��������� ��ֹ����������
	TArray<FString> blacklistComp;

};
