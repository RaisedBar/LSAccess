// OctaveTransposeDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "OctaveTransposeDialog.h"


OctaveTransposeDialog::OctaveTransposeDialog(wxWindow* parent, LinnStrument * pLinnStrument)
	: wxDialog(NULL, wxID_ANY, L""),
	pMyLinnStrument(pLinnStrument)
{
	wxXmlResource::Get()->LoadDialog(this, parent, wxT("octave_transpose_dialog"));
}


// Event handlers

BEGIN_EVENT_TABLE(OctaveTransposeDialog, wxDialog)

END_EVENT_TABLE()
