// SwitchesDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "SwitchesDialog.h"


SwitchesDialog::SwitchesDialog(wxWindow* parent, LinnStrument * pLinnStrument)
	: wxDialog(NULL, wxID_ANY, L""),
	pMyLinnStrument(pLinnStrument)
{
	if (wxXmlResource::Get()->LoadDialog(this, parent, wxT("switches_dialog")))
	{
		InitPanelSwitches();
		InitFootSwitches();
	}
else
	{
	wxMessageBox("Could not load Switche Settings dialog from XRC", wstrErrorTitle, wxOK | wxICON_ERROR);
	EndModal(false);
	}
	}


void SwitchesDialog::InitPanelSwitches()
{
	XRCCTRL(*this, "wrb_switch_1_assign", wxRadioBox)->SetSelection(pMyLinnStrument->GetSWITCH1_ASSIGN());
		XRCCTRL(*this, "chk_switch_1_both_splits", wxCheckBox)->SetValue(pMyLinnStrument->GetSWITCH1_BOTH_SPLITS());
		XRCCTRL(*this, "wsc_cc_for_switch_1_sustain", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_SWITCH1_SUSTAIN());
	XRCCTRL(*this, "wsc_cc_for_switch_1_sustain", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_switch_1_sustain", wxSpinCtrl)->SetMax(MAX_CC);
		XRCCTRL(*this, "wsc_cc_for_switch_1_cc65", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_SWITCH1_CC65());
	XRCCTRL(*this, "wsc_cc_for_switch_1_cc65", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_switch_1_cc65", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wrb_switch_2_assign", wxRadioBox)->SetSelection(pMyLinnStrument->GetSWITCH2_ASSIGN());
	XRCCTRL(*this, "chk_switch_2_both_splits", wxCheckBox)->SetValue(pMyLinnStrument->GetSWITCH2_BOTH_SPLITS());
	XRCCTRL(*this, "wsc_cc_for_switch_2_sustain", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_SWITCH2_SUSTAIN());
	XRCCTRL(*this, "wsc_cc_for_switch_2_sustain", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_switch_2_sustain", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wsc_cc_for_switch_2_cc65", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_SWITCH2_CC65());
	XRCCTRL(*this, "wsc_cc_for_switch_2_cc65", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_switch_2_cc65", wxSpinCtrl)->SetMax(MAX_CC);
}


void SwitchesDialog::InitFootSwitches()
{
	XRCCTRL(*this, "wrb_left_foot_assign", wxRadioBox)->SetSelection(pMyLinnStrument->GetFOOT_LEFT_ASSIGN());
	XRCCTRL(*this, "chk_left_foot_both_splits", wxCheckBox)->SetValue(pMyLinnStrument->GetFOOT_LEFT_BOTH_SPLITS());
	XRCCTRL(*this, "wsc_cc_for_left_foot_sustain", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_LEFT_FOOT_SUSTAIN());
	XRCCTRL(*this, "wsc_cc_for_left_foot_sustain", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_left_foot_sustain", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wsc_cc_for_left_foot_cc65", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_LEFT_FOOT_CC65());
	XRCCTRL(*this, "wsc_cc_for_left_foot_cc65", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_left_foot_cc65", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wrb_left_foot_assign", wxRadioBox)->SetSelection(pMyLinnStrument->GetFOOT_RIGHT_ASSIGN());
	XRCCTRL(*this, "chk_right_foot_both_splits", wxCheckBox)->SetValue(pMyLinnStrument->GetFOOT_RIGHT_BOTH_SPLITS());
	XRCCTRL(*this, "wsc_cc_for_right_foot_sustain", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_RIGHT_FOOT_SUSTAIN());
	XRCCTRL(*this, "wsc_cc_for_right_foot_sustain", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_right_foot_sustain", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wsc_cc_for_right_foot_cc65", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_RIGHT_FOOT_CC65());
	XRCCTRL(*this, "wsc_cc_for_right_foot_cc65", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_right_foot_cc65", wxSpinCtrl)->SetMax(MAX_CC);
}


// Event handlers

void SwitchesDialog::OnSWITCH1_ASSIGN(wxCommandEvent& event)
{
	pMyLinnStrument->SetSWITCH1_ASSIGN(XRCCTRL(*this, "wrb_switch_1_assign", wxRadioBox)->GetSelection());
	pMyLinnStrument->SendNRPN(SWITCH1_ASSIGN_NRPN, pMyLinnStrument->GetSWITCH1_ASSIGN());
}


void SwitchesDialog::OnSWITCH1_BOTH_SPLITS(wxCommandEvent& event)
{
	pMyLinnStrument->SetSWITCH1_BOTH_SPLITS(LinnStrument::LSToggle(XRCCTRL(*this, "chk_switch_1_both_splits", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(SWITCH1_BOTH_SPLITS_NRPN, pMyLinnStrument->GetSWITCH1_BOTH_SPLITS());
}


void SwitchesDialog::OnSWITCH2_ASSIGN(wxCommandEvent& event)
{
	pMyLinnStrument->SetSWITCH2_ASSIGN(XRCCTRL(*this, "wrb_switch_2_assign", wxRadioBox)->GetSelection());
	pMyLinnStrument->SendNRPN(SWITCH2_ASSIGN_NRPN, pMyLinnStrument->GetSWITCH2_ASSIGN());
}


void SwitchesDialog::OnSWITCH2_BOTH_SPLITS(wxCommandEvent& event)
{
	pMyLinnStrument->SetSWITCH2_BOTH_SPLITS(LinnStrument::LSToggle(XRCCTRL(*this, "chk_switch_1_both_splits", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(SWITCH2_BOTH_SPLITS_NRPN, pMyLinnStrument->GetSWITCH2_BOTH_SPLITS());
}


void SwitchesDialog::OnCC_FOR_SWITCH1_SUSTAIN(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_SWITCH1_SUSTAIN(XRCCTRL(*this, "wsc_cc_for_switch_1_sustain", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(CC_FOR_SWITCH1_SUSTAIN, pMyLinnStrument->GetCC_FOR_SWITCH1_SUSTAIN());
}


void SwitchesDialog::OnCC_FOR_SWITCH1_CC65(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_SWITCH1_CC65(XRCCTRL(*this, "wsc_cc_for_switch_1_cc65", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(CC_FOR_SWITCH1_CC65, pMyLinnStrument->GetCC_FOR_SWITCH1_CC65());
}


void SwitchesDialog::OnCC_FOR_SWITCH2_SUSTAIN(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_SWITCH2_SUSTAIN(XRCCTRL(*this, "wsc_cc_for_switch_2_sustain", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(CC_FOR_SWITCH2_SUSTAIN, pMyLinnStrument->GetCC_FOR_SWITCH2_SUSTAIN());
}


void SwitchesDialog::OnCC_FOR_SWITCH2_CC65(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_SWITCH2_CC65(XRCCTRL(*this, "wsc_cc_for_switch_2_cc65", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(CC_FOR_SWITCH2_CC65, pMyLinnStrument->GetCC_FOR_SWITCH2_CC65());
}


void SwitchesDialog::OnFOOT_LEFT_ASSIGN(wxCommandEvent& event)
{
	pMyLinnStrument->SetFOOT_LEFT_ASSIGN(XRCCTRL(*this, "wrb_left_foot_assign", wxRadioBox)->GetSelection());
	pMyLinnStrument->SendNRPN(FOOT_LEFT_ASSIGN_NRPN, pMyLinnStrument->GetFOOT_LEFT_ASSIGN());
}


void SwitchesDialog::OnFOOT_LEFT_BOTH_SPLITS(wxCommandEvent& event)
{
	pMyLinnStrument->SetFOOT_LEFT_BOTH_SPLITS(LinnStrument::LSToggle(XRCCTRL(*this, "chk_left_foot_both_splits", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(FOOT_LEFT_BOTH_SPLITS_NRPN, pMyLinnStrument->GetFOOT_LEFT_BOTH_SPLITS());
}


void SwitchesDialog::OnCC_FOR_LEFT_FOOT_SUSTAIN(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_LEFT_FOOT_SUSTAIN(XRCCTRL(*this, "wsc_cc_for_left_foot_sustain", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(CC_FOR_LEFT_FOOT_SUSTAIN, pMyLinnStrument->GetCC_FOR_LEFT_FOOT_SUSTAIN());
}


void SwitchesDialog::OnCC_FOR_LEFT_FOOT_CC65(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_LEFT_FOOT_CC65(XRCCTRL(*this, "wsc_cc_for_left_foot_cc65", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(CC_FOR_LEFT_FOOT_CC65, pMyLinnStrument->GetCC_FOR_LEFT_FOOT_CC65());
}


void SwitchesDialog::OnFOOT_RIGHT_ASSIGN(wxCommandEvent& event)
{
	pMyLinnStrument->SetFOOT_RIGHT_ASSIGN(XRCCTRL(*this, "wrb_right_foot_assign", wxRadioBox)->GetSelection());
	pMyLinnStrument->SendNRPN(FOOT_RIGHT_ASSIGN_NRPN, pMyLinnStrument->GetFOOT_RIGHT_ASSIGN());
}


void SwitchesDialog::OnFOOT_RIGHT_BOTH_SPLITS(wxCommandEvent& event)
{
	pMyLinnStrument->SetFOOT_RIGHT_BOTH_SPLITS(LinnStrument::LSToggle(XRCCTRL(*this, "chk_right_foot_both_splits", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(FOOT_RIGHT_BOTH_SPLITS_NRPN, pMyLinnStrument->GetFOOT_RIGHT_BOTH_SPLITS());
}


void SwitchesDialog::OnCC_FOR_RIGHT_FOOT_SUSTAIN(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_RIGHT_FOOT_SUSTAIN(XRCCTRL(*this, "wsc_cc_for_right_foot_sustain", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(CC_FOR_RIGHT_FOOT_SUSTAIN, pMyLinnStrument->GetCC_FOR_RIGHT_FOOT_SUSTAIN());
}


void SwitchesDialog::OnCC_FOR_RIGHT_FOOT_CC65(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_RIGHT_FOOT_CC65(XRCCTRL(*this, "wsc_cc_for_right_foot_cc65", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(CC_FOR_RIGHT_FOOT_CC65, pMyLinnStrument->GetCC_FOR_RIGHT_FOOT_CC65());
}


// Event table
BEGIN_EVENT_TABLE(SwitchesDialog, wxPanel)
EVT_CHECKBOX(XRCID("chk_switch_1_both_splits"), SwitchesDialog::OnSWITCH1_BOTH_SPLITS)
EVT_CHECKBOX(XRCID("chk_switch_2_both_splits"), SwitchesDialog::OnSWITCH2_BOTH_SPLITS)
EVT_SPIN(XRCID("wsc_cc_for_switch_1_sustain"), SwitchesDialog::OnCC_FOR_SWITCH1_SUSTAIN)
EVT_SPIN(XRCID("wsc_cc_for_switch_1_cc65"), SwitchesDialog::OnCC_FOR_SWITCH1_CC65)
EVT_SPIN(XRCID("wsc_cc_for_switch_1_sustain"), SwitchesDialog::OnCC_FOR_SWITCH2_SUSTAIN)
EVT_SPIN(XRCID("wsc_cc_for_switch_2_cc65"), SwitchesDialog::OnCC_FOR_SWITCH2_CC65)
EVT_RADIOBOX(XRCID("wrb_switch_1_assign"), SwitchesDialog::OnSWITCH1_ASSIGN)
EVT_RADIOBOX(XRCID("wrb_switch_1_assign"), SwitchesDialog::OnSWITCH2_ASSIGN)
EVT_RADIOBOX(XRCID("wrb_left_foot_assign"), SwitchesDialog::OnFOOT_LEFT_ASSIGN)
EVT_RADIOBOX(XRCID("wrb_right_foot_assign"), SwitchesDialog::OnFOOT_RIGHT_ASSIGN)
EVT_CHECKBOX(XRCID("chk_left_foot_both_splits"), SwitchesDialog::OnFOOT_LEFT_BOTH_SPLITS)
EVT_CHECKBOX(XRCID("chk_right_foot_both_splits"), SwitchesDialog::OnFOOT_RIGHT_BOTH_SPLITS)

EVT_SPINCTRL(XRCID("wsc_cc_for_left_foot_sustain"), SwitchesDialog::OnCC_FOR_LEFT_FOOT_SUSTAIN)
EVT_SPINCTRL(XRCID("wsc_cc_for_right_foot_sustain"), SwitchesDialog::OnCC_FOR_RIGHT_FOOT_SUSTAIN)
EVT_SPINCTRL(XRCID("wsc_cc_for_left_foot_cc65"), SwitchesDialog::OnCC_FOR_LEFT_FOOT_CC65)
EVT_SPINCTRL(XRCID("wsc_cc_for_right_foot_cc65"), SwitchesDialog::OnCC_FOR_RIGHT_FOOT_CC65)
END_EVENT_TABLE()
