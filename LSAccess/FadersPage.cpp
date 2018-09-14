// FadersPage.cpp

#include "stdafx.h"
#include "FadersPage.h"

FadersPage::FadersPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	m_Split(split),
	pMyLinnStrument(pLinnStrument),
pMyParent(parent)
	{
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	wxStaticText * lblCC_FOR_FADER1 = new wxStaticText(myPanel, wxID_ANY, L"CC for Fader &1:");
	wscCC_FOR_FADER1 = new wxSpinCtrl(myPanel, CC_FOR_FADER1_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, pMyLinnStrument->GetCC_FOR_FADER1(split), "CC for Fader &1");
	hBox1->Add(lblCC_FOR_FADER1, 0, wxEXPAND);
	hBox1->Add(wscCC_FOR_FADER1, 0, wxEXPAND);
	
	wxStaticText * lblCC_FOR_FADER2 = new wxStaticText(myPanel, wxID_ANY, L"CC for Fader &2:");
	wscCC_FOR_FADER2 = new wxSpinCtrl(myPanel, CC_FOR_FADER2_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, pMyLinnStrument->GetCC_FOR_FADER2(split), "CC for Fader &2");
	hBox1->Add(lblCC_FOR_FADER2, 0, wxEXPAND);
	hBox1->Add(wscCC_FOR_FADER2, 0, wxEXPAND);
	
	wxStaticText * lblCC_FOR_FADER3 = new wxStaticText(myPanel, wxID_ANY, L"CC for Fader &3:");
	wscCC_FOR_FADER3 = new wxSpinCtrl(myPanel, CC_FOR_FADER3_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, pMyLinnStrument->GetCC_FOR_FADER3(split), "CC for Fader &3");
	hBox1->Add(lblCC_FOR_FADER3, 0, wxEXPAND);
	hBox1->Add(wscCC_FOR_FADER3, 0, wxEXPAND);
	
	wxStaticText * lblCC_FOR_FADER4 = new wxStaticText(myPanel, wxID_ANY, L"CC for Fader &4:");
	wscCC_FOR_FADER4 = new wxSpinCtrl(myPanel, CC_FOR_FADER4_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, pMyLinnStrument->GetCC_FOR_FADER4(split), "CC for Fader &4");
	hBox1->Add(lblCC_FOR_FADER4, 0, wxEXPAND);
	hBox1->Add(wscCC_FOR_FADER4, 0, wxEXPAND);
	
	wxStaticText * lblCC_FOR_FADER5 = new wxStaticText(myPanel, wxID_ANY, L"CC for Fader &5:");
	wscCC_FOR_FADER5 = new wxSpinCtrl(myPanel, CC_FOR_FADER5_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, pMyLinnStrument->GetCC_FOR_FADER5(split), "CC for Fader &5");
	hBox1->Add(lblCC_FOR_FADER5, 0, wxEXPAND);
	hBox1->Add(wscCC_FOR_FADER5, 0, wxEXPAND);
	
	wxStaticText * lblCC_FOR_FADER6 = new wxStaticText(myPanel, wxID_ANY, L"CC for Fader &6:");
	wscCC_FOR_FADER6 = new wxSpinCtrl(myPanel, CC_FOR_FADER6_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, pMyLinnStrument->GetCC_FOR_FADER6(split), "CC for Fader &6");
	hBox1->Add(lblCC_FOR_FADER6, 0, wxEXPAND);
	hBox1->Add(wscCC_FOR_FADER6, 0, wxEXPAND);
	
	wxStaticText * lblCC_FOR_FADER7 = new wxStaticText(myPanel, wxID_ANY, L"CC for Fader &7");
	wscCC_FOR_FADER7 = new wxSpinCtrl(myPanel, CC_FOR_FADER7_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, pMyLinnStrument->GetCC_FOR_FADER7(split), "CC for Fader &7");
	hBox1->Add(lblCC_FOR_FADER7, 0, wxEXPAND);
	hBox1->Add(wscCC_FOR_FADER7, 0, wxEXPAND);
	
	wxStaticText * lblCC_FOR_FADER8 = new wxStaticText(myPanel, wxID_ANY, L"CC for Fader &8:");
	wscCC_FOR_FADER8 = new wxSpinCtrl(myPanel, CC_FOR_FADER8_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, pMyLinnStrument->GetCC_FOR_FADER8(split), "CC for Fader &8");
	hBox1->Add(lblCC_FOR_FADER8, 0, wxEXPAND);
	hBox1->Add(wscCC_FOR_FADER8, 0, wxEXPAND);

	myPanel->SetSizerAndFit(hBox1);
	}


// Event handlers

void FadersPage::OnCC_FOR_FADER1(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER1(wscCC_FOR_FADER1->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER1_NRPN, pMyLinnStrument->GetCC_FOR_FADER1(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER1_NRPN, pMyLinnStrument->GetCC_FOR_FADER1(m_Split));
	}
}


void FadersPage::OnCC_FOR_FADER2(wxSpinEvent& event)
{
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER2_NRPN, pMyLinnStrument->GetCC_FOR_FADER2(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER2_NRPN, pMyLinnStrument->GetCC_FOR_FADER2(m_Split));
	}
	pMyLinnStrument->SetCC_FOR_FADER2(wscCC_FOR_FADER2->GetValue(), m_Split);
}


void FadersPage::OnCC_FOR_FADER3(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER3(wscCC_FOR_FADER3->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER3_NRPN, pMyLinnStrument->GetCC_FOR_FADER3(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER3_NRPN, pMyLinnStrument->GetCC_FOR_FADER3(m_Split));
	}
}


void FadersPage::OnCC_FOR_FADER4(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER4(wscCC_FOR_FADER4->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER4_NRPN, pMyLinnStrument->GetCC_FOR_FADER4(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER4_NRPN, pMyLinnStrument->GetCC_FOR_FADER4(m_Split));
	}
}


void FadersPage::OnCC_FOR_FADER5(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER5(wscCC_FOR_FADER5->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER5_NRPN, pMyLinnStrument->GetCC_FOR_FADER5(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER5_NRPN, pMyLinnStrument->GetCC_FOR_FADER5(m_Split));
	}
}


void FadersPage::OnCC_FOR_FADER6(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER6(wscCC_FOR_FADER6->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER6_NRPN, pMyLinnStrument->GetCC_FOR_FADER6(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER6_NRPN, pMyLinnStrument->GetCC_FOR_FADER6(m_Split));
	}
}


void FadersPage::OnCC_FOR_FADER7(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER7(wscCC_FOR_FADER7->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER7_NRPN, pMyLinnStrument->GetCC_FOR_FADER7(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER7_NRPN, pMyLinnStrument->GetCC_FOR_FADER7(m_Split));
	}
}


void FadersPage::OnCC_FOR_FADER8(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER8(wscCC_FOR_FADER8->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER8_NRPN, pMyLinnStrument->GetCC_FOR_FADER8(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER8_NRPN, pMyLinnStrument->GetCC_FOR_FADER8(m_Split));
	}
}


// Event table
BEGIN_EVENT_TABLE(FadersPage, wxPanel)
EVT_SPINCTRL(CC_FOR_FADER1_ID, FadersPage::OnCC_FOR_FADER1)
EVT_SPINCTRL(CC_FOR_FADER2_ID, FadersPage::OnCC_FOR_FADER2)
EVT_SPINCTRL(CC_FOR_FADER3_ID, FadersPage::OnCC_FOR_FADER3)
EVT_SPINCTRL(CC_FOR_FADER4_ID, FadersPage::OnCC_FOR_FADER4)
EVT_SPINCTRL(CC_FOR_FADER5_ID, FadersPage::OnCC_FOR_FADER5)
EVT_SPINCTRL(CC_FOR_FADER6_ID, FadersPage::OnCC_FOR_FADER6)
EVT_SPINCTRL(CC_FOR_FADER7_ID, FadersPage::OnCC_FOR_FADER7)
EVT_SPINCTRL(CC_FOR_FADER8_ID, FadersPage::OnCC_FOR_FADER8)
END_EVENT_TABLE()
