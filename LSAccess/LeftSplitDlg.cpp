// LeftSplitDlg.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "LeftSplitDlg.h"


LeftSplitDlg::LeftSplitDlg( const wxString& title)
       : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(250, 230))
	   {  
		wxPanel * myPanel = new wxPanel(this, -1);
		wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

		// Dialog buttons
wxBoxSizer * hBoxButtons= new wxBoxSizer( wxHORIZONTAL);
wxButton * OKButton = new wxButton(myPanel, wxID_OK, L"&OK", wxDefaultPosition, wxSize( wxDefaultSize));
wxButton * CancelButton = new wxButton(myPanel, wxID_CANCEL, L"&Cancel", wxDefaultPosition, wxSize( wxDefaultSize));
OKButton->SetDefault(); 
hBoxButtons->Add( OKButton, 0, wxEXPAND);
hBoxButtons->Add( CancelButton, 0, wxEXPAND);

wxBoxSizer * vBox1 = new wxBoxSizer( wxVERTICAL);
vBox1->Add( hBoxSettings);
vBox1->Add( hBoxButtons);	

myPanel->SetSizer( vBox1);
vBox1->SetSizeHints( this );
myPanel->Fit();
vBox1->Fit( myPanel);
Centre();
this->Maximize();
}


// Event handlers:

void LeftSplitDlg::OnOK( wxCommandEvent& event)
		{
	EndModal( wxID_OK);
		}

		
		void LeftSplitDlg::OnCancel( wxCommandEvent& event)
		{
		EndModal( wxID_CANCEL);
		}

		
		// We need to implement an event table in which the events received by a wxNewSurfaceDialog are routed to their respective handler functions 

	BEGIN_EVENT_TABLE(LeftSplitDlg, wxDialog)
		EVT_BUTTON( wxID_OK, LeftSplitDlg::OnOK)
	    EVT_BUTTON( wxID_CANCEL, LeftSplitDlg::OnCancel)
END_EVENT_TABLE()
