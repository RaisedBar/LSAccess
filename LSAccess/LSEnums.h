// LSEnums.h
// control ID values and other enumerations

#pragma once

#include <wx/wx.h>

// IDs for the controls and the menu commands
enum
{
	// File menu
	ID_Quit = wxID_EXIT,
	
	// View menu
	ID_LeftSplitSettings,
	ID_RightSplitSettings,

	ID_NOTEBOOK,
	
	// Channels page
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
	BEND_TYPE_ID,
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
CC_FOR_Y_ID,
RELATIVE_Y_ID,
RELATIVE_Z_ID,
MIDI_EXPRESSION_FOR_Y_ID,
MIDI_EXPRESSION_FOR_Z_ID,
CC_FOR_Z_ID,
LOWROW_X_BEHAVIOUR_ID,
LOWROW_XYZ_BEHAVIOUR_ID,
CC_FOR_LOWROW_XYZ_ID,
CC_FOR_LOWROW_XYZ_Y_ID,
CC_FOR_LOWROW_XYZ_Z_ID,
MIN_CC_FOR_Y_ID,
MAX_CC_FOR_Y_ID,
MIN_CC_FOR_Z_ID,
MAX_CC_FOR_Z_ID,
CC_VALUE_FOR_Z_14BIT_ID,
INITIAL_RELATIVE_VALUE_FOR_Y_ID,

// Globals
ID_GlobalSettings,

	// Status bar
	ID_Switch1Status,
	ID_Switch2Status,
	ID_SplitButton1Status,
	ID_SplitButton2Status,

	// Octave-Transpose settings
	ID_OctaveTransposeSettings,

	// Volume settings

	// Presets

	// Help menu
	// it is important for the id corresponding to the "About" command to have
		// this standard value as otherwise it won't be handled properly under Mac
		// (where it is special and put into the "Apple" menu)
		ID_About = wxID_ABOUT
};


