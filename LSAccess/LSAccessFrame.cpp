// LSAccessFrame.cpp
// Main window for the application

#include "LSAccessFrame.h"


LSAccessFrame::LSAccessFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	// set the frame icon
	SetIcon(wxICON(sample));

	// create a menu bar
	wxMenu *fileMenu = new wxMenu;
	fileMenu->Append(ID_Quit, "E&xit\tAlt-X", "Quit this program");

	wxMenu *SettingsMenu = new wxMenu;
	SettingsMenu->Append(ID_LeftSplitSettings, "&Left Split...\tF2", "Show all settings for the left-hand split");
	SettingsMenu->Append(ID_RightSplitSettings, "&Right Split...\tF3", "Show all settings for the right-hand split");
	SettingsMenu->Append(ID_OctaveTransposeSettings, "&Octave/Transpose...\tF4", "Show all settings for octave and transposition");
	SettingsMenu->Append(ID_PresetsVolumesSettings, "&Presets/Volumes...\tF5", "Show all settings for LinnStrument presets, volues and programs");
	SettingsMenu->Append(ID_SwitchSettings, "&Switches...\tf6", "Show all settings for panel and foot switches");
	SettingsMenu->Append(ID_GlobalSettings, "&Globals...\tF7", "Show all global settings");
	SettingsMenu->Append(ID_StepSequencerSettings, "&Step Sequencer...\tF8", "Show all settings for the Step Sequencer");

	// the "About" item should be in the help menu
	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(ID_About, "&About\tF1", "Show about dialog");

	// now append the freshly created menus to the menu bar...
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(SettingsMenu, "&Settings");
	menuBar->Append(helpMenu, "&Help");

	// ... and attach this menu bar to the frame
	SetMenuBar(menuBar);

	// create a status bar 
	CreateStatusBar(2);
	SetStatusText("Welcome to LSAccess!");
	this->Maximize();
}		


// event handlers

void LSAccessFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	// true forces the frame to close
		Close(true);
	}

void LSAccessFrame::OnLeftSplitSettings(wxCommandEvent& event)
{
	PerSplitFrame * pLeftSplit = new PerSplitFrame( L"Left Split", &m_LinnStrument, LSSplitType::LEFT);
	pLeftSplit->Show(true);
	}

void LSAccessFrame::OnRightSplitSettings(wxCommandEvent& event)
{
	PerSplitFrame * pRightSplit = new PerSplitFrame(L"Right Split", &m_LinnStrument, LSSplitType::RIGHT);
	pRightSplit->Show(true);
}


void LSAccessFrame::OnOctaveTransposeSettings(wxCommandEvent& event)
{
	OctaveTransposeFrame * pOctaveTransposeFrame = new OctaveTransposeFrame(L"Octave/Transpose", &m_LinnStrument);
	pOctaveTransposeFrame->Show(true);
	}


void LSAccessFrame::OnPresetsVolumesSettings(wxCommandEvent& event)
{
	PresetsVolumesFrame * pPresetsVolumesFrame = new PresetsVolumesFrame(L"Presets/Volumes", &m_LinnStrument);
	pPresetsVolumesFrame->Show(true);
}


void LSAccessFrame::OnSwitchSettings(wxCommandEvent& event)
{
	SwitchesFrame * pSwitchesFrame = new SwitchesFrame(L"Switches", &m_LinnStrument);
	pSwitchesFrame->Show(true);
}


void LSAccessFrame::OnGlobalSettings(wxCommandEvent& event)
{
	GlobalsFrame * pGlobalsFrame = new GlobalsFrame(L"Globals", &m_LinnStrument);
	pGlobalsFrame->Show(true);
}


void LSAccessFrame::OnStepSequencerSettings(wxCommandEvent& event)
{
	SequencerFrame * pSequencerFrame = new SequencerFrame(L"Step Sequencer", &m_LinnStrument);
	pSequencerFrame->Show(true);
}


void LSAccessFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox( L"LS Access V1.0", L"About LSAccess", wxOK | wxICON_INFORMATION, this);
}
// event tables and other macros for wxWidgets
wxBEGIN_EVENT_TABLE(LSAccessFrame, wxFrame)
// File menu
EVT_MENU(ID_Quit, LSAccessFrame::OnQuit)

// Settings menu
EVT_MENU(ID_LeftSplitSettings, LSAccessFrame::OnLeftSplitSettings)
	EVT_MENU(ID_RightSplitSettings, LSAccessFrame::OnRightSplitSettings)
		EVT_MENU(ID_OctaveTransposeSettings, LSAccessFrame::OnOctaveTransposeSettings)
	EVT_MENU(ID_SwitchSettings, LSAccessFrame::OnSwitchSettings)
	EVT_MENU(ID_PresetsVolumesSettings, LSAccessFrame::OnPresetsVolumesSettings)
	EVT_MENU(ID_GlobalSettings, LSAccessFrame::OnGlobalSettings)
	EVT_MENU(ID_StepSequencerSettings, LSAccessFrame::OnStepSequencerSettings)

// Help menu
EVT_MENU(ID_About, LSAccessFrame::OnAbout)
wxEND_EVENT_TABLE()
