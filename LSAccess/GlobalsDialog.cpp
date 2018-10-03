// GlobalsDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "GlobalsDialog.h"


GlobalsDialog::GlobalsDialog(wxWindow* parent, const wxString& title, LinnStrument * pLinnStrument)
	: wxDialog(NULL, wxID_ANY, title),
	pMyLinnStrument( pLinnStrument)
{
	if (wxXmlResource::Get()->LoadDialog(this, parent, wxT("globals_dialog")))
	{
		this->SetWindowStyle(wxCAPTION | wxRESIZE_BORDER | wxCLOSE_BOX | wxMAXIMIZE_BOX | wxMINIMIZE_BOX);
		InitSplitPage();
		InitNoteLightsPage();
		InitAccentNoteLightsPage();
		InitArpPage();
		InitPowerMIDIPage();
		InitRowTuningsPage();
		InitVelocityPressurePage();
			}
else
	{
	wxMessageBox("Could not load Global Settings dialog from XRC", wstrErrorTitle, wxOK | wxICON_ERROR);
	EndModal(false);
	}
}


void GlobalsDialog::InitSplitPage()
{
	XRCCTRL(*this, "chk_global_split_active", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_SPLIT_ACTIVE());
		XRCCTRL(*this, "wsc_global_split_column", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_SPLIT_COLUMN());
	XRCCTRL(*this, "wsc_global_split_column", wxSpinCtrl)->SetMin(MIN_SPLIT_COLUMN);
	XRCCTRL(*this, "wsc_global_split_column", wxSpinCtrl)->SetMax(MAX_SPLIT_COLUMN);
		XRCCTRL(*this, "chk_device_left_handed", wxCheckBox)->SetValue(pMyLinnStrument->GetDEVICE_LEFT_HANDED());
		}


void GlobalsDialog::InitNoteLightsPage()
{
	XRCCTRL(*this, "wsc_global_active_note_lights_preset", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_ACTIVE_LIGHTS_PRESET());
	XRCCTRL(*this, "wsc_global_active_note_lights_preset", wxSpinCtrl)->SetMin(MIN_LIGHTS_PRESET);
	XRCCTRL(*this, "wsc_global_active_note_lights_preset", wxSpinCtrl)->SetMax(MAX_LIGHTS_PRESET);
		XRCCTRL(*this, "chk_global_main_note_light_c", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_C());
			XRCCTRL(*this, "chk_global_main_note_light_c_sharp", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_C_SHARP());
						XRCCTRL(*this, "chk_global_main_note_light_d", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_D());
			XRCCTRL(*this, "chk_global_main_note_light_d_sharp", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_D_SHARP());
						XRCCTRL(*this, "chk_global_main_note_light_e", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_E());
												XRCCTRL(*this, "chk_global_main_note_light_f", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_F());
																								XRCCTRL(*this, "chk_global_main_note_light_f_sharp", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_F_SHARP());
																																																																								XRCCTRL(*this, "chk_global_main_note_light_g", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_G());
																								XRCCTRL(*this, "chk_global_main_note_light_g_sharp", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_G_SHARP());
																																																XRCCTRL(*this, "chk_global_main_note_light_a", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_A());
																								XRCCTRL(*this, "chk_global_main_note_light_a_sharp", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_A_SHARP());
																																																XRCCTRL(*this, "chk_global_main_note_light_b", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_B());
}


void GlobalsDialog::InitAccentNoteLightsPage()
{
	XRCCTRL(*this, "chk_global_accent_note_light_c", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_C());
XRCCTRL(*this, "chk_global_accent_note_light_c_sharp", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP());
XRCCTRL(*this, "chk_global_accent_note_light_d", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_D());
XRCCTRL(*this, "chk_global_accent_note_light_d_sharp", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP());
XRCCTRL(*this, "chk_global_accent_note_light_e", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_E());
XRCCTRL(*this, "chk_global_accent_note_light_f", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_F());
XRCCTRL(*this, "chk_global_accent_note_light_f_sharp", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP());
XRCCTRL(*this, "chk_global_accent_note_light_g", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_G());
XRCCTRL(*this, "chk_global_accent_note_light_g_sharp", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP());
XRCCTRL(*this, "chk_global_accent_note_light_a", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_A());
XRCCTRL(*this, "chk_global_accent_note_light_a_sharp", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP());
XRCCTRL(*this, "chk_global_accent_note_light_b", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_B());
}


void GlobalsDialog::InitArpPage()
{
	XRCCTRL(*this, "wsc_global_clock_bpm", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_CLOCK_BPM());
	XRCCTRL(*this, "wsc_global_clock_bpm", wxSpinCtrl)->SetMin(MIN_TEMPO);
	XRCCTRL(*this, "wsc_global_clock_bpm", wxSpinCtrl)->SetMax(MAX_TEMPO);
		XRCCTRL(*this, "wrb_global_arp_direction", wxRadioBox)->SetSelection(pMyLinnStrument->GetGLOBAL_ARP_DIRECTION());
				XRCCTRL(*this, "wrb_global_arp_tempo_note_value", wxRadioBox)->SetSelection(pMyLinnStrument->GetGLOBAL_ARP_TEMPO_NOTE_VALUE());
								XRCCTRL(*this, "wrb_global_arp_octave_extension", wxRadioBox)->SetSelection(pMyLinnStrument->GetGLOBAL_ARP_OCTAVE_EXTENSION());
}


void GlobalsDialog::InitPowerMIDIPage()
{
	XRCCTRL(*this, "wrb_global_midi_device_io", wxRadioBox)->SetSelection(pMyLinnStrument->GetGLOBAL_MIDI_DEVICE_IO());
	XRCCTRL(*this, "chk_device_midi_thru", wxCheckBox)->SetValue(pMyLinnStrument->GetDEVICE_MIDI_THRU());
	XRCCTRL(*this, "wsc_device_min_byte_interval_value", wxSpinCtrl)->SetValue(pMyLinnStrument->GetDEVICE_MIN_BYTE_INTERVAL_VALUE());
	XRCCTRL(*this, "wsc_device_min_byte_interval_value", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_device_min_byte_interval_value", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "chk_device_user_firmware_mode", wxCheckBox)->SetValue(pMyLinnStrument->GetDEVICE_USER_FIRMWARE_MODE());
	}


void GlobalsDialog::InitRowTuningsPage()
{
	XRCCTRL(*this, "wrb_global_row_offset", wxRadioBox)->SetSelection(pMyLinnStrument->GetGLOBAL_ROW_OFFSET());
		XRCCTRL(*this, "wrb_global_custom_row_offset", wxRadioBox)->SetSelection(pMyLinnStrument->GetGLOBAL_CUSTOM_ROW_OFFSET());
				XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_1", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW1());
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_1", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_1", wxSpinCtrl)->SetMax(MAX_CC);
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_2", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW2());
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_2", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_2", wxSpinCtrl)->SetMax(MAX_CC);
						XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_3", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW3());
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_3", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_3", wxSpinCtrl)->SetMax(MAX_CC);
				XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_4", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW4());
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_4", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_4", wxSpinCtrl)->SetMax(MAX_CC);
				XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_5", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW5());
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_5", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_5", wxSpinCtrl)->SetMax(MAX_CC);
				XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_6", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW6());
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_6", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_6", wxSpinCtrl)->SetMax(MAX_CC);
				XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_7", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW7());
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_7", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_7", wxSpinCtrl)->SetMax(MAX_CC);
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_8", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW8());
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_8", wxSpinCtrl)->SetMin(MIN_CC);
		XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_8", wxSpinCtrl)->SetMax(MAX_CC);
}


void GlobalsDialog::InitVelocityPressurePage()
{
	XRCCTRL(*this, "wrb_global_velocity_sensitivity", wxRadioBox)->SetSelection(pMyLinnStrument->GetGLOBAL_VELOCITY_SENSITIVITY());
		XRCCTRL(*this, "wsc_global_min_velocity_value", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_MIN_VELOCITY_VALUE());
	XRCCTRL(*this, "wsc_global_min_velocity_value", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_global_min_velocity_value", wxSpinCtrl)->SetMax(MAX_CC);
		XRCCTRL(*this, "wsc_global_max_velocity_value", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_MAX_VELOCITY_VALUE());
	XRCCTRL(*this, "wsc_global_max_velocity_value", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_global_max_velocity_value", wxSpinCtrl)->SetMax(MAX_CC);
		XRCCTRL(*this, "wsc_global_fixed_velocity_value", wxSpinCtrl)->SetValue(pMyLinnStrument->GetGLOBAL_FIXED_VELOCITY_VALUE());
	XRCCTRL(*this, "wsc_global_fixed_velocity_value", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_global_fixed_velocity_value", wxSpinCtrl)->SetMax(MAX_CC);
		XRCCTRL(*this, "wrb_global_pressure_sensitivity", wxRadioBox)->SetSelection(pMyLinnStrument->GetGLOBAL_PRESSURE_SENSITIVITY());
		XRCCTRL(*this, "chk_global_pressure_aftertouch", wxCheckBox)->SetValue(pMyLinnStrument->GetGLOBAL_PRESSURE_AFTERTOUCH());
		}


// Event handlers

// Split page

void GlobalsDialog::OnGLOBAL_SPLIT_ACTIVE(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_SPLIT_ACTIVE(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_split_active", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_SPLIT_ACTIVE_NRPN, pMyLinnStrument->GetGLOBAL_SPLIT_ACTIVE());
}


void GlobalsDialog::OnDEVICE_LEFT_HANDED(wxCommandEvent& event)
{
	pMyLinnStrument->SetDEVICE_LEFT_HANDED(LinnStrument::LSToggle(XRCCTRL(*this, "chk_device_left_handed", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(DEVICE_LEFT_HANDED_NRPN, pMyLinnStrument->GetDEVICE_LEFT_HANDED());
}


void GlobalsDialog::OnGLOBAL_SPLIT_COLUMN(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_SPLIT_COLUMN(XRCCTRL(*this, "wsc_global_split_column", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_SPLIT_COLUMN_NRPN, pMyLinnStrument->GetGLOBAL_SPLIT_COLUMN());
}


// Note lights page

void GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_C(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAIN_NOTE_LIGHT_C(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_main_note_light_c", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_MAIN_NOTE_LIGHT_C_NRPN, pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_C());
}


void GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_C_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAIN_NOTE_LIGHT_C_SHARP(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_main_note_light_c_sharp", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_NRPN, pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_C_SHARP());
}


void GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_D(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAIN_NOTE_LIGHT_D(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_main_note_light_d", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_MAIN_NOTE_LIGHT_D_NRPN, pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_D());
}


void GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_D_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAIN_NOTE_LIGHT_D_SHARP(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_main_note_light_d_sharp", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_NRPN, pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_D_SHARP());
}


void GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_E(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAIN_NOTE_LIGHT_E(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_main_note_light_e", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_MAIN_NOTE_LIGHT_E_NRPN, pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_E());
}


void GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_F(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAIN_NOTE_LIGHT_F(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_main_note_light_f", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_MAIN_NOTE_LIGHT_F_NRPN, pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_F());
}


void GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_F_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAIN_NOTE_LIGHT_F_SHARP(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_main_note_light_f_sharp", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_NRPN, pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_F_SHARP());
}


void GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_G(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAIN_NOTE_LIGHT_G(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_main_note_light_g", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_MAIN_NOTE_LIGHT_G_NRPN, pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_G());
}


void GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_G_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAIN_NOTE_LIGHT_G_SHARP(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_main_note_light_g_sharp", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_NRPN, pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_G_SHARP());
}


void GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_A(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAIN_NOTE_LIGHT_A(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_main_note_light_a", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_MAIN_NOTE_LIGHT_A_NRPN, pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_A());
}


void GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_A_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAIN_NOTE_LIGHT_A_SHARP(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_main_note_light_a_sharp", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_NRPN, pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_A_SHARP());
}


void GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_B(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAIN_NOTE_LIGHT_B(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_main_note_light_b", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_MAIN_NOTE_LIGHT_B_NRPN, pMyLinnStrument->GetGLOBAL_MAIN_NOTE_LIGHT_B());
}


void GlobalsDialog::OnGLOBAL_ACTIVE_LIGHTS_PRESET(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACTIVE_LIGHTS_PRESET(XRCCTRL(*this, "wsc_global_active_note_lights_preset", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_ACTIVE_LIGHTS_PRESET_NRPN, pMyLinnStrument->GetGLOBAL_ACTIVE_LIGHTS_PRESET());
}


// Accent note lights page

void GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_C(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_C(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_accent_note_light_c", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_ACCENT_NOTE_LIGHT_C_NRPN, pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_C());
}


void GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_accent_note_light_c_sharp", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_NRPN, pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP());
}


void GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_D(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_D(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_accent_note_light_d", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_ACCENT_NOTE_LIGHT_D_NRPN, pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_D());
}


void GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_accent_note_light_d_sharp", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_NRPN, pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP());
}


void GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_E(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_E(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_accent_note_light_e", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_ACCENT_NOTE_LIGHT_E_NRPN, pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_E());
}


void GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_F(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_F(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_accent_note_light_f", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_ACCENT_NOTE_LIGHT_F_NRPN, pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_F());
}


void GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_accent_note_light_f_sharp", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_NRPN, pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP());
}


void GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_G(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_G(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_accent_note_light_g", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_ACCENT_NOTE_LIGHT_G_NRPN, pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_G());
}


void GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_accent_note_light_g_sharp", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_NRPN, pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP());
}


void GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_A(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_A(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_accent_note_light_a", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_ACCENT_NOTE_LIGHT_A_NRPN, pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_A());
}


void GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_accent_note_light_a_sharp", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_NRPN, pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP());
}


void GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_B(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_B(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_accent_note_light_b", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_ACCENT_NOTE_LIGHT_B_NRPN, pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_B());
}


// Arp page

void GlobalsDialog::OnGLOBAL_ARP_DIRECTION(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ARP_DIRECTION(XRCCTRL(*this, "wrb_global_arp_direction", wxRadioBox)->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_ARP_DIRECTION_NRPN, pMyLinnStrument->GetGLOBAL_ARP_DIRECTION());
}


void GlobalsDialog::OnGLOBAL_ARP_TEMPO_NOTE_VALUE(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ARP_TEMPO_NOTE_VALUE(LinnStrument::IntToLSArpTempoNoteType(XRCCTRL(*this, "wrb_global_arp_tempo_note_value", wxRadioBox)->GetSelection()));
	pMyLinnStrument->SendNRPN(GLOBAL_ARP_TEMPO_NOTE_VALUE_NRPN, pMyLinnStrument->GetGLOBAL_ARP_TEMPO_NOTE_VALUE());
}


void GlobalsDialog::OnGLOBAL_ARP_OCTAVE_EXTENSION(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ARP_OCTAVE_EXTENSION(XRCCTRL(*this, "wrb_global_arp_octave_extension", wxRadioBox)->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_ARP_OCTAVE_EXTENSION_NRPN, pMyLinnStrument->GetGLOBAL_ARP_OCTAVE_EXTENSION());
}


void GlobalsDialog::OnGLOBAL_CLOCK_BPM(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_CLOCK_BPM(XRCCTRL(*this, "wsc_global_clock_bpm", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_CLOCK_BPM_NRPN, pMyLinnStrument->GetGLOBAL_CLOCK_BPM());
}


// Power/MIDI page

void GlobalsDialog::OnGLOBAL_MIDI_DEVICE_IO(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MIDI_DEVICE_IO(XRCCTRL(*this, "wrb_global_midi_device_io", wxRadioBox)->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_MIDI_DEVICE_IO_NRPN, pMyLinnStrument->GetGLOBAL_MIDI_DEVICE_IO());
}


void GlobalsDialog::OnDEVICE_MIDI_THRU(wxCommandEvent& event)
{
	pMyLinnStrument->SetDEVICE_MIDI_THRU(LinnStrument::LSToggle(XRCCTRL(*this, "chk_device_midi_thru", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(DEVICE_MIDI_THRU_NRPN, pMyLinnStrument->GetDEVICE_MIDI_THRU());
}


void GlobalsDialog::OnDEVICE_USER_FIRMWARE_MODE(wxCommandEvent& event)
{
	pMyLinnStrument->SetDEVICE_USER_FIRMWARE_MODE(LinnStrument::LSToggle(XRCCTRL(*this, "chk_device_user_firmware_mode", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(DEVICE_USER_FIRMWARE_MODE_NRPN, pMyLinnStrument->GetDEVICE_USER_FIRMWARE_MODE());
}


void GlobalsDialog::OnDEVICE_MIN_BYTE_INTERVAL_VALUE(wxSpinEvent& event)
{
	pMyLinnStrument->SetDEVICE_MIN_BYTE_INTERVAL_VALUE(XRCCTRL(*this, "wsc_device_min_byte_interval_value", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(DEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN, pMyLinnStrument->GetDEVICE_MIN_BYTE_INTERVAL_VALUE());
}


// Row tunings page

void GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW1(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW1(XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_1", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW1_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW1());
}


void GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW2(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW2(XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_2", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW2_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW2());
}


void GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW3(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW3(XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_3", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW3_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW3());
}


void GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW4(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW4(XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_4", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW4_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW4());
}


void GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW5(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW5(XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_5", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW5_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW5());
}


void GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW6(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW6(XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_6", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW6_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW6());
}


void GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW7(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW7(XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_7", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW7_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW7());
}


void GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW8(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_GUITAR_NOTE_TUNING_ROW8(XRCCTRL(*this, "wsc_global_guitar_note_tuning_row_8", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_GUITAR_NOTE_TUNING_ROW8_NRPN, pMyLinnStrument->GetGLOBAL_GUITAR_NOTE_TUNING_ROW8());
}


void GlobalsDialog::OnGLOBAL_ROW_OFFSET(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ROW_OFFSET(LinnStrument::IntToLSRowOffsetType(XRCCTRL(*this, "wrb_global_row_offset", wxRadioBox)->GetSelection()));
	pMyLinnStrument->SendNRPN(GLOBAL_ROW_OFFSET_NRPN, pMyLinnStrument->GetGLOBAL_ROW_OFFSET());
}


void GlobalsDialog::OnGLOBAL_CUSTOM_ROW_OFFSET(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_CUSTOM_ROW_OFFSET(XRCCTRL(*this, "wrb_global_custom_row_offset", wxRadioBox)->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_CUSTOM_ROW_OFFSET_ID, pMyLinnStrument->GetGLOBAL_CUSTOM_ROW_OFFSET());
}


// Velocity/Pressure page

void GlobalsDialog::OnGLOBAL_VELOCITY_SENSITIVITY(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_VELOCITY_SENSITIVITY(XRCCTRL(*this, "wrb_global_velocity_sensitivity", wxRadioBox)->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_VELOCITY_SENSITIVITY_NRPN, pMyLinnStrument->GetGLOBAL_VELOCITY_SENSITIVITY());
}


void GlobalsDialog::OnGLOBAL_PRESSURE_AFTERTOUCH(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_PRESSURE_AFTERTOUCH(LinnStrument::LSToggle(XRCCTRL(*this, "chk_global_pressure_aftertouch", wxCheckBox)->GetValue()));
	pMyLinnStrument->SendNRPN(GLOBAL_PRESSURE_AFTERTOUCH_NRPN, pMyLinnStrument->GetGLOBAL_PRESSURE_AFTERTOUCH());
}


void GlobalsDialog::OnGLOBAL_PRESSURE_SENSITIVITY(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_PRESSURE_SENSITIVITY(XRCCTRL(*this, "wrb_global_pressure_sensitivity", wxRadioBox)->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_PRESSURE_SENSITIVITY_NRPN, pMyLinnStrument->GetGLOBAL_PRESSURE_SENSITIVITY());
}


void GlobalsDialog::OnGLOBAL_FIXED_VELOCITY_VALUE(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_FIXED_VELOCITY_VALUE(XRCCTRL(*this, "wsc_global_fixed_velocity_value", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_FIXED_VELOCITY_VALUE_NRPN, pMyLinnStrument->GetGLOBAL_FIXED_VELOCITY_VALUE());
}


void GlobalsDialog::OnGLOBAL_MAX_VELOCITY_VALUE(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MAX_VELOCITY_VALUE(XRCCTRL(*this, "wsc_global_max_velocity_value", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_MAX_VELOCITY_VALUE_NRPN, pMyLinnStrument->GetGLOBAL_MAX_VELOCITY_VALUE());
}


void GlobalsDialog::OnGLOBAL_MIN_VELOCITY_VALUE(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MIN_VELOCITY_VALUE(XRCCTRL(*this, "wsc_global_min_velocity_value", wxSpinCtrl)->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_MIN_VELOCITY_VALUE_NRPN, pMyLinnStrument->GetGLOBAL_MIN_VELOCITY_VALUE());
}


// event table
BEGIN_EVENT_TABLE(GlobalsDialog, wxPanel)
// Split page
EVT_CHECKBOX(XRCID("chk_global_split_active"), GlobalsDialog::OnGLOBAL_SPLIT_ACTIVE)
EVT_CHECKBOX(XRCID("chk_device_left_handed"), GlobalsDialog::OnDEVICE_LEFT_HANDED)
EVT_SPINCTRL(XRCID("wsc_global_split_column"), GlobalsDialog::OnGLOBAL_SPLIT_COLUMN)

// Note lights page
EVT_SPINCTRL(XRCID("wsc_global_active_note_lights_preset"), GlobalsDialog::OnGLOBAL_ACTIVE_LIGHTS_PRESET)
EVT_CHECKBOX(XRCID("chk_global_main_note_light_c"), GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_C)
EVT_CHECKBOX(XRCID("chk_global_main_note_light_c_sharp"), GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_C_SHARP)
EVT_CHECKBOX(XRCID("chk_global_main_note_light_d"), GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_D)
EVT_CHECKBOX(XRCID("chk_global_main_note_light_d_sharp"), GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_D_SHARP)
EVT_CHECKBOX(XRCID("chk_global_main_note_light_e"), GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_E)
EVT_CHECKBOX(XRCID("chk_global_main_note_light_f"), GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_F)
EVT_CHECKBOX(XRCID("chk_global_main_note_light_f_sharp"), GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_F_SHARP)
EVT_CHECKBOX(XRCID("chk_global_main_note_light_g"), GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_G)
EVT_CHECKBOX(XRCID("chk_global_main_note_light_g_sharp"), GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_G_SHARP)
EVT_CHECKBOX(XRCID("chk_global_main_note_light_a"), GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_A)
EVT_CHECKBOX(XRCID("chk_global_main_note_light_a_sharp"), GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_A_SHARP)
EVT_CHECKBOX(XRCID("chk_global_main_note_light_b"), GlobalsDialog::OnGLOBAL_MAIN_NOTE_LIGHT_B)

// Accent note lights page
EVT_CHECKBOX(XRCID("chk_global_accent_note_light_c"), GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_C)
EVT_CHECKBOX(XRCID("chk_global_accent_note_light_c_sharp"), GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP)
EVT_CHECKBOX(XRCID("chk_global_accent_note_light_d"), GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_D)
EVT_CHECKBOX(XRCID("chk_global_accent_note_light_d_sharp"), GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP)
EVT_CHECKBOX(XRCID("chk_global_accent_note_light_e"), GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_E)
EVT_CHECKBOX(XRCID("chk_global_accent_note_light_f"), GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_F)
EVT_CHECKBOX(XRCID("chk_global_accent_note_light_f_sharp"), GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP)
EVT_CHECKBOX(XRCID("chk_global_accent_note_light_g"), GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_G)
EVT_CHECKBOX(XRCID("chk_global_accent_note_light_g_sharp"), GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP)
EVT_CHECKBOX(XRCID("chk_global_accent_note_light_a"), GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_A)
EVT_CHECKBOX(XRCID("chk_global_accent_note_light_a_sharp"), GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP)
EVT_CHECKBOX(XRCID("chk_global_accent_note_light_b"), GlobalsDialog::OnGLOBAL_ACCENT_NOTE_LIGHT_B)

// Arp page
EVT_SPINCTRL(XRCID("wsc_global_clock_bpm"), GlobalsDialog::OnGLOBAL_CLOCK_BPM)
EVT_RADIOBOX(XRCID("wrb_global_arp_direction"), GlobalsDialog::OnGLOBAL_ARP_DIRECTION)
EVT_RADIOBOX(XRCID("wrb_global_arp_tempo_note_value"), GlobalsDialog::OnGLOBAL_ARP_TEMPO_NOTE_VALUE)
EVT_RADIOBOX(XRCID("wrb_global_arp_octave_extension"), GlobalsDialog::OnGLOBAL_ARP_OCTAVE_EXTENSION)

// Power/MIDI page
EVT_CHECKBOX(XRCID("chk_device_midi_thru"), GlobalsDialog::OnDEVICE_MIDI_THRU)
EVT_CHECKBOX(XRCID("chk_device_user_firmware_mode"), GlobalsDialog::OnDEVICE_USER_FIRMWARE_MODE)
EVT_SPINCTRL(XRCID("wsc_device_min_byte_interval_value"), GlobalsDialog::OnDEVICE_MIN_BYTE_INTERVAL_VALUE)
EVT_RADIOBOX(XRCID("wrb_global_midi_device_io"), GlobalsDialog::OnGLOBAL_MIDI_DEVICE_IO)

// Row tunings page
EVT_SPINCTRL(XRCID("wsc_global_guitar_note_tuning_row_1"), GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW1)
EVT_SPINCTRL(XRCID("wsc_global_guitar_note_tuning_row_2"), GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW2)
EVT_SPINCTRL(XRCID("wsc_global_guitar_note_tuning_row_3"), GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW3)
EVT_SPINCTRL(XRCID("wsc_global_guitar_note_tuning_row_4"), GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW4)
EVT_SPINCTRL(XRCID("wsc_global_guitar_note_tuning_row_5"), GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW5)
EVT_SPINCTRL(XRCID("wsc_global_guitar_note_tuning_row_6"), GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW6)
EVT_SPINCTRL(XRCID("wsc_global_guitar_note_tuning_row_7"), GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW7)
EVT_SPINCTRL(XRCID("wsc_global_guitar_note_tuning_row_8"), GlobalsDialog::OnGLOBAL_GUITAR_NOTE_TUNING_ROW8)
EVT_RADIOBOX(XRCID("wrb_global_row_offset"), GlobalsDialog::OnGLOBAL_ROW_OFFSET)
EVT_RADIOBOX(XRCID("wrb_global_custom_row_offset"), GlobalsDialog::OnGLOBAL_CUSTOM_ROW_OFFSET)

// Velocity/Pressure page
EVT_SPINCTRL(XRCID("wsc_global_min_velocity_value"), GlobalsDialog::OnGLOBAL_MIN_VELOCITY_VALUE)
EVT_SPINCTRL(XRCID("wsc_global_max_velocity_value"), GlobalsDialog::OnGLOBAL_MAX_VELOCITY_VALUE)
EVT_SPINCTRL(XRCID("wsc_global_fixed_velocity_value"), GlobalsDialog::OnGLOBAL_FIXED_VELOCITY_VALUE)
EVT_RADIOBOX(XRCID("wrb_global_velocity_sensitivity"), GlobalsDialog::OnGLOBAL_VELOCITY_SENSITIVITY)
EVT_RADIOBOX(XRCID("wrb_global_pressure_sensitivity"), GlobalsDialog::OnGLOBAL_PRESSURE_SENSITIVITY)
EVT_CHECKBOX(XRCID( "chk_global_pressure_aftertouch"), GlobalsDialog::OnGLOBAL_PRESSURE_AFTERTOUCH)
END_EVENT_TABLE()
