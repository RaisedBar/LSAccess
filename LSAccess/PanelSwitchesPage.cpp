// PanelSwitchesPage.cpp

#include "PanelSwitchesPage.h"

PanelSwitchesPage::PanelSwitchesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument( pLinnStrument),
pMyParent(parent)
{
			wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * vBox1 = new wxBoxSizer(wxVERTICAL);
		wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer * hBox2 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
		// Value is an LSSwitchAssignment
	wrbSWITCH1_ASSIGN = new wxRadioBox(myPanel, SWITCH1_ASSIGN_ID, L"Switch &1 assignment", wxDefaultPosition, wxDefaultSize, WXSIZEOF(wstrSwitchAssignments), wstrSwitchAssignments, pMyLinnStrument->GetSWITCH1_ASSIGN(), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbSWITCH1_ASSIGN, 0, wxEXPAND);
	// Toggle:
chkSWITCH1_BOTH_SPLITS = new wxCheckBox(myPanel, SWITCH1_BOTH_SPLITS_ID, L"Switch 1 affects both splits");
	chkSWITCH1_BOTH_SPLITS->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetSWITCH1_BOTH_SPLITS()));
	hBox1->Add(chkSWITCH1_BOTH_SPLITS, 0, wxEXPAND);
	// Values are constrained by MIN_CC and MAX_CC
	// WXSpinCtrl * wscGLOABAL_CC_FOR_CC65;  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
		wscCC_FOR_SWITCH1_SUSTAIN = new wxSpinCtrl(myPanel, CC_FOR_SWITCH1_SUSTAIN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetCC_FOR_SWITCH1_SUSTAIN(), "CC for switch  1 sustain");
		hBox1->Add(wscCC_FOR_SWITCH1_SUSTAIN, 0, wxEXPAND);
		wscCC_FOR_SWITCH1_CC65 = new wxSpinCtrl(myPanel, CC_FOR_SWITCH1_CC65_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetCC_FOR_SWITCH1_CC65(), "CC for switch  1 CC65");
		hBox1->Add(wscCC_FOR_SWITCH1_CC65, 0, wxEXPAND);
		
		// Value is an LSSwitchAssignment
			wrbSWITCH2_ASSIGN = new wxRadioBox(myPanel, SWITCH2_ASSIGN_ID, L"Switch &2 assignment", wxDefaultPosition, wxDefaultSize, WXSIZEOF(wstrSwitchAssignments), wstrSwitchAssignments, pMyLinnStrument->GetSWITCH2_ASSIGN(), wxRA_SPECIFY_ROWS);
			hBox2->Add(wrbSWITCH2_ASSIGN, 0, wxEXPAND);
			// Toggle:
chkSWITCH2_BOTH_SPLITS = new wxCheckBox(myPanel, SWITCH2_BOTH_SPLITS_ID, L"Switch 2 affects both splits");
	chkSWITCH2_BOTH_SPLITS->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetSWITCH2_BOTH_SPLITS()));
	hBox2->Add(chkSWITCH2_BOTH_SPLITS, 0, wxEXPAND);
	// Values are constrained by MIN_CC and MAX_CC
	wscCC_FOR_SWITCH2_SUSTAIN = new wxSpinCtrl(myPanel, CC_FOR_SWITCH2_SUSTAIN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetCC_FOR_SWITCH2_SUSTAIN(), "CC for switch  2 sustain");
	hBox2->Add(wscCC_FOR_SWITCH2_SUSTAIN, 0, wxEXPAND);
	wscCC_FOR_SWITCH2_CC65 = new wxSpinCtrl(myPanel, CC_FOR_SWITCH2_CC65_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetCC_FOR_SWITCH2_CC65(), "CC for switch  2 CC65");
	hBox2->Add(wscCC_FOR_SWITCH2_CC65, 0, wxEXPAND);

vBox1->Add(hBox1, 0, wxEXPAND);
vBox1->Add(hBox2, 0, wxEXPAND);

	myPanel->SetSizer(vBox1);
	vBox1->SetSizeHints(this);
	myPanel->Fit();
	vBox1->Fit(myPanel);
}


// event handlers

void PanelSwitchesPage::OnSWITCH1_ASSIGN(wxCommandEvent& event)
{
	pMyLinnStrument->SetSWITCH1_ASSIGN(wrbSWITCH1_ASSIGN->GetSelection());
}


void PanelSwitchesPage::OnSWITCH1_BOTH_SPLITS(wxCommandEvent& event)
{
	pMyLinnStrument->SetSWITCH1_BOTH_SPLITS(LinnStrument::LSToggle( chkSWITCH1_BOTH_SPLITS->GetValue()));
}


void PanelSwitchesPage::OnSWITCH2_ASSIGN(wxCommandEvent& event)
{
	pMyLinnStrument->SetSWITCH2_ASSIGN(wrbSWITCH2_ASSIGN->GetSelection());
}


void PanelSwitchesPage::OnSWITCH2_BOTH_SPLITS(wxCommandEvent& event)
{
	pMyLinnStrument->SetSWITCH2_BOTH_SPLITS(LinnStrument::LSToggle(chkSWITCH2_BOTH_SPLITS->GetValue()));
}


void PanelSwitchesPage::OnCC_FOR_SWITCH1_SUSTAIN(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_SWITCH1_SUSTAIN(wscCC_FOR_SWITCH1_SUSTAIN->GetValue());
}


void PanelSwitchesPage::OnCC_FOR_SWITCH1_CC65(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_SWITCH1_CC65( wscCC_FOR_SWITCH1_CC65->GetValue());
}


void PanelSwitchesPage::OnCC_FOR_SWITCH2_SUSTAIN(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_SWITCH2_SUSTAIN(wscCC_FOR_SWITCH2_SUSTAIN->GetValue());
}


void PanelSwitchesPage::OnCC_FOR_SWITCH2_CC65(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_SWITCH2_CC65(wscCC_FOR_SWITCH2_CC65->GetValue());
}


// Event table
BEGIN_EVENT_TABLE(PanelSwitchesPage, wxPanel)
EVT_CHECKBOX(SWITCH1_BOTH_SPLITS_ID, PanelSwitchesPage::OnSWITCH1_BOTH_SPLITS)
EVT_CHECKBOX(SWITCH2_BOTH_SPLITS_ID, PanelSwitchesPage::OnSWITCH2_BOTH_SPLITS)

EVT_SPIN(CC_FOR_SWITCH1_SUSTAIN_ID, PanelSwitchesPage::OnCC_FOR_SWITCH1_SUSTAIN)
EVT_SPIN(CC_FOR_SWITCH1_CC65_ID, PanelSwitchesPage::OnCC_FOR_SWITCH1_CC65)
EVT_SPIN(CC_FOR_SWITCH2_SUSTAIN_ID, PanelSwitchesPage::OnCC_FOR_SWITCH2_SUSTAIN)
EVT_SPIN(CC_FOR_SWITCH2_CC65_ID, PanelSwitchesPage::OnCC_FOR_SWITCH2_CC65)

	EVT_RADIOBOX(SWITCH1_ASSIGN_ID, PanelSwitchesPage::OnSWITCH1_ASSIGN)
EVT_RADIOBOX(SWITCH2_ASSIGN_ID, PanelSwitchesPage::OnSWITCH2_ASSIGN)
END_EVENT_TABLE()
