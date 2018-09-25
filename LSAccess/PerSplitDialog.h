// PerSplitDialog.h
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
#include "wx/xrc/xmlres.h"

#include "LSEnums.h"
#include "LSConsts.h"
#include "MIDIPage.h"
#include "BendPage.h"
#include "ColorsPage.h"
#include "LowRowPage.h"
#include "FadersPage.h"
#include "AxesPage.h"
#include "SpecialPage.h"

class PerSplitDialog : public wxDialog
{
public:
	PerSplitDialog() {};
	PerSplitDialog(wxWindow* parent, const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split);
	bool Create(const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split);

protected:
		wxNotebook * pNotebook;
	MIDIPage * pMIDIPage;
	BendPage * pBendPage;
	ColorsPage * pColorsPage;
	LowRowPage * pLowRowPage;
	FadersPage * pFadersPage;
	AxesPage * pAxesPage;
SpecialPage * pSpecialPage; 

private:
	void InitWidgetsFromXRC();

	// Event handlers
	void OnOK(wxCommandEvent& event);
			void OnTabChanged(wxNotebookEvent& event);
	
	// data
			LinnStrument * pMyLinnStrument;
		
			DECLARE_EVENT_TABLE()
};
