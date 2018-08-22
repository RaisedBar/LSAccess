// LowRowPage.h

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

class LowRowPage : public wxPanel
{
public:
	LowRowPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split);

private:
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSPerSplitSettings m_Settings;

	// controls
// Value is an LSLowRowBehaviour
	wxRadioBox * wrbLOWROW_X_BEHAVIOUR;
	wxRadioBox * wrbLOWROW_XYZ_BEHAVIOUR;
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	wxSpinCtrl * wscCC_FOR_LOWROW_XYZ;
	wxSpinCtrl * wscCC_FOR_LOWROW_XYZ_Y;
	wxSpinCtrl * wscCC_FOR_LOWROW_XYZ_Z;
	// Value is an LSLowRowMode
	wxRadioBox * wrbLOWROW_MODE;
	// Value is an LSSpecial:
	wxSpinCtrl  * wscSPECIAL;
	// Value is an LSOctave
	wxRadioBox * wrbOCTAVE;
	// Values are from LSPitch
	wxRadioBox * wrbPITCH_TRANSPOSE;
	wxRadioBox * wrbTRANSPOSE_LIGHTS;
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	wxSpinCtrl * wscCC_FOR_LOWROW;
};

