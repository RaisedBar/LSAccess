// SequencerPage.cpp

#include "SequencerPage.h"

SequencerPage::SequencerPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetMemoryLocation(pMyLinnStrument->GetActiveMemoryNumber()).GetPerSplitSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

	// Controls
// Value is an LSPatternNumber
	wscSPLIT_LEFT_SEQUENCER_PATTERN = new wxSpinCtrl(myPanel, SPLIT_LEFT_SEQUENCER_PATTERN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_SEQUENCER_PATTERN, MAX_SEQUENCER_PATTERN, m_Settings.GetSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL(), "MIDI per row lowest channel");
	// Toggles:
	chkSPLIT_LEFT_SEQUENCER_TOGGLE_PLAY = new wxCheckBox(myPanel, SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_ID, L"&Play");
		chkSPLIT_LEFT_SEQUENCER_TOGGLE_MUTE = new wxCheckBox(myPanel, SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_ID, L"&Mute");
		btnSPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN = new wxButton(myPanel, SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_ID, L"&Back");
		btnSPLIT_LEFT_SEQUENCER_NEXT_PATTERN = new wxButton(myPanel, SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_ID, L"&Next");
				
	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


