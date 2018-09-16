// PresetsVolumesDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "PresetsVolumesDialog.h"


PresetsVolumesDialog::PresetsVolumesDialog(const wxString& title, LinnStrument * pLinnStrument)
	: wxDialog(NULL, wxID_ANY, title),
	pMyLinnStrument(pLinnStrument)
{
		// Set up the multi-tab notebook
	wxPanel * pPanel = new wxPanel(this);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
	pNotebook = new wxNotebook(pPanel, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0);
	pLeftPresetsVolumesPage = new PresetsVolumesPage(pNotebook, pLinnStrument, LSSplitType::LEFT);
	pRightPresetsVolumesPage = new PresetsVolumesPage(pNotebook, pLinnStrument, LSSplitType::RIGHT);

	pNotebook->AddPage(pLeftPresetsVolumesPage, L"Left", true);
	pNotebook->AddPage(pRightPresetsVolumesPage, L"Right", false);

	hBox1->Insert(0, pNotebook, wxSizerFlags(2).Expand().Border());
	
	wxButton * btnOK = new wxButton(this, wxID_OK);
	btnOK->SetDefault();
	hBox1->Add(btnOK, 0, wxEXPAND);

	pPanel->SetSizerAndFit(hBox1);
	hBox1->Show(pNotebook);
}


// Event handlers

void PresetsVolumesDialog::OnOK(wxCommandEvent& event)
{
	EndModal(true);
}


BEGIN_EVENT_TABLE(PresetsVolumesDialog, wxDialog)
// Buttons
EVT_BUTTON(wxID_OK, PresetsVolumesDialog::OnOK)
END_EVENT_TABLE()
