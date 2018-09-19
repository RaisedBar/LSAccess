// FootSwitchesPage.cpp

#include "stdafx.h"
#include "FootSwitchesPage.h"

FootSwitchesPage::FootSwitchesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument(pLinnStrument),
		pMyParent(parent)
	{
				wxFlexGridSizer * gSizer = new wxFlexGridSizer(9);

	// Controls
		// Value is an LSSwitchAssignment
	wxStaticText * lblFOOT_LEFT_ASSIGN = new wxStaticText(this, wxID_ANY, L"&Left footswitch assignment:");
	wrbFOOT_LEFT_ASSIGN = new wxRadioBox(this, FOOT_LEFT_ASSIGN_ID, L"&Left footswitch assignment", wxDefaultPosition, wxDefaultSize, WXSIZEOF(wstrSwitchAssignments), wstrSwitchAssignments, pMyLinnStrument->GetFOOT_LEFT_ASSIGN(), wxRA_SPECIFY_ROWS);
	gSizer->Add(lblFOOT_LEFT_ASSIGN, 0, wxEXPAND);
	gSizer->Add(wrbFOOT_LEFT_ASSIGN, 0, wxEXPAND);
	
	// Toggle:
chkFOOT_LEFT_BOTH_SPLITS = new wxCheckBox(this, FOOT_LEFT_BOTH_SPLITS_ID, L"Left footswitch affects both splits");
	chkFOOT_LEFT_BOTH_SPLITS->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetFOOT_LEFT_BOTH_SPLITS()));
	gSizer->Add(chkFOOT_LEFT_BOTH_SPLITS, 0, wxEXPAND);

	// Values are constrained by MIN_CC and MAX_CC
	wxStaticText * lblCC_FOR_LEFT_FOOT_SUSTAIN = new wxStaticText(this, wxID_ANY, L"Left footswitch CC for sustain:");
	wscCC_FOR_LEFT_FOOT_SUSTAIN = new wxSpinCtrl(this, CC_FOR_LEFT_FOOT_SUSTAIN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetCC_FOR_LEFT_FOOT_SUSTAIN(), "CC for left switch  sustain");
	gSizer->Add( lblCC_FOR_LEFT_FOOT_SUSTAIN, 0, wxEXPAND);
	gSizer->Add(wscCC_FOR_LEFT_FOOT_SUSTAIN, 0, wxEXPAND);

	wxStaticText * lblCC_FOR_LEFT_FOOT_CC65 = new wxStaticText(this, wxID_ANY, L"Left footswitch CC for CC65:");
	wscCC_FOR_LEFT_FOOT_CC65 = new wxSpinCtrl(this, CC_FOR_LEFT_FOOT_CC65_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetCC_FOR_LEFT_FOOT_CC65(), "CC for left switch 65");
	gSizer->Add( lblCC_FOR_LEFT_FOOT_CC65, 0, wxEXPAND);
	gSizer->Add(wscCC_FOR_LEFT_FOOT_CC65, 0, wxEXPAND);

	// Value is an LSSwitchAssignment
	wxStaticText * lblFOOT_RIGHT_ASSIGN = new wxStaticText(this, wxID_ANY, L"&Right footswitch assignment:");
	wrbFOOT_RIGHT_ASSIGN = new wxRadioBox(this, FOOT_RIGHT_ASSIGN_ID, L"&Right footswitch assignment", wxDefaultPosition, wxDefaultSize, WXSIZEOF(wstrSwitchAssignments), wstrSwitchAssignments, pMyLinnStrument->GetFOOT_RIGHT_ASSIGN(), wxRA_SPECIFY_ROWS);
	gSizer->Add(lblFOOT_RIGHT_ASSIGN, 0, wxEXPAND);
	gSizer->Add(wrbFOOT_RIGHT_ASSIGN, 0, wxEXPAND);
		
		// Toggle:
	chkFOOT_RIGHT_BOTH_SPLITS = new wxCheckBox(this, FOOT_RIGHT_BOTH_SPLITS_ID, L"Right footswitch affects both splits");
	chkFOOT_RIGHT_BOTH_SPLITS->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetFOOT_RIGHT_BOTH_SPLITS()));
		gSizer->Add(chkFOOT_RIGHT_BOTH_SPLITS, 0, wxEXPAND);
	
	// Values are constrained by MIN_CC and MAX_CC
	wxStaticText * lblCC_FOR_RIGHT_FOOT_SUSTAIN = new wxStaticText(this, wxID_ANY, L"&Right footswitch CC for sustain:");
	wscCC_FOR_RIGHT_FOOT_SUSTAIN = new wxSpinCtrl(this, CC_FOR_RIGHT_FOOT_SUSTAIN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetCC_FOR_RIGHT_FOOT_SUSTAIN(), "CC for right switch sustain");
	gSizer->Add(lblCC_FOR_RIGHT_FOOT_SUSTAIN, 0, wxEXPAND);
	gSizer->Add(wscCC_FOR_RIGHT_FOOT_SUSTAIN, 0, wxEXPAND);
	
	wxStaticText * lblCC_FOR_RIGHT_FOOT_CC65 = new wxStaticText(this, wxID_ANY, L"Right footswitch CC for CC65:");
	wscCC_FOR_RIGHT_FOOT_CC65 = new wxSpinCtrl(this, CC_FOR_RIGHT_FOOT_CC65_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetCC_FOR_RIGHT_FOOT_CC65(), "CC for right switch 65");
	gSizer->Add(lblCC_FOR_RIGHT_FOOT_CC65, 0, wxEXPAND);
	gSizer->Add(wscCC_FOR_RIGHT_FOOT_CC65, 0, wxEXPAND);

	this->SetSizerAndFit(gSizer);
	}


// Event handlers

void FootSwitchesPage::OnFOOT_LEFT_ASSIGN(wxCommandEvent& event)
{
	pMyLinnStrument->SetFOOT_LEFT_ASSIGN(wrbFOOT_LEFT_ASSIGN->GetSelection());
		pMyLinnStrument->SendNRPN(FOOT_LEFT_ASSIGN_NRPN, pMyLinnStrument->GetFOOT_LEFT_ASSIGN());
}


void FootSwitchesPage::OnFOOT_LEFT_BOTH_SPLITS(wxCommandEvent& event)
{
	pMyLinnStrument->SetFOOT_LEFT_BOTH_SPLITS(LinnStrument::LSToggle(chkFOOT_LEFT_BOTH_SPLITS->GetValue()));
	pMyLinnStrument->SendNRPN(FOOT_LEFT_BOTH_SPLITS_NRPN, pMyLinnStrument->GetFOOT_LEFT_BOTH_SPLITS());
}


void FootSwitchesPage::OnCC_FOR_LEFT_FOOT_SUSTAIN(wxSpinEvent& event)
{	
	pMyLinnStrument->SetCC_FOR_LEFT_FOOT_SUSTAIN(wscCC_FOR_LEFT_FOOT_SUSTAIN->GetValue());
	pMyLinnStrument->SendNRPN(CC_FOR_LEFT_FOOT_SUSTAIN, pMyLinnStrument->GetCC_FOR_LEFT_FOOT_SUSTAIN());
}


void FootSwitchesPage::OnCC_FOR_LEFT_FOOT_CC65(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_LEFT_FOOT_CC65(wscCC_FOR_LEFT_FOOT_CC65->GetValue());
	pMyLinnStrument->SendNRPN(CC_FOR_LEFT_FOOT_CC65, pMyLinnStrument->GetCC_FOR_LEFT_FOOT_CC65());
}


void FootSwitchesPage::OnFOOT_RIGHT_ASSIGN(wxCommandEvent& event)
{
	pMyLinnStrument->SetFOOT_RIGHT_ASSIGN(wrbFOOT_RIGHT_ASSIGN->GetSelection());
	pMyLinnStrument->SendNRPN(FOOT_RIGHT_ASSIGN_NRPN, pMyLinnStrument->GetFOOT_RIGHT_ASSIGN());
}


void FootSwitchesPage::OnFOOT_RIGHT_BOTH_SPLITS(wxCommandEvent& event)
{
	pMyLinnStrument->SetFOOT_RIGHT_BOTH_SPLITS(LinnStrument::LSToggle(chkFOOT_RIGHT_BOTH_SPLITS->GetValue()));
	pMyLinnStrument->SendNRPN(FOOT_RIGHT_BOTH_SPLITS_NRPN, pMyLinnStrument->GetFOOT_RIGHT_BOTH_SPLITS());
}


void FootSwitchesPage::OnCC_FOR_RIGHT_FOOT_SUSTAIN(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_RIGHT_FOOT_SUSTAIN(wscCC_FOR_RIGHT_FOOT_SUSTAIN->GetValue());
	pMyLinnStrument->SendNRPN(CC_FOR_RIGHT_FOOT_SUSTAIN, pMyLinnStrument->GetCC_FOR_RIGHT_FOOT_SUSTAIN());
}


void FootSwitchesPage::OnCC_FOR_RIGHT_FOOT_CC65(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_RIGHT_FOOT_CC65(wscCC_FOR_RIGHT_FOOT_CC65->GetValue());
	pMyLinnStrument->SendNRPN(CC_FOR_RIGHT_FOOT_CC65, pMyLinnStrument->GetCC_FOR_RIGHT_FOOT_CC65());
}


// Event table
BEGIN_EVENT_TABLE(FootSwitchesPage, wxPanel)
EVT_RADIOBOX(FOOT_LEFT_ASSIGN_ID, FootSwitchesPage::OnFOOT_LEFT_ASSIGN)
EVT_RADIOBOX(FOOT_RIGHT_ASSIGN_ID, FootSwitchesPage::OnFOOT_RIGHT_ASSIGN)

EVT_CHECKBOX(FOOT_LEFT_BOTH_SPLITS_ID, FootSwitchesPage::OnFOOT_LEFT_BOTH_SPLITS)
EVT_CHECKBOX(FOOT_RIGHT_BOTH_SPLITS_ID, FootSwitchesPage::OnFOOT_RIGHT_BOTH_SPLITS)

EVT_SPINCTRL(CC_FOR_LEFT_FOOT_SUSTAIN_ID, FootSwitchesPage::OnCC_FOR_LEFT_FOOT_SUSTAIN)
EVT_SPINCTRL(CC_FOR_RIGHT_FOOT_SUSTAIN_ID, FootSwitchesPage::OnCC_FOR_RIGHT_FOOT_SUSTAIN)
EVT_SPINCTRL(CC_FOR_LEFT_FOOT_CC65_ID, FootSwitchesPage::OnCC_FOR_LEFT_FOOT_CC65)
EVT_SPINCTRL(CC_FOR_RIGHT_FOOT_CC65_ID, FootSwitchesPage::OnCC_FOR_RIGHT_FOOT_CC65)
END_EVENT_TABLE()
