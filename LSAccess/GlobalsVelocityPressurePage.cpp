// GlobalsVelocityPressurePage.cpp

#include "GlobalsVelocityPressurePage.h"

GlobalsVelocityPressurePage::GlobalsVelocityPressurePage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
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
				// Value is an LSVelocityRange
	wxRadioBox * wrbGLOBAL_VELOCITY_SENSITIVITY = new wxRadioBox(myPanel, GLOBAL_VELOCITY_SENSITIVITY_ID, L"&Velocity sensitivity", wxDefaultPosition, wxDefaultSize, WXSIZEOF(VelocityRanges), VelocityRanges, m_Settings.GetGLOBAL_VELOCITY_SENSITIVITY(), wxRA_SPECIFY_ROWS);
	// Values are constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscGLOBAL_MIN_VELOCITY_VALUE = new wxSpinCtrl(myPanel, GLOBAL_MIN_VELOCITY_VALUE_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_MIN_VELOCITY_VALUE(), L"Min. velocity");
	wxSpinCtrl * wscGLOBAL_MAX_VELOCITY_VALUE = new wxSpinCtrl(myPanel, GLOBAL_MAX_VELOCITY_VALUE_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_MAX_VELOCITY_VALUE(), L"Max. velocity");
	wxSpinCtrl * wscGLOBAL_FIXED_VELOCITY_VALUE = new wxSpinCtrl(myPanel, GLOBAL_FIXED_VELOCITY_VALUE_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_FIXED_VELOCITY_VALUE(), L"&Tempo");
	// Value is an LSPressureRange
	wxRadioBox * wrbGLOBAL_PRESSURE_SENSITIVITY = new wxRadioBox(myPanel, GLOBAL_PRESSURE_SENSITIVITY_ID, L"&Pressure sensitivity", wxDefaultPosition, wxDefaultSize, WXSIZEOF(PressureRanges), PressureRanges, m_Settings.GetGLOBAL_PRESSURE_SENSITIVITY(), wxRA_SPECIFY_ROWS);
	// Toggle
	wxCheckBox * chkGLOBAL_PRESSURE_AFTERTOUCH = new wxCheckBox(myPanel, GLOBAL_PRESSURE_AFTERTOUCH_ID, L"Pressure &aftertouch");

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


