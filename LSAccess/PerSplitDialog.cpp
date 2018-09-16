// PerSplitDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "PerSplitDialog.h"


PerSplitDialog::PerSplitDialog(const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split)
	: wxDialog(NULL, wxID_ANY, title),
	pMyLinnStrument(pLinnStrument)
{
		// Set up the multi-tab notebook
	wxPanel * pPanel = new wxPanel(this);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	pNotebook = new wxNotebook(pPanel, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0);
	pMIDISplitPage = new MIDISplitPage(pNotebook, pLinnStrument, split);
	pBendPage = new BendPage(pNotebook, pLinnStrument, split);
	pAxesPage = new AxesPage(pNotebook, pLinnStrument, split);
	pColorsPage = new ColorsPage(pNotebook, pLinnStrument, split);
	pLowRowPage = new LowRowPage(pNotebook, pLinnStrument, split);
	pFadersPage = new FadersPage(pNotebook, pLinnStrument, split);
 	pSpecialPage = new SpecialPage(pNotebook, pLinnStrument, split);
	
	pNotebook->AddPage(pMIDISplitPage, L"MIDI", true);
	pNotebook->AddPage(pBendPage, L"Bend (X-axis)", false);
	pNotebook->AddPage(pAxesPage, L"Y-Z Axes", false);
	pNotebook->AddPage(pColorsPage, L"Colors and Animations", false);
	pNotebook->AddPage(pLowRowPage, L"Low Row", false);
	pNotebook->AddPage(pFadersPage, L"Faders", false);
	pNotebook->AddPage(pSpecialPage, L"Special", false);
	hBox1->Insert(0, pNotebook, wxSizerFlags(7).Expand().Border());
	
	wxButton * btnOK = new wxButton(this, wxID_OK);
	btnOK->SetDefault();
	hBox1->Add(btnOK, 0, wxEXPAND);
	pPanel->SetSizerAndFit(hBox1);
	hBox1->Show(pNotebook);
}


// tabSet handlers...

void PerSplitDialog::OnTabChanged(wxNotebookEvent& event)
{
	// contextualise the menus etc.
	switch (pNotebook->GetSelection())
	{
	case 0:
	{
// Do something
	}
	break;

	default:
	{
		std::cerr << "Oops - unexpected tab change signal";
	}
	}
}


void PerSplitDialog::OnOK(wxCommandEvent& event)
{
	EndModal(true);
}


BEGIN_EVENT_TABLE(PerSplitDialog, wxDialog)
// Notebook tabs
EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, PerSplitDialog::OnTabChanged)

// Buttons
EVT_BUTTON( wxID_OK, PerSplitDialog::OnOK)
END_EVENT_TABLE()
