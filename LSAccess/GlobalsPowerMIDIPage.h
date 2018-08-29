// GlobalsPowerMIDIPage.h

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

class GlobalsPowerMIDIPage : public wxPanel
{
public:
	GlobalsPowerMIDIPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);

private:
	// event handlers
	DECLARE_EVENT_TABLE()
			
	void OnGLOBAL_MIDI_DEVICE_IO(wxCommandEvent& event);
	void OnDEVICE_MIDI_THRU(wxCommandEvent& event);
	void OnDEVICE_USER_FIRMWARE_MODE(wxCommandEvent& event);
	void OnDEVICE_MIN_BYTE_INTERVAL_VALUE(wxSpinEvent& event);

// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSGlobalSettings m_Settings;

	// Controls
		// Value is an LS_MIDIDevice
	wxRadioBox * wrbGLOBAL_MIDI_DEVICE_IO;
	// Toggle:
	wxCheckBox * chkDEVICE_MIDI_THRU;
		// Value is constrained by MIN_MIDI_BYTE_DELAY and MAX_MIDI_BYTE_DELAY
	wxSpinCtrl * wscDEVICE_MIN_BYTE_INTERVAL_VALUE;
	// toggle
	wxCheckBox * chkDEVICE_USER_FIRMWARE_MODE;
	};
