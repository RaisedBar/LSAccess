// OctaveTransposeDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "OctaveTransposeDialog.h"


OctaveTransposeDialog::OctaveTransposeDialog(const wxString& title, LinnStrument * pLinnStrument)
	: wxDialog(NULL, wxID_ANY, title),
	pMyLinnStrument(pLinnStrument)
{
		// Set up the multi-tab notebook
	wxPanel * pPanel = new wxPanel(this);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
		wxNotebook * pNotebook = new wxNotebook(pPanel, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0);
	OctaveTransposePage * pLeftOctaveTransposePage = new OctaveTransposePage(pNotebook, pLinnStrument, LSSplitType::LEFT);
	OctaveTransposePage * pRightOctaveTransposePage = new OctaveTransposePage(pNotebook, pLinnStrument, LSSplitType::RIGHT);

	pNotebook->AddPage(pLeftOctaveTransposePage, L"Left", true);
	pNotebook->AddPage(pRightOctaveTransposePage, L"Right", false);

	hBox1->Insert(0, pNotebook, wxSizerFlags(2).Expand().Border());
	
	wxButton * btnOK = new wxButton(this, wxID_OK);
	btnOK->SetDefault();
	hBox1->Add(btnOK, 0, wxEXPAND);

	pPanel->SetSizerAndFit(hBox1);
	hBox1->Show(pNotebook);
}


// Event handlers

void OctaveTransposeDialog::OnOK(wxCommandEvent& event)
{
	EndModal(true);
}


BEGIN_EVENT_TABLE(OctaveTransposeDialog, wxDialog)
// Notebook tabs
// EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, OctaveTransposeDialog::OnTabChanged)
// Buttons
EVT_BUTTON(wxID_OK, OctaveTransposeDialog::OnOK)
END_EVENT_TABLE()
