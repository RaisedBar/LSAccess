// PitchBendPage.cpp

#include "PitchBendPage.h"

PitchBendPage::PitchBendPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl())
{
pMyLinnStrument = pLinnStrument;
m_Settings = pMyLinnStrument->GetMemoryLocation(pMyLinnStrument->GetActiveMemoryNumber()).GetPerSplitSettings();
pMyParent = parent;
wxPanel * myPanel = new wxPanel(this, -1);
wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

// Controls
// toggle
chkSPLIT_LEFT_BEND_TOGGLE = new wxCheckBox(myPanel, SPLIT_LEFT_BEND_TOGGLE_ID, L"Enable &Bend");
// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
wscSPLIT_LEFT_BEND_RANGE = new wxSpinCtrl(myPanel, SPLIT_LEFT_BEND_RANGE_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_BEND_RANGE, MAX_BEND_RANGE, m_Settings.GetSPLIT_LEFT_BEND_RANGE(), "Bend &range");
// toggle
chkSPLIT_LEFT_BEND_QUANTIZE_TOGGLE = new wxCheckBox(myPanel, SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_ID, L"&Quantize pitch bend");

// Values are from LSPitchQuantize
wxString BendTypes[] =
{
	L"Off",
	L"Medium",
	L"Fast",
	L"Slow"
};

			rdobPitchBendType = new wxRadioBox(myPanel, SPLIT_LEFT_BEND_TYPE_ID, L"Pitch bend &type:", wxDefaultPosition, wxDefaultSize, 4, BendTypes, 0, wxRA_SPECIFY_ROWS);
// Toggles:
chkSPLIT_LEFT_RESET_PITCH_ON_RELEASE = new wxCheckBox(myPanel, SPLIT_LEFT_RESET_PITCH_ON_RELEASE_ID, L"&&Reset pitch &on release");

myPanel->SetSizer(hBoxSettings);
hBoxSettings->SetSizeHints(this);
myPanel->Fit();
hBoxSettings->Fit(myPanel);
}


