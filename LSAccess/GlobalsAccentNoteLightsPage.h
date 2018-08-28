// GlobalsAccentNoteLightsPage.h

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

class GlobalsAccentNoteLightsPage : public wxPanel
{
public:
	GlobalsAccentNoteLightsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);

private:
// event handlers
	DECLARE_EVENT_TABLE()
	
	void OnGLOBAL_ACCENT_NOTE_LIGHT_C(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_D(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_E(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_F(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_G(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_A(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_B(wxCommandEvent& event);

// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSGlobalSettings m_Settings;

	// controls
	// Toggles:
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_C;
		wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP;
		wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_D;
		wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP;
		wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_E;
		wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_F;
		wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP;
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_G;
		wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP;
		wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_A;
		wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP;
		wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_B;
	};

