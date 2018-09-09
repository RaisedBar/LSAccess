// BendPage.cpp

#include "stdafx.h"
#include "BendPage.h"

BendPage::BendPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
		pMyParent(parent),
	pMyLinnStrument( pLinnStrument),
	m_Split(split)
{
wxPanel * myPanel = new wxPanel(this, -1);
wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

// Controls
// toggle
chkBEND_TOGGLE = new wxCheckBox(myPanel, BEND_TOGGLE_ID, L"Pitch /&X");
chkBEND_TOGGLE->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetBEND_TOGGLE(split)));
hBox1->Add(chkBEND_TOGGLE, 0, wxEXPAND);
// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
wscBEND_RANGE = new wxSpinCtrl(myPanel, BEND_RANGE_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_BEND_RANGE, MAX_BEND_RANGE, pMyLinnStrument->GetBEND_RANGE(split), "&range");
hBox1->Add(wscBEND_RANGE, 0, wxEXPAND);
// toggle
chkBEND_QUANTIZE_TOGGLE = new wxCheckBox(myPanel, BEND_QUANTIZE_TOGGLE_ID, L"&Quantize");
chkBEND_QUANTIZE_TOGGLE->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetBEND_QUANTIZE_TOGGLE(split)));
hBox1->Add(chkBEND_QUANTIZE_TOGGLE, 0, wxEXPAND);
// Values are from LSPitchQuantize
			wrbBendQuantize = new wxRadioBox(myPanel, BEND_QUANTIZE_ID, L"Quantization &type:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( BendQuantizations), BendQuantizations, pMyLinnStrument->GetBEND_QUANTIZE(split), wxRA_SPECIFY_ROWS);
			hBox1->Add(wrbBendQuantize, 0, wxEXPAND);
			// Toggle
chkRESET_PITCH_ON_RELEASE = new wxCheckBox(myPanel, RESET_PITCH_ON_RELEASE_ID, L"&&Reset pitch &on release");
chkRESET_PITCH_ON_RELEASE->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetRESET_PITCH_ON_RELEASE(split)));
hBox1->Add(chkRESET_PITCH_ON_RELEASE, 0, wxEXPAND);

myPanel->SetSizer(hBox1);
hBox1->SetSizeHints(this);
myPanel->Fit();
hBox1->Fit(myPanel);
}


// Event handlers

void BendPage::OnBEND_RANGE(wxSpinEvent& event)
{
	pMyLinnStrument->SetBEND_RANGE(wscBEND_RANGE->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_BEND_RANGE_NRPN, pMyLinnStrument->GetBEND_RANGE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_BEND_RANGE_NRPN, pMyLinnStrument->GetBEND_TOGGLE(m_Split));
	}
}


void BendPage::OnBEND_TOGGLE(wxCommandEvent& event)
{
	pMyLinnStrument->SetBEND_TOGGLE(LinnStrument::LSToggle(chkBEND_TOGGLE->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_BEND_TOGGLE_NRPN, pMyLinnStrument->GetBEND_TOGGLE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_BEND_TOGGLE_NRPN, pMyLinnStrument->GetBEND_TOGGLE(m_Split));
	}
}


void BendPage::OnBEND_QUANTIZE_TOGGLE(wxCommandEvent& event)
{
	pMyLinnStrument->SetBEND_QUANTIZE_TOGGLE(LinnStrument::LSToggle(chkBEND_QUANTIZE_TOGGLE->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN, pMyLinnStrument->GetBEND_QUANTIZE_TOGGLE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN, pMyLinnStrument->GetBEND_QUANTIZE_TOGGLE(m_Split));
	}
}


void BendPage::OnBendQuantize(wxCommandEvent& event)
{
	pMyLinnStrument->SetBEND_QUANTIZE(wrbBendQuantize->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_PITCH_QUANTIZE_NRPN, pMyLinnStrument->GetBEND_QUANTIZE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_PITCH_QUANTIZE_NRPN, pMyLinnStrument->GetBEND_QUANTIZE(m_Split));
	}
}


void BendPage::OnRESET_PITCH_ON_RELEASE(wxCommandEvent& event)
{
	pMyLinnStrument->SetRESET_PITCH_ON_RELEASE(LinnStrument::LSToggle(chkRESET_PITCH_ON_RELEASE->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN, pMyLinnStrument->GetRESET_PITCH_ON_RELEASE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN, pMyLinnStrument->GetRESET_PITCH_ON_RELEASE(m_Split));
	}
}


// Event table
BEGIN_EVENT_TABLE(BendPage, wxPanel)
EVT_CHECKBOX(BEND_TOGGLE_ID, BendPage::OnBEND_TOGGLE)
EVT_CHECKBOX(BEND_QUANTIZE_TOGGLE_ID, BendPage::OnBEND_QUANTIZE_TOGGLE)
EVT_CHECKBOX(RESET_PITCH_ON_RELEASE_ID, BendPage::OnRESET_PITCH_ON_RELEASE)

EVT_SPINCTRL(BEND_RANGE_ID, BendPage::OnBEND_RANGE)

EVT_RADIOBOX(BEND_QUANTIZE_ID, BendPage::OnBendQuantize)
END_EVENT_TABLE()
