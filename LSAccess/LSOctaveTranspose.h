// LSOctaveTranspose.h

#pragma once

#include "LSPerSplit.h"

class LSOctaveTransposeSettings
{
public:
	LSOctaveTransposeSettings();

	unsigned int GetOctave( LSSplitType split);
	unsigned int GetTransposePitch(LSSplitType split);
	unsigned int GetTransposeLights(LSSplitType split);
	void SetOctave( unsigned int nValue, LSSplitType split);
	void SetTransposePitch(unsigned int nValue, LSSplitType split);
	void SetTransposeLights(unsigned int nValue, LSSplitType split);

private:
	unsigned int m_LeftOctave, m_LeftTransposePitch, m_LeftTransposeLights;
		unsigned int m_RightOctave, m_RightTransposePitch, m_RightTransposeLights; 
		};
