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

#include "LSPerSplit.h"
#include "LSOctaveTranspose.h"
#include "LSSwitches.h"
#include "LSGlobals.h"
#include "MIDIDialog.h"
#include "MIDI.h"

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


class LinnStrument
{
public:
	LinnStrument();
	~LinnStrument();

	int GetUSBInPortID();
	int GetUSBOutPortID();
		LSPerSplitSettings GetPerSplitSettings();
	void SetPerSplitSettings(LSPerSplitSettings splitSettings);
	LSOctaveTransposeSettings GetOctaveTransposeSettings();
	void SetOctaveTransposeSettings(LSOctaveTransposeSettings octaveTransposeSettings);
	LSSwitchSettings GetSwitchSettings();
	void SetSwitchSettings(LSSwitchSettings SwitchSettings);
	LSGlobalSettings GetGlobalSettings();
	void SetGlobalSettings(LSGlobalSettings globalSettings);
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
	
private:
	void SendNRPN(LSSplitType split, unsigned int NRPNNumber, unsigned int NRPNValue);
	void SendNRPN(unsigned char nChannelNibble, unsigned int NRPNNumber, unsigned int NRPNValue);
	void SetLSParameter( unsigned int NRPNParameterIn, unsigned int NRPNValueIn);
	
	// data
// MIDI devices
		RtMidiIn * m_MIDIIn;
		RtMidiOut * m_MIDIOut;
		// MIDI port ID values;
		int m_InputID, m_OutputID;

		// LinnStrument parameters
		LSPerSplitSettings m_PerSplitSettings;
		LSOctaveTransposeSettings m_OctaveTransposeSettings;
		LSSwitchSettings m_SwitchSettings;
		LSGlobalSettings m_GlobalSettings;
		std::queue <unsigned int> m_NRPNQueue;

		// MIDI traffic handling
		unsigned int m_NRPNParameterIn, m_NRPNValueIn;
		bool m_ReceivedNRPNValueMSB, m_ReceivedNRPNValueLSB;
		bool m_Waiting;
		unsigned int m_Sent, m_Received;

// Application options
		bool m_SpeakNotes;
		ISpVoice * pVoice;
		};

std::string MIDINoteName(unsigned char nNoteNumber);
void SendCC(unsigned char CCNumber, unsigned char CCValue);

void LSCallback(double deltatime, std::vector< unsigned char > *message, void *pLinnStrument);
