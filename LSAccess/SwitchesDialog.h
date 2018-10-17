// SwitchesDialog.h
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

#include "wx/xrc/xmlres.h"
#include <wx/spinctrl.h>

#include "LinnStrument.h"
#include "LSConsts.h"

class SwitchesDialog : public wxDialog
{
public:
	SwitchesDialog(wxWindow* parent, LinnStrument * pLinnStrument);

private:
	void InitPanelSwitches();
	void InitFootSwitches();
	
	// Event handlers
	DECLARE_EVENT_TABLE()

	void OnSWITCH1_ASSIGN(wxCommandEvent& event);
	void OnSWITCH2_ASSIGN(wxCommandEvent& event);
	void OnSWITCH1_BOTH_SPLITS(wxCommandEvent& event);
		void OnSWITCH2_BOTH_SPLITS(wxCommandEvent& event);
	void OnCC_FOR_SWITCH1_SUSTAIN(wxSpinEvent& event);
	void OnCC_FOR_SWITCH2_SUSTAIN(wxSpinEvent& event);
	void OnCC_FOR_SWITCH1_CC65(wxSpinEvent& event);
		void OnCC_FOR_SWITCH2_CC65(wxSpinEvent& event);
		void OnFOOT_LEFT_ASSIGN(wxCommandEvent& event);
		void OnFOOT_RIGHT_ASSIGN(wxCommandEvent& event);
		void OnFOOT_LEFT_BOTH_SPLITS(wxCommandEvent& event);
		void OnFOOT_RIGHT_BOTH_SPLITS(wxCommandEvent& event);
		void OnCC_FOR_LEFT_FOOT_SUSTAIN(wxSpinEvent& event);
		void OnCC_FOR_RIGHT_FOOT_SUSTAIN(wxSpinEvent& event);
		void OnCC_FOR_LEFT_FOOT_CC65(wxSpinEvent& event);
void OnCC_FOR_RIGHT_FOOT_CC65(wxSpinEvent& event);
	
	// data
	LinnStrument * pMyLinnStrument;
		};
