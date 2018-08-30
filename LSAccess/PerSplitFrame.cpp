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
	wxBoxSizer * vBox1 = new wxBoxSizer(wxVERTICAL);

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
	pNotebook->AddPage(pSpecialPage, L"Special", false);

	vBox1->Insert(0, pNotebook, wxSizerFlags(6).Expand().Border());
	pPanel->SetSizer(vBox1);
	pPanel->Layout();
	pPanel->SetSizerAndFit(vBox1);
	vBox1->Show(pNotebook);
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
