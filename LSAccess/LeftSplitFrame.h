// LeftSplitFrame.h
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

#include "LSEnums.h"
#include "ChannelsPage.h"
#include "PitchBendPage.h"


class LeftSplitFrame : public wxFrame
{
public:
	LeftSplitFrame(const wxString& title, LinnStrument * pLinnStrument);

private:
	void OnTabChanged(wxNotebookEvent& event);
	
	LinnStrument * pMyLinnStrument;
		wxNotebook * pNotebook;
	ChannelsPage * pChannelsPage;
	PitchBendPage * pPitchBendPage;

		DECLARE_EVENT_TABLE()
};
