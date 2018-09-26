// PerSplitDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "PerSplitDialog.h"


PerSplitDialog::PerSplitDialog(wxWindow* parent, const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split)
	: wxDialog(NULL, wxID_ANY, title),
pMyLinnStrument(pLinnStrument),
m_Split( split)
{
	wxXmlResource::Get()->LoadDialog(this, parent, wxT("per_split_dialog"));
	SetTitle(title);
	// Set controls to initial values and ranges
	XRCCTRL(*this, "wsc_main_channel", wxSpinCtrl)->SetMin(MIN_MIDI_CHANNEL);
	XRCCTRL(*this, "wsc_main_channel", wxSpinCtrl)->SetMax(MIN_MIDI_CHANNEL);
	XRCCTRL(*this, "wsc_main_channel", wxSpinCtrl)->SetValue(pMyLinnStrument->GetMIDI_MAIN_CHANNEL( m_Split));


// do the same for all of the other controls
}


// Event handlers

void PerSplitDialog::OnMIDI_MAIN_CHANNEL(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIDI_MAIN_CHANNEL(XRCCTRL(*this, "wsc_main_channel", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MAIN_CHANNEL_NRPN, pMyLinnStrument->GetMIDI_MAIN_CHANNEL(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MAIN_CHANNEL_NRPN, pMyLinnStrument->GetMIDI_MAIN_CHANNEL(m_Split));
	}
}


void PerSplitDialog::OnMIDI_PER_ROW_LOWEST_CHANNEL(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIDI_PER_ROW_LOWEST_CHANNEL(XRCCTRL(*this, "wsc_midi_per_row_lowest_channel", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN, pMyLinnStrument->GetMIDI_PER_ROW_LOWEST_CHANNEL(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN, pMyLinnStrument->GetMIDI_PER_ROW_LOWEST_CHANNEL(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_1(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_1", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_1(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_1_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_1(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_2(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_2", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_2(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_2_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_2(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_3(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_3", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_3(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_3_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_3(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_4(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_4", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_4(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_4_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_4(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_5(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_5", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_5(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_5_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_5(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_6(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_6", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_6(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_6_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_6(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_7(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_7", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_7(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_7_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_7(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_8(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_8", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_8(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_8_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_8(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_9(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_9", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_9(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_9_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_9(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_10(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_10", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_10(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_10_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_10(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_11(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_11", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_11(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_11_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_11(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_12(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_12", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_12(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_12_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_12(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_13(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_13", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_13(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_13_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_13(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_14(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_14", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_14(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_14_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_14(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_15(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_15", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_15(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_15_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_15(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_NOTE_16(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_NOTE_1(LinnStrument::LSToggle(XRCCTRL(*this, "chk_16", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_16(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_NOTE_16_NRPN, pMyLinnStrument->GetCHANNEL_PER_NOTE_16(m_Split));
	}
}


void PerSplitDialog::OnSPLIT_MODE(wxCommandEvent& event)
{
	pMyLinnStrument->SetSPLIT_MODE(XRCCTRL(*this, "wrb_split_mode", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MAIN_MODE_NRPN, pMyLinnStrument->GetSPLIT_MODE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MAIN_MODE_NRPN, pMyLinnStrument->GetSPLIT_MODE(m_Split));
	}
}


void PerSplitDialog::OnCHANNEL_PER_ROW_ORDER(wxCommandEvent& event)
{
	pMyLinnStrument->SetCHANNEL_PER_ROW_ORDER(XRCCTRL(*this, "wrb_channel_per_row_order", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CHANNEL_PER_ROW_ORDER_NRPN, pMyLinnStrument->GetCHANNEL_PER_ROW_ORDER(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CHANNEL_PER_ROW_ORDER_NRPN, pMyLinnStrument->GetCHANNEL_PER_ROW_ORDER(m_Split));
	}
}


BEGIN_EVENT_TABLE(PerSplitDialog, wxDialog)
// Buttons
// EVT_BUTTON( wxID_OK, PerSplitDialog::OnOK)

// MIDI page

EVT_CHECKBOX(XRCID("chk1"), PerSplitDialog::OnCHANNEL_PER_NOTE_1)
EVT_CHECKBOX(XRCID("chk2"), PerSplitDialog::OnCHANNEL_PER_NOTE_2)
EVT_CHECKBOX(XRCID("chk3"), PerSplitDialog::OnCHANNEL_PER_NOTE_3)
EVT_CHECKBOX(XRCID("chk4"), PerSplitDialog::OnCHANNEL_PER_NOTE_4)
EVT_CHECKBOX(XRCID("chk5"), PerSplitDialog::OnCHANNEL_PER_NOTE_5)
EVT_CHECKBOX(XRCID("chk6"), PerSplitDialog::OnCHANNEL_PER_NOTE_6)
EVT_CHECKBOX(XRCID("chk7"), PerSplitDialog::OnCHANNEL_PER_NOTE_7)
EVT_CHECKBOX(XRCID("chk8"), PerSplitDialog::OnCHANNEL_PER_NOTE_8)
EVT_CHECKBOX(XRCID("chk9"), PerSplitDialog::OnCHANNEL_PER_NOTE_9)
EVT_CHECKBOX(XRCID("chk10"), PerSplitDialog::OnCHANNEL_PER_NOTE_10)
EVT_CHECKBOX(XRCID("chk11"), PerSplitDialog::OnCHANNEL_PER_NOTE_11)
EVT_CHECKBOX(XRCID("chk12"), PerSplitDialog::OnCHANNEL_PER_NOTE_12)
EVT_CHECKBOX(XRCID("chk13"), PerSplitDialog::OnCHANNEL_PER_NOTE_13)
EVT_CHECKBOX(XRCID("chk14"), PerSplitDialog::OnCHANNEL_PER_NOTE_14)
EVT_CHECKBOX(XRCID("chk15"), PerSplitDialog::OnCHANNEL_PER_NOTE_15)
EVT_CHECKBOX(XRCID("chk16"), PerSplitDialog::OnCHANNEL_PER_NOTE_16)

EVT_SPINCTRL(XRCID("wsc_main_channel"), PerSplitDialog::OnMIDI_MAIN_CHANNEL)
EVT_SPINCTRL(XRCID("wsc_midi_per_row_lowest_channel"), PerSplitDialog::OnMIDI_PER_ROW_LOWEST_CHANNEL)

EVT_RADIOBOX(XRCID("wrb_split_mode"), PerSplitDialog::OnSPLIT_MODE)
EVT_RADIOBOX(XRCID("wrb_channel_per_row_order"), PerSplitDialog::OnCHANNEL_PER_ROW_ORDER)
END_EVENT_TABLE()
