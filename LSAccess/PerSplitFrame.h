// PerSplitFrame.h
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
#include "MIDISplitPage.h"
#include "BendPage.h"
#include "ColorsPage.h"
#include "LowRowPage.h"
#include "FadersPage.h"
#include "AxesPage.h"
#include "SpecialPage.h"

class PerSplitFrame : public wxFrame
{
public:
	PerSplitFrame(const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split);

private:
	void OnTabChanged(wxNotebookEvent& event);
	
	LinnStrument * pMyLinnStrument;
		wxNotebook * pNotebook;
		MIDISplitPage * pMIDISplitPage;
	BendPage * pBendPage;
	ColorsPage * pColorsPage;
	LowRowPage * pLowRowPage;
		FadersPage * pFadersPage;
	AxesPage * pAxesPage;
	SpecialPage * pSpecialPage;

			DECLARE_EVENT_TABLE()
};
