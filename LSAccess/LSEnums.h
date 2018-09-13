// LSEnums.h
// control ID values and other enumerations

#pragma once

#include <wx/string.h>

// Values for toggle parameters
enum class LSToggleValue
{
	OFF = 0,
	ON = 1
};

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

const wxString Specials[] =
{
	L"Off",
	L"Arp",
	L"CC Faders",
	L"Strum",
	L"Sequencer"
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
	THREE = 3,
	FOUR = 4,
	FIVE = 5
	};

const wxString PresetNumbers[] =
{
		L"1",
	L"2",
	L"3",
	L"4",
	L"5",
	L"6"
	};

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

enum class LS_MIDIDevice
{
	MIDI_DIN_JACKS = 0,
	USB = 1
};

const wxString MIDIDeviceConnections[] =
{
	L"DIN jacks",
	L"USB"
	};

enum class LSSplitType
{
	LEFT = 0,
	RIGHT = 1
};

// IDs for the controls and the menu commands
enum
{
	// File menu
	ID_Quit = wxID_EXIT,
	
// Status bar update message ID
STATUS_UPDATE_ID,

// Settings menu
	ID_LeftSplitSettings,
	ID_RightSplitSettings,
		ID_NOTEBOOK,
	
	// MIDISplitPage
	SPLIT_MODE_ID,
	CHANNEL_PER_ROW_ORDER_ID,
	MIDI_MAIN_CHANNEL_ID,
	CHANNEL_PER_NOTE_1_ID,
	CHANNEL_PER_NOTE_2_ID,
	CHANNEL_PER_NOTE_3_ID,
	CHANNEL_PER_NOTE_4_ID,
	CHANNEL_PER_NOTE_5_ID,
	CHANNEL_PER_NOTE_6_ID,
	CHANNEL_PER_NOTE_7_ID,
	CHANNEL_PER_NOTE_8_ID,
	CHANNEL_PER_NOTE_9_ID,
	CHANNEL_PER_NOTE_10_ID,
	CHANNEL_PER_NOTE_11_ID,
	CHANNEL_PER_NOTE_12_ID,
	CHANNEL_PER_NOTE_13_ID,
	CHANNEL_PER_NOTE_14_ID,
	CHANNEL_PER_NOTE_15_ID,
	CHANNEL_PER_NOTE_16_ID,
	MIDI_PER_ROW_LOWEST_CHANNEL_ID,

	// Bend page
	BEND_TOGGLE_ID,
	BEND_RANGE_ID,
	BEND_QUANTIZE_TOGGLE_ID,
	BEND_QUANTIZE_ID,
	RESET_PITCH_ON_RELEASE_ID,

	// Sequencer page
ID_StepSequencerSettings,
SEQUENCER_TOGGLE_PLAY_ID,
SEQUENCER_TOGGLE_MUTE_ID,
	SEQUENCER_PATTERN_ID,
	SEQUENCER_PREVIOUS_PATTERN_ID,
	SEQUENCER_NEXT_PATTERN_ID,
	
	// Colors page
	Color_MAIN_ID,
	Color_ACCENT_ID,
	Color_PLAYED_ID,
	Color_LOWROW_ID,
	ANIMATION_ID,

	// Faders page
	CC_FOR_FADER1_ID,
	CC_FOR_FADER2_ID,
	CC_FOR_FADER3_ID,
	CC_FOR_FADER4_ID,
	CC_FOR_FADER5_ID,
	CC_FOR_FADER6_ID,
	CC_FOR_FADER7_ID,
	CC_FOR_FADER8_ID,
	
// Axes page
SEND_Y_ID,
SEND_Z_ID,
CC_FOR_Y_ID,
RELATIVE_Y_ID,
// RELATIVE_Z_ID,
EXPRESSION_FOR_Y_ID,
EXPRESSION_FOR_Z_ID,
CC_FOR_Z_ID,
MIN_CC_FOR_Y_ID,
MAX_CC_FOR_Y_ID,
MIN_CC_FOR_Z_ID,
MAX_CC_FOR_Z_ID,
CC_VALUE_FOR_Z_14BIT_ID,
INITIAL_RELATIVE_VALUE_FOR_Y_ID,

// Low row page
LOWROW_MODE_ID,
LOWROW_X_BEHAVIOUR_ID,
LOWROW_XYZ_BEHAVIOUR_ID,
CC_FOR_LOWROW_ID,
CC_FOR_LOWROW_XYZ_ID,
CC_FOR_LOWROW_XYZ_Y_ID,
CC_FOR_LOWROW_XYZ_Z_ID,

// Special page
SPECIAL_ID,

// Globals
ID_GlobalSettings,

// GlobalsSplitPage
GLOBAL_SPLIT_ACTIVE_ID,
GLOBAL_SPLIT_COLUMN_ID,
DEVICE_LEFT_HANDED_ID,

// GlobalsVelocityPressurePage
GLOBAL_VELOCITY_SENSITIVITY_ID,
GLOBAL_MIN_VELOCITY_VALUE_ID,
GLOBAL_MAX_VELOCITY_VALUE_ID,
GLOBAL_FIXED_VELOCITY_VALUE_ID,
GLOBAL_PRESSURE_SENSITIVITY_ID,
GLOBAL_PRESSURE_AFTERTOUCH_ID,
// GlobalsNoteLightsPage
GLOBAL_MAIN_NOTE_LIGHT_C_ID,
GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_ID,
GLOBAL_MAIN_NOTE_LIGHT_D_ID,
GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_ID,
GLOBAL_MAIN_NOTE_LIGHT_E_ID,
GLOBAL_MAIN_NOTE_LIGHT_F_ID,
GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_ID,
GLOBAL_MAIN_NOTE_LIGHT_G_ID,
GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_ID,
GLOBAL_MAIN_NOTE_LIGHT_A_ID,
GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_ID,
GLOBAL_MAIN_NOTE_LIGHT_B_ID,
GLOBAL_ACTIVE_LIGHTS_PRESET_ID,

// GlobalsTuningsPage
GLOBAL_ROW_OFFSET_ID,
GLOBAL_CUSTOM_ROW_OFFSET_ID,
GLOBAL_GUITAR_NOTE_TUNING_ROW1_ID,
GLOBAL_GUITAR_NOTE_TUNING_ROW2_ID,
GLOBAL_GUITAR_NOTE_TUNING_ROW3_ID,
GLOBAL_GUITAR_NOTE_TUNING_ROW4_ID,
GLOBAL_GUITAR_NOTE_TUNING_ROW5_ID,
GLOBAL_GUITAR_NOTE_TUNING_ROW6_ID,
GLOBAL_GUITAR_NOTE_TUNING_ROW7_ID,
GLOBAL_GUITAR_NOTE_TUNING_ROW8_ID,

// GlobalsAccentNoteLightsPage
GLOBAL_ACCENT_NOTE_LIGHT_C_ID,
GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_ID,
GLOBAL_ACCENT_NOTE_LIGHT_D_ID,
GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_ID,
GLOBAL_ACCENT_NOTE_LIGHT_E_ID,
GLOBAL_ACCENT_NOTE_LIGHT_F_ID,
GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_ID,
GLOBAL_ACCENT_NOTE_LIGHT_G_ID,
GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_ID,
GLOBAL_ACCENT_NOTE_LIGHT_A_ID,
GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_ID,
GLOBAL_ACCENT_NOTE_LIGHT_B_ID,

//  GlobalsArpPage
GLOBAL_CLOCK_BPM_ID,
GLOBAL_ARP_DIRECTION_ID,
GLOBAL_ARP_TEMPO_NOTE_VALUE_ID,
GLOBAL_ARP_OCTAVE_EXTENSION_ID,

// Status bar
	ID_Switch1Status,
	ID_Switch2Status,
	ID_SplitButton1Status,
	ID_SplitButton2Status,

	// PowerMIDIPage
	GLOBAL_MIDI_DEVICE_IO_ID,
		DEVICE_MIDI_THRU_ID,
		DEVICE_MIN_BYTE_INTERVAL_VALUE_ID,
		DEVICE_USER_FIRMWARE_MODE_ID,
	
		// Octave-Transpose settings
	ID_OctaveTransposeSettings,
	OCTAVE_ID,
	TRANSPOSE_PITCH_ID,
	TRANSPOSE_LIGHTS_ID,

	// Switch settings
	ID_SwitchSettings,
		// Panel switches
		SWITCH1_ASSIGN_ID,
SWITCH1_BOTH_SPLITS_ID,
		CC_FOR_SWITCH1_SUSTAIN_ID,
CC_FOR_SWITCH1_CC65_ID,
		SWITCH2_ASSIGN_ID,
	SWITCH2_BOTH_SPLITS_ID,
		CC_FOR_SWITCH2_SUSTAIN_ID,
CC_FOR_SWITCH2_CC65_ID,

		// Foot switches
				FOOT_LEFT_ASSIGN_ID,
		FOOT_LEFT_BOTH_SPLITS_ID,
		CC_FOR_LEFT_FOOT_SUSTAIN_ID,
CC_FOR_LEFT_FOOT_CC65_ID,
		FOOT_RIGHT_ASSIGN_ID,
		FOOT_RIGHT_BOTH_SPLITS_ID,
CC_FOR_RIGHT_FOOT_SUSTAIN_ID,
		CC_FOR_RIGHT_FOOT_CC65_ID,

		// PresetsVolumes
	ID_PresetsVolumesSettings,
			// PresetsVolumesPage
	GLOBAL_SETTINGS_PRESET_LOAD_ID,
	ProgramNumber_ID,
	Volume_ID,
		
	// Refresh all editor values by querying the hardware
	ID_RefreshAll,

	// Options menu
		ID_SpeakMessages,
ID_SpeakNotes,

	// Help menu
	// it is important for the id corresponding to the "About" command to have
		// this standard value as otherwise it won't be handled properly under Mac
		// (where it is special and put into the "Apple" menu)
		ID_About = wxID_ABOUT
};


