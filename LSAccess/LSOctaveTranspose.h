// LSOctaveTranspose.h

#pragma once

#include "LSEnums.h"


// Value is an LSOctave
const unsigned int SPLIT_LEFT_OCTAVE_NRPN = 36;
// Values are from LSPitch
const unsigned int SPLIT_LEFT_PITCH_TRANSPOSE_NRPN = 37;
const unsigned int SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN = 38;
// Value is an LSOctave
const unsigned int SPLIT_RIGHT_OCTAVE_NRPN = 136;
// Values are from LSPitch
const unsigned int SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN = 137;
const unsigned int SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN = 138;


class LSOctaveTransposeSettings
{
public:
	LSOctaveTransposeSettings()
	{};

	unsigned int GetOctave( LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LeftOctave;
		}
		else
		{
			return m_RightOctave;
		}
	};
	
	unsigned int GetTransposePitch(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LeftTransposePitch;
		}
		else
		{
			return m_RightTransposePitch;
		}
	};
	
	unsigned int GetTransposeLights(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LeftTransposeLights;
		}
		else
		{
			return m_RightTransposeLights;
		}
	};
	
	void SetOctave( unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LeftOctave = nValue;
		}
		else
		{
			m_RightOctave = nValue;
		}
	};
	
	void SetTransposePitch(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LeftTransposePitch = nValue;
		}
		else
		{
			m_RightTransposePitch = nValue;
		}
	};
	
	void SetTransposeLights(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LeftTransposeLights = nValue;
		}
		else
		{
			m_RightTransposeLights = nValue;
		}
	};

private:
	unsigned int m_LeftOctave, m_LeftTransposePitch, m_LeftTransposeLights;
		unsigned int m_RightOctave, m_RightTransposePitch, m_RightTransposeLights; 
		};
