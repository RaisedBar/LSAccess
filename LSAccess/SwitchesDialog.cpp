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
		wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
			wxNotebook * pNotebook = new wxNotebook(this, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0);
	PanelSwitchesPage * thisSwitchesPage = new PanelSwitchesPage(pNotebook, pLinnStrument);
	FootSwitchesPage * pFootSwitchesPage = new FootSwitchesPage(pNotebook, pLinnStrument);

	pNotebook->AddPage(thisSwitchesPage, L"Panel", true);
	pNotebook->AddPage(pFootSwitchesPage, L"Foot", false);
	hBox1->Add(pNotebook, 0, wxEXPAND);

wxButton * btnOK = new wxButton(this, wxID_OK);
btnOK->SetDefault();
hBox1->Add(btnOK, 0, wxEXPAND);

this->SetSizerAndFit(hBox1);
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
