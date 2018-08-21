// FadersPage.h

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

class FadersPage : public wxPanel
{
public:
	FadersPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split);

private:
	LinnStrument * pMyLinnStrument;
	wxBookCtrlBase *pMyParent;
	LSPerSplitSettings m_Settings;

	// controls
				// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	wxSpinCtrl * wscCC_FOR_FADER1;
	wxSpinCtrl * wscCC_FOR_FADER2;
	wxSpinCtrl * wscCC_FOR_FADER3;
	wxSpinCtrl * wscCC_FOR_FADER4;
	wxSpinCtrl * wscCC_FOR_FADER5;
	wxSpinCtrl * wscCC_FOR_FADER6;
	wxSpinCtrl * wscCC_FOR_FADER7;
	wxSpinCtrl * wscCC_FOR_FADER8;
};

