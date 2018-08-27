// FootSwitchesPage.h

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
#include "LSGlobals.h"
#include "LSEnums.h"

class FootSwitchesPage : public wxPanel
{
public:
	FootSwitchesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);

private:
	// Event handlers
	DECLARE_EVENT_TABLE()

	void OnGLOBAL_FOOT_LEFT_ASSIGN(wxCommandEvent& event);
void OnGLOBAL_FOOT_LEFT_BOTH_SPLITS(wxCommandEvent& event);
	void OnGLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN(wxSpinEvent& event);
void OnGLOBAL_CC_FOR_LEFT_FOOT_CC65(wxSpinEvent& event);
		void OnGLOBAL_FOOT_RIGHT_ASSIGN(wxCommandEvent& event);
	void OnGLOBAL_FOOT_RIGHT_BOTH_SPLITS(wxCommandEvent& event);
		void OnGLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN(wxSpinEvent& event);
		void OnGLOBAL_CC_FOR_RIGHT_FOOT_CC65(wxSpinEvent& event);

	// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSGlobalSettings m_Settings;
	
	// controls
// Value is an LSSwitchAssignment
	wxRadioBox * wrbGLOBAL_FOOT_LEFT_ASSIGN;
	// Toggle:
	wxCheckBox * chkGLOBAL_FOOT_LEFT_BOTH_SPLITS;
		// Values are constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscGLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN, *wscGLOBAL_CC_FOR_LEFT_FOOT_CC65;
	// Value is an LSSwitchAssignment
	wxRadioBox * wrbGLOBAL_FOOT_RIGHT_ASSIGN;
	// Toggle:
	wxCheckBox * chkGLOBAL_FOOT_RIGHT_BOTH_SPLITS;
		// Values are constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscGLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN, *wscGLOBAL_CC_FOR_RIGHT_FOOT_CC65;
};
