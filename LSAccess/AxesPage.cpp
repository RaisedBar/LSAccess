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
	chkSEND_Y = new wxCheckBox(myPanel, SEND_Y_ID, L"&Send Y");
	// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	wscCC_FOR_Y = new wxSpinCtrl(myPanel, CC_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "CC for Y");
	// Toggle:
	chkRELATIVE_Y = new wxCheckBox(myPanel, RELATIVE_Y_ID, L"Relative &Y");
	chkRELATIVE_Z = new wxCheckBox(myPanel, RELATIVE_Z_ID, L"&Relative &Z");
	// Value is an LSExpressionZ
	wxString ExpressionZ[] =
	{
L"Poly Aftertouch",
	L"Channel Aftertouch",
	L"CC defined in 29"
	};

	wrbMIDI_EXPRESSION_FOR_Z = new wxRadioBox(myPanel, MIDI_EXPRESSION_FOR_Z_ID, L"&MIDI Expression for Z:", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ExpressionZ), ExpressionZ, 0, wxRA_SPECIFY_ROWS);
	
	// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
	wscCC_FOR_Z = new wxSpinCtrl(myPanel, CC_FOR_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "CC for Z");
	// Value is an LSExpressionY
	wxString ExpressionY[] =
	{
L"Poly Aftertouch",
	L"Channel Aftertouch",
	L"CC defined in 25"
	};

	wrbEXPRESSION_FOR_Y = new wxRadioBox(myPanel, MIDI_EXPRESSION_FOR_Y_ID, L"&MIDI Expression for Y:", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ExpressionY), ExpressionY, 0, wxRA_SPECIFY_ROWS);
	// Value is an LSLowRowBehaviour
	wxString LowRowBehaviour[] = 
	{
	L"Hold",
	L"Fader"
	};

	wrbLOWROW_X_BEHAVIOUR = new wxRadioBox(myPanel, LOWROW_X_BEHAVIOUR_ID, L"&Low row X behaviour:", wxDefaultPosition, wxDefaultSize, WXSIZEOF(LowRowBehaviour), LowRowBehaviour, 0, wxRA_SPECIFY_ROWS);
	wrbLOWROW_XYZ_BEHAVIOUR = new wxRadioBox(myPanel, LOWROW_XYZ_BEHAVIOUR_ID, L"&Low row X Y Z behaviour:", wxDefaultPosition, wxDefaultSize, WXSIZEOF(LowRowBehaviour), LowRowBehaviour, 0, wxRA_SPECIFY_ROWS);
	// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
	wscCC_FOR_LOWROW_XYZ = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_XYZ_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "CC for &Low Row X Y Z");
	wscCC_FOR_LOWROW_XYZ_Y = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_XYZ_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "CC for Low Row X Y Z - Y");
	wscCC_FOR_LOWROW_XYZ_Z = new wxSpinCtrl(myPanel, CC_FOR_LOWROW_XYZ_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_FADER_CC, MAX_FADER_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "CC for Low Row X Y Z - Z");
	// Values are constrained by MIN_CC and MAX_CC
	wscMIN_CC_FOR_Y = new wxSpinCtrl(myPanel, MIN_CC_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "Min. CC for Y");
	wscMAX_CC_FOR_Y = new wxSpinCtrl(myPanel, MAX_CC_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "Max. CC for Y");
	wscMIN_CC_FOR_Z = new wxSpinCtrl(myPanel, MIN_CC_FOR_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "Min. CC for Z");
	wscMAX_CC_FOR_Z = new wxSpinCtrl(myPanel, MAX_CC_FOR_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "Max. CC for Z");
	wsc14BIT_CC_VALUE_FOR_Z = new wxSpinCtrl(myPanel, CC_VALUE_FOR_Z_14BIT_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "14-&bit CC value for Z");
	wscINITIAL_RELATIVE_VALUE_FOR_Y = new wxSpinCtrl(myPanel, INITIAL_RELATIVE_VALUE_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "&Initial relative value for Y");

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


