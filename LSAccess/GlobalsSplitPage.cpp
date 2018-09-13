// GlobalsSplitPage.cpp

#include "stdafx.h"
#include "GlobalsSplitPage.h"

GlobalsSplitPage::GlobalsSplitPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument(pLinnStrument),
pMyParent(parent)
{
		wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	chkGLOBAL_SPLIT_ACTIVE = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_ID, L"&Split");
	chkGLOBAL_SPLIT_ACTIVE->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_SPLIT_ACTIVE()));
	hBox1->Add(chkGLOBAL_SPLIT_ACTIVE, 0, wxEXPAND);

	// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
	wxStaticText * lblGLOBAL_SPLIT_COLUMN = new wxStaticText(myPanel, wxID_ANY, L"&Split column:");
	wscGLOBAL_SPLIT_COLUMN = new wxSpinCtrl(myPanel, GLOBAL_SPLIT_COLUMN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_SPLIT_COLUMN, MAX_SPLIT_COLUMN, pMyLinnStrument->GetGLOBAL_SPLIT_COLUMN(), "Split &column");
	hBox1->Add(lblGLOBAL_SPLIT_COLUMN, 0, wxEXPAND);
	hBox1->Add(wscGLOBAL_SPLIT_COLUMN, 0, wxEXPAND);

	// toggle
	chkDEVICE_LEFT_HANDED = new wxCheckBox(myPanel, DEVICE_LEFT_HANDED_ID, L"&Left-handed");
	chkDEVICE_LEFT_HANDED->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetDEVICE_LEFT_HANDED()));
	hBox1->Add(chkDEVICE_LEFT_HANDED, 0, wxEXPAND);

	myPanel->SetSizer(hBox1);
	hBox1->SetSizeHints(this);
	myPanel->Fit();
	hBox1->Fit(myPanel);
}


// Event handlers

void GlobalsSplitPage::OnGLOBAL_SPLIT_ACTIVE(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_SPLIT_ACTIVE(LinnStrument::LSToggle(chkGLOBAL_SPLIT_ACTIVE->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_SPLIT_ACTIVE_NRPN, pMyLinnStrument->GetGLOBAL_SPLIT_ACTIVE());
}


void GlobalsSplitPage::OnDEVICE_LEFT_HANDED(wxCommandEvent& event)
{
	pMyLinnStrument->SetDEVICE_LEFT_HANDED(LinnStrument::LSToggle(chkDEVICE_LEFT_HANDED->GetValue()));
	pMyLinnStrument->SendNRPN(DEVICE_LEFT_HANDED_NRPN, pMyLinnStrument->GetDEVICE_LEFT_HANDED());
}


void GlobalsSplitPage::OnGLOBAL_SPLIT_COLUMN(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_SPLIT_COLUMN(wscGLOBAL_SPLIT_COLUMN->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_SPLIT_COLUMN_NRPN, pMyLinnStrument->GetGLOBAL_SPLIT_COLUMN());
}


/// Event table
BEGIN_EVENT_TABLE(GlobalsSplitPage, wxPanel)
EVT_CHECKBOX(GLOBAL_SPLIT_ACTIVE_ID, GlobalsSplitPage::OnGLOBAL_SPLIT_ACTIVE)
EVT_CHECKBOX(DEVICE_LEFT_HANDED_ID, GlobalsSplitPage::OnDEVICE_LEFT_HANDED)
EVT_SPINCTRL(GLOBAL_SPLIT_COLUMN_ID, GlobalsSplitPage::OnGLOBAL_SPLIT_COLUMN)
END_EVENT_TABLE()
