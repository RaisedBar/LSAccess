// LSPerSplit.h
// LinnStrument per-split settings

#pragma once

// Left-hand split
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
// Value is from LSBendRange
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
const unsigned int SPLIT_LEFT_RELATIVE_Z_NRPN = 27;
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
// Value is an LSOctave
const unsigned int SPLIT_LEFT_OCTAVE_NRPN = 36;
// Values are from LSPitch
const unsigned int SPLIT_LEFT_PITCH_TRANSPOSE_NRPN = 37;
const unsigned int SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN = 38;
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
const unsigned int SPLIT_LEFT_CHANNEL_PER_ROW_ORDER = 60;
// Value is an LSAnimation
const unsigned int SPLIT_LEFT_TOUCH_ANIMATION = 61;

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
const unsigned int SPLIT_RIGHT_MAIN_CHANNEL = 101;
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
const unsigned int SPLIT_RIGHT_RELATIVE_Z_NRPN = 127;
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
// Value is an LSOctave
const unsigned int SPLIT_RIGHT_OCTAVE_NRPN = 136;
// Values are from LSPitch
const unsigned int SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN = 137;
const unsigned int SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN = 138;
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
const unsigned int SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER = 160;
// Value is an LSAnimation
const unsigned int SPLIT_RIGHT_TOUCH_ANIMATION = 161;

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
	LSPerSplitSettings();

	// Left-hand split
// Toggles:
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN();
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN();
	// Value is a MIDI channel number:
	unsigned int GetSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN();
	// Value is from LSBendRange
	unsigned int GetSPLIT_LEFT_BEND_RANGE_NRPN();
	// Toggles:
	unsigned int GetSPLIT_LEFT_BEND_TOGGLE_NRPN();
	unsigned int GetSPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN();
	// Value is from LSPitchQuantize
	unsigned int GetSPLIT_LEFT_PITCH_QUANTIZE_NRPN();
	// Toggles:
	unsigned int GetSPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN();
	unsigned int GetSPLIT_LEFT_SEND_Y_NRPN();
	// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	unsigned int GetSPLIT_LEFT_CC_FOR_Y_NRPN();
	// Toggle:
	unsigned int GetSPLIT_LEFT_RELATIVE_Y_NRPN();
	unsigned int GetSPLIT_LEFT_RELATIVE_Z_NRPN();
	// Value is an LSExpressionZ
	unsigned int GetSPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN();
	// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
	unsigned int GetSPLIT_LEFT_CC_FOR_Z_NRPN();
	// Values are defined in LSColor
	unsigned int GetSPLIT_LEFT_COLOR_MAIN_NRPN();
	unsigned int GetSPLIT_LEFT_COLOR_ACCENT_NRPN();
	unsigned int GetSPLIT_LEFT_COLOR_PLAYED_NRPN();
	unsigned int GetSPLIT_LEFT_COLOR_LOWROW_NRPN();
	// Value is an LSLowRowMode
	unsigned int GetSPLIT_LEFT_LOWROW_MODE_NRPN();
	// Value is an LSSpecial:
	unsigned int GetSPLIT_LEFT_SPECIAL_NRPN();
	// Value is an LSOctave
	unsigned int GetSPLIT_LEFT_OCTAVE_NRPN();
	// Values are from LSPitch
	unsigned int GetSPLIT_LEFT_PITCH_TRANSPOSE_NRPN();
	unsigned int GetSPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN();
	// Value is an LSExpressionY
	unsigned int GetSPLIT_LEFT_EXPRESSION_FOR_Y_NRPN();
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int GetSPLIT_LEFT_CC_FOR_FADER1_NRPN();
	unsigned int GetSPLIT_LEFT_CC_FOR_FADER2_NRPN();
	unsigned int GetSPLIT_LEFT_CC_FOR_FADER3_NRPN();
	unsigned int GetSPLIT_LEFT_CC_FOR_FADER4_NRPN();
	unsigned int GetSPLIT_LEFT_CC_FOR_FADER5_NRPN();
	unsigned int GetSPLIT_LEFT_CC_FOR_FADER6_NRPN();
	unsigned int GetSPLIT_LEFT_CC_FOR_FADER7_NRPN();
	unsigned int GetSPLIT_LEFT_CC_FOR_FADER8_NRPN();
	// Value is an LSLowRowBehaviour
	unsigned int GetSPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN();
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int GetSPLIT_LEFT_CC_FOR_LOWROW_NRPN();
	// Value is an LSLowRowBehaviour
	unsigned int GetSPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN();
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int GetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN();
	unsigned int GetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN();
	unsigned int GetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN();
	// Values are constrained by MIN_CC and MAX_CC
	unsigned int GetSPLIT_LEFT_MIN_CC_FOR_Y_NRPN();
	unsigned int GetSPLIT_LEFT_MAX_CC_FOR_Y_NRPN();
	unsigned int GetSPLIT_LEFT_MIN_CC_FOR_Z_NRPN();
	unsigned int GetSPLIT_LEFT_MAX_CC_FOR_Z_NRPN();
	unsigned int GetSPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN();
	unsigned int GetSPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN();
	// Value is an LSChannelOrder
	unsigned int GetSPLIT_LEFT_CHANNEL_PER_ROW_ORDER();
	// Value is an LSAnimation
	unsigned int GetSPLIT_LEFT_TOUCH_ANIMATION();
	// Toggle:
	unsigned int GetSPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN();
	unsigned int GetSPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN();
	unsigned int GetSPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN();
	// Value is an LSPatternNumber
	unsigned int GetSPLIT_LEFT_SEQUENCER_PATTERN_NRPN();
	unsigned int GetSPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN();

	// Setters:
	// Value is an LSSplitMode
	void SetSPLIT_MODE_NRPN(unsigned int nValue);
	// Value constrained by MIN_MIDI_CHANNEL and MAX_MIDI_CHANNEL
	void SetMIDI_MAIN_CHANNEL_NRPN(unsigned int nValue);

	// Left-hand split
	// Toggles:
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN(unsigned int nValue);
	// Value is a MIDI channel number:
	void SetSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN(unsigned int nValue);
	// Value is from LSBendRange
	void SetSPLIT_LEFT_BEND_RANGE_NRPN(unsigned int nValue);
	// Toggles:
	void SetSPLIT_LEFT_BEND_TOGGLE_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN(unsigned int nValue);
	// Value is from LSPitchQuantize
	void SetSPLIT_LEFT_PITCH_QUANTIZE_NRPN(unsigned int nValue);
	// Toggles:
	void SetSPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_SEND_Y_NRPN(unsigned int nValue);
	// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	void SetSPLIT_LEFT_CC_FOR_Y_NRPN(unsigned int nValue);
	// Toggle:
	void SetSPLIT_LEFT_RELATIVE_Y_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_RELATIVE_Z_NRPN(unsigned int nValue);
	// Value is an LSExpressionZ
	void SetSPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN(unsigned int nValue);
	// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
	void SetSPLIT_LEFT_CC_FOR_Z_NRPN(unsigned int nValue);
	// Values are defined in LSColor
	void SetSPLIT_LEFT_COLOR_MAIN_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_COLOR_ACCENT_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_COLOR_PLAYED_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_COLOR_LOWROW_NRPN(unsigned int nValue);
	// Value is an LSLowRowMode
	void SetSPLIT_LEFT_LOWROW_MODE_NRPN(unsigned int nValue);
	// Value is an LSSpecial:
	void SetSPLIT_LEFT_SPECIAL_NRPN(unsigned int nValue);
	// Value is an LSOctave
	void SetSPLIT_LEFT_OCTAVE_NRPN(unsigned int nValue);
	// Values are from LSPitch
	void SetSPLIT_LEFT_PITCH_TRANSPOSE_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN(unsigned int nValue);
	// Value is an LSExpressionY
	void SetSPLIT_LEFT_EXPRESSION_FOR_Y_NRPN(unsigned int nValue);
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	void SetSPLIT_LEFT_CC_FOR_FADER1_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CC_FOR_FADER2_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CC_FOR_FADER3_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CC_FOR_FADER4_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CC_FOR_FADER5_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CC_FOR_FADER6_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CC_FOR_FADER7_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CC_FOR_FADER8_NRPN(unsigned int nValue);
	// Value is an LSLowRowBehaviour
	void SetSPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN(unsigned int nValue);
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	void SetSPLIT_LEFT_CC_FOR_LOWROW_NRPN(unsigned int nValue);
	// Value is an LSLowRowBehaviour
	void SetSPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN(unsigned int nValue);
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	void SetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN(unsigned int nValue);
	// Values are constrained by MIN_CC and MAX_CC
	void SetSPLIT_LEFT_MIN_CC_FOR_Y_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_MAX_CC_FOR_Y_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_MIN_CC_FOR_Z_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_MAX_CC_FOR_Z_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN(unsigned int nValue);
	// Value is an LSChannelOrder
	void SetSPLIT_LEFT_CHANNEL_PER_ROW_ORDER(unsigned int nValue);
	// Value is an LSAnimation
	void SetSPLIT_LEFT_TOUCH_ANIMATION(unsigned int nValue);
	// Toggle:
	void SetSPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN(unsigned int nValue);
	// Value is an LSPatternNumber
	void SetSPLIT_LEFT_SEQUENCER_PATTERN_NRPN(unsigned int nValue);
	void SetSPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN(unsigned int nValue);

	// Getters:
		// Right-hand split
	unsigned int GetSPLIT_RIGHT_MAIN_MODE_NRPN();
	unsigned int GetSPLIT_RIGHT_MAIN_CHANNEL();
	// Toggles:
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN();
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN();
	// Value is a MIDI channel number:
	unsigned int GetSPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN();
	// Value is from LSBendRange
	unsigned int GetSPLIT_RIGHT_BEND_RANGE_NRPN();
	// Toggles:
	unsigned int GetSPLIT_RIGHT_BEND_TOGGLE_NRPN();
	unsigned int GetSPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN();
	// Value is from LSPitchQuantize
	unsigned int GetSPLIT_RIGHT_PITCH_QUANTIZE_NRPN();
	// Toggles:
	unsigned int GetSPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN();
	unsigned int GetSPLIT_RIGHT_SEND_Y_NRPN();
	// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	unsigned int GetSPLIT_RIGHT_CC_FOR_Y_NRPN();
	// Toggle:
	unsigned int GetSPLIT_RIGHT_RELATIVE_Y_NRPN();
	unsigned int GetSPLIT_RIGHT_RELATIVE_Z_NRPN();
	// Value is an LSExpressionZ
	unsigned int GetSPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN();
	// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
	unsigned int GetSPLIT_RIGHT_CC_FOR_Z_NRPN();
	// Values are defined in LSColor
	unsigned int GetSPLIT_RIGHT_COLOR_MAIN_NRPN();
	unsigned int GetSPLIT_RIGHT_COLOR_ACCENT_NRPN();
	unsigned int GetSPLIT_RIGHT_COLOR_PLAYED_NRPN();
	unsigned int GetSPLIT_RIGHT_COLOR_LOWROW_NRPN();
	// Value is an LSLowRowMode
	unsigned int GetSPLIT_RIGHT_LOWROW_MODE_NRPN();
	// Value is an LSSpecial:
	unsigned int GetSPLIT_RIGHT_SPECIAL_NRPN();
	// Value is an LSOctave
	unsigned int GetSPLIT_RIGHT_OCTAVE_NRPN();
	// Values are from LSPitch
	unsigned int GetSPLIT_RIGHT_PITCH_TRANSPOSE_NRPN();
	unsigned int GetSPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN();
	// Value is an LSExpressionY
	unsigned int GetSPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN();
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int GetSPLIT_RIGHT_CC_FOR_FADER1_NRPN();
	unsigned int GetSPLIT_RIGHT_CC_FOR_FADER2_NRPN();
	unsigned int GetSPLIT_RIGHT_CC_FOR_FADER3_NRPN();
	unsigned int GetSPLIT_RIGHT_CC_FOR_FADER4_NRPN();
	unsigned int GetSPLIT_RIGHT_CC_FOR_FADER5_NRPN();
	unsigned int GetSPLIT_RIGHT_CC_FOR_FADER6_NRPN();
	unsigned int GetSPLIT_RIGHT_CC_FOR_FADER7_NRPN();
	unsigned int GetSPLIT_RIGHT_CC_FOR_FADER8_NRPN();
	// Value is an LSLowRowBehaviour
	unsigned int GetSPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN();
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int GetSPLIT_RIGHT_CC_FOR_LOWROW_NRPN();
	// Value is an LSLowRowBehaviour
	unsigned int GetSPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN();
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int GetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN();
	unsigned int GetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN();
	unsigned int GetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN();
	// Values are constrained by MIN_CC and MAX_CC
	unsigned int GetSPLIT_RIGHT_MIN_CC_FOR_Y_NRPN();
	unsigned int GetSPLIT_RIGHT_MAX_CC_FOR_Y_NRPN();
	unsigned int GetSPLIT_RIGHT_MIN_CC_FOR_Z_NRPN();
	unsigned int GetSPLIT_RIGHT_MAX_CC_FOR_Z_NRPN();
	unsigned int GetSPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN();
	unsigned int GetSPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN();
	// Value is an LSChannelOrder
	unsigned int GetSPLIT_RIGHT_CHANNEL_PER_ROW_ORDER();
	// Value is an LSAnimation
	unsigned int GetSPLIT_RIGHT_TOUCH_ANIMATION();
	// Toggle:
	unsigned int GetSPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN();
	unsigned int GetSPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN();
	unsigned int GetSPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN();
	// Value is an LSPatternNumber
	unsigned int GetSPLIT_RIGHT_SEQUENCER_PATTERN_NRPN();
	unsigned int GetSPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN();

	// Setters:
	// Right-hand split
	// Toggles:
	void SetSPLIT_RIGHT_MAIN_MODE_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_MAIN_CHANNEL(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN(unsigned int nValue);
	// Value is a MIDI channel number:
	void SetSPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN(unsigned int nValue);
	// Value is from LSBendRange
	void SetSPLIT_RIGHT_BEND_RANGE_NRPN(unsigned int nValue);
	// Toggles:
	void SetSPLIT_RIGHT_BEND_TOGGLE_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN(unsigned int nValue);
	// Value is from LSPitchQuantize
	void SetSPLIT_RIGHT_PITCH_QUANTIZE_NRPN(unsigned int nValue);
	// Toggles:
	void SetSPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_SEND_Y_NRPN(unsigned int nValue);
	// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	void SetSPLIT_RIGHT_CC_FOR_Y_NRPN(unsigned int nValue);
	// Toggle:
	void SetSPLIT_RIGHT_RELATIVE_Y_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_RELATIVE_Z_NRPN(unsigned int nValue);
	// Value is an LSExpressionZ
	void SetSPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN(unsigned int nValue);
	// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
	void SetSPLIT_RIGHT_CC_FOR_Z_NRPN(unsigned int nValue);
	// Values are defined in LSColor
	void SetSPLIT_RIGHT_COLOR_MAIN_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_COLOR_ACCENT_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_COLOR_PLAYED_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_COLOR_LOWROW_NRPN(unsigned int nValue);
	// Value is an LSLowRowMode
	void SetSPLIT_RIGHT_LOWROW_MODE_NRPN(unsigned int nValue);
	// Value is an LSSpecial:
	void SetSPLIT_RIGHT_SPECIAL_NRPN(unsigned int nValue);
	// Value is an LSOctave
	void SetSPLIT_RIGHT_OCTAVE_NRPN(unsigned int nValue);
	// Values are from LSPitch
	void SetSPLIT_RIGHT_PITCH_TRANSPOSE_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN(unsigned int nValue);
	// Value is an LSExpressionY
	void SetSPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN(unsigned int nValue);
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	void SetSPLIT_RIGHT_CC_FOR_FADER1_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CC_FOR_FADER2_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CC_FOR_FADER3_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CC_FOR_FADER4_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CC_FOR_FADER5_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CC_FOR_FADER6_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CC_FOR_FADER7_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CC_FOR_FADER8_NRPN(unsigned int nValue);
	// Value is an LSLowRowBehaviour
	void SetSPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN(unsigned int nValue);
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	void SetSPLIT_RIGHT_CC_FOR_LOWROW_NRPN(unsigned int nValue);
	// Value is an LSLowRowBehaviour
	void SetSPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN(unsigned int nValue);
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	void SetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN(unsigned int nValue);
	// Values are constrained by MIN_CC and MAX_CC
	void SetSPLIT_RIGHT_MIN_CC_FOR_Y_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_MAX_CC_FOR_Y_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_MIN_CC_FOR_Z_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_MAX_CC_FOR_Z_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN(unsigned int nValue);
	// Value is an LSChannelOrder
	void SetSPLIT_RIGHT_CHANNEL_PER_ROW_ORDER(unsigned int nValue);
	// Value is an LSAnimation
	void SetSPLIT_RIGHT_TOUCH_ANIMATION(unsigned int nValue);
	// Toggle:
	void SetSPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN(unsigned int nValue);
	// Value is an LSPatternNumber
	void SetSPLIT_RIGHT_SEQUENCER_PATTERN_NRPN(unsigned int nValue);
	void SetSPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN(unsigned int nValue);

private:
	// Left-hand split
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN;
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN;
	// Value is a MIDI channel number:
	unsigned int m_SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN;
	// Value is from LSBendRange
	unsigned int m_SPLIT_LEFT_BEND_RANGE_NRPN;
	// Toggles:
	unsigned int m_SPLIT_LEFT_BEND_TOGGLE_NRPN;
	unsigned int m_SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN;
	// Value is from LSPitchQuantize
	unsigned int m_SPLIT_LEFT_PITCH_QUANTIZE_NRPN;
	// Toggles:
	unsigned int m_SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN;
	unsigned int m_SPLIT_LEFT_SEND_Y_NRPN;
	// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	unsigned int m_SPLIT_LEFT_CC_FOR_Y_NRPN;
	// Toggle:
	unsigned int m_SPLIT_LEFT_RELATIVE_Y_NRPN;
	unsigned int m_SPLIT_LEFT_RELATIVE_Z_NRPN;
	// Value is an LSExpressionZ
	unsigned int m_SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN;
	// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
	unsigned int m_SPLIT_LEFT_CC_FOR_Z_NRPN;
	// Values are defined in LSColor
	unsigned int m_SPLIT_LEFT_COLOR_MAIN_NRPN;
	unsigned int m_SPLIT_LEFT_COLOR_ACCENT_NRPN;
	unsigned int m_SPLIT_LEFT_COLOR_PLAYED_NRPN;
	unsigned int m_SPLIT_LEFT_COLOR_LOWROW_NRPN;
	// Value is an LSLowRowMode
	unsigned int m_SPLIT_LEFT_LOWROW_MODE_NRPN;
	// Value is an LSSpecial:
	unsigned int m_SPLIT_LEFT_SPECIAL_NRPN;
	// Value is an LSOctave
	unsigned int m_SPLIT_LEFT_OCTAVE_NRPN;
	// Values are from LSPitch
	unsigned int m_SPLIT_LEFT_PITCH_TRANSPOSE_NRPN;
	unsigned int m_SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN;
	// Value is an LSExpressionY
	unsigned int m_SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN;
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int m_SPLIT_LEFT_CC_FOR_FADER1_NRPN;
	unsigned int m_SPLIT_LEFT_CC_FOR_FADER2_NRPN;
	unsigned int m_SPLIT_LEFT_CC_FOR_FADER3_NRPN;
	unsigned int m_SPLIT_LEFT_CC_FOR_FADER4_NRPN;
	unsigned int m_SPLIT_LEFT_CC_FOR_FADER5_NRPN;
	unsigned int m_SPLIT_LEFT_CC_FOR_FADER6_NRPN;
	unsigned int m_SPLIT_LEFT_CC_FOR_FADER7_NRPN;
	unsigned int m_SPLIT_LEFT_CC_FOR_FADER8_NRPN;
	// Value is an LSLowRowBehaviour
	unsigned int m_SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN;
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int m_SPLIT_LEFT_CC_FOR_LOWROW_NRPN;
	// Value is an LSLowRowBehaviour
	unsigned int m_SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN;
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN;
	unsigned int m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN;
	unsigned int m_SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN;
	// Values are constrained by MIN_CC and MAX_CC
	unsigned int m_SPLIT_LEFT_MIN_CC_FOR_Y_NRPN;
	unsigned int m_SPLIT_LEFT_MAX_CC_FOR_Y_NRPN;
	unsigned int m_SPLIT_LEFT_MIN_CC_FOR_Z_NRPN;
	unsigned int m_SPLIT_LEFT_MAX_CC_FOR_Z_NRPN;
	unsigned int m_SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN;
	unsigned int m_SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN;
	// Value is an LSChannelOrder
	unsigned int m_SPLIT_LEFT_CHANNEL_PER_ROW_ORDER;
	// Value is an LSAnimation
	unsigned int m_SPLIT_LEFT_TOUCH_ANIMATION;
	// Toggle:
	unsigned int m_SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN;
	unsigned int m_SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN;
	unsigned int m_SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN;
	// Value is an LSPatternNumber
	unsigned int m_SPLIT_LEFT_SEQUENCER_PATTERN_NRPN;
	unsigned int m_SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN;

	// Right-hand split
	unsigned int m_SPLIT_RIGHT_MAIN_MODE_NRPN;
	unsigned int m_SPLIT_RIGHT_MAIN_CHANNEL;
	// Toggles:
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN;
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN;
	// Value is a MIDI channel number:
	unsigned int m_SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN;
	// Value is from LSBendRange
	unsigned int m_SPLIT_RIGHT_BEND_RANGE_NRPN;
	// Toggles:
	unsigned int m_SPLIT_RIGHT_BEND_TOGGLE_NRPN;
	unsigned int m_SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN;
	// Value is from LSPitchQuantize
	unsigned int m_SPLIT_RIGHT_PITCH_QUANTIZE_NRPN;
	// Toggles:
	unsigned int m_SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN;
	unsigned int m_SPLIT_RIGHT_SEND_Y_NRPN;
	// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	unsigned int m_SPLIT_RIGHT_CC_FOR_Y_NRPN;
	// Toggle:
	unsigned int m_SPLIT_RIGHT_RELATIVE_Y_NRPN;
	unsigned int m_SPLIT_RIGHT_RELATIVE_Z_NRPN;
	// Value is an LSExpressionZ
	unsigned int m_SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN;
	// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
	unsigned int m_SPLIT_RIGHT_CC_FOR_Z_NRPN;
	// Values are defined in LSColor
	unsigned int m_SPLIT_RIGHT_COLOR_MAIN_NRPN;
	unsigned int m_SPLIT_RIGHT_COLOR_ACCENT_NRPN;
	unsigned int m_SPLIT_RIGHT_COLOR_PLAYED_NRPN;
	unsigned int m_SPLIT_RIGHT_COLOR_LOWROW_NRPN;
	// Value is an LSLowRowMode
	unsigned int m_SPLIT_RIGHT_LOWROW_MODE_NRPN;
	// Value is an LSSpecial:
	unsigned int m_SPLIT_RIGHT_SPECIAL_NRPN;
	// Value is an LSOctave
	unsigned int m_SPLIT_RIGHT_OCTAVE_NRPN;
	// Values are from LSPitch
	unsigned int m_SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN;
	unsigned int m_SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN;
	// Value is an LSExpressionY
	unsigned int m_SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN;
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int m_SPLIT_RIGHT_CC_FOR_FADER1_NRPN;
	unsigned int m_SPLIT_RIGHT_CC_FOR_FADER2_NRPN;
	unsigned int m_SPLIT_RIGHT_CC_FOR_FADER3_NRPN;
	unsigned int m_SPLIT_RIGHT_CC_FOR_FADER4_NRPN;
	unsigned int m_SPLIT_RIGHT_CC_FOR_FADER5_NRPN;
	unsigned int m_SPLIT_RIGHT_CC_FOR_FADER6_NRPN;
	unsigned int m_SPLIT_RIGHT_CC_FOR_FADER7_NRPN;
	unsigned int m_SPLIT_RIGHT_CC_FOR_FADER8_NRPN;
	// Value is an LSLowRowBehaviour
	unsigned int m_SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN;
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int m_SPLIT_RIGHT_CC_FOR_LOWROW_NRPN;
	// Value is an LSLowRowBehaviour
	unsigned int m_SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN;
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	unsigned int m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN;
	unsigned int m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN;
	unsigned int m_SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN;
	// Values are constrained by MIN_CC and MAX_CC
	unsigned int m_SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN;
	unsigned int m_SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN;
	unsigned int m_SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN;
	unsigned int m_SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN;
	unsigned int m_SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN;
	unsigned int m_SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN;
	// Value is an LSChannelOrder
	unsigned int m_SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER;
	// Value is an LSAnimation
	unsigned int m_SPLIT_RIGHT_TOUCH_ANIMATION;
	// Toggle:
	unsigned int m_SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN;
	unsigned int m_SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN;
	unsigned int m_SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN;
	// Value is an LSPatternNumber
	unsigned int m_SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN;
	unsigned int m_SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN;
};

