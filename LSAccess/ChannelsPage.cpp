// ChannelsPage.cpp

#include "ChannelsPage.h"

ChannelsPage::ChannelsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
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
chkSPLIT_LEFT_CHANNEL_PER_NOTE_1 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_1_ID, L"Channel per note &1");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_2 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_2_ID, L"Channel per note &2");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_3 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_3_ID, L"Channel per note &3");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_4 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_4_ID, L"Channel per note &4");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_5 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_5_ID, L"Channel per note &5");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_6 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_6_ID, L"Channel per note &6");;
chkSPLIT_LEFT_CHANNEL_PER_NOTE_7 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_7_ID, L"Channel per note &7");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_8 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_8_ID, L"Channel per note &8");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_9 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_9_ID, L"Channel per note &9");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_10 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_10_ID, L"Channel per note 10");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_11 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_11_ID, L"Channel per note &11");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_12 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_12_ID, L"Channel per note &12");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_13 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_13_ID, L"Channel per note 13");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_14 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_14_ID, L"Channel per note 14");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_15 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_15_ID, L"Channel per note 15");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_16 = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_16_ID, L"Channel per note 16");
// Value is a MIDI channel number:
wscSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL = new wxSpinCtrl(myPanel, SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_MIDI_CHANNEL, MAX_MIDI_CHANNEL, m_Settings.GetSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL(), "MIDI per row lowest channel");

myPanel->SetSizer(hBoxSettings);
hBoxSettings->SetSizeHints(this);
myPanel->Fit();
hBoxSettings->Fit(myPanel);
}


