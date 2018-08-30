// PresetsVolumesFrame.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "PresetsVolumesFrame.h"


PresetsVolumesFrame::PresetsVolumesFrame(const wxString& title, LinnStrument * pLinnStrument)
	: wxFrame(NULL, wxID_ANY, title),
	pMyLinnStrument(new LinnStrument)
{
	pMyLinnStrument = pLinnStrument;

	// Set up the multi-tab notebook
	wxPanel * pPanel = new wxPanel(this);
	wxBoxSizer * vBox1 = new wxBoxSizer(wxVERTICAL);
	pPanel->SetSizer(vBox1);
	pPanel->Layout();

	pNotebook = new wxNotebook(pPanel, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0);
	pLeftPresetsVolumesPage = new PresetsVolumesPage(pNotebook, pLinnStrument, LSSplitType::LEFT);
	pRightPresetsVolumesPage = new PresetsVolumesPage(pNotebook, pLinnStrument, LSSplitType::RIGHT);

	pNotebook->AddPage(pLeftPresetsVolumesPage, L"Left", true);
	pNotebook->AddPage(pRightPresetsVolumesPage, L"Right", false);

	vBox1->Insert(0, pNotebook, wxSizerFlags(5).Expand().Border());
	pPanel->SetSizerAndFit(vBox1);
	vBox1->Show(pNotebook);
}


// tabSet handlers...

void PresetsVolumesFrame::OnTabChanged(wxNotebookEvent& event)
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


BEGIN_EVENT_TABLE(PresetsVolumesFrame, wxFrame)
// Notebook tabs
EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, PresetsVolumesFrame::OnTabChanged)
END_EVENT_TABLE()
