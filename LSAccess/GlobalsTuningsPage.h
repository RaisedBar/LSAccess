// GlobalsTuningsPage.h

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

class GlobalsTuningsPage : public wxPanel
{
public:
	GlobalsTuningsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);
	
private:
	// event handlers
	DECLARE_EVENT_TABLE()

	void OnGLOBAL_ROW_OFFSET(wxCommandEvent& event);
	void OnGLOBAL_CUSTOM_ROW_OFFSET(wxCommandEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW1(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW2(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW3(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW4(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW5(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW6(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW7(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW8(wxSpinEvent& event);

	// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSGlobalSettings m_Settings;

// controls
// Controls
		// Value is an LSRowOffsetType
	wxRadioBox * wrbGLOBAL_ROW_OFFSET;
	// Value is an LSCustomRowOffset
	wxRadioBox * wrbGLOBAL_CUSTOM_ROW_OFFSET;
	// Values are constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW1;
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW2;
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW3;
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW4;
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW5;
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW6;
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW7;
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW8;
};

