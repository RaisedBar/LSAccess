// GlobalsDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "GlobalsDialog.h"


GlobalsDialog::GlobalsDialog(const wxString& title, LinnStrument * pLinnStrument)
	: wxDialog(NULL, wxID_ANY, title),
	pMyLinnStrument( pLinnStrument)
{
		// Set up the multi-tab notebook
	wxPanel * pPanel = new wxPanel(this);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
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
				hBox1->Insert(0, pNotebook, wxSizerFlags(5).Expand().Border());

				wxButton * btnOK = new wxButton(this, wxID_OK);
				btnOK->SetDefault();
				hBox1->Add(btnOK, 0, wxEXPAND);

		pPanel->SetSizerAndFit(hBox1);
	hBox1->Show(pNotebook);
}


// Event handlers

void GlobalsDialog::OnOK(wxCommandEvent& event)
{
	EndModal(true);
}


BEGIN_EVENT_TABLE(GlobalsDialog, wxDialog)
// Notebook tabs
// EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, GlobalsDialog::OnTabChanged)
// Buttons
EVT_BUTTON(wxID_OK, GlobalsDialog::OnOK)
END_EVENT_TABLE()
