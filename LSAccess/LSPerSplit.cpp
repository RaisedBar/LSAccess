// LSPerSplit.cpp

#include "LSPerSplit.h"

LSPerSplitSettings::LSPerSplitSettings()
{}


// Left-hand split

unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN()
{
	return m_SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN;
}


// Value is a MIDI channel number:
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN()
{
	return m_SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN;
}


// Value is from LSBendRange
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_BEND_RANGE_NRPN()
{
	return m_SPLIT_LEFT_BEND_RANGE_NRPN;
}


// Toggles:
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_BEND_TOGGLE_NRPN()
{
	return m_SPLIT_LEFT_BEND_TOGGLE_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN()
{
	return m_SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN;
}


// Value is from LSPitchQuantize
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_PITCH_QUANTIZE_NRPN()
{
	return m_SPLIT_LEFT_PITCH_QUANTIZE_NRPN;
}


// Toggles:
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN()
{
	return m_SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_SEND_Y_NRPN()
{
	return m_SPLIT_LEFT_SEND_Y_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_Y_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_Y_NRPN;
}


// Toggle:
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_RELATIVE_Y_NRPN()
{
	return m_SPLIT_LEFT_RELATIVE_Y_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_RELATIVE_Z_NRPN()
{
	return m_SPLIT_LEFT_RELATIVE_Z_NRPN;
}


// Value is an LSExpressionZ
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN()
{
	return m_SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_Z_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_Z_NRPN;
}


// Values are defined in LSColor
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_COLOR_MAIN_NRPN()
{
	return m_SPLIT_LEFT_COLOR_MAIN_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_COLOR_ACCENT_NRPN()
{
	return m_SPLIT_LEFT_COLOR_ACCENT_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_COLOR_PLAYED_NRPN()
{
	return m_SPLIT_LEFT_COLOR_PLAYED_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_COLOR_LOWROW_NRPN()
{
	return m_SPLIT_LEFT_COLOR_LOWROW_NRPN;
}


// Value is an LSLowRowMode
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_LOWROW_MODE_NRPN()
{
	return m_SPLIT_LEFT_LOWROW_MODE_NRPN;
}


// Value is an LSSpecial:
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_SPECIAL_NRPN()
{
	return m_SPLIT_LEFT_SPECIAL_NRPN;
}


// Value is an LSOctave
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_OCTAVE_NRPN()
{
	return m_SPLIT_LEFT_OCTAVE_NRPN;
}


// Values are from LSPitch
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_PITCH_TRANSPOSE_NRPN()
{
	return m_SPLIT_LEFT_PITCH_TRANSPOSE_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN()
{
	return m_SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN;
}


// Value is an LSExpressionY
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_EXPRESSION_FOR_Y_NRPN()
{
	return m_SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_FADER1_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER1_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_FADER2_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER2_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_FADER3_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER3_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_FADER4_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER4_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_FADER5_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER5_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_FADER6_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER6_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_FADER7_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER7_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_FADER8_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_FADER8_NRPN;
}


// Value is an LSLowRowBehaviour
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN()
{
	return m_SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_LOWROW_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_LOWROW_NRPN;
}


// Value is an LSLowRowBehaviour
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN()
{
	return m_SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN()
{
	return m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_MIN_CC_FOR_Y_NRPN()
{
	return m_SPLIT_LEFT_MIN_CC_FOR_Y_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_MAX_CC_FOR_Y_NRPN()
{
	return m_SPLIT_LEFT_MAX_CC_FOR_Y_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_MIN_CC_FOR_Z_NRPN()
{
	return m_SPLIT_LEFT_MIN_CC_FOR_Z_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_MAX_CC_FOR_Z_NRPN()
{
	return m_SPLIT_LEFT_MAX_CC_FOR_Z_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN()
{
	return m_SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN()
{
	return m_SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN;
}


// Value is an LSChannelOrder
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_CHANNEL_PER_ROW_ORDER()
{
	return m_SPLIT_LEFT_CHANNEL_PER_ROW_ORDER;
}


// Value is an LSAnimation
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_TOUCH_ANIMATION()
{
	return m_SPLIT_LEFT_TOUCH_ANIMATION;
}


// Toggle:
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN()
{
	return m_SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN()
{
	return m_SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN()
{
	return m_SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN;
}


// Value is an LSPatternNumber
unsigned int LSPerSplitSettings::GetSPLIT_LEFT_SEQUENCER_PATTERN_NRPN()
{
	return m_SPLIT_LEFT_SEQUENCER_PATTERN_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN()
{
	return m_SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN;
}


// Setters:

// Left-hand split

// Toggles:
void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN = nValue;
	}


// Value is a MIDI channel number:
void LSPerSplitSettings::SetSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN = nValue;
}


// Value is from LSBendRange
void LSPerSplitSettings::SetSPLIT_LEFT_BEND_RANGE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_BEND_RANGE_NRPN = nValue;
	}


// Toggles:
void LSPerSplitSettings::SetSPLIT_LEFT_BEND_TOGGLE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_BEND_TOGGLE_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN = nValue;
	}


// Value is from LSPitchQuantize
void LSPerSplitSettings::SetSPLIT_LEFT_PITCH_QUANTIZE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_PITCH_QUANTIZE_NRPN = nValue;
}


// Toggles:
void LSPerSplitSettings::SetSPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_SEND_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SEND_Y_NRPN = nValue;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_Y_NRPN = nValue;
	}


// Toggle:
void LSPerSplitSettings::SetSPLIT_LEFT_RELATIVE_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_RELATIVE_Y_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_RELATIVE_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_RELATIVE_Z_NRPN = nValue;
	}


// Value is an LSExpressionZ
void LSPerSplitSettings::SetSPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN = nValue;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_Z_NRPN = nValue;
	}


// Values are defined in LSColor
void LSPerSplitSettings::SetSPLIT_LEFT_COLOR_MAIN_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_COLOR_MAIN_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_COLOR_ACCENT_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_COLOR_ACCENT_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_COLOR_PLAYED_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_COLOR_PLAYED_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_COLOR_LOWROW_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_COLOR_LOWROW_NRPN = nValue;
	}


// Value is an LSLowRowMode
void LSPerSplitSettings::SetSPLIT_LEFT_LOWROW_MODE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_LOWROW_MODE_NRPN = nValue;
}


// Value is an LSSpecial:
void LSPerSplitSettings::SetSPLIT_LEFT_SPECIAL_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SPECIAL_NRPN = nValue;
	}


// Value is an LSOctave
void LSPerSplitSettings::SetSPLIT_LEFT_OCTAVE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_OCTAVE_NRPN = nValue;
}


// Values are from LSPitch
void LSPerSplitSettings::SetSPLIT_LEFT_PITCH_TRANSPOSE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_PITCH_TRANSPOSE_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN = nValue;
}


// Value is an LSExpressionY
void LSPerSplitSettings::SetSPLIT_LEFT_EXPRESSION_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN = nValue;
	}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_FADER1_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER1_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_FADER2_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER2_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_FADER3_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER3_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_FADER4_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER4_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_FADER5_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER5_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_FADER6_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER6_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_FADER7_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER7_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_FADER8_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_FADER8_NRPN = nValue;
	}


// Value is an LSLowRowBehaviour
void LSPerSplitSettings::SetSPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN = nValue;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_LOWROW_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_LOWROW_NRPN = nValue;
	}


// Value is an LSLowRowBehaviour
void LSPerSplitSettings::SetSPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN = nValue;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN = nValue;
	}


// Values are constrained by MIN_CC and MAX_CC
void LSPerSplitSettings::SetSPLIT_LEFT_MIN_CC_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_MIN_CC_FOR_Y_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_MAX_CC_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_MAX_CC_FOR_Y_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_MIN_CC_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_MIN_CC_FOR_Z_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_MAX_CC_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_MAX_CC_FOR_Z_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN = nValue;
	}


// Value is an LSChannelOrder
void LSPerSplitSettings::SetSPLIT_LEFT_CHANNEL_PER_ROW_ORDER(unsigned int nValue)
{
	m_SPLIT_LEFT_CHANNEL_PER_ROW_ORDER = nValue;
}


// Value is an LSAnimation
void LSPerSplitSettings::SetSPLIT_LEFT_TOUCH_ANIMATION(unsigned int nValue)
{
	m_SPLIT_LEFT_TOUCH_ANIMATION = nValue;
	}


// Toggle:
void LSPerSplitSettings::SetSPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN = nValue;
}


// Value is an LSPatternNumber
void LSPerSplitSettings::SetSPLIT_LEFT_SEQUENCER_PATTERN_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SEQUENCER_PATTERN_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN(unsigned int nValue)
{
	m_SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN = nValue;
}


// Right-hand split

unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_MAIN_MODE_NRPN()
{
	return m_SPLIT_RIGHT_MAIN_MODE_NRPN;
}


// Value is a MIDIChannel
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_MAIN_CHANNEL()
{
	return m_SPLIT_RIGHT_MAIN_CHANNEL;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN;
}


// Value is a MIDI channel number:
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN()
{
	return m_SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN;
}


// Value is from LSBendRange
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_BEND_RANGE_NRPN()
{
	return m_SPLIT_RIGHT_BEND_RANGE_NRPN;
}


// Toggles:
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_BEND_TOGGLE_NRPN()
{
	return m_SPLIT_RIGHT_BEND_TOGGLE_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN()
{
	return m_SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN;
}


// Value is from LSPitchQuantize
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_PITCH_QUANTIZE_NRPN()
{
	return m_SPLIT_RIGHT_PITCH_QUANTIZE_NRPN;
}


// Toggles:
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN()
{
	return m_SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_SEND_Y_NRPN()
{
	return m_SPLIT_RIGHT_SEND_Y_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_Y_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_Y_NRPN;
}


// Toggle:
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_RELATIVE_Y_NRPN()
{
	return m_SPLIT_RIGHT_RELATIVE_Y_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_RELATIVE_Z_NRPN()
{
	return m_SPLIT_RIGHT_RELATIVE_Z_NRPN;
}


// Value is an LSExpressionZ
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN()
{
	return m_SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_Z_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_Z_NRPN;
}


// Values are defined in LSColor
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_COLOR_MAIN_NRPN()
{
	return m_SPLIT_RIGHT_COLOR_MAIN_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_COLOR_ACCENT_NRPN()
{
	return m_SPLIT_RIGHT_COLOR_ACCENT_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_COLOR_PLAYED_NRPN()
{
	return m_SPLIT_RIGHT_COLOR_PLAYED_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_COLOR_LOWROW_NRPN()
{
	return m_SPLIT_RIGHT_COLOR_LOWROW_NRPN;
}


// Value is an LSLowRowMode
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_LOWROW_MODE_NRPN()
{
	return m_SPLIT_RIGHT_LOWROW_MODE_NRPN;
}


// Value is an LSSpecial:
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_SPECIAL_NRPN()
{
	return m_SPLIT_RIGHT_SPECIAL_NRPN;
}


// Value is an LSOctave
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_OCTAVE_NRPN()
{
	return m_SPLIT_RIGHT_OCTAVE_NRPN;
}


// Values are from LSPitch
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_PITCH_TRANSPOSE_NRPN()
{
	return m_SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN()
{
	return m_SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN;
}


// Value is an LSExpressionY
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN()
{
	return m_SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_FADER1_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER1_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_FADER2_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER2_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_FADER3_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER3_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_FADER4_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER4_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_FADER5_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER5_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_FADER6_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER6_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_FADER7_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER7_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_FADER8_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_FADER8_NRPN;
}


// Value is an LSLowRowBehaviour
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN()
{
	return m_SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_LOWROW_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_LOWROW_NRPN;
}


// Value is an LSLowRowBehaviour
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN()
{
	return m_SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN()
{
	return m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN;
}


// Values are constrained by MIN_CC and MAX_CC
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_MIN_CC_FOR_Y_NRPN()
{
	return m_SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_MAX_CC_FOR_Y_NRPN()
{
	return m_SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_MIN_CC_FOR_Z_NRPN()
{
	return m_SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_MAX_CC_FOR_Z_NRPN()
{
	return m_SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN()
{
	return m_SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN()
{
	return m_SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN;
}


// Value is an LSChannelOrder
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_CHANNEL_PER_ROW_ORDER()
{
	return m_SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER;
}


// Value is an LSAnimation
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_TOUCH_ANIMATION()
{
	return m_SPLIT_RIGHT_TOUCH_ANIMATION;
}


// Toggle:
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN()
{
	return m_SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN()
{
	return m_SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN()
{
	return m_SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN;
}


// Value is an LSPatternNumber
unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_SEQUENCER_PATTERN_NRPN()
{
	return m_SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN;
}


unsigned int LSPerSplitSettings::GetSPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN()
{
	return m_SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN;
}


// Setters:

// Left-hand split

// Toggles:
void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN = nValue;
}


// Value is a MIDI channel number:
void LSPerSplitSettings::SetSPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN = nValue;
	}


// Value is from LSBendRange
void LSPerSplitSettings::SetSPLIT_RIGHT_BEND_RANGE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_BEND_RANGE_NRPN = nValue;
}


// Toggles:
void LSPerSplitSettings::SetSPLIT_RIGHT_BEND_TOGGLE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_BEND_TOGGLE_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN = nValue;
}


// Value is from LSPitchQuantize
void LSPerSplitSettings::SetSPLIT_RIGHT_PITCH_QUANTIZE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_PITCH_QUANTIZE_NRPN = nValue;
	}


// Toggles:
void LSPerSplitSettings::SetSPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_SEND_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SEND_Y_NRPN = nValue;
	}


// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_Y_NRPN = nValue;
}


// Toggle:
void LSPerSplitSettings::SetSPLIT_RIGHT_RELATIVE_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_RELATIVE_Y_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_RELATIVE_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_RELATIVE_Z_NRPN = nValue;
}


// Value is an LSExpressionZ
void LSPerSplitSettings::SetSPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN = nValue;
	}


// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_Z_NRPN = nValue;
}


// Values are defined in LSColor
void LSPerSplitSettings::SetSPLIT_RIGHT_COLOR_MAIN_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_COLOR_MAIN_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_COLOR_ACCENT_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_COLOR_ACCENT_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_COLOR_PLAYED_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_COLOR_PLAYED_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_COLOR_LOWROW_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_COLOR_LOWROW_NRPN = nValue;
}


// Value is an LSLowRowMode
void LSPerSplitSettings::SetSPLIT_RIGHT_LOWROW_MODE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_LOWROW_MODE_NRPN = nValue;
	}


// Value is an LSSpecial:
void LSPerSplitSettings::SetSPLIT_RIGHT_SPECIAL_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SPECIAL_NRPN = nValue;
}


// Value is an LSOctave
void LSPerSplitSettings::SetSPLIT_RIGHT_OCTAVE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_OCTAVE_NRPN = nValue;
	}


// Values are from LSPitch
void LSPerSplitSettings::SetSPLIT_RIGHT_PITCH_TRANSPOSE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN = nValue;
	}


// Value is an LSExpressionY
void LSPerSplitSettings::SetSPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN = nValue;
}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_FADER1_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER1_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_FADER2_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER2_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_FADER3_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER3_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_FADER4_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER4_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_FADER5_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER5_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_FADER6_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER6_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_FADER7_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER7_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_FADER8_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_FADER8_NRPN = nValue;
}


// Value is an LSLowRowBehaviour
void LSPerSplitSettings::SetSPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN = nValue;
	}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_LOWROW_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_LOWROW_NRPN = nValue;
}


// Value is an LSLowRowBehaviour
void LSPerSplitSettings::SetSPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN = nValue;
	}


// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN = nValue;
}


// Values are constrained by MIN_CC and MAX_CC
void LSPerSplitSettings::SetSPLIT_RIGHT_MIN_CC_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_MAX_CC_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_MIN_CC_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_MAX_CC_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN = nValue;
}


// Value is an LSChannelOrder
void LSPerSplitSettings::SetSPLIT_RIGHT_CHANNEL_PER_ROW_ORDER(unsigned int nValue)
{
	m_SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER = nValue;
	}


// Value is an LSAnimation
void LSPerSplitSettings::SetSPLIT_RIGHT_TOUCH_ANIMATION(unsigned int nValue)
{
	m_SPLIT_RIGHT_TOUCH_ANIMATION = nValue;
}


// Toggle:
void LSPerSplitSettings::SetSPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN = nValue;
	}


void LSPerSplitSettings::SetSPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN = nValue;
	}


// Value is an LSPatternNumber
void LSPerSplitSettings::SetSPLIT_RIGHT_SEQUENCER_PATTERN_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN = nValue;
}


void LSPerSplitSettings::SetSPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN(unsigned int nValue)
{
	m_SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN = nValue;
	}

