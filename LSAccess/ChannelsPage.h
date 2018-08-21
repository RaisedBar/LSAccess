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
	ChannelsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);
	
private:
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
		LSPerSplitSettings m_Settings;
	
	// controls
	// Toggles:
		wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_1, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_2, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_3, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_4, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_5, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_6, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_7, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_8;
		wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_9, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_10, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_11, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_12, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_13, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_14, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_15, * chkSPLIT_LEFT_CHANNEL_PER_NOTE_16;
	// Value is a MIDI channel number:
	wxSpinCtrl * wscSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL;
};
