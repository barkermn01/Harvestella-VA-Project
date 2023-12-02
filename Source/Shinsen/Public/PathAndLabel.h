#pragma once
#include "CoreMinimal.h"
#include "PathAndLabel.generated.h"

USTRUCT(BlueprintType)
struct FPathAndLabel {
    GENERATED_BODY()
public:
    TMap<FString, FString> PathAndLabelMap;
    
    SHINSEN_API FPathAndLabel();
};

