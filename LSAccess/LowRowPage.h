// LowRowPage.h

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

class LowRowPage : public wxPanel
{
public:
	LowRowPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split);

private:
	// event handlers
	DECLARE_EVENT_TABLE()

	void OnCC_FOR_LOWROW(wxSpinEvent& event);
	void OnCC_FOR_LOWROW_XYZ(wxSpinEvent& event);
	void OnCC_FOR_LOWROW_XYZ_Y(wxSpinEvent& event);
	void OnCC_FOR_LOWROW_XYZ_Z(wxSpinEvent& event);
	void OnSPECIAL(wxSpinEvent& event);
	void OnLOWROW_X_BEHAVIOUR(wxCommandEvent& event);
	void OnLOWROW_XYZ_BEHAVIOUR(wxCommandEvent& event);
	void OnLOWROW_MODE(wxCommandEvent& event);
	void OnOCTAVE(wxCommandEvent& event);
	void OnPITCH_TRANSPOSE(wxCommandEvent& event);
	void OnTRANSPOSE_LIGHTS(wxCommandEvent& event);
	
	void OnGLOBAL_FIXED_VELOCITY_VALUE(wxSpinEvent& event);
	void OnGLOBAL_MAX_VELOCITY_VALUE(wxSpinEvent& event);
	void OnGLOBAL_MIN_VELOCITY_VALUE(wxSpinEvent& event);

	// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSPerSplitSettings m_Settings;
	LSSplitType m_Split;

// controls
	// Values are constrained by MIN_FADER_CC and MAX_FADER_CC
	wxSpinCtrl * wscCC_FOR_LOWROW;
	wxSpinCtrl * wscCC_FOR_LOWROW_XYZ;
	wxSpinCtrl * wscCC_FOR_LOWROW_XYZ_Y;
	wxSpinCtrl * wscCC_FOR_LOWROW_XYZ_Z;
	// Value is an LSSpecial:
	wxSpinCtrl  * wscSPECIAL;
	// Values are an LSLowRowBehaviour
	wxRadioBox * wrbLOWROW_X_BEHAVIOUR;
	wxRadioBox * wrbLOWROW_XYZ_BEHAVIOUR;
	// Value is an LSLowRowMode
	wxRadioBox * wrbLOWROW_MODE;
	// Value is an LSOctave
	wxRadioBox * wrbOCTAVE;
	// Values are from LSPitch
	wxRadioBox * wrbPITCH_TRANSPOSE;
	wxRadioBox * wrbTRANSPOSE_LIGHTS;
	};
