// GlobalsFootSwitchesPage.cpp

#include "GlobalsFootSwitchesPage.h"

GlobalsFootSwitchesPage::GlobalsFootSwitchesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetGlobalSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

	// Controls
		/*
		// Value is LSSwitchAssignment
	wxRadioBox * wrbGLOBAL_FOOT_LEFT_ASSIGN_NRPN;
	wxRadioBox * wrbGLOBAL_FOOT_RIGHT_ASSIGN_NRPN;
	// Toggle:
	wxCheckBox * chkGLOBAL_FOOT_LEFT_BOTH_SPLITS_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_FOOT_RIGHT_BOTH_SPLITS_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
// Values are constrained by MIN_CC and MAX_CC
	WXSpinCtrl * wscGLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN;
	WXSpinCtrl * wscGLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN;
	WXSpinCtrl * wscGLOBAL_CC_FOR_LEFT_FOOT_CC65;
	WXSpinCtrl * wscGLOBAL_CC_FOR_RIGHT_FOOT_CC65;
*/
	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


