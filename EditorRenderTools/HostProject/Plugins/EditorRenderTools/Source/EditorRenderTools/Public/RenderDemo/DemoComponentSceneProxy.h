// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PrimitiveSceneProxy.h"

/**
 * 
 */
class EDITORRENDERTOOLS_API FDemoComponentSceneProxy : public FPrimitiveSceneProxy
{
public:
	FDemoComponentSceneProxy(UPrimitiveComponent* Component) :FPrimitiveSceneProxy(Component) {}

	//�������ٷ����ڴ��С
	virtual uint32 GetMemoryFootprint(void)const override
	{
		return(sizeof(*this) + GetAllocatedSize());
	}
	//�ռ���̬Ԫ�ز�����
	virtual void GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, uint32 VisibilityMap, class FMeshElementCollector& Collector) const override {
		FBox demoDynamicBox = FBox(FVector(-100.f), FVector(100.f));
		//����һ�����������
		DrawWireBox(
			Collector.GetPDI(0),
			demoDynamicBox,
			FLinearColor::Red,
			ESceneDepthPriorityGroup::SDPG_Foreground,
			10.0f
		);
	}

	//����view �ж���ɼ���
	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* view)const  override
	{
		FPrimitiveViewRelevance result;
		result.bDrawRelevance = IsShown(view);
		result.bDrawRelevance = true;
		result.bShadowRelevance = IsShadowCast(view);
		result.bEditorPrimitiveRelevance = UseEditorCompositing(view);
		return result;
	}

	/** Return a type (or subtype) specific hash for sorting purposes */
	virtual SIZE_T GetTypeHash() const override 
	{
		static size_t UniquePointer;
		return reinterpret_cast<size_t>(&UniquePointer);
	}
};
