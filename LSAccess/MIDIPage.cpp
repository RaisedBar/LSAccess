// MIDIPage.cpp

#include "stdafx.h"
#include "MIDIPage.h"

MIDIPage::MIDIPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	m_Split(split),
	pMyLinnStrument(pLinnStrument),
	pMyParent(parent)
		{
		// this->SetSizerAndFit(vBox1);
}


// Event handlers

void MIDIPage::OnMIDI_MAIN_CHANNEL(wxSpinEvent& event)
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


void MIDIPage::OnMIDI_PER_ROW_LOWEST_CHANNEL(wxSpinEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_1(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_2(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_3(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_4(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_5(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_6(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_7(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_8(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_9(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_10(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_11(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_12(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_13(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_14(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_15(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_NOTE_16(wxCommandEvent& event)
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


void MIDIPage::OnSPLIT_MODE(wxCommandEvent& event)
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


void MIDIPage::OnCHANNEL_PER_ROW_ORDER(wxCommandEvent& event)
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
BEGIN_EVENT_TABLE(MIDIPage, wxPanel)
EVT_CHECKBOX(CHANNEL_PER_NOTE_1_ID, MIDIPage::OnCHANNEL_PER_NOTE_1)
EVT_CHECKBOX(CHANNEL_PER_NOTE_2_ID, MIDIPage::OnCHANNEL_PER_NOTE_2)
EVT_CHECKBOX(CHANNEL_PER_NOTE_3_ID, MIDIPage::OnCHANNEL_PER_NOTE_3)
EVT_CHECKBOX(CHANNEL_PER_NOTE_4_ID, MIDIPage::OnCHANNEL_PER_NOTE_4)
EVT_CHECKBOX(CHANNEL_PER_NOTE_5_ID, MIDIPage::OnCHANNEL_PER_NOTE_5)
EVT_CHECKBOX(CHANNEL_PER_NOTE_6_ID, MIDIPage::OnCHANNEL_PER_NOTE_6)
EVT_CHECKBOX(CHANNEL_PER_NOTE_7_ID, MIDIPage::OnCHANNEL_PER_NOTE_7)
EVT_CHECKBOX(CHANNEL_PER_NOTE_8_ID, MIDIPage::OnCHANNEL_PER_NOTE_8)
EVT_CHECKBOX(CHANNEL_PER_NOTE_9_ID, MIDIPage::OnCHANNEL_PER_NOTE_9)
EVT_CHECKBOX(CHANNEL_PER_NOTE_10_ID, MIDIPage::OnCHANNEL_PER_NOTE_10)
EVT_CHECKBOX(CHANNEL_PER_NOTE_11_ID, MIDIPage::OnCHANNEL_PER_NOTE_11)
EVT_CHECKBOX(CHANNEL_PER_NOTE_12_ID, MIDIPage::OnCHANNEL_PER_NOTE_12)
EVT_CHECKBOX(CHANNEL_PER_NOTE_13_ID, MIDIPage::OnCHANNEL_PER_NOTE_13)
EVT_CHECKBOX(CHANNEL_PER_NOTE_14_ID, MIDIPage::OnCHANNEL_PER_NOTE_14)
EVT_CHECKBOX(CHANNEL_PER_NOTE_15_ID, MIDIPage::OnCHANNEL_PER_NOTE_15)
EVT_CHECKBOX(CHANNEL_PER_NOTE_16_ID, MIDIPage::OnCHANNEL_PER_NOTE_16)

EVT_SPINCTRL(MIDI_MAIN_CHANNEL_ID, MIDIPage::OnMIDI_MAIN_CHANNEL)
EVT_SPINCTRL(MIDI_PER_ROW_LOWEST_CHANNEL_ID, MIDIPage::OnMIDI_PER_ROW_LOWEST_CHANNEL)

EVT_RADIOBOX(SPLIT_MODE_ID, MIDIPage::OnSPLIT_MODE)
EVT_RADIOBOX(CHANNEL_PER_ROW_ORDER_ID, MIDIPage::OnCHANNEL_PER_ROW_ORDER)
END_EVENT_TABLE()
