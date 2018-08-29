// PanelSwitchesPage.h

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

class PanelSwitchesPage : public wxPanel
{
public:
	PanelSwitchesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);

private:
	// event handlers
	DECLARE_EVENT_TABLE()

	void OnGLOBAL_SWITCH1_ASSIGN(wxCommandEvent& event);
	void OnGLOBAL_SWITCH1_BOTH_SPLITS(wxCommandEvent& event);
	void OnGLOBAL_SWITCH2_ASSIGN(wxCommandEvent& event);
	void OnGLOBAL_SWITCH2_BOTH_SPLITS(wxCommandEvent& event);
void OnGLOBAL_CC_FOR_SWITCH1_SUSTAIN(wxSpinEvent& event);
	void OnGLOBAL_CC_FOR_SWITCH1_CC65(wxSpinEvent& event);
	void OnGLOBAL_CC_FOR_SWITCH2_SUSTAIN(wxSpinEvent& event);
	void OnGLOBAL_CC_FOR_SWITCH2_CC65(wxSpinEvent& event);
	
	// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSGlobalSettings m_Settings;

	// controls
	// Value is an LSSwitchAssignment
	wxRadioBox * wrbGLOBAL_SWITCH1_ASSIGN;
	// Toggle:
	wxCheckBox * chkGLOBAL_SWITCH1_BOTH_SPLITS;
	// Values are constrained by MIN_CC and MAX_CC
	// WXSpinCtrl * wscGLOABAL_CC_FOR_CC65;  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
	wxSpinCtrl * wscGLOBAL_CC_FOR_SWITCH1_SUSTAIN;
	wxSpinCtrl * wscGLOBAL_CC_FOR_SWITCH1_CC65;
	// Value is an LSSwitchAssignment
	wxRadioBox * wrbGLOBAL_SWITCH2_ASSIGN;
	// Toggle:
	wxCheckBox * chkGLOBAL_SWITCH2_BOTH_SPLITS;
	// Values are constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscGLOBAL_CC_FOR_SWITCH2_SUSTAIN;
	wxSpinCtrl * wscGLOBAL_CC_FOR_SWITCH2_CC65;
	};
