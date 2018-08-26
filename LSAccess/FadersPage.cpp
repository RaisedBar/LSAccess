// FadersPage.cpp

#include "FadersPage.h"

FadersPage::FadersPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl())
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


