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
	chkGLOBAL_ACCENT_NOTE_LIGHT_C->SetValue(m_Settings.GetGLOBAL_ACCENT_NOTE_LIGHT_C());
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_ID, L"C#");
	chkGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP->SetValue(m_Settings.GetGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP());
		wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_D = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_D_ID, L"&D");
		chkGLOBAL_ACCENT_NOTE_LIGHT_D->SetValue(m_Settings.GetGLOBAL_ACCENT_NOTE_LIGHT_D());
			wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_ID, L"D#");
			chkGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP->SetValue(m_Settings.GetGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP());
			wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_E = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_E_ID, L"&E");
			chkGLOBAL_ACCENT_NOTE_LIGHT_E->SetValue(m_Settings.GetGLOBAL_ACCENT_NOTE_LIGHT_E());
				wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_F = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_F_ID, L"&F");
				chkGLOBAL_ACCENT_NOTE_LIGHT_F->SetValue(m_Settings.GetGLOBAL_ACCENT_NOTE_LIGHT_F());
				wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_ID, L"F#");
				chkGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP->SetValue(m_Settings.GetGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP());
				wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_G = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_G_ID, L"&G");
				chkGLOBAL_ACCENT_NOTE_LIGHT_G->SetValue(m_Settings.GetGLOBAL_ACCENT_NOTE_LIGHT_G());
					wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_ID, L"G#");
					chkGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP->SetValue(m_Settings.GetGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP());
					wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_A = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_A_ID, L"&A");
					chkGLOBAL_ACCENT_NOTE_LIGHT_A->SetValue(m_Settings.GetGLOBAL_ACCENT_NOTE_LIGHT_A());
					wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_ID, L"A#");
					chkGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP->SetValue(m_Settings.GetGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP());
					wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_B = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_B_ID, L"&B");
					chkGLOBAL_ACCENT_NOTE_LIGHT_B->SetValue(m_Settings.GetGLOBAL_ACCENT_NOTE_LIGHT_B());

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}



