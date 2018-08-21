// PitchBendPage.h

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
#include "LSPerSplit.h"
#include "LSEnums.h"

class BendPage : public wxPanel
{
public:
	BendPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);
	
private:
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSPerSplitSettings m_Settings;

	// controls
	// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
	wxSpinCtrl * wscSPLIT_LEFT_BEND_RANGE;
	// Toggles:
	wxCheckBox * chkSPLIT_LEFT_BEND_TOGGLE;
	wxCheckBox * chkSPLIT_LEFT_BEND_QUANTIZE_TOGGLE;
	// Values are from LSPitchQuantize
	wxRadioBox * rdobPitchBendType;
	// Toggles:
	wxCheckBox * chkSPLIT_LEFT_RESET_PITCH_ON_RELEASE;
	};
