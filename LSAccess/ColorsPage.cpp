// ColorsPage.cpp

#include "ColorsPage.h"

ColorsPage::ColorsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
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
		wrbCOLOR_MAIN = new wxRadioBox(myPanel, Color_MAIN_ID, L"Main color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, m_Settings.GetCOLOR_MAIN(), wxRA_SPECIFY_ROWS);
	wrbCOLOR_ACCENT = new wxRadioBox(myPanel, Color_ACCENT_ID, L"Accent color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, m_Settings.GetCOLOR_ACCENT(), wxRA_SPECIFY_ROWS);
	wrbCOLOR_PLAYED = new wxRadioBox(myPanel, Color_PLAYED_ID, L"Played color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, m_Settings.GetCOLOR_PLAYED(), wxRA_SPECIFY_ROWS);
	wrbCOLOR_LOWROW = new wxRadioBox(myPanel, Color_LOWROW_ID, L"&Low row color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, m_Settings.GetCOLOR_LOWROW(), wxRA_SPECIFY_ROWS);
	wrbAnimation = new wxRadioBox(myPanel, ANIMATION_ID, L"&Animation:", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Animations), Animations, m_Settings.GetTOUCH_ANIMATION(), wxRA_SPECIFY_ROWS);

		myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


