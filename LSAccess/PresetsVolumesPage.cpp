// PresetsVolumesPage.cpp

#include "stdafx.h"
#include "PresetsVolumesPage.h"

PresetsVolumesPage::PresetsVolumesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, LSSplitType split)
	:wxPanel(parent),
	m_Split(split),
	pMyLinnStrument(pLinnStrument),
	pMyParent(parent)
{
		wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
		// Value is an LSPresetNumber
	wxStaticText * lblGLOBAL_SETTINGS_PRESET_LOAD = new wxStaticText(myPanel, wxID_ANY, L"&LinnStrument preset:");
		wrbGLOBAL_SETTINGS_PRESET_LOAD = new wxRadioBox(myPanel, GLOBAL_SETTINGS_PRESET_LOAD_ID, L"&LinnStrument Preset", wxDefaultPosition, wxDefaultSize, WXSIZEOF(PresetNumbers), PresetNumbers, pMyLinnStrument->GetLSPresetNumber(), wxRA_SPECIFY_ROWS);
		hBox1->Add(lblGLOBAL_SETTINGS_PRESET_LOAD, 0, wxEXPAND);
		hBox1->Add(wrbGLOBAL_SETTINGS_PRESET_LOAD, 0, wxEXPAND);
	
	// Values constrained by MIN_CC and MAX_CC
		wxStaticText * lblProgramNumber = new wxStaticText(myPanel, wxID_ANY, L"&Program number:");
		wscProgramNumber = new wxSpinCtrl(myPanel, ProgramNumber_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetMIDIProgram(split), "&Program");
		hBox1->Add(lblProgramNumber, 0, wxEXPAND);
		hBox1->Add(wscProgramNumber, 0, wxEXPAND);

wxStaticText * lblVolume = new wxStaticText(myPanel, wxID_ANY, L"&Volume:");
wscVolume = new wxSpinCtrl(myPanel, Volume_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetVolume(split), "&Volume");
hBox1->Add(lblVolume, 0, wxEXPAND);
hBox1->Add(wscVolume, 0, wxEXPAND);

	myPanel->SetSizer(hBox1);
	hBox1->SetSizeHints(this);
	myPanel->Fit();
	hBox1->Fit(myPanel);
	wrbGLOBAL_SETTINGS_PRESET_LOAD->SetFocus();
}


// event handlers

void PresetsVolumesPage::OnGLOBAL_SETTINGS_PRESET_LOAD(wxCommandEvent& event)
{
	pMyLinnStrument->SetLSPresetNumber(wrbGLOBAL_SETTINGS_PRESET_LOAD->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_SETTINGS_PRESET_LOAD_NRPN, pMyLinnStrument->GetGLOBAL_SETTINGS_PRESET_LOAD());
}


void PresetsVolumesPage::OnProgramNumber(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIDIProgram(wscProgramNumber->GetValue(), m_Split);
	// Not sure what should happen here
}


void PresetsVolumesPage::OnVolume(wxSpinEvent& event)
{
	pMyLinnStrument->SetVolume(wscVolume->GetValue(), m_Split);
// Not sure what should happen here
}


// Event table
BEGIN_EVENT_TABLE(PresetsVolumesPage, wxPanel)
EVT_SPIN(ProgramNumber_ID, PresetsVolumesPage::OnProgramNumber)
EVT_SPIN(Volume_ID, PresetsVolumesPage::OnVolume)

EVT_RADIOBOX(GLOBAL_SETTINGS_PRESET_LOAD_ID, PresetsVolumesPage::OnGLOBAL_SETTINGS_PRESET_LOAD)
END_EVENT_TABLE()
