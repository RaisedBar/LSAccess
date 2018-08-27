// FootSwitchesPage.cpp

#include "FootSwitchesPage.h"

FootSwitchesPage::FootSwitchesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
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
	wrbGLOBAL_FOOT_LEFT_ASSIGN = new wxRadioBox(myPanel, GLOBAL_FOOT_LEFT_ASSIGN_ID, L"&Left switch assignment", wxDefaultPosition, wxDefaultSize, WXSIZEOF(wstrSwitchAssignments), wstrSwitchAssignments, m_Settings.GetGLOBAL_FOOT_LEFT_ASSIGN(), wxRA_SPECIFY_ROWS);
	// Toggle:
chkGLOBAL_FOOT_LEFT_BOTH_SPLITS = new wxCheckBox(myPanel, GLOBAL_FOOT_LEFT_BOTH_SPLITS_ID, L"Left switch affects both splits");
	chkGLOBAL_FOOT_LEFT_BOTH_SPLITS->SetValue(m_Settings.GetGLOBAL_FOOT_LEFT_BOTH_SPLITS());
	// Values are constrained by MIN_CC and MAX_CC
	wscGLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN(), "CC for left switch  sustain");
	wscGLOBAL_CC_FOR_LEFT_FOOT_CC65 = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_LEFT_FOOT_CC65_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_LEFT_FOOT_CC65(), "CC for left switch 65");
		// Value is an LSSwitchAssignment
		wrbGLOBAL_FOOT_RIGHT_ASSIGN = new wxRadioBox(myPanel, GLOBAL_FOOT_RIGHT_ASSIGN_ID, L"&Right switch assignment", wxDefaultPosition, wxDefaultSize, WXSIZEOF(wstrSwitchAssignments), wstrSwitchAssignments, m_Settings.GetGLOBAL_FOOT_RIGHT_ASSIGN(), wxRA_SPECIFY_ROWS);
// Toggle:
	chkGLOBAL_FOOT_RIGHT_BOTH_SPLITS = new wxCheckBox(myPanel, GLOBAL_FOOT_RIGHT_BOTH_SPLITS_ID, L"Right switch affects both splits");
	chkGLOBAL_FOOT_RIGHT_BOTH_SPLITS->SetValue(m_Settings.GetGLOBAL_FOOT_RIGHT_BOTH_SPLITS());
	// Values are constrained by MIN_CC and MAX_CC
	wscGLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN(), "CC for right switch sustain");
	wscGLOBAL_CC_FOR_RIGHT_FOOT_CC65 = new wxSpinCtrl(myPanel, GLOBAL_CC_FOR_RIGHT_FOOT_CC65_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_CC_FOR_RIGHT_FOOT_CC65(), "CC for right switch 65");
	
	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


void FootSwitchesPage::OnGLOBAL_FOOT_LEFT_ASSIGN(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_FOOT_LEFT_ASSIGN(wrbGLOBAL_FOOT_LEFT_ASSIGN->GetSelection());
}


void FootSwitchesPage::OnGLOBAL_FOOT_LEFT_BOTH_SPLITS(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_FOOT_LEFT_BOTH_SPLITS(chkGLOBAL_FOOT_LEFT_BOTH_SPLITS->GetValue());
}


void FootSwitchesPage::OnGLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN(wxSpinEvent& event)
{	
	m_Settings.SetGLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN(wscGLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN->GetValue());
}


void FootSwitchesPage::OnGLOBAL_CC_FOR_LEFT_FOOT_CC65(wxSpinEvent& event)
{
	m_Settings.SetGLOBAL_CC_FOR_LEFT_FOOT_CC65(wscGLOBAL_CC_FOR_LEFT_FOOT_CC65->GetValue());
}


void FootSwitchesPage::OnGLOBAL_FOOT_RIGHT_ASSIGN(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_FOOT_RIGHT_ASSIGN(wrbGLOBAL_FOOT_RIGHT_ASSIGN->GetSelection());
}


void FootSwitchesPage::OnGLOBAL_FOOT_RIGHT_BOTH_SPLITS(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_FOOT_RIGHT_BOTH_SPLITS(chkGLOBAL_FOOT_RIGHT_BOTH_SPLITS->GetValue());
}


void FootSwitchesPage::OnGLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN(wxSpinEvent& event)
{
	m_Settings.SetGLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN(wscGLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN->GetValue());
}


void FootSwitchesPage::OnGLOBAL_CC_FOR_RIGHT_FOOT_CC65(wxSpinEvent& event)
{
	m_Settings.SetGLOBAL_CC_FOR_RIGHT_FOOT_CC65(wscGLOBAL_CC_FOR_RIGHT_FOOT_CC65->GetValue());
}


// Event table
BEGIN_EVENT_TABLE(FootSwitchesPage, wxPanel)
EVT_RADIOBOX(GLOBAL_FOOT_LEFT_ASSIGN_ID, FootSwitchesPage::OnGLOBAL_FOOT_LEFT_ASSIGN)
EVT_RADIOBOX(GLOBAL_FOOT_RIGHT_ASSIGN_ID, FootSwitchesPage::OnGLOBAL_FOOT_RIGHT_ASSIGN)

EVT_CHECKBOX(GLOBAL_FOOT_LEFT_BOTH_SPLITS_ID, FootSwitchesPage::OnGLOBAL_FOOT_LEFT_BOTH_SPLITS)
EVT_CHECKBOX(GLOBAL_FOOT_RIGHT_BOTH_SPLITS_ID, FootSwitchesPage::OnGLOBAL_FOOT_RIGHT_BOTH_SPLITS)

EVT_SPINCTRL(GLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN_ID, FootSwitchesPage::OnGLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN)
EVT_SPINCTRL(GLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN_ID, FootSwitchesPage::OnGLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN)
EVT_SPINCTRL(GLOBAL_CC_FOR_LEFT_FOOT_CC65_ID, FootSwitchesPage::OnGLOBAL_CC_FOR_LEFT_FOOT_CC65)
EVT_SPINCTRL(GLOBAL_CC_FOR_RIGHT_FOOT_CC65_ID, FootSwitchesPage::OnGLOBAL_CC_FOR_RIGHT_FOOT_CC65)
END_EVENT_TABLE()
