// LSAccessFrame
// Main wi ndow for the application

#include "LSAccessFrame.h"


LSAccessFrame::LSAccessFrame(const wxString& title, bool EncryptionMode) :
	wxFrame(NULL, wxID_ANY, title)
{
	// Load user options
	// LoadOptions();

	/*
	// Initialise the help system
#ifdef __WINDOWS__
	path myHelpPath(HelpPath());
	wstrHelpFileName = HelpPath().generic_wstring();
	wstrHelpFileName.append(wstrCHMHelpFile);
	pHelpController = new wxCHMHelpController;

	if (!pHelpController->Initialize(wstrHelpFileName))
	{
		wxMessageBox(wstrHelpInitError, wstrErrorTitle, wxOK | wxICON_ERROR);
	}
#else
	std::wstring wstrHelpURL = PathToURL(HelpPath().generic_wstring());
	// 	wstrHelpFileName = "SurfaceReader.htb";
	pHelpController = new wxExtHelpController;

	// Required for wxWidgets HTML help
	// wxFileSystem::AddHandler( new wxZipFSHandler);

	// pHelpController = new wxHtmlHelpController;

	if (!pHelpController->Initialize(HelpPath().generic_string()))
	{
		wxMessageBox(wstrHelpInitError, wstrErrorTitle, wxOK | wxICON_ERROR);
	}

	// 	pHelpController->AddBook( wstrHelpFileName);
#endif
*/

	// Set up the accellerator keys
wxAcceleratorEntry wxaEntries[nKeys];

	wxAcceleratorTable wxatKeys(nKeys, wxaEntries);
	SetAcceleratorTable(wxatKeys);

	// set the frame icon
	//std::string strIcon = AppDataPath();
	//append( wstrAppIconFileName);	
	//SetIcon( wxICON( wstrIcon));

	// create a menu bar
	InitMenus();

	// Set up the rest of the UI
	myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox = new wxBoxSizer(wxHORIZONTAL);

	// We want to show what the application is up to
	CreateStatusBar();

	Centre();

	// Always show the frame if any errors happen during data load
	if (InitData() == false)
			{
		this->Show(true);
	}
		}


LSAccessFrame::~LSAccessFrame()
{
	pHelpController->Quit();
	delete pHelpController;
}


bool LSAccessFrame::InitData()
{
	bool blnResult = true;
	// Load any data here
	return blnResult;
}


void LSAccessFrame::InitMenus()
{
	FileMenu = new wxMenu;
	FileMenu->Append(wxID_EXIT);

	OptionsMenu = new wxMenu;
	OptionsMenu->AppendCheckItem(ID_NoteMute, wstrNoteMute, wstrNoteMuteHelp);

HelpMenu = new wxMenu;
HelpMenu->Append(ID_HelpContents, wstrHelpContents);
	HelpMenu->Append(wxID_ABOUT);

	myMenuBar = new wxMenuBar();
	myMenuBar->Append(FileMenu, wstrFileMenu);
	myMenuBar->Append(OptionsMenu, wstrOptionsMenu);
	myMenuBar->Append(HelpMenu, wstrHelpMenu);
	SetMenuBar(myMenuBar);
}


void LSAccessFrame::UpdateStatusBar()
{
	std::wstring wstrOut;

	SetStatusText(wstrOut);
}


// Event table
BEGIN_EVENT_TABLE(LSAccessFrame, wxFrame)
// Menu events
// EVT_MENU(wxID_EXIT, LSAccessFrame::OnQuit)
// EVT_CLOSE(LSAccessFrame::OnCloseWindow)
// EVT_MENU( ID_NoteMute,                 LSAccessFrame::OnNoteMute)

// EVT_MENU(ID_HelpContents, LSAccessFrame::OnHelpContents)
// EVT_MENU(wxID_ABOUT, LSAccessFrame::OnHelpAbout)
END_EVENT_TABLE()


