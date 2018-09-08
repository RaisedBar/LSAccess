// GlobalsAccentNoteLightsPage.cpp

#include "GlobalsAccentNoteLightsPage.h"

GlobalsAccentNoteLightsPage::GlobalsAccentNoteLightsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument( pLinnStrument),
	pMyParent(parent)
{
		wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * vBox1 = new wxBoxSizer(wxVERTICAL);
		wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer * hBox2 = new wxBoxSizer(wxHORIZONTAL);

	// controls
// Toggles:
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_C = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_C_ID, L"&C");
	chkGLOBAL_ACCENT_NOTE_LIGHT_C->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_C()));
	hBox1->Add(chkGLOBAL_ACCENT_NOTE_LIGHT_C, 0, wxEXPAND);
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_ID, L"C#");
	chkGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP()));
	hBox1->Add(chkGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP, 0, wxEXPAND);
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_D = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_D_ID, L"&D");
		chkGLOBAL_ACCENT_NOTE_LIGHT_D->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_D()));
		hBox1->Add(chkGLOBAL_ACCENT_NOTE_LIGHT_D, 0, wxEXPAND);
		wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_ID, L"D#");
			chkGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP()));
			hBox1->Add(chkGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP, 0, wxEXPAND);
			wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_E = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_E_ID, L"&E");
			chkGLOBAL_ACCENT_NOTE_LIGHT_E->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_E()));
			hBox1->Add(chkGLOBAL_ACCENT_NOTE_LIGHT_E, 0, wxEXPAND);
			wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_F = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_F_ID, L"&F");
				chkGLOBAL_ACCENT_NOTE_LIGHT_F->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_F()));
				hBox1->Add(chkGLOBAL_ACCENT_NOTE_LIGHT_F, 0, wxEXPAND);
				
				wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_ID, L"F#");
				chkGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP()));
				hBox2->Add(chkGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP, 0, wxEXPAND);
				wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_G = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_G_ID, L"&G");
				chkGLOBAL_ACCENT_NOTE_LIGHT_G->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_G()));
				hBox2->Add(chkGLOBAL_ACCENT_NOTE_LIGHT_G, 0, wxEXPAND);
				wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_ID, L"G#");
					chkGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP()));
					hBox2->Add(chkGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP, 0, wxEXPAND);
					wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_A = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_A_ID, L"&A");
					chkGLOBAL_ACCENT_NOTE_LIGHT_A->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_A()));
					hBox2->Add(chkGLOBAL_ACCENT_NOTE_LIGHT_A, 0, wxEXPAND);
					wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_ID, L"A#");
					chkGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP()));
					hBox2->Add(chkGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP, 0, wxEXPAND);
					wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_B = new wxCheckBox(myPanel, GLOBAL_ACCENT_NOTE_LIGHT_B_ID, L"&B");
					chkGLOBAL_ACCENT_NOTE_LIGHT_B->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetGLOBAL_ACCENT_NOTE_LIGHT_B()));
					hBox2->Add(chkGLOBAL_ACCENT_NOTE_LIGHT_B, 0, wxEXPAND);

					vBox1->Add(hBox1, 0, wxEXPAND);
					vBox1->Add(hBox2, 0, wxEXPAND);

	myPanel->SetSizer(vBox1);
	vBox1->SetSizeHints(this);
	myPanel->Fit();
	vBox1->Fit(myPanel);
}


// Event handlers

void GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_C(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_C(LinnStrument::LSToggle(chkGLOBAL_ACCENT_NOTE_LIGHT_C->GetValue()));
}


void GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP(LinnStrument::LSToggle(chkGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP->GetValue()));
}


void GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_D(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_D(LinnStrument::LSToggle(chkGLOBAL_ACCENT_NOTE_LIGHT_D->GetValue()));
}


void GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP(LinnStrument::LSToggle(chkGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP->GetValue()));
}


void GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_E(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_E(LinnStrument::LSToggle(chkGLOBAL_ACCENT_NOTE_LIGHT_E->GetValue()));
}


void GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_F(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_F(LinnStrument::LSToggle(chkGLOBAL_ACCENT_NOTE_LIGHT_F->GetValue()));
}


void GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP(LinnStrument::LSToggle(chkGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP->GetValue()));
}


void GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_G(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_G(LinnStrument::LSToggle(chkGLOBAL_ACCENT_NOTE_LIGHT_G->GetValue()));
}


void GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP(LinnStrument::LSToggle(chkGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP->GetValue()));
}


void GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_A(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_A(LinnStrument::LSToggle(chkGLOBAL_ACCENT_NOTE_LIGHT_A->GetValue()));
}


void GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP(LinnStrument::LSToggle(chkGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP->GetValue()));
}


void GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_B(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ACCENT_NOTE_LIGHT_B(LinnStrument::LSToggle(chkGLOBAL_ACCENT_NOTE_LIGHT_B->GetValue()));
}


// Event table
BEGIN_EVENT_TABLE(GlobalsAccentNoteLightsPage, wxPanel)
EVT_CHECKBOX(GLOBAL_ACCENT_NOTE_LIGHT_C_ID, GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_C)
EVT_CHECKBOX(GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_ID, GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP)
EVT_CHECKBOX(GLOBAL_ACCENT_NOTE_LIGHT_D_ID, GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_D)
EVT_CHECKBOX(GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_ID, GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP)
EVT_CHECKBOX(GLOBAL_ACCENT_NOTE_LIGHT_E_ID, GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_E)
EVT_CHECKBOX(GLOBAL_ACCENT_NOTE_LIGHT_F_ID, GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_F)
EVT_CHECKBOX(GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_ID, GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP)
EVT_CHECKBOX(GLOBAL_ACCENT_NOTE_LIGHT_G_ID, GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_G)
EVT_CHECKBOX(GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_ID, GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP)

EVT_CHECKBOX(GLOBAL_ACCENT_NOTE_LIGHT_A_ID, GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_A)
EVT_CHECKBOX(GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_ID, GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP)
EVT_CHECKBOX(GLOBAL_ACCENT_NOTE_LIGHT_B_ID, GlobalsAccentNoteLightsPage::OnGLOBAL_ACCENT_NOTE_LIGHT_B)
END_EVENT_TABLE()
