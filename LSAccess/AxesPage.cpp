// AxesPage.cpp

#include "AxesPage.h"

AxesPage::AxesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetPerSplitSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

	// Controls
				// toggles
	wxCheckBox * chkSEND_Y;
	// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	wxSpinCtrl * wscCC_FOR_Y;
	// Toggle:
	wxCheckBox * chkRELATIVE_Y;
	wxCheckBox * chkRELATIVE_Z;
	// Value is an LSExpressionZ
	wxSpinCtrl  * wscMIDI_EXPRESSION_FOR_Z;
	// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
	wxSpinCtrl * wscCC_FOR_Z;
	// Value is an LSExpressionY
	wxSpinCtrl  * wscEXPRESSION_FOR_Y;
	// Value is an LSLowRowBehaviour
	wxRadioBox * rdoLOWROW_X_BEHAVIOUR;
	// Value is an LSLowRowBehaviour
	wxRadioBox * rdiLOWROW_XYZ_BEHAVIOUR;
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

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


