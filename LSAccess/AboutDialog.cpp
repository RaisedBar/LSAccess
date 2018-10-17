// About.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net

#include "stdafx.h"
#include "AboutDialog.h"


AboutDialog::AboutDialog(wxWindow* parent)
		{
	if (wxXmlResource::Get()->LoadDialog(this, parent, wxT("help_about_dialog")))
	{
		XRCCTRL(*this, "txt_credits", wxTextCtrl)->SetValue(wstrRBCredit + wstrSerialCodeCopyright);
		XRCCTRL(*this, "txt_credits", wxTextCtrl)->SetEditable(false);
		}
	else
	{
		wxMessageBox("Could not load Help About dialog from XRC", wstrErrorTitle, wxOK | wxICON_ERROR);
		EndModal(false);
	}
}


// Event handlers

void AboutDialog::OnOK(wxCommandEvent& event)
{
	EndModal(true);
}


void AboutDialog::OnLSLicense( wxCommandEvent& event)
{
	wxString        wxstrFile( AppDataPath() + L"\\LICENSE");
		wxString        strLicense;

		// Attempt to open the file
	wxTextFile      tFile(wxstrFile);

	if (!tFile.Exists())
	{
		wxMessageBox( wstrNoFile + wxstrFile, wstrErrorTitle, wxOK | wxICON_ERROR);
	}
	else
	{
		tFile.Open();
		strLicense = tFile.GetFirstLine();

		while (!tFile.Eof())
		{
			strLicense = strLicense + tFile.GetNextLine();
		}
		tFile.Close();
				wxMessageBox(strLicense, wstrAppName);
	}
	}


void AboutDialog::OnSerialLicense(wxCommandEvent& event)
{
	wxMessageBox(wstrSerialCodeCopyright + wstrSerialCopyrightTerms, wstrAppName);
}


BEGIN_EVENT_TABLE(AboutDialog, wxDialog)
EVT_BUTTON(wxID_OK, AboutDialog::OnOK)
EVT_BUTTON(XRCID("btn_ls_license"), AboutDialog::OnLSLicense)
EVT_BUTTON(XRCID("btn_serial_license"), AboutDialog::OnSerialLicense)
END_EVENT_TABLE()
