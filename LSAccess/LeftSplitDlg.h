// LeftSplitDlg.h
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

class LeftSplitDlg: public wxDialog
{
public:
	LeftSplitDlg( const wxString& title);

private:
	// Event handlers:
	void OnOK( wxCommandEvent& event);
void OnCancel( wxCommandEvent& event);

DECLARE_EVENT_TABLE()
};
