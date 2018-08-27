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
wscBEND_RANGE = new wxSpinCtrl(myPanel, BEND_RANGE_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_BEND_RANGE, MAX_BEND_RANGE, m_Settings.GetBEND_RANGE(split), "&range");
// toggle
chkBEND_QUANTIZE_TOGGLE = new wxCheckBox(myPanel, BEND_QUANTIZE_TOGGLE_ID, L"&Quantize");
chkBEND_QUANTIZE_TOGGLE->SetValue(m_Settings.GetBEND_TOGGLE(split));
// Values are from LSPitchQuantize
			wrbBendQuantize = new wxRadioBox(myPanel, BEND_QUANTIZE_ID, L"Quantization &type:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( BendQuantizations), BendQuantizations, m_Settings.GetBEND_QUANTIZE(split), wxRA_SPECIFY_ROWS);
// Toggles:
chkRESET_PITCH_ON_RELEASE = new wxCheckBox(myPanel, RESET_PITCH_ON_RELEASE_ID, L"&&Reset pitch &on release");
chkRESET_PITCH_ON_RELEASE->SetValue(m_Settings.GetRESET_PITCH_ON_RELEASE(split));

myPanel->SetSizer(hBoxSettings);
hBoxSettings->SetSizeHints(this);
myPanel->Fit();
hBoxSettings->Fit(myPanel);
}


void BendPage::OnBEND_RANGE(wxSpinEvent& event)
{}


void BendPage::OnBEND_TOGGLE(wxCommandEvent& event)
{}


void BendPage::OnBEND_QUANTIZE_TOGGLE(wxCommandEvent& event)
{}


void BendPage::OnBendQuantize(wxCommandEvent& event)
{}


void BendPage::OnRESET_PITCH_ON_RELEASE(wxCommandEvent& event)
{}


// Event table
BEGIN_EVENT_TABLE(BendPage, wxPanel)
EVT_CHECKBOX(BEND_TOGGLE_ID, BendPage::OnBEND_TOGGLE)
EVT_CHECKBOX(BEND_QUANTIZE_TOGGLE_ID, BendPage::OnBEND_QUANTIZE_TOGGLE)
EVT_CHECKBOX(RESET_PITCH_ON_RELEASE_ID, BendPage::OnRESET_PITCH_ON_RELEASE)

EVT_SPINCTRL(BEND_RANGE_ID, BendPage::OnBEND_RANGE)

EVT_RADIOBOX(BEND_QUANTIZE_ID, BendPage::OnBendQuantize)
END_EVENT_TABLE()
