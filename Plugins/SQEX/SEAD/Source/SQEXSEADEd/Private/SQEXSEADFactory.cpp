// Fill out your copyright notice in the Description page of Project Settings.

#include "SQEXSEADFactory.h"

#include "AudioDeviceManager.h"
#include "Sound/SoundNodeWavePlayer.h"

#include "PackageTools.h"
#include "Misc/MessageDialog.h"
#include "AssetToolsModule.h"



USQEXSEADFactory::USQEXSEADFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Formats.Add(TEXT("mabf;MAB Data"));
	Formats.Add(TEXT("sabf;SAB Data"));
	bCreateNew = false;
	bEditAfterNew = true;
	bEditorImport = true;
	SupportedClass = USQEXSEADSoundBank::StaticClass();
	
}

bool USQEXSEADFactory::ShouldShowInNewMenu() const
{
	return true;
}

/*static bool bSoundFactorySuppressImportOverwriteDialog = false;*/
UObject* USQEXSEADFactory::FactoryCreateBinary(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn)
{
	GEditor->GetEditorSubsystem<UImportSubsystem>()->BroadcastAssetPreImport(this, Class, InParent, Name, Type);

	const uint64 BufferSize = BufferEnd - Buffer;
	
	TArray<uint8> RawSoundData;
	RawSoundData.Empty(BufferEnd - Buffer);
	RawSoundData.AddUninitialized(BufferEnd - Buffer);
	FMemory::Memcpy(RawSoundData.GetData(), Buffer, RawSoundData.Num());


	RawSoundData.Append(Buffer, BufferSize);
	USQEXSEADSoundBank* NewSoundBank = NewObject<USQEXSEADSoundBank>(InParent, Name, Flags);
	NewSoundBank->Platforms.Add(FName(TEXT("Windows")));
	NewSoundBank->RawData.Lock(LOCK_READ_WRITE);
	void* LockedData = NewSoundBank->RawData.Realloc(BufferEnd - Buffer);
	FMemory::Memcpy(LockedData, Buffer, BufferEnd - Buffer);
	NewSoundBank->RawData.Unlock();
	

	GEditor->GetEditorSubsystem<UImportSubsystem>()->BroadcastAssetPostImport(this, NewSoundBank);
	
	return NewSoundBank;

	
}
	
