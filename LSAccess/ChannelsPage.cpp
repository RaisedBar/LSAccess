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
chkSPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN, L"Channel per note &1");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN, L"Channel per note &2");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN, L"Channel per note &3");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN, L"Channel per note &4");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN, L"Channel per note &5");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN, L"Channel per note &6");;
chkSPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN, L"Channel per note &7");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN, L"Channel per note &8");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN, L"Channel per note &9");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN, L"Channel per note 10");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN, L"Channel per note &11");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN, L"Channel per note &12");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN, L"Channel per note 13");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN, L"Channel per note 14");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN, L"Channel per note 15");
chkSPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN, L"Channel per note 16");
// Value is a MIDI channel number:
wscSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN = new wxSpinCtrl(myPanel, SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_MIDI_CHANNEL, MAX_MIDI_CHANNEL, m_Settings.GetSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN(), "MIDI per row lowest channel");
/*
// toggles:
chkSPLIT_LEFT_SEND_Y_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_SEND_Y_NRPN, L"Send &Y");
// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
wscSPLIT_LEFT_CC_FOR_Y_NRPN = new wxSpinCtrl(myPanel, SPLIT_LEFT_CC_FOR_Y_NRPN, L"CC for &Y");
// Toggle:
wxCheckBox * chkSPLIT_LEFT_RELATIVE_Y_NRPN;
wxCheckBox * chkSPLIT_LEFT_RELATIVE_Z_NRPN;
// Value is an LSExpressionZ
wxSpinCtrl  * wscSPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN;
// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
wscSPLIT_LEFT_CC_FOR_Z_NRPN = new wxSpinCtrl(myPanel, SPLIT_LEFT_CC_FOR_Z_NRPN, L"CC for &Z");
/*
				// Values are defined in LSColor
wxRadioButton * rdoSPLIT_LEFT_COLOR_MAIN_NRPN;
wxRadioButton * rdoSPLIT_LEFT_COLOR_ACCENT_NRPN;
wxRadioButton * rdoSPLIT_LEFT_COLOR_PLAYED_NRPN;
wxRadioButton * rdoSPLIT_LEFT_COLOR_LOWROW_NRPN;
// Value is an LSLowRowMode
wxRadioButton * rdoSPLIT_LEFT_LOWROW_MODE_NRPN;
// Value is an LSSpecial:
wxSpinCtrl  * wscSPLIT_LEFT_SPECIAL_NRPN;
// Value is an LSOctave
wxRadioButton * rdoSPLIT_LEFT_OCTAVE_NRPN;
// Values are from LSPitch
wxRadioButton * rdoSPLIT_LEFT_PITCH_TRANSPOSE_NRPN;
wxRadioButton * rdoSPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN;
// Value is an LSExpressionY
wxSpinCtrl  * wscSPLIT_LEFT_EXPRESSION_FOR_Y_NRPN;
// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
wscSPLIT_LEFT_CC_FOR_FADER1_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_CC_FOR_FADER2_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_CC_FOR_FADER3_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_CC_FOR_FADER4_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_CC_FOR_FADER5_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_CC_FOR_FADER6_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_CC_FOR_FADER7_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_CC_FOR_FADER8_NRPN;
// Value is an LSLowRowBehaviour
wxRadioButton * rdoSPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN;
// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
wxSpinCtrl * wscSPLIT_LEFT_CC_FOR_LOWROW_NRPN;
// Value is an LSLowRowBehaviour
wxRadioButton * rdiSPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN;
// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
wxSpinCtrl * wscSPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN;
// Values are constrained by MIN_CC and MAX_CC
wxSpinCtrl * wscSPLIT_LEFT_MIN_CC_FOR_Y_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_MAX_CC_FOR_Y_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_MIN_CC_FOR_Z_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_MAX_CC_FOR_Z_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN;
wxSpinCtrl * wscSPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN;
// Value is an LSChannelOrder
wxRadioButton * rdoSPLIT_LEFT_CHANNEL_PER_ROW_ORDER;
// Value is an LSAnimation
wxRadioButton * wscSPLIT_LEFT_TOUCH_ANIMATION;
		// Toggle:
wxCheckBox * chkSPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN;
wxCheckBox * chkSPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN;
wxCheckBox * chkSPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN;
// Value is an LSPatternNumber
wxRadioButton * rdoSPLIT_LEFT_SEQUENCER_PATTERN_NRPN;
wxCheckBox * chkSPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN;
*/

myPanel->SetSizer(hBoxSettings);
hBoxSettings->SetSizeHints(this);
myPanel->Fit();
hBoxSettings->Fit(myPanel);
}


/*
void ChannelsPage::SetChannelsPage(CurrentPatchPage * pPage)
{
	pPatchPage = pPage;
}
*/

