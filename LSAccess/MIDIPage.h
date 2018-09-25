// MIDIPage.h

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
#include "wx/xrc/xmlres.h"

#include "LinnStrument.h"
#include "LSEnums.h"

class MIDIPage: public wxPanel
{
public:
	MIDIPage() {};
		MIDIPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split);
	
protected:
	// controls
			// Value is a MIDI channel number:
	wxSpinCtrl * wscMIDI_MAIN_CHANNEL;
	// Value is a MIDI channel number:
	wxSpinCtrl * wscMIDI_PER_ROW_LOWEST_CHANNEL;
	// Toggles:
	wxCheckBox * chkCHANNEL_PER_NOTE_1, *chkCHANNEL_PER_NOTE_2, *chkCHANNEL_PER_NOTE_3, *chkCHANNEL_PER_NOTE_4, *chkCHANNEL_PER_NOTE_5, *chkCHANNEL_PER_NOTE_6, *chkCHANNEL_PER_NOTE_7, *chkCHANNEL_PER_NOTE_8;
	wxCheckBox * chkCHANNEL_PER_NOTE_9, *chkCHANNEL_PER_NOTE_10, *chkCHANNEL_PER_NOTE_11, *chkCHANNEL_PER_NOTE_12, *chkCHANNEL_PER_NOTE_13, *chkCHANNEL_PER_NOTE_14, *chkCHANNEL_PER_NOTE_15, *chkCHANNEL_PER_NOTE_16;
	// Value is an LS_MIDIMode
	wxRadioBox * wrbSPLIT_MODE;
	// Value is an LSChannelOrder
	wxRadioBox * wrbCHANNEL_PER_ROW_ORDER;

private:
	// event handlers
	DECLARE_EVENT_TABLE()

	void OnMIDI_MAIN_CHANNEL(wxSpinEvent& event);
void OnMIDI_PER_ROW_LOWEST_CHANNEL(wxSpinEvent& event);
void OnCHANNEL_PER_NOTE_1(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_2(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_3(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_4(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_5(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_6(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_7(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_8(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_9(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_10(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_11(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_12(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_13(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_14(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_15(wxCommandEvent& event);
void OnCHANNEL_PER_NOTE_16(wxCommandEvent& event);
void OnSPLIT_MODE(wxCommandEvent& event);
void OnCHANNEL_PER_ROW_ORDER(wxCommandEvent& event);

	// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
		LSSplitType m_Split;
			};
