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
	}


BEGIN_EVENT_TABLE(PerSplitDialog, wxDialog)
// Buttons
// EVT_BUTTON( wxID_OK, PerSplitDialog::OnOK)
END_EVENT_TABLE()
