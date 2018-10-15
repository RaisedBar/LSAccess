// SequencerDialog.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "stdafx.h"
#include "SequencerDialog.h"


SequencerDialog::SequencerDialog(wxWindow* parent, LinnStrument * pLinnStrument)
	: wxDialog(NULL, wxID_ANY, L""),
	pMyLinnStrument(pLinnStrument)
{
	if (wxXmlResource::Get()->LoadDialog(this, parent, wxT("step_sequencer_dialog")))
	{
		InitTrack1();
		InitTrack2();
	}
	else
	{
		wxMessageBox("Could not load Step Sequencer dialog from XRC", wstrErrorTitle, wxOK | wxICON_ERROR);
		EndModal(false);
	}
	}


void SequencerDialog::InitTrack1()
{
XRCCTRL(*this, "wsc_track_1_pattern", wxSpinCtrl)->SetValue(pMyLinnStrument->GetSEQUENCER_PATTERN(LSSplitType::LEFT));
	XRCCTRL(*this, "wsc_track_1_pattern", wxSpinCtrl)->SetMin(MIN_SEQUENCER_PATTERN);
	XRCCTRL(*this, "wsc_track_1_pattern", wxSpinCtrl)->SetMax(MAX_SEQUENCER_PATTERN);
					}


void SequencerDialog::InitTrack2()
{
	XRCCTRL(*this, "wsc_track_2_pattern", wxSpinCtrl)->SetValue(pMyLinnStrument->GetSEQUENCER_PATTERN(LSSplitType::RIGHT));
	XRCCTRL(*this, "wsc_track_2_pattern", wxSpinCtrl)->SetMin(MIN_SEQUENCER_PATTERN);
	XRCCTRL(*this, "wsc_track_2_pattern", wxSpinCtrl)->SetMax(MAX_SEQUENCER_PATTERN);
		}


// Event handlers

void SequencerDialog::OnTrack1SEQUENCER_TOGGLE_PLAY(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_TOGGLE_PLAY(LinnStrument::LSToggle(XRCCTRL(*this, "chk_play_track_1", wxCheckBox)->GetValue()), LSSplitType::LEFT);
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN, LinnStrument::LSToggle(XRCCTRL(*this, "chk_play_track_1", wxCheckBox)->GetValue()));
}


void SequencerDialog::OnTrack1SEQUENCER_TOGGLE_MUTE(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_TOGGLE_MUTE(LinnStrument::LSToggle(XRCCTRL(*this, "chk_mute_track_1", wxCheckBox)->GetValue()), LSSplitType::LEFT);
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN, XRCCTRL(*this, "chk_mute_track_1", wxCheckBox)->GetValue());
}


void SequencerDialog::OnTrack1SEQUENCER_PREVIOUS_PATTERN(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_PREVIOUS_PATTERN(1, LSSplitType::LEFT);
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN, 1);
}


void SequencerDialog::OnTrack1SEQUENCER_NEXT_PATTERN(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_NEXT_PATTERN(1, LSSplitType::LEFT);
	pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN, 1);
}


void SequencerDialog::OnTrack1SEQUENCER_PATTERN(wxSpinEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_PATTERN(XRCCTRL(*this, "wsc_track_1_pattern", wxSpinCtrl)->GetValue(), LSSplitType::LEFT);
	pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEQUENCER_PATTERN_NRPN, pMyLinnStrument->GetSEQUENCER_PATTERN(LSSplitType::LEFT));
	}


// Event table
void SequencerDialog::OnTrack2SEQUENCER_TOGGLE_PLAY(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_TOGGLE_PLAY(LinnStrument::LSToggle(XRCCTRL(*this, "chk_play_track_2", wxCheckBox)->GetValue()), LSSplitType::RIGHT);
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEQUENCER_TOGGLE_PLAY_NRPN, LinnStrument::LSToggle(XRCCTRL(*this, "chk_play_track_2", wxCheckBox)->GetValue()));
}


void SequencerDialog::OnTrack2SEQUENCER_TOGGLE_MUTE(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_TOGGLE_MUTE(LinnStrument::LinnStrument::LSToggle(XRCCTRL(*this, "chk_mute_track_2", wxCheckBox)->GetValue()), LSSplitType::RIGHT);
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEQUENCER_TOGGLE_MUTE_NRPN, LinnStrument::LinnStrument::LSToggle(XRCCTRL(*this, "chk_mute_track_2", wxCheckBox)->GetValue()));
	}


void SequencerDialog::OnTrack2SEQUENCER_PREVIOUS_PATTERN(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_PREVIOUS_PATTERN(1, LSSplitType::RIGHT);
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEQUENCER_PREVIOUS_PATTERN_NRPN, 1);
}


void SequencerDialog::OnTrack2SEQUENCER_NEXT_PATTERN(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_NEXT_PATTERN(1, LSSplitType::RIGHT);
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEQUENCER_NEXT_PATTERN_NRPN, 1);
}


void SequencerDialog::OnTrack2SEQUENCER_PATTERN(wxSpinEvent& event)
{
	pMyLinnStrument->SetSEQUENCER_PATTERN(XRCCTRL(*this, "wsc_track_2_pattern", wxSpinCtrl)->GetValue(), LSSplitType::RIGHT);
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEQUENCER_PATTERN_NRPN, pMyLinnStrument->GetSEQUENCER_PATTERN(LSSplitType::RIGHT));
	}


// Event table
BEGIN_EVENT_TABLE(SequencerDialog, wxPanel)
EVT_SPIN(XRCID("wsc_track_1_pattern"), SequencerDialog::OnTrack1SEQUENCER_PATTERN)
EVT_CHECKBOX(XRCID("chk_play_track_1"), SequencerDialog::OnTrack1SEQUENCER_TOGGLE_PLAY)
EVT_CHECKBOX(XRCID("chk_mute_track_1"), SequencerDialog::OnTrack1SEQUENCER_TOGGLE_MUTE)
EVT_BUTTON(XRCID("last_track_1_pattern_button"), SequencerDialog::OnTrack1SEQUENCER_PREVIOUS_PATTERN)
EVT_BUTTON(XRCID("next_track_1_pattern_button"), SequencerDialog::OnTrack1SEQUENCER_NEXT_PATTERN)
EVT_SPIN(XRCID("wsc_track_2_pattern"), SequencerDialog::OnTrack2SEQUENCER_PATTERN)
EVT_CHECKBOX(XRCID("chk_play_track_2"), SequencerDialog::OnTrack2SEQUENCER_TOGGLE_PLAY)
EVT_CHECKBOX(XRCID("chk_mute_track_2"), SequencerDialog::OnTrack2SEQUENCER_TOGGLE_MUTE)
EVT_BUTTON(XRCID("last_track_2_pattern_button"), SequencerDialog::OnTrack2SEQUENCER_PREVIOUS_PATTERN)
EVT_BUTTON(XRCID("next_track_2_pattern_button"), SequencerDialog::OnTrack2SEQUENCER_NEXT_PATTERN)
END_EVENT_TABLE()
