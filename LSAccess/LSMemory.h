// LSMemory
// Class to represent all parameters to be saved to a memory preset
// At the right side of the Preset screen are 6 blue-lit note pads indicating 6 "All Settings" memories. Each of these 6 memories holds a snapshot of all:
// Per-Split Settings, 
// Octave/Transpose settings 
// and Global Settings. 
// (Note that the Preset and Volume screen settings are not included because the intent is to instantly change all of LinnStrument’s settings but not the preset and volume of external MIDI sound generators.)


#pragma once

#include "LSPerSplit.h"
#include "LSOctaveTranspose.h"
#include "LSGlobal.h"

class LSMemoryLocation
{
public:
	LSMemoryLocation();

	LSPerSplitSettings GetPerSplitSettings();
	LSOctaveTransposeSettings GetOctaveTransposeSettings();
	LSGlobalSettings GetGlobalSettings();

private:
	unsigned int m_MemoryNumber;
	LSPerSplitSettings m_PerSplitSettings;
	LSOctaveTransposeSettings m_OctaveTransposeSettings;
	LSGlobalSettings m_GlobalSettings;
};
