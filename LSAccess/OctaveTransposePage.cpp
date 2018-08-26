// OctaveTransposePage.cpp

#include "OctaveTransposePage.h"

OctaveTransposePage::OctaveTransposePage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetOctaveTransposeSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	// Value is an LSOctave
	wxRadioBox * wrbOctave = new wxRadioBox(myPanel, OCTAVE_ID, L"&Octave", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Octaves), Octaves, m_Settings.GetOctave(split), wxRA_SPECIFY_ROWS);
	// Values are from LSPitch
	wxRadioBox * wrbPITCH_TRANSPOSE = new wxRadioBox(myPanel, TRANSPOSE_PITCH_ID, L"&Pitch transpose", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Pitches), Pitches, m_Settings.GetTransposePitch(split), wxRA_SPECIFY_ROWS);
	wxRadioBox * wrbTRANSPOSE_LIGHTS = new wxRadioBox(myPanel, TRANSPOSE_LIGHTS_ID, L"Transpose &lights", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Pitches), Pitches, m_Settings.GetTransposeLights(split), wxRA_SPECIFY_ROWS);

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


