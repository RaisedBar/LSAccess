// GlobalsPanelSwitchesPage.cpp

#include "GlobalsPanelSwitchesPage.h"

GlobalsPanelSwitchesPage::GlobalsPanelSwitchesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
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
	wxRadioBox * wrbGLOBAL_SWITCH1_ASSIGN_NRPN;
	wxRadioBox * wrbGLOBAL_SWITCH2_ASSIGN_NRPN;
	// Toggle:
	wxCheckBox * chkGLOBAL_SWITCH1_BOTH_SPLITS_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_SWITCH2_BOTH_SPLITS_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	// Values are constrained by MIN_CC and MAX_CC
	WXSpinCtrl * wscGLOABAL_CC_FOR_CC65;  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
	// Values are constrained by MIN_CC and MAX_CC
	WXSpinCtrl * wscGLOBAL_CC_FOR_SWITCH1_CC65;
	WXSpinCtrl * wscGLOBAL_CC_FOR_SWITCH2_CC65;
	WXSpinCtrl * wscGLOBAL_CC_FOR_SWITCH1_SUSTAIN;
	WXSpinCtrl * wscGLOBAL_CC_FOR_SWITCH2_SUSTAIN;
	// Values are constrained by MIN_CC and MAX_CC
	*/

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


