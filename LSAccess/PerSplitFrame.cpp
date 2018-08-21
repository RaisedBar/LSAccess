// PerSplitFrame.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "PerSplitFrame.h"


PerSplitFrame::PerSplitFrame(const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split)
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
	pChannelsPage = new ChannelsPage(pNotebook, pLinnStrument, split);
	pBendPage = new BendPage(pNotebook, pLinnStrument, split);
	pSequencerPage = new SequencerPage(pNotebook, pLinnStrument, split);
	pColorsPage = new ColorsPage(pNotebook, pLinnStrument, split);
	pFadersPage = new FadersPage(pNotebook, pLinnStrument, split);
	pAxesPage = new AxesPage(pNotebook, pLinnStrument, split);

			pNotebook->AddPage(pChannelsPage, L"Channels", true);
	pNotebook->AddPage(pBendPage, L"Bend", false);
	pNotebook->AddPage(pSequencerPage, L"Sequencer", false);
	pNotebook->AddPage(pColorsPage, L"Colors and Animations", false);
	pNotebook->AddPage(pFadersPage, L"Faders", false);
	pNotebook->AddPage(pAxesPage, L"X, Y and Z Axes", false);
	
	vSizer->Insert( 0, pNotebook, wxSizerFlags(5).Expand().Border());
	vSizer->Show(pNotebook);
}


// tabSet handlers...

void PerSplitFrame::OnTabChanged(wxNotebookEvent& event)
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


BEGIN_EVENT_TABLE(PerSplitFrame, wxFrame)
// Notebook tabs
EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, PerSplitFrame::OnTabChanged)
END_EVENT_TABLE()
