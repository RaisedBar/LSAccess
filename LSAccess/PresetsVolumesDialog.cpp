// PresetsVolumesDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "PresetsVolumesDialog.h"


PresetsVolumesDialog::PresetsVolumesDialog(wxWindow* parent, LinnStrument * pLinnStrument)
	: wxDialog(NULL, wxID_ANY, L""),
	pMyLinnStrument(pLinnStrument)
{
	wxXmlResource::Get()->LoadDialog(this, parent, wxT( "presets_volumes_dialog"));
	InitLeft();
InitRight();
}


void PresetsVolumesDialog::InitLeft()
{
	XRCCTRL(*this, "wrb_left_global_settings_preset_load", wxRadioBox)->SetSelection(pMyLinnStrument->GetLSPresetNumber());
		XRCCTRL(*this, "wsc_left_program_number", wxSpinCtrl)->SetValue(pMyLinnStrument->GetMIDIProgram(LSSplitType::LEFT));
	XRCCTRL(*this, "wsc_left_program_number", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_left_program_number", wxSpinCtrl)->SetMax(MAX_CC);
		XRCCTRL(*this, "wsc_left_volume", wxSpinCtrl)->SetValue(pMyLinnStrument->GetMIDIVolume(LSSplitType::LEFT));
	XRCCTRL(*this, "wsc_left_volume", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_left_volume", wxSpinCtrl)->SetMax(MAX_CC);
}


void PresetsVolumesDialog::InitRight()
{
	XRCCTRL(*this, "wrb_right_global_settings_preset_load", wxRadioBox)->SetSelection(pMyLinnStrument->GetLSPresetNumber());
	XRCCTRL(*this, "wsc_right_program_number", wxSpinCtrl)->SetValue(pMyLinnStrument->GetMIDIProgram(LSSplitType::RIGHT));
	XRCCTRL(*this, "wsc_right_program_number", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_right_program_number", wxSpinCtrl)->SetMax(MAX_CC);
	XRCCTRL(*this, "wsc_right_volume", wxSpinCtrl)->SetValue(pMyLinnStrument->GetMIDIVolume(LSSplitType::RIGHT));
	XRCCTRL(*this, "wsc_right_volume", wxSpinCtrl)->SetMin(MIN_CC);
	XRCCTRL(*this, "wsc_right_volume", wxSpinCtrl)->SetMax(MAX_CC);
}


// Event handlers


void PresetsVolumesDialog::OnLeftGLOBAL_SETTINGS_PRESET_LOAD(wxCommandEvent& event)
{
	pMyLinnStrument->SetLSPresetNumber(XRCCTRL(*this, "wrb_left_global_settings_preset_load", wxRadioBox)->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_SETTINGS_PRESET_LOAD_NRPN, pMyLinnStrument->GetGLOBAL_SETTINGS_PRESET_LOAD());
}


void PresetsVolumesDialog::OnLeftProgramNumber(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIDIProgram(XRCCTRL(*this, "wsc_left_program_number", wxSpinCtrl)->GetValue(), LSSplitType::LEFT);
	}


void PresetsVolumesDialog::OnLeftVolume(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIDIVolume(XRCCTRL(*this, "wsc_left_volume", wxSpinCtrl)->GetValue(), LSSplitType::LEFT);
}


void PresetsVolumesDialog::OnRightGLOBAL_SETTINGS_PRESET_LOAD(wxCommandEvent& event)
{
	pMyLinnStrument->SetLSPresetNumber(XRCCTRL(*this, "wrb_right_global_settings_preset_load", wxRadioBox)->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_SETTINGS_PRESET_LOAD_NRPN, pMyLinnStrument->GetGLOBAL_SETTINGS_PRESET_LOAD());
}


void PresetsVolumesDialog::OnRightProgramNumber(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIDIProgram(XRCCTRL(*this, "wsc_right_program_number", wxSpinCtrl)->GetValue(), LSSplitType::RIGHT);
}


void PresetsVolumesDialog::OnRightVolume(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIDIVolume(XRCCTRL(*this, "wsc_right_volume", wxSpinCtrl)->GetValue(), LSSplitType::RIGHT);
}


// Event table

BEGIN_EVENT_TABLE(PresetsVolumesDialog, wxDialog)
// global
//left
EVT_RADIOBOX(XRCID( "wrb_left_global_settings_preset_load"), PresetsVolumesDialog::OnLeftGLOBAL_SETTINGS_PRESET_LOAD)
EVT_SPIN(XRCID( "wsc_left_program_number"), PresetsVolumesDialog::OnLeftProgramNumber)
EVT_SPIN(XRCID("wsc_left_volume"), PresetsVolumesDialog::OnLeftVolume)
//right
EVT_RADIOBOX(XRCID( "wrb_right_global_settings_preset_load"), PresetsVolumesDialog::OnRightGLOBAL_SETTINGS_PRESET_LOAD)
EVT_SPIN(XRCID("wsc_right_program_number"), PresetsVolumesDialog::OnRightProgramNumber)
EVT_SPIN(XRCID("wsc_right_volume"), PresetsVolumesDialog::OnRightVolume)
END_EVENT_TABLE()
