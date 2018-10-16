// LSEnums.h
// control ID values and other enumerations

#pragma once

#include <wx/string.h>


enum class LS_MIDIDevice
{
	MIDI_DIN_JACKS = 0,
	USB = 1
};

enum class LSSplitType
{
	LEFT = 0,
	RIGHT = 1
};

enum
{
	// File menu
	ID_Quit = wxID_EXIT,
	
	// Settings menu
	ID_LeftSplitSettings,
	ID_RightSplitSettings,
	ID_OctaveTransposeSettings,
	ID_PresetsVolumesSettings,
	ID_SwitchSettings,
	ID_GlobalSettings,
	ID_StepSequencerSettings,

	// Options menu
	ID_SpeakMessages,
	ID_SpeakNotes,
	ID_RefreshAll,
	ID_MIDIOptions,
	
	// Help menu
	ID_About,

	// Status bar update message ID
	STATUS_UPDATE_ID
};

	