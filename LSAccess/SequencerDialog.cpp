// SequencerDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "SequencerDialog.h"


SequencerDialog::SequencerDialog(const wxString& title, LinnStrument * pLinnStrument)
	: wxDialog(NULL, wxID_ANY, title),
	pMyLinnStrument(pLinnStrument)
{
		// Set up the multi-tab notebook
		wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
			pNotebook = new wxNotebook(this, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0);
	pTrack1Page = new SequencerPage(pNotebook, pLinnStrument, LSSplitType::LEFT);
	pTrack2Page = new SequencerPage(pNotebook, pLinnStrument, LSSplitType::RIGHT);
	
	pNotebook->AddPage(pTrack1Page, L"Track 1", true);
	pNotebook->AddPage(pTrack2Page, L"Track 2", false);
	hBox1->Add(pNotebook, 0, wxEXPAND);

		wxButton * btnOK = new wxButton(this, wxID_OK);
		btnOK->SetDefault();
		hBox1->Add(btnOK, 0, wxEXPAND);

		this->SetSizerAndFit(hBox1);
	hBox1->Show(pNotebook);
}


// Event handlers

void SequencerDialog::OnOK(wxCommandEvent& event)
{
	EndModal(true);
}


BEGIN_EVENT_TABLE(SequencerDialog, wxDialog)
// Buttons
EVT_BUTTON(wxID_OK, SequencerDialog::OnOK)
END_EVENT_TABLE()
