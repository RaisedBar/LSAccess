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
		// Value is an LSSwitchAssignment
	wxRadioBox * wrbGLOBAL_FOOT_LEFT_ASSIGN_NRPN = new wxRadioBox(myPanel, GLOBAL_FOOT_LEFT_ASSIGN_NRPN_ID, L"&Left switch assignment", wxDefaultPosition, wxDefaultSize, WXSIZEOF(wstrSwitchAssignments), wstrSwitchAssignments, m_Settings.GetGLOBAL_FOOT_LEFT_ASSIGN_NRPN(), wxRA_SPECIFY_ROWS);
	// Toggle:
	wxCheckBox * chkGLOBAL_FOOT_LEFT_BOTH_SPLITS_NRPN = new wxCheckBox(myPanel, GLOBAL_FOOT_LEFT_BOTH_SPLITS_NRPN_ID, L"Left switch affects both splits");
	// Values are constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscGLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN(), "CC for left switch  sustain");
	wxSpinCtrl * wscGLOBAL_CC_FOR_LEFT_FOOT_CC65 = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_LEFT_FOOT_CC65_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_LEFT_FOOT_CC65(), "CC for left switch 65");

	// Value is an LSSwitchAssignment
		wxRadioBox * wrbGLOBAL_FOOT_RIGHT_ASSIGN_NRPN = new wxRadioBox(myPanel, GLOBAL_FOOT_RIGHT_ASSIGN_NRPN_ID, L"&Right switch assignment", wxDefaultPosition, wxDefaultSize, WXSIZEOF(wstrSwitchAssignments), wstrSwitchAssignments, m_Settings.GetGLOBAL_FOOT_RIGHT_ASSIGN_NRPN(), wxRA_SPECIFY_ROWS);
// Toggle:
	wxCheckBox * chkGLOBAL_FOOT_RIGHT_BOTH_SPLITS_NRPN = new wxCheckBox(myPanel, GLOBAL_FOOT_RIGHT_BOTH_SPLITS_NRPN_ID, L"Right switch affects both splits");
	// Values are constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscGLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN(), "CC for right switch sustain");
	wxSpinCtrl * wscGLOBAL_CC_FOR_RIGHT_FOOT_CC65 = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_RIGHT_FOOT_CC65_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_RIGHT_FOOT_CC65(), "CC for right switch 65");
	
	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


