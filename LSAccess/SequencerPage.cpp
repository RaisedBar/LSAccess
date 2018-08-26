// SequencerPage.cpp

#include "SequencerPage.h"

SequencerPage::SequencerPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
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
// Value is an LSPatternNumber
	wscSEQUENCER_PATTERN = new wxSpinCtrl(myPanel, SEQUENCER_PATTERN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_SEQUENCER_PATTERN, MAX_SEQUENCER_PATTERN, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(split), "MIDI per row lowest channel");
	// Toggles:
	chkSEQUENCER_TOGGLE_PLAY = new wxCheckBox(myPanel, SEQUENCER_TOGGLE_PLAY_ID, L"&Play");
		chkSEQUENCER_TOGGLE_MUTE = new wxCheckBox(myPanel, SEQUENCER_TOGGLE_MUTE_ID, L"&Mute");
		btnSEQUENCER_PREVIOUS_PATTERN = new wxButton(myPanel, SEQUENCER_PREVIOUS_PATTERN_ID, L"&Back");
		btnSEQUENCER_NEXT_PATTERN = new wxButton(myPanel, SEQUENCER_NEXT_PATTERN_ID, L"&Next");
				
	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


