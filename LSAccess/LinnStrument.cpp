// LinnStrument.cpp

#include "LinnStrument.h"
#include <wx/msgdlg.h>

void LSCallback(double deltatime, std::vector< unsigned char > *message, void *pLinnStrument)
{
	LinnStrument * pMyLinnStrument = (LinnStrument*)pLinnStrument;
	pMyLinnStrument->ProcessMessage(*message);
}


LinnStrument::LinnStrument()
{
	try
	{
		m_MIDIIn = new RtMidiIn();

		m_InputID = GetUSBInPortID();
		
		if (m_InputID != -1)
		{
				m_MIDIIn->openPort(m_InputID);
			m_MIDIIn->setCallback(&LSCallback, (void*)this);
		}
	}
	catch (RtMidiError &error)
	{
		std::string wstrError( error.getMessage());
		m_InputID = -1;
	}
		
	try
	{
		m_MIDIOut = new RtMidiOut();
		m_OutputID = GetUSBOutPortID();

		if (m_OutputID != -1)
		{
			m_MIDIOut->openPort(m_OutputID);
		}
	}
	catch (RtMidiError &error)
	{
		std::string wstrError(error.getMessage());
		m_OutputID = -1;
	}
}


LinnStrument::~LinnStrument()
{
	try
	{
		if (m_MIDIIn->isPortOpen())
		{
			m_MIDIIn->closePort();
		}

		if (m_MIDIOut->isPortOpen())
		{
			m_MIDIOut->closePort();
		}
	}
		catch (RtMidiError &error)
	{
		std::string wstrError(error.getMessage());
		m_OutputID = -1;
	}
}


int LinnStrument::GetUSBInPortID()
{
	int nID;
	unsigned int nTest = m_MIDIIn->getPortCount();
		wxMessageBox( wxString::Format( "%d", nTest), L"Test");

		for ( nID = 0; nID < (int) m_MIDIIn->getPortCount(); nID++)
	{
		wxMessageBox(m_MIDIIn->getPortName(nID), L"Test");
			   					if (m_MIDIIn->getPortName(nID).compare(LSUSBName) == 0)
		{
			return nID;
		}
	}  // end for
		
	return -1;
}


int LinnStrument::GetUSBOutPortID()
{
	int nID = -1;

	return nID;
	}


void LinnStrument::ProcessMessage(std::vector <unsigned char> myMessage)
{
}


void LinnStrument::SendCC(unsigned char CCNumber, unsigned char CCValue)
{
}


void LinnStrument::SendNRPN(unsigned int NRPNNumber, unsigned int NRPNValue)
{
	/*
		NRPN input
		==========

		NRPN messages are a series of MIDI CC messages that allow changing more parameters than are supported by
		the standard MIDI CC message list. LinnStrument always expects an exact series of 6 MIDI CC messages to be
		received for setting one NRPN to a different value. The first two select the NRPN parameter number, the
		next two set the NRPN parameter value(both MSB and LSB are used), and the last two reset the active NRPN
		parameter number. Failure to reset the NRPN parameter number can result in other MIDI input messages to
		behave unpredictably.

		This is an overview of the message chain :

		1011nnnn   01100011 (99)  0vvvvvvv         NRPN parameter number MSB CC
		1011nnnn   01100010 (98)  0vvvvvvv         NRPN parameter number LSB CC
		1011nnnn   00000110 (6)  0vvvvvvv         NRPN parameter value MSB CC
		1011nnnn   00100110 (38)  0vvvvvvv         NRPN parameter value LSB CC
		1011nnnn   01100101 (101)  01111111 (127)   RPN parameter number Reset MSB CC
		1011nnnn   01100100 (100)  01111111 (127)   RPN parameter number Reset LSB CC
		*/
}


// Getters

// Setters:
// Value is an LSSplitMode
unsigned int LinnStrument::GetSPLIT_MODE_NRPN()
{
	return m_SPLIT_MODE_NRPN;
}


// Value constrained by MIN_MIDI_CHANNEL and MAX_MIDI_CHANNEL
unsigned int LinnStrument::GetMIDI_MAIN_CHANNEL_NRPN()
{
	return m_MIDI_MAIN_CHANNEL_NRPN;
}


// Left-hand split

unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN;
}


// Value is a MIDI channel number:
unsigned int LinnStrument::GetSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN()
{
	return m_SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN;
}


// Value is from LSBendRange
unsigned int LinnStrument::GetSPLIT_LEFT_BEND_RANGE_NRPN()
{
	return m_SPLIT_LEFT_BEND_RANGE_NRPN;
}


// Toggles:
unsigned int LinnStrument::GetSPLIT_LEFT_BEND_TOGGLE_NRPN()
{
	return m_SPLIT_LEFT_BEND_TOGGLE_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN()
{
	return m_SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN;
}


// Value is from LSPitchQuantize
unsigned int LinnStrument::GetSPLIT_LEFT_PITCH_QUANTIZE_NRPN()
{
	return m_SPLIT_LEFT_PITCH_QUANTIZE_NRPN;
}


// Toggles:
unsigned int LinnStrument::GetSPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN()
{
	return m_SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_SEND_Y_NRPN()
{
	return m_SPLIT_LEFT_SEND_Y_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_Y_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_Y_NRPN;
}


// Toggle:
unsigned int LinnStrument::GetSPLIT_LEFT_RELATIVE_Y_NRPN()
{
	return m_SPLIT_LEFT_RELATIVE_Y_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_RELATIVE_Z_NRPN()
{
	return m_SPLIT_LEFT_RELATIVE_Z_NRPN;
}


// Value is an LSExpressionZ
unsigned int LinnStrument::GetSPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN()
{
	return m_SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_Z_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_Z_NRPN;
}


// Values are defined in LSColor
unsigned int LinnStrument::GetSPLIT_LEFT_COLOR_MAIN_NRPN()
{
	return m_SPLIT_LEFT_COLOR_MAIN_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_COLOR_ACCENT_NRPN()
{
	return m_SPLIT_LEFT_COLOR_ACCENT_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_COLOR_PLAYED_NRPN()
{
	return m_SPLIT_LEFT_COLOR_PLAYED_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_COLOR_LOWROW_NRPN()
{
	return m_SPLIT_LEFT_COLOR_LOWROW_NRPN;
}


// Value is an LSLowRowMode
unsigned int LinnStrument::GetSPLIT_LEFT_LOWROW_MODE_NRPN()
{
	return m_SPLIT_LEFT_LOWROW_MODE_NRPN;
}


// Value is an LSSpecial:
unsigned int LinnStrument::GetSPLIT_LEFT_SPECIAL_NRPN()
{
	return m_SPLIT_LEFT_SPECIAL_NRPN;
}


// Value is an LSOctave
unsigned int LinnStrument::GetSPLIT_LEFT_OCTAVE_NRPN()
{
	return m_SPLIT_LEFT_OCTAVE_NRPN;
}


// Values are from LSPitch
unsigned int LinnStrument::GetSPLIT_LEFT_PITCH_TRANSPOSE_NRPN()
{
	return m_SPLIT_LEFT_PITCH_TRANSPOSE_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN()
{
	return m_SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN;
}


// Value is an LSExpressionY
unsigned int LinnStrument::GetSPLIT_LEFT_EXPRESSION_FOR_Y_NRPN()
{
	return m_SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_FADER1_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER1_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_FADER2_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER2_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_FADER3_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER3_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_FADER4_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER4_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_FADER5_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER5_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_FADER6_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER6_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_FADER7_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER7_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_FADER8_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER8_NRPN;
}


// Value is an LSLowRowBehaviour
unsigned int LinnStrument::GetSPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN()
{
	return m_SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_LOWROW_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_LOWROW_NRPN;
}


// Value is an LSLowRowBehaviour
unsigned int LinnStrument::GetSPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN()
{
	return m_SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
unsigned int LinnStrument::GetSPLIT_LEFT_MIN_CC_FOR_Y_NRPN()
{
	return m_SPLIT_LEFT_MIN_CC_FOR_Y_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_MAX_CC_FOR_Y_NRPN()
{
	return m_SPLIT_LEFT_MAX_CC_FOR_Y_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_MIN_CC_FOR_Z_NRPN()
{
	return m_SPLIT_LEFT_MIN_CC_FOR_Z_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_MAX_CC_FOR_Z_NRPN()
{
	return m_SPLIT_LEFT_MAX_CC_FOR_Z_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN()
{
	return m_SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN()
{
	return m_SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN;
}


// Value is an LSChannelOrder
unsigned int LinnStrument::GetSPLIT_LEFT_CHANNEL_PER_ROW_ORDER()
{
	return m_SPLIT_LEFT_CHANNEL_PER_ROW_ORDER;
}


// Value is an LSAnimation
unsigned int LinnStrument::GetSPLIT_LEFT_TOUCH_ANIMATION()
{
	return m_SPLIT_LEFT_TOUCH_ANIMATION;
}


// Toggle:
unsigned int LinnStrument::GetSPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN()
{
	return m_SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN()
{
	return m_SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN()
{
	return m_SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN;
}


// Value is an LSPatternNumber
unsigned int LinnStrument::GetSPLIT_LEFT_SEQUENCER_PATTERN_NRPN()
{
	return m_SPLIT_LEFT_SEQUENCER_PATTERN_NRPN;
}


unsigned int LinnStrument::GetSPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN()
{
	return m_SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN;
}


// Setters:

// Value is an LSSplitMode
void LinnStrument::SetSPLIT_MODE_NRPN(unsigned int nValue)
{
	m_SPLIT_MODE_NRPN = nValue;
	SendNRPN(SPLIT_MODE_NRPN, nValue);
}


// Value constrained by MIN_MIDI_CHANNEL and MAX_MIDI_CHANNEL
void LinnStrument::SetMIDI_MAIN_CHANNEL_NRPN(unsigned int nValue)
{
	m_MIDI_MAIN_CHANNEL_NRPN = nValue;
	SendNRPN( MIDI_MAIN_CHANNEL_NRPN, nValue);
}


// Left-hand split

// Toggles:
void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN, nValue);
}


// Value is a MIDI channel number:
void LinnStrument::SetSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN, nValue);
}


// Value is from LSBendRange
void LinnStrument::SetSPLIT_LEFT_BEND_RANGE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_BEND_RANGE_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_BEND_RANGE_NRPN, nValue);
}


// Toggles:
void LinnStrument::SetSPLIT_LEFT_BEND_TOGGLE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_BEND_TOGGLE_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_BEND_TOGGLE_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN, nValue);
}


// Value is from LSPitchQuantize
void LinnStrument::SetSPLIT_LEFT_PITCH_QUANTIZE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_PITCH_QUANTIZE_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_PITCH_QUANTIZE_NRPN, nValue);
}


// Toggles:
void LinnStrument::SetSPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_SEND_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SEND_Y_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_SEND_Y_NRPN, nValue);
}


// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
void LinnStrument::SetSPLIT_LEFT_CC_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_Y_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_Y_NRPN, nValue);
}


// Toggle:
void LinnStrument::SetSPLIT_LEFT_RELATIVE_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_RELATIVE_Y_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_RELATIVE_Y_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_RELATIVE_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_RELATIVE_Z_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_RELATIVE_Z_NRPN, nValue);
}


// Value is an LSExpressionZ
void LinnStrument::SetSPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN, nValue);
}


// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
void LinnStrument::SetSPLIT_LEFT_CC_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_Z_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_Z_NRPN, nValue);
}


// Values are defined in LSColor
void LinnStrument::SetSPLIT_LEFT_COLOR_MAIN_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_COLOR_MAIN_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_COLOR_MAIN_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_COLOR_ACCENT_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_COLOR_ACCENT_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_COLOR_ACCENT_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_COLOR_PLAYED_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_COLOR_PLAYED_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_COLOR_PLAYED_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_COLOR_LOWROW_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_COLOR_LOWROW_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_COLOR_LOWROW_NRPN, nValue);
}


// Value is an LSLowRowMode
void LinnStrument::SetSPLIT_LEFT_LOWROW_MODE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_LOWROW_MODE_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_LOWROW_MODE_NRPN, nValue);
}


// Value is an LSSpecial:
void LinnStrument::SetSPLIT_LEFT_SPECIAL_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SPECIAL_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_SPECIAL_NRPN, nValue);
}


// Value is an LSOctave
void LinnStrument::SetSPLIT_LEFT_OCTAVE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_OCTAVE_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_OCTAVE_NRPN, nValue);
}


// Values are from LSPitch
void LinnStrument::SetSPLIT_LEFT_PITCH_TRANSPOSE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_PITCH_TRANSPOSE_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_PITCH_TRANSPOSE_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN, nValue);
}


// Value is an LSExpressionY
void LinnStrument::SetSPLIT_LEFT_EXPRESSION_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN, nValue);
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LinnStrument::SetSPLIT_LEFT_CC_FOR_FADER1_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER1_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_FADER1_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CC_FOR_FADER2_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER2_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_FADER2_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CC_FOR_FADER3_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER3_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_FADER3_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CC_FOR_FADER4_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER4_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_FADER4_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CC_FOR_FADER5_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER5_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_FADER5_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CC_FOR_FADER6_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER6_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_FADER6_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CC_FOR_FADER7_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER7_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_FADER7_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CC_FOR_FADER8_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER8_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_FADER8_NRPN, nValue);
}


// Value is an LSLowRowBehaviour
void LinnStrument::SetSPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN, nValue);
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LinnStrument::SetSPLIT_LEFT_CC_FOR_LOWROW_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_LOWROW_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_LOWROW_NRPN, nValue);
}


// Value is an LSLowRowBehaviour
void LinnStrument::SetSPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN, nValue);
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LinnStrument::SetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN, nValue);
}


// Values are constrained by MIN_CC and MAX_CC
void LinnStrument::SetSPLIT_LEFT_MIN_CC_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_MIN_CC_FOR_Y_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_MIN_CC_FOR_Y_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_MAX_CC_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_MAX_CC_FOR_Y_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_MAX_CC_FOR_Y_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_MIN_CC_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_MIN_CC_FOR_Z_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_MIN_CC_FOR_Z_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_MAX_CC_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_MAX_CC_FOR_Z_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_MAX_CC_FOR_Z_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN, nValue);
}


// Value is an LSChannelOrder
void LinnStrument::SetSPLIT_LEFT_CHANNEL_PER_ROW_ORDER(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_ROW_ORDER = nValue;
	SendNRPN(SPLIT_LEFT_CHANNEL_PER_ROW_ORDER, nValue);
}


// Value is an LSAnimation
void LinnStrument::SetSPLIT_LEFT_TOUCH_ANIMATION(unsigned int nValue)
{
	m_SPLIT_LEFT_TOUCH_ANIMATION = nValue;
	SendNRPN(SPLIT_LEFT_TOUCH_ANIMATION, nValue);
}


// Toggle:
void LinnStrument::SetSPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN, nValue);
}


// Value is an LSPatternNumber
void LinnStrument::SetSPLIT_LEFT_SEQUENCER_PATTERN_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SEQUENCER_PATTERN_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_SEQUENCER_PATTERN_NRPN, nValue);
}


void LinnStrument::SetSPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN = nValue;
	SendNRPN(SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN, nValue);
}


// Getters
// Right-hand split

unsigned int LinnStrument::GetSPLIT_RIGHT_MAIN_MODE_NRPN()
{
	return m_SPLIT_RIGHT_MAIN_MODE_NRPN;
}


// Value is a MIDIChannel
unsigned int LinnStrument::GetSPLIT_RIGHT_MAIN_CHANNEL()
{
	return m_SPLIT_RIGHT_MAIN_CHANNEL;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN;
}


// Value is a MIDI channel number:
unsigned int LinnStrument::GetSPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN()
{
	return m_SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN;
}


// Value is from LSBendRange
unsigned int LinnStrument::GetSPLIT_RIGHT_BEND_RANGE_NRPN()
{
	return m_SPLIT_RIGHT_BEND_RANGE_NRPN;
}


// Toggles:
unsigned int LinnStrument::GetSPLIT_RIGHT_BEND_TOGGLE_NRPN()
{
	return m_SPLIT_RIGHT_BEND_TOGGLE_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN()
{
	return m_SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN;
}


// Value is from LSPitchQuantize
unsigned int LinnStrument::GetSPLIT_RIGHT_PITCH_QUANTIZE_NRPN()
{
	return m_SPLIT_RIGHT_PITCH_QUANTIZE_NRPN;
}


// Toggles:
unsigned int LinnStrument::GetSPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN()
{
	return m_SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_SEND_Y_NRPN()
{
	return m_SPLIT_RIGHT_SEND_Y_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_Y_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_Y_NRPN;
}


// Toggle:
unsigned int LinnStrument::GetSPLIT_RIGHT_RELATIVE_Y_NRPN()
{
	return m_SPLIT_RIGHT_RELATIVE_Y_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_RELATIVE_Z_NRPN()
{
	return m_SPLIT_RIGHT_RELATIVE_Z_NRPN;
}


// Value is an LSExpressionZ
unsigned int LinnStrument::GetSPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN()
{
	return m_SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_Z_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_Z_NRPN;
}


// Values are defined in LSColor
unsigned int LinnStrument::GetSPLIT_RIGHT_COLOR_MAIN_NRPN()
{
	return m_SPLIT_RIGHT_COLOR_MAIN_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_COLOR_ACCENT_NRPN()
{
	return m_SPLIT_RIGHT_COLOR_ACCENT_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_COLOR_PLAYED_NRPN()
{
	return m_SPLIT_RIGHT_COLOR_PLAYED_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_COLOR_LOWROW_NRPN()
{
	return m_SPLIT_RIGHT_COLOR_LOWROW_NRPN;
}


// Value is an LSLowRowMode
unsigned int LinnStrument::GetSPLIT_RIGHT_LOWROW_MODE_NRPN()
{
	return m_SPLIT_RIGHT_LOWROW_MODE_NRPN;
}


// Value is an LSSpecial:
unsigned int LinnStrument::GetSPLIT_RIGHT_SPECIAL_NRPN()
{
	return m_SPLIT_RIGHT_SPECIAL_NRPN;
}


// Value is an LSOctave
unsigned int LinnStrument::GetSPLIT_RIGHT_OCTAVE_NRPN()
{
	return m_SPLIT_RIGHT_OCTAVE_NRPN;
}


// Values are from LSPitch
unsigned int LinnStrument::GetSPLIT_RIGHT_PITCH_TRANSPOSE_NRPN()
{
	return m_SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN()
{
	return m_SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN;
}


// Value is an LSExpressionY
unsigned int LinnStrument::GetSPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN()
{
	return m_SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_FADER1_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER1_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_FADER2_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER2_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_FADER3_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER3_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_FADER4_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER4_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_FADER5_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER5_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_FADER6_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER6_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_FADER7_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER7_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_FADER8_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER8_NRPN;
}


// Value is an LSLowRowBehaviour
unsigned int LinnStrument::GetSPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN()
{
	return m_SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_LOWROW_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_LOWROW_NRPN;
}


// Value is an LSLowRowBehaviour
unsigned int LinnStrument::GetSPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN()
{
	return m_SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
unsigned int LinnStrument::GetSPLIT_RIGHT_MIN_CC_FOR_Y_NRPN()
{
	return m_SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_MAX_CC_FOR_Y_NRPN()
{
	return m_SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_MIN_CC_FOR_Z_NRPN()
{
	return m_SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_MAX_CC_FOR_Z_NRPN()
{
	return m_SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN()
{
	return m_SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN()
{
	return m_SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN;
}


// Value is an LSChannelOrder
unsigned int LinnStrument::GetSPLIT_RIGHT_CHANNEL_PER_ROW_ORDER()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER;
}


// Value is an LSAnimation
unsigned int LinnStrument::GetSPLIT_RIGHT_TOUCH_ANIMATION()
{
	return m_SPLIT_RIGHT_TOUCH_ANIMATION;
}


// Toggle:
unsigned int LinnStrument::GetSPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN()
{
	return m_SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN()
{
	return m_SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN()
{
	return m_SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN;
}


// Value is an LSPatternNumber
unsigned int LinnStrument::GetSPLIT_RIGHT_SEQUENCER_PATTERN_NRPN()
{
	return m_SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN;
}


unsigned int LinnStrument::GetSPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN()
{
	return m_SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN;
}


// Setters:

// Left-hand split

// Toggles:
void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN, nValue);
}


// Value is a MIDI channel number:
void LinnStrument::SetSPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN, nValue);
}


// Value is from LSBendRange
void LinnStrument::SetSPLIT_RIGHT_BEND_RANGE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_BEND_RANGE_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_BEND_RANGE_NRPN, nValue);
}


// Toggles:
void LinnStrument::SetSPLIT_RIGHT_BEND_TOGGLE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_BEND_TOGGLE_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_BEND_TOGGLE_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN, nValue);
}


// Value is from LSPitchQuantize
void LinnStrument::SetSPLIT_RIGHT_PITCH_QUANTIZE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_PITCH_QUANTIZE_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_PITCH_QUANTIZE_NRPN, nValue);
}


// Toggles:
void LinnStrument::SetSPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_SEND_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SEND_Y_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_SEND_Y_NRPN, nValue);
}


// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
void LinnStrument::SetSPLIT_RIGHT_CC_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_Y_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_Y_NRPN, nValue);
}


// Toggle:
void LinnStrument::SetSPLIT_RIGHT_RELATIVE_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_RELATIVE_Y_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_RELATIVE_Y_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_RELATIVE_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_RELATIVE_Z_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_RELATIVE_Z_NRPN, nValue);
}


// Value is an LSExpressionZ
void LinnStrument::SetSPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN, nValue);
}


// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
void LinnStrument::SetSPLIT_RIGHT_CC_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_Z_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_Z_NRPN, nValue);
}


// Values are defined in LSColor
void LinnStrument::SetSPLIT_RIGHT_COLOR_MAIN_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_COLOR_MAIN_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_COLOR_MAIN_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_COLOR_ACCENT_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_COLOR_ACCENT_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_COLOR_ACCENT_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_COLOR_PLAYED_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_COLOR_PLAYED_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_COLOR_PLAYED_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_COLOR_LOWROW_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_COLOR_LOWROW_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_COLOR_LOWROW_NRPN, nValue);
}


// Value is an LSLowRowMode
void LinnStrument::SetSPLIT_RIGHT_LOWROW_MODE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_LOWROW_MODE_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_LOWROW_MODE_NRPN, nValue);
}


// Value is an LSSpecial:
void LinnStrument::SetSPLIT_RIGHT_SPECIAL_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SPECIAL_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_SPECIAL_NRPN, nValue);
}


// Value is an LSOctave
void LinnStrument::SetSPLIT_RIGHT_OCTAVE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_OCTAVE_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_OCTAVE_NRPN, nValue);
}


// Values are from LSPitch
void LinnStrument::SetSPLIT_RIGHT_PITCH_TRANSPOSE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN, nValue);
}


// Value is an LSExpressionY
void LinnStrument::SetSPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN, nValue);
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LinnStrument::SetSPLIT_RIGHT_CC_FOR_FADER1_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER1_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_FADER1_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CC_FOR_FADER2_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER2_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_FADER2_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CC_FOR_FADER3_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER3_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_FADER3_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CC_FOR_FADER4_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER4_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_FADER4_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CC_FOR_FADER5_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER5_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_FADER5_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CC_FOR_FADER6_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER6_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_FADER6_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CC_FOR_FADER7_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER7_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_FADER7_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CC_FOR_FADER8_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER8_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_FADER8_NRPN, nValue);
}


// Value is an LSLowRowBehaviour
void LinnStrument::SetSPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN, nValue);
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LinnStrument::SetSPLIT_RIGHT_CC_FOR_LOWROW_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_LOWROW_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_NRPN, nValue);
}


// Value is an LSLowRowBehaviour
void LinnStrument::SetSPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN, nValue);
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LinnStrument::SetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN, nValue);
}


// Values are constrained by MIN_CC and MAX_CC
void LinnStrument::SetSPLIT_RIGHT_MIN_CC_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_MAX_CC_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_MIN_CC_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_MAX_CC_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN, nValue);
}


// Value is an LSChannelOrder
void LinnStrument::SetSPLIT_RIGHT_CHANNEL_PER_ROW_ORDER(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER = nValue;
	SendNRPN(SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER, nValue);
}


// Value is an LSAnimation
void LinnStrument::SetSPLIT_RIGHT_TOUCH_ANIMATION(unsigned int nValue)
{
	m_SPLIT_RIGHT_TOUCH_ANIMATION = nValue;
	SendNRPN(SPLIT_RIGHT_TOUCH_ANIMATION, nValue);
}


// Toggle:
void LinnStrument::SetSPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN, nValue);
}


// Value is an LSPatternNumber
void LinnStrument::SetSPLIT_RIGHT_SEQUENCER_PATTERN_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN, nValue);
}


void LinnStrument::SetSPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN = nValue;
	SendNRPN(SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN, nValue);
}

