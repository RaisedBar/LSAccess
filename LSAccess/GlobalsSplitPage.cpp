// GlobalsSplitPage.cpp

#include "GlobalsSplitPage.h"

GlobalsSplitPage::GlobalsSplitPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetGlobalSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	wxCheckBox * chkGLOBAL_SPLIT_ACTIVE = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_ID, L"&Split");
	chkGLOBAL_SPLIT_ACTIVE->SetValue(m_Settings.GetGLOBAL_SPLIT_ACTIVE());
	// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
	wxSpinCtrl * wscGLOBAL_SPLIT_COLUMN = new wxSpinCtrl(myPanel, GLOBAL_SPLIT_COLUMN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_SPLIT_COLUMN, MAX_SPLIT_COLUMN, m_Settings.GetGLOBAL_SPLIT_COLUMN(), "Split &column");
	wxCheckBox * chkDEVICE_LEFT_HANDED = new wxCheckBox(myPanel, DEVICE_LEFT_HANDED_ID, L"&Left-handed");
	chkDEVICE_LEFT_HANDED->SetValue(m_Settings.GetDEVICE_LEFT_HANDED());

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
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
