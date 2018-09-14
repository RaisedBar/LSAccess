// SequencerPage.cpp

#include "stdafx.h"
#include "SequencerPage.h"

SequencerPage::SequencerPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	m_Split(split),
	pMyLinnStrument(pLinnStrument),
	pMyParent(parent)
{
				wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
// Value is an LSPatternNumber
	wxStaticText * lblSEQUENCER_PATTERN = new wxStaticText(myPanel, wxID_ANY, L"&Pattern:");
	wscSEQUENCER_PATTERN = new wxSpinCtrl(myPanel, SEQUENCER_PATTERN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_SEQUENCER_PATTERN, MAX_SEQUENCER_PATTERN, pMyLinnStrument->GetSEQUENCER_PATTERN(split), "&Pattern");
	hBox1->Add(lblSEQUENCER_PATTERN, 0, wxEXPAND);
	hBox1->Add(wscSEQUENCER_PATTERN, 0, wxEXPAND);

	// Toggles:
	chkSEQUENCER_TOGGLE_PLAY = new wxCheckBox(myPanel, SEQUENCER_TOGGLE_PLAY_ID, L"&Play");
	chkSEQUENCER_TOGGLE_PLAY->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetSEQUENCER_TOGGLE_PLAY(split)));
	hBox1->Add(chkSEQUENCER_TOGGLE_PLAY, 0, wxEXPAND);

	chkSEQUENCER_TOGGLE_MUTE = new wxCheckBox(myPanel, SEQUENCER_TOGGLE_MUTE_ID, L"&Mute");
		chkSEQUENCER_TOGGLE_MUTE->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetSEQUENCER_TOGGLE_MUTE(split)));
		hBox1->Add(chkSEQUENCER_TOGGLE_MUTE, 0, wxEXPAND);

		btnSEQUENCER_PREVIOUS_PATTERN = new wxButton(myPanel, SEQUENCER_PREVIOUS_PATTERN_ID, L"&Back");
		hBox1->Add(btnSEQUENCER_PREVIOUS_PATTERN, 0, wxEXPAND);

		btnSEQUENCER_NEXT_PATTERN = new wxButton(myPanel, SEQUENCER_NEXT_PATTERN_ID, L"&Next");
		hBox1->Add(btnSEQUENCER_NEXT_PATTERN, 0, wxEXPAND);
			myPanel->SetSizerAndFit(hBox1);
	}


// event handlers

void SequencerPage::OnSEQUENCER_TOGGLE_PLAY(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_TOGGLE_PLAY(LinnStrument::LSToggle(chkSEQUENCER_TOGGLE_PLAY->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN, pMyLinnStrument->GetSEQUENCER_TOGGLE_PLAY(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN, pMyLinnStrument->GetSEQUENCER_TOGGLE_PLAY(m_Split));
	}
}


void SequencerPage::OnSEQUENCER_TOGGLE_MUTE(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_TOGGLE_MUTE(LinnStrument::LSToggle(chkSEQUENCER_TOGGLE_MUTE->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN, pMyLinnStrument->GetSEQUENCER_TOGGLE_MUTE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN, pMyLinnStrument->GetSEQUENCER_TOGGLE_MUTE(m_Split));
	}
}


void SequencerPage::OnSEQUENCER_PREVIOUS_PATTERN(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_PREVIOUS_PATTERN( 1, m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN, pMyLinnStrument->GetSEQUENCER_PREVIOUS_PATTERN(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN, pMyLinnStrument->GetSEQUENCER_PREVIOUS_PATTERN(m_Split));
	}
}


void SequencerPage::OnSEQUENCER_NEXT_PATTERN(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_NEXT_PATTERN( 1, m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN, pMyLinnStrument->GetSEQUENCER_NEXT_PATTERN(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN, pMyLinnStrument->GetSEQUENCER_NEXT_PATTERN(m_Split));
	}
}


void SequencerPage::OnSEQUENCER_PATTERN(wxSpinEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_PATTERN(wscSEQUENCER_PATTERN->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEQUENCER_PATTERN_NRPN, pMyLinnStrument->GetSEQUENCER_PATTERN(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN, pMyLinnStrument->GetSEQUENCER_PATTERN(m_Split));
	}
}


// Event table
BEGIN_EVENT_TABLE(SequencerPage, wxPanel)
EVT_SPIN( SEQUENCER_PATTERN_ID, SequencerPage::OnSEQUENCER_PATTERN)

EVT_CHECKBOX(SEQUENCER_TOGGLE_PLAY_ID, SequencerPage::OnSEQUENCER_TOGGLE_PLAY)
EVT_CHECKBOX(SEQUENCER_TOGGLE_MUTE_ID, SequencerPage::OnSEQUENCER_TOGGLE_MUTE)

EVT_BUTTON(SEQUENCER_PREVIOUS_PATTERN_ID, SequencerPage::OnSEQUENCER_PREVIOUS_PATTERN)
EVT_BUTTON(SEQUENCER_NEXT_PATTERN_ID, SequencerPage::OnSEQUENCER_NEXT_PATTERN)
END_EVENT_TABLE()
