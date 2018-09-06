// GlobalsSplitPage.h

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
#include <wx/spinctrl.h>

#include "LinnStrument.h"
#include "LSEnums.h"

class GlobalsSplitPage : public wxPanel
{
public:
	GlobalsSplitPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);

private:
	// event handlers
	DECLARE_EVENT_TABLE()
		
	void OnGLOBAL_SPLIT_ACTIVE(wxCommandEvent& event);
	void OnDEVICE_LEFT_HANDED(wxCommandEvent& event);
	void OnGLOBAL_SPLIT_COLUMN(wxSpinEvent& event);

// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;

// controls
// Controls
	wxCheckBox * chkGLOBAL_SPLIT_ACTIVE;
// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
	wxSpinCtrl * wscGLOBAL_SPLIT_COLUMN;
	wxCheckBox * chkDEVICE_LEFT_HANDED;
};

