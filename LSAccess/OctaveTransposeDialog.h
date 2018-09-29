// OctaveTransposeDialog.h
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

#include <wx/notebook.h>
#include "wx/xrc/xmlres.h"

#include "LSEnums.h"
#include "OctaveTransposePage.h"

class OctaveTransposeDialog : public wxDialog
{
public:
	OctaveTransposeDialog(wxWindow* parent, LinnStrument * pLinnStrument);

private:
	void InitLeft();
	void InitRight();
	
// Event handlers
	void OnLeftOctave(wxCommandEvent& event);
	void OnLeftPITCH_TRANSPOSE(wxCommandEvent& event);
	void OnLeftTRANSPOSE_LIGHTS(wxCommandEvent& event);
	void OnRightOctave(wxCommandEvent& event);
	void OnRightPITCH_TRANSPOSE(wxCommandEvent& event);
	void OnRightTRANSPOSE_LIGHTS(wxCommandEvent& event);

// data
	LinnStrument * pMyLinnStrument;
	wxNotebook * pNotebook;
	
	DECLARE_EVENT_TABLE()
};
