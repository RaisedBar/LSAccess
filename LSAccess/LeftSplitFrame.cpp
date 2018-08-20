// LeftSplitFrame.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "LeftSplitFrame.h"


LeftSplitFrame::LeftSplitFrame(const wxString& title, LinnStrument * pLinnStrument)
	: wxFrame(NULL, wxID_ANY, title),
		pMyLinnStrument(new LinnStrument)
{
	pMyLinnStrument = pLinnStrument;
	
	// Set up the multi-tab notebook
	wxPanel * pPanel = new wxPanel(this);
	wxBoxSizer * vSizer = new wxBoxSizer(wxVERTICAL);
	pPanel->SetSizer(vSizer);
	pPanel->Layout();

	pNotebook = new wxNotebook(pPanel, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0);
	pChannelsPage = new ChannelsPage(pNotebook, pLinnStrument);
	pPitchBendPage = new PitchBendPage(pNotebook, pLinnStrument);
	pNotebook->AddPage(pChannelsPage, L"Channels", true);
	pNotebook->AddPage(pPitchBendPage, L"Pitch Bend", false);
		vSizer->Insert( 0, pNotebook, wxSizerFlags(5).Expand().Border());
	vSizer->Show(pNotebook);
}


// tabSet handlers...

void LeftSplitFrame::OnTabChanged(wxNotebookEvent& event)
{
	// contextualise the menus etc.
	switch (pNotebook->GetSelection())
	{
	case 0:
	{
		/*
				FileMenu->Enable( ID_IMPORT, true);
				FileMenu->Enable( ID_SAVE_AS, false);
				FileMenu->Enable( ID_PRINT, true);
		*/
	}
	break;

	default:
	{
		std::cerr << "Oops - unexpected tab change signal";
	}
	}
}


BEGIN_EVENT_TABLE(LeftSplitFrame, wxFrame)
// Notebook tabs
EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, LeftSplitFrame::OnTabChanged)
END_EVENT_TABLE()
