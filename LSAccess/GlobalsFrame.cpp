// GlobalsFrame.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "GlobalsFrame.h"


GlobalsFrame::GlobalsFrame(const wxString& title, LinnStrument * pLinnStrument)
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

	GlobalsSplitPage * pGlobalsSplitPage = new GlobalsSplitPage(pNotebook, pLinnStrument);
	GlobalsArpPage * pGlobalsArpPage = new GlobalsArpPage(pNotebook, pLinnStrument);
	GlobalsVelocityPressurePage * pGlobalsVelocityPressurePage = new GlobalsVelocityPressurePage(pNotebook, pLinnStrument);
	GlobalsNoteLightsPage * pGlobalsNoteLightsPage = new GlobalsNoteLightsPage(pNotebook, pLinnStrument);
	GlobalsAccentNoteLightsPage * pGlobalsAccentNoteLightsPage = new GlobalsAccentNoteLightsPage(pNotebook, pLinnStrument);
	GlobalsTuningsPage * pGlobalsTuningsPage = new GlobalsTuningsPage(pNotebook, pLinnStrument);
	GlobalsPowerMIDIPage * pGlobalsPowerMIDIPage = new 
		GlobalsPowerMIDIPage(pNotebook, pLinnStrument);

	pNotebook->AddPage(pGlobalsSplitPage, L"Split", true);
		pNotebook->AddPage(pGlobalsArpPage, L"Arp", false);
	pNotebook->AddPage( pGlobalsVelocityPressurePage, L"Velocity/Pressure", false);
	pNotebook->AddPage(pGlobalsNoteLightsPage, L"Note Lights", FALSE);
	pNotebook->AddPage(pGlobalsAccentNoteLightsPage, L"Accent Note Lights", false);
		pNotebook->AddPage(pGlobalsTuningsPage, L"Row Tuning", false);
		pNotebook->AddPage(pGlobalsPowerMIDIPage, L"Power/MIDI", FALSE);
	
		vSizer->Insert(0, pNotebook, wxSizerFlags(5).Expand().Border());
	vSizer->Show(pNotebook);
}


// tabSet handlers...

BEGIN_EVENT_TABLE(GlobalsFrame, wxFrame)
// Notebook tabs
// EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, GlobalsFrame::OnTabChanged)
END_EVENT_TABLE()
