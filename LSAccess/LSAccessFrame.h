// LSAccessFrame.h
// The main window for the application

#pragma once

#include "LinnStrument.h"

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

// IDs for the controls and the menu commands
enum
{
	// File menu
	LSAccess_Quit = wxID_EXIT,
	
// View menu
	LSAccess_LeftSplitSettings,
	LSAccess_RightSplitSettings,
LSAccess_OctaveTransposeSettings,	
LSAccess_StepSequencerSettings,
LSAccess_GlobalSettings,

// Status bar
LSAccess_Switch1Status,
LSAccess_Switch2Status,
LSAccess_SplitButton1Status,
LSAccess_SplitButton2Status,
	
// Volume settings

// Presets

// Help menu
// it is important for the id corresponding to the "About" command to have
	// this standard value as otherwise it won't be handled properly under Mac
	// (where it is special and put into the "Apple" menu)
	LSAccess_About = wxID_ABOUT
};


class LSAccessFrame : public wxFrame
{
public:
	LSAccessFrame(const wxString& title);

	// event handlers (these functions should _not_ be virtual)
	// File menu
	void OnQuit(wxCommandEvent& event);

// View menu
	void OnLeftSplitSettings(wxCommandEvent& event);
		void OnRightSplitSettings(wxCommandEvent& event);
		void OnOctaveTransposeSettings(wxCommandEvent& event);
		void OnStepSequencerSettings(wxCommandEvent& event);
		void OnGlobalSettings(wxCommandEvent& event);

// Help menu
	void OnAbout(wxCommandEvent& event);

private:
	// Internal storage
	LinnStrument * pLinnStrument;

	wxDECLARE_EVENT_TABLE();
};


