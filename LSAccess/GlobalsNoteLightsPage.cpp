// GlobalsNoteLightsPage.cpp

#include "GlobalsNoteLightsPage.h"

GlobalsNoteLightsPage::GlobalsNoteLightsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetGlobalSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * vBox1 = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer * hBox2 = new wxBoxSizer(wxHORIZONTAL);

		// controls
// Value is constrained by MIN_LIGHTS_PRESET and MAX_LIGHTS_PRESET 
	wscGLOBAL_ACTIVE_LIGHTS_PRESET = new wxSpinCtrl(myPanel, GLOBAL_ACTIVE_LIGHTS_PRESET_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_LIGHTS_PRESET, MAX_LIGHTS_PRESET, m_Settings.GetGLOBAL_ACTIVE_LIGHTS_PRESET(), L"Preset");
vBox1->Add(wscGLOBAL_ACTIVE_LIGHTS_PRESET, 0, wxEXPAND);
	
// Toggles:
	chkGLOBAL_MAIN_NOTE_LIGHT_C = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_C_ID, L"&C");
	chkGLOBAL_MAIN_NOTE_LIGHT_C->SetValue(m_Settings.GetGLOBAL_MAIN_NOTE_LIGHT_C());
	hBox1->Add(chkGLOBAL_MAIN_NOTE_LIGHT_C, 0, wxEXPAND);
	chkGLOBAL_MAIN_NOTE_LIGHT_C_SHARP = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_ID, L"C#");
	chkGLOBAL_MAIN_NOTE_LIGHT_C_SHARP->SetValue(m_Settings.GetGLOBAL_MAIN_NOTE_LIGHT_C_SHARP());
	hBox1->Add(chkGLOBAL_MAIN_NOTE_LIGHT_C_SHARP, 0, wxEXPAND);
	chkGLOBAL_MAIN_NOTE_LIGHT_D = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_D_ID, L"&D");
	chkGLOBAL_MAIN_NOTE_LIGHT_D->SetValue(m_Settings.GetGLOBAL_MAIN_NOTE_LIGHT_D());
	hBox1->Add(chkGLOBAL_MAIN_NOTE_LIGHT_D, 0, wxEXPAND);
	chkGLOBAL_MAIN_NOTE_LIGHT_D_SHARP = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_ID, L"D#");
	chkGLOBAL_MAIN_NOTE_LIGHT_D_SHARP->SetValue(m_Settings.GetGLOBAL_MAIN_NOTE_LIGHT_D_SHARP());
	hBox1->Add(chkGLOBAL_MAIN_NOTE_LIGHT_D_SHARP, 0, wxEXPAND);
	chkGLOBAL_MAIN_NOTE_LIGHT_E = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_E_ID, L"&E");
	chkGLOBAL_MAIN_NOTE_LIGHT_E->SetValue(m_Settings.GetGLOBAL_MAIN_NOTE_LIGHT_E());
	hBox1->Add(chkGLOBAL_MAIN_NOTE_LIGHT_E, 0, wxEXPAND);
	chkGLOBAL_MAIN_NOTE_LIGHT_F = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_F_ID, L"&F");
	chkGLOBAL_MAIN_NOTE_LIGHT_F->SetValue(m_Settings.GetGLOBAL_MAIN_NOTE_LIGHT_F());
	hBox1->Add(chkGLOBAL_MAIN_NOTE_LIGHT_F, 0, wxEXPAND);
	
	chkGLOBAL_MAIN_NOTE_LIGHT_F_SHARP = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_ID, L"F#");
	chkGLOBAL_MAIN_NOTE_LIGHT_F_SHARP->SetValue(m_Settings.GetGLOBAL_MAIN_NOTE_LIGHT_F_SHARP());
	hBox2->Add(chkGLOBAL_MAIN_NOTE_LIGHT_F_SHARP, 0, wxEXPAND);
	chkGLOBAL_MAIN_NOTE_LIGHT_G = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_G_ID, L"&G");
	chkGLOBAL_MAIN_NOTE_LIGHT_G->SetValue(m_Settings.GetGLOBAL_MAIN_NOTE_LIGHT_G());
	hBox2->Add(chkGLOBAL_MAIN_NOTE_LIGHT_G, 0, wxEXPAND);
	chkGLOBAL_MAIN_NOTE_LIGHT_G_SHARP = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_ID, L"G#");
	chkGLOBAL_MAIN_NOTE_LIGHT_G_SHARP->SetValue(m_Settings.GetGLOBAL_MAIN_NOTE_LIGHT_G_SHARP());
	hBox2->Add(chkGLOBAL_MAIN_NOTE_LIGHT_G_SHARP, 0, wxEXPAND);
	chkGLOBAL_MAIN_NOTE_LIGHT_A = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_A_ID, L"&A");
	chkGLOBAL_MAIN_NOTE_LIGHT_A->SetValue(m_Settings.GetGLOBAL_MAIN_NOTE_LIGHT_A());
	hBox2->Add(chkGLOBAL_MAIN_NOTE_LIGHT_A, 0, wxEXPAND);
	chkGLOBAL_MAIN_NOTE_LIGHT_A_SHARP = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_ID, L"A#");
	chkGLOBAL_MAIN_NOTE_LIGHT_A_SHARP->SetValue(m_Settings.GetGLOBAL_MAIN_NOTE_LIGHT_A_SHARP());
	hBox2->Add(chkGLOBAL_MAIN_NOTE_LIGHT_A_SHARP, 0, wxEXPAND);
	chkGLOBAL_MAIN_NOTE_LIGHT_B = new wxCheckBox(myPanel, GLOBAL_MAIN_NOTE_LIGHT_B_ID, L"&B");
chkGLOBAL_MAIN_NOTE_LIGHT_B->SetValue(m_Settings.GetGLOBAL_MAIN_NOTE_LIGHT_B());
hBox2->Add(chkGLOBAL_MAIN_NOTE_LIGHT_B, 0, wxEXPAND);

vBox1->Add(hBox1, 0, wxEXPAND);
vBox1->Add(hBox2, 0, wxEXPAND);

	myPanel->SetSizer(vBox1);
	vBox1->SetSizeHints(this);
	myPanel->Fit();
	vBox1->Fit(myPanel);
}





void GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_C(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_MAIN_NOTE_LIGHT_C(chkGLOBAL_MAIN_NOTE_LIGHT_C->GetValue());
}


void GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_C_SHARP(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_MAIN_NOTE_LIGHT_C_SHARP(chkGLOBAL_MAIN_NOTE_LIGHT_C_SHARP->GetValue());
}


void GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_D(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_MAIN_NOTE_LIGHT_D(chkGLOBAL_MAIN_NOTE_LIGHT_D->GetValue());
}


void GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_D_SHARP(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_MAIN_NOTE_LIGHT_D_SHARP(chkGLOBAL_MAIN_NOTE_LIGHT_D_SHARP->GetValue());
}


void GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_E(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_MAIN_NOTE_LIGHT_E(chkGLOBAL_MAIN_NOTE_LIGHT_E->GetValue());
}


void GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_F(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_MAIN_NOTE_LIGHT_F(chkGLOBAL_MAIN_NOTE_LIGHT_F->GetValue());
}


void GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_F_SHARP(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_MAIN_NOTE_LIGHT_F_SHARP(chkGLOBAL_MAIN_NOTE_LIGHT_F_SHARP->GetValue());
}


void GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_G(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_MAIN_NOTE_LIGHT_G(chkGLOBAL_MAIN_NOTE_LIGHT_G->GetValue());
}


void GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_G_SHARP(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_MAIN_NOTE_LIGHT_G_SHARP(chkGLOBAL_MAIN_NOTE_LIGHT_G_SHARP->GetValue());
}


void GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_A(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_MAIN_NOTE_LIGHT_A(chkGLOBAL_MAIN_NOTE_LIGHT_A->GetValue());
}


void GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_A_SHARP(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_MAIN_NOTE_LIGHT_A_SHARP(chkGLOBAL_MAIN_NOTE_LIGHT_A_SHARP->GetValue());
}


void GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_B(wxCommandEvent& event)
{
	m_Settings.SetGLOBAL_MAIN_NOTE_LIGHT_B(chkGLOBAL_MAIN_NOTE_LIGHT_B->GetValue());
}


void GlobalsNoteLightsPage::OnGLOBAL_ACTIVE_LIGHTS_PRESET(wxSpinEvent& event)
{
	m_Settings.SetGLOBAL_ACTIVE_LIGHTS_PRESET(wscGLOBAL_ACTIVE_LIGHTS_PRESET->GetValue());
}


// Event table
BEGIN_EVENT_TABLE(GlobalsNoteLightsPage, wxPanel)
EVT_CHECKBOX(GLOBAL_MAIN_NOTE_LIGHT_C_ID, GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_C)
EVT_CHECKBOX(GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_ID, GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_C_SHARP)
EVT_CHECKBOX(GLOBAL_MAIN_NOTE_LIGHT_D_ID, GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_D)
EVT_CHECKBOX(GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_ID, GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_D_SHARP)
EVT_CHECKBOX(GLOBAL_MAIN_NOTE_LIGHT_E_ID, GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_E)
EVT_CHECKBOX(GLOBAL_MAIN_NOTE_LIGHT_F_ID, GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_F)
EVT_CHECKBOX(GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_ID, GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_F_SHARP)
EVT_CHECKBOX(GLOBAL_MAIN_NOTE_LIGHT_G_ID, GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_G)
EVT_CHECKBOX(GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_ID, GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_G_SHARP)

EVT_CHECKBOX(GLOBAL_MAIN_NOTE_LIGHT_A_ID, GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_A)
EVT_CHECKBOX(GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_ID, GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_A_SHARP)
EVT_CHECKBOX(GLOBAL_MAIN_NOTE_LIGHT_B_ID, GlobalsNoteLightsPage::OnGLOBAL_MAIN_NOTE_LIGHT_B)

EVT_SPINCTRL(GLOBAL_ACTIVE_LIGHTS_PRESET_ID, GlobalsNoteLightsPage::OnGLOBAL_ACTIVE_LIGHTS_PRESET)
END_EVENT_TABLE()
