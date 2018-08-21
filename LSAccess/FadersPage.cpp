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
	wxSpinCtrl * wscCC_FOR_FADER1;
	wxSpinCtrl * wscCC_FOR_FADER2;
	wxSpinCtrl * wscCC_FOR_FADER3;
	wxSpinCtrl * wscCC_FOR_FADER4;
	wxSpinCtrl * wscCC_FOR_FADER5;
	wxSpinCtrl * wscCC_FOR_FADER6;
	wxSpinCtrl * wscCC_FOR_FADER7;
	wxSpinCtrl * wscCC_FOR_FADER8;

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


