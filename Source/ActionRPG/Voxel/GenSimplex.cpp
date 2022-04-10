// Copyright 2021 Phyronnaz

#include "GenSimplex.h"
#include "VoxelMaterialBuilder.h"
#include "SimplexNoiseBPLibrary.h"

TVoxelSharedRef<FVoxelGeneratorInstance> UGenSimplex::GetInstance()
{
	return MakeVoxelShared<FGenSimplexInstance>(*this);
}

///////////////////////////////////////////////////////////////////////////////

FGenSimplexInstance::FGenSimplexInstance(const UGenSimplex& MyGenerator)
	:
	Super(&MyGenerator),
	GenSimplex( &MyGenerator )
{
}

void FGenSimplexInstance::Init(const FVoxelGeneratorInit& InitStruct)
{
}

v_flt FGenSimplexInstance::GetValueImpl(v_flt X, v_flt Y, v_flt Z, int32 LOD, const FVoxelItemStack& Items) const
{
	//const float Height = 1.0f; //Noise.GetPerlin_2D(X, Y, 0.01f) * NoiseHeight;

	const float Height = USimplexNoiseBPLibrary::SimplexNoise2D( X * GenSimplex->XYScale, Y * GenSimplex->XYScale) * GenSimplex->NoiseHeight;

	// Positive value -> empty voxel
	// Negative value -> full voxel
	// Value positive when Z > Height, and negative Z < Height
	float Value = Z - Height;
	
	// The voxel value is clamped between -1 and 1. That can result in a bad gradient/normal. To solve that we divide it
	Value /= 5;

	return Value;
}

FVoxelMaterial FGenSimplexInstance::GetMaterialImpl(v_flt X, v_flt Y, v_flt Z, int32 LOD, const FVoxelItemStack& Items) const
{
	FVoxelMaterialBuilder Builder;

	// RGB
	Builder.SetMaterialConfig(EVoxelMaterialConfig::RGB);
	Builder.SetColor(FColor::Red);

	// Single index
	//Builder.SetMaterialConfig(EVoxelMaterialConfig::SingleIndex);
	//Builder.SetSingleIndex(0); 

	// Multi index
	//Builder.SetMaterialConfig(EVoxelMaterialConfig::MultiIndex);
	//Builder.AddMultiIndex(0, 0.5f);
	//Builder.AddMultiIndex(1, 0.5f);
	
	return Builder.Build();
}

TVoxelRange<v_flt> FGenSimplexInstance::GetValueRangeImpl(const FVoxelIntBox& Bounds, int32 LOD, const FVoxelItemStack& Items) const
{
	// Return the values that GetValueImpl can return in Bounds
	// Used to skip chunks where the value does not change
	// Be careful, if wrong your world will have holes!
	// By default return infinite range to be safe
	return TVoxelRange<v_flt>::Infinite();

	// Example for the GetValueImpl above

	// Noise is between -1 and 1
	const TVoxelRange<v_flt> Height = TVoxelRange<v_flt>(-1, 1) * GenSimplex->NoiseHeight;

	// Z can go from min to max
	TVoxelRange<v_flt> Value = TVoxelRange<v_flt>(Bounds.Min.Z, Bounds.Max.Z) - Height;

	Value /= 5;

	return Value;
}

FVector FGenSimplexInstance::GetUpVector(v_flt X, v_flt Y, v_flt Z) const
{
	// Used by spawners
	return FVector::UpVector;
}
