// LinnStrument.cpp

#include "LinnStrument.h"



std::string MIDINoteName(unsigned char nNoteNumber)
{
	std::string strNoteName;
	int nOctaveNumber = ((nNoteNumber + 12) / 12) - 1;

	switch (nNoteNumber % 12)
	{
	case 0: strNoteName = "C";
	case 1: strNoteName = "C#";
	case 2: strNoteName = "D";
	case 3: strNoteName = "D#";
	case 4: strNoteName = "E";
	case 5: strNoteName = "F";
	case 6: strNoteName = "F#";
	case 7: strNoteName = "G";
	case 8: strNoteName = "G#";
	case 9: strNoteName = "A";
	case 10: strNoteName = "A#";
	case 11: strNoteName = "B";
	default: strNoteName = "";
	}  // end switch
	return strNoteName.append(std::to_string(nOctaveNumber));
}


void SendCC(unsigned char CCNumber, unsigned char CCValue)
{
}


void LinnStrument::SendNRPN(unsigned int nChannel, unsigned int NRPNNumber, unsigned int NRPNValue)
{
	std::vector<unsigned char> myMessage;
	unsigned char myNRPNParameterMSB, myNRPNParameterLSB;
	unsigned char myNRPNValueMSB, myNRPNValueLSB;

	if (NRPNNumber == REQUEST_VALUE_OF_NRPN)
	{
		// Record the NRPN parameter we're querying
		m_NRPNQueue.push(NRPNValue);
}

// Calculate the MSB and LSB values here

	myMessage.push_back( (unsigned char) nChannel);
	myMessage.push_back(myNRPNParameterMSB);
	myMessage.push_back(myNRPNParameterLSB);
	m_MIDIOut->sendMessage(&myMessage);

	myMessage.push_back( (unsigned char) nChannel);
	myMessage.push_back(myNRPNValueMSB);
	myMessage.push_back(myNRPNValueLSB);
	m_MIDIOut->sendMessage(&myMessage);

	myMessage.push_back((unsigned char)nChannel);
	myMessage.push_back(RESET_NRPN_CC_MSB);
	myMessage.push_back(127);
	m_MIDIOut->sendMessage(&myMessage);

	myMessage.push_back((unsigned char)nChannel);
	myMessage.push_back(RESET_NRPN_CC_LSB);
	myMessage.push_back(127);
	m_MIDIOut->sendMessage(&myMessage);
}


void LSCallback(double deltatime, std::vector< unsigned char > *message, void *pLinnStrument)
{
	LinnStrument * pMyLinnStrument = (LinnStrument*)pLinnStrument;
	pMyLinnStrument->ProcessMessage(*message);
}


LinnStrument::LinnStrument():
	m_OutputID(-1),
	m_InputID( -1),
	blnReceivedNRPNResetMSB(false),
	blnReceivedNRPNResetLSB(false),
	m_SpeakNotes(false)
	{
	try
	{
		m_MIDIIn = new RtMidiIn();
		m_MIDIOut = new RtMidiOut();
		m_OutputID = GetUSBOutPortID();
		m_InputID = GetUSBInPortID();

		if ((m_OutputID == -1) || (m_InputID == -1))
		{
			// Prompt for appropriate DIN sockets
			MIDIDialog * pMIDIDialog = new MIDIDialog(L"LinnStrument MIDI I/O jacks");
			if (pMIDIDialog->ShowModal() == wxID_OK)
			{
												m_GlobalSettings.SetGLOBAL_MIDI_DEVICE_IO(m_GlobalSettings.GetLS_MIDIDeviceIndex(LS_MIDIDevice::MIDI_DIN_JACKS));
												m_OutputID = pMIDIDialog->GetSelectedOutput();
													m_InputID = pMIDIDialog->GetSelectedInput();

													if ((m_OutputID != -1) && (m_InputID != -1))
													{
														m_MIDIOut->openPort();
														m_MIDIIn->openPort(pMIDIDialog->GetSelectedInput());
														m_MIDIIn->setCallback(&LSCallback, (void*)this);
													}  // if valid port selections
																}   // if dialog OK
			else
			{
				m_InputID = -1;
				m_OutputID = -1;
			}  // dialog cancelled
		}   
		else  // USB connection detected
		{
			m_GlobalSettings.SetGLOBAL_MIDI_DEVICE_IO(m_GlobalSettings.GetLS_MIDIDeviceIndex(LS_MIDIDevice::USB));
			m_MIDIOut->openPort(m_OutputID);
			m_MIDIIn->openPort(m_InputID);
			m_MIDIIn->setCallback(&LSCallback, (void*)this);
		}
	}  // end try
		catch (RtMidiError &error)
	{
		std::string wstrError( error.getMessage());
		m_InputID = -1;
		m_OutputID = -1;
		m_GlobalSettings.SetGLOBAL_MIDI_DEVICE_IO(m_GlobalSettings.GetLS_MIDIDeviceIndex(LS_MIDIDevice::MIDI_DIN_JACKS));
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
	
		for ( nID = 0; nID < (int) m_MIDIIn->getPortCount(); nID++)
	{
			std::string strTemp = m_MIDIIn->getPortName(nID);
			unsigned int nPos = strTemp.find_last_of(" ");
			strTemp = strTemp.substr(0, nPos);

						if (strTemp.compare(LSUSBName) == 0)
		{
			return nID;
		}
	}  // end for
		
	return -1;
}


int LinnStrument::GetUSBOutPortID()
{
	int nID;

	for (nID = 0; nID < (int)m_MIDIOut->getPortCount(); nID++)
	{
		// C++17 - try using string_view instead: better memory management
				std::string strTemp = m_MIDIOut->getPortName(nID);
		unsigned int nPos = strTemp.find_last_of(" ");
		strTemp = strTemp.substr(0, nPos);

		if (strTemp.compare(LSUSBName) == 0)
		{
			return nID;
		}
	}  // end for

	return -1;
}


void LinnStrument::SetLSParameter(unsigned int NRPNParameterIn, unsigned int NRPNValueIn)
{
	switch (NRPNParameterIn)
	{
		// Per-split parameters

// Left-hand split
	case SPLIT_LEFT_MAIN_MODE_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_MAIN_CHANNEL_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_BEND_RANGE_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_BEND_TOGGLE_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_PITCH_QUANTIZE_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_SEND_Y_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_Y_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_RELATIVE_Y_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_SEND_Z_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_Z_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_COLOR_MAIN_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_COLOR_ACCENT_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_COLOR_PLAYED_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_COLOR_LOWROW_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_LOWROW_MODE_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_SPECIAL_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_OCTAVE_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_PITCH_TRANSPOSE_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER1_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER2_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER3_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER4_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER5_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER6_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER7_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER8_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_LOWROW_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_MIN_CC_FOR_Y_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_MAX_CC_FOR_Y_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_MIN_CC_FOR_Z_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_MAX_CC_FOR_Z_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_ROW_ORDER_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_TOUCH_ANIMATION_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_SEQUENCER_PATTERN_NRPN:
	{

	}
	break;

	case SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN:
	{

	}
	break;


	// Right-hand split
	case SPLIT_RIGHT_MAIN_MODE_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_MAIN_CHANNEL_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_BEND_RANGE_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_BEND_TOGGLE_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_PITCH_QUANTIZE_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_SEND_Y_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_Y_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_RELATIVE_Y_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_RELATIVE_Z_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_Z_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_COLOR_MAIN_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_COLOR_ACCENT_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_COLOR_PLAYED_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_COLOR_LOWROW_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_LOWROW_MODE_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_SPECIAL_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_OCTAVE_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER1_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER2_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER3_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER4_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER5_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER6_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER7_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER8_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_LOWROW_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_TOUCH_ANIMATION_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN:
	{

	}
	break;

	case SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN:
	{

	}
	break;


	// Global parameters
	case GLOBAL_SPLIT_ACTIVE_NRPN:
	{

	}
	break;

	case GLOBAL_SELECTED_SPLIT_NRPN:
	{

	}
	break;

	case GLOBAL_SPLIT_COLUMN_NRPN:
	{

	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_C_NRPN:
	{

	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_NRPN:
	{

	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_D_NRPN:
	{

	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_NRPN:
	{

	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_E_NRPN:
	{

	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_F_NRPN:
	{

	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_NRPN:
	{

	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_G_NRPN:
	{

	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_NRPN:
	{

	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_A_NRPN:
	{

	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_NRPN:
	{

	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_B_NRPN:
	{

	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_C_NRPN:
	{

	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_NRPN:
	{

	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_D_NRPN:
	{

	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_NRPN:
	{

	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_E_NRPN:
	{

	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_F_NRPN:
	{

	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_NRPN:
	{

	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_G_NRPN:
	{

	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_NRPN:
	{

	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_A_NRPN:
	{

	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_NRPN:
	{

	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_B_NRPN:
	{

	}
	break;

	case GLOBAL_ROW_OFFSET_NRPN:
	{

	}
	break;

	case GLOBAL_SWITCH1_ASSIGN_NRPN:
	{

	}
	break;

	case GLOBAL_SWITCH2_ASSIGN_NRPN:
	{

	}
	break;

	case GLOBAL_FOOT_LEFT_ASSIGN_NRPN:
	{

	}
	break;

	case GLOBAL_FOOT_RIGHT_ASSIGN_NRPN:
	{

	}
	break;

	case GLOBAL_VELOCITY_SENSITIVITY_NRPN:
	{

	}
	break;

	case GLOBAL_PRESSURE_SENSITIVITY_NRPN:
	{

	}
	break;

	case GLOBAL_MIDI_DEVICE_IO_NRPN:
	{

	}
	break;

	case GLOBAL_ARP_DIRECTION_NRPN:
	{

	}
	break;

	case GLOBAL_ARP_TEMPO_NOTE_VALUE_NRPN:
	{

	}
	break;

	case GLOBAL_ARP_OCTAVE_EXTENSION_NRPN:
	{

	}
	break;

	case GLOBAL_CLOCK_BPM_NRPN:
	{

	}
	break;

	case GLOBAL_SWITCH1_BOTH_SPLITS_NRPN:
	{

	}
	break;

	case GLOBAL_SWITCH2_BOTH_SPLITS_NRPN:
	{

	}
	break;

	case GLOBAL_FOOT_LEFT_BOTH_SPLITS_NRPN:
	{

	}
	break;

	case GLOBAL_FOOT_RIGHT_BOTH_SPLITS_NRPN:
	{

	}
	break;

	case GLOBAL_SETTINGS_PRESET_LOAD_NRPN:
	{

	}
	break;

	case GLOBAL_PRESSURE_AFTERTOUCH_NRPN:
	{

	}
	break;

	case DEVICE_USER_FIRMWARE_MODE_NRPN:
	{

	}
	break;

	case DEVICE_LEFT_HANDED_NRPN:
	{

	}
	break;

	case GLOBAL_ACTIVE_LIGHTS_PRESET_NRPN:
	{

	}
	break;

	case GLOABAL_CC_FOR_CC65: // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
	case GLOBAL_MIN_VELOCITY_VALUE_NRPN:
	{

	}
	break;

	case GLOBAL_MAX_VELOCITY_VALUE_NRPN:
	{

	}
	break;

	case GLOBAL_FIXED_VELOCITY_VALUE_NRPN:
	{

	}
	break;

	case DEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN:
	{

	}
	break;

	case GLOBAL_CUSTOM_ROW_OFFSET:
	{

	}
	break;

	case DEVICE_MIDI_THRU_NRPN:
	{

	}
	break;

	case GLOBAL_CC_FOR_LEFT_FOOT_CC65:
	{

	}
	break;

	case GLOBAL_CC_FOR_RIGHT_FOOT_CC65:
	{

	}
	break;

	case GLOBAL_CC_FOR_SWITCH1_CC65:
	{

	}
	break;

	case GLOBAL_CC_FOR_SWITCH2_CC65:
	{

	}
	break;

	case GLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN:
	{

	}
	break;

	case GLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN:
	{

	}
	break;

	case GLOBAL_CC_FOR_SWITCH1_SUSTAIN:
	{

	}
	break;

	case GLOBAL_CC_FOR_SWITCH2_SUSTAIN:
	{

	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW1:
	{

	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW2:
	{

	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW3:
	{

	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW4:
	{

	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW5:
	{

	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW6:
	{

	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW7:
	{

	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW8:
	{

	}
	break;

	default:
	{}
	break;
		} // end switch
}


void LinnStrument::ProcessMessage(std::vector <unsigned char> myMessage)
{
	unsigned char nStatus = MIDI().ShortMsgStatus(myMessage);

	switch (nStatus)
	{
	case MIDI_CMD_NOTE_ON:
	{
		if (m_SpeakNotes)
		{
			unsigned char nNoteNumber = MIDI().ShortMsgData1(myMessage);
			std::string strNoteName = MIDINoteName(nNoteNumber);
			// Announce
					}
}
	break;

		case CC_NRPN_PARAM_MSB:
		{
			m_NRPNParameterIn = MIDI().ShortMsgData2(myMessage) * 127;
		}
		break;

		case CC_NRPN_PARAM_LSB:
		{
			m_NRPNParameterIn = m_NRPNParameterIn + MIDI().ShortMsgData2(myMessage);
		}
		break;

		case CC_NRPN_VALUE_MSB:
		{
			m_NRPNValueIn = MIDI().ShortMsgData2(myMessage) * 127;
		}
		break;

		case CC_NRPN_VALUE_LSB:
		{
			m_NRPNValueIn = m_NRPNValueIn + MIDI().ShortMsgData2(myMessage);
		}
		break;

		case RESET_NRPN_CC_MSB:
		{
if ((blnReceivedNRPNResetLSB) && (m_NRPNParameterIn == REQUEST_VALUE_OF_NRPN))
			{
	m_NRPNParameterIn = m_NRPNQueue.Front();
	m_NRPNQueue.pop();
				SetLSParameter(m_NRPNParameterIn, m_NRPNValueIn);
				blnReceivedNRPNResetMSB = false;
				blnReceivedNRPNResetLSB = false;
			}
			else
			{
				blnReceivedNRPNResetLSB = true;
			}
		}
		break;

		case RESET_NRPN_CC_LSB:
		{
			if (blnReceivedNRPNResetMSB)
			{
				SetLSParameter(m_NRPNParameterIn, m_NRPNValueIn);
				blnReceivedNRPNResetMSB = false;
				blnReceivedNRPNResetLSB = false;
			}
			else
			{
				blnReceivedNRPNResetLSB = true;
			}
					   		}
		break;

		default:
			{
			}
			break;
		}  // end switch
}


bool LinnStrument::GetSpeakNotes()
{
	return m_SpeakNotes;
	}

void LinnStrument::SetSpeakNotes(bool blnSpeakNotes)
{
	m_SpeakNotes = blnSpeakNotes;
}

LSPerSplitSettings LinnStrument::GetPerSplitSettings()
{
	return m_PerSplitSettings;
}


LSOctaveTransposeSettings LinnStrument::GetOctaveTransposeSettings()
{
	return m_OctaveTransposeSettings;
}


LSGlobalSettings LinnStrument::GetGlobalSettings()
{
	return m_GlobalSettings;
	}


