// LinnStrument.cpp

#include "LinnStrument.h"


void SendCC(unsigned char CCNumber, unsigned char CCValue)
{

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
												m_GlobalSettings.SetGLOBAL_MIDI_DEVICE_IO( m_GlobalSettings.GetLS_MIDIDeviceIndex(LS_MIDIDevice::MIDI_DIN_JACKS));
												m_OutputID = pMIDIDialog->GetSelectedOutput();
													m_InputID = pMIDIDialog->GetSelectedInput();

													if ((m_OutputID != -1) && (m_InputID != -1))
													{
														m_MIDIOut->openPort();
														m_MIDIIn->openPort(pMIDIDialog->GetSelectedInput());
														m_MIDIIn->setCallback(&LSCallback, (void*)this);
														QueryAll();
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
			QueryAll();
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
		
		// Dereference the callback
		
		// Tidy up
		m_MIDIIn->setCallback(NULL);
		delete m_MIDIIn;
		delete m_MIDIOut;
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
		// Update the appropriate member based on the provided NRPN parameter number
			switch (NRPNParameterIn)
	{
		// Per-split parameters

// Left-hand split
	case SPLIT_LEFT_MAIN_MODE_NRPN:
	{
					m_PerSplitSettings.SetSPLIT_MODE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MAIN_CHANNEL_NRPN:
	{
		m_PerSplitSettings.SetMIDI_MAIN_CHANNEL(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_1(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_2(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_3(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_4(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_5(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_6(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_7(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_8(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_9(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_10(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_11(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_12(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_13(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_14(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_15(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_16(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN:
	{
		m_PerSplitSettings.SetMIDI_PER_ROW_LOWEST_CHANNEL(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_BEND_RANGE_NRPN:
	{
		m_PerSplitSettings.SetBEND_RANGE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_BEND_TOGGLE_NRPN:
	{
		m_PerSplitSettings.SetBEND_TOGGLE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN:
	{
		m_PerSplitSettings.SetBEND_QUANTIZE_TOGGLE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_PITCH_QUANTIZE_NRPN:
	{
		m_PerSplitSettings.SetBEND_QUANTIZE_TOGGLE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN:
	{
		m_PerSplitSettings.SetRESET_PITCH_ON_RELEASE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEND_Y_NRPN:
	{
		m_PerSplitSettings.SetSEND_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_Y_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_RELATIVE_Y_NRPN:
	{
		m_PerSplitSettings.SetRELATIVE_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEND_Z_NRPN:
	{
		m_PerSplitSettings.SetSEND_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN:
	{
		m_PerSplitSettings.SetMIDI_EXPRESSION_FOR_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_Z_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_COLOR_MAIN_NRPN:
	{
		m_PerSplitSettings.SetCOLOR_MAIN(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_COLOR_ACCENT_NRPN:
	{
		m_PerSplitSettings.SetCOLOR_ACCENT(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_COLOR_PLAYED_NRPN:
	{
		m_PerSplitSettings.SetCOLOR_PLAYED(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_COLOR_LOWROW_NRPN:
	{
		m_PerSplitSettings.SetCOLOR_LOWROW(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_LOWROW_MODE_NRPN:
	{
		m_PerSplitSettings.SetLOWROW_MODE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SPECIAL_NRPN:
	{
		m_PerSplitSettings.SetSPECIAL(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_OCTAVE_NRPN:
	{
		m_PerSplitSettings.SetOCTAVE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_PITCH_TRANSPOSE_NRPN:
	{
		m_PerSplitSettings.SetPITCH_TRANSPOSE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN:
	{
		m_PerSplitSettings.SetTRANSPOSE_LIGHTS(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN:
	{
		m_PerSplitSettings.SetEXPRESSION_FOR_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER1_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER1(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER2_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER2(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER3_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER3(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER4_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER4(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER5_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER5(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER6_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER6(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER7_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER7(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER8_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER8(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN:
	{
		m_PerSplitSettings.SetLOWROW_X_BEHAVIOUR(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_LOWROW_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_LOWROW(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN:
	{
		m_PerSplitSettings.SetLOWROW_XYZ_BEHAVIOUR(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_LOWROW_XYZ(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_LOWROW_XYZ_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_LOWROW_XYZ_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MIN_CC_FOR_Y_NRPN:
	{
		m_PerSplitSettings.SetMIN_CC_FOR_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MAX_CC_FOR_Y_NRPN:
	{
		m_PerSplitSettings.SetMAX_CC_FOR_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MIN_CC_FOR_Z_NRPN:
	{
		m_PerSplitSettings.SetMIN_CC_FOR_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MAX_CC_FOR_Z_NRPN:
	{
		m_PerSplitSettings.SetMAX_CC_FOR_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN:
	{
		m_PerSplitSettings.Set14BIT_CC_VALUE_FOR_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN:
	{
		m_PerSplitSettings.SetINITIAL_RELATIVE_VALUE_FOR_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_ROW_ORDER_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_ROW_ORDER(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_TOUCH_ANIMATION_NRPN:
	{
		m_PerSplitSettings.SetTOUCH_ANIMATION(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN:
	{
		m_PerSplitSettings.SetSEQUENCER_TOGGLE_PLAY(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN:
	{
		m_PerSplitSettings.SetSEQUENCER_PREVIOUS_PATTERN(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN:
	{
		m_PerSplitSettings.SetSEQUENCER_NEXT_PATTERN(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEQUENCER_PATTERN_NRPN:
	{
		m_PerSplitSettings.SetSEQUENCER_PATTERN(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN:
	{
		m_PerSplitSettings.SetSEQUENCER_TOGGLE_MUTE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	// Right-hand split

			case SPLIT_RIGHT_MAIN_MODE_NRPN:
	{
					m_PerSplitSettings.SetSPLIT_MODE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MAIN_CHANNEL_NRPN:
	{
		m_PerSplitSettings.SetMIDI_MAIN_CHANNEL(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_1(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_2(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_3(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_4(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_5(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_6(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_7(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_8(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_9(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_10(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_11(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_12(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_13(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_14(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_15(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_NOTE_16(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN:
	{
		m_PerSplitSettings.SetMIDI_PER_ROW_LOWEST_CHANNEL(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_BEND_RANGE_NRPN:
	{
		m_PerSplitSettings.SetBEND_RANGE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_BEND_TOGGLE_NRPN:
	{
		m_PerSplitSettings.SetBEND_TOGGLE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN:
	{
		m_PerSplitSettings.SetBEND_QUANTIZE_TOGGLE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_PITCH_QUANTIZE_NRPN:
	{
		m_PerSplitSettings.SetBEND_QUANTIZE_TOGGLE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN:
	{
		m_PerSplitSettings.SetRESET_PITCH_ON_RELEASE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEND_Y_NRPN:
	{
		m_PerSplitSettings.SetSEND_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_Y_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_RELATIVE_Y_NRPN:
	{
		m_PerSplitSettings.SetRELATIVE_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	/*
	case SPLIT_RIGHT_SEND_Z_NRPN:
	{
		m_PerSplitSettings.SetSEND_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;
	*/

	case SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN:
	{
		m_PerSplitSettings.SetMIDI_EXPRESSION_FOR_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_Z_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_COLOR_MAIN_NRPN:
	{
		m_PerSplitSettings.SetCOLOR_MAIN(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_COLOR_ACCENT_NRPN:
	{
		m_PerSplitSettings.SetCOLOR_ACCENT(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_COLOR_PLAYED_NRPN:
	{
		m_PerSplitSettings.SetCOLOR_PLAYED(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_COLOR_LOWROW_NRPN:
	{
		m_PerSplitSettings.SetCOLOR_LOWROW(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_LOWROW_MODE_NRPN:
	{
		m_PerSplitSettings.SetLOWROW_MODE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SPECIAL_NRPN:
	{
		m_PerSplitSettings.SetSPECIAL(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_OCTAVE_NRPN:
	{
		m_PerSplitSettings.SetOCTAVE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN:
	{
		m_PerSplitSettings.SetPITCH_TRANSPOSE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN:
	{
		m_PerSplitSettings.SetTRANSPOSE_LIGHTS(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN:
	{
		m_PerSplitSettings.SetEXPRESSION_FOR_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER1_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER1(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER2_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER2(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER3_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER3(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER4_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER4(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER5_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER5(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER6_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER6(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER7_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER7(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER8_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_FADER8(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN:
	{
		m_PerSplitSettings.SetLOWROW_X_BEHAVIOUR(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_LOWROW_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_LOWROW(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN:
	{
		m_PerSplitSettings.SetLOWROW_XYZ_BEHAVIOUR(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_LOWROW_XYZ(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_LOWROW_XYZ_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN:
	{
		m_PerSplitSettings.SetCC_FOR_LOWROW_XYZ_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN:
	{
		m_PerSplitSettings.SetMIN_CC_FOR_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN:
	{
		m_PerSplitSettings.SetMAX_CC_FOR_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN:
	{
		m_PerSplitSettings.SetMIN_CC_FOR_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN:
	{
		m_PerSplitSettings.SetMAX_CC_FOR_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN:
	{
		m_PerSplitSettings.Set14BIT_CC_VALUE_FOR_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN:
	{
		m_PerSplitSettings.SetINITIAL_RELATIVE_VALUE_FOR_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER_NRPN:
	{
		m_PerSplitSettings.SetCHANNEL_PER_ROW_ORDER(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_TOUCH_ANIMATION_NRPN:
	{
		m_PerSplitSettings.SetTOUCH_ANIMATION(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN:
	{
		m_PerSplitSettings.SetSEQUENCER_TOGGLE_PLAY(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN:
	{
		m_PerSplitSettings.SetSEQUENCER_PREVIOUS_PATTERN(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN:
	{
		m_PerSplitSettings.SetSEQUENCER_NEXT_PATTERN(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN:
	{
		m_PerSplitSettings.SetSEQUENCER_PATTERN(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN:
	{
		m_PerSplitSettings.SetSEQUENCER_TOGGLE_MUTE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	// Global parameters

	case GLOBAL_SPLIT_ACTIVE_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_SPLIT_ACTIVE(NRPNValueIn);
	}
	break;

	case GLOBAL_SELECTED_SPLIT_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_SELECTED_SPLIT(NRPNValueIn);
	}
	break;

	case GLOBAL_SPLIT_COLUMN_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_SPLIT_COLUMN(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_C_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAIN_NOTE_LIGHT_C(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAIN_NOTE_LIGHT_C_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_D_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAIN_NOTE_LIGHT_D(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAIN_NOTE_LIGHT_D_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_E_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAIN_NOTE_LIGHT_E(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_F_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAIN_NOTE_LIGHT_F(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAIN_NOTE_LIGHT_F_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_G_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAIN_NOTE_LIGHT_G(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAIN_NOTE_LIGHT_G_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_A_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAIN_NOTE_LIGHT_A(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAIN_NOTE_LIGHT_A_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_B_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAIN_NOTE_LIGHT_B(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_C_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACCENT_NOTE_LIGHT_C(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_D_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACCENT_NOTE_LIGHT_D(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_E_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACCENT_NOTE_LIGHT_E(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_F_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACCENT_NOTE_LIGHT_F(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_G_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACCENT_NOTE_LIGHT_G(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_A_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACCENT_NOTE_LIGHT_A(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_B_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACCENT_NOTE_LIGHT_B(NRPNValueIn);
	}
	break;

	case GLOBAL_ROW_OFFSET_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ROW_OFFSET(NRPNValueIn);
	}
	break;

	case SWITCH1_ASSIGN_NRPN:
	{
		m_SwitchSettings.SetSWITCH1_ASSIGN(NRPNValueIn);
	}
	break;

	case SWITCH2_ASSIGN_NRPN:
	{
		m_SwitchSettings.SetSWITCH2_ASSIGN(NRPNValueIn);
	}
	break;

	case FOOT_LEFT_ASSIGN_NRPN:
	{
		m_SwitchSettings.SetFOOT_LEFT_ASSIGN(NRPNValueIn);
	}
	break;

	case FOOT_RIGHT_ASSIGN_NRPN:
	{
		m_SwitchSettings.SetFOOT_RIGHT_ASSIGN(NRPNValueIn);
	}
	break;

	case GLOBAL_VELOCITY_SENSITIVITY_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_VELOCITY_SENSITIVITY(NRPNValueIn);
	}
	break;

	case GLOBAL_PRESSURE_SENSITIVITY_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_PRESSURE_SENSITIVITY(NRPNValueIn);
	}
	break;

	case GLOBAL_MIDI_DEVICE_IO_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MIDI_DEVICE_IO(NRPNValueIn);
	}
	break;

	case GLOBAL_ARP_DIRECTION_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ARP_DIRECTION(NRPNValueIn);
	}
	break;

	case GLOBAL_ARP_TEMPO_NOTE_VALUE_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ARP_TEMPO_NOTE_VALUE(NRPNValueIn);
	}
	break;

	case GLOBAL_ARP_OCTAVE_EXTENSION_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ARP_OCTAVE_EXTENSION(NRPNValueIn);
	}
	break;

	case GLOBAL_CLOCK_BPM_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_CLOCK_BPM(NRPNValueIn);
	}
	break;

	case SWITCH1_BOTH_SPLITS_NRPN:
	{
		m_SwitchSettings.SetSWITCH1_BOTH_SPLITS(NRPNValueIn);
	}
	break;

	case SWITCH2_BOTH_SPLITS_NRPN:
	{
		m_SwitchSettings.SetSWITCH2_BOTH_SPLITS(NRPNValueIn);
	}
	break;

	case FOOT_LEFT_BOTH_SPLITS_NRPN:
	{
		m_SwitchSettings.SetFOOT_LEFT_BOTH_SPLITS(NRPNValueIn);
	}
	break;

	case FOOT_RIGHT_BOTH_SPLITS_NRPN:
	{
		m_SwitchSettings.SetFOOT_RIGHT_BOTH_SPLITS(NRPNValueIn);
	}
	break;

	case GLOBAL_SETTINGS_PRESET_LOAD_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_SETTINGS_PRESET_LOAD(NRPNValueIn);
	}
	break;

	case GLOBAL_PRESSURE_AFTERTOUCH_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_PRESSURE_AFTERTOUCH(NRPNValueIn);
	}
	break;

	case DEVICE_USER_FIRMWARE_MODE_NRPN:
	{
		m_GlobalSettings.SetDEVICE_USER_FIRMWARE_MODE(NRPNValueIn);
	}
	break;

	case DEVICE_LEFT_HANDED_NRPN:
	{
		m_GlobalSettings.SetDEVICE_LEFT_HANDED(NRPNValueIn);
	}
	break;

	case GLOBAL_ACTIVE_LIGHTS_PRESET_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_ACTIVE_LIGHTS_PRESET(NRPNValueIn);
	}
	break;

	// case GLOABAL_CC_FOR_CC65: // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
	// {
//
	// }
// 	break;

	case GLOBAL_MIN_VELOCITY_VALUE_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MIN_VELOCITY_VALUE(NRPNValueIn);
	}
	break;

	case GLOBAL_MAX_VELOCITY_VALUE_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_MAX_VELOCITY_VALUE(NRPNValueIn);
	}
	break;

	case GLOBAL_FIXED_VELOCITY_VALUE_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_FIXED_VELOCITY_VALUE(NRPNValueIn);
	}
	break;

	case DEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN:
	{
		m_GlobalSettings.SetDEVICE_MIN_BYTE_INTERVAL_VALUE(NRPNValueIn);
	}
	break;

	case GLOBAL_CUSTOM_ROW_OFFSET_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_CUSTOM_ROW_OFFSET(NRPNValueIn);
	}
	break;

	case DEVICE_MIDI_THRU_NRPN:
	{
		m_GlobalSettings.SetDEVICE_MIDI_THRU(NRPNValueIn);
	}
	break;

	case CC_FOR_LEFT_FOOT_CC65:
	{
		m_SwitchSettings.SetCC_FOR_LEFT_FOOT_CC65(NRPNValueIn);
	}
	break;

	case CC_FOR_RIGHT_FOOT_CC65:
	{
		m_SwitchSettings.SetCC_FOR_RIGHT_FOOT_CC65(NRPNValueIn);
	}
	break;

	case CC_FOR_SWITCH1_CC65:
	{
		m_SwitchSettings.SetCC_FOR_SWITCH1_CC65(NRPNValueIn);
	}
	break;

	case CC_FOR_SWITCH2_CC65:
	{
		m_SwitchSettings.SetCC_FOR_SWITCH2_CC65(NRPNValueIn);
	}
	break;

	case CC_FOR_LEFT_FOOT_SUSTAIN:
	{
		m_SwitchSettings.SetCC_FOR_LEFT_FOOT_SUSTAIN(NRPNValueIn);
	}
	break;

	case CC_FOR_RIGHT_FOOT_SUSTAIN:
	{
		m_SwitchSettings.SetCC_FOR_RIGHT_FOOT_SUSTAIN(NRPNValueIn);
	}
	break;

	case CC_FOR_SWITCH1_SUSTAIN:
	{
		m_SwitchSettings.SetCC_FOR_SWITCH1_SUSTAIN(NRPNValueIn);
	}
	break;

	case CC_FOR_SWITCH2_SUSTAIN:
	{
		m_SwitchSettings.SetCC_FOR_SWITCH2_SUSTAIN(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW1_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_GUITAR_NOTE_TUNING_ROW1(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW2_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_GUITAR_NOTE_TUNING_ROW2(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW3_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_GUITAR_NOTE_TUNING_ROW3(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW4_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_GUITAR_NOTE_TUNING_ROW4(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW5_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_GUITAR_NOTE_TUNING_ROW5(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW6_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_GUITAR_NOTE_TUNING_ROW6(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW7_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_GUITAR_NOTE_TUNING_ROW7(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW8_NRPN:
	{
		m_GlobalSettings.SetGLOBAL_GUITAR_NOTE_TUNING_ROW8(NRPNValueIn);
	}
	break;

	default:
	{}
	break;
		} // end switch
}


void LinnStrument::ProcessMessage(std::vector <unsigned char> myMessage)
{
	unsigned char nCmd = MIDI().ShortMsgCommandNibble(myMessage);

	switch (nCmd)
	{
	case MIDI_CMD_PITCH_WHEEL:
	{
		int x = 1;
	}
	break;

	case MIDI_CMD_NOTE_ON:
	{
		// if (m_SpeakNotes)
		// {
			unsigned char nNoteNumber = MIDI().ShortMsgData1(myMessage);
			std::string strNoteName = MIDI().GetNoteName(nNoteNumber);
			wxMessageBox(strNoteName, "Test");
			// Announce and update status bar
		// }
	}
	break;

	case MIDI_CMD_NOTE_OFF:
	{
		if (m_SpeakNotes)
		{
			unsigned char nNoteNumber = MIDI().ShortMsgData1(myMessage);
						// Update status bar
		}
	}
	break;

	case CC_NRPN_PARAM_MSB:
	{
		m_NRPNParameterIn = MIDI().ShortMsgData2(myMessage) * 128;
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
			m_NRPNParameterIn = m_NRPNQueue.front();
			m_NRPNQueue.pop();
			// We now have enough information to change the value of a member
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
			// We now have enough information to change the value of a member
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


LSSwitchSettings LinnStrument::GetSwitchSettings()
{
	return m_SwitchSettings;
}


void LinnStrument::SetSwitchSettings(LSSwitchSettings SwitchSettings)
{
	m_SwitchSettings = SwitchSettings;
}


LSGlobalSettings LinnStrument::GetGlobalSettings()
{
	return m_GlobalSettings;
}


void LinnStrument::SendNRPN(LSSplitType split, unsigned int NRPNNumber, unsigned int NRPNValue)
{
	SendNRPN(m_PerSplitSettings.GetMIDI_MAIN_CHANNEL(split), NRPNNumber, NRPNValue);
}


void LinnStrument::SendNRPN(unsigned char nChannelNibble, unsigned int NRPNNumber, unsigned int NRPNValue)
{
	std::vector<unsigned char> myMessage;
	unsigned char myCmdNibble = MIDI_CMD_CONTROL_CHANGE;
	unsigned char myStatusByte = (myCmdNibble * 128) + nChannelNibble;
	unsigned char myNRPNParameterMSB, myNRPNParameterLSB;
	unsigned char myNRPNValueMSB, myNRPNValueLSB;

	if (NRPNNumber == REQUEST_VALUE_OF_NRPN)
	{
		// Record the NRPN parameter we're querying
		m_NRPNQueue.push(NRPNValue);
	}

	// Calculate the MSB and LSB values here
	myNRPNParameterMSB = MIDI().GetMSB(NRPNNumber);
	myNRPNParameterLSB = MIDI().GetLSB(NRPNNumber);
	myNRPNValueMSB = MIDI().GetMSB(NRPNValue);
	myNRPNValueLSB = MIDI().GetLSB(NRPNValue);

try
{
	myMessage.push_back(myStatusByte);
	myMessage.push_back(myNRPNParameterMSB);
	myMessage.push_back(myNRPNParameterLSB);
			m_MIDIOut->sendMessage(&myMessage);
}  // end try
catch (RtMidiError &error)
{
	std::string wstrError(error.getMessage());
}

try
{
	myMessage.push_back(myStatusByte);
	myMessage.push_back(myNRPNValueMSB);
	myMessage.push_back(myNRPNValueLSB);
	m_MIDIOut->sendMessage(&myMessage);
}  // end try
catch (RtMidiError &error)
{
	std::string wstrError(error.getMessage());
}

	// Always send the reset or bad things can happen
	try
	{
		myMessage.push_back(myStatusByte);
	myMessage.push_back(RESET_NRPN_CC_MSB);
	myMessage.push_back(127);
	m_MIDIOut->sendMessage(&myMessage);
	}  // end try
	catch (RtMidiError &error)
	{
		std::string wstrError(error.getMessage());
	}

	try
	{
		myMessage.push_back(myStatusByte);
	myMessage.push_back(RESET_NRPN_CC_LSB);
	myMessage.push_back(127);
	m_MIDIOut->sendMessage(&myMessage);
	}  // end try
	catch (RtMidiError &error)
	{
		std::string wstrError(error.getMessage());
	}
}


void LinnStrument::QueryNRPN(unsigned int nParameterNumber)
{
	SendNRPN(m_PerSplitSettings.GetMIDI_MAIN_CHANNEL(LSSplitType::LEFT), REQUEST_VALUE_OF_NRPN, nParameterNumber);
}


void LinnStrument::QueryPerSplitSettings()
{
	// Left-hand split
	QueryNRPN(SPLIT_LEFT_MAIN_MODE_NRPN);
	QueryNRPN(SPLIT_LEFT_MAIN_CHANNEL_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN);
	QueryNRPN(SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN);
	QueryNRPN(SPLIT_LEFT_BEND_RANGE_NRPN);
	QueryNRPN(SPLIT_LEFT_BEND_TOGGLE_NRPN);
	QueryNRPN(SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN);
	QueryNRPN(SPLIT_LEFT_PITCH_QUANTIZE_NRPN);
	QueryNRPN(SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN);
	QueryNRPN(SPLIT_LEFT_SEND_Y_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_Y_NRPN);
	QueryNRPN(SPLIT_LEFT_RELATIVE_Y_NRPN);
	QueryNRPN(SPLIT_LEFT_SEND_Z_NRPN);
	QueryNRPN(SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_Z_NRPN);
	QueryNRPN(SPLIT_LEFT_COLOR_MAIN_NRPN);
	QueryNRPN(SPLIT_LEFT_COLOR_ACCENT_NRPN);
	QueryNRPN(SPLIT_LEFT_COLOR_PLAYED_NRPN);
	QueryNRPN(SPLIT_LEFT_COLOR_LOWROW_NRPN);
	QueryNRPN(SPLIT_LEFT_LOWROW_MODE_NRPN);
	QueryNRPN(SPLIT_LEFT_SPECIAL_NRPN);
	QueryNRPN(SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_FADER1_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_FADER2_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_FADER3_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_FADER4_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_FADER5_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_FADER6_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_FADER7_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_FADER8_NRPN);
	QueryNRPN(SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_LOWROW_NRPN);
	QueryNRPN(SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN);
	QueryNRPN(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN);
	QueryNRPN(SPLIT_LEFT_MIN_CC_FOR_Y_NRPN);
	QueryNRPN(SPLIT_LEFT_MAX_CC_FOR_Y_NRPN);
	QueryNRPN(SPLIT_LEFT_MIN_CC_FOR_Z_NRPN);
	QueryNRPN(SPLIT_LEFT_MAX_CC_FOR_Z_NRPN);
	QueryNRPN(SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN);
	QueryNRPN(SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN);
	QueryNRPN(SPLIT_LEFT_CHANNEL_PER_ROW_ORDER_NRPN);
	QueryNRPN(SPLIT_LEFT_TOUCH_ANIMATION_NRPN);
	QueryNRPN(SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN);
	QueryNRPN(SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN);
	QueryNRPN(SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN);
	QueryNRPN(SPLIT_LEFT_SEQUENCER_PATTERN_NRPN);
	QueryNRPN(SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN);

	// Right-hand split
	QueryNRPN(SPLIT_RIGHT_MAIN_MODE_NRPN);
	QueryNRPN(SPLIT_RIGHT_MAIN_CHANNEL_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN);
	QueryNRPN(SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN);
	QueryNRPN(SPLIT_RIGHT_BEND_RANGE_NRPN);
	QueryNRPN(SPLIT_RIGHT_BEND_TOGGLE_NRPN);
	QueryNRPN(SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN);
	QueryNRPN(SPLIT_RIGHT_PITCH_QUANTIZE_NRPN);
	QueryNRPN(SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN);
	QueryNRPN(SPLIT_RIGHT_SEND_Y_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_Y_NRPN);
	QueryNRPN(SPLIT_RIGHT_RELATIVE_Y_NRPN);
	QueryNRPN(SPLIT_RIGHT_SEND_Z_NRPN);
	QueryNRPN(SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_Z_NRPN);
	QueryNRPN(SPLIT_RIGHT_COLOR_MAIN_NRPN);
	QueryNRPN(SPLIT_RIGHT_COLOR_ACCENT_NRPN);
	QueryNRPN(SPLIT_RIGHT_COLOR_PLAYED_NRPN);
	QueryNRPN(SPLIT_RIGHT_COLOR_LOWROW_NRPN);
	QueryNRPN(SPLIT_RIGHT_LOWROW_MODE_NRPN);
	QueryNRPN(SPLIT_RIGHT_SPECIAL_NRPN);
	QueryNRPN(SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN);
		QueryNRPN(SPLIT_RIGHT_CC_FOR_FADER1_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_FADER2_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_FADER3_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_FADER4_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_FADER5_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_FADER6_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_FADER7_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_FADER8_NRPN);
	QueryNRPN(SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_NRPN);
	QueryNRPN(SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN);
	QueryNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN);
	QueryNRPN(SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN);
	QueryNRPN(SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN);
	QueryNRPN(SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN);
	QueryNRPN(SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN);
	QueryNRPN(SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN);
	QueryNRPN(SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN);
	QueryNRPN(SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER_NRPN);
	QueryNRPN(SPLIT_RIGHT_TOUCH_ANIMATION_NRPN);
	QueryNRPN(SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN);
	QueryNRPN(SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN);
	QueryNRPN(SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN);
	QueryNRPN(SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN);
	QueryNRPN(SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN);
}

void LinnStrument::QueryGlobalSettings()
{
	QueryNRPN(GLOBAL_SPLIT_ACTIVE_NRPN);
	QueryNRPN(GLOBAL_SELECTED_SPLIT_NRPN);
	QueryNRPN(GLOBAL_SPLIT_COLUMN_NRPN);
	QueryNRPN(GLOBAL_MAIN_NOTE_LIGHT_C_NRPN);
	QueryNRPN(GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_NRPN);
	QueryNRPN(GLOBAL_MAIN_NOTE_LIGHT_D_NRPN);
	QueryNRPN(GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_NRPN);
	QueryNRPN(GLOBAL_MAIN_NOTE_LIGHT_E_NRPN);
	QueryNRPN(GLOBAL_MAIN_NOTE_LIGHT_F_NRPN);
	QueryNRPN(GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_NRPN);
	QueryNRPN(GLOBAL_MAIN_NOTE_LIGHT_G_NRPN);
	QueryNRPN(GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_NRPN);
	QueryNRPN(GLOBAL_MAIN_NOTE_LIGHT_A_NRPN);
	QueryNRPN(GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_NRPN);
	QueryNRPN(GLOBAL_MAIN_NOTE_LIGHT_B_NRPN);
	QueryNRPN(GLOBAL_ACCENT_NOTE_LIGHT_C_NRPN);
	QueryNRPN(GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_NRPN);
	QueryNRPN(GLOBAL_ACCENT_NOTE_LIGHT_D_NRPN);
	QueryNRPN(GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_NRPN);
	QueryNRPN(GLOBAL_ACCENT_NOTE_LIGHT_E_NRPN);
	QueryNRPN(GLOBAL_ACCENT_NOTE_LIGHT_F_NRPN);
	QueryNRPN(GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_NRPN);
	QueryNRPN(GLOBAL_ACCENT_NOTE_LIGHT_G_NRPN);
	QueryNRPN(GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_NRPN);
	QueryNRPN(GLOBAL_ACCENT_NOTE_LIGHT_A_NRPN);
	QueryNRPN(GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_NRPN);
	QueryNRPN(GLOBAL_ACCENT_NOTE_LIGHT_B_NRPN);
	QueryNRPN(GLOBAL_ROW_OFFSET_NRPN);
	QueryNRPN(GLOBAL_VELOCITY_SENSITIVITY_NRPN);
	QueryNRPN(GLOBAL_PRESSURE_SENSITIVITY_NRPN);
	QueryNRPN(GLOBAL_MIDI_DEVICE_IO_NRPN);
	QueryNRPN(GLOBAL_ARP_DIRECTION_NRPN);
	QueryNRPN(GLOBAL_ARP_TEMPO_NOTE_VALUE_NRPN);
	QueryNRPN(GLOBAL_ARP_OCTAVE_EXTENSION_NRPN);
	QueryNRPN(GLOBAL_CLOCK_BPM_NRPN);
	QueryNRPN(GLOBAL_SETTINGS_PRESET_LOAD_NRPN);
	QueryNRPN(GLOBAL_PRESSURE_AFTERTOUCH_NRPN);
	QueryNRPN(DEVICE_USER_FIRMWARE_MODE_NRPN);
	QueryNRPN(DEVICE_LEFT_HANDED_NRPN);
	QueryNRPN(GLOBAL_ACTIVE_LIGHTS_PRESET_NRPN);
	QueryNRPN(GLOBAL_MIN_VELOCITY_VALUE_NRPN);
	QueryNRPN(GLOBAL_MAX_VELOCITY_VALUE_NRPN);
	QueryNRPN(GLOBAL_FIXED_VELOCITY_VALUE_NRPN);
	QueryNRPN(DEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN);
	QueryNRPN(GLOBAL_CUSTOM_ROW_OFFSET_NRPN);
	QueryNRPN(DEVICE_MIDI_THRU_NRPN);
	QueryNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW1_NRPN);
	QueryNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW2_NRPN);
	QueryNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW3_NRPN);
	QueryNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW4_NRPN);
	QueryNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW5_NRPN);
	QueryNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW6_NRPN);
	QueryNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW7_NRPN);
	QueryNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW8_NRPN);
}


void LinnStrument::QueryOctaveTransposeSettings()
{
	QueryNRPN(SPLIT_LEFT_OCTAVE_NRPN);
	QueryNRPN(SPLIT_LEFT_PITCH_TRANSPOSE_NRPN);
	QueryNRPN(SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN);
	QueryNRPN(SPLIT_RIGHT_OCTAVE_NRPN);
	QueryNRPN(SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN);
	QueryNRPN(SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN);
}


void LinnStrument::QuerySwitchSettings()
{
	QueryNRPN(SWITCH1_ASSIGN_NRPN);
	QueryNRPN(SWITCH2_ASSIGN_NRPN);
	QueryNRPN(FOOT_LEFT_ASSIGN_NRPN);
	QueryNRPN(FOOT_RIGHT_ASSIGN_NRPN);
	QueryNRPN(SWITCH1_BOTH_SPLITS_NRPN);
	QueryNRPN(SWITCH2_BOTH_SPLITS_NRPN);
	QueryNRPN(FOOT_LEFT_BOTH_SPLITS_NRPN);
	QueryNRPN(FOOT_RIGHT_BOTH_SPLITS_NRPN);
	// QueryNRPN( CC_FOR_CC65);  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
	QueryNRPN(CC_FOR_LEFT_FOOT_CC65);
	QueryNRPN(CC_FOR_RIGHT_FOOT_CC65);
	QueryNRPN(CC_FOR_SWITCH1_CC65);
	QueryNRPN(CC_FOR_SWITCH2_CC65);
	QueryNRPN(CC_FOR_LEFT_FOOT_SUSTAIN);
	QueryNRPN(CC_FOR_RIGHT_FOOT_SUSTAIN);
	QueryNRPN(CC_FOR_SWITCH1_SUSTAIN);
	QueryNRPN(CC_FOR_SWITCH2_SUSTAIN);
}


void LinnStrument::QueryAll()
{
	QueryPerSplitSettings();
	QueryGlobalSettings();
	QuerySwitchSettings();
	QueryOctaveTransposeSettings();
}

