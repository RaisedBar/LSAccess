// PerSplitDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "PerSplitDialog.h"


PerSplitDialog::PerSplitDialog()
	: wxDialog()
{
InitWidgetsFromXRC();
}


PerSplitDialog::PerSplitDialog(const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split)
	: wxDialog(NULL, wxID_ANY, title),
pMyLinnStrument(pLinnStrument)
{
		InitWidgetsFromXRC();
		SetTitle(title);

		/*
	pBendPage = new BendPage(pNotebook, pLinnStrument, split);
	pAxesPage = new AxesPage(pNotebook, pLinnStrument, split);
	pColorsPage = new ColorsPage(pNotebook, pLinnStrument, split);
	pLowRowPage = new LowRowPage(pNotebook, pLinnStrument, split);
	pFadersPage = new FadersPage(pNotebook, pLinnStrument, split);
 	pSpecialPage = new SpecialPage(pNotebook, pLinnStrument, split);
		wxButton * btnOK = new wxButton(this, wxID_OK);
	btnOK->SetDefault();
	hBox1->Add(btnOK, 0, wxEXPAND);
	this->SetSizerAndFit(hBox1);
	hBox1->Show(pNotebook);
*/
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


// Custom XML handler

// Register with wxWidgets' dynamic class subsystem.
wxIMPLEMENT_DYNAMIC_CLASS(PerSplitDialogXmlHandler, wxXmlResourceHandler);

PerSplitDialogXmlHandler::PerSplitDialogXmlHandler()
{
	// this call adds support for all wxWidgets class styles    
	// (e.g. wxBORDER_SIMPLE, wxBORDER_SUNKEN, wxWS_EX_* etc etc)    
	AddWindowStyles();
}

wxObject * PerSplitDialogXmlHandler::DoCreateResource()
{
	// the following macro will init a pointer named "control"    
	// with a new instance of the PerSplitDialog class, but will NOT    
	// Create() it!    
		XRC_MAKE_INSTANCE(control, PerSplitDialog);
	return control;
}

		// this is the point where you'll typically need to do the most    
		// important changes: here the control is created and initialized.    
		// You'll want to use the wxXmlResourceHandler's getters to    
		// do most of your work.    
		// If e.g. the PerSplitDialog::Create function looks like:    
		//    
bool PerSplitDialog::Create(const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split)
{
	SetPosition(wxPoint( 0, 0));
	SetSize(wxSize( 800, 900));
	SetTitle(title);
	pMyLinnStrument = pLinnStrument;
	return true;
	}

		//                        const wxBitmap &first, const wxPoint &posFirst,    
		//                        const wxBitmap &second, const wxPoint &posSecond,    
		//                        const wxString &theTitle, const wxFont &titleFont,    
		//                        const wxPoint &pos, const wxSize &size,    
		//                        long style = PerSplitDialog_DEFAULT_STYLE,    
		//                        const wxString &name = wxT("MyControl"));    
		