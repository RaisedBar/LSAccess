// LSPerSplit.h
// LinnStrument per-split settings

#pragma once

#include "LSEnums.h"


// Value is an LSSplitMode
const unsigned int SPLIT_LEFT_MAIN_MODE_NRPN = 0;
// Value constrained by MIN_MIDI_CHANNEL and MAX_MIDI_CHANNEL
const unsigned int SPLIT_LEFT_MAIN_CHANNEL_NRPN = 1;
// Toggles:
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN = 2;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN = 3;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN = 4;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN = 5;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN = 6;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN = 7;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN = 8;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN = 9;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN = 10;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN = 11;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN = 12;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN = 13;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN = 14;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN = 15;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN = 16;
const unsigned int SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN = 17;
// Value is a MIDI channel number:
const unsigned int SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN = 18;
// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
const unsigned int SPLIT_LEFT_BEND_RANGE_NRPN = 19;
// Toggles:
const unsigned int SPLIT_LEFT_BEND_TOGGLE_NRPN = 20;
const unsigned int SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN = 21;
// Value is from LSPitchQuantize
const unsigned int SPLIT_LEFT_PITCH_QUANTIZE_NRPN = 22;
// Toggles:
const unsigned int SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN = 23;
const unsigned int SPLIT_LEFT_SEND_Y_NRPN = 24;
// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
const unsigned int SPLIT_LEFT_CC_FOR_Y_NRPN = 25;
// Toggle:
const unsigned int SPLIT_LEFT_RELATIVE_Y_NRPN = 26;
const unsigned int SPLIT_LEFT_SEND_Z_NRPN = 27;
// Value is an LSExpressionZ
const unsigned int SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN = 28;
// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
const unsigned int SPLIT_LEFT_CC_FOR_Z_NRPN = 29;
// Values are defined in LSColor
const unsigned int SPLIT_LEFT_COLOR_MAIN_NRPN = 30;
const unsigned int SPLIT_LEFT_COLOR_ACCENT_NRPN = 31;
const unsigned int SPLIT_LEFT_COLOR_PLAYED_NRPN = 32;
const unsigned int SPLIT_LEFT_COLOR_LOWROW_NRPN = 33;
// Value is an LSLowRowMode
const unsigned int SPLIT_LEFT_LOWROW_MODE_NRPN = 34;
// Value is an LSSpecial:
const unsigned int SPLIT_LEFT_SPECIAL_NRPN = 35;
// Value is an LSExpressionY
const unsigned int SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN = 39;

// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
const unsigned int SPLIT_LEFT_CC_FOR_FADER1_NRPN = 40;
const unsigned int SPLIT_LEFT_CC_FOR_FADER2_NRPN = 41;
const unsigned int SPLIT_LEFT_CC_FOR_FADER3_NRPN = 42;
const unsigned int SPLIT_LEFT_CC_FOR_FADER4_NRPN = 43;
const unsigned int SPLIT_LEFT_CC_FOR_FADER5_NRPN = 44;
const unsigned int SPLIT_LEFT_CC_FOR_FADER6_NRPN = 45;
const unsigned int SPLIT_LEFT_CC_FOR_FADER7_NRPN = 46;
const unsigned int SPLIT_LEFT_CC_FOR_FADER8_NRPN = 47;
// Value is an LSLowRowBehaviour
const unsigned int SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN = 48;
// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
const unsigned int SPLIT_LEFT_CC_FOR_LOWROW_NRPN = 49;
// Value is an LSLowRowBehaviour
const unsigned int SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN = 50;
// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
const unsigned int SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN = 51;
const unsigned int SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN = 52;
const unsigned int SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN = 53;
// Values are constrained by MIN_CC and MAX_CC
const unsigned int SPLIT_LEFT_MIN_CC_FOR_Y_NRPN = 54;
const unsigned int SPLIT_LEFT_MAX_CC_FOR_Y_NRPN = 55;
const unsigned int SPLIT_LEFT_MIN_CC_FOR_Z_NRPN = 56;
const unsigned int SPLIT_LEFT_MAX_CC_FOR_Z_NRPN = 57;
const unsigned int SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN = 58;
const unsigned int SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN = 59;
// Value is an LSChannelOrder
const unsigned int SPLIT_LEFT_CHANNEL_PER_ROW_ORDER_NRPN = 60;
// Value is an LSAnimation
const unsigned int SPLIT_LEFT_TOUCH_ANIMATION_NRPN = 61;

// Toggle:
const unsigned int SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN = 62;
const unsigned int SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN = 63;
const unsigned int SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN = 64;
// Value is an LSPatternNumber
const unsigned int SPLIT_LEFT_SEQUENCER_PATTERN_NRPN = 65;
const unsigned int SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN = 66;

// Right-hand split
// Value is an LSSplitMode
const unsigned int SPLIT_RIGHT_MAIN_MODE_NRPN = 100;
// Value is a MIDIChannel
const unsigned int SPLIT_RIGHT_MAIN_CHANNEL_NRPN = 101;
// Toggles:
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN = 102;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN = 103;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN = 104;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN = 105;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN = 106;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN = 107;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN = 108;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN = 109;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN = 110;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN = 111;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN = 112;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN = 113;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN = 114;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN = 115;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN = 116;
const unsigned int SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN = 117;
// Value is a MIDI channel number:
const unsigned int SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN = 118;
// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE 
const unsigned int SPLIT_RIGHT_BEND_RANGE_NRPN = 119;
// Toggles:
const unsigned int SPLIT_RIGHT_BEND_TOGGLE_NRPN = 120;
const unsigned int SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN = 121;
// Value is from LSPitchQuantize
const unsigned int SPLIT_RIGHT_PITCH_QUANTIZE_NRPN = 122;
// Toggles:
const unsigned int SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN = 123;
const unsigned int SPLIT_RIGHT_SEND_Y_NRPN = 124;
// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
const unsigned int SPLIT_RIGHT_CC_FOR_Y_NRPN = 125;
// Toggle:
const unsigned int SPLIT_RIGHT_RELATIVE_Y_NRPN = 126;
const unsigned int SPLIT_RIGHT_SEND_Z_NRPN = 127;
// Value is an LSExpressionZ
const unsigned int SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN = 128;
// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
const unsigned int SPLIT_RIGHT_CC_FOR_Z_NRPN = 129;
// Values are defined in LSColor
const unsigned int SPLIT_RIGHT_COLOR_MAIN_NRPN = 130;
const unsigned int SPLIT_RIGHT_COLOR_ACCENT_NRPN = 131;
const unsigned int SPLIT_RIGHT_COLOR_PLAYED_NRPN = 132;
const unsigned int SPLIT_RIGHT_COLOR_LOWROW_NRPN = 133;
// Value is an LSLowRowMode
const unsigned int SPLIT_RIGHT_LOWROW_MODE_NRPN = 134;
// Value is an LSSpecial:
const unsigned int SPLIT_RIGHT_SPECIAL_NRPN = 135;
// Value is an LSExpressionY
const unsigned int SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN = 139;

// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
const unsigned int SPLIT_RIGHT_CC_FOR_FADER1_NRPN = 140;
const unsigned int SPLIT_RIGHT_CC_FOR_FADER2_NRPN = 141;
const unsigned int SPLIT_RIGHT_CC_FOR_FADER3_NRPN = 142;
const unsigned int SPLIT_RIGHT_CC_FOR_FADER4_NRPN = 143;
const unsigned int SPLIT_RIGHT_CC_FOR_FADER5_NRPN = 144;
const unsigned int SPLIT_RIGHT_CC_FOR_FADER6_NRPN = 145;
const unsigned int SPLIT_RIGHT_CC_FOR_FADER7_NRPN = 146;
const unsigned int SPLIT_RIGHT_CC_FOR_FADER8_NRPN = 147;
// Value is an LSLowRowBehaviour
const unsigned int SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN = 148;
// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
const unsigned int SPLIT_RIGHT_CC_FOR_LOWROW_NRPN = 149;
// Value is an LSLowRowBehaviour
const unsigned int SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN = 150;
// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
const unsigned int SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN = 151;
const unsigned int SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN = 152;
const unsigned int SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN = 153;
// Values are constrained by MIN_CC and MAX_CC
const unsigned int SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN = 154;
const unsigned int SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN = 155;
const unsigned int SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN = 156;
const unsigned int SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN = 157;
const unsigned int SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN = 158;
const unsigned int SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN = 159;
// Value is an LSChannelOrder
const unsigned int SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER_NRPN = 160;
// Value is an LSAnimation
const unsigned int SPLIT_RIGHT_TOUCH_ANIMATION_NRPN = 161;

// Toggle:
const unsigned int SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN = 162;
const unsigned int SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN = 163;
const unsigned int SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN = 164;
// Value is an LSPatternNumber
const unsigned int SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN = 165;
const unsigned int SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN = 166;


class LSPerSplitSettings
{
public:
	LSPerSplitSettings()
	{};

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
	unsigned int GetSEQUENCER_TOGGLE_PLAY(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_SEQUENCER_TOGGLE_PLAY;
		}
		else
		{
			return m_RIGHT_SEQUENCER_TOGGLE_PLAY;
		}
	}


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


	unsigned int GetSEQUENCER_TOGGLE_MUTE(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_SEQUENCER_TOGGLE_MUTE;
		}
		else
		{
			return m_RIGHT_SEQUENCER_TOGGLE_MUTE;
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

private:
	// Left split
	unsigned int m_LEFT_SPLIT_MODE;
	unsigned int m_LEFT_MIDI_MAIN_CHANNEL;
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
	unsigned int m_RIGHT_MIDI_MAIN_CHANNEL;
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
};
