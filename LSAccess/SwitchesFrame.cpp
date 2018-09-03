// SwitchesFrame.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "SwitchesFrame.h"


SwitchesFrame::SwitchesFrame(const wxString& title, LinnStrument * pLinnStrument)
	: wxFrame(NULL, wxID_ANY, title)
{
	pMyLinnStrument = pLinnStrument;

	// Set up the multi-tab notebook
	wxPanel * pPanel = new wxPanel(this);
	wxBoxSizer * vBox1 = new wxBoxSizer(wxVERTICAL);
	pPanel->SetSizer(vBox1);
	pPanel->Layout();

	wxNotebook * pNotebook = new wxNotebook(pPanel, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0);
	PanelSwitchesPage * pPanelSwitchesPage = new PanelSwitchesPage(pNotebook, pLinnStrument);
	FootSwitchesPage * pFootSwitchesPage = new FootSwitchesPage(pNotebook, pLinnStrument);

	pNotebook->AddPage(pPanelSwitchesPage, L"Panel", true);
	pNotebook->AddPage(pFootSwitchesPage, L"Foot", false);

	vBox1->Insert(0, pNotebook, wxSizerFlags(5).Expand().Border());
	pPanel->SetSizerAndFit(vBox1);
	vBox1->Show(pNotebook);
}


BEGIN_EVENT_TABLE(SwitchesFrame, wxFrame)
// Notebook tabs
// EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, SwitchesFrame::OnTabChanged)
END_EVENT_TABLE()
