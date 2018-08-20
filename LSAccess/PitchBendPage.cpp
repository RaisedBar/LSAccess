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
// Value is from LSBendRange
wxStaticText * lblSPLIT_LEFT_BEND_RANGE_NRPN = new wxStaticText(myPanel, wxID_ANY, L"&Bend Range:");
wscSPLIT_LEFT_BEND_RANGE_NRPN = new wxSpinCtrl(myPanel, SPLIT_LEFT_BEND_RANGE_NRPN, L"MIDI per row lowest channel");
chkSPLIT_LEFT_BEND_TOGGLE_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_BEND_TOGGLE_NRPN, L"Enable &pitch bend");
chkSPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN, L"&Quantize pitch bend");
// Value is from LSPitchQuantize
rdoSPLIT_LEFT_PITCH_QUANTIZE_NRPN = new wxRadioButton(myPanel, SPLIT_LEFT_PITCH_QUANTIZE_NRPN, L"&Quantize pitch bend type");
// Toggles:
chkSPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN, L"&&Reset pitch on release");

myPanel->SetSizer(hBoxSettings);
hBoxSettings->SetSizeHints(this);
myPanel->Fit();
hBoxSettings->Fit(myPanel);
}


/*
void PitchBendPage::SetPitchBendPage(CurrentPatchPage * pPage)
{
	pPatchPage = pPage;
}
*/


