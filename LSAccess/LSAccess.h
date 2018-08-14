// LSAccess.h
// User interface definitions for the LSAccess application

#pragma once

#include "resource.h"
#include "LinnStrument.h"

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

// define this to 1 to use HTML help even under Windows (by default, Windows
// version will use WinHelp).
// Please also see samples/html/helpview.
#define USE_HTML_HELP 1

#ifdef __WINDOWS__ 
// define this to 1 to use external help controller (not used by default)
#define USE_EXT_HELP 0
// Define this to 0 to use the help controller as the help
// provider, or to 1 to use the 'simple help provider'
// (the one implemented with wxTipWindow).
#define USE_SIMPLE_HELP_PROVIDER 0
#else   // Mac
#define USE_EXT_HELP 1
#define USE_SIMPLE_HELP_PROVIDER 1
#endif

#include <wx/snglinst.h>
#include <wx/msw/winundef.h> 


class LSAccessApp : public wxApp
{
public:
	LSAccessApp();
	virtual ~LSAccessApp() {};

	virtual bool OnInit();

	// Check for multiple instances
	wxSingleInstanceChecker * m_checker;
};
