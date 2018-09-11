// LSAccessFrame.h
// The main window for the application

#pragma once

#include "LSEnums.h"
#include "LinnStrument.h"
#include "PerSplitFrame.h"
#include "OctaveTransposeFrame.h"
#include "PresetsVolumesFrame.h"
#include "SwitchesFrame.h"
#include "GlobalsFrame.h"
#include "SequencerFrame.h"

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

#include <wx/notebook.h>
#include <wx/stdpaths.h>
#include <wx/config.h>
#include <wx/confbase.h>
#include <wx/fileconf.h>
#include <wx/dir.h>
#include <wx/string.h>

#include <Windows.h>
#include <Dbt.h>
#include <wx/msw/winundef.h> 

const std::wstring wstrVendor = L"Raised Bar";
const 	std::wstring wstrAppName = L"LSAccess";

class LSAccessFrame : public wxFrame
{
public:
	LSAccessFrame(const wxString& title);
	~LSAccessFrame();

	// event handlers (these functions should _not_ be virtual)
	// File menu
	void OnQuit(wxCommandEvent& event);

// Settings menu
	void OnLeftSplitSettings(wxCommandEvent& event);
		void OnRightSplitSettings(wxCommandEvent& event);
		void OnOctaveTransposeSettings(wxCommandEvent& event);
		void OnSwitchSettings(wxCommandEvent& event);
		void OnPresetsVolumesSettings(wxCommandEvent& event);
		void OnGlobalSettings(wxCommandEvent& event);
		void OnStepSequencerSettings(wxCommandEvent& event);

// Options menu
		void OnSpeakMessages(wxCommandEvent& event);
		void OnSpeakNotes(wxCommandEvent& event);
void OnRefreshAll(wxCommandEvent& event);

// Help menu
	void OnAbout(wxCommandEvent& event);

private:
	// Event handlers for hardware changes
	/*
	// Windows:
#ifdef __WINDOWS__
		WXLRESULT MSWWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam);
#endif
*/
// Mac:

	void onStatusUpdate(wxCommandEvent& event);
	
		// Menus
	wxMenu * FileMenu, *SettingsMenu, *OptionsMenu, *HelpMenu;
	
	// Internal storage
	LinnStrument * pLinnStrument;
	wxFileName m_IniFile;
	wxFileConfig * m_Config;
	wxNotebook * pNotebook;
	
	wxDECLARE_EVENT_TABLE();
};


