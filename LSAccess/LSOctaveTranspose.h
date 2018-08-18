// LSOctaveTranspose.h

#pragma once

class LSOctaveTransposeSettings
{
public:
	LSOctaveTransposeSettings();

	unsigned int GetOctave();
	unsigned int GetTransposePitch();
	unsigned int GetTransposeLights();
	void SetOctave( unsigned int nValue);
	void SetTransposePitch(unsigned int nValue);
	void SetTransposeLights(unsigned int nValue);

private:
	unsigned int m_Octave, m_TransposePitch, m_TransposeLights;
		};
