// LinnStrument.cpp

#include "stdafx.h"
#include "LinnStrument.h"

wxDEFINE_EVENT(NoteEvent, wxCommandEvent);
wxDEFINE_EVENT(MIDIErrorEvent, wxCommandEvent);


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


LinnStrument::LinnStrument() 
	:
	m_Parent(NULL),
	m_InputID(NO_PORT),
	m_OutputID(NO_PORT),
	m_TimeOut( DEFAULT_TIME_OUT),
	m_SpeakMessages(false),
	m_SpeakNotes(false),
	m_thread(),
		m_ReceivedNRPNValueMSB(false),
		m_ReceivedNRPNValueLSB(false),
								m_CanDetectSerialPorts(true),
		// left split
		m_LEFT_SPLIT_MODE(0),
				m_LEFT_MIDI_MAIN_CHANNEL(0),
		m_LEFT_CHANNEL_PER_NOTE_1(0),
		m_LEFT_CHANNEL_PER_NOTE_2(0),
		m_LEFT_CHANNEL_PER_NOTE_3(0),
		m_LEFT_CHANNEL_PER_NOTE_4(0),
		m_LEFT_CHANNEL_PER_NOTE_5(0),
		m_LEFT_CHANNEL_PER_NOTE_6(0),
		m_LEFT_CHANNEL_PER_NOTE_7(0),
		m_LEFT_CHANNEL_PER_NOTE_8(0),
		m_LEFT_CHANNEL_PER_NOTE_9(0),
		m_LEFT_CHANNEL_PER_NOTE_10(0),
		m_LEFT_CHANNEL_PER_NOTE_11(0),
		m_LEFT_CHANNEL_PER_NOTE_12(0),
		m_LEFT_CHANNEL_PER_NOTE_13(0),
		m_LEFT_CHANNEL_PER_NOTE_14(0),
		m_LEFT_CHANNEL_PER_NOTE_15(0),
		m_LEFT_CHANNEL_PER_NOTE_16(0),
		// Value is a MIDI channel number:
		m_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL(0),
		// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
		m_LEFT_BEND_RANGE(0),
		// Toggles:
		m_LEFT_BEND_TOGGLE(0),
		m_LEFT_BEND_QUANTIZE_TOGGLE(0),
		// Value is from LSPitchQuantize
		m_LEFT_PITCH_QUANTIZE(0),
		// Toggles:
		m_LEFT_RESET_PITCH_ON_RELEASE(0),
		// Values are constrained by MIN_CC and MAX_CC
		// CC 1 or CC 74 are recommended, any CC is possible though
		m_LEFT_CC_FOR_Y(0),
		// Toggle:
		m_LEFT_RELATIVE_Y(0),
		m_LEFT_RELATIVE_Z(0),
		// Value is an LSExpressionZ
		m_LEFT_EXPRESSION_FOR_Z(0),
		// Values are constrained by MIN_CC and MAX_CC
		// CC 11 is recommended, any CC is possible though
		m_LEFT_CC_FOR_Z(0),
		// Values are defined in LSColor
		m_LEFT_COLOR_MAIN(0),
		m_LEFT_COLOR_ACCENT(0),
		m_LEFT_COLOR_PLAYED(0),
		m_LEFT_COLOR_LOWROW(0),
		// Value is an LSLowRowMode
		m_LEFT_LOWROW_MODE(0),
		// Value is an LSSpecial:
		m_LEFT_SPECIAL(0),
		// Value is an LSOctave
		m_LEFT_OCTAVE(0),
		// Values are from LSPitch
		m_LEFT_PITCH_TRANSPOSE(0),
		m_LEFT_TRANSPOSE_LIGHTS(0),
		// Value is an LSExpressionY
		m_LEFT_EXPRESSION_FOR_Y(0),
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		m_LEFT_CC_FOR_FADER1(0),
		m_LEFT_CC_FOR_FADER2(0),
		m_LEFT_CC_FOR_FADER3(0),
		m_LEFT_CC_FOR_FADER4(0),
		m_LEFT_CC_FOR_FADER5(0),
		m_LEFT_CC_FOR_FADER6(0),
		m_LEFT_CC_FOR_FADER7(0),
		m_LEFT_CC_FOR_FADER8(0),
		// Value is an LSLowRowBehaviour
		m_LEFT_LOWROW_X_BEHAVIOUR(0),
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		m_LEFT_CC_FOR_LOWROW(0),
		// Value is an LSLowRowBehaviour
		m_LEFT_LOWROW_XYZ_BEHAVIOUR(0),
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		m_LEFT_CC_FOR_LOWROW_XYZ(0),
		m_LEFT_CC_FOR_LOWROW_XYZ_Y(0),
		m_LEFT_CC_FOR_LOWROW_XYZ_Z(0),
		// Values are constrained by MIN_CC and MAX_CC
		m_LEFT_MIN_CC_FOR_Y(0),
		m_LEFT_MAX_CC_FOR_Y(0),
		m_LEFT_MIN_CC_FOR_Z(0),
		m_LEFT_MAX_CC_FOR_Z(0),
		m_LEFT_14BIT_CC_VALUE_FOR_Z(0),
		m_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y(0),
		// Value is an LSChannelOrder
		m_LEFT_CHANNEL_PER_ROW_ORDER(0),
		// Value is an LSAnimation
		m_LEFT_TOUCH_ANIMATION(0),
		// Toggle:
		m_LEFT_SEQUENCER_TOGGLE_PLAY(0),
		m_LEFT_SEQUENCER_PREVIOUS_PATTERN(0),
		m_LEFT_SEQUENCER_NEXT_PATTERN(0),
		// Value is an LSPatternNumber
		m_LEFT_SEQUENCER_PATTERN(0),
		m_LEFT_SEQUENCER_TOGGLE_MUTE(0),
		// Right split
		m_RIGHT_SPLIT_MODE(0),
		m_RIGHT_MIDI_MAIN_CHANNEL(0),
		m_RIGHT_SPLIT_RIGHT_MAIN_MODE(0),
		m_RIGHT_SPLIT_RIGHT_MAIN_CHANNEL(0),
		m_RIGHT_CHANNEL_PER_NOTE_1(0),
		m_RIGHT_CHANNEL_PER_NOTE_2(0),
		m_RIGHT_CHANNEL_PER_NOTE_3(0),
		m_RIGHT_CHANNEL_PER_NOTE_4(0),
		m_RIGHT_CHANNEL_PER_NOTE_5(0),
		m_RIGHT_CHANNEL_PER_NOTE_6(0),
		m_RIGHT_CHANNEL_PER_NOTE_7(0),
		m_RIGHT_CHANNEL_PER_NOTE_8(0),
		m_RIGHT_CHANNEL_PER_NOTE_9(0),
		m_RIGHT_CHANNEL_PER_NOTE_10(0),
		m_RIGHT_CHANNEL_PER_NOTE_11(0),
		m_RIGHT_CHANNEL_PER_NOTE_12(0),
		m_RIGHT_CHANNEL_PER_NOTE_13(0),
		m_RIGHT_CHANNEL_PER_NOTE_14(0),
		m_RIGHT_CHANNEL_PER_NOTE_15(0),
		m_RIGHT_CHANNEL_PER_NOTE_16(0),
		// Value is a MIDI channel number:
		m_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL(0),
		// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
		m_RIGHT_BEND_RANGE(0),
		// Toggles:
		m_RIGHT_BEND_TOGGLE(0),
		m_RIGHT_BEND_QUANTIZE_TOGGLE(0),
		// Value is from LSPitchQuantize
		m_RIGHT_PITCH_QUANTIZE(0),
		// Toggles:
		m_RIGHT_RESET_PITCH_ON_RELEASE(0),
		m_LEFT_SEND_Y(0),
			m_RIGHT_SEND_Y(0),
		// Values are constrained by MIN_CC and MAX_CC
		// CC 1 or CC 74 are recommended, any CC is possible though
		m_RIGHT_CC_FOR_Y(0),
		// Toggle:
		m_RIGHT_RELATIVE_Y(0),
		m_RIGHT_RELATIVE_Z(0),
		// Value is an LSExpressionZ
		m_RIGHT_EXPRESSION_FOR_Z(0),
		// Values are constrained by MIN_CC and MAX_CC
		// CC 11 is recommended, any CC is possible though
		m_RIGHT_CC_FOR_Z(0),
		// Values are defined in LSColor
		m_RIGHT_COLOR_MAIN(0),
		m_RIGHT_COLOR_ACCENT(0),
		m_RIGHT_COLOR_PLAYED(0),
		m_RIGHT_COLOR_LOWROW(0),
		// Value is an LSLowRowMode
		m_RIGHT_LOWROW_MODE(0),
		// Value is an LSSpecial:
		m_RIGHT_SPECIAL(0),
		// Value is an LSOctave
		m_RIGHT_OCTAVE(0),
		// Values are from LSPitch
		m_RIGHT_PITCH_TRANSPOSE(0),
		m_RIGHT_TRANSPOSE_LIGHTS(0),
		// Value is an LSExpressionY
		m_RIGHT_EXPRESSION_FOR_Y(0),
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		m_RIGHT_CC_FOR_FADER1(0),
		m_RIGHT_CC_FOR_FADER2(0),
		m_RIGHT_CC_FOR_FADER3(0),
		m_RIGHT_CC_FOR_FADER4(0),
		m_RIGHT_CC_FOR_FADER5(0),
		m_RIGHT_CC_FOR_FADER6(0),
		m_RIGHT_CC_FOR_FADER7(0),
		m_RIGHT_CC_FOR_FADER8(0),
		// Value is an LSLowRowBehaviour
		m_RIGHT_LOWROW_X_BEHAVIOUR(0),
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		m_RIGHT_CC_FOR_LOWROW(0),
		// Value is an LSLowRowBehaviour
		m_RIGHT_LOWROW_XYZ_BEHAVIOUR(0),
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		m_RIGHT_CC_FOR_LOWROW_XYZ(0),
		m_RIGHT_CC_FOR_LOWROW_XYZ_Y(0),
		m_RIGHT_CC_FOR_LOWROW_XYZ_Z(0),
		// Values are constrained by MIN_CC and MAX_CC
		m_RIGHT_MIN_CC_FOR_Y(0),
		m_RIGHT_MAX_CC_FOR_Y(0),
		m_RIGHT_MIN_CC_FOR_Z(0),
		m_RIGHT_MAX_CC_FOR_Z(0),
		m_RIGHT_14BIT_CC_VALUE_FOR_Z(0),
		m_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y(0),
		// Value is an LSChannelOrder
		m_RIGHT_CHANNEL_PER_ROW_ORDER(0),
		// Value is an LSAnimation
		m_RIGHT_TOUCH_ANIMATION(0),
		// Toggle:
		m_RIGHT_SEQUENCER_TOGGLE_PLAY(0),
		m_RIGHT_SEQUENCER_PREVIOUS_PATTERN(0),
		m_RIGHT_SEQUENCER_NEXT_PATTERN(0),
		// Value is an LSPatternNumber
		m_RIGHT_SEQUENCER_PATTERN(0),
		m_RIGHT_SEQUENCER_TOGGLE_MUTE(0),
		m_LEFT_SEND_Z(0),
			m_RIGHT_SEND_Z(0),
					// Foot and panel switches
		// Value is LSSwitchAssignment
		m_SWITCH1_ASSIGN(0),
		m_SWITCH2_ASSIGN(0),
		m_FOOT_LEFT_ASSIGN(0),
		m_FOOT_RIGHT_ASSIGN(0),
		// Toggle:
		m_SWITCH1_BOTH_SPLITS(0),
		m_SWITCH2_BOTH_SPLITS(0),
		m_FOOT_LEFT_BOTH_SPLITS(0),
		m_FOOT_RIGHT_BOTH_SPLITS(0),
		// Values are constrained by MIN_CC and MAX_CC
		m_CC_FOR_LEFT_FOOT_CC65(0),
		m_CC_FOR_RIGHT_FOOT_CC65(0),
		m_CC_FOR_SWITCH1_CC65(0),
		m_CC_FOR_SWITCH2_CC65(0),
		m_CC_FOR_LEFT_FOOT_SUSTAIN(0),
		m_CC_FOR_RIGHT_FOOT_SUSTAIN(0),
		m_CC_FOR_SWITCH1_SUSTAIN(0),
		m_CC_FOR_SWITCH2_SUSTAIN(0),

		// Octave/transpose settings
		m_LeftOctave(0),m_LeftTransposePitch(0),
			m_LeftTransposeLights(0),
		m_RightOctave(0),
			m_RightTransposePitch(0),
			m_RightTransposeLights(0),
					// Global settings
		m_GLOBAL_SPLIT_ACTIVE(0),
		// Value is LSSplitType
		m_GLOBAL_SELECTED_SPLIT(0),
		// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
		m_GLOBAL_SPLIT_COLUMN(0),
		// Toggles:
		m_GLOBAL_MAIN_NOTE_LIGHT_C(0),
		m_GLOBAL_MAIN_NOTE_LIGHT_C_SHARP(0),
		m_GLOBAL_MAIN_NOTE_LIGHT_D(0),
		m_GLOBAL_MAIN_NOTE_LIGHT_D_SHARP(0),
		m_GLOBAL_MAIN_NOTE_LIGHT_E(0),
		m_GLOBAL_MAIN_NOTE_LIGHT_F(0),
		m_GLOBAL_MAIN_NOTE_LIGHT_F_SHARP(0),
		m_GLOBAL_MAIN_NOTE_LIGHT_G(0),
		m_GLOBAL_MAIN_NOTE_LIGHT_G_SHARP(0),
		m_GLOBAL_MAIN_NOTE_LIGHT_A(0),
		m_GLOBAL_MAIN_NOTE_LIGHT_A_SHARP(0),
		m_GLOBAL_MAIN_NOTE_LIGHT_B(0),
		m_GLOBAL_ACCENT_NOTE_LIGHT_C(0),
		m_GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP(0),
		m_GLOBAL_ACCENT_NOTE_LIGHT_D(0),
		m_GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP(0),
		m_GLOBAL_ACCENT_NOTE_LIGHT_E(0),
		m_GLOBAL_ACCENT_NOTE_LIGHT_F(0),
		m_GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP(0),
		m_GLOBAL_ACCENT_NOTE_LIGHT_G(0),
		m_GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP(0),
		m_GLOBAL_ACCENT_NOTE_LIGHT_A(0),
		m_GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP(0),
		m_GLOBAL_ACCENT_NOTE_LIGHT_B(0),
		// Value is LSRowOffsetType
		m_GLOBAL_ROW_OFFSET(0),
		// Value is LSVelocityRange
		m_GLOBAL_VELOCITY_SENSITIVITY(0),
		// Value is LSPressureRange
		m_GLOBAL_PRESSURE_SENSITIVITY(0),
		// Value is LSMIDIDevice
		m_GLOBAL_MIDI_DEVICE_IO(0),
		// Value is LSArpDirection
		m_GLOBAL_ARP_DIRECTION(0),
		// Value is LSArpTempoNoteType
		m_GLOBAL_ARP_TEMPO_NOTE_VALUE(0),
		// Value is LSGlobalArpOctaveExtension
		m_GLOBAL_ARP_OCTAVE_EXTENSION(0),
		// Value = 1 - 360  (applies when receiving no MIDI clock)
		m_GLOBAL_CLOCK_BPM(1),
		// Value is LSPresetNumber
		m_GLOBAL_SETTINGS_PRESET_LOAD(0),
		// Toggles:
		m_GLOBAL_PRESSURE_AFTERTOUCH(0),
		m_DEVICE_USER_FIRMWARE_MODE(0),
		m_DEVICE_LEFT_HANDED(0),
		// Value is constrained by MIN_LIGHTS_PRESET and MAX_LIGHTS_PRESET 
		m_GLOBAL_ACTIVE_LIGHTS_PRESET(0),
		// Values are constrained by MIN_CC and MAX_CC
		m_GLOBAL_MIN_VELOCITY_VALUE(0),
		m_GLOBAL_MAX_VELOCITY_VALUE(0),
		m_GLOBAL_FIXED_VELOCITY_VALUE(0),
		// Value range =     0 - 512  
		m_DEVICE_MIN_BYTE_INTERVAL_VALUE(0),
		// Value is LSCustomRowOffset
		m_GLOBAL_CUSTOM_ROW_OFFSET(0),
		// Toggle:
		m_DEVICE_MIDI_THRU(0),
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW1(0),
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW2(0),
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW3(0),
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW4(0),
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW5(0),
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW6(0),
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW7(0),
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW8(0),
		m_LSPresetNumber(0),
		m_LEFT_PROGRAM(0),
		m_RIGHT_PROGRAM(0),
		m_LEFT_VOLUME(0),
			m_RIGHT_VOLUME(0)
	{
						// Initialise note tracking
		for (unsigned int i = 0; i < MAX_BYTE_VALUES; i++)
		{
			m_NotesHeld[i] = false;
		}

#ifdef __WINDOWS__
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
#endif

		m_MIDIIn = new RtMidiIn();
		m_MIDIOut = new RtMidiOut();
					   }


LinnStrument::LinnStrument(wxWindow * parent, int nInputID, int nOutputID, bool blnSpeakMessages, bool blnSpeakNotes) 
	: LinnStrument()
{
	m_Parent = parent;
		m_InputID = nInputID;
		m_OutputID = nOutputID;
		m_SpeakMessages = blnSpeakMessages;
		m_SpeakNotes = blnSpeakNotes;
				InitMIDI( m_InputID, m_OutputID);
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
		
	return NO_PORT;
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

	return NO_PORT;
}


void LinnStrument::SetLSParameter(unsigned int NRPNParameterIn, unsigned int NRPNValueIn)
{
	std::unique_lock<std::mutex> lck(m_mtx);
	NRPNParameterIn = m_parameter;
	DBOUT( L"Parameter = " + std::to_wstring(NRPNParameterIn) + L"\nValue = " + std::to_wstring(NRPNValueIn) + L"\n")
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
		m_cv.notify_all(); 
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
		m_NotesHeld[ MIDI().ShortMsgData1(myMessage)] = false;
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
																SetLSParameter(m_NRPNParameterIn, m_NRPNValueIn);
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

void LinnStrument::HandleMIDIError(std::string strError)
{
	wxCommandEvent myMIDIErrorEvent(MIDIErrorEvent, MIDI_ERROR_ID);
	myMIDIErrorEvent.SetString(strError);
	m_Parent->GetEventHandler()->ProcessEvent(myMIDIErrorEvent);
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

								unsigned char myStatusByte = (MIDI_CMD_CONTROL_CHANGE * 16) + nChannelNibble;
		unsigned char myNRPNParameterLSB = NRPNNumber % 128;
		unsigned char myNRPNParameterMSB = (NRPNNumber - myNRPNParameterLSB) / 128;
		unsigned char myNRPNValueLSB = NRPNValue % 128;
		unsigned char myNRPNValueMSB = (NRPNValue - myNRPNValueLSB) / 128;
						myMessage.push_back(myStatusByte);
		myMessage.push_back(SET_NRPN_CC_MSB);
		myMessage.push_back(myNRPNParameterMSB);
			
		try
		{
			m_MIDIOut->sendMessage(&myMessage);
		}
		catch (RtMidiError &error)
		{
			HandleMIDIError( error.getMessage());
		}

				myMessage.clear();
								myMessage.push_back(myStatusByte);
		myMessage.push_back(SET_NRPN_CC_LSB);
		myMessage.push_back(myNRPNParameterLSB);
		
		try
		{
			m_MIDIOut->sendMessage(&myMessage);
		}
		catch (RtMidiError &error)
		{
			HandleMIDIError(error.getMessage());
		}

		myMessage.clear();
				myMessage.push_back(myStatusByte);
		myMessage.push_back(CC_NRPN_VALUE_MSB);
		myMessage.push_back(myNRPNValueMSB);

try
{
	m_MIDIOut->sendMessage(&myMessage);
}
catch (RtMidiError &error)
{
	HandleMIDIError(error.getMessage());
}

myMessage.clear();
		myMessage.push_back(myStatusByte);
		myMessage.push_back(CC_NRPN_VALUE_LSB);
		myMessage.push_back(myNRPNValueLSB);
		
		try
		{
			m_MIDIOut->sendMessage(&myMessage);
		}
		catch (RtMidiError &error)
		{
			HandleMIDIError(error.getMessage());
		}

		myMessage.clear();
				// Always send the reset or bad things can happen
		myMessage.push_back(myStatusByte);
		myMessage.push_back(RESET_NRPN_CC_MSB);
		myMessage.push_back(127);

try
{
	m_MIDIOut->sendMessage(&myMessage);
}
catch (RtMidiError &error)
{
	HandleMIDIError(error.getMessage());
}

myMessage.clear();
		myMessage.push_back(myStatusByte);
		myMessage.push_back(RESET_NRPN_CC_LSB);
		myMessage.push_back(127);
		try
		{
			m_MIDIOut->sendMessage(&myMessage);
		}
		catch (RtMidiError &error)
		{
			HandleMIDIError(error.getMessage());
		}

		myMessage.clear();
	}  // Is the output port open?
	}


void LinnStrument::InitParameter( unsigned int nParameterNumber)
{
	m_parameter = nParameterNumber;
		m_thread = std::thread(&LinnStrument::QueryNRPN, this, m_parameter);
	std::unique_lock<std::mutex> lck(m_mtx);
	std::cv_status myCVStatus =  m_cv.wait_for(lck, std::chrono::milliseconds( m_TimeOut));
	
	if (myCVStatus == std::cv_status::timeout)
	{
		DBOUT(L"Timed out for NRPN " + std::to_wstring(m_parameter));
		} 
	
		m_thread.join();
		
	if ((nParameterNumber == 0) && (m_GLOBAL_MIDI_DEVICE_IO == GetLS_MIDIDeviceIndex(LS_MIDIDevice::MIDI_DIN_JACKS)))
		{
			// Response received to first parameter query, so first indication that we have good MIDI DIN communication
						Speak(wstrDINConnected);
		}
}


void LinnStrument::QueryNRPN(unsigned int nParameterNumber)
{
		SendNRPN(0, REQUEST_VALUE_OF_NRPN, nParameterNumber);
}


void LinnStrument::QueryAll()
{
	QueryLeftSplitSettings();
	QueryRightSplitSettings();
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
	InitMIDI(m_InputID, m_OutputID);
}

int LinnStrument::GetMIDIOutID()
{
	return m_OutputID;
}

void LinnStrument::SetMIDIOutID(int nID)
{
	m_OutputID = nID;
	InitMIDI(m_InputID, m_OutputID);
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
			wxstrOut = wxstrOut + wxString::Format("COM%u\n", port);
	}
	else
		wxstrOut = wxstrOut + wxString::Format("CEnumerateSerial::UsingCreateFile failed, Error:%u\n"), GetLastError();
#endif //#ifndef NO_CENUMERATESERIAL_USING_CREATEFILE

#ifndef NO_CENUMERATESERIAL_USING_QUERYDOSDEVICE
	wxstrOut = wxstrOut + wxString::Format("QueryDosDevice method reports\n");
	if (CEnumerateSerial::UsingQueryDosDevice(ports))
	{
		for (const auto& port : ports)
			wxstrOut = wxstrOut + wxString::Format("COM%u\n", port);
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
		wxstrOut = wxstrOut + wxString::Format("CEnumerateSerial::UsingGetDefaultCommConfig failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_GETDEFAULTCOMMCONFIG

#ifndef NO_CENUMERATESERIAL_USING_SETUPAPI1
	wxstrOut = wxstrOut + wxString::Format("Device Manager (SetupAPI - GUID_DEVINTERFACE_COMPORT) reports\n");
	if (CEnumerateSerial::UsingSetupAPI1(portAndNames))
	{
		for (const auto& port : portAndNames)
			wxstrOut = wxstrOut + wxString::Format("COM%u <%s>\n", port.first, port.second.c_str());
	}
	else
		wxstrOut = wxstrOut + wxString::Format("CEnumerateSerial::UsingSetupAPI1 failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_SETUPAPI1

#ifndef NO_CENUMERATESERIAL_USING_SETUPAPI2
	wxstrOut = wxstrOut + wxString::Format("Device Manager (SetupAPI - Ports Device information set) reports\n");
	if (CEnumerateSerial::UsingSetupAPI2(portAndNames))
	{
		for (const auto& port : portAndNames)
			wxstrOut = wxstrOut + wxString::Format("COM%u <%s>\n", port.first, port.second.c_str());
	}
	else
		wxstrOut = wxstrOut + wxString::Format("CEnumerateSerial::UsingSetupAPI2 failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_SETUPAPI2

#ifndef NO_CENUMERATESERIAL_USING_ENUMPORTS
	wxstrOut = wxstrOut + wxString::Format("EnumPorts method reports\n");
	if (CEnumerateSerial::UsingEnumPorts(portAndNames))
	{
		for (const auto& port : portAndNames)
			wxstrOut = wxstrOut + wxString::Format("COM%u <%s>\n", port.first, port.second.c_str());
	}
	else
		wxstrOut = wxstrOut + wxString::Format("CEnumerateSerial::UsingEnumPorts failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_ENUMPORTS

#ifndef NO_CENUMERATESERIAL_USING_WMI
	wxstrOut = wxstrOut + wxString::Format("WMI method reports\n");
	HRESULT hr = CEnumerateSerial::UsingWMI(portAndNames);
	if (SUCCEEDED(hr))
	{
		for (const auto& port : portAndNames)
			wxstrOut = wxstrOut + wxString::Format("COM%u <%s>\n", port.first, port.second.c_str());
	}
	else
		wxstrOut = wxstrOut + wxString::Format("CEnumerateSerial::UsingWMI failed, Error:%08X\n", hr);
#endif //#ifndef NO_CENUMERATESERIAL_USING_WMI

#ifndef NO_CENUMERATESERIAL_USING_COMDB
	wxstrOut = wxstrOut + wxString::Format("ComDB method reports\n");
	if (CEnumerateSerial::UsingComDB(ports))
	{
		for (const auto& port : ports)
			wxstrOut = wxstrOut + wxString::Format("COM%u\n", port);
	}
	else
		wxstrOut = wxstrOut + wxString::Format("CEnumerateSerial::UsingComDB failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_COMDB

#ifndef NO_CENUMERATESERIAL_USING_REGISTRY
	wxstrOut = wxstrOut + wxString::Format("Registry method reports\n");
	if (CEnumerateSerial::UsingRegistry(names))
	{
		for (const auto& name : names)
			wxstrOut = wxstrOut + wxString::Format("%s\n", name.c_str());
	}
	else
		wxstrOut = wxstrOut + wxString::Format("CEnumerateSerial::UsingRegistry failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_REGISTRY

#ifndef NO_CENUMERATESERIAL_USING_GETCOMMPORTS
	wxstrOut = wxstrOut + wxString::Format("UsingGetCommPorts method reports\n");
	if (CEnumerateSerial::UsingGetCommPorts(ports))
	{
		for (const auto& port : ports)
			wxstrOut = wxstrOut + wxString::Format("COM%u\n", port);
	}
	else
		wxstrOut = wxstrOut + wxString::Format("CEnumerateSerial::UsingGetCommPorts failed, Error:%u\n", GetLastError());
#endif //#ifndef NO_CENUMERATESERIAL_USING_GETCOMMPORTS

	blnResult = wxstrOut.Contains(LSOSUpdateName);
	return blnResult;
}

void LinnStrument::Speak(std::wstring wstrIn)
{
#ifdef __WINDOWS__
	// HRESULT hr = pSpeech->Speak((LPCWSTR)wstrIn.c_str(), 0, NULL);
	HRESULT 		hr = pSpeech->Speak( (LPCWSTR) L"", SVSFPurgeBeforeSpeak, NULL);
		hr = pSpeech->Speak((LPCWSTR)wstrIn.c_str(), SVSFlagsAsync, NULL);
	#endif
}


bool LinnStrument::IsDINWorking()
{
	return (m_GLOBAL_MIDI_DEVICE_IO == GetLS_MIDIDeviceIndex(LS_MIDIDevice::USB));
		// && (m_ResponseReceived));
}


void LinnStrument::InitMIDI(int nInputID, int nOutputID)
{
	try
	{
		if (m_MIDIIn->isPortOpen())
	{
		m_MIDIIn->cancelCallback();
		m_MIDIIn->closePort();
		m_MIDIIn->openPort(m_InputID);
		m_MIDIIn->setCallback(&LSCallback, (void*)this);
	}

	if (m_MIDIOut->isPortOpen())
	{
		m_MIDIOut->closePort();
	}

	if ((m_MIDIIn->getPortCount() == 0) || (m_MIDIOut->getPortCount() == 0))
	{
		m_InputID = NO_PORT;
		m_OutputID = NO_PORT;
	}
	else
	{
		int nUSBInID = GetUSBInPortID();
		int nUSBOutID = GetUSBOutPortID();

		if ((nUSBInID != NO_PORT) && (nUSBOutID != NO_PORT))
		{
			// USB connection detected, so ignore any saved port ID values and override
			m_GLOBAL_MIDI_DEVICE_IO = GetLS_MIDIDeviceIndex(LS_MIDIDevice::USB);
			m_InputID = nUSBInID;
			m_OutputID = nUSBOutID;
		}

		if ((m_InputID == NO_PORT) || (m_OutputID == NO_PORT))
		{
			// No USB connection detected and no MIDI I/O ports saved, so get user to specify DIN connections
			MIDIDialog * pMIDIDialog = new MIDIDialog(wstrMIDIDlgTitle);
			if (pMIDIDialog->ShowModal() == wxID_OK)
			{
				m_OutputID = pMIDIDialog->GetSelectedOutput();
				m_InputID = pMIDIDialog->GetSelectedInput();
				m_GLOBAL_MIDI_DEVICE_IO = GetLS_MIDIDeviceIndex(LS_MIDIDevice::USB);
			}  // End of manual DIN selection
		}

		// Now we have valid port ID values, so open the ports and initialise parameter values
		if ((m_OutputID != NO_PORT) && (m_InputID != NO_PORT))
		{
			m_MIDIOut->openPort(m_OutputID);
			m_MIDIIn->openPort(m_InputID);
			m_MIDIIn->setCallback(&LSCallback, (void*)this);

			if (m_GLOBAL_MIDI_DEVICE_IO == GetLS_MIDIDeviceIndex( LS_MIDIDevice::USB))
			{
				Speak(wstrUSBConnected);
			}

			QueryAll();
		}  // end if DIN ports selected
	}  // end if 0 input and output ports
	}
	catch (RtMidiError &error)
	{
		HandleMIDIError(error.getMessage());
	}


	if ((m_SpeakMessages)
		&& (m_InputID == NO_PORT)
		&& (m_OutputID == NO_PORT))
	{
		Speak(wstrNotConnected);
	}
}
void LinnStrument::QueryLeftSplitSettings()
{
	// Left-hand split
	InitParameter(SPLIT_LEFT_MAIN_MODE_NRPN);
	InitParameter(SPLIT_LEFT_MAIN_CHANNEL_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN);
	InitParameter(SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN);
	InitParameter(SPLIT_LEFT_BEND_RANGE_NRPN);
	InitParameter(SPLIT_LEFT_BEND_TOGGLE_NRPN);
	InitParameter(SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN);
	InitParameter(SPLIT_LEFT_PITCH_QUANTIZE_NRPN);
	InitParameter(SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN);
	InitParameter(SPLIT_LEFT_SEND_Y_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_Y_NRPN);
	InitParameter(SPLIT_LEFT_RELATIVE_Y_NRPN);
	InitParameter(SPLIT_LEFT_SEND_Z_NRPN);
	InitParameter(SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_Z_NRPN);
	InitParameter(SPLIT_LEFT_COLOR_MAIN_NRPN);
	InitParameter(SPLIT_LEFT_COLOR_ACCENT_NRPN);
	InitParameter(SPLIT_LEFT_COLOR_PLAYED_NRPN);
	InitParameter(SPLIT_LEFT_COLOR_LOWROW_NRPN);
	InitParameter(SPLIT_LEFT_LOWROW_MODE_NRPN);
	InitParameter(SPLIT_LEFT_SPECIAL_NRPN);
	InitParameter(SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_FADER1_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_FADER2_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_FADER3_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_FADER4_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_FADER5_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_FADER6_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_FADER7_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_FADER8_NRPN);
	InitParameter(SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_LOWROW_NRPN);
	InitParameter(SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN);
	InitParameter(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN);
	InitParameter(SPLIT_LEFT_MIN_CC_FOR_Y_NRPN);
	InitParameter(SPLIT_LEFT_MAX_CC_FOR_Y_NRPN);
	InitParameter(SPLIT_LEFT_MIN_CC_FOR_Z_NRPN);
	InitParameter(SPLIT_LEFT_MAX_CC_FOR_Z_NRPN);
	InitParameter(SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN);
	InitParameter(SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN);
	InitParameter(SPLIT_LEFT_CHANNEL_PER_ROW_ORDER_NRPN);
	InitParameter(SPLIT_LEFT_TOUCH_ANIMATION_NRPN);
	// Parameter does not respond to queries currently
	// InitParameter(SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN);
// Parameter does not respond to queries currently
		// InitParameter(SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN);
// Parameter does not respond to queries currently
		// InitParameter(SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN);
	InitParameter(SPLIT_LEFT_SEQUENCER_PATTERN_NRPN);
	// Parameter does not respond to queries currently
	// InitParameter(SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN);
}

void LinnStrument::QueryRightSplitSettings()
{
	// Right-hand split
	InitParameter(SPLIT_RIGHT_MAIN_MODE_NRPN);
	InitParameter(SPLIT_RIGHT_MAIN_CHANNEL_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN);
	InitParameter(SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN);
	InitParameter(SPLIT_RIGHT_BEND_RANGE_NRPN);
	InitParameter(SPLIT_RIGHT_BEND_TOGGLE_NRPN);
	InitParameter(SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN);
	InitParameter(SPLIT_RIGHT_PITCH_QUANTIZE_NRPN);
	InitParameter(SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN);
	InitParameter(SPLIT_RIGHT_SEND_Y_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_Y_NRPN);
	InitParameter(SPLIT_RIGHT_RELATIVE_Y_NRPN);
	InitParameter(SPLIT_RIGHT_SEND_Z_NRPN);
	InitParameter(SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_Z_NRPN);
	InitParameter(SPLIT_RIGHT_COLOR_MAIN_NRPN);
	InitParameter(SPLIT_RIGHT_COLOR_ACCENT_NRPN);
	InitParameter(SPLIT_RIGHT_COLOR_PLAYED_NRPN);
	InitParameter(SPLIT_RIGHT_COLOR_LOWROW_NRPN);
	InitParameter(SPLIT_RIGHT_LOWROW_MODE_NRPN);
	InitParameter(SPLIT_RIGHT_SPECIAL_NRPN);
	InitParameter(SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_FADER1_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_FADER2_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_FADER3_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_FADER4_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_FADER5_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_FADER6_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_FADER7_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_FADER8_NRPN);
	InitParameter(SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_LOWROW_NRPN);
	InitParameter(SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN);
	InitParameter(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN);
	InitParameter(SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN);
	InitParameter(SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN);
	InitParameter(SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN);
	InitParameter(SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN);
	InitParameter(SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN);
	InitParameter(SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN);
	InitParameter(SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER_NRPN);
	InitParameter(SPLIT_RIGHT_TOUCH_ANIMATION_NRPN);
	// Parameter does not respond to queries currently
// 	InitParameter(SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN);
// Parameter does not respond to queries currently
// 	InitParameter(SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN);
// Parameter does not respond to queries currently
	// 	InitParameter(SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN);
	InitParameter(SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN);
	// Parameter does not respond to queries currently
// 	InitParameter(SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN);
}

void LinnStrument::QueryGlobalSettings()
{
	InitParameter(GLOBAL_SPLIT_ACTIVE_NRPN);
	InitParameter(GLOBAL_SELECTED_SPLIT_NRPN);
	InitParameter(GLOBAL_SPLIT_COLUMN_NRPN);
	InitParameter(GLOBAL_MAIN_NOTE_LIGHT_C_NRPN);
	InitParameter(GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_NRPN);
	InitParameter(GLOBAL_MAIN_NOTE_LIGHT_D_NRPN);
	InitParameter(GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_NRPN);
	InitParameter(GLOBAL_MAIN_NOTE_LIGHT_E_NRPN);
	InitParameter(GLOBAL_MAIN_NOTE_LIGHT_F_NRPN);
	InitParameter(GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_NRPN);
	InitParameter(GLOBAL_MAIN_NOTE_LIGHT_G_NRPN);
	InitParameter(GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_NRPN);
	InitParameter(GLOBAL_MAIN_NOTE_LIGHT_A_NRPN);
	InitParameter(GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_NRPN);
	InitParameter(GLOBAL_MAIN_NOTE_LIGHT_B_NRPN);
	InitParameter(GLOBAL_ACCENT_NOTE_LIGHT_C_NRPN);
	InitParameter(GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_NRPN);
	InitParameter(GLOBAL_ACCENT_NOTE_LIGHT_D_NRPN);
	InitParameter(GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_NRPN);
	InitParameter(GLOBAL_ACCENT_NOTE_LIGHT_E_NRPN);
	InitParameter(GLOBAL_ACCENT_NOTE_LIGHT_F_NRPN);
	InitParameter(GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_NRPN);
	InitParameter(GLOBAL_ACCENT_NOTE_LIGHT_G_NRPN);
	InitParameter(GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_NRPN);
	InitParameter(GLOBAL_ACCENT_NOTE_LIGHT_A_NRPN);
	InitParameter(GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_NRPN);
	InitParameter(GLOBAL_ACCENT_NOTE_LIGHT_B_NRPN);
	InitParameter(GLOBAL_ROW_OFFSET_NRPN);
	InitParameter(GLOBAL_VELOCITY_SENSITIVITY_NRPN);
	InitParameter(GLOBAL_PRESSURE_SENSITIVITY_NRPN);
	InitParameter(GLOBAL_MIDI_DEVICE_IO_NRPN);
	InitParameter(GLOBAL_ARP_DIRECTION_NRPN);
	InitParameter(GLOBAL_ARP_TEMPO_NOTE_VALUE_NRPN);
	InitParameter(GLOBAL_ARP_OCTAVE_EXTENSION_NRPN);
	InitParameter(GLOBAL_CLOCK_BPM_NRPN);
	InitParameter(GLOBAL_SETTINGS_PRESET_LOAD_NRPN);
	InitParameter(GLOBAL_PRESSURE_AFTERTOUCH_NRPN);
	InitParameter(DEVICE_USER_FIRMWARE_MODE_NRPN);
	InitParameter(DEVICE_LEFT_HANDED_NRPN);
	InitParameter(GLOBAL_ACTIVE_LIGHTS_PRESET_NRPN);
	InitParameter(GLOBAL_MIN_VELOCITY_VALUE_NRPN);
	InitParameter(GLOBAL_MAX_VELOCITY_VALUE_NRPN);
	InitParameter(GLOBAL_FIXED_VELOCITY_VALUE_NRPN);
	InitParameter(DEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN);
	InitParameter(GLOBAL_CUSTOM_ROW_OFFSET_NRPN);
	InitParameter(DEVICE_MIDI_THRU_NRPN);
	InitParameter(GLOBAL_GUITAR_NOTE_TUNING_ROW1_NRPN);
	InitParameter(GLOBAL_GUITAR_NOTE_TUNING_ROW2_NRPN);
	InitParameter(GLOBAL_GUITAR_NOTE_TUNING_ROW3_NRPN);
	InitParameter(GLOBAL_GUITAR_NOTE_TUNING_ROW4_NRPN);
	InitParameter(GLOBAL_GUITAR_NOTE_TUNING_ROW5_NRPN);
	InitParameter(GLOBAL_GUITAR_NOTE_TUNING_ROW6_NRPN);
	InitParameter(GLOBAL_GUITAR_NOTE_TUNING_ROW7_NRPN);
	InitParameter(GLOBAL_GUITAR_NOTE_TUNING_ROW8_NRPN);
}


void LinnStrument::QueryOctaveTransposeSettings()
{
	InitParameter(SPLIT_LEFT_OCTAVE_NRPN);
	InitParameter(SPLIT_LEFT_PITCH_TRANSPOSE_NRPN);
	InitParameter(SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN);
	InitParameter(SPLIT_RIGHT_OCTAVE_NRPN);
	InitParameter(SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN);
	InitParameter(SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN);
}


void LinnStrument::QuerySwitchSettings()
{
	InitParameter(SWITCH1_ASSIGN_NRPN);
	InitParameter(SWITCH2_ASSIGN_NRPN);
	InitParameter(FOOT_LEFT_ASSIGN_NRPN);
	InitParameter(FOOT_RIGHT_ASSIGN_NRPN);
	InitParameter(SWITCH1_BOTH_SPLITS_NRPN);
	InitParameter(SWITCH2_BOTH_SPLITS_NRPN);
	InitParameter(FOOT_LEFT_BOTH_SPLITS_NRPN);
	InitParameter(FOOT_RIGHT_BOTH_SPLITS_NRPN);
	// InitParameter( CC_FOR_CC65);  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
	InitParameter(CC_FOR_LEFT_FOOT_CC65);
	InitParameter(CC_FOR_RIGHT_FOOT_CC65);
	InitParameter(CC_FOR_SWITCH1_CC65);
	InitParameter(CC_FOR_SWITCH2_CC65);
	InitParameter(CC_FOR_LEFT_FOOT_SUSTAIN);
	InitParameter(CC_FOR_RIGHT_FOOT_SUSTAIN);
	InitParameter(CC_FOR_SWITCH1_SUSTAIN);
	InitParameter(CC_FOR_SWITCH2_SUSTAIN);
}

void LinnStrument::SetTimeOut(unsigned int nTimeOut)
{
	m_TimeOut = nTimeOut;
}

unsigned int LinnStrument::GetTimeOut()
{
	return m_TimeOut;
}
