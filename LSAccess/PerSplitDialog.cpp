// PerSplitDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "PerSplitDialog.h"


PerSplitDialog::PerSplitDialog(wxWindow* parent, const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split)
	: 
	pMyLinnStrument(pLinnStrument),
m_Split( split)
{
	if (wxXmlResource::Get()->LoadDialog(this, parent, wxT("per_split_dialog")))
	{
		SetTitle(title);
		// Set controls to initial values and ranges
	InitMIDIPage();
	InitBendPage();
	InitAxesPage();
InitColorsPage();
	InitLowRowPage();
InitFadersPage();
	InitSpecialPage();
		}
	else
	{
		wxMessageBox("Could not load Per-Split Settings dialog from XRC", wstrErrorTitle, wxOK | wxICON_ERROR);
		EndModal(false);
	}
}


void PerSplitDialog::InitMIDIPage()
{
	/*
	XRCCTRL(*this, "wrb_split_mode", wxRadioBox)->SetSelection(pMyLinnStrument->GetSPLIT_MODE(m_Split));
	int myY = 200;
	XRCCTRL(*this, "wrb_split_mode", wxRadioBox)->
	XRCCTRL(*this, "wrb_split_mode", wxRadioBox)->SetPosition( wxPoint( -1, myY));
	*/
		wxPoint myPoint = XRCCTRL(*this, "wrbOneChannel", wxRadioButton)->GetPosition();
		DBOUT(L"wrbOneChannel X = " + std::to_wstring(myPoint.x) + L"\nwrbOneChannel Y = " + std::to_wstring(myPoint.y) + L"\n")

				myPoint = XRCCTRL(*this, "main_channel_label", wxStaticText)->GetPosition();
		DBOUT(L"Main channel label X = " + std::to_wstring(myPoint.x) + L"\nwrbOneChannel Y = " + std::to_wstring(myPoint.y) + L"\n")

		myPoint = XRCCTRL(*this, "wsc_main_channel", wxSpinCtrl)->GetPosition();
		DBOUT(L"wsc_main_channel X = " + std::to_wstring(myPoint.x) + L"\nwrbOneChannel Y = " + std::to_wstring(myPoint.y) + L"\n")

		XRCCTRL(*this, "wsc_main_channel", wxSpinCtrl)->SetValue(pMyLinnStrument->GetMIDI_MAIN_CHANNEL(m_Split));
	XRCCTRL(*this, "wsc_main_channel", wxSpinCtrl)->SetMin(MIN_MIDI_CHANNEL);
	XRCCTRL(*this, "wsc_main_channel", wxSpinCtrl)->SetMax(MAX_MIDI_CHANNEL);

		XRCCTRL(*this, "wsc_midi_per_row_lowest_channel", wxSpinCtrl)->SetValue(pMyLinnStrument->GetMIDI_PER_ROW_LOWEST_CHANNEL(m_Split));
	XRCCTRL(*this, "wrb_channel_per_row_order", wxRadioBox)->SetSelection(pMyLinnStrument->GetCHANNEL_PER_ROW_ORDER(m_Split));
	XRCCTRL(*this, "chk_1", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_1(m_Split));
	XRCCTRL(*this, "chk_2", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_2(m_Split));
	XRCCTRL(*this, "chk_3", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_3(m_Split));
	XRCCTRL(*this, "chk_4", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_4(m_Split));
	XRCCTRL(*this, "chk_5", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_5(m_Split));
	XRCCTRL(*this, "chk_6", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_6(m_Split));
	XRCCTRL(*this, "chk_7", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_7(m_Split));
	XRCCTRL(*this, "chk_8", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_8(m_Split));
	XRCCTRL(*this, "chk_9", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_9(m_Split));
	XRCCTRL(*this, "chk_10", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_10(m_Split));
	XRCCTRL(*this, "chk_11", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_11(m_Split));
	XRCCTRL(*this, "chk_12", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_12(m_Split));
	XRCCTRL(*this, "chk_13", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_13(m_Split));
	XRCCTRL(*this, "chk_14", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_14(m_Split));
	XRCCTRL(*this, "chk_15", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_15(m_Split));
	XRCCTRL(*this, "chk_16", wxCheckBox)->SetValue(pMyLinnStrument->GetCHANNEL_PER_NOTE_16(m_Split));
}


void PerSplitDialog::InitBendPage()
{
	XRCCTRL(*this, "chk_send_bend", wxCheckBox)->SetValue(pMyLinnStrument->GetBEND_TOGGLE(m_Split));
	XRCCTRL(*this, "wsc_bend_range", wxSpinCtrl)->SetValue(pMyLinnStrument->GetBEND_RANGE(m_Split));
	XRCCTRL(*this, "wsc_bend_range", wxSpinCtrl)->SetMin(MIN_BEND_RANGE);
	XRCCTRL(*this, "wsc_bend_range", wxSpinCtrl)->SetMax(MAX_BEND_RANGE);
		XRCCTRL(*this, "chk_bend_quantize", wxCheckBox)->SetValue(pMyLinnStrument->GetBEND_QUANTIZE_TOGGLE(m_Split));
	XRCCTRL(*this, "wrb_bend_quantize", wxRadioBox)->SetSelection(pMyLinnStrument->GetBEND_QUANTIZE(m_Split));
	XRCCTRL(*this, "chk_reset_pitch_on_release", wxCheckBox)->SetValue(pMyLinnStrument->GetRESET_PITCH_ON_RELEASE(m_Split));
	}


void PerSplitDialog::InitAxesPage()
{
	// Y-axis
	XRCCTRL(*this, "chk_send_y", wxCheckBox)->SetValue(pMyLinnStrument->GetSEND_Y(m_Split));
		XRCCTRL(*this, "wsc_cc_for_y", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_Y(m_Split));
	XRCCTRL(*this, "wsc_cc_for_y", wxSpinCtrl)->SetMin( MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_y", wxSpinCtrl)->SetMax(MAX_CC);
		XRCCTRL(*this, "wsc_min_cc_for_y", wxSpinCtrl)->SetValue(pMyLinnStrument->GetMIN_CC_FOR_Y(m_Split));
	XRCCTRL(*this, "wsc_min_cc_for_y", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_min_cc_for_y", wxSpinCtrl)->SetMax(MAX_CC);
		XRCCTRL(*this, "wsc_max_cc_for_y", wxSpinCtrl)->SetValue(pMyLinnStrument->GetMAX_CC_FOR_Y(m_Split));
	XRCCTRL(*this, "wsc_max_cc_for_y", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_max_cc_for_y", wxSpinCtrl)->SetMax(MAX_CC);
		XRCCTRL(*this, "chk_relative_y", wxCheckBox)->SetValue(pMyLinnStrument->GetRELATIVE_Y(m_Split));
		XRCCTRL(*this, "wrb_expression_for_y", wxRadioBox)->SetSelection(pMyLinnStrument->GetEXPRESSION_FOR_Y(m_Split));
				XRCCTRL(*this, "wsc_initial_relative_value_for_y", wxSpinCtrl)->SetValue(pMyLinnStrument->GetINITIAL_RELATIVE_VALUE_FOR_Y(m_Split));
		XRCCTRL(*this, "wsc_initial_relative_value_for_y", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_initial_relative_value_for_y", wxSpinCtrl)->SetMax(MAX_CC);
		// Z-axis
		XRCCTRL(*this, "chk_send_z", wxCheckBox)->SetValue(pMyLinnStrument->GetSEND_Z(m_Split));
		XRCCTRL(*this, "wsc_cc_for_z", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_Z(m_Split));
		XRCCTRL(*this, "wsc_cc_for_z", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_cc_for_z", wxSpinCtrl)->SetMax(MAX_CC);
		XRCCTRL(*this, "wsc_min_cc_for_z", wxSpinCtrl)->SetValue(pMyLinnStrument->GetMIN_CC_FOR_Z(m_Split));
		XRCCTRL(*this, "wsc_min_cc_for_z", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_min_cc_for_z", wxSpinCtrl)->SetMax(MAX_CC);
		XRCCTRL(*this, "wsc_max_cc_for_z", wxSpinCtrl)->SetValue(pMyLinnStrument->GetMAX_CC_FOR_Z(m_Split));
		XRCCTRL(*this, "wsc_max_cc_for_z", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_max_cc_for_z", wxSpinCtrl)->SetMax(MAX_CC);
				XRCCTRL(*this, "wrb_expression_for_z", wxRadioBox)->SetSelection(pMyLinnStrument->GetEXPRESSION_FOR_Z(m_Split));
		XRCCTRL(*this, "wsc_14bit_cc_value_for_z", wxSpinCtrl)->SetValue(pMyLinnStrument->Get14BIT_CC_VALUE_FOR_Z(m_Split));
		XRCCTRL(*this, "wsc_14bit_cc_value_for_z", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_14bit_cc_value_for_z", wxSpinCtrl)->SetMax(MAX_CC);
}


void PerSplitDialog::InitColorsPage()
{
	XRCCTRL(*this, "wrb_color_main", wxRadioBox)->SetSelection(pMyLinnStrument->GetCOLOR_MAIN(m_Split));
	XRCCTRL(*this, "wrb_color_accent", wxRadioBox)->SetSelection(pMyLinnStrument->GetCOLOR_ACCENT(m_Split));
		XRCCTRL(*this, "wrb_color_played", wxRadioBox)->SetSelection(pMyLinnStrument->GetCOLOR_PLAYED(m_Split));
		XRCCTRL(*this, "wrb_color_low_row", wxRadioBox)->SetSelection(pMyLinnStrument->GetCOLOR_LOWROW(m_Split));
		XRCCTRL(*this, "wrb_touch_animation", wxRadioBox)->SetSelection(pMyLinnStrument->GetTOUCH_ANIMATION(m_Split));
}


void PerSplitDialog::InitLowRowPage()
{
	XRCCTRL(*this, "wrb_low_row_mode", wxRadioBox)->SetSelection(pMyLinnStrument->GetLOWROW_MODE(m_Split));
		XRCCTRL(*this, "wrb_low_row_x_behaviour", wxRadioBox)->SetSelection(pMyLinnStrument->GetLOWROW_X_BEHAVIOUR(m_Split));
		XRCCTRL(*this, "wsc_cc_for_low_row", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_LOWROW(m_Split));
		XRCCTRL(*this, "wsc_cc_for_low_row", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_cc_for_low_row", wxSpinCtrl)->SetMax(MAX_CC);
				XRCCTRL(*this, "wrb_low_row_x_y_z_behaviour", wxRadioBox)->SetSelection(pMyLinnStrument->GetLOWROW_XYZ_BEHAVIOUR(m_Split));
								XRCCTRL(*this, "wsc_cc_for_x_y_z", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_LOWROW_XYZ(m_Split));
				XRCCTRL(*this, "wsc_cc_for_x_y_z", wxSpinCtrl)->SetMin(MIN_CC);
				XRCCTRL(*this, "wsc_cc_for_x_y_z", wxSpinCtrl)->SetMax(MAX_CC);
								XRCCTRL(*this, "wsc_low_row_cc_for_x_y_z_y", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_LOWROW_XYZ_Y(m_Split));
				XRCCTRL(*this, "wsc_low_row_cc_for_x_y_z_y", wxSpinCtrl)->SetMin(MIN_CC);
				XRCCTRL(*this, "wsc_low_row_cc_for_x_y_z_y", wxSpinCtrl)->SetMax(MAX_CC);
								XRCCTRL(*this, "wsc_cc_for_low_row_x_y_z_z", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_LOWROW_XYZ_Z(m_Split));
				XRCCTRL(*this, "wsc_cc_for_low_row_x_y_z_z", wxSpinCtrl)->SetMin(MIN_CC);
				XRCCTRL(*this, "wsc_cc_for_low_row_x_y_z_z", wxSpinCtrl)->SetMax(MAX_CC);
}


void PerSplitDialog::InitFadersPage()
{
	XRCCTRL(*this, "wsc_cc_for_fader_1", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_FADER1(m_Split));
	XRCCTRL(*this, "wsc_cc_for_fader_1", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_1", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_2", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_FADER2(m_Split));
	XRCCTRL(*this, "wsc_cc_for_fader_2", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_2", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_3", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_FADER3(m_Split));
	XRCCTRL(*this, "wsc_cc_for_fader_3", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_3", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_4", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_FADER4(m_Split));
	XRCCTRL(*this, "wsc_cc_for_fader_4", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_4", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_5", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_FADER5(m_Split));
	XRCCTRL(*this, "wsc_cc_for_fader_5", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_5", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_6", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_FADER6(m_Split));
	XRCCTRL(*this, "wsc_cc_for_fader_6", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_6", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_7", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_FADER7(m_Split));
	XRCCTRL(*this, "wsc_cc_for_fader_7", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_7", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_8", wxSpinCtrl)->SetValue(pMyLinnStrument->GetCC_FOR_FADER8(m_Split));
	XRCCTRL(*this, "wsc_cc_for_fader_8", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_cc_for_fader_8", wxSpinCtrl)->SetMax(MAX_CC);
}


void 	PerSplitDialog::InitSpecialPage()
{
	XRCCTRL(*this, "wrb_special", wxRadioBox)->SetSelection(pMyLinnStrument->GetSPECIAL(m_Split));
}


// Event handlers

// MIDI page

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


// Bend page

void PerSplitDialog::OnBEND_RANGE(wxSpinEvent& event)
{
	pMyLinnStrument->SetBEND_RANGE(XRCCTRL(*this, "wsc_bend_range", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_BEND_RANGE_NRPN, pMyLinnStrument->GetBEND_RANGE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_BEND_RANGE_NRPN, pMyLinnStrument->GetBEND_TOGGLE(m_Split));
	}
}


void PerSplitDialog::OnBEND_TOGGLE(wxCommandEvent& event)
{
	pMyLinnStrument->SetBEND_TOGGLE(LinnStrument::LSToggle(XRCCTRL(*this, "chk_send_bend", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_BEND_TOGGLE_NRPN, pMyLinnStrument->GetBEND_TOGGLE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_BEND_TOGGLE_NRPN, pMyLinnStrument->GetBEND_TOGGLE(m_Split));
	}
}


void PerSplitDialog::OnBEND_QUANTIZE_TOGGLE(wxCommandEvent& event)
{
	pMyLinnStrument->SetBEND_QUANTIZE_TOGGLE(LinnStrument::LSToggle(XRCCTRL(*this, "chk_bend_quantize", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN, pMyLinnStrument->GetBEND_QUANTIZE_TOGGLE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_BEND_QUANTIZE_TOGGLE_NRPN, pMyLinnStrument->GetBEND_QUANTIZE_TOGGLE(m_Split));
	}
}


void PerSplitDialog::OnBendQuantize(wxCommandEvent& event)
{
	pMyLinnStrument->SetBEND_QUANTIZE(XRCCTRL(*this, "wrb_bend_quantize", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_PITCH_QUANTIZE_NRPN, pMyLinnStrument->GetBEND_QUANTIZE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_PITCH_QUANTIZE_NRPN, pMyLinnStrument->GetBEND_QUANTIZE(m_Split));
	}
}


void PerSplitDialog::OnRESET_PITCH_ON_RELEASE(wxCommandEvent& event)
{
	pMyLinnStrument->SetRESET_PITCH_ON_RELEASE(LinnStrument::LSToggle(XRCCTRL(*this, "chk_reset_pitch_on_release", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN, pMyLinnStrument->GetRESET_PITCH_ON_RELEASE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN, pMyLinnStrument->GetRESET_PITCH_ON_RELEASE(m_Split));
	}
}


// Axes page

void PerSplitDialog::OnSEND_Y(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEND_Y(LinnStrument::LSToggle(XRCCTRL(*this, "chk_send_y", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEND_Y_NRPN, pMyLinnStrument->GetSEND_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEND_Y_NRPN, pMyLinnStrument->GetSEND_Y(m_Split));
	}
}


void PerSplitDialog::OnCC_FOR_Y(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_Y(XRCCTRL(*this, "wsc_cc_for_y", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_Y_NRPN, pMyLinnStrument->GetCC_FOR_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_Y_NRPN, pMyLinnStrument->GetCC_FOR_Y(m_Split));
	}
}


void PerSplitDialog::OnMIN_CC_FOR_Y(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIN_CC_FOR_Y(XRCCTRL(*this, "wsc_min_cc_for_y", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MIN_CC_FOR_Y_NRPN, pMyLinnStrument->GetMIN_CC_FOR_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN, pMyLinnStrument->GetMIN_CC_FOR_Y(m_Split));
	}
}


void PerSplitDialog::OnMAX_CC_FOR_Y(wxSpinEvent& event)
{
	pMyLinnStrument->SetMAX_CC_FOR_Y(XRCCTRL(*this, "wsc_max_cc_for_y", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MAX_CC_FOR_Y_NRPN, pMyLinnStrument->GetMAX_CC_FOR_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN, pMyLinnStrument->GetMAX_CC_FOR_Y(m_Split));
	}
}


void PerSplitDialog::OnRELATIVE_Y(wxCommandEvent& event)
{
	pMyLinnStrument->SetRELATIVE_Y(LinnStrument::LSToggle(XRCCTRL(*this, "chk_relative_y", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_RELATIVE_Y_NRPN, pMyLinnStrument->GetRELATIVE_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_RELATIVE_Y_NRPN, pMyLinnStrument->GetRELATIVE_Y(m_Split));
	}
}


void PerSplitDialog::OnEXPRESSION_FOR_Y(wxCommandEvent& event)
{
	pMyLinnStrument->SetEXPRESSION_FOR_Y(XRCCTRL(*this, "wrb_expression_for_y", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN, pMyLinnStrument->GetEXPRESSION_FOR_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN, pMyLinnStrument->GetEXPRESSION_FOR_Y(m_Split));
	}
}


void PerSplitDialog::OnINITIAL_RELATIVE_VALUE_FOR_Y(wxSpinEvent& event)
{
	pMyLinnStrument->SetINITIAL_RELATIVE_VALUE_FOR_Y(XRCCTRL(*this, "wsc_initial_relative_value_for_y", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN, pMyLinnStrument->GetINITIAL_RELATIVE_VALUE_FOR_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN, pMyLinnStrument->GetINITIAL_RELATIVE_VALUE_FOR_Y(m_Split));
	}
}


void PerSplitDialog::OnSEND_Z(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEND_Z(LinnStrument::LSToggle(XRCCTRL(*this, "chk_send_z", wxCheckBox)->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEND_Z_NRPN, pMyLinnStrument->GetSEND_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEND_Z_NRPN, pMyLinnStrument->GetSEND_Z(m_Split));
	}
}


void PerSplitDialog::OnCC_FOR_Z(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_Z(XRCCTRL(*this, "wsc_cc_for_z", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_Z_NRPN, pMyLinnStrument->GetCC_FOR_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_Z_NRPN, pMyLinnStrument->GetCC_FOR_Z(m_Split));
	}
}


void PerSplitDialog::OnMIN_CC_FOR_Z(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIN_CC_FOR_Z(XRCCTRL(*this, "wsc_min_cc_for_z", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MIN_CC_FOR_Z_NRPN, pMyLinnStrument->GetMIN_CC_FOR_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN, pMyLinnStrument->GetMIN_CC_FOR_Z(m_Split));
	}
}


void PerSplitDialog::OnMAX_CC_FOR_Z(wxSpinEvent& event)
{
	pMyLinnStrument->SetMAX_CC_FOR_Y(XRCCTRL(*this, "wsc_max_cc_for_z", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MAX_CC_FOR_Z_NRPN, pMyLinnStrument->GetMAX_CC_FOR_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN, pMyLinnStrument->GetMAX_CC_FOR_Z(m_Split));
	}
}


/*
void PerSplitDialog::OnRELATIVE_Z(wxCommandEvent& event)
{
	pMyLinnStrument->SetRELATIVE_Z(LinnStrument::LSToggle(chkRELATIVE_Z->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_REL, pMyLinnStrument->GetRELATIVE_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_RELATIVE_Z_NRPN, pMyLinnStrument->GetRELATIVE_Z(m_Split));
	}
}
*/


void PerSplitDialog::OnEXPRESSION_FOR_Z(wxCommandEvent& event)
{
	pMyLinnStrument->SetEXPRESSION_FOR_Z(XRCCTRL(*this, "wrb_expression_for_z", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN, pMyLinnStrument->GetEXPRESSION_FOR_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN, pMyLinnStrument->GetEXPRESSION_FOR_Z(m_Split));
	}
}


void PerSplitDialog::On14BIT_CC_VALUE_FOR_Z(wxSpinEvent& event)
{
	pMyLinnStrument->Set14BIT_CC_VALUE_FOR_Z(XRCCTRL(*this, "wsc_14bit_cc_value_for_z", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN, pMyLinnStrument->Get14BIT_CC_VALUE_FOR_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN, pMyLinnStrument->Get14BIT_CC_VALUE_FOR_Z(m_Split));
	}
}


// Colors page

void PerSplitDialog::OnCOLOR_MAIN(wxCommandEvent& event)
{
	pMyLinnStrument->SetCOLOR_MAIN(XRCCTRL(*this, "wrb_color_main", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_COLOR_MAIN_NRPN, pMyLinnStrument->GetCOLOR_MAIN(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_COLOR_MAIN_NRPN, pMyLinnStrument->GetCOLOR_MAIN(m_Split));
	}
}


void PerSplitDialog::OnCOLOR_ACCENT(wxCommandEvent& event)
{
	pMyLinnStrument->SetCOLOR_ACCENT(XRCCTRL(*this, "wrb_color_accent", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_COLOR_ACCENT_NRPN, pMyLinnStrument->GetCOLOR_ACCENT(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_COLOR_ACCENT_NRPN, pMyLinnStrument->GetCOLOR_ACCENT(m_Split));
	}
}


void PerSplitDialog::OnCOLOR_PLAYED(wxCommandEvent& event)
{
	pMyLinnStrument->SetCOLOR_PLAYED(XRCCTRL(*this, "wrb_color_played", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_COLOR_PLAYED_NRPN, pMyLinnStrument->GetCOLOR_PLAYED(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_COLOR_PLAYED_NRPN, pMyLinnStrument->GetCOLOR_PLAYED(m_Split));
	}
}

void PerSplitDialog::OnCOLOR_LOWROW(wxCommandEvent& event)
{
	pMyLinnStrument->SetCOLOR_LOWROW(XRCCTRL(*this, "wrb_color_low_row", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_COLOR_LOWROW_NRPN, pMyLinnStrument->GetCOLOR_LOWROW(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_COLOR_LOWROW_NRPN, pMyLinnStrument->GetCOLOR_LOWROW(m_Split));
	}
}


void PerSplitDialog::OnAnimation(wxCommandEvent& event)
{
	pMyLinnStrument->SetTOUCH_ANIMATION(XRCCTRL(*this, "wrb_touch_animation", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_TOUCH_ANIMATION_NRPN, pMyLinnStrument->GetTOUCH_ANIMATION(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_TOUCH_ANIMATION_NRPN, pMyLinnStrument->GetTOUCH_ANIMATION(m_Split));
	}
}


// Low row page

void PerSplitDialog::OnCC_FOR_LOWROW(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_LOWROW(XRCCTRL(*this, "wsc_cc_for_low_row", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_LOWROW_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW(m_Split));
	}
}


void PerSplitDialog::OnCC_FOR_LOWROW_XYZ(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_LOWROW_XYZ(XRCCTRL(*this, "wsc_cc_for_x_y_z", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ(m_Split));
	}
}


void PerSplitDialog::OnCC_FOR_LOWROW_XYZ_Y(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_LOWROW_XYZ_Y(XRCCTRL(*this, "wsc_low_row_cc_for_x_y_z_y", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Y_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ_Y(m_Split));
	}
}


void PerSplitDialog::OnCC_FOR_LOWROW_XYZ_Z(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_LOWROW_XYZ_Z(XRCCTRL(*this, "wsc_low_row_cc_for_x_y_z_z", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_LOWROW_XYZ_Z_NRPN, pMyLinnStrument->GetCC_FOR_LOWROW_XYZ_Z(m_Split));
	}
}


void PerSplitDialog::OnLOWROW_X_BEHAVIOUR(wxCommandEvent& event)
{
	pMyLinnStrument->SetLOWROW_X_BEHAVIOUR(XRCCTRL(*this, "wrb_low_row_x_behaviour", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN, pMyLinnStrument->GetLOWROW_X_BEHAVIOUR(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_LOWROW_X_BEHAVIOUR_NRPN, pMyLinnStrument->GetLOWROW_X_BEHAVIOUR(m_Split));
	}
}


void PerSplitDialog::OnLOWROW_XYZ_BEHAVIOUR(wxCommandEvent& event)
{
	pMyLinnStrument->SetLOWROW_XYZ_BEHAVIOUR(XRCCTRL(*this, "wrb_low_row_x_y_z_behaviour", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN, pMyLinnStrument->GetLOWROW_XYZ_BEHAVIOUR(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_LOWROW_XYZ_BEHAVIOUR_NRPN, pMyLinnStrument->GetLOWROW_XYZ_BEHAVIOUR(m_Split));
	}
}


void PerSplitDialog::OnLOWROW_MODE(wxCommandEvent& event)
{
	pMyLinnStrument->SetLOWROW_MODE(XRCCTRL(*this, "wrb_low_row_mode", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_LOWROW_MODE_NRPN, pMyLinnStrument->GetLOWROW_MODE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_LOWROW_MODE_NRPN, pMyLinnStrument->GetLOWROW_MODE(m_Split));
	}
}


// Faders page

void PerSplitDialog::OnCC_FOR_FADER1(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER1(XRCCTRL(*this, "wsc_cc_for_fader_1", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER1_NRPN, pMyLinnStrument->GetCC_FOR_FADER1(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER1_NRPN, pMyLinnStrument->GetCC_FOR_FADER1(m_Split));
	}
}


void PerSplitDialog::OnCC_FOR_FADER2(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER2(XRCCTRL(*this, "wsc_cc_for_fader_2", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER2_NRPN, pMyLinnStrument->GetCC_FOR_FADER2(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER2_NRPN, pMyLinnStrument->GetCC_FOR_FADER2(m_Split));
	}
	}


void PerSplitDialog::OnCC_FOR_FADER3(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER3(XRCCTRL(*this, "wsc_cc_for_fader_3", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER3_NRPN, pMyLinnStrument->GetCC_FOR_FADER3(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER3_NRPN, pMyLinnStrument->GetCC_FOR_FADER3(m_Split));
	}
}


void PerSplitDialog::OnCC_FOR_FADER4(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER4(XRCCTRL(*this, "wsc_cc_for_fader_4", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER4_NRPN, pMyLinnStrument->GetCC_FOR_FADER4(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER4_NRPN, pMyLinnStrument->GetCC_FOR_FADER4(m_Split));
	}
}


void PerSplitDialog::OnCC_FOR_FADER5(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER5(XRCCTRL(*this, "wsc_cc_for_fader_5", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER5_NRPN, pMyLinnStrument->GetCC_FOR_FADER5(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER5_NRPN, pMyLinnStrument->GetCC_FOR_FADER5(m_Split));
	}
}


void PerSplitDialog::OnCC_FOR_FADER6(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER6(XRCCTRL(*this, "wsc_cc_for_fader_6", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER6_NRPN, pMyLinnStrument->GetCC_FOR_FADER6(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER6_NRPN, pMyLinnStrument->GetCC_FOR_FADER6(m_Split));
	}
}


void PerSplitDialog::OnCC_FOR_FADER7(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER7(XRCCTRL(*this, "wsc_cc_for_fader_7", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER7_NRPN, pMyLinnStrument->GetCC_FOR_FADER7(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER7_NRPN, pMyLinnStrument->GetCC_FOR_FADER7(m_Split));
	}
}


void PerSplitDialog::OnCC_FOR_FADER8(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_FADER8(XRCCTRL(*this, "wsc_cc_for_fader_8", wxSpinCtrl)->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_FADER8_NRPN, pMyLinnStrument->GetCC_FOR_FADER8(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_FADER8_NRPN, pMyLinnStrument->GetCC_FOR_FADER8(m_Split));
	}
}


// Special page

void PerSplitDialog::OnSpecial(wxCommandEvent& event)
{
	pMyLinnStrument->SetSPECIAL(XRCCTRL(*this, "wrb_special", wxRadioBox)->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SPECIAL_NRPN, pMyLinnStrument->GetSPECIAL(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SPECIAL_NRPN, pMyLinnStrument->GetSPECIAL(m_Split));
	}
}


BEGIN_EVENT_TABLE(PerSplitDialog, wxDialog)
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

// Bend page
EVT_CHECKBOX(XRCID( "chk_send_bend"), PerSplitDialog::OnBEND_TOGGLE)
EVT_CHECKBOX(XRCID("chk_bend_quantize"), PerSplitDialog::OnBEND_QUANTIZE_TOGGLE)
EVT_CHECKBOX(XRCID("chk_reset_pitch_on_release"), PerSplitDialog::OnRESET_PITCH_ON_RELEASE)
EVT_SPINCTRL(XRCID("wsc_bend_range"), PerSplitDialog::OnBEND_RANGE)
EVT_RADIOBOX(XRCID("wrb_bend_quantize"), PerSplitDialog::OnBendQuantize)

// Axes page
EVT_CHECKBOX(XRCID("chk_send_y"), PerSplitDialog::OnSEND_Y)
EVT_CHECKBOX(XRCID("chk_relative_y"), PerSplitDialog::OnRELATIVE_Y)
EVT_CHECKBOX(XRCID("chk_send_z"), PerSplitDialog::OnSEND_Z)
// EVT_CHECKBOX(RELATIVE_Z_ID, PerSplitDialog::OnRELATIVE_Z)
EVT_SPINCTRL(XRCID("wsc_min_cc_for_y"), PerSplitDialog::OnMIN_CC_FOR_Y)
EVT_SPINCTRL(XRCID("wsc_max_cc_for_y"), PerSplitDialog::OnMAX_CC_FOR_Y)
EVT_SPINCTRL(XRCID("wsc_cc_for_y"), PerSplitDialog::OnCC_FOR_Y)
EVT_SPINCTRL(XRCID("wsc_initial_relative_value_for_y"), PerSplitDialog::OnINITIAL_RELATIVE_VALUE_FOR_Y)
EVT_SPINCTRL(XRCID("wsc_min_cc_for_z"), PerSplitDialog::OnMIN_CC_FOR_Z)
EVT_SPINCTRL(XRCID("wsc_max_cc_for_z"), PerSplitDialog::OnMAX_CC_FOR_Z)
EVT_SPINCTRL(XRCID("wsc_cc_for_z"), PerSplitDialog::OnCC_FOR_Z)
EVT_SPINCTRL(XRCID("wsc_14bit_cc_value_for_z"), PerSplitDialog::On14BIT_CC_VALUE_FOR_Z)
EVT_RADIOBOX(XRCID("wrb_expression_for_y"), PerSplitDialog::OnEXPRESSION_FOR_Y)
EVT_RADIOBOX(XRCID("wrb_expression_for_z"), PerSplitDialog::OnEXPRESSION_FOR_Z)

// Colors page
EVT_RADIOBOX(XRCID("wrb_color_main"), PerSplitDialog::OnCOLOR_MAIN)
EVT_RADIOBOX(XRCID("wrb_color_accent"), PerSplitDialog::OnCOLOR_ACCENT)
EVT_RADIOBOX(XRCID("wrb_color_played"), PerSplitDialog::OnCOLOR_PLAYED)
EVT_RADIOBOX(XRCID("wrb_color_low_row"), PerSplitDialog::OnCOLOR_LOWROW)
EVT_RADIOBOX(XRCID("wrb_touch_animation"), PerSplitDialog::OnAnimation)

// Low row page
EVT_SPINCTRL(XRCID("wsc_cc_for_low_row"), PerSplitDialog::OnCC_FOR_LOWROW)
EVT_SPINCTRL(XRCID("wsc_cc_for_x_y_z"), PerSplitDialog::OnCC_FOR_LOWROW_XYZ)
EVT_SPINCTRL(XRCID( "wsc_low_row_cc_for_x_y_z_y"), PerSplitDialog::OnCC_FOR_LOWROW_XYZ_Y)
EVT_SPIN(XRCID("wsc_cc_for_low_row_x_y_z_z"), PerSplitDialog::OnCC_FOR_LOWROW_XYZ_Z)
EVT_RADIOBOX(XRCID( "wrb_low_row_x_y_z_behaviour"), PerSplitDialog::OnLOWROW_XYZ_BEHAVIOUR)
EVT_RADIOBOX(XRCID("wrb_low_row_x_behaviour"), PerSplitDialog::OnLOWROW_X_BEHAVIOUR)
EVT_RADIOBOX(XRCID( "wrb_low_row_mode"), PerSplitDialog::OnLOWROW_MODE)

// Faders page
EVT_SPINCTRL(XRCID("wsc_cc_for_fader_1"), PerSplitDialog::OnCC_FOR_FADER1)
EVT_SPINCTRL(XRCID("wsc_cc_for_fader_2"), PerSplitDialog::OnCC_FOR_FADER2)
EVT_SPINCTRL(XRCID("wsc_cc_for_fader_3"), PerSplitDialog::OnCC_FOR_FADER3)
EVT_SPINCTRL(XRCID("wsc_cc_for_fader_4"), PerSplitDialog::OnCC_FOR_FADER4)
EVT_SPINCTRL(XRCID("wsc_cc_for_fader_5"), PerSplitDialog::OnCC_FOR_FADER5)
EVT_SPINCTRL(XRCID("wsc_cc_for_fader_6"), PerSplitDialog::OnCC_FOR_FADER6)
EVT_SPINCTRL(XRCID("wsc_cc_for_fader_7"), PerSplitDialog::OnCC_FOR_FADER7)
EVT_SPINCTRL(XRCID("wsc_cc_for_fader_8"), PerSplitDialog::OnCC_FOR_FADER8)

// Special page
EVT_RADIOBOX(XRCID("wrb_special"), PerSplitDialog::OnSpecial)
END_EVENT_TABLE()
