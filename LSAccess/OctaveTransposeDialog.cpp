// OctaveTransposeDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "OctaveTransposeDialog.h"


OctaveTransposeDialog::OctaveTransposeDialog(wxWindow* parent, LinnStrument * pLinnStrument)
	: wxDialog(NULL, wxID_ANY, L""),
	pMyLinnStrument(pLinnStrument)
{
	wxXmlResource::Get()->LoadDialog(this, parent, wxT("octave_transpose_dialog"));
	InitLeft();
	InitRight();
	}


void OctaveTransposeDialog::InitLeft()
{
	XRCCTRL(*this, "wrb_left_octave", wxRadioBox)->SetSelection(pMyLinnStrument->GetOCTAVE(LSSplitType::LEFT));
	XRCCTRL(*this, "wrb_left_pitch_transpose", wxRadioBox)->SetSelection(pMyLinnStrument->GetPITCH_TRANSPOSE(LSSplitType::LEFT));
	XRCCTRL(*this, "wrb_left_transpose_lights", wxRadioBox)->SetSelection(pMyLinnStrument->GetTransposeLights(LSSplitType::LEFT));
	   	 }


void OctaveTransposeDialog::InitRight()
{
	XRCCTRL(*this, "wrb_right_octave", wxRadioBox)->SetSelection(pMyLinnStrument->GetOCTAVE(LSSplitType::RIGHT));
	XRCCTRL(*this, "wrb_right_pitch_transpose", wxRadioBox)->SetSelection(pMyLinnStrument->GetPITCH_TRANSPOSE(LSSplitType::RIGHT));
	XRCCTRL(*this, "wrb_right_transpose_lights", wxRadioBox)->SetSelection(pMyLinnStrument->GetTransposeLights(LSSplitType::RIGHT));
}


// Event handlers

void OctaveTransposeDialog::OnLeftOctave(wxCommandEvent& event)
{
	pMyLinnStrument->SetOctave(XRCCTRL(*this, "wrb_left_octave", wxRadioBox)->GetSelection(), LSSplitType::LEFT);
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_OCTAVE_NRPN, pMyLinnStrument->GetOCTAVE(LSSplitType::LEFT));
	}


void OctaveTransposeDialog::OnLeftPITCH_TRANSPOSE(wxCommandEvent& event)
{
	pMyLinnStrument->SetTransposePitch(XRCCTRL(*this, "wrb_left_pitch_transpose", wxRadioBox)->GetSelection(), LSSplitType::LEFT);
	pMyLinnStrument->SendNRPN(SPLIT_LEFT_PITCH_TRANSPOSE_NRPN, pMyLinnStrument->GetPITCH_TRANSPOSE(LSSplitType::LEFT));
	}


void OctaveTransposeDialog::OnLeftTRANSPOSE_LIGHTS(wxCommandEvent& event)
{
	pMyLinnStrument->SetTransposeLights(XRCCTRL(*this, "wrb_left_transpose_lights", wxRadioBox)->GetSelection(), LSSplitType::LEFT);
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN, pMyLinnStrument->GetTransposeLights(LSSplitType::LEFT));
	}


void OctaveTransposeDialog::OnRightOctave(wxCommandEvent& event)
{
	pMyLinnStrument->SetOctave(XRCCTRL(*this, "wrb_left_octave", wxRadioBox)->GetSelection(), LSSplitType::RIGHT);
	pMyLinnStrument->SendNRPN(SPLIT_LEFT_OCTAVE_NRPN, pMyLinnStrument->GetOCTAVE(LSSplitType::RIGHT));
}


void OctaveTransposeDialog::OnRightPITCH_TRANSPOSE(wxCommandEvent& event)
{
	pMyLinnStrument->SetTransposePitch(XRCCTRL(*this, "wrb_left_pitch_transpose", wxRadioBox)->GetSelection(), LSSplitType::RIGHT);
	pMyLinnStrument->SendNRPN(SPLIT_LEFT_PITCH_TRANSPOSE_NRPN, pMyLinnStrument->GetPITCH_TRANSPOSE(LSSplitType::RIGHT));
}


void OctaveTransposeDialog::OnRightTRANSPOSE_LIGHTS(wxCommandEvent& event)
{
	pMyLinnStrument->SetTransposeLights(XRCCTRL(*this, "wrb_left_transpose_lights", wxRadioBox)->GetSelection(), LSSplitType::RIGHT);
	pMyLinnStrument->SendNRPN(SPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN, pMyLinnStrument->GetTransposeLights(LSSplitType::RIGHT));
}


BEGIN_EVENT_TABLE(OctaveTransposeDialog, wxDialog)
// left
EVT_RADIOBOX(XRCID("wrb_left_octave"), OctaveTransposeDialog::OnLeftOctave)
EVT_RADIOBOX(XRCID("wrb_left_pitch_transpose"), OctaveTransposeDialog::OnLeftPITCH_TRANSPOSE)
EVT_RADIOBOX(XRCID("wrb_left_transpose_lights"), OctaveTransposeDialog::OnLeftTRANSPOSE_LIGHTS)
// right
EVT_RADIOBOX(XRCID("wrb_right_octave"), OctaveTransposeDialog::OnRightOctave)
EVT_RADIOBOX(XRCID("wrb_right_pitch_transpose"), OctaveTransposeDialog::OnRightPITCH_TRANSPOSE)
EVT_RADIOBOX(XRCID("wrb_right_transpose_lights"), OctaveTransposeDialog::OnRightTRANSPOSE_LIGHTS)
END_EVENT_TABLE()
