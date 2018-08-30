// SequencerPage.cpp

#include "SequencerPage.h"

SequencerPage::SequencerPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	m_Split(split),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetPerSplitSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

	// Controls
// Value is an LSPatternNumber
	wscSEQUENCER_PATTERN = new wxSpinCtrl(myPanel, SEQUENCER_PATTERN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_SEQUENCER_PATTERN, MAX_SEQUENCER_PATTERN, m_Settings.GetSEQUENCER_PATTERN(split), "&Pattern");
	// Toggles:
	chkSEQUENCER_TOGGLE_PLAY = new wxCheckBox(myPanel, SEQUENCER_TOGGLE_PLAY_ID, L"&Play");
	chkSEQUENCER_TOGGLE_PLAY->SetValue(m_Settings.GetSEQUENCER_TOGGLE_PLAY(split));
		chkSEQUENCER_TOGGLE_MUTE = new wxCheckBox(myPanel, SEQUENCER_TOGGLE_MUTE_ID, L"&Mute");
		chkSEQUENCER_TOGGLE_MUTE->SetValue(m_Settings.GetSEQUENCER_TOGGLE_MUTE(split));
		btnSEQUENCER_PREVIOUS_PATTERN = new wxButton(myPanel, SEQUENCER_PREVIOUS_PATTERN_ID, L"&Back");
		btnSEQUENCER_NEXT_PATTERN = new wxButton(myPanel, SEQUENCER_NEXT_PATTERN_ID, L"&Next");
				
	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


// event handlers

void SequencerPage::OnSEQUENCER_TOGGLE_PLAY(wxCommandEvent& event)
{
	m_Settings.SetSEQUENCER_TOGGLE_PLAY(chkSEQUENCER_TOGGLE_PLAY->GetValue(), m_Split);
}


void SequencerPage::OnSEQUENCER_TOGGLE_MUTE(wxCommandEvent& event)
{
	m_Settings.SetSEQUENCER_TOGGLE_MUTE(chkSEQUENCER_TOGGLE_MUTE->GetValue(), m_Split);
}


void SequencerPage::OnSEQUENCER_PREVIOUS_PATTERN(wxCommandEvent& event)
{
	m_Settings.SetSEQUENCER_PREVIOUS_PATTERN(1, m_Split);
}


void SequencerPage::OnSEQUENCER_NEXT_PATTERN(wxCommandEvent& event)
{
	m_Settings.SetSEQUENCER_NEXT_PATTERN(1, m_Split);
}


void SequencerPage::OnSEQUENCER_PATTERN(wxSpinEvent& event)
{
	m_Settings.SetSEQUENCER_PATTERN(wscSEQUENCER_PATTERN->GetValue(), m_Split);
}


// Event table
BEGIN_EVENT_TABLE(SequencerPage, wxPanel)
EVT_SPIN( SEQUENCER_PATTERN_ID, SequencerPage::OnSEQUENCER_PATTERN)

EVT_CHECKBOX(SEQUENCER_TOGGLE_PLAY_ID, SequencerPage::OnSEQUENCER_TOGGLE_PLAY)
EVT_CHECKBOX(SEQUENCER_TOGGLE_MUTE_ID, SequencerPage::OnSEQUENCER_TOGGLE_MUTE)

EVT_BUTTON(SEQUENCER_PREVIOUS_PATTERN_ID, SequencerPage::OnSEQUENCER_PREVIOUS_PATTERN)
EVT_BUTTON(SEQUENCER_NEXT_PATTERN_ID, SequencerPage::OnSEQUENCER_NEXT_PATTERN)
END_EVENT_TABLE()
