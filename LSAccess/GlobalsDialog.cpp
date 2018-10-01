// GlobalsDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "GlobalsDialog.h"


GlobalsDialog::GlobalsDialog(wxWindow* parent, const wxString& title, LinnStrument * pLinnStrument)
	: wxDialog(NULL, wxID_ANY, title),
	pMyLinnStrument( pLinnStrument)
{
	if (wxXmlResource::Get()->LoadDialog(this, parent, wxT("globals_dialog")))
	{
	}
else
	{
	wxMessageBox("Could not load Global Settings dialog from XRC", wstrErrorTitle + L" error", wxOK | wxICON_ERROR);
	EndModal(false);
	}
}


// Event handlers

BEGIN_EVENT_TABLE(GlobalsDialog, wxDialog)
END_EVENT_TABLE()
