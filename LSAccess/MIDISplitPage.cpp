// MIDISplitPage.cpp

#include "MIDISplitPage.h"

MIDISplitPage::MIDISplitPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	m_Split(split),
	pMyLinnStrument(pLinnStrument),
	pMyParent(parent)
		{
wxPanel * myPanel = new wxPanel(this, -1);
wxBoxSizer * vBox1 = new wxBoxSizer(wxVERTICAL);
wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
wxBoxSizer * hBox2 = new wxBoxSizer(wxHORIZONTAL);

// Controls
// Value is an LS_MIDIMode
			wrbSPLIT_MODE = new wxRadioBox(myPanel, SPLIT_MODE_ID, L"&Split mode", wxDefaultPosition, wxDefaultSize, WXSIZEOF(SplitModes), SplitModes, pMyLinnStrument->GetSPLIT_MODE(split), wxRA_SPECIFY_ROWS);
vBox1->Add(wrbSPLIT_MODE, 0, wxEXPAND);
// Value is a MIDI channel number:
wscMIDI_MAIN_CHANNEL = new wxSpinCtrl(myPanel, MIDI_MAIN_CHANNEL_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_MIDI_CHANNEL, MAX_MIDI_CHANNEL, pMyLinnStrument->GetMIDI_MAIN_CHANNEL(split), "Main MIDI channel");
vBox1->Add(wscMIDI_MAIN_CHANNEL, 0, wxEXPAND);
// Value is an LSChannelOrder
wrbCHANNEL_PER_ROW_ORDER = new wxRadioBox(myPanel, CHANNEL_PER_ROW_ORDER_ID, L"Channel &Order", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ChannelOrders), ChannelOrders, pMyLinnStrument->GetCHANNEL_PER_ROW_ORDER(split), wxRA_SPECIFY_ROWS);
vBox1->Add(wrbCHANNEL_PER_ROW_ORDER, 0, wxEXPAND);

chkCHANNEL_PER_NOTE_1 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_1_ID, L"Channel per note &1");
chkCHANNEL_PER_NOTE_1->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_1(split)));
hBox1->Add(chkCHANNEL_PER_NOTE_1, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_2 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_2_ID, L"Channel per note &2");
chkCHANNEL_PER_NOTE_2->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_2(split)));
hBox1->Add(chkCHANNEL_PER_NOTE_2, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_3 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_3_ID, L"Channel per note &3");
chkCHANNEL_PER_NOTE_3->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_3(split)));
hBox1->Add(chkCHANNEL_PER_NOTE_3, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_4 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_4_ID, L"Channel per note &4");
chkCHANNEL_PER_NOTE_4->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_4(split)));
hBox1->Add(chkCHANNEL_PER_NOTE_4, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_5 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_5_ID, L"Channel per note &5");
chkCHANNEL_PER_NOTE_5->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_5(split)));
hBox1->Add(chkCHANNEL_PER_NOTE_5, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_6 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_6_ID, L"Channel per note &6");;
chkCHANNEL_PER_NOTE_6->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_6(split)));
hBox1->Add(chkCHANNEL_PER_NOTE_6, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_7 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_7_ID, L"Channel per note &7");
chkCHANNEL_PER_NOTE_7->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_7(split)));
hBox1->Add(chkCHANNEL_PER_NOTE_7, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_8 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_8_ID, L"Channel per note &8");
chkCHANNEL_PER_NOTE_8->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_8(split)));
hBox1->Add(chkCHANNEL_PER_NOTE_8, 0, wxEXPAND);

chkCHANNEL_PER_NOTE_9 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_9_ID, L"Channel per note &9");
chkCHANNEL_PER_NOTE_9->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_9(split)));
hBox2->Add(chkCHANNEL_PER_NOTE_9, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_10 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_10_ID, L"Channel per note 10");
chkCHANNEL_PER_NOTE_10->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_10(split)));
hBox2->Add(chkCHANNEL_PER_NOTE_10, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_11 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_11_ID, L"Channel per note &11");
chkCHANNEL_PER_NOTE_11->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_11(split)));
hBox2->Add(chkCHANNEL_PER_NOTE_11, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_12 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_12_ID, L"Channel per note &12");
chkCHANNEL_PER_NOTE_12->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_12(split)));
hBox2->Add(chkCHANNEL_PER_NOTE_12, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_13 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_13_ID, L"Channel per note 13");
chkCHANNEL_PER_NOTE_13->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_13(split)));
hBox2->Add(chkCHANNEL_PER_NOTE_13, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_14 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_14_ID, L"Channel per note 14");
chkCHANNEL_PER_NOTE_14->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_14(split)));
hBox2->Add(chkCHANNEL_PER_NOTE_14, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_15 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_15_ID, L"Channel per note 15");
chkCHANNEL_PER_NOTE_15->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_15(split)));
hBox2->Add(chkCHANNEL_PER_NOTE_15, 0, wxEXPAND);
chkCHANNEL_PER_NOTE_16 = new wxCheckBox(myPanel, CHANNEL_PER_NOTE_16_ID, L"Channel per note 16");
chkCHANNEL_PER_NOTE_16->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetCHANNEL_PER_NOTE_16(split)));
hBox2->Add(chkCHANNEL_PER_NOTE_16, 0, wxEXPAND);

// Value is a MIDI channel number:
wscMIDI_PER_ROW_LOWEST_CHANNEL = new wxSpinCtrl(myPanel, MIDI_PER_ROW_LOWEST_CHANNEL_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_MIDI_CHANNEL, MAX_MIDI_CHANNEL, pMyLinnStrument->GetMIDI_PER_ROW_LOWEST_CHANNEL(split), "MIDI per row lowest channel");
vBox1->Add(wscMIDI_PER_ROW_LOWEST_CHANNEL, 0, wxEXPAND);

vBox1->Add(hBox1, 0, wxEXPAND);
vBox1->Add(hBox2, 0, wxEXPAND);

myPanel->SetSizer(vBox1);
vBox1->SetSizeHints(this);
myPanel->Fit();
vBox1->Fit(myPanel);
}


// Event handlers

void MIDISplitPage::OnMIDI_MAIN_CHANNEL(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIDI_MAIN_CHANNEL(wscMIDI_MAIN_CHANNEL->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MAIN_CHANNEL_NRPN, pMyLinnStrument->GetMIDI_MAIN_CHANNEL( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MAIN_CHANNEL_NRPN, pMyLinnStrument->GetMIDI_MAIN_CHANNEL( m_Split));
	}
	}


void MIDISplitPage::OnMIDI_PER_ROW_LOWEST_CHANNEL(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIDI_PER_ROW_LOWEST_CHANNEL(wscMIDI_PER_ROW_LOWEST_CHANNEL->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN, pMyLinnStrument->GetMIDI_PER_ROW_LOWEST_CHANNEL( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN, pMyLinnStrument->GetMIDI_PER_ROW_LOWEST_CHANNEL( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_1(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_1->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_1( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_1( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_2(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_2(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_2->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_2( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_2( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_3(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_3(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_3->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_3( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_3( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_4(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_4(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_4->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_4( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_4( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_5(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_5(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_5->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_5( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_5( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_6(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_6(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_6->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_6( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_6( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_7(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_7(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_7->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_7( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_7( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_8(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_8(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_8->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_8( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_8( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_9(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_9(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_9->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_9( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_9( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_10(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_10(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_10->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_10( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_10( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_11(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_11(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_11->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_11( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_11( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_12(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_12(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_12->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_12( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_12( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_13(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_13(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_13->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_13( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_13( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_14(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_14(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_14->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_14( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_14( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_15(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_15(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_15->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_15( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_15( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_NOTE_16(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_16(LinnStrument::LSToggle(chkCHANNEL_PER_NOTE_16->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_16( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_16( m_Split));
	}
}


void MIDISplitPage::OnSPLIT_MODE(wxCommandEvent& event)
{
	pMyLinnStrument->SetSPLIT_MODE(wrbSPLIT_MODE->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MAIN_MODE_NRPN, pMyLinnStrument->GetSPLIT_MODE( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MAIN_MODE_NRPN, pMyLinnStrument->GetSPLIT_MODE( m_Split));
	}
}


void MIDISplitPage::OnCHANNEL_PER_ROW_ORDER(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_ROW_ORDER(wrbCHANNEL_PER_ROW_ORDER->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_ROW_ORDER_NRPN, pMyLinnStrument->GetCHANNEL_PER_ROW_ORDER( m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER_NRPN, pMyLinnStrument->GetCHANNEL_PER_ROW_ORDER( m_Split));
	}
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
