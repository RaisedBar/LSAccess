// PerSplitDialog.h
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

#include <wx/notebook.h>
#include "wx/xrc/xmlres.h"

#include "LSEnums.h"
#include "LSConsts.h"
#include "MIDIPage.h"
#include "BendPage.h"
#include "ColorsPage.h"
#include "LowRowPage.h"
#include "FadersPage.h"
#include "AxesPage.h"
#include "SpecialPage.h"

class PerSplitDialog : public wxDialog
{
public:
	PerSplitDialog() {};
	PerSplitDialog(wxWindow* parent, const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split);
	bool Create(const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split);

protected:
		wxNotebook * pNotebook;
	MIDIPage * pMIDIPage;
	BendPage * pBendPage;
	ColorsPage * pColorsPage;
	LowRowPage * pLowRowPage;
	FadersPage * pFadersPage;
	AxesPage * pAxesPage;
SpecialPage * pSpecialPage; 

private:
	// Event handlers
	
	// MIDI page
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
			LSSplitType m_Split;
			
			DECLARE_EVENT_TABLE()
};
