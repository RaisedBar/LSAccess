// BendPage.h

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

class BendPage : public wxPanel
{
public:
	BendPage()
	{};
	
	BendPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split);
	
protected:
	// controls
	// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
	wxSpinCtrl * wscBEND_RANGE;
	// Toggles:
	wxCheckBox * chkBEND_TOGGLE;
	wxCheckBox * chkBEND_QUANTIZE_TOGGLE;
	// Values are from LSPitchQuantize
	wxRadioBox * wrbBendQuantize;
	// Toggles:
	wxCheckBox * chkRESET_PITCH_ON_RELEASE;

private:
	// Event handlers
	DECLARE_EVENT_TABLE()

void OnBEND_RANGE(wxSpinEvent& event);
	void OnBEND_TOGGLE(wxCommandEvent& event);
	void OnBEND_QUANTIZE_TOGGLE(wxCommandEvent& event);
	void OnBendQuantize(wxCommandEvent& event);
	void OnRESET_PITCH_ON_RELEASE(wxCommandEvent& event);

	// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
		LSSplitType m_Split;
};
