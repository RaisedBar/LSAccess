// GlobalsAccentNoteLightsPage.cpp

#include "GlobalsAccentNoteLightsPage.h"

GlobalsAccentNoteLightsPage::GlobalsAccentNoteLightsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
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
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_C = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_C_ID, L"&C");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_ID, L"C#");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_D = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_D_ID, L"&D");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_ID, L"D#");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_E = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_E_ID, L"&E");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_F = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_F_ID, L"&F");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_ID, L"F#");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_G = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_G_ID, L"&G");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_ID, L"G#");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_A = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_A_ID, L"&A");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_ID, L"A#");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_B = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_B_ID, L"&B");

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}



