// OctaveTransposeFrame.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "OctaveTransposeFrame.h"


OctaveTransposeFrame::OctaveTransposeFrame(const wxString& title, LinnStrument * pLinnStrument)
	: wxFrame(NULL, wxID_ANY, title),
	pMyLinnStrument(pLinnStrument)
{
		// Set up the multi-tab notebook
	wxPanel * pPanel = new wxPanel(this);
	wxBoxSizer * vBox1 = new wxBoxSizer(wxVERTICAL);
	pPanel->SetSizer(vBox1);
	pPanel->Layout();

	wxNotebook * pNotebook = new wxNotebook(pPanel, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0);
	OctaveTransposePage * pLeftOctaveTransposePage = new OctaveTransposePage(pNotebook, pLinnStrument, LSSplitType::LEFT);
	OctaveTransposePage * pRightOctaveTransposePage = new OctaveTransposePage(pNotebook, pLinnStrument, LSSplitType::RIGHT);

	pNotebook->AddPage(pLeftOctaveTransposePage, L"Left", true);
	pNotebook->AddPage(pRightOctaveTransposePage, L"Right", false);

	vBox1->Insert(0, pNotebook, wxSizerFlags(5).Expand().Border());
	pPanel->SetSizerAndFit(vBox1);
	vBox1->Show(pNotebook);
}


BEGIN_EVENT_TABLE(OctaveTransposeFrame, wxFrame)
// Notebook tabs
// EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, OctaveTransposeFrame::OnTabChanged)
END_EVENT_TABLE()
