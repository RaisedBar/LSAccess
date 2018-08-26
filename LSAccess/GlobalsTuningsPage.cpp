// GlobalsTuningsPage.cpp

#include "GlobalsTuningsPage.h"

GlobalsTuningsPage::GlobalsTuningsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
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
		// Value is an LSRowOffsetType
		wxRadioBox * wrbGLOBAL_ROW_OFFSET = new wxRadioBox(myPanel, GLOBAL_ROW_OFFSET_ID, L"Row offset &type", wxDefaultPosition, wxDefaultSize, WXSIZEOF(RowOffsetTypes), RowOffsetTypes, m_Settings.GetGLOBAL_ROW_OFFSET(), wxRA_SPECIFY_ROWS);
	// Value is an LSCustomRowOffset
	wxRadioBox * wrbGLOBAL_CUSTOM_ROW_OFFSET = new wxRadioBox(myPanel, GLOBAL_CUSTOM_ROW_OFFSET_ID, L"&Custom row offset", wxDefaultPosition, wxDefaultSize, WXSIZEOF(CustomRowOffsets), CustomRowOffsets, m_Settings.GetGLOBAL_CUSTOM_ROW_OFFSET(), wxRA_SPECIFY_ROWS);
	// Values are constrained by MIN_CC and MAX_CC
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW1 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW1_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_GUITAR_NOTE_TUNING_ROW1(), "Row &1 tuning");
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW2 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW2_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_GUITAR_NOTE_TUNING_ROW2(), "Row &2 tuning");
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW3 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW3_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_GUITAR_NOTE_TUNING_ROW3(), "Row &3 tuning");
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW4 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW4_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_GUITAR_NOTE_TUNING_ROW4(), "Row &4 tuning");
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW5 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW5_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_GUITAR_NOTE_TUNING_ROW5(), "Row &5 tuning");
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW6 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW6_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_GUITAR_NOTE_TUNING_ROW6(), "Row &6 tuning");
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW7 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW7_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_GUITAR_NOTE_TUNING_ROW7(), "Row &7 tuning");
	wxSpinCtrl * wscGLOBAL_GUITAR_NOTE_TUNING_ROW8 = new wxSpinCtrl(myPanel, GLOBAL_GUITAR_NOTE_TUNING_ROW8_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetGLOBAL_GUITAR_NOTE_TUNING_ROW8(), "Row &8 tuning");

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}



