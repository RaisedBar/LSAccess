// ColorsPage.cpp

#include "stdafx.h"
#include "ColorsPage.h"

ColorsPage::ColorsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	
	m_Split(split),
	pMyLinnStrument( pLinnStrument),
pMyParent(parent)
{
wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	wxStaticText * lblCOLOR_MAIN = new wxStaticText(myPanel, wxID_ANY, L"&Main color:");
	wrbCOLOR_MAIN = new wxRadioBox(myPanel, Color_MAIN_ID, L"Main color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, pMyLinnStrument->GetCOLOR_MAIN(split), wxRA_SPECIFY_ROWS);
	hBox1->Add(lblCOLOR_MAIN, 0, wxEXPAND);
	hBox1->Add(wrbCOLOR_MAIN, 0, wxEXPAND);
			
		wxStaticText * lblCOLOR_ACCENT = new wxStaticText(myPanel, wxID_ANY, L"&Accent color:");
		wrbCOLOR_ACCENT = new wxRadioBox(myPanel, Color_ACCENT_ID, L"Accent color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, pMyLinnStrument->GetCOLOR_ACCENT(split), wxRA_SPECIFY_ROWS);
		hBox1->Add(lblCOLOR_ACCENT, 0, wxEXPAND);
		hBox1->Add(wrbCOLOR_ACCENT, 0, wxEXPAND);
		
		wxStaticText * lblCOLOR_PLAYED = new wxStaticText(myPanel, wxID_ANY, L"&Played color:");
		wrbCOLOR_PLAYED = new wxRadioBox(myPanel, Color_PLAYED_ID, L"Played color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, pMyLinnStrument->GetCOLOR_PLAYED(split), wxRA_SPECIFY_ROWS);
		hBox1->Add(lblCOLOR_PLAYED, 0, wxEXPAND);
		hBox1->Add(wrbCOLOR_PLAYED, 0, wxEXPAND);
		
		wxStaticText * lblCOLOR_LOWROW = new wxStaticText(myPanel, wxID_ANY, L"&Low-row color:");
		wrbCOLOR_LOWROW = new wxRadioBox(myPanel, Color_LOWROW_ID, L"&Low row color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, pMyLinnStrument->GetCOLOR_LOWROW(split), wxRA_SPECIFY_ROWS);
		hBox1->Add(lblCOLOR_LOWROW, 0, wxEXPAND);
		hBox1->Add(wrbCOLOR_LOWROW, 0, wxEXPAND);

		wxStaticText * lblAnimation = new wxStaticText(myPanel, wxID_ANY, L"&Animation:");
		wrbAnimation = new wxRadioBox(myPanel, ANIMATION_ID, L"&Animation:", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Animations), Animations, pMyLinnStrument->GetTOUCH_ANIMATION(split), wxRA_SPECIFY_ROWS);
		hBox1->Add(lblAnimation, 0, wxEXPAND);
		hBox1->Add(wrbAnimation, 0, wxEXPAND);

		myPanel->SetSizer(hBox1);
	hBox1->SetSizeHints(this);
	myPanel->Fit();
	hBox1->Fit(myPanel);
}


// Event handlers

void ColorsPage::OnCOLOR_MAIN(wxCommandEvent& event)
{
	pMyLinnStrument->SetCOLOR_MAIN( wrbCOLOR_MAIN->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_COLOR_MAIN_NRPN, pMyLinnStrument->GetCOLOR_MAIN(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_COLOR_MAIN_NRPN, pMyLinnStrument->GetCOLOR_MAIN(m_Split));
	}
}


void ColorsPage::OnCOLOR_ACCENT(wxCommandEvent& event)
{
	pMyLinnStrument->SetCOLOR_ACCENT( wrbCOLOR_ACCENT->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_COLOR_ACCENT_NRPN, pMyLinnStrument->GetCOLOR_ACCENT(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_COLOR_ACCENT_NRPN, pMyLinnStrument->GetCOLOR_ACCENT(m_Split));
	}
}


void ColorsPage::OnCOLOR_PLAYED(wxCommandEvent& event)
{
	pMyLinnStrument->SetCOLOR_PLAYED( wrbCOLOR_PLAYED->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_COLOR_PLAYED_NRPN, pMyLinnStrument->GetCOLOR_PLAYED(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_COLOR_PLAYED_NRPN, pMyLinnStrument->GetCOLOR_PLAYED(m_Split));
	}
}

void ColorsPage::OnCOLOR_LOWROW(wxCommandEvent& event)
{
	pMyLinnStrument->SetCOLOR_LOWROW( wrbCOLOR_LOWROW->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_COLOR_LOWROW_NRPN, pMyLinnStrument->GetCOLOR_LOWROW(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_COLOR_LOWROW_NRPN, pMyLinnStrument->GetCOLOR_LOWROW(m_Split));
	}
}


void ColorsPage::OnAnimation(wxCommandEvent& event)
{
	pMyLinnStrument->SetTOUCH_ANIMATION(wrbAnimation->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_TOUCH_ANIMATION_NRPN, pMyLinnStrument->GetTOUCH_ANIMATION(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_TOUCH_ANIMATION_NRPN, pMyLinnStrument->GetTOUCH_ANIMATION(m_Split));
	}
}


// Event table
BEGIN_EVENT_TABLE(ColorsPage, wxPanel)
EVT_RADIOBOX(Color_MAIN_ID, ColorsPage::OnCOLOR_MAIN)
EVT_RADIOBOX(Color_ACCENT_ID, ColorsPage::OnCOLOR_ACCENT)
EVT_RADIOBOX(Color_PLAYED_ID, ColorsPage::OnCOLOR_PLAYED)
EVT_RADIOBOX(Color_LOWROW_ID, ColorsPage::OnCOLOR_LOWROW)
EVT_RADIOBOX(ANIMATION_ID, ColorsPage::OnAnimation)
END_EVENT_TABLE()
