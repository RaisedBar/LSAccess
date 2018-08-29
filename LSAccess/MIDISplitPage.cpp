// MIDISplitPage.cpp

#include "MIDISplitPage.h"

MIDISplitPage::MIDISplitPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
		pMyParent(new wxBookCtrl()),
	m_Split( split)
	{
	pMyLinnStrument = pLinnStrument;
m_Settings = pMyLinnStrument->GetPerSplitSettings();
pMyParent = parent;
wxPanel * myPanel = new wxPanel(this, -1);
wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

// Controls
// Value is an LS_MIDIMode
wrbSPLIT_MODE = new wxRadioBox(myPanel, SPLIT_MODE_ID, L"&Split mode", wxDefaultPosition, wxDefaultSize, WXSIZEOF(SplitModes), SplitModes, m_Settings.GetSPLIT_MODE(split), wxRA_SPECIFY_ROWS);
	// Value is a MIDI channel number:
wscMIDI_MAIN_CHANNEL = new wxSpinCtrl(myPanel, MIDI_MAIN_CHANNEL_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_MIDI_CHANNEL, MAX_MIDI_CHANNEL, m_Settings.GetMIDI_MAIN_CHANNEL(split), "Main MIDI channel");
// Value is an LSChannelOrder
wrbCHANNEL_PER_ROW_ORDER = new wxRadioBox(myPanel, CHANNEL_PER_ROW_ORDER_ID, L"Channel &Order", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ChannelOrders), ChannelOrders, m_Settings.GetCHANNEL_PER_ROW_ORDER(split), wxRA_SPECIFY_ROWS);
chkCHANNEL_PER_NOTE_1 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_1_ID, L"Channel per note &1");
chkCHANNEL_PER_NOTE_1->SetValue(m_Settings.GetCHANNEL_PER_NOTE_1(split));
chkCHANNEL_PER_NOTE_2 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_2_ID, L"Channel per note &2");
chkCHANNEL_PER_NOTE_2->SetValue(m_Settings.GetCHANNEL_PER_NOTE_2(split));
chkCHANNEL_PER_NOTE_3 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_3_ID, L"Channel per note &3");
chkCHANNEL_PER_NOTE_3->SetValue(m_Settings.GetCHANNEL_PER_NOTE_3(split));
chkCHANNEL_PER_NOTE_4 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_4_ID, L"Channel per note &4");
chkCHANNEL_PER_NOTE_4->SetValue(m_Settings.GetCHANNEL_PER_NOTE_4(split));
chkCHANNEL_PER_NOTE_5 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_5_ID, L"Channel per note &5");
chkCHANNEL_PER_NOTE_5->SetValue(m_Settings.GetCHANNEL_PER_NOTE_5(split));
chkCHANNEL_PER_NOTE_6 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_6_ID, L"Channel per note &6");;
chkCHANNEL_PER_NOTE_6->SetValue(m_Settings.GetCHANNEL_PER_NOTE_6(split));
chkCHANNEL_PER_NOTE_7 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_7_ID, L"Channel per note &7");
chkCHANNEL_PER_NOTE_7->SetValue(m_Settings.GetCHANNEL_PER_NOTE_7(split));
chkCHANNEL_PER_NOTE_8 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_8_ID, L"Channel per note &8");
chkCHANNEL_PER_NOTE_8->SetValue(m_Settings.GetCHANNEL_PER_NOTE_8(split));
chkCHANNEL_PER_NOTE_9 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_9_ID, L"Channel per note &9");
chkCHANNEL_PER_NOTE_9->SetValue(m_Settings.GetCHANNEL_PER_NOTE_9(split));
chkCHANNEL_PER_NOTE_10 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_10_ID, L"Channel per note 10");
chkCHANNEL_PER_NOTE_10->SetValue(m_Settings.GetCHANNEL_PER_NOTE_10(split));
chkCHANNEL_PER_NOTE_11 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_11_ID, L"Channel per note &11");
chkCHANNEL_PER_NOTE_11->SetValue(m_Settings.GetCHANNEL_PER_NOTE_11(split));
chkCHANNEL_PER_NOTE_12 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_12_ID, L"Channel per note &12");
chkCHANNEL_PER_NOTE_12->SetValue(m_Settings.GetCHANNEL_PER_NOTE_12(split));
chkCHANNEL_PER_NOTE_13 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_13_ID, L"Channel per note 13");
chkCHANNEL_PER_NOTE_13->SetValue(m_Settings.GetCHANNEL_PER_NOTE_13(split));
chkCHANNEL_PER_NOTE_14 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_14_ID, L"Channel per note 14");
chkCHANNEL_PER_NOTE_14->SetValue(m_Settings.GetCHANNEL_PER_NOTE_14(split));
chkCHANNEL_PER_NOTE_15 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_15_ID, L"Channel per note 15");
chkCHANNEL_PER_NOTE_15->SetValue(m_Settings.GetCHANNEL_PER_NOTE_15(split));
chkCHANNEL_PER_NOTE_16 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_16_ID, L"Channel per note 16");
chkCHANNEL_PER_NOTE_16->SetValue(m_Settings.GetCHANNEL_PER_NOTE_16(split));
// Value is a MIDI channel number:
wscMIDI_PER_ROW_LOWEST_CHANNEL = new wxSpinCtrl(myPanel, MIDI_PER_ROW_LOWEST_CHANNEL_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_MIDI_CHANNEL, MAX_MIDI_CHANNEL, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(split), "MIDI per row lowest channel");

myPanel->SetSizer(hBoxSettings);
hBoxSettings->SetSizeHints(this);
myPanel->Fit();
hBoxSettings->Fit(myPanel);
}


void MIDISplitPage::OnMIDI_MAIN_CHANNEL(wxSpinEvent& event)
{
	m_Settings.SetMIDI_MAIN_CHANNEL(wscMIDI_MAIN_CHANNEL->GetValue(), m_Split);
}


void MIDISplitPage::OnMIDI_PER_ROW_LOWEST_CHANNEL(wxSpinEvent& event)
{
	m_Settings.SetMIDI_PER_ROW_LOWEST_CHANNEL(wscMIDI_PER_ROW_LOWEST_CHANNEL->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_1(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_1(chkCHANNEL_PER_NOTE_1->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_2(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_2(chkCHANNEL_PER_NOTE_2->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_3(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_3(chkCHANNEL_PER_NOTE_3->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_4(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_4(chkCHANNEL_PER_NOTE_4->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_5(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_5(chkCHANNEL_PER_NOTE_5->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_6(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_6(chkCHANNEL_PER_NOTE_6->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_7(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_7(chkCHANNEL_PER_NOTE_7->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_8(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_8(chkCHANNEL_PER_NOTE_8->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_9(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_9(chkCHANNEL_PER_NOTE_9->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_10(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_10(chkCHANNEL_PER_NOTE_10->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_11(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_11(chkCHANNEL_PER_NOTE_11->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_12(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_12(chkCHANNEL_PER_NOTE_12->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_13(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_13(chkCHANNEL_PER_NOTE_13->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_14(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_14(chkCHANNEL_PER_NOTE_14->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_15(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_15(chkCHANNEL_PER_NOTE_15->GetValue(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_16(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_NOTE_16(chkCHANNEL_PER_NOTE_16->GetValue(), m_Split);
}


void MIDISplitPage::OnSPLIT_MODE(wxCommandEvent& event)
{
	m_Settings.SetSPLIT_MODE(wrbSPLIT_MODE->GetSelection(), m_Split);
}


void MIDISplitPage::OnCHANNEL_PER_ROW_ORDER(wxCommandEvent& event)
{
	m_Settings.SetCHANNEL_PER_ROW_ORDER(wrbCHANNEL_PER_ROW_ORDER->GetSelection(), m_Split);
}


// Event table
BEGIN_EVENT_TABLE(MIDISplitPage, wxPanel)
EVT_CHECKBOX(CHANNEL_PER_NOTE_1_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_1)
EVT_CHECKBOX(CHANNEL_PER_NOTE_2_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_2)
EVT_CHECKBOX(CHANNEL_PER_NOTE_3_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_3)
EVT_CHECKBOX(CHANNEL_PER_NOTE_4_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_4)
EVT_CHECKBOX(CHANNEL_PER_NOTE_5_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_5)
EVT_CHECKBOX(CHANNEL_PER_NOTE_6_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_6)
EVT_CHECKBOX(CHANNEL_PER_NOTE_7_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_7)
EVT_CHECKBOX(CHANNEL_PER_NOTE_8_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_8)
EVT_CHECKBOX(CHANNEL_PER_NOTE_9_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_9)
EVT_CHECKBOX(CHANNEL_PER_NOTE_10_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_10)
EVT_CHECKBOX(CHANNEL_PER_NOTE_11_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_11)
EVT_CHECKBOX(CHANNEL_PER_NOTE_12_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_12)
EVT_CHECKBOX(CHANNEL_PER_NOTE_13_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_13)
EVT_CHECKBOX(CHANNEL_PER_NOTE_14_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_14)
EVT_CHECKBOX(CHANNEL_PER_NOTE_15_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_15)
EVT_CHECKBOX(CHANNEL_PER_NOTE_16_ID, MIDISplitPage::OnCHANNEL_PER_NOTE_16)

EVT_SPINCTRL(MIDI_MAIN_CHANNEL_ID, MIDISplitPage::OnMIDI_MAIN_CHANNEL)
EVT_SPINCTRL(MIDI_PER_ROW_LOWEST_CHANNEL_ID, MIDISplitPage::OnMIDI_PER_ROW_LOWEST_CHANNEL)

EVT_RADIOBOX(SPLIT_MODE_ID, MIDISplitPage::OnSPLIT_MODE)
EVT_RADIOBOX(CHANNEL_PER_ROW_ORDER_ID, MIDISplitPage::OnCHANNEL_PER_ROW_ORDER)
END_EVENT_TABLE()
