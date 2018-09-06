// AxesPage.h

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

class AxesPage : public wxPanel
{
public:
	AxesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split);

private:
	// Event handlers
	DECLARE_EVENT_TABLE()

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

	   // controls
	wxCheckBox * chkSEND_Y, *chkSEND_Z;
	wxCheckBox * chkRELATIVE_Y, *chkRELATIVE_Z;
	wxSpinCtrl * wscMIN_CC_FOR_Y, *wscMIN_CC_FOR_Z;
		wxSpinCtrl * wscMAX_CC_FOR_Y, * wscMAX_CC_FOR_Z;
		wxSpinCtrl * wscCC_FOR_Y, *wscCC_FOR_Z;
		wxSpinCtrl * wscINITIAL_RELATIVE_VALUE_FOR_Y, *wscINITIAL_RELATIVE_VALUE_FOR_Z;
		wxRadioBox * wrbEXPRESSION_FOR_Y, *wrbEXPRESSION_FOR_Z;
		wxSpinCtrl * wsc14BIT_CC_VALUE_FOR_Z;

		// Data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
		LSSplitType m_Split;
};

