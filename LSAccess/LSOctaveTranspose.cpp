// LSOctaveTranspose.cpp

#include "LSOctaveTranspose.h"

LSOctaveTransposeSettings::LSOctaveTransposeSettings()
{}


unsigned int LSOctaveTransposeSettings::GetOctave(LSSplitType split)
{
	if (split == LSSplitType::LEFT)
	{
		return m_LeftOctave;
	}
	else
	{
		return m_RightOctave;
	}
}


unsigned int LSOctaveTransposeSettings::GetTransposePitch(LSSplitType split)
{
	if (split == LSSplitType::LEFT)
	{
		return m_LeftTransposePitch;
	}
	else
	{
		return m_RightTransposePitch;
	}
	}


unsigned int LSOctaveTransposeSettings::GetTransposeLights(LSSplitType split)
{
	if (split == LSSplitType::LEFT)
	{
		return m_LeftTransposeLights;
	}
	else
	{
		return m_RightTransposeLights;
	}
}


void LSOctaveTransposeSettings::SetOctave(unsigned int nValue, LSSplitType split)
{
	if (split == LSSplitType::LEFT)
	{
		m_LeftOctave = nValue;
	}
	else
	{
		m_RightOctave = nValue;
	}
}


void LSOctaveTransposeSettings::SetTransposePitch(unsigned int nValue, LSSplitType split)
{
	if (split == LSSplitType::LEFT)
	{
		m_LeftTransposePitch = nValue;
	}
	else
	{
		m_RightTransposePitch = nValue;
	}
}


void LSOctaveTransposeSettings::SetTransposeLights(unsigned int nValue, LSSplitType split)
{
	if (split == LSSplitType::LEFT)
	{
		m_LeftTransposeLights = nValue;
	}
	else
	{
		m_RightTransposeLights = nValue;
	}
}
