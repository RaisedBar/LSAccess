// ChannelsPage.h

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

class ChannelsPage: public wxPanel
{
public:
	ChannelsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split);
	
private:
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
		LSPerSplitSettings m_Settings;
	
	// controls
	// Toggles:
		wxCheckBox * chkCHANNEL_PER_NOTE_1, * chkCHANNEL_PER_NOTE_2, * chkCHANNEL_PER_NOTE_3, * chkCHANNEL_PER_NOTE_4, * chkCHANNEL_PER_NOTE_5, * chkCHANNEL_PER_NOTE_6, * chkCHANNEL_PER_NOTE_7, * chkCHANNEL_PER_NOTE_8;
		wxCheckBox * chkCHANNEL_PER_NOTE_9, * chkCHANNEL_PER_NOTE_10, * chkCHANNEL_PER_NOTE_11, * chkCHANNEL_PER_NOTE_12, * chkCHANNEL_PER_NOTE_13, * chkCHANNEL_PER_NOTE_14, * chkCHANNEL_PER_NOTE_15, * chkCHANNEL_PER_NOTE_16;
	// Value is a MIDI channel number:
	wxSpinCtrl * wscMIDI_PER_ROW_LOWEST_CHANNEL;
};
