// LSOctaveTranspose.cpp

#include "LSOctaveTranspose.h"

LSOctaveTransposeSettings::LSOctaveTransposeSettings()
{}


unsigned int LSOctaveTransposeSettings::GetOctave()
{
	return m_Octave;
}


unsigned int LSOctaveTransposeSettings::GetTransposePitch()
{
	return m_TransposePitch;
}


unsigned int LSOctaveTransposeSettings::GetTransposeLights()
{
	return m_TransposeLights;
}


void LSOctaveTransposeSettings::SetOctave(unsigned int nValue)
{
	m_Octave = nValue;
}


void LSOctaveTransposeSettings::SetTransposePitch(unsigned int nValue)
{
	m_TransposePitch = nValue;
}


void LSOctaveTransposeSettings::SetTransposeLights(unsigned int nValue)
{
	m_TransposeLights = nValue;
}
