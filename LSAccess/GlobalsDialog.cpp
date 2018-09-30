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
	wxXmlResource::Get()->LoadDialog(this, parent, wxT("globals_dialog"));
	
/*
GlobalsSplitPage * pGlobalsSplitPage = new GlobalsSplitPage(pNotebook, pLinnStrument);
	GlobalsArpPage * pGlobalsArpPage = new GlobalsArpPage(pNotebook, pLinnStrument);
	GlobalsVelocityPressurePage * pGlobalsVelocityPressurePage = new GlobalsVelocityPressurePage(pNotebook, pLinnStrument);
	GlobalsNoteLightsPage * pGlobalsNoteLightsPage = new GlobalsNoteLightsPage(pNotebook, pLinnStrument);
	GlobalsAccentNoteLightsPage * pGlobalsAccentNoteLightsPage = new GlobalsAccentNoteLightsPage(pNotebook, pLinnStrument);
	GlobalsTuningsPage * pGlobalsTuningsPage = new GlobalsTuningsPage(pNotebook, pLinnStrument);
	GlobalsPowerMIDIPage * pGlobalsPowerMIDIPage = new 
*/
}


// Event handlers

BEGIN_EVENT_TABLE(GlobalsDialog, wxDialog)
END_EVENT_TABLE()
