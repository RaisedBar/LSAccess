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
#include "LSEnums.h"

class SequencerPage : public wxPanel
{
public:
	SequencerPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split);

private:
	// event handlers
	DECLARE_EVENT_TABLE()
		
void OnSEQUENCER_TOGGLE_PLAY(wxCommandEvent& event);
	void OnSEQUENCER_TOGGLE_MUTE(wxCommandEvent& event);
	void OnSEQUENCER_PREVIOUS_PATTERN(wxCommandEvent& event);
	void OnSEQUENCER_NEXT_PATTERN(wxCommandEvent& event);
		void OnSEQUENCER_PATTERN(wxSpinEvent& event);
	
// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
		LSSplitType m_Split;

	
// controls
			// Toggles:
	wxCheckBox * chkSEQUENCER_TOGGLE_PLAY, * chkSEQUENCER_TOGGLE_MUTE;
	wxButton *btnSEQUENCER_PREVIOUS_PATTERN, * btnSEQUENCER_NEXT_PATTERN;
	// Value is an LSPatternNumber
	wxSpinCtrl * wscSEQUENCER_PATTERN;
};

