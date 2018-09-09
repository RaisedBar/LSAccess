// GlobalsTuningsPage.cpp

#include "stdafx.h"
#include "GlobalsTuningsPage.h"

GlobalsTuningsPage::GlobalsTuningsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument(pLinnStrument),
pMyParent(parent)
{
		wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
	
	// Controls
		// Value is an LSRowOffsetType
		wrbGLOBAL_ROW_OFFSET = new wxRadioBox(myPanel, GLOBAL_ROW_OFFSET_ID, L"Row offset &type", wxDefaultPosition, wxDefaultSize, WXSIZEOF(RowOffsetTypes), RowOffsetTypes, LinnStrument::LSRowOffsetTypeToInt( pMyLinnStrument->GetGLOBAL_ROW_OFFSET()), wxRA_SPECIFY_ROWS);
		hBox1->Add(wrbGLOBAL_ROW_OFFSET, 0, wxEXPAND);
		// Value is an LSCustomRowOffset
	wrbGLOBAL_CUSTOM_ROW_OFFSET = new wxRadioBox(myPanel, GLOBAL_CUSTOM_ROW_OFFSET_ID, L"&Custom row offset", wxDefaultPosition, wxDefaultSize, WXSIZEOF(CustomRowOffsets), CustomRowOffsets, pMyLinnStrument->GetGLOBAL_CUSTOM_ROW_OFFSET(), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbGLOBAL_CUSTOM_ROW_OFFSET, 0, wxEXPAND);
	// Values are constrained by MIN_CC and MAX_CC
	wscGLOBAL_GUITAR_NOTE_TUNING_ROW1 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW1_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW1(), "Row &1 tuning");
	hBox1->Add(wscGLOBAL_GUITAR_NOTE_TUNING_ROW1, 0, wxEXPAND);
	wscGLOBAL_GUITAR_NOTE_TUNING_ROW2 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW2_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW2(), "Row &2 tuning");
	hBox1->Add(wscGLOBAL_GUITAR_NOTE_TUNING_ROW2, 0, wxEXPAND);
	wscGLOBAL_GUITAR_NOTE_TUNING_ROW3 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW3_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW3(), "Row &3 tuning");
	hBox1->Add(wscGLOBAL_GUITAR_NOTE_TUNING_ROW3, 0, wxEXPAND);
	wscGLOBAL_GUITAR_NOTE_TUNING_ROW4 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW4_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW4(), "Row &4 tuning");
	hBox1->Add(wscGLOBAL_GUITAR_NOTE_TUNING_ROW4, 0, wxEXPAND);
	wscGLOBAL_GUITAR_NOTE_TUNING_ROW5 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW5_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW5(), "Row &5 tuning");
	hBox1->Add(wscGLOBAL_GUITAR_NOTE_TUNING_ROW5, 0, wxEXPAND);
	wscGLOBAL_GUITAR_NOTE_TUNING_ROW6 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW6_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW6(), "Row &6 tuning");
	hBox1->Add(wscGLOBAL_GUITAR_NOTE_TUNING_ROW6, 0, wxEXPAND);
	wscGLOBAL_GUITAR_NOTE_TUNING_ROW7 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW7_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW7(), "Row &7 tuning");
	hBox1->Add(wscGLOBAL_GUITAR_NOTE_TUNING_ROW7, 0, wxEXPAND);
	wscGLOBAL_GUITAR_NOTE_TUNING_ROW8 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW8_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW8(), "Row &8 tuning");
	hBox1->Add(wscGLOBAL_GUITAR_NOTE_TUNING_ROW8, 0, wxEXPAND);

	myPanel->SetSizer(hBox1);
	hBox1->SetSizeHints(this);
	myPanel->Fit();
	hBox1->Fit(myPanel);
}


// event handlers

void GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW1(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW1(wscGLOBAL_GUITAR_NOTE_TUNING_ROW1->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW1_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW1());
}


void GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW2(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW2(wscGLOBAL_GUITAR_NOTE_TUNING_ROW2->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW2_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW2());
}


void GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW3(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW3(wscGLOBAL_GUITAR_NOTE_TUNING_ROW3->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW3_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW3());
}


void GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW4(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW4(wscGLOBAL_GUITAR_NOTE_TUNING_ROW4->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW4_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW4());
}


void GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW5(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW5(wscGLOBAL_GUITAR_NOTE_TUNING_ROW5->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW5_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW5());
}


void GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW6(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW6(wscGLOBAL_GUITAR_NOTE_TUNING_ROW6->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW6_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW6());
}


void GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW7(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW7(wscGLOBAL_GUITAR_NOTE_TUNING_ROW7->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW7_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW7());
}


void GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW8(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW8(wscGLOBAL_GUITAR_NOTE_TUNING_ROW8->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW8_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW8());
}


void GlobalsTuningsPage::OnGLOBAL_ROW_OFFSET(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ROW_OFFSET(LinnStrument::IntToLSRowOffsetType( wrbGLOBAL_ROW_OFFSET->GetSelection()));
	pMyLinnStrument->SendNRPN(GLOBAL_ROW_OFFSET_NRPN, pMyLinnStrument->GetGLOBAL_ROW_OFFSET());
}


void GlobalsTuningsPage::OnGLOBAL_CUSTOM_ROW_OFFSET(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_CUSTOM_ROW_OFFSET(wrbGLOBAL_CUSTOM_ROW_OFFSET->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_CUSTOM_ROW_OFFSET_ID, pMyLinnStrument->GetGLOBAL_CUSTOM_ROW_OFFSET());
}


// Event table
BEGIN_EVENT_TABLE(GlobalsTuningsPage, wxPanel)
EVT_SPINCTRL(GLOBAL_GUITAR_NOTE_TUNING_ROW1_ID, GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW1)
EVT_SPINCTRL(GLOBAL_GUITAR_NOTE_TUNING_ROW2_ID, GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW2)
EVT_SPINCTRL(GLOBAL_GUITAR_NOTE_TUNING_ROW3_ID, GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW3)
EVT_SPINCTRL(GLOBAL_GUITAR_NOTE_TUNING_ROW4_ID, GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW4)
EVT_SPINCTRL(GLOBAL_GUITAR_NOTE_TUNING_ROW5_ID, GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW5)
EVT_SPINCTRL(GLOBAL_GUITAR_NOTE_TUNING_ROW6_ID, GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW6)
EVT_SPINCTRL(GLOBAL_GUITAR_NOTE_TUNING_ROW7_ID, GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW7)
EVT_SPINCTRL(GLOBAL_GUITAR_NOTE_TUNING_ROW8_ID, GlobalsTuningsPage::OnGLOBAL_GUITAR_NOTE_TUNING_ROW8)

EVT_RADIOBOX(GLOBAL_ROW_OFFSET_ID, GlobalsTuningsPage::OnGLOBAL_ROW_OFFSET)
EVT_RADIOBOX(GLOBAL_CUSTOM_ROW_OFFSET_ID, GlobalsTuningsPage::OnGLOBAL_CUSTOM_ROW_OFFSET)
	END_EVENT_TABLE()
