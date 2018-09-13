// LinnStrument.cpp

#include "stdafx.h"
#include "LinnStrument.h"

wxDEFINE_EVENT(NoteEvent, wxCommandEvent);


std::wstring widen(const std::string& s)
{
std::vector<wchar_t> buf(MultiByteToWideChar(CP_ACP, 0, s.c_str(), s.size() + 1, 0, 0));
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), s.size() + 1, &buf[0], buf.size());
		return std::wstring(&buf[0]);
	}


void SendCC(unsigned char CCNumber, unsigned char CCValue)
{

}


void LSCallback(double deltatime, std::vector< unsigned char > *message, void *pLinnStrument)
{
	LinnStrument * pMyLinnStrument = (LinnStrument*)pLinnStrument;
	pMyLinnStrument->ProcessMessage(*message);
}

	LinnStrument::LinnStrument():
		m_Parent(NULL),
		m_InputID(-1),
		m_OutputID(-1),
		m_SpeakMessages(false),
		m_SpeakNotes(false),
		m_ReceivedNRPNValueMSB(false),
		m_ReceivedNRPNValueLSB(false),
		m_Waiting(false),
		m_Sent(0),
		m_Received(0),
		m_CanDetectSerialPorts(true)
	{
		// Initialise note tracking
		for (unsigned int i = 0; i < MAX_BYTE_VALUES; i++)
		{
			m_NotesHeld[i] = false;
		}

		// Initialise COM
		HRESULT hr = CoInitialize(NULL);

		// Declare the smart pointer for speech output.
		// Use its member function CoCreateInstance to
	// create the COM object and obtain the ISpVoice pointer.
		hr = pSpeech.CoCreateInstance(CLSID_SpVoice);
		if (FAILED(hr))
		{			}

		//Initialize COM security (Required by CEnumerateSerial::UsingWMI)
		hr = CoInitializeSecurity(nullptr, -1, nullptr, nullptr, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE, nullptr);
		if (FAILED(hr))
		{
			m_CanDetectSerialPorts = false;
		}

		m_MIDIIn = new RtMidiIn();
		m_MIDIOut = new RtMidiOut();
			   }


LinnStrument::LinnStrument(wxWindow * parent, int nInputID, int nOutputID, bool blnSpeakMessages, bool blnSpeakNotes) :
	m_Parent(parent),
	m_InputID(nInputID),
	m_OutputID(nOutputID),
	m_SpeakMessages(blnSpeakMessages),
	m_SpeakNotes(blnSpeakNotes),
	m_ReceivedNRPNValueMSB(false),
	m_ReceivedNRPNValueLSB(false),
	m_Waiting(false),
	m_Sent(0),
	m_Received(0),
	m_CanDetectSerialPorts( true)
{
	// Initialise note tracking
	for (unsigned int i= 0; i < MAX_BYTE_VALUES; i++)
	{
		m_NotesHeld[i] = false;
	}
	
	// Initialise COM
	HRESULT hr = CoInitialize(NULL);
	
	// Declare the smart pointer for speech output.
	// Use its member function CoCreateInstance to
// create the COM object and obtain the ISpVoice pointer.
	hr = pSpeech.CoCreateInstance(CLSID_SpVoice);
	if (FAILED(hr))
	{
		// m_SpeakMessages = false;
				// m_SpeakNotes = false;
	}

	//Initialize COM security (Required by CEnumerateSerial::UsingWMI)
	hr = CoInitializeSecurity(nullptr, -1, nullptr, nullptr, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE, nullptr);
	if (FAILED(hr))
	{
		m_CanDetectSerialPorts = false;
					}
	
			m_MIDIIn = new RtMidiIn();
	m_MIDIOut = new RtMidiOut();

	if ((m_MIDIIn->getPortCount() == 0) || (m_MIDIOut->getPortCount() == 0))
	{
		m_InputID = -1;
		m_OutputID = -1;
	}
	else
	{
		int nUSBInID = GetUSBInPortID();
		int nUSBOutID = GetUSBOutPortID();

		if ((nUSBInID != -1) && (nUSBOutID != -1))
		{
			// USB connection detected, so ignore any saved port ID values and override
			m_GLOBAL_MIDI_DEVICE_IO = GetLS_MIDIDeviceIndex(LS_MIDIDevice::USB);
			m_InputID = nUSBInID;
			m_OutputID = nUSBOutID;
		}

		if ((m_InputID == -1) || (m_OutputID == -1))
		{
			// No USB connection detected and no MIDI I/O ports saved, so get user to specify DIN connections
			MIDIDialog * pMIDIDialog = new MIDIDialog(L"LinnStrument MIDI I/O jacks");
			if (pMIDIDialog->ShowModal() == wxID_OK)
			{
				m_OutputID = pMIDIDialog->GetSelectedOutput();
				m_InputID = pMIDIDialog->GetSelectedInput();
				m_GLOBAL_MIDI_DEVICE_IO = GetLS_MIDIDeviceIndex(LS_MIDIDevice::USB);
			}  // End of manual DIN selection
		}

		// Now we have valid port ID values, so open the ports and initialise parameter values
		if ((m_OutputID != -1) && (m_InputID != -1))
		{
			m_MIDIOut->openPort(m_OutputID);
			m_MIDIIn->openPort(m_InputID);
			m_MIDIIn->setCallback(&LSCallback, (void*)this);
			QueryLeftChannel();
			QueryRightChannel();
			m_Sent = 0;
			m_Received = 0;
			QueryAll();
		}  // end if DIN ports selected
	}  // end if 0 input and output ports
	
		if ((m_SpeakMessages)
			&& (m_InputID == -1)
			&& (m_OutputID == -1))
		{
			Speak(L"LinnStrument not connected");
			}
	}

	
LinnStrument::~LinnStrument()
{
		if (m_MIDIIn->isPortOpen())
		{
			m_MIDIIn->cancelCallback();
			m_MIDIIn->closePort();
		}

		if (m_MIDIOut->isPortOpen())
		{
			m_MIDIOut->closePort();
		}

		// Dereference the callback and tidy up
		m_MIDIIn->setCallback(NULL);
		delete m_MIDIIn;
		delete m_MIDIOut;
	
		// Tidy up SAPI
// 		pVoice->Release();
//pVoice = NULL;
// Tidy up COM
				CoUninitialize();
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
	DBOUT( L"Parameter = " + std::to_wstring(NRPNParameterIn) + L"\n")
			DBOUT( L"Value = " + std::to_wstring(NRPNValueIn) + L"\n")

		// Update the appropriate member based on the provided NRPN parameter number
			switch (NRPNParameterIn)
	{
		// Per-split parameters

// Left-hand split
	case SPLIT_LEFT_MAIN_MODE_NRPN:
	{
					SetSPLIT_MODE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MAIN_CHANNEL_NRPN:
	{
		SetMIDI_MAIN_CHANNEL(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN:
	{
		SetCHANNEL_PER_NOTE_1(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN:
	{
		SetCHANNEL_PER_NOTE_2(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN:
	{
		SetCHANNEL_PER_NOTE_3(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN:
	{
		SetCHANNEL_PER_NOTE_4(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN:
	{
		SetCHANNEL_PER_NOTE_5(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN:
	{
		SetCHANNEL_PER_NOTE_6(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN:
	{
		SetCHANNEL_PER_NOTE_7(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN:
	{
		SetCHANNEL_PER_NOTE_8(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN:
	{
		SetCHANNEL_PER_NOTE_9(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN:
	{
		SetCHANNEL_PER_NOTE_10(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN:
	{
		SetCHANNEL_PER_NOTE_11(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN:
	{
		SetCHANNEL_PER_NOTE_12(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN:
	{
		SetCHANNEL_PER_NOTE_13(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN:
	{
		SetCHANNEL_PER_NOTE_14(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN:
	{
		SetCHANNEL_PER_NOTE_15(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN:
	{
		SetCHANNEL_PER_NOTE_16(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN:
	{
		SetMIDI_PER_ROW_LOWEST_CHANNEL(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_BEND_RANGE_NRPN:
	{
		SetBEND_RANGE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_BEND_TOGGLE_NRPN:
	{
		SetBEND_TOGGLE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN:
	{
		SetBEND_QUANTIZE_TOGGLE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_PITCH_QUANTIZE_NRPN:
	{
		SetBEND_QUANTIZE_TOGGLE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN:
	{
		SetRESET_PITCH_ON_RELEASE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEND_Y_NRPN:
	{
		SetSEND_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_Y_NRPN:
	{
		SetCC_FOR_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_RELATIVE_Y_NRPN:
	{
		SetRELATIVE_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEND_Z_NRPN:
	{
		SetSEND_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN:
	{
		SetMIDI_EXPRESSION_FOR_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_Z_NRPN:
	{
		SetCC_FOR_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_COLOR_MAIN_NRPN:
	{
		SetCOLOR_MAIN(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_COLOR_ACCENT_NRPN:
	{
		SetCOLOR_ACCENT(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_COLOR_PLAYED_NRPN:
	{
		SetCOLOR_PLAYED(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_COLOR_LOWROW_NRPN:
	{
		SetCOLOR_LOWROW(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_LOWROW_MODE_NRPN:
	{
		SetLOWROW_MODE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SPECIAL_NRPN:
	{
		SetSPECIAL(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_OCTAVE_NRPN:
	{
		SetOCTAVE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_PITCH_TRANSPOSE_NRPN:
	{
		SetPITCH_TRANSPOSE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN:
	{
		SetTRANSPOSE_LIGHTS(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN:
	{
		SetEXPRESSION_FOR_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER1_NRPN:
	{
		SetCC_FOR_FADER1(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER2_NRPN:
	{
		SetCC_FOR_FADER2(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER3_NRPN:
	{
		SetCC_FOR_FADER3(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER4_NRPN:
	{
		SetCC_FOR_FADER4(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER5_NRPN:
	{
		SetCC_FOR_FADER5(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER6_NRPN:
	{
		SetCC_FOR_FADER6(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER7_NRPN:
	{
		SetCC_FOR_FADER7(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_FADER8_NRPN:
	{
		SetCC_FOR_FADER8(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN:
	{
		SetLOWROW_X_BEHAVIOUR(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_LOWROW_NRPN:
	{
		SetCC_FOR_LOWROW(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN:
	{
		SetLOWROW_XYZ_BEHAVIOUR(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN:
	{
		SetCC_FOR_LOWROW_XYZ(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN:
	{
		SetCC_FOR_LOWROW_XYZ_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN:
	{
		SetCC_FOR_LOWROW_XYZ_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MIN_CC_FOR_Y_NRPN:
	{
		SetMIN_CC_FOR_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MAX_CC_FOR_Y_NRPN:
	{
		SetMAX_CC_FOR_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MIN_CC_FOR_Z_NRPN:
	{
		SetMIN_CC_FOR_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_MAX_CC_FOR_Z_NRPN:
	{
		SetMAX_CC_FOR_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN:
	{
		Set14BIT_CC_VALUE_FOR_Z(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN:
	{
		SetINITIAL_RELATIVE_VALUE_FOR_Y(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_CHANNEL_PER_ROW_ORDER_NRPN:
	{
		SetCHANNEL_PER_ROW_ORDER(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_TOUCH_ANIMATION_NRPN:
	{
		SetTOUCH_ANIMATION(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN:
	{
		SetSEQUENCER_TOGGLE_PLAY(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN:
	{
		SetSEQUENCER_PREVIOUS_PATTERN(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN:
	{
		SetSEQUENCER_NEXT_PATTERN(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEQUENCER_PATTERN_NRPN:
	{
		SetSEQUENCER_PATTERN(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	case SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN:
	{
		SetSEQUENCER_TOGGLE_MUTE(NRPNValueIn, LSSplitType::LEFT);
	}
	break;

	// Right-hand split

			case SPLIT_RIGHT_MAIN_MODE_NRPN:
	{
					SetSPLIT_MODE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MAIN_CHANNEL_NRPN:
	{
		SetMIDI_MAIN_CHANNEL(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN:
	{
		SetCHANNEL_PER_NOTE_1(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN:
	{
		SetCHANNEL_PER_NOTE_2(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN:
	{
		SetCHANNEL_PER_NOTE_3(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN:
	{
		SetCHANNEL_PER_NOTE_4(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN:
	{
		SetCHANNEL_PER_NOTE_5(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN:
	{
		SetCHANNEL_PER_NOTE_6(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN:
	{
		SetCHANNEL_PER_NOTE_7(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN:
	{
		SetCHANNEL_PER_NOTE_8(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN:
	{
		SetCHANNEL_PER_NOTE_9(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN:
	{
		SetCHANNEL_PER_NOTE_10(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN:
	{
		SetCHANNEL_PER_NOTE_11(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN:
	{
		SetCHANNEL_PER_NOTE_12(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN:
	{
		SetCHANNEL_PER_NOTE_13(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN:
	{
		SetCHANNEL_PER_NOTE_14(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN:
	{
		SetCHANNEL_PER_NOTE_15(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN:
	{
		SetCHANNEL_PER_NOTE_16(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN:
	{
		SetMIDI_PER_ROW_LOWEST_CHANNEL(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_BEND_RANGE_NRPN:
	{
		SetBEND_RANGE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_BEND_TOGGLE_NRPN:
	{
		SetBEND_TOGGLE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN:
	{
		SetBEND_QUANTIZE_TOGGLE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_PITCH_QUANTIZE_NRPN:
	{
		SetBEND_QUANTIZE_TOGGLE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN:
	{
		SetRESET_PITCH_ON_RELEASE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEND_Y_NRPN:
	{
		SetSEND_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_Y_NRPN:
	{
		SetCC_FOR_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_RELATIVE_Y_NRPN:
	{
		SetRELATIVE_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEND_Z_NRPN:
	{
		SetSEND_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN:
	{
		SetMIDI_EXPRESSION_FOR_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_Z_NRPN:
	{
		SetCC_FOR_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_COLOR_MAIN_NRPN:
	{
		SetCOLOR_MAIN(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_COLOR_ACCENT_NRPN:
	{
		SetCOLOR_ACCENT(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_COLOR_PLAYED_NRPN:
	{
		SetCOLOR_PLAYED(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_COLOR_LOWROW_NRPN:
	{
		SetCOLOR_LOWROW(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_LOWROW_MODE_NRPN:
	{
		SetLOWROW_MODE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SPECIAL_NRPN:
	{
		SetSPECIAL(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_OCTAVE_NRPN:
	{
		SetOCTAVE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN:
	{
		SetPITCH_TRANSPOSE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN:
	{
		SetTRANSPOSE_LIGHTS(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN:
	{
		SetEXPRESSION_FOR_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER1_NRPN:
	{
		SetCC_FOR_FADER1(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER2_NRPN:
	{
		SetCC_FOR_FADER2(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER3_NRPN:
	{
		SetCC_FOR_FADER3(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER4_NRPN:
	{
		SetCC_FOR_FADER4(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER5_NRPN:
	{
		SetCC_FOR_FADER5(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER6_NRPN:
	{
		SetCC_FOR_FADER6(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER7_NRPN:
	{
		SetCC_FOR_FADER7(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_FADER8_NRPN:
	{
		SetCC_FOR_FADER8(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN:
	{
		SetLOWROW_X_BEHAVIOUR(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_LOWROW_NRPN:
	{
		SetCC_FOR_LOWROW(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN:
	{
		SetLOWROW_XYZ_BEHAVIOUR(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN:
	{
		SetCC_FOR_LOWROW_XYZ(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN:
	{
		SetCC_FOR_LOWROW_XYZ_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN:
	{
		SetCC_FOR_LOWROW_XYZ_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN:
	{
		SetMIN_CC_FOR_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN:
	{
		SetMAX_CC_FOR_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN:
	{
		SetMIN_CC_FOR_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN:
	{
		SetMAX_CC_FOR_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN:
	{
		Set14BIT_CC_VALUE_FOR_Z(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN:
	{
		SetINITIAL_RELATIVE_VALUE_FOR_Y(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER_NRPN:
	{
		SetCHANNEL_PER_ROW_ORDER(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_TOUCH_ANIMATION_NRPN:
	{
		SetTOUCH_ANIMATION(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN:
	{
		SetSEQUENCER_TOGGLE_PLAY(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN:
	{
		SetSEQUENCER_PREVIOUS_PATTERN(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN:
	{
		SetSEQUENCER_NEXT_PATTERN(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN:
	{
		SetSEQUENCER_PATTERN(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	case SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN:
	{
		SetSEQUENCER_TOGGLE_MUTE(NRPNValueIn, LSSplitType::RIGHT);
	}
	break;

	// Global parameters

	case GLOBAL_SPLIT_ACTIVE_NRPN:
	{
		SetGLOBAL_SPLIT_ACTIVE(NRPNValueIn);
	}
	break;

	case GLOBAL_SELECTED_SPLIT_NRPN:
	{
		SetGLOBAL_SELECTED_SPLIT(NRPNValueIn);
	}
	break;

	case GLOBAL_SPLIT_COLUMN_NRPN:
	{
		SetGLOBAL_SPLIT_COLUMN(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_C_NRPN:
	{
		SetGLOBAL_MAIN_NOTE_LIGHT_C(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_NRPN:
	{
		SetGLOBAL_MAIN_NOTE_LIGHT_C_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_D_NRPN:
	{
		SetGLOBAL_MAIN_NOTE_LIGHT_D(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_NRPN:
	{
		SetGLOBAL_MAIN_NOTE_LIGHT_D_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_E_NRPN:
	{
		SetGLOBAL_MAIN_NOTE_LIGHT_E(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_F_NRPN:
	{
		SetGLOBAL_MAIN_NOTE_LIGHT_F(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_NRPN:
	{
		SetGLOBAL_MAIN_NOTE_LIGHT_F_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_G_NRPN:
	{
		SetGLOBAL_MAIN_NOTE_LIGHT_G(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_NRPN:
	{
		SetGLOBAL_MAIN_NOTE_LIGHT_G_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_A_NRPN:
	{
		SetGLOBAL_MAIN_NOTE_LIGHT_A(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_NRPN:
	{
		SetGLOBAL_MAIN_NOTE_LIGHT_A_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_MAIN_NOTE_LIGHT_B_NRPN:
	{
		SetGLOBAL_MAIN_NOTE_LIGHT_B(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_C_NRPN:
	{
		SetGLOBAL_ACCENT_NOTE_LIGHT_C(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_NRPN:
	{
		SetGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_D_NRPN:
	{
		SetGLOBAL_ACCENT_NOTE_LIGHT_D(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_NRPN:
	{
		SetGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_E_NRPN:
	{
		SetGLOBAL_ACCENT_NOTE_LIGHT_E(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_F_NRPN:
	{
		SetGLOBAL_ACCENT_NOTE_LIGHT_F(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_NRPN:
	{
		SetGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_G_NRPN:
	{
		SetGLOBAL_ACCENT_NOTE_LIGHT_G(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_NRPN:
	{
		SetGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_A_NRPN:
	{
		SetGLOBAL_ACCENT_NOTE_LIGHT_A(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_NRPN:
	{
		SetGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP(NRPNValueIn);
	}
	break;

	case GLOBAL_ACCENT_NOTE_LIGHT_B_NRPN:
	{
		SetGLOBAL_ACCENT_NOTE_LIGHT_B(NRPNValueIn);
	}
	break;

	case GLOBAL_ROW_OFFSET_NRPN:
	{
		SetGLOBAL_ROW_OFFSET(NRPNValueIn);
	}
	break;

	case SWITCH1_ASSIGN_NRPN:
	{
		SetSWITCH1_ASSIGN(NRPNValueIn);
	}
	break;

	case SWITCH2_ASSIGN_NRPN:
	{
		SetSWITCH2_ASSIGN(NRPNValueIn);
	}
	break;

	case FOOT_LEFT_ASSIGN_NRPN:
	{
		SetFOOT_LEFT_ASSIGN(NRPNValueIn);
	}
	break;

	case FOOT_RIGHT_ASSIGN_NRPN:
	{
		SetFOOT_RIGHT_ASSIGN(NRPNValueIn);
	}
	break;

	case GLOBAL_VELOCITY_SENSITIVITY_NRPN:
	{
		SetGLOBAL_VELOCITY_SENSITIVITY(NRPNValueIn);
	}
	break;

	case GLOBAL_PRESSURE_SENSITIVITY_NRPN:
	{
		SetGLOBAL_PRESSURE_SENSITIVITY(NRPNValueIn);
	}
	break;

	case GLOBAL_MIDI_DEVICE_IO_NRPN:
	{
		SetGLOBAL_MIDI_DEVICE_IO(NRPNValueIn);
	}
	break;

	case GLOBAL_ARP_DIRECTION_NRPN:
	{
		SetGLOBAL_ARP_DIRECTION(NRPNValueIn);
	}
	break;

	case GLOBAL_ARP_TEMPO_NOTE_VALUE_NRPN:
	{
		SetGLOBAL_ARP_TEMPO_NOTE_VALUE(NRPNValueIn);
	}
	break;

	case GLOBAL_ARP_OCTAVE_EXTENSION_NRPN:
	{
		SetGLOBAL_ARP_OCTAVE_EXTENSION(NRPNValueIn);
	}
	break;

	case GLOBAL_CLOCK_BPM_NRPN:
	{
		SetGLOBAL_CLOCK_BPM(NRPNValueIn);
	}
	break;

	case SWITCH1_BOTH_SPLITS_NRPN:
	{
		SetSWITCH1_BOTH_SPLITS(NRPNValueIn);
	}
	break;

	case SWITCH2_BOTH_SPLITS_NRPN:
	{
		SetSWITCH2_BOTH_SPLITS(NRPNValueIn);
	}
	break;

	case FOOT_LEFT_BOTH_SPLITS_NRPN:
	{
		SetFOOT_LEFT_BOTH_SPLITS(NRPNValueIn);
	}
	break;

	case FOOT_RIGHT_BOTH_SPLITS_NRPN:
	{
		SetFOOT_RIGHT_BOTH_SPLITS(NRPNValueIn);
	}
	break;

	case GLOBAL_SETTINGS_PRESET_LOAD_NRPN:
	{
		SetGLOBAL_SETTINGS_PRESET_LOAD(NRPNValueIn);
	}
	break;

	case GLOBAL_PRESSURE_AFTERTOUCH_NRPN:
	{
		SetGLOBAL_PRESSURE_AFTERTOUCH(NRPNValueIn);
	}
	break;

	case DEVICE_USER_FIRMWARE_MODE_NRPN:
	{
		SetDEVICE_USER_FIRMWARE_MODE(NRPNValueIn);
	}
	break;

	case DEVICE_LEFT_HANDED_NRPN:
	{
		SetDEVICE_LEFT_HANDED(NRPNValueIn);
	}
	break;

	case GLOBAL_ACTIVE_LIGHTS_PRESET_NRPN:
	{
		SetGLOBAL_ACTIVE_LIGHTS_PRESET(NRPNValueIn);
	}
	break;

	// case GLOABAL_CC_FOR_CC65: // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
	// {
//
	// }
// 	break;

	case GLOBAL_MIN_VELOCITY_VALUE_NRPN:
	{
		SetGLOBAL_MIN_VELOCITY_VALUE(NRPNValueIn);
	}
	break;

	case GLOBAL_MAX_VELOCITY_VALUE_NRPN:
	{
		SetGLOBAL_MAX_VELOCITY_VALUE(NRPNValueIn);
	}
	break;

	case GLOBAL_FIXED_VELOCITY_VALUE_NRPN:
	{
		SetGLOBAL_FIXED_VELOCITY_VALUE(NRPNValueIn);
	}
	break;

	case DEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN:
	{
		SetDEVICE_MIN_BYTE_INTERVAL_VALUE(NRPNValueIn);
	}
	break;

	case GLOBAL_CUSTOM_ROW_OFFSET_NRPN:
	{
		SetGLOBAL_CUSTOM_ROW_OFFSET(NRPNValueIn);
	}
	break;

	case DEVICE_MIDI_THRU_NRPN:
	{
		SetDEVICE_MIDI_THRU(NRPNValueIn);
	}
	break;

	case CC_FOR_LEFT_FOOT_CC65:
	{
		SetCC_FOR_LEFT_FOOT_CC65(NRPNValueIn);
	}
	break;

	case CC_FOR_RIGHT_FOOT_CC65:
	{
		SetCC_FOR_RIGHT_FOOT_CC65(NRPNValueIn);
	}
	break;

	case CC_FOR_SWITCH1_CC65:
	{
		SetCC_FOR_SWITCH1_CC65(NRPNValueIn);
	}
	break;

	case CC_FOR_SWITCH2_CC65:
	{
		SetCC_FOR_SWITCH2_CC65(NRPNValueIn);
	}
	break;

	case CC_FOR_LEFT_FOOT_SUSTAIN:
	{
		SetCC_FOR_LEFT_FOOT_SUSTAIN(NRPNValueIn);
	}
	break;

	case CC_FOR_RIGHT_FOOT_SUSTAIN:
	{
		SetCC_FOR_RIGHT_FOOT_SUSTAIN(NRPNValueIn);
	}
	break;

	case CC_FOR_SWITCH1_SUSTAIN:
	{
		SetCC_FOR_SWITCH1_SUSTAIN(NRPNValueIn);
	}
	break;

	case CC_FOR_SWITCH2_SUSTAIN:
	{
		SetCC_FOR_SWITCH2_SUSTAIN(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW1_NRPN:
	{
		SetGLOBAL_GUITAR_NOTE_TUNING_ROW1(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW2_NRPN:
	{
		SetGLOBAL_GUITAR_NOTE_TUNING_ROW2(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW3_NRPN:
	{
		SetGLOBAL_GUITAR_NOTE_TUNING_ROW3(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW4_NRPN:
	{
		SetGLOBAL_GUITAR_NOTE_TUNING_ROW4(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW5_NRPN:
	{
		SetGLOBAL_GUITAR_NOTE_TUNING_ROW5(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW6_NRPN:
	{
		SetGLOBAL_GUITAR_NOTE_TUNING_ROW6(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW7_NRPN:
	{
		SetGLOBAL_GUITAR_NOTE_TUNING_ROW7(NRPNValueIn);
	}
	break;

	case GLOBAL_GUITAR_NOTE_TUNING_ROW8_NRPN:
	{
		SetGLOBAL_GUITAR_NOTE_TUNING_ROW8(NRPNValueIn);
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
	unsigned char nChannel = MIDI().ShortMsgChannelNibble(myMessage);
	unsigned char nData1 = MIDI().ShortMsgData1(myMessage);
	unsigned char nData2 = MIDI().ShortMsgData2(myMessage);
			
	switch (nCmd)
	{
		case MIDI_CMD_NOTE_ON:
		{
			unsigned char nNoteNumber = MIDI().ShortMsgData1(myMessage);
			m_NotesHeld[nNoteNumber] = true;
			
			if (m_SpeakNotes)
			{
				std::wstring wstrNoteName = MIDI().GetWideNoteName(nNoteNumber);
												Speak( wstrNoteName);
												}
			UpdateStatusBar();
		}
		break;

		case MIDI_CMD_NOTE_OFF:
	{
		unsigned char nNoteNumber = MIDI().ShortMsgData1(myMessage);
		m_NotesHeld[nNoteNumber] = false;
		UpdateStatusBar();
	}
	break;

	case MIDI_CMD_CONTROL_CHANGE:
	{
		switch (nData1)
		{
		case SET_NRPN_CC_MSB:
		{
			m_NRPNParameterIn = MIDI().ShortMsgData2(myMessage) * 128;
		}
		break;

		case SET_NRPN_CC_LSB:
		{
			m_NRPNParameterIn = m_NRPNParameterIn + MIDI().ShortMsgData2(myMessage);
		}
		break;

		case CC_NRPN_VALUE_MSB:
		{
			m_ReceivedNRPNValueMSB = true;
			m_NRPNValueIn = MIDI().ShortMsgData2(myMessage) * 127;
		}
		break;

		case CC_NRPN_VALUE_LSB:
		{
			m_ReceivedNRPNValueLSB = true;
			m_NRPNValueIn = m_NRPNValueIn + MIDI().ShortMsgData2(myMessage);
			// We should now have enough information to change the value of a member
			if (m_ReceivedNRPNValueMSB && m_ReceivedNRPNValueLSB)
			{
				SetLSParameter(m_NRPNQueue.front(), m_NRPNValueIn);
				m_NRPNQueue.pop();
				m_Received++;
				m_Waiting = false;
								m_ReceivedNRPNValueMSB = false;
				m_ReceivedNRPNValueLSB = false;
			}
		}
		break;

		case RESET_NRPN_CC_MSB:
		{}
					break;

		case RESET_NRPN_CC_LSB:
		{
			}
		break;

		default:
		{
		}
		break;
		}   // end switch
	}  // end case MIDI_CMD_CONTROL_CHANGE
	break;
	
	default:
	{}
	break;  
}  // end switch
}


bool LinnStrument::GetSpeakMessages()
{
	return m_SpeakMessages;
}

void LinnStrument::SetSpeakMessages(bool blnSpeakMessages)
{
	m_SpeakMessages = blnSpeakMessages;
		}

bool LinnStrument::GetSpeakNotes()
{
	return m_SpeakNotes;
}

void LinnStrument::SetSpeakNotes(bool blnSpeakNotes)
{
	m_SpeakNotes = blnSpeakNotes;
		}

void LinnStrument::SendNRPN( unsigned int NRPNNumber, unsigned int NRPNValue)
{
	SendNRPN(GetMIDI_MAIN_CHANNEL(LSSplitType::LEFT), NRPNNumber, NRPNValue);
}


void LinnStrument::SendNRPN(LSSplitType split, unsigned int NRPNNumber, unsigned int NRPNValue)
{
	SendNRPN(GetMIDI_MAIN_CHANNEL(split), NRPNNumber, NRPNValue);
}


void LinnStrument::SendNRPN(unsigned char nChannelNibble, unsigned int NRPNNumber, unsigned int NRPNValue)
{
	if (m_MIDIOut->isPortOpen())
	{
		std::vector<unsigned char> myMessage;

		DBOUT(L"Sending channel = " + std::to_wstring(nChannelNibble) + L"\n")
			DBOUT(L"Parameter = " + std::to_wstring(NRPNNumber) + L"\n")
			DBOUT(L"Value = " + std::to_wstring(NRPNValue) + L"\n")

			unsigned char myStatusByte = (MIDI_CMD_CONTROL_CHANGE * 16) + nChannelNibble;
		unsigned char myNRPNParameterLSB = NRPNNumber % 128;
		unsigned char myNRPNParameterMSB = (NRPNNumber - myNRPNParameterLSB) / 128;
		unsigned char myNRPNValueLSB = NRPNValue % 128;
		unsigned char myNRPNValueMSB = (NRPNValue - myNRPNValueLSB) / 128;

		if (NRPNNumber == REQUEST_VALUE_OF_NRPN)
		{
			// Record the NRPN parameter we're querying
			m_NRPNQueue.push(NRPNValue);
			m_Sent++;
		}

		myMessage.push_back(myStatusByte);
		myMessage.push_back(SET_NRPN_CC_MSB);
		myMessage.push_back(myNRPNParameterMSB);
		m_MIDIOut->sendMessage(&myMessage);
		myMessage.clear();

		myMessage.push_back(myStatusByte);
		myMessage.push_back(SET_NRPN_CC_LSB);
		myMessage.push_back(myNRPNParameterLSB);
		m_MIDIOut->sendMessage(&myMessage);
		myMessage.clear();

		myMessage.push_back(myStatusByte);
		myMessage.push_back(CC_NRPN_VALUE_MSB);
		myMessage.push_back(myNRPNValueMSB);
		m_MIDIOut->sendMessage(&myMessage);
		myMessage.clear();

		myMessage.push_back(myStatusByte);
		myMessage.push_back(CC_NRPN_VALUE_LSB);
		myMessage.push_back(myNRPNValueLSB);
		m_MIDIOut->sendMessage(&myMessage);
		myMessage.clear();

		// Always send the reset or bad things can happen
		myMessage.push_back(myStatusByte);
		myMessage.push_back(RESET_NRPN_CC_MSB);
		myMessage.push_back(127);
		m_MIDIOut->sendMessage(&myMessage);
		myMessage.clear();

		myMessage.push_back(myStatusByte);
		myMessage.push_back(RESET_NRPN_CC_LSB);
		myMessage.push_back(127);
		m_MIDIOut->sendMessage(&myMessage);
		myMessage.clear();
	}  // Is the output port open?
	}


void LinnStrument::QueryLeftChannel()
{
	for ( unsigned char nChannel = (MIN_MIDI_CHANNEL - 1); nChannel < MAX_MIDI_CHANNEL; nChannel++)
	{
		SendNRPN(nChannel, REQUEST_VALUE_OF_NRPN, SPLIT_LEFT_MAIN_CHANNEL_NRPN);
	}
}


void LinnStrument::QueryRightChannel()
{
	for (unsigned char nChannel = (MIN_MIDI_CHANNEL - 1); nChannel < MAX_MIDI_CHANNEL; nChannel++)
	{
		SendNRPN(nChannel, REQUEST_VALUE_OF_NRPN, SPLIT_RIGHT_MAIN_CHANNEL_NRPN);
	}
}


void LinnStrument::QueryNRPN(unsigned int nParameterNumber)
{
	SendNRPN(GetMIDI_MAIN_CHANNEL(LSSplitType::LEFT), REQUEST_VALUE_OF_NRPN, nParameterNumber);
	m_Waiting = true;

	/*
	while (m_Waiting)
	{
		Sleep(1);
	}
*/
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

int LinnStrument::GetMIDIInID()
{
	return m_InputID;
}

void LinnStrument::SetMIDIInID(int nID)
{
	m_InputID = nID;
	if (m_MIDIIn->isPortOpen())
	{
		m_MIDIIn->cancelCallback();
		m_MIDIIn->closePort();
		m_MIDIIn->openPort(m_InputID);
		m_MIDIIn->setCallback(&LSCallback, (void*)this);
	}
}

int LinnStrument::GetMIDIOutID()
{
	return m_OutputID;
}

void LinnStrument::SetMIDIOutID(int nID)
{
	m_OutputID = nID;
	if (m_MIDIOut->isPortOpen())
	{
		m_MIDIOut->closePort();
		m_MIDIOut->openPort(m_OutputID);
	}
}

wxWindow * LinnStrument::GetParent()
{
	return m_Parent;
}

void LinnStrument::SetParent(wxWindow * parent)
{
	m_Parent = parent;
}


void LinnStrument::UpdateStatusBar()
{
	std::wstring wstrText;

	for (unsigned int i = 0; i < MAX_BYTE_VALUES; i++)
	{
		if (m_NotesHeld[i])
		{
			wstrText = wstrText + MIDI().GetNoteName(i) + " ";
		}
	}

		wxCommandEvent myNoteEvent(NoteEvent, STATUS_UPDATE_ID);
	myNoteEvent.SetString(wstrText);
					m_Parent->GetEventHandler()->ProcessEvent(myNoteEvent);
		}


bool LinnStrument::IsUpdateMode()
{
	bool blnResult = false;

	// LSOSUpdateName is what we're looking for

	CEnumerateSerial::CPortsArray ports;
	CEnumerateSerial::CPortAndNamesArray portAndNames;
	CEnumerateSerial::CNamesArray names;
	wxString wxstrOut;

#ifndef NO_CENUMERATESERIAL_USING_CREATEFILE
		wxstrOut = "CreateFile method reports\n";
	if (CEnumerateSerial::UsingCreateFile(ports))
	{
		for (const auto& port : ports)
			wxstrOut = wxstrOut + wxString::Format( "COM%u\n", port);
	}
	else
		wxstrOut = wxstrOut + wxString::Format("CEnumerateSerial::UsingCreateFile failed, Error:%u\n"), GetLastError();
#endif //#ifndef NO_CENUMERATESERIAL_USING_CREATEFILE

#ifndef NO_CENUMERATESERIAL_USING_QUERYDOSDEVICE
		wxstrOut = wxstrOut + wxString::Format( "QueryDosDevice method reports\n");
	if (CEnumerateSerial::UsingQueryDosDevice(ports))
	{
		for (const auto& port : ports)
			wxstrOut = wxstrOut + wxString::Format( "COM%u\n", port);
	}
	else
		wxstrOut = wxstrOut + wxString::Format("CEnumerateSerial::UsingQueryDosDevice failed, Error:%u\n"), GetLastError();
#endif //#ifndef NO_CENUMERATESERIAL_USING_QUERYDOSDEVICE

#ifndef NO_CENUMERATESERIAL_USING_GETDEFAULTCOMMCONFIG
	wxstrOut = wxstrOut + wxString::Format("GetDefaultCommConfig method reports\n");
	if (CEnumerateSerial::UsingGetDefaultCommConfig(ports))
	{
		for (const auto& port : ports)
			wxstrOut = wxstrOut + wxString::Format("COM%u\n", port);
	}
	else
		wxstrOut = wxstrOut + wxString::Format( "CEnumerateSerial::UsingGetDefaultCommConfig failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_GETDEFAULTCOMMCONFIG

#ifndef NO_CENUMERATESERIAL_USING_SETUPAPI1
	wxstrOut = wxstrOut + wxString::Format( "Device Manager (SetupAPI - GUID_DEVINTERFACE_COMPORT) reports\n");
	if (CEnumerateSerial::UsingSetupAPI1(portAndNames))
	{
		for (const auto& port : portAndNames)
			wxstrOut = wxstrOut + wxString::Format( "COM%u <%s>\n", port.first, port.second.c_str());
	}
	else
		wxstrOut = wxstrOut + wxString::Format( "CEnumerateSerial::UsingSetupAPI1 failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_SETUPAPI1

#ifndef NO_CENUMERATESERIAL_USING_SETUPAPI2
	wxstrOut = wxstrOut + wxString::Format( "Device Manager (SetupAPI - Ports Device information set) reports\n");
	if (CEnumerateSerial::UsingSetupAPI2(portAndNames))
	{
		for (const auto& port : portAndNames)
			wxstrOut = wxstrOut + wxString::Format( "COM%u <%s>\n", port.first, port.second.c_str());
	}
	else
		wxstrOut = wxstrOut + wxString::Format( "CEnumerateSerial::UsingSetupAPI2 failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_SETUPAPI2

#ifndef NO_CENUMERATESERIAL_USING_ENUMPORTS
	wxstrOut = wxstrOut + wxString::Format( "EnumPorts method reports\n");
	if (CEnumerateSerial::UsingEnumPorts(portAndNames))
	{
		for (const auto& port : portAndNames)
			wxstrOut = wxstrOut + wxString::Format( "COM%u <%s>\n", port.first, port.second.c_str());
	}
	else
		wxstrOut = wxstrOut + wxString::Format( "CEnumerateSerial::UsingEnumPorts failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_ENUMPORTS

#ifndef NO_CENUMERATESERIAL_USING_WMI
	wxstrOut = wxstrOut + wxString::Format( "WMI method reports\n");
	HRESULT hr = CEnumerateSerial::UsingWMI(portAndNames);
	if (SUCCEEDED(hr))
	{
		for (const auto& port : portAndNames)
			wxstrOut = wxstrOut + wxString::Format( "COM%u <%s>\n", port.first, port.second.c_str());
	}
	else
		wxstrOut = wxstrOut + wxString::Format( "CEnumerateSerial::UsingWMI failed, Error:%08X\n", hr);
#endif //#ifndef NO_CENUMERATESERIAL_USING_WMI

#ifndef NO_CENUMERATESERIAL_USING_COMDB
	wxstrOut = wxstrOut + wxString::Format( "ComDB method reports\n");
	if (CEnumerateSerial::UsingComDB(ports))
	{
		for (const auto& port : ports)
			wxstrOut = wxstrOut + wxString::Format( "COM%u\n", port);
	}
	else
		wxstrOut = wxstrOut + wxString::Format( "CEnumerateSerial::UsingComDB failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_COMDB

#ifndef NO_CENUMERATESERIAL_USING_REGISTRY
	wxstrOut = wxstrOut + wxString::Format( "Registry method reports\n");
	if (CEnumerateSerial::UsingRegistry(names))
	{
		for (const auto& name : names)
			wxstrOut = wxstrOut + wxString::Format( "%s\n", name.c_str());
	}
	else
		wxstrOut = wxstrOut + wxString::Format( "CEnumerateSerial::UsingRegistry failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_REGISTRY

#ifndef NO_CENUMERATESERIAL_USING_GETCOMMPORTS
	wxstrOut = wxstrOut + wxString::Format( "UsingGetCommPorts method reports\n");
	if (CEnumerateSerial::UsingGetCommPorts(ports))
	{
		for (const auto& port : ports)
			wxstrOut = wxstrOut + wxString::Format( "COM%u\n", port);
	}
	else
		wxstrOut = wxstrOut + wxString::Format( "CEnumerateSerial::UsingGetCommPorts failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_GETCOMMPORTS
	wxMessageBox(wxstrOut);
	return blnResult;
}

void LinnStrument::Speak(std::wstring wstrIn)
{
	HRESULT hr = pSpeech->Speak((LPCWSTR)wstrIn.c_str(), 0, NULL);
}
