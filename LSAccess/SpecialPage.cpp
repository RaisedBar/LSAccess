// SpecialPage.cpp

#include "SpecialPage.h"

SpecialPage::SpecialPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
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
	// Value is an LSSpecial:
	wxString Specials[] =
	{
		L"Off",
		L"Arp",
		L"CC Faders",
		L"Strum",
		L"Sequencer"
};
wrbSPECIAL = new wxRadioBox(myPanel, SPECIAL_ID, L"Mode", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Specials), Specials, 0, wxRA_SPECIFY_ROWS);

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


