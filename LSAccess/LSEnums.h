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


