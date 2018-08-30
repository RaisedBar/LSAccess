// PanelSwitchesPage.cpp

#include "PanelSwitchesPage.h"

PanelSwitchesPage::PanelSwitchesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetGlobalSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * vBox1 = new wxBoxSizer(wxVERTICAL);
		wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer * hBox2 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
		// Value is an LSSwitchAssignment
	wrbGLOBAL_SWITCH1_ASSIGN = new wxRadioBox(myPanel, GLOBAL_SWITCH1_ASSIGN_ID, L"Switch &1 assignment", wxDefaultPosition, wxDefaultSize, WXSIZEOF(wstrSwitchAssignments), wstrSwitchAssignments, m_Settings.GetGLOBAL_SWITCH1_ASSIGN(), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbGLOBAL_SWITCH1_ASSIGN, 0, wxEXPAND);
	// Toggle:
chkGLOBAL_SWITCH1_BOTH_SPLITS = new wxCheckBox(myPanel, GLOBAL_SWITCH1_BOTH_SPLITS_ID, L"Switch 1 affects both splits");
	chkGLOBAL_SWITCH1_BOTH_SPLITS->SetValue(m_Settings.GetGLOBAL_SWITCH1_BOTH_SPLITS());
	hBox1->Add(chkGLOBAL_SWITCH1_BOTH_SPLITS, 0, wxEXPAND);
	// Values are constrained by MIN_CC and MAX_CC
	// WXSpinCtrl * wscGLOABAL_CC_FOR_CC65;  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
		wscGLOBAL_CC_FOR_SWITCH1_SUSTAIN = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_SWITCH1_SUSTAIN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_SWITCH1_SUSTAIN(), "CC for switch  1 sustain");
		hBox1->Add(wscGLOBAL_CC_FOR_SWITCH1_SUSTAIN, 0, wxEXPAND);
		wscGLOBAL_CC_FOR_SWITCH1_CC65 = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_SWITCH1_CC65_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_SWITCH1_CC65(), "CC for switch  1 CC65");
		hBox1->Add(wscGLOBAL_CC_FOR_SWITCH1_CC65, 0, wxEXPAND);
		
		// Value is an LSSwitchAssignment
			wrbGLOBAL_SWITCH2_ASSIGN = new wxRadioBox(myPanel, GLOBAL_SWITCH2_ASSIGN_ID, L"Switch &2 assignment", wxDefaultPosition, wxDefaultSize, WXSIZEOF(wstrSwitchAssignments), wstrSwitchAssignments, m_Settings.GetGLOBAL_SWITCH2_ASSIGN(), wxRA_SPECIFY_ROWS);
			hBox2->Add(wrbGLOBAL_SWITCH2_ASSIGN, 0, wxEXPAND);
			// Toggle:
chkGLOBAL_SWITCH2_BOTH_SPLITS = new wxCheckBox(myPanel, GLOBAL_SWITCH2_BOTH_SPLITS_ID, L"Switch 2 affects both splits");
	chkGLOBAL_SWITCH2_BOTH_SPLITS->SetValue(m_Settings.GetGLOBAL_SWITCH2_BOTH_SPLITS());
	hBox2->Add(chkGLOBAL_SWITCH2_BOTH_SPLITS, 0, wxEXPAND);
	// Values are constrained by MIN_CC and MAX_CC
	wscGLOBAL_CC_FOR_SWITCH2_SUSTAIN = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_SWITCH2_SUSTAIN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_SWITCH2_SUSTAIN(), "CC for switch  2 sustain");
	hBox2->Add(wscGLOBAL_CC_FOR_SWITCH2_SUSTAIN, 0, wxEXPAND);
	wscGLOBAL_CC_FOR_SWITCH2_CC65 = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_SWITCH2_CC65_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_SWITCH2_CC65(), "CC for switch  2 CC65");
	hBox2->Add(wscGLOBAL_CC_FOR_SWITCH2_CC65, 0, wxEXPAND);

vBox1->Add(hBox1, 0, wxEXPAND);
vBox1->Add(hBox2, 0, wxEXPAND);

	myPanel->SetSizer(vBox1);
	vBox1->SetSizeHints(this);
	myPanel->Fit();
	vBox1->Fit(myPanel);
}


// event handlers

void PanelSwitchesPage::OnGLOBAL_SWITCH1_ASSIGN(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_SWITCH1_ASSIGN(wrbGLOBAL_SWITCH1_ASSIGN->GetSelection());
}


void PanelSwitchesPage::OnGLOBAL_SWITCH1_BOTH_SPLITS(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_SWITCH1_BOTH_SPLITS(chkGLOBAL_SWITCH1_BOTH_SPLITS->GetValue());
}


void PanelSwitchesPage::OnGLOBAL_SWITCH2_ASSIGN(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_SWITCH2_ASSIGN(wrbGLOBAL_SWITCH2_ASSIGN->GetSelection());
}


void PanelSwitchesPage::OnGLOBAL_SWITCH2_BOTH_SPLITS(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_SWITCH2_BOTH_SPLITS(chkGLOBAL_SWITCH2_BOTH_SPLITS->GetValue());
}


void PanelSwitchesPage::OnGLOBAL_CC_FOR_SWITCH1_SUSTAIN(wxSpinEvent& event)
{
	m_Settings.SetGLOBAL_CC_FOR_SWITCH1_SUSTAIN(wscGLOBAL_CC_FOR_SWITCH1_SUSTAIN->GetValue());
}


void PanelSwitchesPage::OnGLOBAL_CC_FOR_SWITCH1_CC65(wxSpinEvent& event)
{
	m_Settings.SetGLOBAL_CC_FOR_SWITCH1_CC65( wscGLOBAL_CC_FOR_SWITCH1_CC65->GetValue());
}


void PanelSwitchesPage::OnGLOBAL_CC_FOR_SWITCH2_SUSTAIN(wxSpinEvent& event)
{
	m_Settings.SetGLOBAL_CC_FOR_SWITCH2_SUSTAIN(wscGLOBAL_CC_FOR_SWITCH2_SUSTAIN->GetValue());
}


void PanelSwitchesPage::OnGLOBAL_CC_FOR_SWITCH2_CC65(wxSpinEvent& event)
{
	m_Settings.SetGLOBAL_CC_FOR_SWITCH2_CC65(wscGLOBAL_CC_FOR_SWITCH2_CC65->GetValue());
}


// Event table
BEGIN_EVENT_TABLE(PanelSwitchesPage, wxPanel)
EVT_CHECKBOX(GLOBAL_SWITCH1_BOTH_SPLITS_ID, PanelSwitchesPage::OnGLOBAL_SWITCH1_BOTH_SPLITS)
EVT_CHECKBOX(GLOBAL_SWITCH2_BOTH_SPLITS_ID, PanelSwitchesPage::OnGLOBAL_SWITCH2_BOTH_SPLITS)

EVT_SPIN(GLOBAL_CC_FOR_SWITCH1_SUSTAIN_ID, PanelSwitchesPage::OnGLOBAL_CC_FOR_SWITCH1_SUSTAIN)
EVT_SPIN(GLOBAL_CC_FOR_SWITCH1_CC65_ID, PanelSwitchesPage::OnGLOBAL_CC_FOR_SWITCH1_CC65)
EVT_SPIN(GLOBAL_CC_FOR_SWITCH2_SUSTAIN_ID, PanelSwitchesPage::OnGLOBAL_CC_FOR_SWITCH2_SUSTAIN)
EVT_SPIN(GLOBAL_CC_FOR_SWITCH2_CC65_ID, PanelSwitchesPage::OnGLOBAL_CC_FOR_SWITCH2_CC65)

	EVT_RADIOBOX(GLOBAL_SWITCH1_ASSIGN_ID, PanelSwitchesPage::OnGLOBAL_SWITCH1_ASSIGN)
EVT_RADIOBOX(GLOBAL_SWITCH2_ASSIGN_ID, PanelSwitchesPage::OnGLOBAL_SWITCH2_ASSIGN)
END_EVENT_TABLE()
