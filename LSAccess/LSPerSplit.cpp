// LSPerSplit.cpp

#include "LSPerSplit.h"

LSPerSplitSettings::LSPerSplitSettings()
{}


unsigned int LSPerSplitSettings::GetSPLIT_MODE(LSSplitType split)
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


unsigned int LSPerSplitSettings::GetMIDI_MAIN_CHANNEL(LSSplitType split)
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


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_1(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_1;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_2(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_2;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_3(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_3;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_4(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_4;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_5(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_5;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_6(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_6;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_7(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_7;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_8(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_8;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_9(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_9;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_10(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_10;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_11(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_11;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_12(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_12;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_13(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_13;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_14(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_14;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_15(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_15;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_16(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_NOTE_16;
}


// Value is a MIDI channel number:
unsigned int LSPerSplitSettings::GetMIDI_PER_ROW_LOWEST_CHANNEL(LSSplitType split)
{
	return m_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL;
}


// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
unsigned int LSPerSplitSettings::GetBEND_RANGE(LSSplitType split)
{
	return m_LEFT_BEND_RANGE;
}


// Toggles:
unsigned int LSPerSplitSettings::GetBEND_TOGGLE(LSSplitType split)
{
	return m_LEFT_BEND_TOGGLE;
}


unsigned int LSPerSplitSettings::GetBEND_QUANTIZE_TOGGLE(LSSplitType split)
{
	return m_LEFT_BEND_QUANTIZE_TOGGLE;
}


// Value is from LSPitchQuantize
unsigned int LSPerSplitSettings::GetPITCH_QUANTIZE(LSSplitType split)
{
	return m_LEFT_PITCH_QUANTIZE;
}


// Toggles:
unsigned int LSPerSplitSettings::GetRESET_PITCH_ON_RELEASE(LSSplitType split)
{
	return m_LEFT_RESET_PITCH_ON_RELEASE;
}


unsigned int LSPerSplitSettings::GetSEND_Y(LSSplitType split)
{
	return m_LEFT_SEND_Y;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
unsigned int LSPerSplitSettings::GetCC_FOR_Y(LSSplitType split)
{
	return m_LEFT_CC_FOR_Y;
}


// Toggle:
unsigned int LSPerSplitSettings::GetRELATIVE_Y(LSSplitType split)
{
	return m_LEFT_RELATIVE_Y;
}


unsigned int LSPerSplitSettings::GetRELATIVE_Z(LSSplitType split)
{
	return m_LEFT_RELATIVE_Z;
}


// Value is an LSExpressionZ
unsigned int LSPerSplitSettings::GetMIDI_EXPRESSION_FOR_Z(LSSplitType split)
{
	return m_LEFT_MIDI_EXPRESSION_FOR_Z;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
unsigned int LSPerSplitSettings::GetCC_FOR_Z(LSSplitType split)
{
	return m_LEFT_CC_FOR_Z;
}


// Values are defined in LSColor
unsigned int LSPerSplitSettings::GetCOLOR_MAIN(LSSplitType split)
{
	return m_LEFT_COLOR_MAIN;
}


unsigned int LSPerSplitSettings::GetCOLOR_ACCENT(LSSplitType split)
{
	return m_LEFT_COLOR_ACCENT;
}


unsigned int LSPerSplitSettings::GetCOLOR_PLAYED(LSSplitType split)
{
	return m_LEFT_COLOR_PLAYED;
}


unsigned int LSPerSplitSettings::GetCOLOR_LOWROW(LSSplitType split)
{
	return m_LEFT_COLOR_LOWROW;
}


// Value is an LSLowRowMode
unsigned int LSPerSplitSettings::GetLOWROW_MODE(LSSplitType split)
{
	return m_LEFT_LOWROW_MODE;
}


// Value is an LSSpecial:
unsigned int LSPerSplitSettings::GetSPECIAL(LSSplitType split)
{
	return m_LEFT_SPECIAL;
}


// Value is an LSOctave
unsigned int LSPerSplitSettings::GetOCTAVE(LSSplitType split)
{
	return m_LEFT_OCTAVE;
}


// Values are from LSPitch
unsigned int LSPerSplitSettings::GetPITCH_TRANSPOSE(LSSplitType split)
{
	return m_LEFT_PITCH_TRANSPOSE;
}


unsigned int LSPerSplitSettings::GetTRANSPOSE_LIGHTS(LSSplitType split)
{
	return m_LEFT_TRANSPOSE_LIGHTS;
}


// Value is an LSExpressionY
unsigned int LSPerSplitSettings::GetEXPRESSION_FOR_Y(LSSplitType split)
{
	return m_LEFT_EXPRESSION_FOR_Y;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LSPerSplitSettings::GetCC_FOR_FADER1(LSSplitType split)
{
	return m_LEFT_CC_FOR_FADER1;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER2(LSSplitType split)
{
	return m_LEFT_CC_FOR_FADER2;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER3(LSSplitType split)
{
	return m_LEFT_CC_FOR_FADER3;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER4(LSSplitType split)
{
	return m_LEFT_CC_FOR_FADER4;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER5(LSSplitType split)
{
	return m_LEFT_CC_FOR_FADER5;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER6(LSSplitType split)
{
	return m_LEFT_CC_FOR_FADER6;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER7(LSSplitType split)
{
	return m_LEFT_CC_FOR_FADER7;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER8(LSSplitType split)
{
	return m_LEFT_CC_FOR_FADER8;
}


// Value is an LSLowRowBehaviour
unsigned int LSPerSplitSettings::GetLOWROW_X_BEHAVIOUR(LSSplitType split)
{
	return m_LEFT_LOWROW_X_BEHAVIOUR;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LSPerSplitSettings::GetCC_FOR_LOWROW(LSSplitType split)
{
	return m_LEFT_CC_FOR_LOWROW;
}


// Value is an LSLowRowBehaviour
unsigned int LSPerSplitSettings::GetLOWROW_XYZ_BEHAVIOUR(LSSplitType split)
{
	return m_LEFT_LOWROW_XYZ_BEHAVIOUR;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LSPerSplitSettings::GetCC_FOR_LOWROW_XYZ(LSSplitType split)
{
	return m_LEFT_CC_FOR_LOWROW_XYZ;
}


unsigned int LSPerSplitSettings::GetCC_FOR_LOWROW_XYZ_Y(LSSplitType split)
{
	return m_LEFT_CC_FOR_LOWROW_XYZ_Y;
}


unsigned int LSPerSplitSettings::GetCC_FOR_LOWROW_XYZ_Z(LSSplitType split)
{
	return m_LEFT_CC_FOR_LOWROW_XYZ_Z;
}


// Values are constrained by MIN_CC and MAX_CC
unsigned int LSPerSplitSettings::GetMIN_CC_FOR_Y(LSSplitType split)
{
	return m_LEFT_MIN_CC_FOR_Y;
}


unsigned int LSPerSplitSettings::GetMAX_CC_FOR_Y(LSSplitType split)
{
	return m_LEFT_MAX_CC_FOR_Y;
}


unsigned int LSPerSplitSettings::GetMIN_CC_FOR_Z(LSSplitType split)
{
	return m_LEFT_MIN_CC_FOR_Z;
}


unsigned int LSPerSplitSettings::GetMAX_CC_FOR_Z(LSSplitType split)
{
	return m_LEFT_MAX_CC_FOR_Z;
}


unsigned int LSPerSplitSettings::Get14BIT_CC_VALUE_FOR_Z(LSSplitType split)
{
	return m_LEFT_14BIT_CC_VALUE_FOR_Z;
}


unsigned int LSPerSplitSettings::GetINITIAL_RELATIVE_VALUE_FOR_Y(LSSplitType split)
{
	return m_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y;
}


// Value is an LSChannelOrder
unsigned int LSPerSplitSettings::GetCHANNEL_PER_ROW_ORDER(LSSplitType split)
{
	return m_LEFT_CHANNEL_PER_ROW_ORDER;
}


// Value is an LSAnimation
unsigned int LSPerSplitSettings::GetTOUCH_ANIMATION(LSSplitType split)
{
	return m_LEFT_TOUCH_ANIMATION;
}


// Toggle:
unsigned int LSPerSplitSettings::GetSEQUENCER_TOGGLE_PLAY(LSSplitType split)
{
	return m_LEFT_SEQUENCER_TOGGLE_PLAY;
}


unsigned int LSPerSplitSettings::GetSEQUENCER_PREVIOUS_PATTERN(LSSplitType split)
{
	return m_LEFT_SEQUENCER_PREVIOUS_PATTERN;
}


unsigned int LSPerSplitSettings::GetSEQUENCER_NEXT_PATTERN(LSSplitType split)
{
	return m_LEFT_SEQUENCER_NEXT_PATTERN;
}


// Value is an LSPatternNumber
unsigned int LSPerSplitSettings::GetSEQUENCER_PATTERN(LSSplitType split)
{
	return m_LEFT_SEQUENCER_PATTERN;
}


unsigned int LSPerSplitSettings::GetSEQUENCER_TOGGLE_MUTE(LSSplitType split)
{
	return m_LEFT_SEQUENCER_TOGGLE_MUTE;
}


// Setters:

// Left-hand split

// Toggles:
void LSPerSplitSettings::SetCHANNEL_PER_NOTE_1(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_1 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_2(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_2 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_3(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_3 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_4(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_4 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_5(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_5 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_6(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_6 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_7(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_7 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_8(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_8 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_9(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_9 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_10(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_10 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_11(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_11 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_12(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_12 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_13(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_13 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_14(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_14 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_15(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_15 = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_16(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_NOTE_16 = nValue;
}


// Value is a MIDI channel number:
void LSPerSplitSettings::SetMIDI_PER_ROW_LOWEST_CHANNEL(unsigned int nValue)
{
	m_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL = nValue;
}


// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
void LSPerSplitSettings::SetBEND_RANGE(unsigned int nValue)
{
	m_LEFT_BEND_RANGE = nValue;
}


// Toggles:
void LSPerSplitSettings::SetBEND_TOGGLE(unsigned int nValue)
{
	m_LEFT_BEND_TOGGLE = nValue;
}


void LSPerSplitSettings::SetBEND_QUANTIZE_TOGGLE(unsigned int nValue)
{
	m_LEFT_BEND_QUANTIZE_TOGGLE = nValue;
}


// Value is from LSPitchQuantize
void LSPerSplitSettings::SetPITCH_QUANTIZE(unsigned int nValue)
{
	m_LEFT_PITCH_QUANTIZE = nValue;
}


// Toggles:
void LSPerSplitSettings::SetRESET_PITCH_ON_RELEASE(unsigned int nValue)
{
	m_LEFT_RESET_PITCH_ON_RELEASE = nValue;
}


void LSPerSplitSettings::SetSEND_Y(unsigned int nValue)
{
	m_LEFT_SEND_Y = nValue;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
void LSPerSplitSettings::SetCC_FOR_Y(unsigned int nValue)
{
	m_LEFT_CC_FOR_Y = nValue;
}


// Toggle:
void LSPerSplitSettings::SetRELATIVE_Y(unsigned int nValue)
{
	m_LEFT_RELATIVE_Y = nValue;
}


void LSPerSplitSettings::SetRELATIVE_Z(unsigned int nValue)
{
	m_LEFT_RELATIVE_Z = nValue;
}


// Value is an LSExpressionZ
void LSPerSplitSettings::SetMIDI_EXPRESSION_FOR_Z(unsigned int nValue)
{
	m_LEFT_MIDI_EXPRESSION_FOR_Z = nValue;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
void LSPerSplitSettings::SetCC_FOR_Z(unsigned int nValue)
{
	m_LEFT_CC_FOR_Z = nValue;
}


// Values are defined in LSColor
void LSPerSplitSettings::SetCOLOR_MAIN(unsigned int nValue)
{
	m_LEFT_COLOR_MAIN = nValue;
}


void LSPerSplitSettings::SetCOLOR_ACCENT(unsigned int nValue)
{
	m_LEFT_COLOR_ACCENT = nValue;
}


void LSPerSplitSettings::SetCOLOR_PLAYED(unsigned int nValue)
{
	m_LEFT_COLOR_PLAYED = nValue;
}


void LSPerSplitSettings::SetCOLOR_LOWROW(unsigned int nValue)
{
	m_LEFT_COLOR_LOWROW = nValue;
}


// Value is an LSLowRowMode
void LSPerSplitSettings::SetLOWROW_MODE(unsigned int nValue)
{
	m_LEFT_LOWROW_MODE = nValue;
}


// Value is an LSSpecial:
void LSPerSplitSettings::SetSPECIAL(unsigned int nValue)
{
	m_LEFT_SPECIAL = nValue;
}


// Value is an LSOctave
void LSPerSplitSettings::SetOCTAVE(unsigned int nValue)
{
	m_LEFT_OCTAVE = nValue;
}


// Values are from LSPitch
void LSPerSplitSettings::SetPITCH_TRANSPOSE(unsigned int nValue)
{
	m_LEFT_PITCH_TRANSPOSE = nValue;
}


void LSPerSplitSettings::SetTRANSPOSE_LIGHTS(unsigned int nValue)
{
	m_LEFT_TRANSPOSE_LIGHTS = nValue;
}


// Value is an LSExpressionY
void LSPerSplitSettings::SetEXPRESSION_FOR_Y(unsigned int nValue)
{
	m_LEFT_EXPRESSION_FOR_Y = nValue;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LSPerSplitSettings::SetCC_FOR_FADER1(unsigned int nValue)
{
	m_LEFT_CC_FOR_FADER1 = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER2(unsigned int nValue)
{
	m_LEFT_CC_FOR_FADER2 = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER3(unsigned int nValue)
{
	m_LEFT_CC_FOR_FADER3 = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER4(unsigned int nValue)
{
	m_LEFT_CC_FOR_FADER4 = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER5(unsigned int nValue)
{
	m_LEFT_CC_FOR_FADER5 = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER6(unsigned int nValue)
{
	m_LEFT_CC_FOR_FADER6 = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER7(unsigned int nValue)
{
	m_LEFT_CC_FOR_FADER7 = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER8(unsigned int nValue)
{
	m_LEFT_CC_FOR_FADER8 = nValue;
}


// Value is an LSLowRowBehaviour
void LSPerSplitSettings::SetLOWROW_X_BEHAVIOUR(unsigned int nValue)
{
	m_LEFT_LOWROW_X_BEHAVIOUR = nValue;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LSPerSplitSettings::SetCC_FOR_LOWROW(unsigned int nValue)
{
	m_LEFT_CC_FOR_LOWROW = nValue;
}


// Value is an LSLowRowBehaviour
void LSPerSplitSettings::SetLOWROW_XYZ_BEHAVIOUR(unsigned int nValue)
{
	m_LEFT_LOWROW_XYZ_BEHAVIOUR = nValue;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LSPerSplitSettings::SetCC_FOR_LOWROW_XYZ(unsigned int nValue)
{
	m_LEFT_CC_FOR_LOWROW_XYZ = nValue;
}


void LSPerSplitSettings::SetCC_FOR_LOWROW_XYZ_Y(unsigned int nValue)
{
	m_LEFT_CC_FOR_LOWROW_XYZ_Y = nValue;
}


void LSPerSplitSettings::SetCC_FOR_LOWROW_XYZ_Z(unsigned int nValue)
{
	m_LEFT_CC_FOR_LOWROW_XYZ_Z = nValue;
}


// Values are constrained by MIN_CC and MAX_CC
void LSPerSplitSettings::SetMIN_CC_FOR_Y(unsigned int nValue)
{
	m_LEFT_MIN_CC_FOR_Y = nValue;
}


void LSPerSplitSettings::SetMAX_CC_FOR_Y(unsigned int nValue)
{
	m_LEFT_MAX_CC_FOR_Y = nValue;
}


void LSPerSplitSettings::SetMIN_CC_FOR_Z(unsigned int nValue)
{
	m_LEFT_MIN_CC_FOR_Z = nValue;
}


void LSPerSplitSettings::SetMAX_CC_FOR_Z(unsigned int nValue)
{
	m_LEFT_MAX_CC_FOR_Z = nValue;
}


void LSPerSplitSettings::Set14BIT_CC_VALUE_FOR_Z(unsigned int nValue)
{
	m_LEFT_14BIT_CC_VALUE_FOR_Z = nValue;
}


void LSPerSplitSettings::SetINITIAL_RELATIVE_VALUE_FOR_Y(unsigned int nValue)
{
	m_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y = nValue;
}


// Value is an LSChannelOrder
void LSPerSplitSettings::SetCHANNEL_PER_ROW_ORDER(unsigned int nValue)
{
	m_LEFT_CHANNEL_PER_ROW_ORDER = nValue;
}


// Value is an LSAnimation
void LSPerSplitSettings::SetTOUCH_ANIMATION(unsigned int nValue)
{
	m_LEFT_TOUCH_ANIMATION = nValue;
}


// Toggle:
void LSPerSplitSettings::SetSEQUENCER_TOGGLE_PLAY(unsigned int nValue)
{
	m_LEFT_SEQUENCER_TOGGLE_PLAY = nValue;
}


void LSPerSplitSettings::SetSEQUENCER_PREVIOUS_PATTERN(unsigned int nValue)
{
	m_LEFT_SEQUENCER_PREVIOUS_PATTERN = nValue;
}


void LSPerSplitSettings::SetSEQUENCER_NEXT_PATTERN(unsigned int nValue)
{
	m_LEFT_SEQUENCER_NEXT_PATTERN = nValue;
}


// Value is an LSPatternNumber
void LSPerSplitSettings::SetSEQUENCER_PATTERN(unsigned int nValue)
{
	m_LEFT_SEQUENCER_PATTERN = nValue;
}


void LSPerSplitSettings::SetSEQUENCER_TOGGLE_MUTE(unsigned int nValue)
{
	m_LEFT_SEQUENCER_TOGGLE_MUTE = nValue;
}


