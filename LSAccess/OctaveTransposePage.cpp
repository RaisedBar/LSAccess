// OctaveTransposePage.cpp

#include "stdafx.h"
#include "OctaveTransposePage.h"

OctaveTransposePage::OctaveTransposePage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	m_Split(split),
	pMyLinnStrument(pLinnStrument),
		pMyParent(parent)
	{
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	// Value is an LSOctave
	wxStaticText * lblOctave = new wxStaticText(myPanel, wxID_ANY, L"&Octave:");
	wrbOctave = new wxRadioBox(myPanel, OCTAVE_ID, L"&Octave", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Octaves), Octaves, pMyLinnStrument->GetOctave(split), wxRA_SPECIFY_ROWS);
	hBox1->Add(lblOctave, 0, wxEXPAND);
	hBox1->Add(wrbOctave, 0, wxEXPAND);

	// Values are from LSPitch
	wxStaticText * lblPITCH_TRANSPOSE = new wxStaticText(myPanel, wxID_ANY, L"&Pitch transpose:");
wrbPITCH_TRANSPOSE = new wxRadioBox(myPanel, TRANSPOSE_PITCH_ID, L"&Pitch transpose", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Pitches), Pitches, pMyLinnStrument->GetTransposePitch(split), wxRA_SPECIFY_ROWS);
hBox1->Add(lblPITCH_TRANSPOSE, 0, wxEXPAND);
hBox1->Add(wrbPITCH_TRANSPOSE, 0, wxEXPAND);
	
wxStaticText * lblTRANSPOSE_LIGHTS = new wxStaticText(myPanel, wxID_ANY, L"Transpose &lights:");
wrbTRANSPOSE_LIGHTS = new wxRadioBox(myPanel, TRANSPOSE_LIGHTS_ID, L"Transpose &lights", wxDefaultPosition, wxDefaultSize, WXSIZEOF(Pitches), Pitches, pMyLinnStrument->GetTransposeLights(split), wxRA_SPECIFY_ROWS);
hBox1->Add(lblTRANSPOSE_LIGHTS, 0, wxEXPAND);
hBox1->Add(wrbTRANSPOSE_LIGHTS, 0, wxEXPAND);

	myPanel->SetSizer(hBox1);
	hBox1->SetSizeHints(this);
	myPanel->Fit();
	hBox1->Fit(myPanel);
	wrbOctave->SetFocus();
}


// event handlers

void OctaveTransposePage::OnOctave(wxCommandEvent& event)
{
	pMyLinnStrument->SetOctave(wrbOctave->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_OCTAVE_NRPN, pMyLinnStrument->GetOCTAVE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_OCTAVE_NRPN, pMyLinnStrument->GetOCTAVE(m_Split));
	}
}


void OctaveTransposePage::OnPITCH_TRANSPOSE(wxCommandEvent& event)
{
	pMyLinnStrument->SetTransposePitch(wrbPITCH_TRANSPOSE->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_PITCH_TRANSPOSE_NRPN, pMyLinnStrument->GetPITCH_TRANSPOSE(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_PITCH_TRANSPOSE_NRPN, pMyLinnStrument->GetPITCH_TRANSPOSE(m_Split));
	}
}


void OctaveTransposePage::OnTRANSPOSE_LIGHTS(wxCommandEvent& event)
{
	pMyLinnStrument->SetTransposeLights(wrbTRANSPOSE_LIGHTS->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN, pMyLinnStrument->GetTransposeLights(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_TRANSPOSE_LIGHTS_NRPN, pMyLinnStrument->GetTransposeLights(m_Split));
	}
}


// Event table
BEGIN_EVENT_TABLE(OctaveTransposePage, wxPanel)
EVT_RADIOBOX(OCTAVE_ID, OctaveTransposePage::OnOctave)
EVT_RADIOBOX(TRANSPOSE_PITCH_ID, OctaveTransposePage::OnPITCH_TRANSPOSE)
EVT_RADIOBOX(TRANSPOSE_LIGHTS_ID, OctaveTransposePage::OnTRANSPOSE_LIGHTS)
END_EVENT_TABLE()
