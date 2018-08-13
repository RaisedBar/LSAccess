#pragma once

#include "resource.h"

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
enum LSToggleValue
{
	OFF = 0,
	ON = 1
};

// Valid MIDI channel number range:
enum MIDIChannelRange
{
	MIN = 1,
	MAX = 16
};

enum LSSplitMode
{
	SINGLE_CHANNEL = 0,
	CHANNEL_PER_NOTE = 1,
	CHANNEL_PER_ROW = 2
};

enum LSBendRange
{
	MIN = 0,
	MAX = 96
};

enum LSPitchQuantize
{
	OFF = 0,
MEDIUM = 1,
	FAST = 2,
SLOW = 3
};

enum LSCCRange
{
	MIN = 0,
	MAX = 127
};

enum LSFaderCCRange
{
	MIN = 0,
	CHANNEL_AFTERTOUCH = 128
};

enum LSExpressionY
{
	POLY_AFTERTOUCH = 0,
	CHANNEL_AFTERTOUCH = 1,
	CC_DEFINED_IN_25 = 2
};

enum LSExpressionZ
{
	POLY_AFTERTOUCH = 0,
	CHANNEL_AFTERTOUCH = 1,
	CC_DEFINED_IN_29 = 2
};

enum LSLowRowMode
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

enum LSSpecial
{
	OFF = 0,
	ARPEG = 1,
	CC_FADERS = 2,
	STRUM = 3,
	SEQUENCER = 4
};


// Color Values
enum LSColor
{
	COLOR_OFF = 0,
	COLOR_RED = 1,
	COLOR_YELLOW = 2,
	COLOR_GREEN = 3,
	COLOR_CYAN = 4,
	COLOR_BLUE = 5,
	COLOR_MAGENTA = 6,
	COLOR_BLACK = 7,
	COLOR_WHITE = 8,
	COLOR_ORANGE = 9,
	COLOR_LIME = 10,
	COLOR_PINK = 11
	// Values higher than 11 set the color to default
};

enum LSOctave
{
	MINUS5 = 0,
	MINUS4 = 1,
	MINUS3 = 2,
	MINUS2 = 3,
	MINUS1 = 4,
	ZERO = 5,
	PLUS1 = 6,
	PLUS2 = 7,
	PLUS3 = 8
	PLUS4 = 9,
	PLUS5 = 10
};

enum LSPitch
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

enum LSLowRowBehaviour
{
	HOLD = 0,
	FADER = 1
};

enum LSChannelOrder
{
	NORMAL = 0,
	REVERSED = 1
};

enum LSAnimation
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

enum LSPatternNumber
{
	ZERO = 0,
	ONE = 1,
	TWO = 2,
	THREE = 3
};

const int SET_NRPN_CC_MSB = 99;
const int SET_NRPN_CC_LSB = 98;
const int SET_NRPN_VALUE_MSB = 6;
const int SET_NRPN_VALUE_LSB = 38;
const int RESET_NRPN_CC_MSB = 101;
const int RESET_NRPN_CC_LSB = 100;

// Value is an LSSplitMode
const int SET_SPLIT_MODE_NRPN = 0;

// Value is from MIDIChannelRange
const int MIDI_MAIN_CHANNEL_NRPN = 1;

// Left-hand split
// Toggles:
const int SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN = 2;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN = 3;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN = 4;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN = 5;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN = 6;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN = 7;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN = 8;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN = 9;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN = 10;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN = 11;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN = 12;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN = 13;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN = 14;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN = 15;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN = 16;
const int SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN = 17;
// Value is a MIDI channel number:
const int SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN = 18;
// Value is from LSBendRange
const int SPLIT_LEFT_BEND_RANGE_NRPN = 19;
// Toggles:
const int SPLIT_LEFT_BEND_TOGGLE_NRPN = 20;
const int SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN = 21;
// Value is from LSPitchQuantize
const int SPLIT_LEFT_PITCH_QUANTIZE_NRPN = 22;
// Toggles:
const int SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN = 23;
const int SPLIT_LEFT_SEND_Y_NRPN = 24;
// Value is from LSCCRange
// CC 1 or CC 74 are recommended, any CC is possible though
const int SPLIT_LEFT_CC_FOR_Y_NRPN = 25; 
// Toggle:
const int SPLIT_LEFT_RELATIVE_Y_NRPN = 26;
const int SPLIT_LEFT_RELATIVE_Z_NRPN = 27;
// Value is an LSExpressionZ
const int SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN = 28;
// Value is an LSCCRange
// CC 11 is recommended, any CC is possible though
const int SPLIT_LEFT_CC_FOR_Z_NRPN = 29;
// Values are defined in LSColor
const int SPLIT_LEFT_COLOR_MAIN_NRPN = 30;
const int SPLIT_LEFT_COLOR_ACCENT_NRPN = 31;
const int SPLIT_LEFT_COLOR_PLAYED_NRPN = 32;
const int SPLIT_LEFT_COLOR_LOWROW_NRPN = 33;
// Value is an LSLowRowMode
const int SPLIT_LEFT_LOWROW_MODE_NRPN = 34;
// Value is an LSSpecial:
const int SPLIT_LEFT_SPECIAL_NRPN = 35;
// Value is an LSOctave
const int SPLIT_LEFT_OCTAVE_NRPN = 36;
// Values are from LSPitch
const int LEFT_SPLIT_PITCH_TRANSPOSE_NRPN = 37;
const int SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN = 38;
// Value is an LSExpressionY
const int SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN = 39;

// Values are an LSFaderCCRange
const int SPLIT_LEFT_CC_FOR_FADER1_NRPN = 40;
const int SPLIT_LEFT_CC_FOR_FADER2_NRPN = 41;
const int SPLIT_LEFT_CC_FOR_FADER3_NRPN = 42;
const int SPLIT_LEFT_CC_FOR_FADER4_NRPN = 43;
const int SPLIT_LEFT_CC_FOR_FADER5_NRPN = 44;
const int SPLIT_LEFT_CC_FOR_FADER6_NRPN = 45;
const int SPLIT_LEFT_CC_FOR_FADER7_NRPN = 46;
const int SPLIT_LEFT_CC_FOR_FADER8_NRPN = 47;
// Value is an LSLowRowBehaviour
const int SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN = 48;
// Value is an LSFaderCCRange
const int SPLIT_LEFT_CC_FOR_LOWROW_NRPN = 49;
// Value is an LSLowRowBehaviour
const int SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN = 50;
// Values are an LSFaderCCRange
const int SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN = 51;
const int SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN = 52;
const int SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN = 53;
// Values are an LSCCRange
const int SPLIT_LEFT_MIN_CC_FOR_Y_NRPN = 54;
const int SPLIT_LEFT_MAX_CC_FOR_Y_NRPN = 55;
const int SPLIT_LEFT_MIN_CC_FOR_Z_NRPN = 56;
const int SPLIT_LEFT_MAX_CC_FOR_Z_NRPN = 57;
const int SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN = 58;
const int SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN = 59;
// Value is an LSChannelOrder
const int SPLIT_LEFT_CHANNEL_PER_ROW_ORDER = 60;
// Value is an LSAnimation
const int SPLIT_LEFT_TOUCH_ANIMATION = 61;

// Toggle:
const int SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN = 62;
const SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN = 63;
const SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN = 64;
// Value is an LSPatternNumber
const int SPLIT_LEFT_SEQUENCER_PATTERN_NRPN = 65;
const int SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN = 66;


// Right-hand split
// Value is an LSSplitMode
const int SPLIT_RIGHT_MAIN_MODE_NRPN = 100;
// Value is a MIDIChannel
const int SPLIT_RIGHT_MAIN_CHANNEL = 101;
// Toggles:
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN = 102;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN = 103;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN = 104;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN = 105;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN = 106;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN = 107;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN = 108;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN = 109;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN = 110;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN = 111;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN = 112;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN = 113;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN = 114;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN = 115;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN = 116;
const int SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN = 117;
// Value is a MIDI channel number:
const int SPLIT_RIGHT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN = 118;
// Value is from LSBendRange
const int SPLIT_RIGHT_BEND_RANGE_NRPN = 119;
// Toggles:
const int SPLIT_RIGHT_BEND_TOGGLE_NRPN = 120;
const int SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN = 121;
// Value is from LSPitchQuantize
const int SPLIT_RIGHT_PITCH_QUANTIZE_NRPN = 122;
// Toggles:
const int SPLIT_RIGHT_RESET_PITCH_ON_RELEASE_NRPN = 123;
const int SPLIT_RIGHT_SEND_Y_NRPN = 124;
// Value is from LSCCRange
// CC 1 or CC 74 are recommended, any CC is possible though
const int SPLIT_RIGHT_CC_FOR_Y_NRPN = 125;
// Toggle:
const int SPLIT_RIGHT_RELATIVE_Y_NRPN = 126;
const int SPLIT_RIGHT_RELATIVE_Z_NRPN = 127;
// Value is an LSExpressionZ
const int SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN = 128;
// Value is an LSCCRange
// CC 11 is recommended, any CC is possible though
const int SPLIT_RIGHT_CC_FOR_Z_NRPN = 129;
// Values are defined in LSColor
const int SPLIT_RIGHT_COLOR_MAIN_NRPN = 130;
const int SPLIT_RIGHT_COLOR_ACCENT_NRPN = 131;
const int SPLIT_RIGHT_COLOR_PLAYED_NRPN = 132;
const int SPLIT_RIGHT_COLOR_LOWROW_NRPN = 133;
// Value is an LSLowRowMode
const int SPLIT_RIGHT_LOWROW_MODE_NRPN = 134;
// Value is an LSSpecial:
const int SPLIT_RIGHT_SPECIAL_NRPN = 135;
// Value is an LSOctave
const int SPLIT_RIGHT_OCTAVE_NRPN = 136;
// Values are from LSPitch
const int LEFT_SPLIT_PITCH_TRANSPOSE_NRPN = 137;
const int SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN = 138;
// Value is an LSExpressionY
const int SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN = 139;

// Values are an LSFaderCCRange
const int SPLIT_RIGHT_CC_FOR_FADER1_NRPN = 140;
const int SPLIT_RIGHT_CC_FOR_FADER2_NRPN = 141;
const int SPLIT_RIGHT_CC_FOR_FADER3_NRPN = 142;
const int SPLIT_RIGHT_CC_FOR_FADER4_NRPN = 143;
const int SPLIT_RIGHT_CC_FOR_FADER5_NRPN = 144;
const int SPLIT_RIGHT_CC_FOR_FADER6_NRPN = 145;
const int SPLIT_RIGHT_CC_FOR_FADER7_NRPN = 146;
const int SPLIT_RIGHT_CC_FOR_FADER8_NRPN = 147;
// Value is an LSLowRowBehaviour
const int SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN = 148;
// Value is an LSFaderCCRange
const int SPLIT_RIGHT_CC_FOR_LOWROW_NRPN = 149;
// Value is an LSLowRowBehaviour
const int SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN = 150;
// Values are an LSFaderCCRange
const int SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN = 151;
const int SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN = 152;
const int SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN = 153;
// Values are an LSCCRange
const int SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN = 154;
const int SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN = 155;
const int SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN = 156;
const int SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN = 157;
const int SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN = 158;
const int SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN = 159;
// Value is an LSChannelOrder
const int SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER = 160;
// Value is an LSAnimation
const int SPLIT_RIGHT_TOUCH_ANIMATION = 161;

// Toggle:
const int SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN = 162;
const SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN = 163;
const SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN = 164;
// Value is an LSPatternNumber
const int SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN = 165;
const int SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN = 166;

// Globals
/*
200    0 - 1     Global Split Active(0: Inactive, 1 : Active)
201    0 - 1     Global Selected Split(0: Left Split, 1 : Right Split)
202    2 - 25    Global Split Point Column
203    0 - 1     Global Main Note Light C(0: Off, 1 : On)
204    0 - 1     Global Main Note Light C# (0: Off, 1 : On)
205    0 - 1     Global Main Note Light D(0: Off, 1 : On)
206    0 - 1     Global Main Note Light D# (0: Off, 1 : On)
207    0 - 1     Global Main Note Light E(0: Off, 1 : On)
208    0 - 1     Global Main Note Light F(0: Off, 1 : On)
209    0 - 1     Global Main Note Light F# (0: Off, 1 : On)
210    0 - 1     Global Main Note Light G(0: Off, 1 : On)
211    0 - 1     Global Main Note Light G# (0: Off, 1 : On)
212    0 - 1     Global Main Note Light A(0: Off, 1 : On)
213    0 - 1     Global Main Note Light A# (0: Off, 1 : On)
214    0 - 1     Global Main Note Light B(0: Off, 1 : On)
215    0 - 1     Global Accent Note Light C(0: Off, 1 : On)
216    0 - 1     Global Accent Note Light C# (0: Off, 1 : On)
217    0 - 1     Global Accent Note Light D(0: Off, 1 : On)
218    0 - 1     Global Accent Note Light D# (0: Off, 1 : On)
219    0 - 1     Global Accent Note Light E(0: Off, 1 : On)
220    0 - 1     Global Accent Note Light F(0: Off, 1 : On)
221    0 - 1     Global Accent Note Light F# (0: Off, 1 : On)
222    0 - 1     Global Accent Note Light G(0: Off, 1 : On)
223    0 - 1     Global Accent Note Light G# (0: Off, 1 : On)
224    0 - 1     Global Accent Note Light A(0: Off, 1 : On)
225    0 - 1     Global Accent Note Light A# (0: Off, 1 : On)
226    0 - 1     Global Accent Note Light B(0: Off, 1 : On)
227    0 - 13    Global Row Offset(only supports, 0: No overlap, 3 4 5 6 7 12 : Intervals, 13 : Guitar, 127 : 0 offset)
228    0 - 5     Global Switch 1 Assignment(0: Oct Down, 1 : Oct Up, 2 : Sustain, 3 : CC65, 4 : Arp, 5 : Alt Split, 6 : Auto Octave, 7 : Tap Tempo, 8 : Legato, 9 : Latch, 10 : Preset Up, 11 : Preset Down, 12 : Reverse Pitch X, 13 : Sequencer Play, 14 : Sequencer Previous, 15 : Sequencer Next, 16 : Send MIDI Clock, 17 : Sequencer Mute)
229    0 - 5     Global Switch 2 Assignment(0: Oct Down, 1 : Oct Up, 2 : Sustain, 3 : CC65, 4 : Arp, 5 : Alt Split, 6 : Auto Octave, 7 : Tap Tempo, 8 : Legato, 9 : Latch, 10 : Preset Up, 11 : Preset Down, 12 : Reverse Pitch X, 13 : Sequencer Play, 14 : Sequencer Previous, 15 : Sequencer Next, 16 : Send MIDI Clock, 17 : Sequencer Mute)
230    0 - 5     Global Foot Left Assignment(0: Oct Down, 1 : Oct Up, 2 : Sustain, 3 : CC65, 4 : Arp, 5 : Alt Split, 6 : Auto Octave, 7 : Tap Tempo, 8 : Legato, 9 : Latch, 10 : Preset Up, 11 : Preset Down, 12 : Reverse Pitch X, 13 : Sequencer Play, 14 : Sequencer Previous, 15 : Sequencer Next, 16 : Send MIDI Clock, 17 : Sequencer Mute)
231    0 - 5     Global Foot Right Assignment(0: Oct Down, 1 : Oct Up, 2 : Sustain, 3 : CC65, 4 : Arp, 5 : Alt Split, 6 : Auto Octave, 7 : Tap Tempo, 8 : Legato, 9 : Latch, 10 : Preset Up, 11 : Preset Down, 12 : Reverse Pitch X, 13 : Sequencer Play, 14 : Sequencer Previous, 15 : Sequencer Next, 16 : Send MIDI Clock, 17 : Sequencer Mute)
232    0 - 3     Global Velocity Sensitivity(0: Low, 1 : Medium, 2 : High, 3 : Fixed)
233    0 - 2     Global Pressure Sensitivity(0: Low, 1 : Medium, 2 : High)
234    0 - 1     Device MIDI I / O(0: MIDI Jacks, 1 : USB)
235    0 - 4     Global Arp Direction(0: Up, 1 : Down, 2 : Up Down, 3 : Random, 4 : Replay All)
236    1 - 7     Global Arp Tempo Note Value(1: 8, 2 : 8 Tri, 3 : 16, 4 : 16 Swing, 5 : 16 Tri, 6 : 32, 7 : 32 Tri)
237    0 - 2     Global Arp Octave Extension(0: None, 1 : +1, 2 : +2)
238    1 - 360   Global Clock BPM(applies when receiving no MIDI clock)
239    0 - 1     Global Switch 1 Both Splits(0: Off, 1 : On)
240    0 - 1     Global Switch 2 Both Splits(0: Off, 1 : On)
241    0 - 1     Global Foot Left Both Splits(0: Off, 1 : On)
242    0 - 1     Global Foot Right Both Splits(0: Off, 1 : On)
243    0 - 3     Global Settings Preset Load
244    0 - 1     Global Pressure Aftertouch(0: Off, 1 : On)
245    0 - 1     Device User Firmware Mode(0: Off, 1 : On)
246    0 - 1     Device Left Handed Operation(0: Off, 1 : On)
247    0 - 11    Global Active Note Lights Preset
248    0 - 127   Global MIDI CC For Switch CC65(Changes the CC for all switches - Legacy option, see NRPN 255 - 258)
249    1 - 127   Global Minimum Value For Velocity
250    1 - 127   Global Maximum Value For Velocity
251    1 - 127   Global Value For Fixed Velocity
252    0 - 512   Device Minimum Interval Between MIDI Bytes Over USB
253    0 - 33    Global Custom Row Offset Instead Of Octave(0 - 32: -16 - 16 semitone intervals, 33 : inverted Guitar)
254    0 - 1     Device MIDI Through(0: Off, 1 : On)
255    0 - 127   Global MIDI CC For Foot Left CC65
256    0 - 127   Global MIDI CC For Foot Right CC65
257    0 - 127   Global MIDI CC For Switch 1 CC65
258    0 - 127   Global MIDI CC For Switch 2 CC65
259    0 - 127   Global MIDI CC For Foot Left Sustain
260    0 - 127   Global MIDI CC For Foot Right Sustain
261    0 - 127   Global MIDI CC For Switch 1 Sustain
262    0 - 127   Global MIDI CC For Switch 2 Sustain
263    0 - 127   Global Note Number For Guitar Tuning Row 1
264    0 - 127   Global Note Number For Guitar Tuning Row 2
265    0 - 127   Global Note Number For Guitar Tuning Row 3
266    0 - 127   Global Note Number For Guitar Tuning Row 4
267    0 - 127   Global Note Number For Guitar Tuning Row 5
268    0 - 127   Global Note Number For Guitar Tuning Row 6
269    0 - 127   Global Note Number For Guitar Tuning Row 7
270    0 - 127   Global Note Number For Guitar Tuning Row 8
* /
const int REQUEST_VALUE_OF_NRPN = 299;

