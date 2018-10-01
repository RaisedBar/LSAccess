// PresetsVolumesDialog.h
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net

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

#include "wx/xrc/xmlres.h"
#include <wx/spinctrl.h>

#include "LinnStrument.h"
#include "LSConsts.h"

class PresetsVolumesDialog : public wxDialog
{
public:
	PresetsVolumesDialog(wxWindow* parent, LinnStrument * pLinnStrument);

private:
	void InitLeft();
	void InitRight();

// Event handlers
	DECLARE_EVENT_TABLE()

	void OnLeftGLOBAL_SETTINGS_PRESET_LOAD(wxCommandEvent& event);
	void OnLeftProgramNumber(wxSpinEvent& event);
	void OnLeftVolume(wxSpinEvent& event);
	void OnRightGLOBAL_SETTINGS_PRESET_LOAD(wxCommandEvent& event);
	void OnRightProgramNumber(wxSpinEvent& event);
	void OnRightVolume(wxSpinEvent& event);

// data
	LinnStrument * pMyLinnStrument;
};
