// ColorsPage.cpp

#include "ColorsPage.h"

ColorsPage::ColorsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl()),
	m_Split(split)
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetPerSplitSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
		wrbCOLOR_MAIN = new wxRadioBox(myPanel, Color_MAIN_ID, L"Main color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, m_Settings.GetCOLOR_MAIN(split), wxRA_SPECIFY_ROWS);
		hBox1->Add(wrbCOLOR_MAIN, 0, wxEXPAND);
			wrbCOLOR_ACCENT = new wxRadioBox(myPanel, Color_ACCENT_ID, L"Accent color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, m_Settings.GetCOLOR_ACCENT(split), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbCOLOR_ACCENT, 0, wxEXPAND);
		wrbCOLOR_PLAYED = new wxRadioBox(myPanel, Color_PLAYED_ID, L"Played color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, m_Settings.GetCOLOR_PLAYED(split), wxRA_SPECIFY_ROWS);
		hBox1->Add(wrbCOLOR_PLAYED, 0, wxEXPAND);
		wrbCOLOR_LOWROW = new wxRadioBox(myPanel, Color_LOWROW_ID, L"&Low row color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, m_Settings.GetCOLOR_LOWROW(split), wxRA_SPECIFY_ROWS);
		hBox1->Add(wrbCOLOR_LOWROW, 0, wxEXPAND);
		wrbAnimation = new wxRadioBox(myPanel, ANIMATION_ID, L"&Animation:", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Animations), Animations, m_Settings.GetTOUCH_ANIMATION(split), wxRA_SPECIFY_ROWS);
		hBox1->Add(wrbAnimation, 0, wxEXPAND);

		myPanel->SetSizer(hBox1);
	hBox1->SetSizeHints(this);
	myPanel->Fit();
	hBox1->Fit(myPanel);
}


void ColorsPage::OnCOLOR_MAIN(wxCommandEvent& event)
{
	m_Settings.SetCOLOR_MAIN( wrbCOLOR_MAIN->GetSelection(), m_Split);
}


void ColorsPage::OnCOLOR_ACCENT(wxCommandEvent& event)
{
	m_Settings.SetCOLOR_ACCENT( wrbCOLOR_ACCENT->GetSelection(), m_Split);
}


void ColorsPage::OnCOLOR_PLAYED(wxCommandEvent& event)
{
	m_Settings.SetCOLOR_PLAYED( wrbCOLOR_PLAYED->GetSelection(), m_Split);
}

void ColorsPage::OnCOLOR_LOWROW(wxCommandEvent& event)
{
	m_Settings.SetCOLOR_MAIN( wrbCOLOR_MAIN->GetSelection(), m_Split);
}


void ColorsPage::OnAnimation(wxCommandEvent& event)
{
	m_Settings.SetTOUCH_ANIMATION(wrbAnimation->GetSelection(), m_Split);
}


// Event table
BEGIN_EVENT_TABLE(ColorsPage, wxPanel)
EVT_RADIOBOX(Color_MAIN_ID, ColorsPage::OnCOLOR_MAIN)
EVT_RADIOBOX(Color_ACCENT_ID, ColorsPage::OnCOLOR_ACCENT)
EVT_RADIOBOX(Color_PLAYED_ID, ColorsPage::OnCOLOR_PLAYED)
EVT_RADIOBOX(Color_LOWROW_ID, ColorsPage::OnCOLOR_LOWROW)
EVT_RADIOBOX(ANIMATION_ID, ColorsPage::OnAnimation)
END_EVENT_TABLE()
