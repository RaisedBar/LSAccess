// OctaveTransposePage.cpp

#include "OctaveTransposePage.h"

OctaveTransposePage::OctaveTransposePage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	pMyParent(new wxBookCtrl()),
	m_Split(split)
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetOctaveTransposeSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	// Value is an LSOctave
	wrbOctave = new wxRadioBox(myPanel, OCTAVE_ID, L"&Octave", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Octaves), Octaves, m_Settings.GetOctave(split), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbOctave, 0, wxEXPAND);
	// Values are from LSPitch
	wrbPITCH_TRANSPOSE = new wxRadioBox(myPanel, TRANSPOSE_PITCH_ID, L"&Pitch transpose", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Pitches), Pitches, m_Settings.GetTransposePitch(split), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbPITCH_TRANSPOSE, 0, wxEXPAND);
	wrbTRANSPOSE_LIGHTS = new wxRadioBox(myPanel, TRANSPOSE_LIGHTS_ID, L"Transpose &lights", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Pitches), Pitches, m_Settings.GetTransposeLights(split), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbTRANSPOSE_LIGHTS, 0, wxEXPAND);

	myPanel->SetSizer(hBox1);
	hBox1->SetSizeHints(this);
	myPanel->Fit();
	hBox1->Fit(myPanel);
}


// event handlers

void OctaveTransposePage::OnOctave(wxCommandEvent& event)
{
	m_Settings.SetOctave(wrbOctave->GetSelection(), m_Split);
}


void OctaveTransposePage::OnPITCH_TRANSPOSE(wxCommandEvent& event)
{
	m_Settings.SetTransposePitch(wrbPITCH_TRANSPOSE->GetSelection(), m_Split);
}


void OctaveTransposePage::OnTRANSPOSE_LIGHTS(wxCommandEvent& event)
{
	m_Settings.SetTransposeLights(wrbTRANSPOSE_LIGHTS->GetSelection(), m_Split);
}


// Event table
BEGIN_EVENT_TABLE(OctaveTransposePage, wxPanel)
EVT_RADIOBOX(OCTAVE_ID, OctaveTransposePage::OnOctave)
EVT_RADIOBOX(TRANSPOSE_PITCH_ID, OctaveTransposePage::OnPITCH_TRANSPOSE)
EVT_RADIOBOX(TRANSPOSE_LIGHTS_ID, OctaveTransposePage::OnTRANSPOSE_LIGHTS)
END_EVENT_TABLE()
