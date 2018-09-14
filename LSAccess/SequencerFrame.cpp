// SequencerFrame.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "SequencerFrame.h"


SequencerFrame::SequencerFrame(const wxString& title, LinnStrument * pLinnStrument)
	: wxFrame(NULL, wxID_ANY, title),
	pMyLinnStrument(pLinnStrument)
{
		// Set up the multi-tab notebook
	wxPanel * pPanel = new wxPanel(this);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
			pNotebook = new wxNotebook(pPanel, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0);
	pTrack1Page = new SequencerPage(pNotebook, pLinnStrument, LSSplitType::LEFT);
	pTrack2Page = new SequencerPage(pNotebook, pLinnStrument, LSSplitType::RIGHT);
	
	pNotebook->AddPage(pTrack1Page, L"Track 1", true);
	pNotebook->AddPage(pTrack2Page, L"Track 2", false);
	
	hBox1->Insert(0, pNotebook, wxSizerFlags(5).Expand().Border());
	pPanel->SetSizerAndFit(hBox1);
	hBox1->Show(pNotebook);
}


// tabSet handlers...

void SequencerFrame::OnTabChanged(wxNotebookEvent& event)
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


BEGIN_EVENT_TABLE(SequencerFrame, wxFrame)
// Notebook tabs
EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, SequencerFrame::OnTabChanged)
END_EVENT_TABLE()
