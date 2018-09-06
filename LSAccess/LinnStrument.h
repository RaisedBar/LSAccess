// LinnStrument.h

#pragma once

#include <RtMidi.h>
#include <wx/string.h>

#include <iostream>
#include <sstream>
#include <queue>

#define _ATL_APARTMENT_THREADED
#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override something,
//but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>
#include <sapi.h>
#include <Windows.h>

#include "MIDIDialog.h"
#include "MIDI.h"
#include "LSEnums.h"

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

*/

// CC messages
const unsigned char FADER1 = 1; // Change the position of the CC faders, the split is determined by its active MIDI mode channels
const unsigned char FADER2 = 2;
const unsigned char FADER3 = 3;
const unsigned char FADER4 = 4;
const unsigned char FADER5 = 5;
const unsigned char FADER6 = 6;
const unsigned char FADER7 = 7;
const unsigned char FADER8 = 8;
const unsigned char USER_FIRMWARE_X_AXIS_ROW_SLIDE = 9;  //  Configure User Firmware X - axis row slide, the channel specifies the row(0: disable, 1 : enable)
const unsigned char USER_FIRMWARE_X_AXIS_ROW_DATA = 10;           // Configure User Firmware X - axis data, the channel specifies the row, default is off(0: disable, 1 : enable)
const unsigned char USER_FIRMWARE_Y_AXIS_ROW_DATA = 11;           // Configure User Firmware Y - axis data, the channel specifies the row, default is off(0: disable, 1 : enable)
const unsigned char USER_FIRMWARE_Z_AXIS_ROW_DATA = 12;           // Configure User Firmware Z - axis data, the channel specifies the row, default is off(0: disable, 1 : enable)
const unsigned char USER_FIRMWARE_MIDI_DECIMATION_RATE = 13;           // Configure User Firmware MIDI decimation rate in milliseconds(minimum 12 ms in low power mode)
const unsigned char CELL_COLOR_CHANGE_COLUMN = 20;           // Column coordinate for cell color change with CC 22 (starts from 0)
const unsigned char CELL_COLOR_CHANGE_ROW = 21;           // Row coordinate for cell color change with CC 22 (starts from 0)
const unsigned char CELL_COLOR_CHANGE = 22;           // Change the color of the cell with the provided column and row coordinates

// Name of LinnStrument when connected over USB
const std::string LSUSBName = "LinnStrument MIDI";
// Name of LinnStrument when in O/S update mode
// todo
const std::string LSOSUpdateName = "";

// Values for toggle parameters
enum class LSToggleValue
{
	OFF = 0,
	ON = 1
};

// Valid MIDI channel number range:
// const unsigned int MIN_MIDI_CHANNEL = 1;
// const unsigned int MAX_MIDI_CHANNEL = 16;

enum class LS_MIDIMode
{
	ONE_CHAN = 0,
	CHANNEL_PER_NOTE_MPE = 1,
	CHANNEL_PER_ROW = 2
};

const wxString SplitModes[] =
{
	L"One channel",
	L"Channel per note (MPE)",
	L"Channel per row"
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

const wxString BendQuantizations[] =
{
	L"Off",
	L"Medium",
	L"Fast",
	L"Slow"
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

const wxString ExpressionY[] =
{
L"Poly Aftertouch",
	L"Channel Aftertouch",
	L"CC defined in 25"
};

enum class LSExpressionZ
{
	POLY_AFTERTOUCH = 0,
	CHANNEL_AFTERTOUCH = 1,
	CC_DEFINED_IN_29 = 2
};

const wxString ExpressionZ[] =
{
L"Poly Aftertouch",
	L"Channel Aftertouch",
	L"CC defined in 29"
};

const unsigned int MIN_TEMPO = 1;
const unsigned int MAX_TEMPO = 360;

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
	DEFAULT = 12
};

const wxString ColorNames[] =
{
	L"Off",
		L"RED",
L"YELLOW",
L"GREEN",
"CYAN",
L"BLUE",
L"MAGENTA",
L"BLACK",
L"WHITE",
L"ORANGE",
L"LIME",
L"PINK",
// Values higher than pink (11) set the color to default
L"DEFAULT"
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

const wxString Octaves[] = 
{
L"-5",
	L"-4",
	L"-3",
L"-2",
	L"-1",
	L"0",
	L"+1",
L"+2",
	L"+3",
	L"+4",
	L"+5"
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

const wxString Pitches[] = 
{
	L"-7",
L"-6",
L"-5",
L"-4",
L"-3",
	L"-2",
	L"-1",
	L"0",
	L"+1",
	L"+2",
	L"+3",
	L"+4",
	L"+5",
	L"+6",
	L"+7"
};

enum class LSLowRowBehaviour
{
	HOLD = 0,
	FADER = 1
};

const wxString LowRowModes[] =
{
	L"Normal",
		L"Sustain",
		L"Restrike",
		L"Strum",
		L"Arp",
		L"Bend"
		L"CC1",
	L"X,Y,Z=16-18"
};

const wxString LowRowBehaviour[] =
{
L"Hold",
L"Fader"
};

enum class LSChannelOrder
{
	NORMAL = 0,
	REVERSED = 1
};

const wxString ChannelOrders[] =
{
	L"Normal",
	L"Reversed"
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

const 	wxString Animations[] =
{
	L"SAME",
	L"CROSSES",
	L"CIRCLES",
	L"SQUARES",
	L"DIAMONDS",
	L"STARS",
	L"SPARKLES",
	L"CURTAINS",
	L"BLINDS",
	L"TARGETS",
	L"UP",
	L"DOWN",
	L"LEFT",
	L"RIGHT",
	L"ORBITS"
};

const unsigned int MIN_SEQUENCER_PATTERN = 0;
const unsigned int MAX_SEQUENCER_PATTERN = 3;

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

const wxString RowOffsetTypes[] =
{
	L"No overlap",
	L"3rd",
	L"4th",
	L"5th",
	L"6th",
	L"7th",
	L"Octave",
	L"Guitar",
	L"No offset"
};

enum class LSSwitchType
{
	PANEL = 0,
	FOOT = 1
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

const wxString wstrSwitchAssignments[] = 
	{
		L"Octave Down",
	L"Octave Up",
L"Sustain",
	L"CC65",
	L"Arp",
	L"Alt Split",
	L"Auto Octave",
	L"Tap Tempo",
	L"Legato",
	L"Latch",
	L"Preset Up",
	L"Preset Down",
	L"Reverse Pitch-X",
	L"Sequencer Play",
	L"Sequencer Previous",
	L"Sequencer Next",
	L"Send MIDI Clock",
	L"Sequencer Mute"
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

const wxString PressureRanges[] =
{
	L"Low",
	L"Medium",
	L"High"
};

const wxString VelocityRanges[] =
{
	L"Low",
	L"Medium",
	L"High",
	L"Fixed"
};

const unsigned int MIN_MIDI_BYTE_DELAY = 0;
const unsigned int MAX_MIDI_BYTE_DELAY = 512;

enum class LSArpDirection
{
	UP = 0,
	DOWN = 1,
	UP_DOWN = 2,
	RANDOM = 3,
	REPLAY_ALL = 4
};

const wxString ArpDirections[] = 
{
	L"Up",
	L"Down",
	L"Up/Down",
	L"Random",
	L"Replay all"
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

const wxString ArpTempoNoteTypes[] =
{
	L"8th",
	L"8th triplet",
	L"16th",
	L"16th swing",
	L"16th triplet",
	L"32nd",
	L"32nd triplet"
};

enum class LSGlobalArpOctaveExtension
{
	NONE = 0,
	PLUS1 = 1,
	PLUS2 = 2
};

const wxString ArpOctaveExtensions[] =
{
	L"None",
	L"+1",
	L"+2"
};

enum class LSPresetNumber
{
	ZERO = 0,
	ONE = 1,
	TWO = 2,
	THREE = 3
};

const wxString PresetNumbers[] =
{
	L"0",
	L"1",
	L"2",
	L"3"
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

const wxString CustomRowOffsets[] =
{
	// Semitone intervals:
	L"-16",
	L"-15",
	L"-14",
	L"-13",
	L"-12",
	L"-11",
	L"-10",
	L"-9",
	L"-8",
	L"-7",
	L"-6",
	L"-5",
	L"-4",
	L"-3",
	L"-2",
	L"-1",
L"0",
	L"+1",
L"+2",
	L"+3",
	L"+4",
L"+5",
	L"+6",
L"+7",
L"+8",
	L"+9",
	L"+10",
L"+11",
	L"+12",
	L"+13",
	L"+14",
	L"+15",
	L"+16",
	L"Inverted guitar"
};

const unsigned int MIN_MEMORY_LOCATION = 1;
const unsigned int MAX_MEMORY_LOCATION = 6;

const unsigned int REQUEST_VALUE_OF_NRPN = 299;

const unsigned int SET_NRPN_CC_MSB = 99;
const unsigned int SET_NRPN_CC_LSB = 98;
const unsigned int SET_NRPN_VALUE_MSB = 6;
const unsigned int SET_NRPN_VALUE_LSB = 38;
const unsigned int RESET_NRPN_CC_MSB = 101;
const unsigned int RESET_NRPN_CC_LSB = 100;


// Per-split constants
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

// Constants for panel and foot switches

// Value is LSSwitchAssignment
const unsigned int SWITCH1_ASSIGN_NRPN = 228;
const unsigned int SWITCH2_ASSIGN_NRPN = 229;
const unsigned int FOOT_LEFT_ASSIGN_NRPN = 230;
const unsigned int FOOT_RIGHT_ASSIGN_NRPN = 231;
// Toggle:
const unsigned int SWITCH1_BOTH_SPLITS_NRPN = 239;
const unsigned int SWITCH2_BOTH_SPLITS_NRPN = 240;
const unsigned int FOOT_LEFT_BOTH_SPLITS_NRPN = 241;
const unsigned int FOOT_RIGHT_BOTH_SPLITS_NRPN = 242;
// Values are constrained by MIN_CC and MAX_CC
const unsigned int CC_FOR_CC65 = 248;  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
// Values are constrained by MIN_CC and MAX_CC
const unsigned int CC_FOR_LEFT_FOOT_CC65 = 255;
const unsigned int CC_FOR_RIGHT_FOOT_CC65 = 256;
const unsigned int CC_FOR_SWITCH1_CC65 = 257;
const unsigned int CC_FOR_SWITCH2_CC65 = 258;
const unsigned int CC_FOR_LEFT_FOOT_SUSTAIN = 259;
const unsigned int CC_FOR_RIGHT_FOOT_SUSTAIN = 260;
const unsigned int CC_FOR_SWITCH1_SUSTAIN = 261;
const unsigned int CC_FOR_SWITCH2_SUSTAIN = 262;

// Octave/transpose settings
// Value is an LSOctave
const unsigned int SPLIT_LEFT_OCTAVE_NRPN = 36;
// Values are from LSPitch
const unsigned int SPLIT_LEFT_PITCH_TRANSPOSE_NRPN = 37;
const unsigned int SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN = 38;
// Value is an LSOctave
const unsigned int SPLIT_RIGHT_OCTAVE_NRPN = 136;
// Values are from LSPitch
const unsigned int SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN = 137;
const unsigned int SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN = 138;

// Global settings

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
// Value is LSVelocityRange
const unsigned int GLOBAL_VELOCITY_SENSITIVITY_NRPN = 232;
// Value is LSPressureRange
const unsigned int GLOBAL_PRESSURE_SENSITIVITY_NRPN = 233;
// Value is LSMIDIDevice
const unsigned int GLOBAL_MIDI_DEVICE_IO_NRPN = 234;
// Value is LSArpDirection
const unsigned int GLOBAL_ARP_DIRECTION_NRPN = 235;
// Value is LSArpTempoNoteType
const unsigned int GLOBAL_ARP_TEMPO_NOTE_VALUE_NRPN = 236;
// Value is LSGlobalArpOctaveExtension
const unsigned int GLOBAL_ARP_OCTAVE_EXTENSION_NRPN = 237;
// Value_NRPN = 1 - 360  (applies when receiving no MIDI clock)
const unsigned int GLOBAL_CLOCK_BPM_NRPN = 238;
// Value is LSPresetNumber
const unsigned int GLOBAL_SETTINGS_PRESET_LOAD_NRPN = 243;
// Toggles:
const unsigned int GLOBAL_PRESSURE_AFTERTOUCH_NRPN = 244;
const unsigned int DEVICE_USER_FIRMWARE_MODE_NRPN = 245;
const unsigned int DEVICE_LEFT_HANDED_NRPN = 246;
// Value is constrained by MIN_LIGHTS_PRESET and MAX_LIGHTS_PRESET 
const unsigned int GLOBAL_ACTIVE_LIGHTS_PRESET_NRPN = 247;
// Values are constrained by MIN_CC and MAX_CC
const unsigned int GLOBAL_MIN_VELOCITY_VALUE_NRPN = 249;
const unsigned int GLOBAL_MAX_VELOCITY_VALUE_NRPN = 250;
const unsigned int GLOBAL_FIXED_VELOCITY_VALUE_NRPN = 251;
// Value range_NRPN =     0 - 512  
const unsigned int DEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN = 252;
// Value is LSCustomRowOffset
const unsigned int GLOBAL_CUSTOM_ROW_OFFSET_NRPN = 253;
// Toggle:
const unsigned int DEVICE_MIDI_THRU_NRPN = 254;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW1_NRPN = 263;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW2_NRPN = 264;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW3_NRPN = 265;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW4_NRPN = 266;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW5_NRPN = 267;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW6_NRPN = 268;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW7_NRPN = 269;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW8_NRPN = 270;


class LinnStrument
{
public:
	LinnStrument();
	~LinnStrument();

	int GetUSBInPortID();
	int GetUSBOutPortID();
		void ProcessMessage(std::vector <unsigned char> vBytes);

		void QueryLeftChannel();
		void QueryRightChannel();
				void QueryNRPN(unsigned int nParameterNumber);
		void QueryPerSplitSettings();
		void QueryGlobalSettings();
		void QuerySwitchSettings();
		void QueryOctaveTransposeSettings();
		void QueryAll();

			// Option to use speech to output note names
	bool GetSpeakNotes();
	void SetSpeakNotes(bool blnSpeakNotes);
	
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
	
	unsigned int GetLS_MIDIDeviceIndex(LS_MIDIDevice device)
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
	unsigned int GetVolume(LSSplitType split)
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

	void SetVolume(unsigned int nValue, LSSplitType split)
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

	void QueryGLOBAL_SPLIT_ACTIVE()
	{

	}

	void QueryGLOBAL_SELECTED_SPLIT()
	{

	}

	void QueryGLOBAL_SPLIT_COLUMN()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_C()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_C_SHARP()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_D()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_D_SHARP()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_E()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_F()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_F_SHARP()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_G()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_G_SHARP()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_A()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_A_SHARP()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_B()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_C()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_D()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_E()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_F()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_G()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_A()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_B()
	{

	}

	void QueryGLOBAL_ROW_OFFSET()
	{

	}

	void QueryGLOBAL_VELOCITY_SENSITIVITY()
	{

	}

	void QueryGLOBAL_PRESSURE_SENSITIVITY()
	{

	}

	void QueryGLOBAL_MIDI_DEVICE_IO()
	{

	}

	void QueryGLOBAL_ARP_DIRECTION()
	{

	}

	void QueryGLOBAL_ARP_TEMPO_NOTE_VALUE()
	{

	}

	void QueryGLOBAL_ARP_OCTAVE_EXTENSION()
	{

	}

	void QueryGLOBAL_CLOCK_BPM()
	{

	}

	void QueryGLOBAL_SETTINGS_PRESET_LOAD()
	{

	}

	void QueryGLOBAL_PRESSURE_AFTERTOUCH()
	{

	}

	void QueryDEVICE_USER_FIRMWARE_MODE()
	{

	}

	void QueryDEVICE_LEFT_HANDED()
	{

	}

	void QueryGLOBAL_ACTIVE_LIGHTS_PRESET()
	{

	}

	void QueryGLOBAL_MIN_VELOCITY_VALUE()
	{

	}

	void QueryGLOBAL_MAX_VELOCITY_VALUE()
	{

	}

	void QueryGLOBAL_FIXED_VELOCITY_VALUE()
	{

	}

	void QueryDEVICE_MIN_BYTE_INTERVAL_VALUE()
	{

	}

	void QueryGLOBAL_CUSTOQueryROW_OFFSET()
	{

	}

	void QueryDEVICE_MIDI_THRU()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW1()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW2()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW3()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW4()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW5()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW6()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW7()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW8()
	{

	}

	void QueryLSPresetNumber()
	{

	}

	void QueryLEFT_PROGRAM()
	{

	}

	void QueryRIGHT_PROGRAM()
	{

	}

	void QueryLEFT_VOLUME()
	{

	}

	void QueryRIGHT_VOLUME()
	{

	}


private:
	void SendNRPN(LSSplitType split, unsigned int NRPNNumber, unsigned int NRPNValue);
	void SendNRPN(unsigned char nChannelNibble, unsigned int NRPNNumber, unsigned int NRPNValue);
	void SetLSParameter( unsigned int NRPNParameterIn, unsigned int NRPNValueIn);
	
	// data
// LinnStrument message tracking
	std::queue <unsigned int> m_NRPNQueue;
		unsigned int m_NRPNParameterIn, m_NRPNValueIn;
	bool m_ReceivedNRPNValueMSB, m_ReceivedNRPNValueLSB;
	bool m_Waiting;
	unsigned int m_Sent, m_Received;

	// Application options
	bool m_SpeakNotes;
	ISpVoice * pVoice;

	// MIDI devices
		RtMidiIn * m_MIDIIn;
		RtMidiOut * m_MIDIOut;
		// MIDI port ID values;
		int m_InputID, m_OutputID;

// Per-split settings
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
