// LSPerSplit.cpp

#include "LSPerSplit.h"

LSPerSplitSettings::LSPerSplitSettings()
{}


unsigned int GetSplit_Mode()
{
	return false;
}


// Left-hand split

unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_1()
{
	return m_CHANNEL_PER_NOTE_1_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_2()
{
	return m_CHANNEL_PER_NOTE_2_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_3()
{
	return m_CHANNEL_PER_NOTE_3_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_4()
{
	return m_CHANNEL_PER_NOTE_4_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_5()
{
	return m_CHANNEL_PER_NOTE_5_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_6()
{
	return m_CHANNEL_PER_NOTE_6_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_7()
{
	return m_CHANNEL_PER_NOTE_7_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_8()
{
	return m_CHANNEL_PER_NOTE_8_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_9()
{
	return m_CHANNEL_PER_NOTE_9_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_10()
{
	return m_CHANNEL_PER_NOTE_10_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_11()
{
	return m_CHANNEL_PER_NOTE_11_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_12()
{
	return m_CHANNEL_PER_NOTE_12_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_13()
{
	return m_CHANNEL_PER_NOTE_13_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_14()
{
	return m_CHANNEL_PER_NOTE_14_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_15()
{
	return m_CHANNEL_PER_NOTE_15_NRPN;
}


unsigned int LSPerSplitSettings::GetCHANNEL_PER_NOTE_16()
{
	return m_CHANNEL_PER_NOTE_16_NRPN;
}


// Value is a MIDI channel number:
unsigned int LSPerSplitSettings::GetMIDI_PER_ROW_LOWEST_CHANNEL()
{
	return m_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN;
}


// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
unsigned int LSPerSplitSettings::GetBEND_RANGE()
{
	return m_BEND_RANGE_NRPN;
}


// Toggles:
unsigned int LSPerSplitSettings::GetBEND_TOGGLE()
{
	return m_BEND_TOGGLE_NRPN;
}


unsigned int LSPerSplitSettings::GetBEND_QUANTIZE_TOGGLE()
{
	return m_BEND_QUANTIZE_TOGGLE_NRPN;
}


// Value is from LSPitchQuantize
unsigned int LSPerSplitSettings::GetPITCH_QUANTIZE()
{
	return m_PITCH_QUANTIZE_NRPN;
}


// Toggles:
unsigned int LSPerSplitSettings::GetRESET_PITCH_ON_RELEASE()
{
	return m_RESET_PITCH_ON_RELEASE_NRPN;
}


unsigned int LSPerSplitSettings::GetSEND_Y()
{
	return m_SEND_Y_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
unsigned int LSPerSplitSettings::GetCC_FOR_Y()
{
	return m_CC_FOR_Y_NRPN;
}


// Toggle:
unsigned int LSPerSplitSettings::GetRELATIVE_Y()
{
	return m_RELATIVE_Y_NRPN;
}


unsigned int LSPerSplitSettings::GetRELATIVE_Z()
{
	return m_RELATIVE_Z_NRPN;
}


// Value is an LSExpressionZ
unsigned int LSPerSplitSettings::GetMIDI_EXPRESSION_FOR_Z()
{
	return m_MIDI_EXPRESSION_FOR_Z_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
unsigned int LSPerSplitSettings::GetCC_FOR_Z()
{
	return m_CC_FOR_Z_NRPN;
}


// Values are defined in LSColor
unsigned int LSPerSplitSettings::GetCOLOR_MAIN()
{
	return m_COLOR_MAIN_NRPN;
}


unsigned int LSPerSplitSettings::GetCOLOR_ACCENT()
{
	return m_COLOR_ACCENT_NRPN;
}


unsigned int LSPerSplitSettings::GetCOLOR_PLAYED()
{
	return m_COLOR_PLAYED_NRPN;
}


unsigned int LSPerSplitSettings::GetCOLOR_LOWROW()
{
	return m_COLOR_LOWROW_NRPN;
}


// Value is an LSLowRowMode
unsigned int LSPerSplitSettings::GetLOWROW_MODE()
{
	return m_LOWROW_MODE_NRPN;
}


// Value is an LSSpecial:
unsigned int LSPerSplitSettings::GetSPECIAL()
{
	return m_SPECIAL_NRPN;
}


// Value is an LSOctave
unsigned int LSPerSplitSettings::GetOCTAVE()
{
	return m_OCTAVE_NRPN;
}


// Values are from LSPitch
unsigned int LSPerSplitSettings::GetPITCH_TRANSPOSE()
{
	return m_PITCH_TRANSPOSE_NRPN;
}


unsigned int LSPerSplitSettings::GetTRANSPOSE_LIGHTS()
{
	return m_TRANSPOSE_LIGHTS_NRPN;
}


// Value is an LSExpressionY
unsigned int LSPerSplitSettings::GetEXPRESSION_FOR_Y()
{
	return m_EXPRESSION_FOR_Y_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LSPerSplitSettings::GetCC_FOR_FADER1()
{
	return m_CC_FOR_FADER1_NRPN;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER2()
{
	return m_CC_FOR_FADER2_NRPN;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER3()
{
	return m_CC_FOR_FADER3_NRPN;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER4()
{
	return m_CC_FOR_FADER4_NRPN;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER5()
{
	return m_CC_FOR_FADER5_NRPN;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER6()
{
	return m_CC_FOR_FADER6_NRPN;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER7()
{
	return m_CC_FOR_FADER7_NRPN;
}


unsigned int LSPerSplitSettings::GetCC_FOR_FADER8()
{
	return m_CC_FOR_FADER8_NRPN;
}


// Value is an LSLowRowBehaviour
unsigned int LSPerSplitSettings::GetLOWROW_X_BEHAVIOUR()
{
	return m_LOWROW_X_BEHAVIOUR_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LSPerSplitSettings::GetCC_FOR_LOWROW()
{
	return m_CC_FOR_LOWROW_NRPN;
}


// Value is an LSLowRowBehaviour
unsigned int LSPerSplitSettings::GetLOWROW_XYZ_BEHAVIOUR()
{
	return m_LOWROW_XYZ_BEHAVIOUR_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LSPerSplitSettings::GetCC_FOR_LOWROW_XYZ()
{
	return m_CC_FOR_LOWROW_XYZ_NRPN;
}


unsigned int LSPerSplitSettings::GetCC_FOR_LOWROW_XYZ_Y()
{
	return m_CC_FOR_LOWROW_XYZ_Y_NRPN;
}


unsigned int LSPerSplitSettings::GetCC_FOR_LOWROW_XYZ_Z()
{
	return m_CC_FOR_LOWROW_XYZ_Z_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
unsigned int LSPerSplitSettings::GetMIN_CC_FOR_Y()
{
	return m_MIN_CC_FOR_Y_NRPN;
}


unsigned int LSPerSplitSettings::GetMAX_CC_FOR_Y()
{
	return m_MAX_CC_FOR_Y_NRPN;
}


unsigned int LSPerSplitSettings::GetMIN_CC_FOR_Z()
{
	return m_MIN_CC_FOR_Z_NRPN;
}


unsigned int LSPerSplitSettings::GetMAX_CC_FOR_Z()
{
	return m_MAX_CC_FOR_Z_NRPN;
}


unsigned int LSPerSplitSettings::Get14BIT_CC_VALUE_FOR_Z()
{
	return m_14BIT_CC_VALUE_FOR_Z_NRPN;
}


unsigned int LSPerSplitSettings::GetINITIAL_RELATIVE_VALUE_FOR_Y()
{
	return m_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN;
}


// Value is an LSChannelOrder
unsigned int LSPerSplitSettings::GetCHANNEL_PER_ROW_ORDER()
{
	return m_CHANNEL_PER_ROW_ORDER;
}


// Value is an LSAnimation
unsigned int LSPerSplitSettings::GetTOUCH_ANIMATION()
{
	return m_TOUCH_ANIMATION;
}


// Toggle:
unsigned int LSPerSplitSettings::GetSEQUENCER_TOGGLE_PLAY()
{
	return m_SEQUENCER_TOGGLE_PLAY_NRPN;
}


unsigned int LSPerSplitSettings::GetSEQUENCER_PREVIOUS_PATTERN()
{
	return m_SEQUENCER_PREVIOUS_PATTERN_NRPN;
}


unsigned int LSPerSplitSettings::GetSEQUENCER_NEXT_PATTERN()
{
	return m_SEQUENCER_NEXT_PATTERN_NRPN;
}


// Value is an LSPatternNumber
unsigned int LSPerSplitSettings::GetSEQUENCER_PATTERN()
{
	return m_SEQUENCER_PATTERN_NRPN;
}


unsigned int LSPerSplitSettings::GetSEQUENCER_TOGGLE_MUTE()
{
	return m_SEQUENCER_TOGGLE_MUTE_NRPN;
}


// Setters:

// Left-hand split

// Toggles:
void LSPerSplitSettings::SetCHANNEL_PER_NOTE_1(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_1_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_2(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_2_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_3(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_3_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_4(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_4_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_5(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_5_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_6(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_6_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_7(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_7_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_8(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_8_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_9(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_9_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_10(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_10_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_11(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_11_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_12(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_12_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_13(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_13_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_14(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_14_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_15(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_15_NRPN = nValue;
}


void LSPerSplitSettings::SetCHANNEL_PER_NOTE_16(unsigned int nValue)
{
	m_CHANNEL_PER_NOTE_16_NRPN = nValue;
}


// Value is a MIDI channel number:
void LSPerSplitSettings::SetMIDI_PER_ROW_LOWEST_CHANNEL(unsigned int nValue)
{
	m_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN = nValue;
}


// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
void LSPerSplitSettings::SetBEND_RANGE(unsigned int nValue)
{
	m_BEND_RANGE_NRPN = nValue;
}


// Toggles:
void LSPerSplitSettings::SetBEND_TOGGLE(unsigned int nValue)
{
	m_BEND_TOGGLE_NRPN = nValue;
}


void LSPerSplitSettings::SetBEND_QUANTIZE_TOGGLE(unsigned int nValue)
{
	m_BEND_QUANTIZE_TOGGLE_NRPN = nValue;
}


// Value is from LSPitchQuantize
void LSPerSplitSettings::SetPITCH_QUANTIZE(unsigned int nValue)
{
	m_PITCH_QUANTIZE_NRPN = nValue;
}


// Toggles:
void LSPerSplitSettings::SetRESET_PITCH_ON_RELEASE(unsigned int nValue)
{
	m_RESET_PITCH_ON_RELEASE_NRPN = nValue;
}


void LSPerSplitSettings::SetSEND_Y(unsigned int nValue)
{
	m_SEND_Y_NRPN = nValue;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
void LSPerSplitSettings::SetCC_FOR_Y(unsigned int nValue)
{
	m_CC_FOR_Y_NRPN = nValue;
}


// Toggle:
void LSPerSplitSettings::SetRELATIVE_Y(unsigned int nValue)
{
	m_RELATIVE_Y_NRPN = nValue;
}


void LSPerSplitSettings::SetRELATIVE_Z(unsigned int nValue)
{
	m_RELATIVE_Z_NRPN = nValue;
}


// Value is an LSExpressionZ
void LSPerSplitSettings::SetMIDI_EXPRESSION_FOR_Z(unsigned int nValue)
{
	m_MIDI_EXPRESSION_FOR_Z_NRPN = nValue;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
void LSPerSplitSettings::SetCC_FOR_Z(unsigned int nValue)
{
	m_CC_FOR_Z_NRPN = nValue;
}


// Values are defined in LSColor
void LSPerSplitSettings::SetCOLOR_MAIN(unsigned int nValue)
{
	m_COLOR_MAIN_NRPN = nValue;
}


void LSPerSplitSettings::SetCOLOR_ACCENT(unsigned int nValue)
{
	m_COLOR_ACCENT_NRPN = nValue;
}


void LSPerSplitSettings::SetCOLOR_PLAYED(unsigned int nValue)
{
	m_COLOR_PLAYED_NRPN = nValue;
}


void LSPerSplitSettings::SetCOLOR_LOWROW(unsigned int nValue)
{
	m_COLOR_LOWROW_NRPN = nValue;
}


// Value is an LSLowRowMode
void LSPerSplitSettings::SetLOWROW_MODE(unsigned int nValue)
{
	m_LOWROW_MODE_NRPN = nValue;
}


// Value is an LSSpecial:
void LSPerSplitSettings::SetSPECIAL(unsigned int nValue)
{
	m_SPECIAL_NRPN = nValue;
}


// Value is an LSOctave
void LSPerSplitSettings::SetOCTAVE(unsigned int nValue)
{
	m_OCTAVE_NRPN = nValue;
}


// Values are from LSPitch
void LSPerSplitSettings::SetPITCH_TRANSPOSE(unsigned int nValue)
{
	m_PITCH_TRANSPOSE_NRPN = nValue;
}


void LSPerSplitSettings::SetTRANSPOSE_LIGHTS(unsigned int nValue)
{
	m_TRANSPOSE_LIGHTS_NRPN = nValue;
}


// Value is an LSExpressionY
void LSPerSplitSettings::SetEXPRESSION_FOR_Y(unsigned int nValue)
{
	m_EXPRESSION_FOR_Y_NRPN = nValue;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LSPerSplitSettings::SetCC_FOR_FADER1(unsigned int nValue)
{
	m_CC_FOR_FADER1_NRPN = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER2(unsigned int nValue)
{
	m_CC_FOR_FADER2_NRPN = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER3(unsigned int nValue)
{
	m_CC_FOR_FADER3_NRPN = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER4(unsigned int nValue)
{
	m_CC_FOR_FADER4_NRPN = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER5(unsigned int nValue)
{
	m_CC_FOR_FADER5_NRPN = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER6(unsigned int nValue)
{
	m_CC_FOR_FADER6_NRPN = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER7(unsigned int nValue)
{
	m_CC_FOR_FADER7_NRPN = nValue;
}


void LSPerSplitSettings::SetCC_FOR_FADER8(unsigned int nValue)
{
	m_CC_FOR_FADER8_NRPN = nValue;
}


// Value is an LSLowRowBehaviour
void LSPerSplitSettings::SetLOWROW_X_BEHAVIOUR(unsigned int nValue)
{
	m_LOWROW_X_BEHAVIOUR_NRPN = nValue;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LSPerSplitSettings::SetCC_FOR_LOWROW(unsigned int nValue)
{
	m_CC_FOR_LOWROW_NRPN = nValue;
}


// Value is an LSLowRowBehaviour
void LSPerSplitSettings::SetLOWROW_XYZ_BEHAVIOUR(unsigned int nValue)
{
	m_LOWROW_XYZ_BEHAVIOUR_NRPN = nValue;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LSPerSplitSettings::SetCC_FOR_LOWROW_XYZ(unsigned int nValue)
{
	m_CC_FOR_LOWROW_XYZ_NRPN = nValue;
}


void LSPerSplitSettings::SetCC_FOR_LOWROW_XYZ_Y(unsigned int nValue)
{
	m_CC_FOR_LOWROW_XYZ_Y_NRPN = nValue;
}


void LSPerSplitSettings::SetCC_FOR_LOWROW_XYZ_Z(unsigned int nValue)
{
	m_CC_FOR_LOWROW_XYZ_Z_NRPN = nValue;
}


// Values are constrained by MIN_CC and MAX_CC
void LSPerSplitSettings::SetMIN_CC_FOR_Y(unsigned int nValue)
{
	m_MIN_CC_FOR_Y_NRPN = nValue;
}


void LSPerSplitSettings::SetMAX_CC_FOR_Y(unsigned int nValue)
{
	m_MAX_CC_FOR_Y_NRPN = nValue;
}


void LSPerSplitSettings::SetMIN_CC_FOR_Z(unsigned int nValue)
{
	m_MIN_CC_FOR_Z_NRPN = nValue;
}


void LSPerSplitSettings::SetMAX_CC_FOR_Z(unsigned int nValue)
{
	m_MAX_CC_FOR_Z_NRPN = nValue;
}


void LSPerSplitSettings::Set14BIT_CC_VALUE_FOR_Z(unsigned int nValue)
{
	m_14BIT_CC_VALUE_FOR_Z_NRPN = nValue;
}


void LSPerSplitSettings::SetINITIAL_RELATIVE_VALUE_FOR_Y(unsigned int nValue)
{
	m_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN = nValue;
}


// Value is an LSChannelOrder
void LSPerSplitSettings::SetCHANNEL_PER_ROW_ORDER(unsigned int nValue)
{
	m_CHANNEL_PER_ROW_ORDER = nValue;
}


// Value is an LSAnimation
void LSPerSplitSettings::SetTOUCH_ANIMATION(unsigned int nValue)
{
	m_TOUCH_ANIMATION = nValue;
}


// Toggle:
void LSPerSplitSettings::SetSEQUENCER_TOGGLE_PLAY(unsigned int nValue)
{
	m_SEQUENCER_TOGGLE_PLAY_NRPN = nValue;
}


void LSPerSplitSettings::SetSEQUENCER_PREVIOUS_PATTERN(unsigned int nValue)
{
	m_SEQUENCER_PREVIOUS_PATTERN_NRPN = nValue;
}


void LSPerSplitSettings::SetSEQUENCER_NEXT_PATTERN(unsigned int nValue)
{
	m_SEQUENCER_NEXT_PATTERN_NRPN = nValue;
}


// Value is an LSPatternNumber
void LSPerSplitSettings::SetSEQUENCER_PATTERN(unsigned int nValue)
{
	m_SEQUENCER_PATTERN_NRPN = nValue;
}


void LSPerSplitSettings::SetSEQUENCER_TOGGLE_MUTE(unsigned int nValue)
{
	m_SEQUENCER_TOGGLE_MUTE_NRPN = nValue;
}


unsigned int LSPerSplitSettings::GetRightSplitMAIN_MODE()
{
	return m_SPLIT_RIGHT_MAIN_MODE_NRPN;
}


// Value is a MIDIChannel
unsigned int LSPerSplitSettings::GetRightSplitMAIN_CHANNEL()
{
	return m_SPLIT_RIGHT_MAIN_CHANNEL;
}


void LSPerSplitSettings::SetRightSplitMAIN_MODE( unsigned int nValue)
{
	m_SPLIT_RIGHT_MAIN_MODE_NRPN = nValue;
}


// Value is a MIDIChannel
void LSPerSplitSettings::SetRightSplitMAIN_CHANNEL( unsigned int nValue)
{
	m_SPLIT_RIGHT_MAIN_CHANNEL = nValue;
}


