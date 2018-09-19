// PerSplitDialog.h
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
#include "MIDISplitPage.h"
#include "BendPage.h"
#include "ColorsPage.h"
#include "LowRowPage.h"
#include "FadersPage.h"
#include "AxesPage.h"
#include "SpecialPage.h"

class PerSplitDialog : public wxDialog
{
public:
	PerSplitDialog();
	PerSplitDialog(const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split);
	bool Create(const wxString& title, LinnStrument * pLinnStrument, const LSSplitType split);

	private:
	void InitWidgetsFromXRC() 
	{ 
		wxXmlResource::Get()->LoadObject(this, NULL, "PerSplitDialog", "wxDialog");        
		}
	
// Event handlers
	void OnOK(wxCommandEvent& event);
			void OnTabChanged(wxNotebookEvent& event);
	
	LinnStrument * pMyLinnStrument;
		wxNotebook * pNotebook;
		MIDISplitPage * pMIDISplitPage;
	BendPage * pBendPage;
	ColorsPage * pColorsPage;
	LowRowPage * pLowRowPage;
		FadersPage * pFadersPage;
	AxesPage * pAxesPage;
	SpecialPage * pSpecialPage;
	
			DECLARE_EVENT_TABLE()
};

class PerSplitDialogXmlHandler : public wxXmlResourceHandler 
{
public:    
	// Constructor.    
	PerSplitDialogXmlHandler();    
	
	// Creates the control and returns a pointer to it.    
		virtual wxObject *DoCreateResource();    
				// Returns true if we know how to create a control for the given node.    
		bool CanHandle(wxXmlNode *node)
		{
			return true;
		}

	// Register with wxWidgets' dynamic class subsystem.    
	wxDECLARE_DYNAMIC_CLASS(PerSplitDialogXmlHandler);
};
