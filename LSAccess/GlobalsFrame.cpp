// GlobalsFrame.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "GlobalsFrame.h"


GlobalsFrame::GlobalsFrame(const wxString& title, LinnStrument * pLinnStrument)
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
	GlobalsGuitarPage * pGlobalsGuitarPage = new GlobalsGuitarPage(pNotebook, pLinnStrument);
	
	pNotebook->AddPage(pGlobalsGuitarPage, L"Guitar Row Tuning", true);
	
	vSizer->Insert(0, pNotebook, wxSizerFlags(5).Expand().Border());
	vSizer->Show(pNotebook);
}


// tabSet handlers...

void GlobalsFrame::OnTabChanged(wxNotebookEvent& event)
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


BEGIN_EVENT_TABLE(GlobalsFrame, wxFrame)
// Notebook tabs
EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, GlobalsFrame::OnTabChanged)
END_EVENT_TABLE()
