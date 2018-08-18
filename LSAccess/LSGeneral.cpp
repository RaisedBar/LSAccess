// LSGeneral.cpp

#include "LSGeneral.h"

LSGeneralSettings::LSGeneralSettings()
{}


// Value is an LSSplitMode
void LSGeneralSettings::SetSPLIT_MODE_NRPN(unsigned int nValue)
{
	m_SPLIT_MODE_NRPN = nValue;
	}


// Value constrained by MIN_MIDI_CHANNEL and MAX_MIDI_CHANNEL
void LSGeneralSettings::SetMIDI_MAIN_CHANNEL_NRPN(unsigned int nValue)
{
	m_MIDI_MAIN_CHANNEL_NRPN = nValue;
}


// Value is an LSSplitMode
unsigned int LSGeneralSettings::GetSPLIT_MODE_NRPN()
{
	return m_SPLIT_MODE_NRPN;
	}


// Value constrained by MIN_MIDI_CHANNEL and MAX_MIDI_CHANNEL
unsigned int LSGeneralSettings::GetMIDI_MAIN_CHANNEL_NRPN()
{
	return m_MIDI_MAIN_CHANNEL_NRPN;
	}


