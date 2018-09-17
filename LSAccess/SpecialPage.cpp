// SpecialPage.cpp

#include "stdafx.h"
#include "SpecialPage.h"

SpecialPage::SpecialPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	m_Split(split),
	pMyLinnStrument(pLinnStrument),
	pMyParent(parent)
{
		wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	// Value is an LSSpecial:
	wxStaticText * lblSPECIAL = new wxStaticText(this, wxID_ANY, L"Special &Mode:");
	wrbSPECIAL = new wxRadioBox(this, SPECIAL_ID, L"Special &Mode", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Specials), Specials, pMyLinnStrument->GetSPECIAL(m_Split), wxRA_SPECIFY_ROWS);
	hBox1->Add(lblSPECIAL, 0, wxEXPAND);
	hBox1->Add(wrbSPECIAL, 0, wxEXPAND);
		this->SetSizerAndFit(hBox1);
	}


// event handlers

void SpecialPage::OnSpecial(wxCommandEvent& event)
{
	pMyLinnStrument->SetSPECIAL(wrbSPECIAL->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SPECIAL_NRPN, pMyLinnStrument->GetSPECIAL(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SPECIAL_NRPN, pMyLinnStrument->GetSPECIAL(m_Split));
	}
}


// Event table
BEGIN_EVENT_TABLE(SpecialPage, wxPanel)
EVT_RADIOBOX(SPECIAL_ID, SpecialPage::OnSpecial)
END_EVENT_TABLE()
