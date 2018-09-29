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
	wxXmlResource::Get()->LoadDialog(this, parent, wxT("presets_volumes_dialog"));
	InitLeft();
	InitRight();

}


void PresetsVolumesDialog::InitLeft()
{
}


void PresetsVolumesDialog::InitRight()
{
}


// Event handlers

void PresetsVolumesDialog::OnGLOBAL_SETTINGS_PRESET_LOAD(wxCommandEvent& event)
{
}


void PresetsVolumesDialog::OnLeftProgramNumber(wxSpinEvent& event)
{
}


void PresetsVolumesDialog::OnLeftVolume(wxSpinEvent& event)
{
}


void PresetsVolumesDialog::OnRightProgramNumber(wxSpinEvent& event)
{
}


void PresetsVolumesDialog::OnRightVolume(wxSpinEvent& event)
{
}


BEGIN_EVENT_TABLE(PresetsVolumesDialog, wxDialog)
// global
EVT_RADIOBOX(GLOBAL_SETTINGS_PRESET_LOAD_ID, PresetsVolumesDialog::OnGLOBAL_SETTINGS_PRESET_LOAD)
//left
EVT_SPIN(ProgramNumber_ID, PresetsVolumesDialog::OnLeftProgramNumber)
EVT_SPIN(Volume_ID, PresetsVolumesDialog::OnLeftVolume)
//right
EVT_SPIN(ProgramNumber_ID, PresetsVolumesDialog::OnRightProgramNumber)
EVT_SPIN(Volume_ID, PresetsVolumesDialog::OnRightVolume)
END_EVENT_TABLE()
