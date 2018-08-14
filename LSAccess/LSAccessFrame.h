// LSAccessFrame.h
// The main window for the application

#pragma once

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/accel.h>
#include <wx/sizer.h>
#include <wx/menu.h>


#ifdef __WINDOWS__ 
#include <wx/msw/helpchm.h> // (MS HTML Help controller)
#else
#include <wx/generic/helpext.h>
#endif

// ID values and strings for menus and dialogs
const std::wstring wstrFileMenu = L"&File";

const std::wstring wstrOptionsMenu = L"&Options";
const unsigned int ID_NoteMute = 2001;
const std::wstring wstrNoteMute = L"&Mute note names";
const std::wstring wstrNoteMuteHelp = L"Stops speech announcing note names as you press LinnStrument's pads";

const std::wstring wstrHelpMenu = L"&Help";
unsigned int ID_HelpContents = 2002;
std::wstring wstrHelpContents = L"&Contents...";


// Number of accellerator keys to be defined
const unsigned int nKeys = 13;

// Screen positions
const int LEFT_MARGIN = 60;
const int TOP_MARGIN = 60;
const int NORMAL_WIDTH = 150;
const int TEXT_WIDTH = 600;


class LSAccessFrame : public wxFrame
{
public:
	LSAccessFrame(const wxString& title, bool EncryptionMode);
	~LSAccessFrame();

	void Shutdown();

private:
	bool InitData();
	void 	InitMenus();
	void UpdateStatusBar();
	// 	bool OpenLSPorts(LSPointer pMyLinnStrument);
	// 	void CloseLSPorts(LSPointer pMyLinnStrument);
	// 	std::string GetPortErrorReport(LSPointer pMyLinnStrument);
	// bool LoadOptions();
	// bool SaveOptions();

	// event handlers 
	void onStatusUpdate(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);

	void OnHelpContents(wxCommandEvent& event);
	void OnHelpAbout(wxCommandEvent& event);

	// internal storage
	wxPanel *myPanel;
	wxMenuBar *myMenuBar;

	// UI options, etc.
	// LSAccessOptions myOptions;

	// Menus
	wxMenu * FileMenu;
	wxMenu * OptionsMenu;
	wxMenu * HelpMenu;

	std::wstring wstrHelpFileName;

	// Platform-dependent help systems
#ifdef __WINDOWS__ 
	wxCHMHelpController * pHelpController;
#else
	wxExtHelpController * pHelpController;
#endif

	DECLARE_EVENT_TABLE()
};
