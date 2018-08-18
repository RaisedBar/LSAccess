// LSGeneral.h

#pragma once

// Value is an LSSplitMode
const unsigned int SPLIT_MODE_NRPN = 0;

// Value constrained by MIN_MIDI_CHANNEL and MAX_MIDI_CHANNEL
const unsigned int MIDI_MAIN_CHANNEL_NRPN = 1;

class LSGeneralSettings
{
public:
	LSGeneralSettings();

		unsigned int GetSPLIT_MODE_NRPN();
	unsigned int GetMIDI_MAIN_CHANNEL_NRPN();
	void SetSPLIT_MODE_NRPN(unsigned int nValue);
	void SetMIDI_MAIN_CHANNEL_NRPN(unsigned int nValue);
	
			   private:
	unsigned int m_SPLIT_MODE_NRPN;
	unsigned int m_MIDI_MAIN_CHANNEL_NRPN;
};


