// LSAccess.cpp

#include "stdafx.h"
#include "LSAccess.h"

// Create a new application object: this macro will allow wxWidgets to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also implements the accessor function
// wxGetApp() which will return the reference of the right type (i.e. LSAccessApp and
// not wxApp)

wxIMPLEMENT_APP(LSAccessApp);

// 'Main program' equivalent: the program execution "starts" here

bool LSAccessApp::OnInit()
{
	// call the base class initialization method, currently it only parses a
	// few common command-line options but it could do more in the future

		if (!wxApp::OnInit())
		{
			return false;
		}

		// create the main application window
		LSAccessFrame *frame = new LSAccessFrame(L"LSAccess");

		// and show it (the frames, unlike simple controls, are not shown when
		// created initially)
			frame->Show(true);

			// success: wxApp::OnRun() will be called which will enter the main message
				// loop and the application will run. If we returned false here, the
				// application would exit immediately.
				return true;
				}
