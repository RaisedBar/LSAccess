// LSAccessFrame.cpp
// Main window for the application

#include "stdafx.h"
#include "LSAccessFrame.h"

const std::string strMIDIOptions = "/MIDIOptions";
const std::string strInPort = "InPort";
const std::string strOutPort = "OutPort";

const std::string strSpeechOptions = "/SpeechOptions";
const std::string strSpeakMessages = "SpeakMessages";
const std::string strSpeakNotes = "SpeakNotes";

LSAccessFrame::LSAccessFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
		// set the frame icon
	SetIcon(wxICON(sample));

	// Restore any saved settings
		wxDir myDir;
	std::wstring wstrConfigPath(wxStandardPaths::Get().GetUserConfigDir() + L"\\" + wstrVendor + L"\\" + wstrAppName);

	if (!myDir.Exists(wstrConfigPath))
	{
		myDir.Make(wxStandardPaths::Get().GetUserConfigDir() + L"\\" + wstrVendor);
		myDir.Make(wstrConfigPath);
	}

	int nInputID = -1;
	int nOutputID = -1;
	std::wstring wstrIniPath = wstrConfigPath + L"\\" + wstrAppName + L".ini";
	m_IniFile.SetPath(wstrIniPath);
	m_Config = new wxFileConfig(wstrVendor, wstrAppName, wstrIniPath);
	m_Config->SetPath(wstrConfigPath);
	
	if (m_Config->HasGroup(strMIDIOptions))
	{
		m_Config->SetPath(strMIDIOptions);
		
		if (m_Config->HasEntry(strInPort))
		{
			nInputID = m_Config->ReadLong(strInPort, -1);
		}
		else
		{
			nInputID = -1;
		}

		if (m_Config->HasEntry(strOutPort))
		{
			nOutputID = m_Config->ReadLong(strOutPort, -1);
		}
		else
		{
			nOutputID = -1;
		}
	}
	
	bool blnSpeakMessages;
	bool blnSpeakNotes;

	if (m_Config->HasGroup(strSpeechOptions))
	{
		m_Config->SetPath(strSpeechOptions);

		if (m_Config->HasEntry(strSpeakMessages))
		{
			blnSpeakMessages = m_Config->ReadBool(strSpeakMessages, true);
					}

		if (m_Config->HasEntry(strSpeakNotes))
		{
			blnSpeakNotes = m_Config->ReadBool(strSpeakMessages, true);
		}
	}

	// We now have enough information to create the LinnStrument
	try
	{
		m_LinnStrument = LinnStrument::LinnStrument(this, nInputID, nOutputID, blnSpeakMessages, blnSpeakNotes);
	}
catch (RtMidiError &error)
{
	wxMessageBox(error.getMessage(), wstrAppName + L" error", wxOK | wxICON_ERROR);
}

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
OptionsMenu->AppendCheckItem( ID_SpeakMessages, "&Speak messages\tF9", "Enable speech output of status information");
	OptionsMenu->AppendCheckItem(ID_SpeakNotes, "Speak &note names\tF10", "Announce the names of notes when LinnStrument pads are played");
	OptionsMenu->Append(ID_RefreshAll, "&Refresh all parameters\tF11", "Request all parameters from the LinnStrument to update the editor");

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
	CreateStatusBar();
		SetStatusText("Welcome to LSAccess!");
	this->Maximize();
}		


LSAccessFrame::~LSAccessFrame()
{
	// Save settings and clean-up
	m_Config->SetPath(strSpeechOptions);
	m_Config->Write(strSpeakMessages, m_LinnStrument.GetSpeakMessages());
	m_Config->Write(strSpeakNotes, m_LinnStrument.GetSpeakNotes());
	m_Config->SetPath( strMIDIOptions);
	m_Config->Write(strInPort, m_LinnStrument.GetMIDIInID());
	m_Config->Write(strOutPort, m_LinnStrument.GetMIDIOutID());
	m_Config->Flush();
	delete m_Config;
	}


// event handlers

WXLRESULT LSAccessFrame::MSWWindowProc(WXUINT nMsg, WXWPARAM wParam, WXLPARAM lParam) 
{
	wxLogDebug(wxT("MSWWindowProc %08x %08x %08x"), nMsg, wParam, lParam);
	std::wstring wstrOut;

// Detect hardware changes as LinnStrument transitions to/from MIDI and O/S update modes
	if (nMsg == WM_DEVICECHANGE)
		// && (wParam == DBT_DEVICEARRIVAL || wParam == DBT_DEVICEREMOVECOMPLETE))
	{
		wxLogDebug(wxT("WM_DEVICECHANGE %x %x"), wParam, lParam);
		switch (wParam)
		{
		case DBT_CONFIGCHANGECANCELED:   // 0x0019 A request to change the current configuration (dock or undock) has been canceled.
		{
			wstrOut = L"DBT_CONFIGCHANGECANCELED";
		}
		break;

		case DBT_CONFIGCHANGED:   // 0x0018 The current configuration has changed, due to a dock or undock.
		{
			wstrOut = L"DBT_CONFIGCHANGED";
		}
		break;

		case DBT_CUSTOMEVENT:   // 0x8006 A custom event has occurred.
		{
			wstrOut = L"DBT_CUSTOMEVENT";
		}
		break;

		case DBT_DEVICEARRIVAL:   // 0x8000 A device or piece of media has been inserted and is now available.
		{
			wstrOut = L"DBT_DEVICEARRIVAL";
		}
		break;

		case DBT_DEVICEQUERYREMOVE:   // 0x8001 Permission is requested to remove a device or piece of media. Any application can deny this request and cancel the removal.
		{
			wstrOut = L"DBT_DEVICEQUERYREMOVE";
		} 
		break;

		case DBT_DEVICEQUERYREMOVEFAILED:   // 0x8002 A request to remove a device or piece of media has been canceled.
		{
			wstrOut = L"DBT_DEVICEQUERYREMOVEFAILED";
		}
		break;

		case DBT_DEVICEREMOVECOMPLETE:   // 0x8004 A device or piece of media has been removed.
		{
			wstrOut = L"DBT_DEVICEREMOVECOMPLETE";
		}
		break;

		case DBT_DEVICEREMOVEPENDING:   // 0x8003 A device or piece of media is about to be removed. Cannot be denied.
		{
			wstrOut = L"DBT_DEVICEREMOVEPENDING";
		}
		break;

		case DBT_DEVICETYPESPECIFIC:   // 0x8005 A device-specific event has occurred.
		{
			wstrOut = L"DBT_DEVICETYPESPECIFIC";
		}
		break;

		case DBT_DEVNODES_CHANGED:   // 0x0007 A device has been added to or removed from the system.
		{
			wstrOut = L"DBT_DEVNODES_CHANGED";
				// Some hardware device has been added or removed. Check for LinnStrument MIDI USB connection
				unsigned int nInputID = m_LinnStrument.GetUSBInPortID();
			unsigned int nOutputID = m_LinnStrument.GetUSBOutPortID();

			if ((nInputID != -1) && (nOutputID != -1))
			{
				// USB connection found, so make sure we're using it
				m_LinnStrument.SetMIDIInID(nInputID);
				m_LinnStrument.SetMIDIOutID(nOutputID);
			}
			else
			{
				// Check for LinnStrument serial port (i.e. O/S update mode
				if (m_LinnStrument.IsUpdateMode())
				{
					m_LinnStrument.Speak(L"Firmware update mode");
				}
				else
				{
					m_LinnStrument.Speak(L"No USB connection to a LinnStrument");
				}
			}  // end if USB
		}
		break;

		case DBT_QUERYCHANGECONFIG:   // 0x0017 Permission is requested to change the current configuration (dock or undock).
		{
			wstrOut = L"DBT_QUERYCHANGECONFIG";
		}
		break;

		case DBT_USERDEFINED:   // 0xFFFF The meaning of this message is user-defined.
		{
			wstrOut = L"DBT_USERDEFINED";
		}
		break;

		default:
		{
			wstrOut = L"Unknown";
		}
		break;
				}   // end wparam switch
			}  // end if wm_devicechange
	return wxFrame::MSWWindowProc(nMsg, wParam, lParam);
}


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


// Options menu

void LSAccessFrame::OnSpeakMessages(wxCommandEvent& event)
{
		m_LinnStrument.SetSpeakMessages(! m_LinnStrument.GetSpeakMessages());
	}


void LSAccessFrame::OnSpeakNotes(wxCommandEvent& event)
{
		m_LinnStrument.SetSpeakNotes(! m_LinnStrument.GetSpeakNotes());
		}


void LSAccessFrame::OnRefreshAll(wxCommandEvent& event)
{
	m_LinnStrument.QueryAll();
	wxMessageBox(L"All editor parameters refreshed.", wstrAppName, wxOK | wxICON_INFORMATION, this);
}

void LSAccessFrame::OnAbout(wxCommandEvent& event)
{
	std::wstring wstrAboutText = L"Author: Tim Burgess\n" + wstrVendor;
			wxMessageBox(wstrAboutText, wstrAppName, wxOK | wxICON_INFORMATION);
}


void LSAccessFrame::onStatusUpdate(wxCommandEvent& event)
{
		wxString wxstrStatus = event.GetString();
	
	SetStatusText(wxEmptyString);
	SetStatusText(wxstrStatus);
	this->Refresh();
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
EVT_MENU(ID_RefreshAll, LSAccessFrame::OnRefreshAll)

	// Help menu
EVT_MENU(ID_About, LSAccessFrame::OnAbout)

// Custom events
// Update the status bar
EVT_COMMAND(STATUS_UPDATE_ID, NoteEvent, LSAccessFrame::onStatusUpdate)
wxEND_EVENT_TABLE()
