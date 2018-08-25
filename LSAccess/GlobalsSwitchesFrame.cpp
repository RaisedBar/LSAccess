// GlobalsSwitchesFrame.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "GlobalsSwitchesFrame.h"


GlobalsSwitchesFrame::GlobalsSwitchesFrame(const wxString& title, LinnStrument * pLinnStrument)
	: wxFrame(NULL, wxID_ANY, title),
	pMyLinnStrument(new LinnStrument)
{
	pMyLinnStrument = pLinnStrument;

	// Set up the multi-tab notebook
	wxPanel * pPanel = new wxPanel(this);
	wxBoxSizer * vSizer = new wxBoxSizer(wxVERTICAL);
	pPanel->SetSizer(vSizer);
	pPanel->Layout();

	wxNotebook * pNotebook = new wxNotebook(pPanel, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0);
	GlobalsPanelSwitchesPage * pGlobalsPanelSwitchesPage = new GlobalsPanelSwitchesPage(pNotebook, pLinnStrument);
	GlobalsFootSwitchesPage * pGlobalsFootSwitchesPage = new GlobalsFootSwitchesPage(pNotebook, pLinnStrument);

	pNotebook->AddPage(pGlobalsPanelSwitchesPage, L"Panel", true);
	pNotebook->AddPage(pGlobalsFootSwitchesPage, L"Foot", false);

	vSizer->Insert(0, pNotebook, wxSizerFlags(5).Expand().Border());
	vSizer->Show(pNotebook);
}


BEGIN_EVENT_TABLE(GlobalsSwitchesFrame, wxFrame)
// Notebook tabs
// EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, GlobalsSwitchesFrame::OnTabChanged)
END_EVENT_TABLE()
