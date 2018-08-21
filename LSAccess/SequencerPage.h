// SequencerPage.h

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

#include <wx/notebook.h>
#include <wx/spinctrl.h>

#include "LinnStrument.h"
#include "LSPerSplit.h"
#include "LSEnums.h"

class SequencerPage : public wxPanel
{
public:
	SequencerPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);

private:
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSPerSplitSettings m_Settings;

	// controls
			// Toggles:
	wxCheckBox * chkSPLIT_LEFT_SEQUENCER_TOGGLE_PLAY, * chkSPLIT_LEFT_SEQUENCER_TOGGLE_MUTE;
	wxButton *btnSPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN, * btnSPLIT_LEFT_SEQUENCER_NEXT_PATTERN;
	// Value is an LSPatternNumber
	wxSpinCtrl * wscSPLIT_LEFT_SEQUENCER_PATTERN;
};

