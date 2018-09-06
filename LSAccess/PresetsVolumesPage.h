// PresetsVolumesPage.h

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

class PresetsVolumesPage : public wxPanel
{
public:
	PresetsVolumesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, LSSplitType split);

private:
	// event handlers
	DECLARE_EVENT_TABLE()

	void OnGLOBAL_SETTINGS_PRESET_LOAD(wxCommandEvent& event);
		void OnProgramNumber(wxSpinEvent& event);
	void OnVolume(wxSpinEvent& event);

	// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSSplitType m_Split;
	
	// Controls
			// Value is an LSPresetNumber
	wxRadioBox * wrbGLOBAL_SETTINGS_PRESET_LOAD;
	// Values constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscProgramNumber;
	wxSpinCtrl * wscVolume;
};

