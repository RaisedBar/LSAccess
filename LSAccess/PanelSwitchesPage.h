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
#include "LSEnums.h"

class PanelSwitchesPage : public wxPanel
{
public:
	PanelSwitchesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);

private:
	// event handlers
	DECLARE_EVENT_TABLE()

	void OnSWITCH1_ASSIGN(wxCommandEvent& event);
	void OnSWITCH1_BOTH_SPLITS(wxCommandEvent& event);
	void OnSWITCH2_ASSIGN(wxCommandEvent& event);
	void OnSWITCH2_BOTH_SPLITS(wxCommandEvent& event);
void OnCC_FOR_SWITCH1_SUSTAIN(wxSpinEvent& event);
	void OnCC_FOR_SWITCH1_CC65(wxSpinEvent& event);
	void OnCC_FOR_SWITCH2_SUSTAIN(wxSpinEvent& event);
	void OnCC_FOR_SWITCH2_CC65(wxSpinEvent& event);
	
	// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	
	// controls
	// Value is an LSSwitchAssignment
	wxRadioBox * wrbSWITCH1_ASSIGN;
	// Toggle:
	wxCheckBox * chkSWITCH1_BOTH_SPLITS;
	// Values are constrained by MIN_CC and MAX_CC
	// WXSpinCtrl * wscGLOABAL_CC_FOR_CC65;  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
	wxSpinCtrl * wscCC_FOR_SWITCH1_SUSTAIN;
	wxSpinCtrl * wscCC_FOR_SWITCH1_CC65;
	// Value is an LSSwitchAssignment
	wxRadioBox * wrbSWITCH2_ASSIGN;
	// Toggle:
	wxCheckBox * chkSWITCH2_BOTH_SPLITS;
	// Values are constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscCC_FOR_SWITCH2_SUSTAIN;
	wxSpinCtrl * wscCC_FOR_SWITCH2_CC65;
	};
