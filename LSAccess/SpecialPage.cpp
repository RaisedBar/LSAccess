// SpecialPage.cpp

#include "SpecialPage.h"

SpecialPage::SpecialPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	m_Split(split),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetPerSplitSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

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

hBox1->Add(wrbSPECIAL, 0, wxEXPAND);
	myPanel->SetSizer(hBox1);
	hBox1->SetSizeHints(this);
	myPanel->Fit();
	hBox1->Fit(myPanel);
}


// event handlers

void SpecialPage::OnSpecial(wxCommandEvent& event)
{
	m_Settings.SetSPECIAL(wrbSPECIAL->GetSelection(), m_Split);
}


// Event table
BEGIN_EVENT_TABLE(SpecialPage, wxPanel)
EVT_RADIOBOX(SPECIAL_ID, SpecialPage::OnSpecial)
END_EVENT_TABLE()
