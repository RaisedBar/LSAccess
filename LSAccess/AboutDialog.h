// AboutDialog.h
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
#include <wx/dir.h>
#include <wx/textfile.h>
#include <wx/stdpaths.h>

#include "LSConsts.h"

class AboutDialog : public wxDialog
{
public:
	AboutDialog(wxWindow* parent);

private:
	// Event handlers
	DECLARE_EVENT_TABLE()

	void OnOK(wxCommandEvent& event);
	void OnLSLicense(wxCommandEvent& event);
	void OnSerialLicense(wxCommandEvent& event);
};
