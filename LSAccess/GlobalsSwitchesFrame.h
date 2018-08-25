// GlobalsSwitchesFrame.h
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net

#pragma once

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include <wx/notebook.h>

#include "LSEnums.h"
#include "GlobalsPanelSwitchesPage.h"
#include "GlobalsFootSwitchesPage.h"

class GlobalsSwitchesFrame : public wxFrame
{
public:
	GlobalsSwitchesFrame(const wxString& title, LinnStrument * pLinnStrument);

private:
		LinnStrument * pMyLinnStrument;
		
	DECLARE_EVENT_TABLE()
};
