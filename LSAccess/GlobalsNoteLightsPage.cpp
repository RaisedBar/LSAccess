// GlobalsNoteLightsPage.cpp

#include "GlobalsNoteLightsPage.h"

GlobalsNoteLightsPage::GlobalsNoteLightsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetGlobalSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	
	wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);
	
		// controls
// Toggles:
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_C_NRPN = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_C_NRPN_ID, L"&C");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_C_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_NRPN_ID, L"C#");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_D_NRPN = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_D_NRPN_ID, L"&D");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_D_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_NRPN_ID, L"D#");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_E_NRPN = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_E_NRPN_ID, L"&E");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_F_NRPN = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_F_NRPN_ID, L"&F");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_F_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_NRPN_ID, L"F#");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_G_NRPN = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_G_NRPN_ID, L"&G");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_G_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_NRPN_ID, L"G#");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_A_NRPN = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_A_NRPN_ID, L"&A");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_A_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_NRPN_ID, L"A#");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_B_NRPN = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_B_NRPN_ID, L"&B");

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}



