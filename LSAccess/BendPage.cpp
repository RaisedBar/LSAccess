// BendPage.cpp

#include "BendPage.h"

BendPage::BendPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl())
{
pMyLinnStrument = pLinnStrument;
m_Settings = pMyLinnStrument->GetPerSplitSettings();
pMyParent = parent;
wxPanel * myPanel = new wxPanel(this, -1);
wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

// Controls
// toggle
chkBEND_TOGGLE = new wxCheckBox(myPanel, BEND_TOGGLE_ID, L"Pitch /&X");
// Value is constrained by MIN_BEND_RANGE and MAX_BEND_RANGE
wscBEND_RANGE = new wxSpinCtrl(myPanel, BEND_RANGE_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_BEND_RANGE, MAX_BEND_RANGE, m_Settings.GetBEND_RANGE(), "&range");
// toggle
chkBEND_QUANTIZE_TOGGLE = new wxCheckBox(myPanel, BEND_QUANTIZE_TOGGLE_ID, L"&Quantize");
// Values are from LSPitchQuantize
			wrbcPitchBendType = new wxRadioBox(myPanel, BEND_TYPE_ID, L"Quantization &type:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( BendTypes), BendTypes, m_Settings.GetPitchBendType(), wxRA_SPECIFY_ROWS);
// Toggles:
chkRESET_PITCH_ON_RELEASE = new wxCheckBox(myPanel, RESET_PITCH_ON_RELEASE_ID, L"&&Reset pitch &on release");

myPanel->SetSizer(hBoxSettings);
hBoxSettings->SetSizeHints(this);
myPanel->Fit();
hBoxSettings->Fit(myPanel);
}


