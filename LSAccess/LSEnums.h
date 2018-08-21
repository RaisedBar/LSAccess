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
	ID_NOTEBOOK,
	ID_RightSplitSettings,
	ID_OctaveTransposeSettings,
	ID_StepSequencerSettings,
	ID_GlobalSettings,

	// Channels page
		SPLIT_LEFT_CHANNEL_PER_NOTE_1_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_2_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_3_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_4_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_5_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_6_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_7_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_8_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_9_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_10_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_11_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_12_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_13_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_14_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_15_ID,
	SPLIT_LEFT_CHANNEL_PER_NOTE_16_ID,
	SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_ID,
	
	// Pitch bend page
	SPLIT_LEFT_BEND_TOGGLE_ID,
	SPLIT_LEFT_BEND_RANGE_ID,
	SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_ID,
	SPLIT_LEFT_BEND_TYPE_ID,
	SPLIT_LEFT_RESET_PITCH_ON_RELEASE_ID,

	// Status bar
	ID_Switch1Status,
	ID_Switch2Status,
	ID_SplitButton1Status,
	ID_SplitButton2Status,

	// Volume settings

	// Presets

	// Help menu
	// it is important for the id corresponding to the "About" command to have
		// this standard value as otherwise it won't be handled properly under Mac
		// (where it is special and put into the "Apple" menu)
		ID_About = wxID_ABOUT
};


