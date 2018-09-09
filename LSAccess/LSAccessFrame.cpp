// LSAccessFrame.cpp
// Main window for the application

#include "stdafx.h"
#include "LSAccessFrame.h"


LSAccessFrame::LSAccessFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	// Initialise the LinnStrument
	m_LinnStrument = new LinnStrument(this);
	
	// set the frame icon
	SetIcon(wxICON(sample));

	// create a menu bar
	FileMenu = new wxMenu;
	FileMenu->Append(ID_Quit, "E&xit\tAlt-X", "Quit this program");

	SettingsMenu = new wxMenu;
	SettingsMenu->Append(ID_LeftSplitSettings, "&Left Split...\tF2", "Show all settings for the left-hand split");
	SettingsMenu->Append(ID_RightSplitSettings, "&Right Split...\tF3", "Show all settings for the right-hand split");
	SettingsMenu->Append(ID_OctaveTransposeSettings, "&Octave/Transpose...\tF4", "Show all settings for octave and transposition");
	SettingsMenu->Append(ID_PresetsVolumesSettings, "&Presets/Volumes...\tF5", "Show all settings for LinnStrument presets, volues and programs");
	SettingsMenu->Append(ID_SwitchSettings, "&Switches...\tf6", "Show all settings for panel and foot switches");
	SettingsMenu->Append(ID_GlobalSettings, "&Globals...\tF7", "Show all global settings");
	SettingsMenu->Append(ID_StepSequencerSettings, "&Step Sequencer...\tF8", "Show all settings for the Step Sequencer");

	OptionsMenu = new wxMenu;
	mnuSpeakMessages = new wxMenuItem(OptionsMenu, ID_SpeakMessages, "&Speak messages\tF9", "Enable speech output of status information", wxITEM_CHECK);
		mnuSpeakNotes = new wxMenuItem(OptionsMenu, ID_SpeakNotes, "Speak &note names\tF10", "Announce the names of notes when LinnStrument pads are played", wxITEM_CHECK);
		OptionsMenu->Append(mnuSpeakMessages);
		OptionsMenu->Append(mnuSpeakNotes);
	
// the "About" item should be in the help menu
	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(ID_About, "&About\tF1", "Show about dialog");

	// now append the freshly created menus to the menu bar...
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(FileMenu, "&File");
	menuBar->Append(SettingsMenu, "&Settings");
	menuBar->Append(OptionsMenu, "&Options");
	menuBar->Append(helpMenu, "&Help");

	// ... and attach this menu bar to the frame
	SetMenuBar(menuBar);

	// create a status bar 
	CreateStatusBar(2);

	// Restore any saved settings
	const std::wstring wstrVendor = L"Raised Bar";
	const 	std::wstring wstrAppName = L"LSAccess";

	wxDir myDir;
	std::wstring wstrConfigPath(wxStandardPaths::Get().GetUserConfigDir() + L"\\" + wstrVendor + L"\\" + wstrAppName);

	if (!myDir.Exists(wstrConfigPath))
	{
		myDir.Make(wxStandardPaths::Get().GetUserConfigDir() + L"\\" + wstrVendor);
		myDir.Make(wstrConfigPath);
	}

	std::wstring wstrIniPath = wstrConfigPath + L"\\" + wstrAppName + L".ini";
	m_IniFile.SetPath(wstrIniPath);
	m_Config = new wxFileConfig(wstrVendor, wstrAppName, wstrIniPath);
	m_Config->SetPath(wstrConfigPath);

	if (m_Config->HasGroup("SpeechOutput"))
	{
		if (m_Config->HasEntry("SpeakMessages"))
		{
			SetSpeakMessages(m_Config->ReadBool("SpeakMessages", &m_IniFile));
		}

		if (m_Config->HasEntry("SpeakNotes"))
		{
			SetSpeakNotes(m_Config->ReadBool("SpeakNotes", &m_IniFile));
		}
	}

	SetStatusText("Welcome to LSAccess!");
	this->Maximize();
}		


LSAccessFrame::~LSAccessFrame()
{
	// Save settings and clean-up
	m_Config->Flush();
	delete m_Config;
}


// event handlers

#ifdef __WINDOWS__
WXLRESULT LSAccessFrame::MSWWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam) {
	//wxLogDebug(wxT("MSWWindowProc %08x %08x %08x"), nMsg, wParam, lParam);
	
	// Detect hardware changes as LinnStrument transitions to/from MIDI and O/S update modes
	if (nMsg == WM_DEVICECHANGE && (wParam == DBT_DEVICEARRIVAL || wParam == DBT_DEVICEREMOVECOMPLETE))
	{
		wxLogDebug(wxT("WM_DEVICECHANGE %x %x"), wParam, lParam);
		// do your work here
	}
	return wxFrame::MSWWindowProc(nMsg, wParam, lParam);
}
#endif


void LSAccessFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	// true forces the frame to close
		Close(true);
	}

void LSAccessFrame::OnLeftSplitSettings(wxCommandEvent& event)
{
	PerSplitFrame * pLeftSplit = new PerSplitFrame( L"Left Split", m_LinnStrument, LSSplitType::LEFT);
	pLeftSplit->Show(true);
	}

void LSAccessFrame::OnRightSplitSettings(wxCommandEvent& event)
{
	PerSplitFrame * pRightSplit = new PerSplitFrame(L"Right Split", m_LinnStrument, LSSplitType::RIGHT);
	pRightSplit->Show(true);
}


void LSAccessFrame::OnOctaveTransposeSettings(wxCommandEvent& event)
{
	OctaveTransposeFrame * pOctaveTransposeFrame = new OctaveTransposeFrame(L"Octave/Transpose", m_LinnStrument);
	pOctaveTransposeFrame->Show(true);
	}


void LSAccessFrame::OnPresetsVolumesSettings(wxCommandEvent& event)
{
	PresetsVolumesFrame * pPresetsVolumesFrame = new PresetsVolumesFrame(L"Presets/Volumes", m_LinnStrument);
	pPresetsVolumesFrame->Show(true);
}


void LSAccessFrame::OnSwitchSettings(wxCommandEvent& event)
{
	SwitchesFrame * pSwitchesFrame = new SwitchesFrame(L"Switches", m_LinnStrument);
	pSwitchesFrame->Show(true);
}


void LSAccessFrame::OnGlobalSettings(wxCommandEvent& event)
{
	GlobalsFrame * pGlobalsFrame = new GlobalsFrame(L"Globals", m_LinnStrument);
	pGlobalsFrame->Show(true);
}


void LSAccessFrame::OnStepSequencerSettings(wxCommandEvent& event)
{
	SequencerFrame * pSequencerFrame = new SequencerFrame(L"Step Sequencer", m_LinnStrument);
	pSequencerFrame->Show(true);
}


// Options menu

void LSAccessFrame::OnSpeakMessages(wxCommandEvent& event)
{
	bool blnSpeechState = OptionsMenu->IsChecked(ID_SpeakMessages);
	m_LinnStrument->SetSpeakMessages(blnSpeechState);
	m_Config->SetPath("/SpeechOptions");
	m_Config->Write("SpeakMessages", blnSpeechState);
	}

void LSAccessFrame::OnSpeakNotes(wxCommandEvent& event)
{
	bool blnSpeechState = OptionsMenu->IsChecked(ID_SpeakNotes);
	m_LinnStrument->SetSpeakNotes(blnSpeechState);
		m_Config->SetPath("/SpeechOptions");
	m_Config->Write("SpeakNotes", blnSpeechState);
}


// Help menu
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

// Options menu
EVT_MENU( ID_SpeakMessages, LSAccessFrame::OnSpeakMessages)
EVT_MENU( ID_SpeakNotes, LSAccessFrame::OnSpeakNotes)

	// Help menu
EVT_MENU(ID_About, LSAccessFrame::OnAbout)
wxEND_EVENT_TABLE()
