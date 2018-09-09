// LowRowPage.cpp

#include "stdafx.h"
#include "LowRowPage.h"

LowRowPage::LowRowPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	m_Split(split),
	pMyLinnStrument(pLinnStrument),
	pMyParent(parent)
	{
wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
			// Value is an LSLowRowMode
	wrbLOWROW_MODE = new wxRadioBox(myPanel, LOWROW_MODE_ID, L"&Mode", wxDefaultPosition, wxDefaultSize, WXSIZEOF(LowRowModes), LowRowModes, pMyLinnStrument->GetLOWROW_MODE(split), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbLOWROW_MODE, 0, wxEXPAND);
	// Value is an LSLowRowBehaviour
		wrbLOWROW_X_BEHAVIOUR = new wxRadioBox(myPanel, LOWROW_X_BEHAVIOUR_ID, L"&Low row X behaviour:", wxDefaultPosition, wxDefaultSize, WXSIZEOF(LowRowBehaviour), LowRowBehaviour, pMyLinnStrument->GetLOWROW_X_BEHAVIOUR(split), wxRA_SPECIFY_ROWS);
		hBox1->Add(wrbLOWROW_X_BEHAVIOUR, 0, wxEXPAND);
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		wscCC_FOR_LOWROW = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, pMyLinnStrument->GetCC_FOR_LOWROW(split), L"CC message");
		hBox1->Add(wscCC_FOR_LOWROW, 0, wxEXPAND);
		wrbLOWROW_XYZ_BEHAVIOUR = new wxRadioBox(myPanel, LOWROW_XYZ_BEHAVIOUR_ID, L"X,Y,Z X-axis behaviour", wxDefaultPosition, wxDefaultSize, WXSIZEOF(LowRowBehaviour), LowRowBehaviour, pMyLinnStrument->GetLOWROW_XYZ_BEHAVIOUR(split), wxRA_SPECIFY_ROWS);
		hBox1->Add(wrbLOWROW_XYZ_BEHAVIOUR, 0, wxEXPAND);
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	wscCC_FOR_LOWROW_XYZ = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_XYZ_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ(split), "CC for &Low Row X,Y,Z - X");
	hBox1->Add(wscCC_FOR_LOWROW_XYZ, 0, wxEXPAND);
	wscCC_FOR_LOWROW_XYZ_Y = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_XYZ_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ_Y(split), "CC for X,Y,Z - Y");
	hBox1->Add(wscCC_FOR_LOWROW_XYZ_Y, 0, wxEXPAND);
	wscCC_FOR_LOWROW_XYZ_Z = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_XYZ_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ_Z(split), "CC for X,Y,Z - Z");
	hBox1->Add(wscCC_FOR_LOWROW_XYZ_Z, 0, wxEXPAND);

	myPanel->SetSizer(hBox1);
	hBox1->SetSizeHints(this);
	myPanel->Fit();
	hBox1->Fit(myPanel);
}


// event handlers

void LowRowPage::OnCC_FOR_LOWROW(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_LOWROW(wscCC_FOR_LOWROW->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_LOWROW_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW(m_Split));
	}
}


void LowRowPage::OnCC_FOR_LOWROW_XYZ(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_LOWROW_XYZ(wscCC_FOR_LOWROW_XYZ->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ(m_Split));
	}
}


void LowRowPage::OnCC_FOR_LOWROW_XYZ_Y(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_LOWROW_XYZ_Y(wscCC_FOR_LOWROW_XYZ_Y->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ_Y(m_Split));
	}
}


void LowRowPage::OnCC_FOR_LOWROW_XYZ_Z(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_LOWROW_XYZ_Z(wscCC_FOR_LOWROW_XYZ_Z->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ_Z(m_Split));
	}
}


void LowRowPage::OnSPECIAL(wxSpinEvent& event)
{
	pMyLinnStrument->SetSPECIAL(wscSPECIAL->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SPECIAL_NRPN, pMyLinnStrument->GetSPECIAL(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SPECIAL_NRPN, pMyLinnStrument->GetSPECIAL(m_Split));
	}
}


void LowRowPage::OnLOWROW_X_BEHAVIOUR(wxCommandEvent& event)
{
	pMyLinnStrument->SetLOWROW_X_BEHAVIOUR(wrbLOWROW_X_BEHAVIOUR->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN, pMyLinnStrument->GetLOWROW_X_BEHAVIOUR(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN, pMyLinnStrument->GetLOWROW_X_BEHAVIOUR(m_Split));
	}
}


void LowRowPage::OnLOWROW_XYZ_BEHAVIOUR(wxCommandEvent& event)
{
	pMyLinnStrument->SetLOWROW_XYZ_BEHAVIOUR(wrbLOWROW_XYZ_BEHAVIOUR->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN, pMyLinnStrument->GetLOWROW_XYZ_BEHAVIOUR(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN, pMyLinnStrument->GetLOWROW_XYZ_BEHAVIOUR(m_Split));
	}
}


void LowRowPage::OnLOWROW_MODE(wxCommandEvent& event)
{
	pMyLinnStrument->SetLOWROW_MODE(wrbLOWROW_MODE->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_LOWROW_MODE_NRPN, pMyLinnStrument->GetLOWROW_MODE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_LOWROW_MODE_NRPN, pMyLinnStrument->GetLOWROW_MODE(m_Split));
	}
}


void LowRowPage::OnOCTAVE(wxCommandEvent& event)
{
	pMyLinnStrument->SetOCTAVE(wrbOCTAVE->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_OCTAVE_NRPN, pMyLinnStrument->GetOCTAVE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_OCTAVE_NRPN, pMyLinnStrument->GetOCTAVE(m_Split));
	}
}


void LowRowPage::OnPITCH_TRANSPOSE(wxCommandEvent& event)
{
	pMyLinnStrument->SetPITCH_TRANSPOSE(wrbPITCH_TRANSPOSE->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_OCTAVE_NRPN, pMyLinnStrument->GetPITCH_TRANSPOSE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN, pMyLinnStrument->GetPITCH_TRANSPOSE(m_Split));
	}
}


void LowRowPage::OnTRANSPOSE_LIGHTS(wxCommandEvent& event)
{
	pMyLinnStrument->SetTRANSPOSE_LIGHTS(wrbTRANSPOSE_LIGHTS->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN, pMyLinnStrument->GetTRANSPOSE_LIGHTS(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN, pMyLinnStrument->GetTRANSPOSE_LIGHTS(m_Split));
	}
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
