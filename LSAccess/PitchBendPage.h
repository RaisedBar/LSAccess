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

class PitchBendPage : public wxPanel
{
public:
	PitchBendPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);
	// void SetPitchBendPage(CurrentPatchPage * pPage);

private:
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSPerSplitSettings m_Settings;

	// controls
	// Value is from LSBendRange
	wxSpinCtrl * wscSPLIT_LEFT_BEND_RANGE_NRPN;
	// Toggles:
	wxCheckBox * chkSPLIT_LEFT_BEND_TOGGLE_NRPN;
	wxCheckBox * chkSPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN;
	// Value is from LSPitchQuantize
	wxRadioButton * rdoSPLIT_LEFT_PITCH_QUANTIZE_NRPN;
	// Toggles:
	wxCheckBox * chkSPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN;
	};
