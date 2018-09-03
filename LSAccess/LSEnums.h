// LSEnums.h
// control ID values and other enumerations

#pragma once

#include <wx/wx.h>

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
	
	// View menu
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
RELATIVE_Z_ID,
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
		
	// Help menu
	// it is important for the id corresponding to the "About" command to have
		// this standard value as otherwise it won't be handled properly under Mac
		// (where it is special and put into the "Apple" menu)
		ID_About = wxID_ABOUT
};


