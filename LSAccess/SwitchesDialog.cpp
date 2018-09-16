// SwitchesDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "SwitchesDialog.h"


SwitchesDialog::SwitchesDialog(const wxString& title, LinnStrument * pLinnStrument)
	: wxDialog(NULL, wxID_ANY, title),
	pMyLinnStrument(pLinnStrument)
{
		// Set up the multi-tab notebook
	wxPanel * pPanel = new wxPanel(this);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
			wxNotebook * pNotebook = new wxNotebook(pPanel, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0);
	PanelSwitchesPage * pPanelSwitchesPage = new PanelSwitchesPage(pNotebook, pLinnStrument);
	FootSwitchesPage * pFootSwitchesPage = new FootSwitchesPage(pNotebook, pLinnStrument);

	pNotebook->AddPage(pPanelSwitchesPage, L"Panel", true);
	pNotebook->AddPage(pFootSwitchesPage, L"Foot", false);
hBox1->Insert(0, pNotebook, wxSizerFlags(5).Expand().Border());

wxButton * btnOK = new wxButton(this, wxID_OK);
btnOK->SetDefault();
hBox1->Add(btnOK, 0, wxEXPAND);

pPanel->SetSizerAndFit(hBox1);
	hBox1->Show(pNotebook);
}


// Event handlers

void SwitchesDialog::OnOK(wxCommandEvent& event)
{
	EndModal(true);
}


BEGIN_EVENT_TABLE(SwitchesDialog, wxDialog)
// Buttons
EVT_BUTTON(wxID_OK, SwitchesDialog::OnOK)
END_EVENT_TABLE()
