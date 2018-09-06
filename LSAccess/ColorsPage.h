// ColorsPage.h

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

class ColorsPage : public wxPanel
{
public:
	ColorsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split);

private:
	// event handlers
	DECLARE_EVENT_TABLE()

void OnCOLOR_MAIN(wxCommandEvent& event);
void OnCOLOR_ACCENT(wxCommandEvent& event);
void OnCOLOR_PLAYED(wxCommandEvent& event);
void OnCOLOR_LOWROW(wxCommandEvent& event);
	void OnAnimation(wxCommandEvent& event);

	// data
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSSplitType m_Split;

	// controls
				// Values are defined in LSColor
	wxRadioBox * wrbCOLOR_MAIN, *wrbCOLOR_ACCENT, *wrbCOLOR_PLAYED, * wrbCOLOR_LOWROW;
	wxRadioBox * wrbAnimation;
};
