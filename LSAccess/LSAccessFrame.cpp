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

	wxMenu *viewMenu = new wxMenu;
	viewMenu->Append(ID_LeftSplitSettings, "&Left Split...\tF2", "Show all settings for the left-hand split");
	viewMenu->Append(ID_RightSplitSettings, "&Right Split...\tF3", "Show all settings for the right-hand split");
	viewMenu->Append(ID_OctaveTransposeSettings, "&Octave and Transpose...\tF4", "Show all settings for octave and transposition");
	viewMenu->Append(ID_StepSequencerSettings, "&Step Sequencer...\tF5", "Show all settings for the Step Sequencer");
	viewMenu->Append(ID_GlobalSettings, "&Global...\tF6", "Show all global settings");

	// the "About" item should be in the help menu
	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(ID_About, "&About\tF1", "Show about dialog");

	// now append the freshly created menus to the menu bar...
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(viewMenu, "&View");
	menuBar->Append(helpMenu, "&Help");

	// ... and attach this menu bar to the frame
	SetMenuBar(menuBar);

	// create a status bar 
	CreateStatusBar(2);
	SetStatusText("Welcome to LSAccess!");

	// Initialize the LinnStrument itself
	pLinnStrument = new LinnStrument();
		}


// event handlers

void LSAccessFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	// true forces the frame to close
		Close(true);
	}

void LSAccessFrame::OnLeftSplitSettings(wxCommandEvent& event)
{
	LeftSplitFrame * pLeftSplit = new LeftSplitFrame( L"Left Split", pLinnStrument);
	pLeftSplit->Show(true);
	}

void LSAccessFrame::OnRightSplitSettings(wxCommandEvent& event)
{}


void LSAccessFrame::OnOctaveTransposeSettings(wxCommandEvent& event)
{}


void LSAccessFrame::OnStepSequencerSettings(wxCommandEvent& event)
{}


void LSAccessFrame::OnGlobalSettings(wxCommandEvent& event)
{}


void LSAccessFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox( L"LS Access V1.0", L"About LSAccess", wxOK | wxICON_INFORMATION, this);
}
// event tables and other macros for wxWidgets
wxBEGIN_EVENT_TABLE(LSAccessFrame, wxFrame)
// File menu
EVT_MENU(ID_Quit, LSAccessFrame::OnQuit)

// View menu
EVT_MENU(ID_LeftSplitSettings, LSAccessFrame::OnLeftSplitSettings)
	EVT_MENU(ID_RightSplitSettings, LSAccessFrame::OnRightSplitSettings)
		EVT_MENU(ID_OctaveTransposeSettings, LSAccessFrame::OnOctaveTransposeSettings)
			EVT_MENU(ID_StepSequencerSettings, LSAccessFrame::OnStepSequencerSettings)
				EVT_MENU(ID_GlobalSettings, LSAccessFrame::OnGlobalSettings)

// Help menu
EVT_MENU(ID_About, LSAccessFrame::OnAbout)
wxEND_EVENT_TABLE()
