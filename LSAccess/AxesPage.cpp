// AxesPage.cpp

#include "AxesPage.h"

AxesPage::AxesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
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
				// toggles
	chkSEND_Y = new wxCheckBox(myPanel, SEND_Y_ID, L"&Send Y-axis timbre messages");
	// Values are constrained by MIN_CC and MAX_CC
	wscMIN_CC_FOR_Y = new wxSpinCtrl(myPanel, MIN_CC_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "Min. CC value for Y-axis");
	wscMAX_CC_FOR_Y = new wxSpinCtrl(myPanel, MAX_CC_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "Max. value for Y-axis");
	// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	wscCC_FOR_Y = new wxSpinCtrl(myPanel, CC_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "Y-axis message");
	// Toggle:
	chkRELATIVE_Y = new wxCheckBox(myPanel, RELATIVE_Y_ID, L"Relative &Y");
		// Value is an LSExpressionY
	wxString ExpressionY[] =
	{
L"Poly Aftertouch",
	L"Channel Aftertouch",
	L"CC defined in 25"
	};
		wrbEXPRESSION_FOR_Y = new wxRadioBox(myPanel, MIDI_EXPRESSION_FOR_Y_ID, L"MIDI Expression for Y", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ExpressionY), ExpressionY, 0, wxRA_SPECIFY_ROWS);
		wscINITIAL_RELATIVE_VALUE_FOR_Y = new wxSpinCtrl(myPanel, INITIAL_RELATIVE_VALUE_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "&Initial relative value for Y-axis");

		// toggle
		chkSEND_Z = new wxCheckBox(myPanel, SEND_Z_ID, L"&Send Z-axis loudness messages");
				// Values are constrained by MIN_CC and MAX_CC
		wscMIN_CC_FOR_Z = new wxSpinCtrl(myPanel, MIN_CC_FOR_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "Min. CC value for Z-axis");
		wscMAX_CC_FOR_Z = new wxSpinCtrl(myPanel, MAX_CC_FOR_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "Min. CC value for Z-axis");
		// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
		wscCC_FOR_Z = new wxSpinCtrl(myPanel, CC_FOR_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "CC for Z");
		chkRELATIVE_Z = new wxCheckBox(myPanel, RELATIVE_Z_ID, L"&Relative &Z");
		// Value is an LSExpressionZ
		wxString ExpressionZ[] =
		{
	L"Poly Aftertouch",
		L"Channel Aftertouch",
		L"CC defined in 29"
		};
		wrbMIDI_EXPRESSION_FOR_Z = new wxRadioBox(myPanel, MIDI_EXPRESSION_FOR_Z_ID, L"MIDI Expression for Z", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ExpressionZ), ExpressionZ, 0, wxRA_SPECIFY_ROWS);
				wsc14BIT_CC_VALUE_FOR_Z = new wxSpinCtrl(myPanel, CC_VALUE_FOR_Z_14BIT_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "14-&bit CC value for Z");

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


