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
#include "LSPerSplit.h"
#include "LSEnums.h"

class ColorsPage : public wxPanel
{
public:
	ColorsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split);

private:
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSPerSplitSettings m_Settings;

	// controls
				// Values are defined in LSColor
	wxRadioBox * wrbcCOLOR_MAIN, *wrbcCOLOR_ACCENT, *wrbcCOLOR_PLAYED, * wrbc_COLOR_LOWROW;
};
