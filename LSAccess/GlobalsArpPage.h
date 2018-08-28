// GlobalsArpPage.h

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
#include "LSGlobals.h"
#include "LSEnums.h"

class GlobalsArpPage : public wxPanel
{
public:
	GlobalsArpPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);

private:
	// event handlers
	DECLARE_EVENT_TABLE()
				
	void OnGLOBAL_ARP_DIRECTION(wxCommandEvent& event);
	void OnGLOBAL_ARP_TEMPO_NOTE_VALUE(wxCommandEvent& event);
	void OnGLOBAL_ARP_OCTAVE_EXTENSION(wxCommandEvent& event);
	void OnGLOBAL_CLOCK_BPM(wxSpinEvent& event);
	
	// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSGlobalSettings m_Settings;
	
	// Controls
			// Value is constrained by MIN_TEMPO and MAX_TEMPO
	wxSpinCtrl * wscGLOBAL_CLOCK_BPM;
	// Value is an LSArpDirection
	wxRadioBox * wrbGLOBAL_ARP_DIRECTION;
	// Value is an LSArpTempoNoteType
	wxRadioBox * wrbGLOBAL_ARP_TEMPO_NOTE_VALUE;
	// Value is an LSGlobalArpOctaveExtension
	wxRadioBox * wrbGLOBAL_ARP_OCTAVE_EXTENSION;
};
