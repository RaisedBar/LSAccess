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
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSGlobalSettings m_Settings;

	// controls
	// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
	wxSpinCtrl * wscBEND_RANGE;
	// Toggles:
	wxCheckBox * chkBEND_TOGGLE;
	wxCheckBox * chkBEND_QUANTIZE_TOGGLE;
	// Values are from LSPitchQuantize
	wxRadioBox * wrbcPitchBendType;
	// Toggles:
	wxCheckBox * chkRESET_PITCH_ON_RELEASE;
};
