// SequencerDialog.h
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net

#pragma once

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/xrc/xmlres.h"
#include <wx/spinctrl.h>

#include "LinnStrument.h"
#include "LSConsts.h"

class SequencerDialog : public wxDialog
{
public:
	SequencerDialog(wxWindow* parent, LinnStrument * pLinnStrument);

private:
	void InitTrack1();
	void InitTrack2();

// event handlers
	DECLARE_EVENT_TABLE()

	void OnTrack1SEQUENCER_PATTERN(wxSpinEvent& event);
		void OnTrack1SEQUENCER_TOGGLE_PLAY(wxCommandEvent& event);
	void OnTrack1SEQUENCER_TOGGLE_MUTE(wxCommandEvent& event);
	void OnTrack1SEQUENCER_PREVIOUS_PATTERN(wxCommandEvent& event);
	void OnTrack1SEQUENCER_NEXT_PATTERN(wxCommandEvent& event);
	void OnTrack2SEQUENCER_PATTERN(wxSpinEvent& event);
	void OnTrack2SEQUENCER_TOGGLE_PLAY(wxCommandEvent& event);
	void OnTrack2SEQUENCER_TOGGLE_MUTE(wxCommandEvent& event);
	void OnTrack2SEQUENCER_PREVIOUS_PATTERN(wxCommandEvent& event);
	void OnTrack2SEQUENCER_NEXT_PATTERN(wxCommandEvent& event);
	
	// data
	LinnStrument * pMyLinnStrument;
	};
