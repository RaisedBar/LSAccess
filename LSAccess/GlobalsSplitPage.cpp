// GlobalsSplitPage.cpp

#include "GlobalsSplitPage.h"

GlobalsSplitPage::GlobalsSplitPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetGlobalSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	chkGLOBAL_SPLIT_ACTIVE = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_ID, L"&Split");
	chkGLOBAL_SPLIT_ACTIVE->SetValue(m_Settings.GetGLOBAL_SPLIT_ACTIVE());
	hBox1->Add(chkGLOBAL_SPLIT_ACTIVE, 0, wxEXPAND);
	// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
wscGLOBAL_SPLIT_COLUMN = new wxSpinCtrl(myPanel, GLOBAL_SPLIT_COLUMN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_SPLIT_COLUMN, MAX_SPLIT_COLUMN, m_Settings.GetGLOBAL_SPLIT_COLUMN(), "Split &column");
	hBox1->Add(wscGLOBAL_SPLIT_COLUMN, 0, wxEXPAND);
	chkDEVICE_LEFT_HANDED = new wxCheckBox(myPanel, DEVICE_LEFT_HANDED_ID, L"&Left-handed");
	chkDEVICE_LEFT_HANDED->SetValue(m_Settings.GetDEVICE_LEFT_HANDED());
	hBox1->Add(chkDEVICE_LEFT_HANDED, 0, wxEXPAND);

	myPanel->SetSizer(hBox1);
	hBox1->SetSizeHints(this);
	myPanel->Fit();
	hBox1->Fit(myPanel);
}


void GlobalsSplitPage::OnGLOBAL_SPLIT_ACTIVE(wxCommandEvent& event)
{

}


void GlobalsSplitPage::OnDEVICE_LEFT_HANDED(wxCommandEvent& event)
{

}


void GlobalsSplitPage::OnGLOBAL_SPLIT_COLUMN(wxSpinEvent& event)
{

}


/// Event table
BEGIN_EVENT_TABLE(GlobalsSplitPage, wxPanel)
EVT_CHECKBOX(GLOBAL_SPLIT_ACTIVE_ID, GlobalsSplitPage::OnGLOBAL_SPLIT_ACTIVE)
EVT_CHECKBOX(DEVICE_LEFT_HANDED_ID, GlobalsSplitPage::OnDEVICE_LEFT_HANDED)
EVT_SPINCTRL(GLOBAL_SPLIT_COLUMN_ID, GlobalsSplitPage::OnGLOBAL_SPLIT_COLUMN)
END_EVENT_TABLE()
