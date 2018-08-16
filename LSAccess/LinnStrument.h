// LinnStrument.h
// Constants, classes and related code to support Roger Linn's LinnStrument device

#pragma once

#include <RtMidi.h>
#include <vector>

/*
The following definitions are derived from:

https://github.com/rogerlinndesign/linnstrument-firmware/blob/master/midi.txt

LinnStrument responds to the following MIDI input
================================================ =

Status     Data       Message                 Used for
------------------------------------------------------------------------------------------------------------ -
1001cccc   0nnnnnnn   Note On                 Highlight cells that correspond to the note
0vvvvvvv                           The split is determined by its active MIDI mode channels
c is the channel, n is the note number, v is the velocity
1000cccc   0nnnnnnn   Note Off                Un - highlight cells that correspond to the note
0vvvvvvv                           The split is determined by its active MIDI mode channels
c is the channel, n is the note number, v is the velocity
1011cccc   0nnnnnnn   Control Change          See table below
0vvvvvvv                           c is the channel, n is the cc number, v is the velocity
11111010              Start                   Start listening to MIDI clock and reset ARP
11111011              Continue                Same behavior as Start
11111100              Stop                    Stop listening to MIDI clock and reset ARP
11111000              Timing Clock            Tempo sync, sent 24 times per quarter note
11110010   0lllllll   Song Position Pointer   Beats since song start, used for tempo sync alignment
0mmmmmmm                           l is the LSB, m the MSB
1100cccc   0ppppppp   Program Change          Set the active preset for a split
The split is determined by its active MIDI mode channels
c is the channel, p is the preset number
11111110              Active Sensing          During manufacturing test, show green led at col 25 row 2

MIDI Control Change input
======================== =

CC Number   Used for
------------------------------------------------------------------------------------------------------------ -
1 - 8         Change the position of the CC faders, the split is determined by its active MIDI mode channels
9           Configure User Firmware X - axis row slide, the channel specifies the row(0: disable, 1 : enable)
10          Configure User Firmware X - axis data, the channel specifies the row, default is off(0: disable, 1 : enable)
11          Configure User Firmware Y - axis data, the channel specifies the row, default is off(0: disable, 1 : enable)
12          Configure User Firmware Z - axis data, the channel specifies the row, default is off(0: disable, 1 : enable)
13          Configure User Firmware MIDI decimation rate in milliseconds(minimum 12 ms in low power mode)
20          Column coordinate for cell color change with CC 22 (starts from 0)
21          Row coordinate for cell color change with CC 22 (starts from 0)
22          Change the color of the cell with the provided column and row coordinates
see color value table below, 11 + : default color
*/

/*
NRPN input
==========

NRPN messages are a series of MIDI CC messages that allow changing more parameters than are supported by
the standard MIDI CC message list. LinnStrument always expects an exact series of 6 MIDI CC messages to be
received for setting one NRPN to a different value. The first two select the NRPN parameter number, the
next two set the NRPN parameter value(both MSB and LSB are used), and the last two reset the active NRPN
parameter number. Failure to reset the NRPN parameter number can result in other MIDI input messages to
behave unpredictably.

This is an overview of the message chain :

1011nnnn   01100011 (99)  0vvvvvvv         NRPN parameter number MSB CC
1011nnnn   01100010 (98)  0vvvvvvv         NRPN parameter number LSB CC
1011nnnn   00000110 (6)  0vvvvvvv         NRPN parameter value MSB CC
1011nnnn   00100110 (38)  0vvvvvvv         NRPN parameter value LSB CC
1011nnnn   01100101 (101)  01111111 (127)   RPN parameter number Reset MSB CC
1011nnnn   01100100 (100)  01111111 (127)   RPN parameter number Reset LSB CC

The following table lists all the NRPN input values that LinnStrument understands.

NRPN   Value   Description
------------------------------------------------------------------------------------------------------------ -
*/

// Values for toggle parameters
enum class LSToggleValue
{
	OFF = 0,
	ON = 1
};

// Valid MIDI channel number range:
const unsigned int MIN_MIDI_CHANNEL = 1;
const unsigned int MAX_MIDI_CHANNEL = 16;

enum class LSSplitMode
{
	SINGLE_CHANNEL = 0,
	CHANNEL_PER_NOTE = 1,
	CHANNEL_PER_ROW = 2
};

const unsigned int MIN_BEND_RANGE = 0;
const unsigned int MAX_BEND_RANGE = 96;

enum class LSPitchQuantize
{
	OFF = 0,
	MEDIUM = 1,
	FAST = 2,
	SLOW = 3
};

const unsigned int MIN_CC = 0;
const unsigned int MAX_CC = 127;

const unsigned int MIN_FADER_CC = 0;
const unsigned int MAX_FADER_CC = 128;  // Represents channel aftertouch

enum class LSExpressionY
{
	POLY_AFTERTOUCH = 0,
	CHANNEL_AFTERTOUCH = 1,
	CC_DEFINED_IN_25 = 2
};

enum class LSExpressionZ
{
	POLY_AFTERTOUCH = 0,
	CHANNEL_AFTERTOUCH = 1,
	CC_DEFINED_IN_29 = 2
};

enum class LSLowRowMode
{
	OFF = 0,
	SUST = 1,
	REST = 2,
	STRUM = 3,
	ARP = 4,
	BEND = 5,
	CC1 = 6,
	CC16_CC18 = 7
};

enum class LSSpecial
{
	OFF = 0,
	ARPEG = 1,
	CC_FADERS = 2,
	STRUM = 3,
	SEQUENCER = 4
};

// Color Values
enum class LSColor
{
	OFF = 0,
RED = 1,
	YELLOW = 2,
GREEN = 3,
	CYAN = 4,
BLUE = 5,
	MAGENTA = 6,
BLACK = 7,
	WHITE = 8,
ORANGE = 9,
	LIME = 10,
PINK = 11,
	// Values higher than 11 set the color to default
	DEFAULT = 11
};

enum class LSOctave
{
	MINUS5 = 0,
	MINUS4 = 1,
	MINUS3 = 2,
	MINUS2 = 3,
	MINUS1 = 4,
	ZERO = 5,
	PLUS1 = 6,
	PLUS2 = 7,
	PLUS3 = 8,
	PLUS4 = 9,
	PLUS5 = 10
};

enum class LSPitch
{
	MINUS7 = 0,
	MINUS6 = 1,
	MINUS5 = 2,
	MINUS4 = 3,
	MINUS3 = 4,
	MINUS2 = 5,
	MINUS1 = 6,
	ZERO = 7,
	PLUS1 = 8,
	PLUS2 = 9,
	PLUS3 = 10,
	PLUS4 = 11,
	PLUS5 = 12,
	PLUS6 = 13,
	PLUS7 = 14
};

enum class LSLowRowBehaviour
{
	HOLD = 0,
	FADER = 1
};

enum class LSChannelOrder
{
	NORMAL = 0,
	REVERSED = 1
};

enum class LSAnimation
{
	SAME = 0,
	CROSSES = 1,
	CIRCLES = 2,
	SQUARES = 3,
	DIAMONDS = 4,
	STARS = 5,
	SPARKLES = 6,
	CURTAINS = 7,
	BLINDS = 8,
	TARGETS = 9,
	UP = 10,
	DOWN = 11,
	LEFT = 12,
	RIGHT = 13,
	ORBITS = 14
};

enum class LSPatternNumber
{
	ZERO = 0,
	ONE = 1,
	TWO = 2,
	THREE = 3
};

enum class LSSplitType
{
	LEFT = 0,
	RIGHT = 1
};

const unsigned int MIN_SPLIT_COLUMN = 2;
const unsigned int MAX_SPLIT_COLUMN = 25;

enum class LSRowOffsetType
{
	NO_OVERLAP = 0,
	THIRD = 3,
	FOURTH = 4,
	FIFTH = 5,
	SIXTH = 6,
	SEVENTH = 7,
	OCTAVE = 12,
	GUITAR = 13,
	NO_OFFSET = 127
};

enum class LSSwitchAssignment
{
	OCTAVE_DOWN = 0,
	OCTAVE_UP = 1,
	SUSTAIN = 2,
	CC65 = 3,
	ARP = 4,
	ALT_SPLIT = 5,
	AUTO_OCTAVE = 6,
	TAP_TEMPO = 7,
	LEGATO = 8,
	LATCH = 9,
	PRESET_UP = 10,
	PRESET_DOWN = 11,
	REVERSE_PITCH_X = 12,
	SEQUENCER_PLAY = 13,
	SEQUENCER_PREVIOUS = 14,
	SEQUENCER_NEXT = 15,
	SEND_MIDI_CLOCK = 16,
	SEQUENCER_MUTE = 17
};

enum class LSVelocityRange
{
	LOW = 0,
	MEDIUM = 1,
	HIGH = 2,
	FIXED = 3
};

enum class LSPressureRange
{
	LOW = 0,
	MEDIUM = 1,
	HIGH = 2
};

enum class LSMIDIDevice
{
	MIDI_DIN_JACKS = 0,
	USB = 1
};

enum class LSArpDirection
{
	UP = 0,
	DOWN = 1,
	UP_DOWN = 2,
	RANDOM = 3,
	REPLAY_ALL = 4
};

enum class LSArpTempoNoteType
{
	EIGHTH = 1,
	EIGHTH_TRIPLET = 2,
	SIXTEENTH = 3,
	SIXTEENTH_SWING = 4,
	SIXTEENTH_TRIPLET = 5,
	THIRTY_SECOND = 6,
	THIRTY_SECOND_TRIPLET = 7
};

enum class LSGlobalArpOctaveExtension
{
	NONE = 0,
	PLUS1 = 1,
	PLUS2 = 2
};

enum class LSPresetNumber
{
	ZERO = 0,
	ONE = 1,
	TWO = 2,
	THREE = 3
};

const unsigned int MIN_LIGHTS_PRESET = 0;
const unsigned int MAX_LIGHTS_PRESET = 11;

enum class LSCustomRowOffset
{
	// Semitone intervals:
	MINUS16 = 0,
	MINUS15 = 1,
	MINUS14 = 2,
	MINUS13 = 3,
	MINUS12 = 4,
	MINUS11 = 5,
	MINUS10 = 6,
	MINUS9 = 7,
	MINUS8 = 8,
	MINUS7 = 9,
	MINUS6 = 10,
	MINUS5 = 11,
	MINUS4 = 12,
	MINUS3 = 13,
	MINUS2 = 14,
	MINUS1 = 15,
	ZERO = 16,
	PLUS1 = 17,
	PLUS2 = 18,
	PLUS3 = 19,
	PLUS4 = 20,
	PLUS5 = 21,
	PLUS6 = 22,
	PLUS7 = 23,
	PLUS8 = 24,
	PLUS9 = 25,
	PLUS10 = 26,
	PLUS11 = 27,
	PLUS12 = 28,
	PLUS13 = 29,
	PLUS14 = 30,
	PLUS15 = 31,
	PLUS16 = 32,
	INVERTED_GUITAR = 33
};

const unsigned int SET_NRPN_CC_MSB = 99;
const unsigned int SET_NRPN_CC_LSB = 98;
const unsigned int SET_NRPN_VALUE_MSB = 6;
const unsigned int SET_NRPN_VALUE_LSB = 38;
const unsigned int RESET_NRPN_CC_MSB = 101;
const unsigned int RESET_NRPN_CC_LSB = 100;

// Value is an LSSplitMode
const unsigned int SET_SPLIT_MODE_NRPN = 0;

// Value constrained by MIN_MIDI_CHANNEL and MAX_MIDI_CHANNEL
const unsigned int MIDI_MAIN_CHANNEL_NRPN = 1;

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

// Globals
// Toggle:
const unsigned int GLOBAL_SPLIT_ACTIVE_NRPN = 200;
// Value is LSSplitType
const unsigned int GLOBAL_SELECTED_SPLIT_NRPN = 201;
// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
const unsigned int GLOBAL_SPLIT_COLUMN_NRPN = 202;
// Toggles:
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_C_NRPN = 203;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_NRPN = 204;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_D_NRPN = 205;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_NRPN = 206;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_E_NRPN = 207;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_F_NRPN = 208;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_NRPN = 209;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_G_NRPN = 210;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_NRPN = 211;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_A_NRPN = 212;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_NRPN = 213;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_B_NRPN = 214;

const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_C_NRPN = 215;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_NRPN = 216;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_D_NRPN = 217;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_NRPN = 218;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_E_NRPN = 219;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_F_NRPN = 220;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_NRPN = 221;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_G_NRPN = 222;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_NRPN = 223;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_A_NRPN = 224;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_NRPN = 225;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_B_NRPN = 226;

// Value is LSRowOffsetType
const unsigned int GLOBAL_ROW_OFFSET_NRPN = 227;
// Value is LSSwitchAssignment
int const GLOBAL_SWITCH1_ASSIGN_NRPN = 228;
int const GLOBAL_SWITCH2_ASSIGN_NRPN = 229;
int const GLOBAL_FOOT_LEFT_ASSIGN_NRPN = 230;
int const GLOBAL_FOOT_RIGHT_ASSIGN_NRPN = 231;
// Value is LSVelocityRange
const unsigned int GLOBAL_VELOCITY_SENSITIVITY_NRPN = 232;
// Value is LSPressureRange
const unsigned int GLOBAL_PRESSURE_SENSITIVITY_NRPN = 233;
// Value is LSMIDIDevice
int const GLOBAL_MIDI_DEVICE_IO_NRPN = 234;
// Value is LSArpDirection
const unsigned int GLOBAL_ARP_DIRECTION_NRPN = 235;
// Value is LSArpTempoNoteType
const unsigned int GLOBAL_ARP_TEMPO_NOTE_VALUE_NRPN = 236;
// Value is LSGlobalArpOctaveExtension
const unsigned int GLOBAL_ARP_OCTAVE_EXTENSION_NRPN = 237;
// Value = 1 - 360  (applies when receiving no MIDI clock)
const unsigned int GLOBAL_CLOCK_BPM_NRPN = 238;
// Toggle:
const unsigned int GLOBAL_SWITCH1_BOTH_SPLITS_NRPN = 239;
const unsigned int GLOBAL_SWITCH2_BOTH_SPLITS_NRPN = 240;
const unsigned int GLOBAL_FOOT_LEFT_BOTH_SPLITS_NRPN = 241;
const unsigned int GLOBAL_FOOT_RIGHT_BOTH_SPLITS_NRPN = 242;
// Value is LSPresetNumber
const unsigned int GLOBAL_SETTINGS_PRESET_LOAD_NRPN = 243;
// Toggles:
const unsigned int GLOBAL_PRESSURE_AFTERTOUCH_NRPN = 244;
const unsigned int DEVICE_USER_FIRMWARE_MODE_NRPN = 245;
const unsigned int DEVICE_LEFT_HANDED_NRPN = 246;
// Value is constrained by MIN_LIGHTS_PRESET and MAX_LIGHTS_PRESET 
const unsigned int GLOBAL_ACTIVE_LIGHTS_PRESET_NRPN = 247;
// Values are constrained by MIN_CC and MAX_CC
const unsigned int GLOABAL_CC_FOR_CC65 = 248;  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
									  // Values are constrained by MIN_CC and MAX_CC
const unsigned int GLOBAL_MIN_VELOCITY_VALUE_NRPN = 249;
const unsigned int GLOBAL_MAX_VELOCITY_VALUE_NRPN = 250;
const unsigned int GLOBAL_FIXED_VELOCITY_VALUE_NRPN = 251;
// Value range =     0 - 512  
const unsigned int DEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN = 252;
// Value is LSCustomRowOffset
const unsigned int GLOBAL_CUSTOM_ROW_OFFSET = 253;
// Toggle:
const unsigned int DEVICE_MIDI_THRU_NRPN = 254;
// Values are constrained by MIN_CC and MAX_CC
const unsigned int GLOBAL_CC_FOR_LEFT_FOOT_CC65 = 255;
const unsigned int GLOBAL_CC_FOR_RIGHT_FOOT_CC65 = 256;
const unsigned int GLOBAL_CC_FOR_SWITCH1_CC65 = 257;
const unsigned int GLOBAL_CC_FOR_SWITCH2_CC65 = 258;
const unsigned int GLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN = 259;
const unsigned int GLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN = 260;
const unsigned int GLOBAL_CC_FOR_SWITCH1_SUSTAIN = 261;
const unsigned int GLOBAL_CC_FOR_SWITCH2_SUSTAIN = 262;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW1 = 263;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW2 = 264;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW3 = 265;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW4 = 266;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW5 = 267;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW6 = 268;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW7 = 269;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW8 = 270;

const unsigned int REQUEST_VALUE_OF_NRPN = 299;


class LinnStrument
{
public:
	LinnStrument();
	void ProcessMessage(std::vector <unsigned char> vBytes);

private:
		// MIDI devices
RtMidiIn m_MIDIIn;
	RtMidiOut m_MIDIOut;
	};

void LSCallback(double deltatime, std::vector< unsigned char > *message, void *pLinnStrument);
