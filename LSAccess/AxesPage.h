// AxesPage.h

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

class AxesPage : public wxPanel
{
public:
	AxesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split);

private:
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSPerSplitSettings m_Settings;

	// controls
				// toggles
	wxCheckBox * chkSEND_Y;
	// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	wxSpinCtrl * wscCC_FOR_Y;
	// Toggles:
	wxCheckBox * chkRELATIVE_Y;
	wxCheckBox * chkRELATIVE_Z;
	// Value is an LSExpressionZ
	wxRadioBox * wrbMIDI_EXPRESSION_FOR_Z;
	// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
	wxSpinCtrl * wscCC_FOR_Z;
	// Value is an LSExpressionY
	wxRadioBox * wrbEXPRESSION_FOR_Y;
	// Value is an LSLowRowBehaviour
	wxRadioBox * wrbLOWROW_X_BEHAVIOUR;
	// Value is an LSLowRowBehaviour
	wxRadioBox * wrbLOWROW_XYZ_BEHAVIOUR;
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	wxSpinCtrl * wscCC_FOR_LOWROW_XYZ;
	wxSpinCtrl * wscCC_FOR_LOWROW_XYZ_Y;
	wxSpinCtrl * wscCC_FOR_LOWROW_XYZ_Z;
	// Values are constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscMIN_CC_FOR_Y;
	wxSpinCtrl * wscMAX_CC_FOR_Y;
	wxSpinCtrl * wscMIN_CC_FOR_Z;
	wxSpinCtrl * wscMAX_CC_FOR_Z;
	wxSpinCtrl * wsc14BIT_CC_VALUE_FOR_Z;
	wxSpinCtrl * wscINITIAL_RELATIVE_VALUE_FOR_Y;
};

