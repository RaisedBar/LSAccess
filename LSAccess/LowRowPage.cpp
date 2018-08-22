// LowRowPage.cpp

#include "LowRowPage.h"

LowRowPage::LowRowPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
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
			// Value is an LSLowRowMode
	wxString LowRowModes[] =
	{
		L"Normal",
			L"Sustain",
			L"Restrike",
			L"Strum",
			L"Arp",
			L"Bend"
			L"CC1",
		L"X,Y,Z=16-18"
	};
	wrbLOWROW_MODE = new wxRadioBox(myPanel, LOWROW_MODE_ID, L"&Mode", wxDefaultPosition, wxDefaultSize, WXSIZEOF(LowRowModes), LowRowModes, 0, wxRA_SPECIFY_ROWS);
	// Value is an LSLowRowBehaviour
	wxString LowRowBehaviour[] =
	{
	L"Hold",
	L"Fader"
	};
		wrbLOWROW_X_BEHAVIOUR = new wxRadioBox(myPanel, LOWROW_X_BEHAVIOUR_ID, L"&Low row X behaviour:", wxDefaultPosition, wxDefaultSize, WXSIZEOF(LowRowBehaviour), LowRowBehaviour, 0, wxRA_SPECIFY_ROWS);
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		wscCC_FOR_LOWROW = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), L"CC message");
			wrbLOWROW_XYZ_BEHAVIOUR = new wxRadioBox(myPanel, LOWROW_XYZ_BEHAVIOUR_ID, L"X,Y,Z X-axis behaviour", wxDefaultPosition, wxDefaultSize, WXSIZEOF(LowRowBehaviour), LowRowBehaviour, 0, wxRA_SPECIFY_ROWS);
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	wscCC_FOR_LOWROW_XYZ = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_XYZ_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "CC for &Low Row X,Y,Z - X");
		wscCC_FOR_LOWROW_XYZ_Y = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_XYZ_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "CC for X,Y,Z - Y");
	wscCC_FOR_LOWROW_XYZ_Z = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_XYZ_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "CC for X,Y,Z - Z");
	
	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}



