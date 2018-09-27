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
	void InitMIDIPage();
	void InitBendPage();
	void InitAxesPage();
	void InitColorsPage();
	void InitLowRowPage();
	void InitFadersPage();
void 	InitSpecialPage();
	
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

// Bend page
	void OnBEND_RANGE(wxSpinEvent& event);
	void OnBEND_TOGGLE(wxCommandEvent& event);
	void OnBEND_QUANTIZE_TOGGLE(wxCommandEvent& event);
	void OnBendQuantize(wxCommandEvent& event);
	void OnRESET_PITCH_ON_RELEASE(wxCommandEvent& event);

	// Axes page
	void OnSEND_Y(wxCommandEvent& event);
	void OnMIN_CC_FOR_Y(wxSpinEvent& event);
	void OnMAX_CC_FOR_Y(wxSpinEvent& event);
	void OnCC_FOR_Y(wxSpinEvent& event);
	void OnRELATIVE_Y(wxCommandEvent& event);
	void OnEXPRESSION_FOR_Y(wxCommandEvent& event);
	void OnINITIAL_RELATIVE_VALUE_FOR_Y(wxSpinEvent& event);
	void OnSEND_Z(wxCommandEvent& event);
	void OnMIN_CC_FOR_Z(wxSpinEvent& event);
	void OnMAX_CC_FOR_Z(wxSpinEvent& event);
	void OnCC_FOR_Z(wxSpinEvent& event);
	void OnRELATIVE_Z(wxCommandEvent& event);
	void OnEXPRESSION_FOR_Z(wxCommandEvent& event);
	void On14BIT_CC_VALUE_FOR_Z(wxSpinEvent& event);

// Colors page
	void OnCOLOR_MAIN(wxCommandEvent& event);
	void OnCOLOR_ACCENT(wxCommandEvent& event);
	void OnCOLOR_PLAYED(wxCommandEvent& event);
	void OnCOLOR_LOWROW(wxCommandEvent& event);
	void OnAnimation(wxCommandEvent& event);

	// Low Row page
	void OnCC_FOR_LOWROW(wxSpinEvent& event);
	void OnCC_FOR_LOWROW_XYZ(wxSpinEvent& event);
	void OnCC_FOR_LOWROW_XYZ_Y(wxSpinEvent& event);
	void OnCC_FOR_LOWROW_XYZ_Z(wxSpinEvent& event);
		void OnLOWROW_X_BEHAVIOUR(wxCommandEvent& event);
	void OnLOWROW_XYZ_BEHAVIOUR(wxCommandEvent& event);
	void OnLOWROW_MODE(wxCommandEvent& event);

// Faders page
	void OnCC_FOR_FADER1(wxSpinEvent& event);
	void OnCC_FOR_FADER2(wxSpinEvent& event);
	void OnCC_FOR_FADER3(wxSpinEvent& event);
	void OnCC_FOR_FADER4(wxSpinEvent& event);
	void OnCC_FOR_FADER5(wxSpinEvent& event);
	void OnCC_FOR_FADER6(wxSpinEvent& event);
	void OnCC_FOR_FADER7(wxSpinEvent& event);
	void OnCC_FOR_FADER8(wxSpinEvent& event);

// Special page
	void OnSpecial(wxCommandEvent& event);

	// data
			LinnStrument * pMyLinnStrument;
			LSSplitType m_Split;
			
			DECLARE_EVENT_TABLE()
};
