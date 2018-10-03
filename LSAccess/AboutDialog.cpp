// About.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net

#include "stdafx.h"
#include "AboutDialog.h"


wxString AppDataPath()
{
	#ifdef __WINDOWS__
	wxString wxstrAppPath = wxStandardPaths::Get().GetConfigDir();
	wxstrAppPath = wxstrAppPath.substr(0, wxstrAppPath.Find(wstrAppName));
	wxstrAppPath = wxstrAppPath + wstrVendor + L"\\" + wstrAppName;
#else
	wxDir myPath = wxStandardPaths::Get().GetExecutablePath();
#endif

	return wxstrAppPath;
}


AboutDialog::AboutDialog(wxWindow* parent)
	: wxDialog(NULL, wxID_ANY, L"")
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
	wxString        wxstrFile( AppDataPath() + L"\\" + L"LICENSE");
		wxString        strLicense;

		// Attempt to open the file
	wxTextFile      tFile(wxstrFile);

	if (!tFile.Exists())
	{
		wxMessageBox(L"Could not find " + wxstrFile, wstrErrorTitle, wxOK | wxICON_ERROR);
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
