// LinnStrument.h

#pragma once

#include <RtMidi.h>
#include <wx/string.h>

#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

#ifdef __WINDOWS__
#define _ATL_APARTMENT_THREADED
#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override something,
//but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>
#include <sapi.h>
#include <Windows.h>
#include <wx/msw/winundef.h> 

#include "enumser.h"
#endif

#include "MIDIDialog.h"
#include "MIDI.h"
#include "LSEnums.h"
#include "LSConsts.h"

#define DBOUT( s )            \
{                             \
   std::wostringstream os_;    \
   os_ << s;                   \
   OutputDebugStringW( os_.str().c_str() );  \
}

// Custom events
wxDECLARE_EVENT(NoteEvent, wxCommandEvent);
wxDECLARE_EVENT(MIDIErrorEvent, wxCommandEvent);

class LinnStrument
{
public:
	LinnStrument();
		LinnStrument(wxWindow * parent, int nInputID, int nOutputID, bool blnSpeakMessages, bool blnSpeakNotes);
	~LinnStrument();

	wxWindow * GetParent();
	void SetParent(wxWindow * parent);
	
	// Options for MIDI I/O
	int GetMIDIInID();
	void SetMIDIInID(int nID);
	int GetMIDIOutID();
	void SetMIDIOutID(int nID);
	void InitMIDI( int nMIDIIn, int nMIDIOut);
	void SetTimeOut(unsigned int nTimeOut);
	unsigned int GetTimeOut();
		bool IsDINWorking();
	
	// Options to use speech output
	bool GetSpeakMessages();
	void SetSpeakMessages(bool blnSpeakNotes);
	bool GetSpeakNotes();
	void SetSpeakNotes(bool blnSpeakNotes);

	static unsigned int LSArpTempoNoteTypeToInt( unsigned int nLSArpTempoNoteType)
	{
		switch (nLSArpTempoNoteType)
		{
		case 1:
		{
			return 0;
		}
		break;

		case 2:
		{
			return 1;
		}
		break;

		case 3:
		{
			return 2;
		}
		break;

		case 4:
		{
			return 3;
		}
		break;

		case 5:
		{
			return 4;
		}
		break;

		case 6:
		{
			return 5;
		}
		break;

		case 7:
		{
			return 6;
		}
		break;

		default:
		{
			return 1;  // 8th note
		}
		break;
			   		}  // end switch
	}


	static unsigned int IntToLSArpTempoNoteType( unsigned int nInt)
	{
		switch (nInt)
		{
		case 0:
		{
			return 1;
		}
		break;

		case 1:
		{
			return 2;
		}
		break;

		case 2:
		{
			return 3;
		}
		break;

				case 3:
		{
			return 4;
		}
		break;

		case 4:
		{
			return 5;
		}
		break;

		case 5:
		{
			return 6;
		}
		break;
				
		case 6:
		{
			return 7;
		}
		break;

		default:
		{
			return 1;
		}
		break;
		}   // end switch
			}


	static unsigned int LSRowOffsetTypeToInt(unsigned int nLSRowOffsetType)
	{
// Useful for converting an LSRowOffsetType to a control index
		switch (nLSRowOffsetType)
		{
		case 0:
		{
			return 0;
		}
		break;

		case 3:
		{
			return 1;
		}
		break;

		case 4:
		{
			return 2;
		}
		break;

		case 5:
		{
			return 3;
		}
		break;

		case 6:
		{
			return 4;
		}
		break;

		case 7:
		{
			return 5;
		}
		break;

		case 12:
		{
			return 6;
		}
		break;

		case 13:
		{
			return 7;
		}
		break;

		case 127:
		{
			return 8;
		}
		break;

		default:
		{
			return 4;
		}
		break;
		}  // end switch
	}

	static unsigned int IntToLSRowOffsetType(unsigned int nInt)
	{
		// Useful for setting the value of an LSRowOffsetType from a control index
		switch (nInt)
		{
		case 0:
		{
			return 0;
		}
		break;

		case 1:
		{
			return 3;
		}
		break;

		case 2:
		{
			return 4;
		}
		break;

		case 3:
		{
			return 5;
		}
		break;

		case 4:
		{
			return 6;
		}
		break;

		case 5:
		{
			return 7;
		}
		break;

		case 6:
		{
			return 12;
		}
		break;

		case 7:
		{
			return 13;
		}
		break;

		case 8:
		{
			return 127;
		}
		break;

		default:
		{
			return 4;  // Default LinnStrument tuning
		}
		break;
		}  // end switch
		}

			static bool LSToggle(unsigned int nValue)
	{
		if (nValue == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	static unsigned int LSToggle(bool blnValue)
	{
		if (blnValue)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int GetUSBInPortID();
	int GetUSBOutPortID();
	bool IsUpdateMode();
	void ProcessMessage(std::vector <unsigned char> vBytes);

				void QueryNRPN( unsigned int nParameterNumber);
		void QueryLeftSplitSettings();
		void QueryRightSplitSettings();
		void QueryGlobalSettings();
		void QuerySwitchSettings();
		void QueryOctaveTransposeSettings();
		void QueryAll();

			// Per-split settings
	unsigned int GetSPLIT_MODE(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_SPLIT_MODE;
		}
		else
		{
			return m_RIGHT_SPLIT_MODE;
		}
	}


	unsigned int GetMIDI_MAIN_CHANNEL(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_MIDI_MAIN_CHANNEL;
		}
		else
		{
			return m_RIGHT_MIDI_MAIN_CHANNEL;
		}
	}


	void SetSPLIT_MODE(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_SPLIT_MODE = nValue;
		}
		else
		{
			m_RIGHT_SPLIT_MODE = nValue;
		}
	}


	void SetMIDI_MAIN_CHANNEL(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_MIDI_MAIN_CHANNEL = nValue;
		}
		else
		{
			m_RIGHT_MIDI_MAIN_CHANNEL = nValue;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_1(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_1;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_1;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_2(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_2;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_2;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_3(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_3;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_3;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_4(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_4;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_4;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_5(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_5;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_5;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_6(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_6;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_6;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_7(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_7;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_7;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_8(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_8;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_8;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_9(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_9;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_9;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_10(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_10;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_10;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_11(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_11;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_11;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_12(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_12;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_12;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_13(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_13;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_13;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_14(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_14;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_14;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_15(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_15;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_15;
		}
	}


	unsigned int GetCHANNEL_PER_NOTE_16(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_NOTE_16;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_NOTE_16;
		}
	}


	// Value is a MIDI channel number:
	unsigned int GetMIDI_PER_ROW_LOWEST_CHANNEL(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL;
		}
		else
		{
			return m_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL;
		}
	}


	// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
	unsigned int GetBEND_RANGE(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_BEND_RANGE;
		}
		else
		{
			return m_RIGHT_BEND_RANGE;
		}
	}


	// Toggles:
	unsigned int GetBEND_TOGGLE(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_BEND_TOGGLE;
		}
		else
		{
			return m_RIGHT_BEND_TOGGLE;
		}
	}


	unsigned int GetBEND_QUANTIZE_TOGGLE(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_BEND_QUANTIZE_TOGGLE;
		}
		else
		{
			return m_RIGHT_BEND_QUANTIZE_TOGGLE;
		}
	}


	// Value is from LSPitchQuantize
	unsigned int GetBEND_QUANTIZE(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_PITCH_QUANTIZE;
		}
		else
		{
			return m_RIGHT_PITCH_QUANTIZE;
		}
	}


	// Toggles:
	unsigned int GetRESET_PITCH_ON_RELEASE(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_RESET_PITCH_ON_RELEASE;
		}
		else
		{
			return m_RIGHT_RESET_PITCH_ON_RELEASE;
		}
	}


	unsigned int GetSEND_Y(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_SEND_Y;
		}
		else
		{
			return m_RIGHT_SEND_Y;
		}
	}


	unsigned int GetSEND_Z(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_SEND_Z;
		}
		else
		{
			return m_RIGHT_SEND_Z;
		}
	}


	// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	unsigned int GetCC_FOR_Y(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_Y;
		}
		else
		{
			return m_RIGHT_CC_FOR_Y;
		}
	}


	// Toggle:
	unsigned int GetRELATIVE_Y(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_RELATIVE_Y;
		}
		else
		{
			return m_RIGHT_RELATIVE_Y;
		}
	}


	/*
	unsigned int GetRELATIVE_Z(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_RELATIVE_Z;
		}
		else
		{
			return m_RIGHT_RELATIVE_Z;
		}
	}
	*/

	// Value is an LSExpressionZ
	unsigned int GetEXPRESSION_FOR_Z(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_EXPRESSION_FOR_Z;
		}
		else
		{
			return m_RIGHT_EXPRESSION_FOR_Z;
		}
	}


	// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
	unsigned int GetCC_FOR_Z(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_Z;
		}
		else
		{
			return m_RIGHT_CC_FOR_Z;
		}
	}


	// Values are defined in LSColor
	unsigned int GetCOLOR_MAIN(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_COLOR_MAIN;
		}
		else
		{
			return m_RIGHT_COLOR_MAIN;
		}
	}


	unsigned int GetCOLOR_ACCENT(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_COLOR_ACCENT;
		}
		else
		{
			return m_RIGHT_COLOR_ACCENT;
		}
	}


	unsigned int GetCOLOR_PLAYED(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_COLOR_PLAYED;
		}
		else
		{
			return m_RIGHT_COLOR_PLAYED;
		}
	}


	unsigned int GetCOLOR_LOWROW(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_COLOR_LOWROW;
		}
		else
		{
			return m_RIGHT_COLOR_LOWROW;
		}
	}


	// Value is an LSLowRowMode
	unsigned int GetLOWROW_MODE(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_LOWROW_MODE;
		}
		else
		{
			return m_RIGHT_LOWROW_MODE;
		}
	}


	// Value is an LSSpecial:
	unsigned int GetSPECIAL(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_SPECIAL;
		}
		else
		{
			return m_RIGHT_SPECIAL;
		}
	}


	// Value is an LSOctave
	unsigned int GetOCTAVE(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_OCTAVE;
		}
		else
		{
			return m_RIGHT_OCTAVE;
		}
	}


	// Values are from LSPitch
	unsigned int GetPITCH_TRANSPOSE(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_PITCH_TRANSPOSE;
		}
		else
		{
			return m_RIGHT_PITCH_TRANSPOSE;
		}
	}


	unsigned int GetTRANSPOSE_LIGHTS(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_TRANSPOSE_LIGHTS;
		}
		else
		{
			return m_RIGHT_TRANSPOSE_LIGHTS;
		}
	}


	// Value is an LSExpressionY
	unsigned int GetEXPRESSION_FOR_Y(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_EXPRESSION_FOR_Y;
		}
		else
		{
			return m_RIGHT_EXPRESSION_FOR_Y;
		}
	}


	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int GetCC_FOR_FADER1(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_FADER1;
		}
		else
		{
			return m_RIGHT_CC_FOR_FADER1;
		}
	}


	unsigned int GetCC_FOR_FADER2(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_FADER2;
		}
		else
		{
			return m_RIGHT_CC_FOR_FADER2;
		}
	}


	unsigned int GetCC_FOR_FADER3(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_FADER3;
		}
		else
		{
			return m_RIGHT_CC_FOR_FADER3;
		}
	}


	unsigned int GetCC_FOR_FADER4(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_FADER4;
		}
		else
		{
			return m_RIGHT_CC_FOR_FADER4;
		}
	}


	unsigned int GetCC_FOR_FADER5(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_FADER5;
		}
		else
		{
			return m_RIGHT_CC_FOR_FADER5;
		}
	}


	unsigned int GetCC_FOR_FADER6(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_FADER6;
		}
		else
		{
			return m_RIGHT_CC_FOR_FADER6;
		}
	}


	unsigned int GetCC_FOR_FADER7(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_FADER7;
		}
		else
		{
			return m_RIGHT_CC_FOR_FADER7;
		}
	}


	unsigned int GetCC_FOR_FADER8(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_FADER8;
		}
		else
		{
			return m_RIGHT_CC_FOR_FADER8;
		}
	}


	// Value is an LSLowRowBehaviour
	unsigned int GetLOWROW_X_BEHAVIOUR(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_LOWROW_X_BEHAVIOUR;
		}
		else
		{
			return m_LEFT_LOWROW_X_BEHAVIOUR;
		}
	}


	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int GetCC_FOR_LOWROW(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_LOWROW;
		}
		else
		{
			return m_RIGHT_CC_FOR_LOWROW;
		}
	}


	// Value is an LSLowRowBehaviour
	unsigned int GetLOWROW_XYZ_BEHAVIOUR(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_LOWROW_XYZ_BEHAVIOUR;
		}
		else
		{
			return m_RIGHT_LOWROW_XYZ_BEHAVIOUR;
		}
	}


	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int GetCC_FOR_LOWROW_XYZ(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_LOWROW_XYZ;
		}
		else
		{
			return m_RIGHT_CC_FOR_LOWROW_XYZ;
		}
	}


	unsigned int GetCC_FOR_LOWROW_XYZ_Y(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CC_FOR_LOWROW_XYZ_Y;
		}
		else
		{
			return m_RIGHT_CC_FOR_LOWROW_XYZ_Y;
		}
	}


	unsigned int GetCC_FOR_LOWROW_XYZ_Z(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{

			return m_LEFT_CC_FOR_LOWROW_XYZ_Z;
		}
		else
		{
			return m_RIGHT_CC_FOR_LOWROW_XYZ_Z;
		}
	}


	// Values are constrained by MIN_CC and MAX_CC
	unsigned int GetMIN_CC_FOR_Y(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_MIN_CC_FOR_Y;
		}
		else
		{
			return m_RIGHT_MIN_CC_FOR_Y;
		}
	}


	unsigned int GetMAX_CC_FOR_Y(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_MAX_CC_FOR_Y;
		}
		else
		{
			return m_RIGHT_MAX_CC_FOR_Y;
		}
	}


	unsigned int GetMIN_CC_FOR_Z(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_MIN_CC_FOR_Z;
		}
		else
		{
			return m_RIGHT_MIN_CC_FOR_Z;
		}
	}


	unsigned int GetMAX_CC_FOR_Z(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_MAX_CC_FOR_Z;
		}
		else
		{
			return m_RIGHT_MAX_CC_FOR_Z;
		}
	}


	unsigned int Get14BIT_CC_VALUE_FOR_Z(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_14BIT_CC_VALUE_FOR_Z;
		}
		else
		{
			return m_RIGHT_14BIT_CC_VALUE_FOR_Z;
		}
	}


	unsigned int GetINITIAL_RELATIVE_VALUE_FOR_Y(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y;
		}
		else
		{
			return m_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y;
		}
	}


	// Value is an LSChannelOrder
	unsigned int GetCHANNEL_PER_ROW_ORDER(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_CHANNEL_PER_ROW_ORDER;
		}
		else
		{
			return m_RIGHT_CHANNEL_PER_ROW_ORDER;
		}
	}


	// Value is an LSAnimation
	unsigned int GetTOUCH_ANIMATION(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_TOUCH_ANIMATION;
		}
		else
		{
			return m_RIGHT_TOUCH_ANIMATION;
		}
	}


		// Toggle:
	bool GetSEQUENCER_TOGGLE_PLAY(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return LSToggle( m_LEFT_SEQUENCER_TOGGLE_PLAY);
		}
		else
		{
			return LSToggle( m_RIGHT_SEQUENCER_TOGGLE_PLAY);
		}
	}
	

/*
Can't query this parameter currently:
unsigned int GetSEQUENCER_PREVIOUS_PATTERN(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_SEQUENCER_PREVIOUS_PATTERN;
		}
		else
		{
			return m_RIGHT_SEQUENCER_PREVIOUS_PATTERN;
		}
	}
*/


/*
Can't query this parameter currently:
unsigned int GetSEQUENCER_NEXT_PATTERN(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_SEQUENCER_NEXT_PATTERN;
		}
		else
		{
			return m_RIGHT_SEQUENCER_NEXT_PATTERN;
		}
	}
*/

		// Value is an LSPatternNumber
	unsigned int GetSEQUENCER_PATTERN(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_SEQUENCER_PATTERN;
		}
		else
		{
			return m_RIGHT_SEQUENCER_PATTERN;
		}
	}


bool GetSEQUENCER_TOGGLE_MUTE(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return LSToggle( m_LEFT_SEQUENCER_TOGGLE_MUTE);
		}
		else
		{
			return LSToggle( m_RIGHT_SEQUENCER_TOGGLE_MUTE);
		}
	}

		// Setters:

	// Toggles:
	void SetCHANNEL_PER_NOTE_1(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_1 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_1 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_2(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_2 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_2 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_3(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_3 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_3 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_4(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_4 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_4 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_5(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_5 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_5 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_6(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_6 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_6 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_7(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_7 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_7 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_8(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_8 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_8 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_9(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_9 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_9 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_10(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_10 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_10 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_11(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_11 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_11 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_12(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_12 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_12 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_13(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_13 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_13 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_14(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_14 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_14 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_15(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_15 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_15 = nValue;
		}
	}


	void SetCHANNEL_PER_NOTE_16(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CHANNEL_PER_NOTE_16 = nValue;
		}
		else
		{
			m_RIGHT_CHANNEL_PER_NOTE_16 = nValue;
		}
	}


	// Value is a MIDI channel number:
	void SetMIDI_PER_ROW_LOWEST_CHANNEL(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL = nValue;
		}
		else
		{
			m_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL = nValue;
		}
	}


	// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
	void SetBEND_RANGE(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_BEND_RANGE = nValue;
		}
		else
		{
			m_RIGHT_BEND_RANGE = nValue;
		}
	}


	// Toggles:
	void SetBEND_TOGGLE(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_BEND_TOGGLE = nValue;
		}
		else
		{
			m_RIGHT_BEND_TOGGLE = nValue;
		}
	}


	void SetBEND_QUANTIZE_TOGGLE(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_BEND_QUANTIZE_TOGGLE = nValue;
		}
		else
		{
			m_RIGHT_BEND_QUANTIZE_TOGGLE = nValue;
		}
	}


	// Value is from LSPitchQuantize
	void SetBEND_QUANTIZE(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_PITCH_QUANTIZE = nValue;
		}
		else
		{
			m_RIGHT_PITCH_QUANTIZE = nValue;
		}
	}


	// Toggles:
	void SetRESET_PITCH_ON_RELEASE(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_RESET_PITCH_ON_RELEASE = nValue;
		}
		else
		{
			m_RIGHT_RESET_PITCH_ON_RELEASE = nValue;
		}
	}


	void SetSEND_Y(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_SEND_Y = nValue;
		}
		else
		{
			m_RIGHT_SEND_Y = nValue;
		}
	}


	// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	void SetCC_FOR_Y(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_Y = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_Y = nValue;
		}
	}


	void SetSEND_Z(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_SEND_Z = nValue;
		}
		else
		{
			m_RIGHT_SEND_Z = nValue;
		}
	}


	// Toggle:
	void SetRELATIVE_Y(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_RELATIVE_Y = nValue;
		}
		else
		{
			m_RIGHT_RELATIVE_Y = nValue;
		}
	}


	/*
	void SetRELATIVE_Z(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_RELATIVE_Z = nValue;
		}
		else
		{
			m_RIGHT_RELATIVE_Z = nValue;
		}
	}
*/


	// Value is an LSExpressionZ
	void SetMIDI_EXPRESSION_FOR_Z(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_EXPRESSION_FOR_Z = nValue;
		}
		else
		{
			m_RIGHT_EXPRESSION_FOR_Z = nValue;
		}
	}


	// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
	void SetCC_FOR_Z(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_Z = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_Z = nValue;
		}
	}


	// Values are defined in LSColor
	void SetCOLOR_MAIN(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_COLOR_MAIN = nValue;
		}
		else
		{
			m_RIGHT_COLOR_MAIN = nValue;
		}
	}


	void SetCOLOR_ACCENT(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_COLOR_ACCENT = nValue;
		}
		else
		{
			m_RIGHT_COLOR_ACCENT = nValue;
		}
	}


	void SetCOLOR_PLAYED(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_COLOR_PLAYED = nValue;
		}
		else
		{
			m_RIGHT_COLOR_PLAYED = nValue;
		}
	}


	void SetCOLOR_LOWROW(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_COLOR_LOWROW = nValue;
		}
		else
		{
			m_RIGHT_COLOR_LOWROW = nValue;
		}
	}


	// Value is an LSLowRowMode
	void SetLOWROW_MODE(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_LOWROW_MODE = nValue;
		}
		else
		{
			m_RIGHT_LOWROW_MODE = nValue;
		}
	}


	// Value is an LSSpecial:
	void SetSPECIAL(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_SPECIAL = nValue;
		}
		else
		{
			m_RIGHT_SPECIAL = nValue;
		}
	}


	// Value is an LSOctave
	void SetOCTAVE(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_OCTAVE = nValue;
		}
		else
		{
			m_RIGHT_OCTAVE = nValue;
		}
	}


	// Values are from LSPitch
	void SetPITCH_TRANSPOSE(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_PITCH_TRANSPOSE = nValue;
		}
		else
		{
			m_RIGHT_PITCH_TRANSPOSE = nValue;
		}
	}


	void SetTRANSPOSE_LIGHTS(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_TRANSPOSE_LIGHTS = nValue;
		}
		else
		{
			m_RIGHT_TRANSPOSE_LIGHTS = nValue;
		}
	}


	// Value is an LSExpressionY
	void SetEXPRESSION_FOR_Y(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_EXPRESSION_FOR_Y = nValue;
		}
		else
		{
			m_RIGHT_EXPRESSION_FOR_Y = nValue;
		}
	}


	void SetEXPRESSION_FOR_Z(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_EXPRESSION_FOR_Z = nValue;
		}
		else
		{
			m_RIGHT_EXPRESSION_FOR_Z = nValue;;
		}
	}


	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	void SetCC_FOR_FADER1(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_FADER1 = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_FADER1 = nValue;
		}
	}


	void SetCC_FOR_FADER2(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_FADER2 = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_FADER2 = nValue;
		}
	}


	void SetCC_FOR_FADER3(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_FADER3 = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_FADER3 = nValue;
		}
	}


	void SetCC_FOR_FADER4(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_FADER4 = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_FADER4 = nValue;
		}
	}


	void SetCC_FOR_FADER5(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_FADER5 = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_FADER5 = nValue;
		}
	}


	void SetCC_FOR_FADER6(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_FADER6 = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_FADER6 = nValue;
		}
	}


	void SetCC_FOR_FADER7(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_FADER7 = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_FADER7 = nValue;
		}
	}


	void SetCC_FOR_FADER8(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_FADER8 = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_FADER8 = nValue;
		}
	}


	// Value is an LSLowRowBehaviour
	void SetLOWROW_X_BEHAVIOUR(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_LOWROW_X_BEHAVIOUR = nValue;
		}
		else
		{
			m_RIGHT_LOWROW_X_BEHAVIOUR = nValue;
		}
	}


	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	void SetCC_FOR_LOWROW(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_LOWROW = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_LOWROW = nValue;
		}
	}


	// Value is an LSLowRowBehaviour
	void SetLOWROW_XYZ_BEHAVIOUR(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_LOWROW_XYZ_BEHAVIOUR = nValue;
		}
		else
		{
			m_RIGHT_LOWROW_XYZ_BEHAVIOUR = nValue;
		}
	}


	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	void SetCC_FOR_LOWROW_XYZ(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_LOWROW_XYZ = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_LOWROW_XYZ = nValue;
		}
	}


	void SetCC_FOR_LOWROW_XYZ_Y(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_LOWROW_XYZ_Y = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_LOWROW_XYZ_Y = nValue;
		}
	}


	void SetCC_FOR_LOWROW_XYZ_Z(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_CC_FOR_LOWROW_XYZ_Z = nValue;
		}
		else
		{
			m_RIGHT_CC_FOR_LOWROW_XYZ_Z = nValue;
		}
	}


	// Values are constrained by MIN_CC and MAX_CC
	void SetMIN_CC_FOR_Y(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_MIN_CC_FOR_Y = nValue;
		}
		else
		{
			m_RIGHT_MIN_CC_FOR_Y = nValue;
		}
	}


	void SetMAX_CC_FOR_Y(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_MAX_CC_FOR_Y = nValue;
		}
		else
		{
			m_RIGHT_MAX_CC_FOR_Y = nValue;
		}
	}


	void SetMIN_CC_FOR_Z(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_MIN_CC_FOR_Z = nValue;
		}
		else
		{
			m_RIGHT_MIN_CC_FOR_Z = nValue;
		}
	}


	void SetMAX_CC_FOR_Z(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_MAX_CC_FOR_Z = nValue;
		}
		else
		{
			m_RIGHT_MAX_CC_FOR_Z = nValue;
		}
	}


	void Set14BIT_CC_VALUE_FOR_Z(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_14BIT_CC_VALUE_FOR_Z = nValue;
		}
		else
		{
			m_RIGHT_14BIT_CC_VALUE_FOR_Z = nValue;
		}
	}


	void SetINITIAL_RELATIVE_VALUE_FOR_Y(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y = nValue;
		}
		else
		{
			m_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y = nValue;
		}
	}


	// Value is an LSChannelOrder
	void SetCHANNEL_PER_ROW_ORDER(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y = nValue; m_LEFT_CHANNEL_PER_ROW_ORDER = nValue;
		}
		else
		{
			m_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y = nValue; m_LEFT_CHANNEL_PER_ROW_ORDER = nValue;
		}
	}


	// Value is an LSAnimation
	void SetTOUCH_ANIMATION(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_TOUCH_ANIMATION = nValue;
		}
		else
		{
			m_RIGHT_TOUCH_ANIMATION = nValue;
		}
	}


	// Toggle:
			void SetSEQUENCER_TOGGLE_PLAY(unsigned int nValue, LSSplitType split)
							   {
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_SEQUENCER_TOGGLE_PLAY = nValue;
		}
		else
		{
			m_RIGHT_SEQUENCER_TOGGLE_PLAY = nValue;
		}
	}


	void SetSEQUENCER_PREVIOUS_PATTERN(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_SEQUENCER_PREVIOUS_PATTERN = nValue;
		}
		else
		{
			m_RIGHT_SEQUENCER_PREVIOUS_PATTERN = nValue;
		}
	}


	void SetSEQUENCER_NEXT_PATTERN(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_SEQUENCER_NEXT_PATTERN = nValue;
		}
		else
		{
			m_RIGHT_SEQUENCER_NEXT_PATTERN = nValue;
		}
	}


	// Value is an LSPatternNumber
	void SetSEQUENCER_PATTERN(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_SEQUENCER_PATTERN = nValue;
		}
		else
		{
			m_RIGHT_SEQUENCER_PATTERN = nValue;
		}
	}


	void SetSEQUENCER_TOGGLE_MUTE(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_SEQUENCER_TOGGLE_MUTE = nValue;
		}
		else
		{
			m_RIGHT_SEQUENCER_TOGGLE_MUTE = nValue;
		}
	}

	// Foot and panel switches
	// Value is LSSwitchAssignment
	unsigned int GetSWITCH1_ASSIGN()
	{
		return m_SWITCH1_ASSIGN;
	}

	void SetSWITCH1_ASSIGN(unsigned int nValue)
	{
		m_SWITCH1_ASSIGN = nValue;
	}

	unsigned int GetSWITCH2_ASSIGN()
	{
		return m_SWITCH2_ASSIGN;
	}

	void SetSWITCH2_ASSIGN(unsigned int nValue)
	{
		m_SWITCH2_ASSIGN = nValue;
	}

	unsigned int GetFOOT_LEFT_ASSIGN()
	{
		return m_FOOT_LEFT_ASSIGN;
	}

	void SetFOOT_LEFT_ASSIGN(unsigned int nValue)
	{
		m_FOOT_LEFT_ASSIGN = nValue;
	}

	unsigned int GetFOOT_RIGHT_ASSIGN()
	{
		return m_FOOT_RIGHT_ASSIGN;
	}

	void SetFOOT_RIGHT_ASSIGN(unsigned int nValue)
	{
		m_FOOT_RIGHT_ASSIGN = nValue;
	}

	unsigned int GetSWITCH1_BOTH_SPLITS()
	{
		return m_SWITCH1_BOTH_SPLITS;
	}

	void SetSWITCH1_BOTH_SPLITS(unsigned int nValue)
	{
		m_SWITCH1_BOTH_SPLITS = nValue;
	}

	unsigned int GetSWITCH2_BOTH_SPLITS()
	{
		return m_SWITCH2_BOTH_SPLITS;
	}

	void SetSWITCH2_BOTH_SPLITS(unsigned int nValue)
	{
		m_SWITCH2_BOTH_SPLITS = nValue;
	}


	unsigned int GetFOOT_LEFT_BOTH_SPLITS()
	{
		return m_FOOT_LEFT_BOTH_SPLITS;
	}

	void SetFOOT_LEFT_BOTH_SPLITS(unsigned int nValue)
	{
		m_FOOT_LEFT_BOTH_SPLITS = nValue;
	}

	unsigned int GetFOOT_RIGHT_BOTH_SPLITS()
	{
		return m_FOOT_RIGHT_BOTH_SPLITS;
	}

	void SetFOOT_RIGHT_BOTH_SPLITS(unsigned int nValue)
	{
		m_FOOT_RIGHT_BOTH_SPLITS = nValue;
	}

	// Values are constrained by MIN_CC and MAX_CC
	unsigned int GetCC_FOR_LEFT_FOOT_CC65()
	{
		return m_CC_FOR_LEFT_FOOT_CC65;
	}

	void SetCC_FOR_LEFT_FOOT_CC65(unsigned int nValue)
	{
		m_CC_FOR_LEFT_FOOT_CC65 = nValue;
	}

	unsigned int GetCC_FOR_RIGHT_FOOT_CC65()
	{
		return m_CC_FOR_RIGHT_FOOT_CC65;
	}

	void SetCC_FOR_RIGHT_FOOT_CC65(unsigned int nValue)
	{
		m_CC_FOR_RIGHT_FOOT_CC65 = nValue;
	}

	unsigned int GetCC_FOR_SWITCH1_CC65()
	{
		return m_CC_FOR_SWITCH1_CC65;
	}

	void SetCC_FOR_SWITCH1_CC65(unsigned int nValue)
	{
		m_CC_FOR_SWITCH1_CC65 = nValue;
	}

	unsigned int GetCC_FOR_SWITCH2_CC65()
	{
		return m_CC_FOR_SWITCH2_CC65;
	}

	void SetCC_FOR_SWITCH2_CC65(unsigned int nValue)
	{
		m_CC_FOR_SWITCH2_CC65 = nValue;
	}

	unsigned int GetCC_FOR_LEFT_FOOT_SUSTAIN()
	{
		return m_CC_FOR_LEFT_FOOT_SUSTAIN;
	}

	void SetCC_FOR_LEFT_FOOT_SUSTAIN(unsigned int nValue)
	{
		m_CC_FOR_LEFT_FOOT_SUSTAIN = nValue;
	}

	unsigned int GetCC_FOR_RIGHT_FOOT_SUSTAIN()
	{
		return m_CC_FOR_RIGHT_FOOT_SUSTAIN;
	}

	void SetCC_FOR_RIGHT_FOOT_SUSTAIN(unsigned int nValue)
	{
		m_CC_FOR_RIGHT_FOOT_SUSTAIN = nValue;
	}

	unsigned int GetCC_FOR_SWITCH1_SUSTAIN()
	{
		return m_CC_FOR_SWITCH1_SUSTAIN;
	}

	void SetCC_FOR_SWITCH1_SUSTAIN(unsigned int nValue)
	{
		m_CC_FOR_SWITCH1_SUSTAIN = nValue;
	}

	unsigned int GetCC_FOR_SWITCH2_SUSTAIN()
	{
		return m_CC_FOR_SWITCH2_SUSTAIN;
	}

	void SetCC_FOR_SWITCH2_SUSTAIN(unsigned int nValue)
	{
		m_CC_FOR_SWITCH2_SUSTAIN = nValue;
	}

// Octave/transpose settings
	unsigned int GetOctave(LSSplitType split)
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

	void SetOctave(unsigned int nValue, LSSplitType split)
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

	// Global settings
	
	static LS_MIDIDevice GetLS_MIDIDeviceType(unsigned int nDevice)
	{
		switch (nDevice)
		{
		case 0:
		{
			return LS_MIDIDevice::MIDI_DIN_JACKS;
		}
		break;

		case 1:
		{
			return LS_MIDIDevice::USB;
		}
		break;

		default:
		{
			return LS_MIDIDevice::MIDI_DIN_JACKS;
		}
		break;
		}
	};

	static unsigned int GetLS_MIDIDeviceIndex(LS_MIDIDevice device)
	{
		switch (device)
		{
		case LS_MIDIDevice::MIDI_DIN_JACKS:
		{
			return 0;
			break;
		}
		case LS_MIDIDevice::USB:
		{
			return 1;
			break;
		}

		default:
		{
			return 1;
			break;
		}
		}
	};

	unsigned int GetGLOBAL_SPLIT_ACTIVE()
	{
		return m_GLOBAL_SPLIT_ACTIVE;
	}

	void SetGLOBAL_SPLIT_ACTIVE(unsigned int nValue)
	{
		m_GLOBAL_SPLIT_ACTIVE = nValue;
	}

	// Value is LSSplitType
	unsigned int GetGLOBAL_SELECTED_SPLIT()
	{
		return m_GLOBAL_SELECTED_SPLIT;
	}

	void SetGLOBAL_SELECTED_SPLIT(unsigned int nValue)
	{
		m_GLOBAL_SELECTED_SPLIT = nValue;
	}

	unsigned int GetLSPresetNumber()
	{
		return m_LSPresetNumber;
	}

	void SetLSPresetNumber(unsigned int nValue)
	{
		m_LSPresetNumber = nValue;
	};

	// Values are constrained by MIN_CC and MAX_CC
	unsigned int GetMIDIVolume(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_VOLUME;
		}
		else
		{
			return m_RIGHT_VOLUME;
		}
	}

	void SetMIDIVolume(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_VOLUME = nValue;
		}
		else
		{
			m_RIGHT_VOLUME = nValue;
		}
	}

	unsigned int GetMIDIProgram(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_PROGRAM;
		}
		else
		{
			return m_RIGHT_PROGRAM;
		}
	}

	void SetMIDIProgram(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_PROGRAM = nValue;
		}
		else
		{
			m_RIGHT_PROGRAM = nValue;
		}
	}

	// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
	unsigned int GetGLOBAL_SPLIT_COLUMN()
	{
		return m_GLOBAL_SPLIT_COLUMN;
	}

	void SetGLOBAL_SPLIT_COLUMN(unsigned int nValue)
	{
		m_GLOBAL_SPLIT_COLUMN = nValue;
	}

	// Toggles:

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_C()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_C;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_C_SHARP()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_C_SHARP;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_D()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_D;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_D_SHARP()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_D_SHARP;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_E()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_E;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_F()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_F;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_F_SHARP()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_F_SHARP;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_G()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_G;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_G_SHARP()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_G_SHARP;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_A()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_A;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_A_SHARP()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_A_SHARP;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_B()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_B;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_C(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_C = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_C_SHARP(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_C_SHARP = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_D(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_D = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_D_SHARP(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_D_SHARP = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_E(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_E = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_F(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_F = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_F_SHARP(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_F_SHARP = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_G(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_G = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_G_SHARP(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_G_SHARP = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_A(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_A = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_A_SHARP(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_A_SHARP = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_B(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_B = nValue;
	}


	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_C()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_C;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_D()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_D;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_E()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_E;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_F()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_F;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_G()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_G;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_A()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_A;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_B()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_B;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_C(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_C = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_D(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_D = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_E(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_E = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_F(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_F = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_G(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_G = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_A(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_A = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_B(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_B = nValue;
	}

	// Value is LSRowOffsetType
	unsigned int GetGLOBAL_ROW_OFFSET()
	{
		return m_GLOBAL_ROW_OFFSET;
	}

	void SetGLOBAL_ROW_OFFSET(unsigned int nValue)
	{
		m_GLOBAL_ROW_OFFSET = nValue;
	}

	// Value is LSVelocityRange
	unsigned int GetGLOBAL_VELOCITY_SENSITIVITY()
	{
		return m_GLOBAL_VELOCITY_SENSITIVITY;
	}

	void SetGLOBAL_VELOCITY_SENSITIVITY(unsigned int nValue)
	{
		m_GLOBAL_VELOCITY_SENSITIVITY = nValue;
	}

	// Value is LSPressureRange
	unsigned int GetGLOBAL_PRESSURE_SENSITIVITY()
	{
		return m_GLOBAL_PRESSURE_SENSITIVITY;
	}

	void SetGLOBAL_PRESSURE_SENSITIVITY(unsigned int nValue)
	{
		m_GLOBAL_PRESSURE_SENSITIVITY = nValue;
	}

	// Value is LSMIDIDevice
	unsigned int GetGLOBAL_MIDI_DEVICE_IO()
	{
		return m_GLOBAL_MIDI_DEVICE_IO;
	}

	void SetGLOBAL_MIDI_DEVICE_IO(unsigned int nValue)
	{
		m_GLOBAL_MIDI_DEVICE_IO = nValue;
	}

	// Value is LSArpDirection
	unsigned int GetGLOBAL_ARP_DIRECTION()
	{
		return m_GLOBAL_ARP_DIRECTION;
	}

	void SetGLOBAL_ARP_DIRECTION(unsigned int nValue)
	{
		m_GLOBAL_ARP_DIRECTION = nValue;
	}

	// Value is LSArpTempoNoteType
	unsigned int GetGLOBAL_ARP_TEMPO_NOTE_VALUE()
	{
		return m_GLOBAL_ARP_TEMPO_NOTE_VALUE;
	}

	void SetGLOBAL_ARP_TEMPO_NOTE_VALUE(unsigned int nValue)
	{
		m_GLOBAL_ARP_TEMPO_NOTE_VALUE = nValue;
	}

	// Value is LSGlobalArpOctaveExtension
	unsigned int GetGLOBAL_ARP_OCTAVE_EXTENSION()
	{
		return m_GLOBAL_ARP_OCTAVE_EXTENSION;
	}

	void SetGLOBAL_ARP_OCTAVE_EXTENSION(unsigned int nValue)
	{
		m_GLOBAL_ARP_OCTAVE_EXTENSION = nValue;
	}

	// Value = 1 - 360  (applies when receiving no MIDI clock)
	unsigned int GetGLOBAL_CLOCK_BPM()
	{
		return m_GLOBAL_CLOCK_BPM;
	}

	void SetGLOBAL_CLOCK_BPM(unsigned int nValue)
	{
		m_GLOBAL_CLOCK_BPM = nValue;
	}

	// Value is LSPresetNumber
	unsigned int GetGLOBAL_SETTINGS_PRESET_LOAD()
	{
		return m_GLOBAL_SETTINGS_PRESET_LOAD;
	}

	void SetGLOBAL_SETTINGS_PRESET_LOAD(unsigned int nValue)
	{
		m_GLOBAL_SETTINGS_PRESET_LOAD = nValue;
	}

	// Toggles:
	unsigned int GetGLOBAL_PRESSURE_AFTERTOUCH()
	{
		return m_GLOBAL_PRESSURE_AFTERTOUCH;
	}

	void SetGLOBAL_PRESSURE_AFTERTOUCH(unsigned int nValue)
	{
		m_GLOBAL_PRESSURE_AFTERTOUCH = nValue;
	}

	unsigned int GetDEVICE_USER_FIRMWARE_MODE()
	{
		return m_DEVICE_USER_FIRMWARE_MODE;
	}

	void SetDEVICE_USER_FIRMWARE_MODE(unsigned int nValue)
	{
		m_DEVICE_USER_FIRMWARE_MODE = nValue;
	}

	unsigned int GetDEVICE_LEFT_HANDED()
	{
		return m_DEVICE_LEFT_HANDED;
	}

	void SetDEVICE_LEFT_HANDED(unsigned int nValue)
	{
		m_DEVICE_LEFT_HANDED = nValue;
	}

	// Value is constrained by MIN_LIGHTS_PRESET and MAX_LIGHTS_PRESET 
	unsigned int GetGLOBAL_ACTIVE_LIGHTS_PRESET()
	{
		return m_GLOBAL_ACTIVE_LIGHTS_PRESET;
	}

	void SetGLOBAL_ACTIVE_LIGHTS_PRESET(unsigned int nValue)
	{
		m_GLOBAL_ACTIVE_LIGHTS_PRESET = nValue;
	}

	// Values are constrained by MIN_CC and MAX_CC
	unsigned int GetGLOBAL_MIN_VELOCITY_VALUE()
	{
		return m_GLOBAL_MIN_VELOCITY_VALUE;
	}

	void SetGLOBAL_MIN_VELOCITY_VALUE(unsigned int nValue)
	{
		m_GLOBAL_MIN_VELOCITY_VALUE = nValue;
	}

	unsigned int GetGLOBAL_MAX_VELOCITY_VALUE()
	{
		return m_GLOBAL_MAX_VELOCITY_VALUE;
	}

	void SetGLOBAL_MAX_VELOCITY_VALUE(unsigned int nValue)
	{
		m_GLOBAL_MAX_VELOCITY_VALUE = nValue;
	}

	unsigned int GetGLOBAL_FIXED_VELOCITY_VALUE()
	{
		return m_GLOBAL_FIXED_VELOCITY_VALUE;
	}

	void SetGLOBAL_FIXED_VELOCITY_VALUE(unsigned int nValue)
	{
		m_GLOBAL_FIXED_VELOCITY_VALUE = nValue;
	}

	// Value range =     0 - 512  
	unsigned int GetDEVICE_MIN_BYTE_INTERVAL_VALUE()
	{
		return m_DEVICE_MIN_BYTE_INTERVAL_VALUE;
	}

	void SetDEVICE_MIN_BYTE_INTERVAL_VALUE(unsigned int nValue)
	{
		m_DEVICE_MIN_BYTE_INTERVAL_VALUE = nValue;
	}

	// Value is LSCustomRowOffset
	unsigned int GetGLOBAL_CUSTOM_ROW_OFFSET()
	{
		return m_GLOBAL_CUSTOM_ROW_OFFSET;
	}

	void SetGLOBAL_CUSTOM_ROW_OFFSET(unsigned int nValue)
	{
		m_GLOBAL_CUSTOM_ROW_OFFSET = nValue;
	}

	// Toggle:
	unsigned int GetDEVICE_MIDI_THRU()
	{
		return m_DEVICE_MIDI_THRU;
	}

	void SetDEVICE_MIDI_THRU(unsigned int nValue)
	{
		m_DEVICE_MIDI_THRU = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW1()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW1;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW1(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW1 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW2()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW2;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW2(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW2 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW3()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW3;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW3(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW3 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW4()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW4;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW4(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW4 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW5()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW5;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW5(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW5 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW6()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW6;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW6(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW6 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW7()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW7;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW7(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW7 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW8()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW8;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW8(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW8 = nValue;
	}

void SendNRPN(unsigned int NRPNNumber, unsigned int NRPNValue);
	void SendNRPN(LSSplitType split, unsigned int NRPNNumber, unsigned int NRPNValue);
	void Speak(std::wstring wstrIn);

	private:
		void InitParameter(unsigned int nParameterNumber);
		void HandleMIDIError(std::string strError);
		void SendNRPN(unsigned char nChannelNibble, unsigned int NRPNNumber, unsigned int NRPNValue);
	void SetLSParameter( unsigned int NRPNParameterIn, unsigned int NRPNValueIn);
	void UpdateStatusBar();
	
	// data
	// Parent window
	wxWindow * m_Parent;

	// LinnStrument message tracking
			unsigned int m_NRPNParameterIn, m_NRPNValueIn;
	bool m_ReceivedNRPNValueMSB, m_ReceivedNRPNValueLSB;

// Query/response synchronization
	std::thread m_thread;
	std::mutex m_mtx;
	std::condition_variable m_cv;
		unsigned int m_parameter;

	// Track note information;
	bool m_NotesHeld[MAX_BYTE_VALUES];

// Application options
	bool m_SpeakMessages, m_SpeakNotes;

#ifdef __WINDOWS__
		CComPtr<ISpVoice> pSpeech;
#endif
		
		// Serial port detection
		bool m_CanDetectSerialPorts;
		
		// MIDI devices
		RtMidiIn * m_MIDIIn;
		RtMidiOut * m_MIDIOut;
		// MIDI port ID values;
		int m_InputID, m_OutputID;
		// Time-out for MIDI responses
		unsigned int m_TimeOut;

// Per-split settings
// Left split
		unsigned int m_LEFT_SPLIT_MODE;
		unsigned int m_LEFT_MIDI_MAIN_CHANNEL = 0;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_1;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_2;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_3;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_4;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_5;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_6;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_7;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_8;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_9;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_10;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_11;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_12;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_13;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_14;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_15;
		unsigned int m_LEFT_CHANNEL_PER_NOTE_16;
		// Value is a MIDI channel number:
		unsigned int m_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL;
		// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
		unsigned int m_LEFT_BEND_RANGE;
		// Toggles:
		unsigned int m_LEFT_BEND_TOGGLE;
		unsigned int m_LEFT_BEND_QUANTIZE_TOGGLE;
		// Value is from LSPitchQuantize
		unsigned int m_LEFT_PITCH_QUANTIZE;
		// Toggles:
		unsigned int m_LEFT_RESET_PITCH_ON_RELEASE;
		// Values are constrained by MIN_CC and MAX_CC
		// CC 1 or CC 74 are recommended, any CC is possible though
		unsigned int m_LEFT_CC_FOR_Y;
		// Toggle:
		unsigned int m_LEFT_RELATIVE_Y;
		unsigned int m_LEFT_RELATIVE_Z;
		// Value is an LSExpressionZ
		unsigned int m_LEFT_EXPRESSION_FOR_Z;
		// Values are constrained by MIN_CC and MAX_CC
		// CC 11 is recommended, any CC is possible though
		unsigned int m_LEFT_CC_FOR_Z;
		// Values are defined in LSColor
		unsigned int m_LEFT_COLOR_MAIN;
		unsigned int m_LEFT_COLOR_ACCENT;
		unsigned int m_LEFT_COLOR_PLAYED;
		unsigned int m_LEFT_COLOR_LOWROW;
		// Value is an LSLowRowMode
		unsigned int m_LEFT_LOWROW_MODE;
		// Value is an LSSpecial:
		unsigned int m_LEFT_SPECIAL;
		// Value is an LSOctave
		unsigned int m_LEFT_OCTAVE;
		// Values are from LSPitch
		unsigned int m_LEFT_PITCH_TRANSPOSE;
		unsigned int m_LEFT_TRANSPOSE_LIGHTS;
		// Value is an LSExpressionY
		unsigned int m_LEFT_EXPRESSION_FOR_Y;
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		unsigned int m_LEFT_CC_FOR_FADER1;
		unsigned int m_LEFT_CC_FOR_FADER2;
		unsigned int m_LEFT_CC_FOR_FADER3;
		unsigned int m_LEFT_CC_FOR_FADER4;
		unsigned int m_LEFT_CC_FOR_FADER5;
		unsigned int m_LEFT_CC_FOR_FADER6;
		unsigned int m_LEFT_CC_FOR_FADER7;
		unsigned int m_LEFT_CC_FOR_FADER8;
		// Value is an LSLowRowBehaviour
		unsigned int m_LEFT_LOWROW_X_BEHAVIOUR;
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		unsigned int m_LEFT_CC_FOR_LOWROW;
		// Value is an LSLowRowBehaviour
		unsigned int m_LEFT_LOWROW_XYZ_BEHAVIOUR;
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		unsigned int m_LEFT_CC_FOR_LOWROW_XYZ;
		unsigned int m_LEFT_CC_FOR_LOWROW_XYZ_Y;
		unsigned int m_LEFT_CC_FOR_LOWROW_XYZ_Z;
		// Values are constrained by MIN_CC and MAX_CC
		unsigned int m_LEFT_MIN_CC_FOR_Y;
		unsigned int m_LEFT_MAX_CC_FOR_Y;
		unsigned int m_LEFT_MIN_CC_FOR_Z;
		unsigned int m_LEFT_MAX_CC_FOR_Z;
		unsigned int m_LEFT_14BIT_CC_VALUE_FOR_Z;
		unsigned int m_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y;
		// Value is an LSChannelOrder
		unsigned int m_LEFT_CHANNEL_PER_ROW_ORDER;
		// Value is an LSAnimation
		unsigned int m_LEFT_TOUCH_ANIMATION;
		// Toggle:
		unsigned int m_LEFT_SEQUENCER_TOGGLE_PLAY;
		unsigned int m_LEFT_SEQUENCER_PREVIOUS_PATTERN;
		unsigned int m_LEFT_SEQUENCER_NEXT_PATTERN;
		// Value is an LSPatternNumber
		unsigned int m_LEFT_SEQUENCER_PATTERN;
		unsigned int m_LEFT_SEQUENCER_TOGGLE_MUTE;

		// Right split
		unsigned int m_RIGHT_SPLIT_MODE;
		unsigned int m_RIGHT_MIDI_MAIN_CHANNEL = 0;
		unsigned int m_RIGHT_SPLIT_RIGHT_MAIN_MODE;
		unsigned int m_RIGHT_SPLIT_RIGHT_MAIN_CHANNEL;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_1;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_2;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_3;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_4;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_5;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_6;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_7;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_8;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_9;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_10;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_11;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_12;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_13;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_14;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_15;
		unsigned int m_RIGHT_CHANNEL_PER_NOTE_16;
		// Value is a MIDI channel number:
		unsigned int m_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL;
		// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
		unsigned int m_RIGHT_BEND_RANGE;
		// Toggles:
		unsigned int m_RIGHT_BEND_TOGGLE;
		unsigned int m_RIGHT_BEND_QUANTIZE_TOGGLE;
		// Value is from LSPitchQuantize
		unsigned int m_RIGHT_PITCH_QUANTIZE;
		// Toggles:
		unsigned int m_RIGHT_RESET_PITCH_ON_RELEASE;
		unsigned int m_LEFT_SEND_Y, m_RIGHT_SEND_Y;
		// Values are constrained by MIN_CC and MAX_CC
		// CC 1 or CC 74 are recommended, any CC is possible though
		unsigned int m_RIGHT_CC_FOR_Y;
		// Toggle:
		unsigned int m_RIGHT_RELATIVE_Y;
		unsigned int m_RIGHT_RELATIVE_Z;
		// Value is an LSExpressionZ
		unsigned int m_RIGHT_EXPRESSION_FOR_Z;
		// Values are constrained by MIN_CC and MAX_CC
		// CC 11 is recommended, any CC is possible though
		unsigned int m_RIGHT_CC_FOR_Z;
		// Values are defined in LSColor
		unsigned int m_RIGHT_COLOR_MAIN;
		unsigned int m_RIGHT_COLOR_ACCENT;
		unsigned int m_RIGHT_COLOR_PLAYED;
		unsigned int m_RIGHT_COLOR_LOWROW;
		// Value is an LSLowRowMode
		unsigned int m_RIGHT_LOWROW_MODE;
		// Value is an LSSpecial:
		unsigned int m_RIGHT_SPECIAL;
		// Value is an LSOctave
		unsigned int m_RIGHT_OCTAVE;
		// Values are from LSPitch
		unsigned int m_RIGHT_PITCH_TRANSPOSE;
		unsigned int m_RIGHT_TRANSPOSE_LIGHTS;
		// Value is an LSExpressionY
		unsigned int m_RIGHT_EXPRESSION_FOR_Y;
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		unsigned int m_RIGHT_CC_FOR_FADER1;
		unsigned int m_RIGHT_CC_FOR_FADER2;
		unsigned int m_RIGHT_CC_FOR_FADER3;
		unsigned int m_RIGHT_CC_FOR_FADER4;
		unsigned int m_RIGHT_CC_FOR_FADER5;
		unsigned int m_RIGHT_CC_FOR_FADER6;
		unsigned int m_RIGHT_CC_FOR_FADER7;
		unsigned int m_RIGHT_CC_FOR_FADER8;
		// Value is an LSLowRowBehaviour
		unsigned int m_RIGHT_LOWROW_X_BEHAVIOUR;
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		unsigned int m_RIGHT_CC_FOR_LOWROW;
		// Value is an LSLowRowBehaviour
		unsigned int m_RIGHT_LOWROW_XYZ_BEHAVIOUR;
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		unsigned int m_RIGHT_CC_FOR_LOWROW_XYZ;
		unsigned int m_RIGHT_CC_FOR_LOWROW_XYZ_Y;
		unsigned int m_RIGHT_CC_FOR_LOWROW_XYZ_Z;
		// Values are constrained by MIN_CC and MAX_CC
		unsigned int m_RIGHT_MIN_CC_FOR_Y;
		unsigned int m_RIGHT_MAX_CC_FOR_Y;
		unsigned int m_RIGHT_MIN_CC_FOR_Z;
		unsigned int m_RIGHT_MAX_CC_FOR_Z;
		unsigned int m_RIGHT_14BIT_CC_VALUE_FOR_Z;
		unsigned int m_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y;
		// Value is an LSChannelOrder
		unsigned int m_RIGHT_CHANNEL_PER_ROW_ORDER;
		// Value is an LSAnimation
		unsigned int m_RIGHT_TOUCH_ANIMATION;
		// Toggle:
		unsigned int m_RIGHT_SEQUENCER_TOGGLE_PLAY;
		unsigned int m_RIGHT_SEQUENCER_PREVIOUS_PATTERN;
		unsigned int m_RIGHT_SEQUENCER_NEXT_PATTERN;
		// Value is an LSPatternNumber
		unsigned int m_RIGHT_SEQUENCER_PATTERN;
		unsigned int m_RIGHT_SEQUENCER_TOGGLE_MUTE;
		unsigned int m_LEFT_SEND_Z, m_RIGHT_SEND_Z;

// Foot and panel switches
// Value is LSSwitchAssignment
		unsigned int m_SWITCH1_ASSIGN;
		unsigned int m_SWITCH2_ASSIGN;
		unsigned int m_FOOT_LEFT_ASSIGN;
		unsigned int m_FOOT_RIGHT_ASSIGN;
		// Toggle:
		unsigned int m_SWITCH1_BOTH_SPLITS;
		unsigned int m_SWITCH2_BOTH_SPLITS;
		unsigned int m_FOOT_LEFT_BOTH_SPLITS;
		unsigned int m_FOOT_RIGHT_BOTH_SPLITS;
		// Values are constrained by MIN_CC and MAX_CC
		unsigned int m_CC_FOR_LEFT_FOOT_CC65;
		unsigned int m_CC_FOR_RIGHT_FOOT_CC65;
		unsigned int m_CC_FOR_SWITCH1_CC65;
		unsigned int m_CC_FOR_SWITCH2_CC65;
		unsigned int m_CC_FOR_LEFT_FOOT_SUSTAIN;
		unsigned int m_CC_FOR_RIGHT_FOOT_SUSTAIN;
		unsigned int m_CC_FOR_SWITCH1_SUSTAIN;
		unsigned int m_CC_FOR_SWITCH2_SUSTAIN;

// Octave/transpose settings
		unsigned int m_LeftOctave, m_LeftTransposePitch, m_LeftTransposeLights;
		unsigned int m_RightOctave, m_RightTransposePitch, m_RightTransposeLights;

				// Global settings
		unsigned int m_GLOBAL_SPLIT_ACTIVE;
		// Value is LSSplitType
		unsigned int m_GLOBAL_SELECTED_SPLIT;
		// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
		unsigned int m_GLOBAL_SPLIT_COLUMN;
		// Toggles:
		unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_C;
		unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_C_SHARP;
		unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_D;
		unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_D_SHARP;
		unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_E;
		unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_F;
		unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_F_SHARP;
		unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_G;
		unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_G_SHARP;
		unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_A;
		unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_A_SHARP;
		unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_B;
		unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_C;
		unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP;
		unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_D;
		unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP;
		unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_E;
		unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_F;
		unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP;
		unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_G;
		unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP;
		unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_A;
		unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP;
		unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_B;
		// Value is LSRowOffsetType
		unsigned int m_GLOBAL_ROW_OFFSET;
		// Value is LSVelocityRange
		unsigned int m_GLOBAL_VELOCITY_SENSITIVITY;
		// Value is LSPressureRange
		unsigned int m_GLOBAL_PRESSURE_SENSITIVITY;
		// Value is LSMIDIDevice
		unsigned int m_GLOBAL_MIDI_DEVICE_IO;
		// Value is LSArpDirection
		unsigned int m_GLOBAL_ARP_DIRECTION;
		// Value is LSArpTempoNoteType
		unsigned int m_GLOBAL_ARP_TEMPO_NOTE_VALUE;
		// Value is LSGlobalArpOctaveExtension
		unsigned int m_GLOBAL_ARP_OCTAVE_EXTENSION;
		// Value = 1 - 360  (applies when receiving no MIDI clock)
		unsigned int m_GLOBAL_CLOCK_BPM;
		// Value is LSPresetNumber
		unsigned int m_GLOBAL_SETTINGS_PRESET_LOAD;
		// Toggles:
		unsigned int m_GLOBAL_PRESSURE_AFTERTOUCH;
		unsigned int m_DEVICE_USER_FIRMWARE_MODE;
		unsigned int m_DEVICE_LEFT_HANDED;
		// Value is constrained by MIN_LIGHTS_PRESET and MAX_LIGHTS_PRESET 
		unsigned int m_GLOBAL_ACTIVE_LIGHTS_PRESET;
		// Values are constrained by MIN_CC and MAX_CC
		unsigned int m_GLOBAL_MIN_VELOCITY_VALUE;
		unsigned int m_GLOBAL_MAX_VELOCITY_VALUE;
		unsigned int m_GLOBAL_FIXED_VELOCITY_VALUE;
		// Value range =     0 - 512  
		unsigned int m_DEVICE_MIN_BYTE_INTERVAL_VALUE;
		// Value is LSCustomRowOffset
		unsigned int m_GLOBAL_CUSTOM_ROW_OFFSET;
		// Toggle:
		unsigned int m_DEVICE_MIDI_THRU;
		unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW1;
		unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW2;
		unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW3;
		unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW4;
		unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW5;
		unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW6;
		unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW7;
		unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW8;
		unsigned int m_LSPresetNumber;
		unsigned int m_LEFT_PROGRAM, m_RIGHT_PROGRAM;
		unsigned int m_LEFT_VOLUME, m_RIGHT_VOLUME;
};

std::string MIDINoteName(unsigned char nNoteNumber);
void SendCC(unsigned char CCNumber, unsigned char CCValue);

void LSCallback(double deltatime, std::vector< unsigned char > *message, void *pLinnStrument);
