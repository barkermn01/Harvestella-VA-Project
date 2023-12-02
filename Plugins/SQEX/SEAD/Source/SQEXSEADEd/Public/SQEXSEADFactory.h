// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealEd.h"
#include "Factories/Factory.h"
#include "SQEXSEADSoundBank.h"
#include "SQEXSEADFactory.generated.h"

/**
 * 
 */
UCLASS(hidecategories = Object)
class USQEXSEADFactory : public UFactory
{
	GENERATED_BODY()
	virtual UObject* FactoryCreateBinary(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn) override;

	/*USQEXSEADSoundBank* FindSEADMusic(FName FileName, FString PackagePath);*/
	/*USQEXSEADSoundBank* FindSEADSound(FName FileName, FString PackagePath);*/
	virtual bool ShouldShowInNewMenu() const override;

	USQEXSEADFactory(const FObjectInitializer& ObjectInitializer);
};