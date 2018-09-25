// PerSplitDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "PerSplitDialog.h"


PerSplitDialog::PerSplitDialog(wxWindow* parent, const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split)
	: wxDialog(NULL, wxID_ANY, title),
pMyLinnStrument(pLinnStrument)
{
	wxXmlResource::Get()->LoadDialog(this, parent, wxT("per_split_dialog"));
	SetTitle(title);
	/*
		pBendPage
		pAxesPage = new AxesPage(pNotebook, pLinnStrument, split);
	pColorsPage = new ColorsPage(pNotebook, pLinnStrument, split);
	pLowRowPage = new LowRowPage(pNotebook, pLinnStrument, split);
	pFadersPage = new FadersPage(pNotebook, pLinnStrument, split);
	pSpecialPage = new SpecialPage(pNotebook, pLinnStrument, split);
		wxButton * btnOK = new wxButton(this, wxID_OK);
	btnOK->SetDefault();
	hBox1->Add(btnOK, 0, wxEXPAND);
	*/
}


void PerSplitDialog::InitWidgetsFromXRC()
{					}


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
EVT_NOTEBOOK_PAGE_CHANGED( XRCID("notebook_1"), PerSplitDialog::OnTabChanged)

// Buttons
// EVT_BUTTON( wxID_OK, PerSplitDialog::OnOK)
END_EVENT_TABLE()
