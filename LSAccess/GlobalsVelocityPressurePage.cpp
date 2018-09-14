// GlobalsVelocityPressurePage.cpp

#include "stdafx.h"
#include "GlobalsVelocityPressurePage.h"

GlobalsVelocityPressurePage::GlobalsVelocityPressurePage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument(pLinnStrument),
pMyParent(parent)
{
		wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
				// Value is an LSVelocityRange
	wxStaticText * lblGLOBAL_VELOCITY_SENSITIVITY = new wxStaticText(myPanel, wxID_ANY, L"&Velocity sensitivity:");
	wrbGLOBAL_VELOCITY_SENSITIVITY = new wxRadioBox(myPanel, GLOBAL_VELOCITY_SENSITIVITY_ID, L"&Velocity sensitivity", wxDefaultPosition, wxDefaultSize, WXSIZEOF(VelocityRanges), VelocityRanges, pMyLinnStrument->GetGLOBAL_VELOCITY_SENSITIVITY(), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbGLOBAL_VELOCITY_SENSITIVITY, 0, wxEXPAND);

	// Values are constrained by MIN_CC and MAX_CC
	wxStaticText * lblGLOBAL_MIN_VELOCITY_VALUE = new wxStaticText(myPanel, wxID_ANY, L"Min. velocity:");
	wscGLOBAL_MIN_VELOCITY_VALUE = new wxSpinCtrl(myPanel, GLOBAL_MIN_VELOCITY_VALUE_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetGLOBAL_MIN_VELOCITY_VALUE(), L"Min. velocity");
	hBox1->Add(wscGLOBAL_MIN_VELOCITY_VALUE, 0, wxEXPAND);

	wxStaticText * lblGLOBAL_MAX_VELOCITY_VALUE = new wxStaticText(myPanel, wxID_ANY, L"Max. velocity:");
	wscGLOBAL_MAX_VELOCITY_VALUE = new wxSpinCtrl(myPanel, GLOBAL_MAX_VELOCITY_VALUE_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetGLOBAL_MAX_VELOCITY_VALUE(), L"Max. velocity");
	hBox1->Add(wscGLOBAL_MAX_VELOCITY_VALUE, 0, wxEXPAND);

	wxStaticText * lblGLOBAL_FIXED_VELOCITY_VALUE = new wxStaticText(myPanel, wxID_ANY, L"&Fixed velocity:");
	wscGLOBAL_FIXED_VELOCITY_VALUE = new wxSpinCtrl(myPanel, GLOBAL_FIXED_VELOCITY_VALUE_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetGLOBAL_FIXED_VELOCITY_VALUE(), L"&Tempo");
	hBox1->Add(wscGLOBAL_FIXED_VELOCITY_VALUE, 0, wxEXPAND);

		// Value is an LSPressureRange
	wxStaticText * lblGLOBAL_PRESSURE_SENSITIVITY = new wxStaticText(myPanel, wxID_ANY, L"&Pressure sensitivity:");
	wrbGLOBAL_PRESSURE_SENSITIVITY = new wxRadioBox(myPanel, GLOBAL_PRESSURE_SENSITIVITY_ID, L"&Pressure sensitivity", wxDefaultPosition, wxDefaultSize, WXSIZEOF(PressureRanges), PressureRanges, pMyLinnStrument->GetGLOBAL_PRESSURE_SENSITIVITY(), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbGLOBAL_PRESSURE_SENSITIVITY, 0, wxEXPAND);

	// Toggle
	chkGLOBAL_PRESSURE_AFTERTOUCH = new wxCheckBox(myPanel, GLOBAL_PRESSURE_AFTERTOUCH_ID, L"Pressure &aftertouch");
	chkGLOBAL_PRESSURE_AFTERTOUCH->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_PRESSURE_AFTERTOUCH()));
	hBox1->Add(chkGLOBAL_PRESSURE_AFTERTOUCH, 0, wxEXPAND);

	myPanel->SetSizerAndFit(hBox1);
	}


// Event handlers

void GlobalsVelocityPressurePage::OnGLOBAL_VELOCITY_SENSITIVITY(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_VELOCITY_SENSITIVITY(wrbGLOBAL_VELOCITY_SENSITIVITY->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_VELOCITY_SENSITIVITY_NRPN, pMyLinnStrument->GetGLOBAL_VELOCITY_SENSITIVITY());
}


void GlobalsVelocityPressurePage::OnGLOBAL_PRESSURE_AFTERTOUCH(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_PRESSURE_AFTERTOUCH(LinnStrument::LSToggle(chkGLOBAL_PRESSURE_AFTERTOUCH->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_PRESSURE_AFTERTOUCH_NRPN, pMyLinnStrument->GetGLOBAL_PRESSURE_AFTERTOUCH());
}


void GlobalsVelocityPressurePage::OnGLOBAL_PRESSURE_SENSITIVITY(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_PRESSURE_SENSITIVITY(wrbGLOBAL_PRESSURE_SENSITIVITY->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_PRESSURE_SENSITIVITY_NRPN, pMyLinnStrument->GetGLOBAL_PRESSURE_SENSITIVITY());
}


void GlobalsVelocityPressurePage::OnGLOBAL_FIXED_VELOCITY_VALUE(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_FIXED_VELOCITY_VALUE(wscGLOBAL_FIXED_VELOCITY_VALUE->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_FIXED_VELOCITY_VALUE_NRPN, pMyLinnStrument->GetGLOBAL_FIXED_VELOCITY_VALUE());
}


void GlobalsVelocityPressurePage::OnGLOBAL_MAX_VELOCITY_VALUE(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAX_VELOCITY_VALUE(wscGLOBAL_MAX_VELOCITY_VALUE->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_MAX_VELOCITY_VALUE_NRPN, pMyLinnStrument->GetGLOBAL_MAX_VELOCITY_VALUE());
}


void GlobalsVelocityPressurePage::OnGLOBAL_MIN_VELOCITY_VALUE(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MIN_VELOCITY_VALUE(wscGLOBAL_MIN_VELOCITY_VALUE->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_MIN_VELOCITY_VALUE_NRPN, pMyLinnStrument->GetGLOBAL_MIN_VELOCITY_VALUE());
}


// Event table
BEGIN_EVENT_TABLE(GlobalsVelocityPressurePage, wxPanel)
EVT_SPINCTRL(GLOBAL_MIN_VELOCITY_VALUE_ID, GlobalsVelocityPressurePage::OnGLOBAL_MIN_VELOCITY_VALUE)
EVT_SPINCTRL(GLOBAL_MAX_VELOCITY_VALUE_ID, GlobalsVelocityPressurePage::OnGLOBAL_MAX_VELOCITY_VALUE)
EVT_SPINCTRL(GLOBAL_FIXED_VELOCITY_VALUE_ID, GlobalsVelocityPressurePage::OnGLOBAL_FIXED_VELOCITY_VALUE)

EVT_RADIOBOX(GLOBAL_VELOCITY_SENSITIVITY_ID, GlobalsVelocityPressurePage::OnGLOBAL_PRESSURE_SENSITIVITY)
EVT_RADIOBOX(GLOBAL_PRESSURE_SENSITIVITY_ID, GlobalsVelocityPressurePage::OnGLOBAL_PRESSURE_SENSITIVITY)

EVT_CHECKBOX(GLOBAL_PRESSURE_AFTERTOUCH_ID, GlobalsVelocityPressurePage::OnGLOBAL_PRESSURE_AFTERTOUCH)
END_EVENT_TABLE()
