// GlobalsVelocityPressurePage.h

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

class GlobalsVelocityPressurePage : public wxPanel
{
public:
	GlobalsVelocityPressurePage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument);

private:
	// event handlers
	DECLARE_EVENT_TABLE()

	void OnGLOBAL_VELOCITY_SENSITIVITY(wxCommandEvent& event);
	void OnGLOBAL_PRESSURE_AFTERTOUCH(wxCommandEvent& event);
	void OnGLOBAL_PRESSURE_SENSITIVITY(wxCommandEvent& event);
void OnGLOBAL_FIXED_VELOCITY_VALUE(wxSpinEvent& event);
	void OnGLOBAL_MAX_VELOCITY_VALUE(wxSpinEvent& event);
void OnGLOBAL_MIN_VELOCITY_VALUE(wxSpinEvent& event);
	
// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;

// controls
				// Value is an LSVelocityRange
	wxRadioBox * wrbGLOBAL_VELOCITY_SENSITIVITY;
	// Values are constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscGLOBAL_MIN_VELOCITY_VALUE;
	wxSpinCtrl * wscGLOBAL_MAX_VELOCITY_VALUE;
	wxSpinCtrl * wscGLOBAL_FIXED_VELOCITY_VALUE;
	// Value is an LSPressureRange
	wxRadioBox * wrbGLOBAL_PRESSURE_SENSITIVITY;
	// Toggle
	wxCheckBox * chkGLOBAL_PRESSURE_AFTERTOUCH;
	};

