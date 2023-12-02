#include "SQEXSEADSoundBank.h"



USQEXSEADSoundBank::USQEXSEADSoundBank(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    this->bStreaming = false;
    this->bMAGIAsset = false;
    this->BankOverrideAttenuation = NULL;
}


void USQEXSEADSoundBank::Serialize(FArchive& Ar)
{
  
    Super::Serialize(Ar);
        
    Ar << Platforms;
    RawData.Serialize(Ar, this);

}
