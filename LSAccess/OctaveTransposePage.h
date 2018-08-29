// OctaveTransposePage.h

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
#include "LSOctaveTranspose.h"
#include "LSEnums.h"

class OctaveTransposePage : public wxPanel
{
public:
	OctaveTransposePage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split);

private:
	// event handlers
	DECLARE_EVENT_TABLE()

	void OnOctave(wxCommandEvent& event);
	void OnPITCH_TRANSPOSE(wxCommandEvent& event);
	void OnTRANSPOSE_LIGHTS(wxCommandEvent& event);
	
	// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSOctaveTransposeSettings m_Settings;
	LSSplitType m_Split;

// controls
			// Value is an LSOctave
	wxRadioBox * wrbOctave;
	// Values are from LSPitch
	wxRadioBox * wrbPITCH_TRANSPOSE;
	wxRadioBox * wrbTRANSPOSE_LIGHTS;
};
