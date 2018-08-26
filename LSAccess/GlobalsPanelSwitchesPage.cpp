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
		// Value is an LSSwitchAssignment
	wxRadioBox * wrbGLOBAL_SWITCH1_ASSIGN = new wxRadioBox(myPanel, GLOBAL_SWITCH1_ASSIGN_ID, L"Switch &1 assignment", wxDefaultPosition, wxDefaultSize, WXSIZEOF(wstrSwitchAssignments), wstrSwitchAssignments, m_Settings.GetGLOBAL_SWITCH1_ASSIGN(), wxRA_SPECIFY_ROWS);
	// Toggle:
	wxCheckBox * chkGLOBAL_SWITCH1_BOTH_SPLITS = new wxCheckBox(myPanel, GLOBAL_SWITCH1_BOTH_SPLITS_ID, L"Switch 1 affects both splits");
	// Values are constrained by MIN_CC and MAX_CC
	// WXSpinCtrl * wscGLOABAL_CC_FOR_CC65;  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
		wxSpinCtrl * wscGLOBAL_CC_FOR_SWITCH1_SUSTAIN = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_SWITCH1_SUSTAIN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_SWITCH1_SUSTAIN(), "CC for switch  1 sustain");
		wxSpinCtrl * wscGLOBAL_CC_FOR_SWITCH1_CC65 = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_SWITCH1_CC65_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_SWITCH1_CC65(), "CC for switch  1 CC65");
			// Value is an LSSwitchAssignment
	wxRadioBox * wrbGLOBAL_SWITCH2_ASSIGN = new wxRadioBox(myPanel, GLOBAL_SWITCH2_ASSIGN_ID, L"Switch &2 assignment", wxDefaultPosition, wxDefaultSize, WXSIZEOF(wstrSwitchAssignments), wstrSwitchAssignments, m_Settings.GetGLOBAL_SWITCH2_ASSIGN(), wxRA_SPECIFY_ROWS);
	// Toggle:
	wxCheckBox * chkGLOBAL_SWITCH2_BOTH_SPLITS = new wxCheckBox(myPanel, GLOBAL_SWITCH2_BOTH_SPLITSN_ID, L"Switch 2 affects both splits");
		// Values are constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscGLOBAL_CC_FOR_SWITCH2_SUSTAIN = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_SWITCH2_SUSTAIN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_SWITCH2_SUSTAIN(), "CC for switch  2 sustain");
	wxSpinCtrl * wscGLOBAL_CC_FOR_SWITCH2_CC65 = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_SWITCH2_CC65_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_SWITCH2_CC65(), "CC for switch  2 CC65");
	
	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


