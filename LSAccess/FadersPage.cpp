// FadersPage.cpp

#include "FadersPage.h"

FadersPage::FadersPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl()),
	m_Split(split)
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetPerSplitSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	wscCC_FOR_FADER1 = new wxSpinCtrl(myPanel, CC_FOR_FADER1_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetCC_FOR_FADER1(split), "CC for Fader &1");
	wscCC_FOR_FADER2 = new wxSpinCtrl(myPanel, CC_FOR_FADER2_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetCC_FOR_FADER2(split), "CC for Fader &2");
	wscCC_FOR_FADER3 = new wxSpinCtrl(myPanel, CC_FOR_FADER3_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetCC_FOR_FADER3(split), "CC for Fader &3");
	wscCC_FOR_FADER4 = new wxSpinCtrl(myPanel, CC_FOR_FADER4_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetCC_FOR_FADER4(split), "CC for Fader &4");
	wscCC_FOR_FADER5 = new wxSpinCtrl(myPanel, CC_FOR_FADER5_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetCC_FOR_FADER5(split), "CC for Fader &5");
	wscCC_FOR_FADER6 = new wxSpinCtrl(myPanel, CC_FOR_FADER6_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetCC_FOR_FADER6(split), "CC for Fader &6");
	wscCC_FOR_FADER7 = new wxSpinCtrl(myPanel, CC_FOR_FADER7_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetCC_FOR_FADER7(split), "CC for Fader &7");
	wscCC_FOR_FADER8 = new wxSpinCtrl(myPanel, CC_FOR_FADER8_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetCC_FOR_FADER8(split), "CC for Fader &8");

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


// Event handlers

void FadersPage::OnCC_FOR_FADER1(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_FADER1(wscCC_FOR_FADER1->GetValue(), m_Split);
}


void FadersPage::OnCC_FOR_FADER2(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_FADER2(wscCC_FOR_FADER2->GetValue(), m_Split);
}


void FadersPage::OnCC_FOR_FADER3(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_FADER3(wscCC_FOR_FADER3->GetValue(), m_Split);
}


void FadersPage::OnCC_FOR_FADER4(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_FADER4(wscCC_FOR_FADER4->GetValue(), m_Split);
}


void FadersPage::OnCC_FOR_FADER5(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_FADER5(wscCC_FOR_FADER5->GetValue(), m_Split);
}


void FadersPage::OnCC_FOR_FADER6(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_FADER6(wscCC_FOR_FADER6->GetValue(), m_Split);
}


void FadersPage::OnCC_FOR_FADER7(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_FADER7(wscCC_FOR_FADER7->GetValue(), m_Split);
}


void FadersPage::OnCC_FOR_FADER8(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_FADER8(wscCC_FOR_FADER8->GetValue(), m_Split);
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
