// LowRowPage.cpp

#include "LowRowPage.h"

LowRowPage::LowRowPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl()),
	m_Split(split)
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetPerSplitSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
			// Value is an LSLowRowMode
	wrbLOWROW_MODE = new wxRadioBox(myPanel, LOWROW_MODE_ID, L"&Mode", wxDefaultPosition, wxDefaultSize, WXSIZEOF(LowRowModes), LowRowModes, m_Settings.GetLOWROW_MODE(split), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbLOWROW_MODE, 0, wxEXPAND);
	// Value is an LSLowRowBehaviour
		wrbLOWROW_X_BEHAVIOUR = new wxRadioBox(myPanel, LOWROW_X_BEHAVIOUR_ID, L"&Low row X behaviour:", wxDefaultPosition, wxDefaultSize, WXSIZEOF(LowRowBehaviour), LowRowBehaviour, m_Settings.GetLOWROW_X_BEHAVIOUR(split), wxRA_SPECIFY_ROWS);
		hBox1->Add(wrbLOWROW_X_BEHAVIOUR, 0, wxEXPAND);
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		wscCC_FOR_LOWROW = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetCC_FOR_LOWROW(split), L"CC message");
		hBox1->Add(wscCC_FOR_LOWROW, 0, wxEXPAND);
		wrbLOWROW_XYZ_BEHAVIOUR = new wxRadioBox(myPanel, LOWROW_XYZ_BEHAVIOUR_ID, L"X,Y,Z X-axis behaviour", wxDefaultPosition, wxDefaultSize, WXSIZEOF(LowRowBehaviour), LowRowBehaviour, m_Settings.GetLOWROW_XYZ_BEHAVIOUR(split), wxRA_SPECIFY_ROWS);
		hBox1->Add(wrbLOWROW_XYZ_BEHAVIOUR, 0, wxEXPAND);
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	wscCC_FOR_LOWROW_XYZ = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_XYZ_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetCC_FOR_LOWROW_XYZ(split), "CC for &Low Row X,Y,Z - X");
	hBox1->Add(wscCC_FOR_LOWROW_XYZ, 0, wxEXPAND);
	wscCC_FOR_LOWROW_XYZ_Y = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_XYZ_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetCC_FOR_LOWROW_XYZ_Y(split), "CC for X,Y,Z - Y");
	hBox1->Add(wscCC_FOR_LOWROW_XYZ_Y, 0, wxEXPAND);
	wscCC_FOR_LOWROW_XYZ_Z = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_XYZ_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetCC_FOR_LOWROW_XYZ_Z(split), "CC for X,Y,Z - Z");
	hBox1->Add(wscCC_FOR_LOWROW_XYZ_Z, 0, wxEXPAND);

	myPanel->SetSizer(hBox1);
	hBox1->SetSizeHints(this);
	myPanel->Fit();
	hBox1->Fit(myPanel);
}


// event handlers

void LowRowPage::OnCC_FOR_LOWROW(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_LOWROW(wscCC_FOR_LOWROW->GetValue(), m_Split);
}


void LowRowPage::OnCC_FOR_LOWROW_XYZ(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_LOWROW_XYZ(wscCC_FOR_LOWROW_XYZ->GetValue(), m_Split);
}


void LowRowPage::OnCC_FOR_LOWROW_XYZ_Y(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_LOWROW_XYZ_Y(wscCC_FOR_LOWROW_XYZ_Y->GetValue(), m_Split);
}


void LowRowPage::OnCC_FOR_LOWROW_XYZ_Z(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_LOWROW_XYZ_Z(wscCC_FOR_LOWROW_XYZ_Z->GetValue(), m_Split);
}


void LowRowPage::OnSPECIAL(wxSpinEvent& event)
{
	m_Settings.SetSPECIAL(wscSPECIAL->GetValue(), m_Split);
}


void LowRowPage::OnLOWROW_X_BEHAVIOUR(wxCommandEvent& event)
{
	m_Settings.SetLOWROW_X_BEHAVIOUR(wrbLOWROW_X_BEHAVIOUR->GetSelection(), m_Split);
}


void LowRowPage::OnLOWROW_XYZ_BEHAVIOUR(wxCommandEvent& event)
{
	m_Settings.SetLOWROW_XYZ_BEHAVIOUR(wrbLOWROW_XYZ_BEHAVIOUR->GetSelection(), m_Split);
}


void LowRowPage::OnLOWROW_MODE(wxCommandEvent& event)
{
	m_Settings.SetLOWROW_MODE(wrbLOWROW_MODE->GetSelection(), m_Split);
}


void LowRowPage::OnOCTAVE(wxCommandEvent& event)
{
	m_Settings.SetOCTAVE(wrbOCTAVE->GetSelection(), m_Split);
}


void LowRowPage::OnPITCH_TRANSPOSE(wxCommandEvent& event)
{
	m_Settings.SetPITCH_TRANSPOSE(wrbPITCH_TRANSPOSE->GetSelection(), m_Split);
}


void LowRowPage::OnTRANSPOSE_LIGHTS(wxCommandEvent& event)
{
	m_Settings.SetTRANSPOSE_LIGHTS(wrbTRANSPOSE_LIGHTS->GetSelection(), m_Split);
}


// Event table
BEGIN_EVENT_TABLE(LowRowPage, wxPanel)
EVT_SPINCTRL(CC_FOR_LOWROW_ID, LowRowPage::OnCC_FOR_LOWROW)
EVT_SPINCTRL(CC_FOR_LOWROW_XYZ_ID, LowRowPage::OnCC_FOR_LOWROW_XYZ)
EVT_SPINCTRL(CC_FOR_LOWROW_XYZ_Y_ID, LowRowPage::OnCC_FOR_LOWROW_XYZ_Y)
EVT_SPIN(CC_FOR_LOWROW_XYZ_Z_ID, LowRowPage::OnCC_FOR_LOWROW_XYZ_Z)

EVT_RADIOBOX(LOWROW_XYZ_BEHAVIOUR_ID, LowRowPage::OnLOWROW_XYZ_BEHAVIOUR)
EVT_RADIOBOX(LOWROW_X_BEHAVIOUR_ID, LowRowPage::OnLOWROW_X_BEHAVIOUR)
EVT_RADIOBOX(LOWROW_MODE_ID, LowRowPage::OnLOWROW_MODE)
END_EVENT_TABLE()
