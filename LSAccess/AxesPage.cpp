// AxesPage.cpp

#include "AxesPage.h"

AxesPage::AxesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
		pMyParent(new wxBookCtrl()),
	m_Split(split)
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetPerSplitSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * vBox1 = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer * hBoxY = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer * hBoxZ = new wxBoxSizer(wxHORIZONTAL);

	// Controls
				// toggles
	chkSEND_Y = new wxCheckBox(myPanel, SEND_Y_ID, L"&Send Y-axis timbre messages");
	chkSEND_Y->SetValue(m_Settings.GetSEND_Y(split));
	hBoxY->Add(chkSEND_Y, 0, wxEXPAND);
			// Values are constrained by MIN_CC and MAX_CC
	wscMIN_CC_FOR_Y = new wxSpinCtrl(myPanel, MIN_CC_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIN_CC_FOR_Y(split), "Min. CC value for Y-axis");
	hBoxY->Add(wscMIN_CC_FOR_Y, 0, wxEXPAND);
		wscMAX_CC_FOR_Y = new wxSpinCtrl(myPanel, MAX_CC_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMAX_CC_FOR_Y(split), "Max. value for Y-axis");
	hBoxY->Add(wscMAX_CC_FOR_Y, 0, wxEXPAND);
		// Values are constrained by MIN_CC and MAX_CC
	// CC 1 or CC 74 are recommended, any CC is possible though
	wscCC_FOR_Y = new wxSpinCtrl(myPanel, CC_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetCC_FOR_Y(split), "Y-axis message");
	hBoxY->Add(wscCC_FOR_Y, 0, wxEXPAND);

	// Toggle:
	chkRELATIVE_Y = new wxCheckBox(myPanel, RELATIVE_Y_ID, L"Relative &Y");
	chkRELATIVE_Y->SetValue(m_Settings.GetRELATIVE_Y(split));
	hBoxY->Add(chkRELATIVE_Y, 0, wxEXPAND);
			// Value is an LSExpressionY
		wrbEXPRESSION_FOR_Y = new wxRadioBox(myPanel, EXPRESSION_FOR_Y_ID, L"MIDI Expression for Y", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ExpressionY), ExpressionY, m_Settings.GetEXPRESSION_FOR_Y(split), wxRA_SPECIFY_ROWS);
		hBoxY->Add(wrbEXPRESSION_FOR_Y, 0, wxEXPAND);
				wscINITIAL_RELATIVE_VALUE_FOR_Y = new wxSpinCtrl(myPanel, INITIAL_RELATIVE_VALUE_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetINITIAL_RELATIVE_VALUE_FOR_Y(split), "&Initial relative value for Y-axis");
				hBoxY->Add(wscINITIAL_RELATIVE_VALUE_FOR_Y, 0, wxEXPAND);
				
				// toggle
		chkSEND_Z = new wxCheckBox(myPanel, SEND_Z_ID, L"&Send Z-axis loudness messages");
		chkSEND_Z->SetValue(m_Settings.GetSEND_Z(split));
		hBoxZ->Add(chkSEND_Z, 0, wxEXPAND);
				// Values are constrained by MIN_CC and MAX_CC
		wscMIN_CC_FOR_Z = new wxSpinCtrl(myPanel, MIN_CC_FOR_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMIN_CC_FOR_Z(split), "Min. CC value for Z-axis");
		hBoxZ->Add(wscMIN_CC_FOR_Z, 0, wxEXPAND);
		wscMAX_CC_FOR_Z = new wxSpinCtrl(myPanel, MAX_CC_FOR_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetMAX_CC_FOR_Z(split), "Min. CC value for Z-axis");
		hBoxZ->Add(wscMAX_CC_FOR_Z, 0, wxEXPAND);
		// Values are constrained by MIN_CC and MAX_CC
	// CC 11 is recommended, any CC is possible though
		wscCC_FOR_Z = new wxSpinCtrl(myPanel, CC_FOR_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.GetCC_FOR_Z(split), "CC for Z");
		hBoxZ->Add(wscCC_FOR_Z, 0, wxEXPAND);
		chkRELATIVE_Z = new wxCheckBox(myPanel, RELATIVE_Z_ID, L"&Relative &Z");
		chkRELATIVE_Z->SetValue(m_Settings.GetRELATIVE_Z(split));
		hBoxZ->Add(chkRELATIVE_Z, 0, wxEXPAND);
		// Value is an LSExpressionZ
		wrbEXPRESSION_FOR_Z = new wxRadioBox(myPanel, EXPRESSION_FOR_Z_ID, L"MIDI Expression for Z", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ExpressionZ), ExpressionZ, m_Settings.GetEXPRESSION_FOR_Z(split), wxRA_SPECIFY_ROWS);
		hBoxZ->Add(wrbEXPRESSION_FOR_Z, 0, wxEXPAND);
		wsc14BIT_CC_VALUE_FOR_Z = new wxSpinCtrl(myPanel, CC_VALUE_FOR_Z_14BIT_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, m_Settings.Get14BIT_CC_VALUE_FOR_Z(split), "14-&bit CC value for Z");
		hBoxZ->Add(wsc14BIT_CC_VALUE_FOR_Z, 0, wxEXPAND);

		vBox1->Add(hBoxY, 0, wxEXPAND);
		vBox1->Add(hBoxZ, 0, wxEXPAND);
		myPanel->SetSizer(vBox1);
	vBox1->SetSizeHints(this);
			vBox1->Fit(myPanel);
}


// Event handlers

void AxesPage::OnSEND_Y(wxCommandEvent& event)
{
	m_Settings.SetSEND_Y(chkSEND_Y->GetValue(), m_Split);
		}


void AxesPage::OnMIN_CC_FOR_Y(wxSpinEvent& event)
{
	m_Settings.SetMIN_CC_FOR_Y(wscMIN_CC_FOR_Y->GetValue(), m_Split);
}


void AxesPage::OnMAX_CC_FOR_Y(wxSpinEvent& event)
{
	m_Settings.SetMAX_CC_FOR_Y(wscMAX_CC_FOR_Y->GetValue(), m_Split);
}


void AxesPage::OnCC_FOR_Y(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_Y(wscCC_FOR_Y->GetValue(), m_Split);
}


void AxesPage::OnRELATIVE_Y(wxCommandEvent& event)
{
	m_Settings.SetRELATIVE_Y(chkRELATIVE_Y->GetValue(),  m_Split);
}


void AxesPage::OnEXPRESSION_FOR_Y(wxCommandEvent& event)
{
	m_Settings.SetEXPRESSION_FOR_Y(wrbEXPRESSION_FOR_Y->GetSelection(), m_Split);
}


void AxesPage::OnINITIAL_RELATIVE_VALUE_FOR_Y(wxSpinEvent& event)
{
	m_Settings.SetINITIAL_RELATIVE_VALUE_FOR_Y(wscINITIAL_RELATIVE_VALUE_FOR_Y->GetValue(), m_Split);
}


void AxesPage::OnSEND_Z(wxCommandEvent& event)
{
	m_Settings.SetSEND_Z(chkSEND_Z->GetValue(), m_Split);
}


void AxesPage::OnMIN_CC_FOR_Z(wxSpinEvent& event)
{
	m_Settings.SetMIN_CC_FOR_Z(wscMIN_CC_FOR_Z->GetValue(), m_Split);
}


void AxesPage::OnMAX_CC_FOR_Z(wxSpinEvent& event)
{
	m_Settings.SetMAX_CC_FOR_Y(wscMAX_CC_FOR_Y->GetValue(), m_Split);
}


void AxesPage::OnCC_FOR_Z(wxSpinEvent& event)
{
	m_Settings.SetCC_FOR_Z(wscCC_FOR_Z->GetValue(), m_Split);
}


void AxesPage::OnRELATIVE_Z(wxCommandEvent& event)
{
	m_Settings.SetRELATIVE_Z(chkRELATIVE_Z->GetValue(), m_Split);
}


void AxesPage::OnEXPRESSION_FOR_Z(wxCommandEvent& event)
{
	m_Settings.SetEXPRESSION_FOR_Z(wrbEXPRESSION_FOR_Z->GetSelection(), m_Split);
}


void AxesPage::On14BIT_CC_VALUE_FOR_Z(wxSpinEvent& event)
{
	m_Settings.Set14BIT_CC_VALUE_FOR_Z(wsc14BIT_CC_VALUE_FOR_Z->GetValue(), m_Split);
}


// Event table
BEGIN_EVENT_TABLE(AxesPage, wxPanel)
EVT_CHECKBOX(SEND_Y_ID, AxesPage::OnSEND_Y)
EVT_CHECKBOX(RELATIVE_Y_ID, AxesPage::OnRELATIVE_Y)
EVT_CHECKBOX(SEND_Z_ID, AxesPage::OnSEND_Z)
EVT_CHECKBOX(RELATIVE_Z_ID, AxesPage::OnRELATIVE_Z)

EVT_SPINCTRL(MIN_CC_FOR_Y_ID, AxesPage::OnMIN_CC_FOR_Y)
EVT_SPINCTRL(MAX_CC_FOR_Y_ID, AxesPage::OnMAX_CC_FOR_Y)
EVT_SPINCTRL(CC_FOR_Y_ID, AxesPage::OnCC_FOR_Y)
EVT_SPINCTRL(INITIAL_RELATIVE_VALUE_FOR_Y_ID, AxesPage::OnINITIAL_RELATIVE_VALUE_FOR_Y)
EVT_SPINCTRL(MIN_CC_FOR_Z_ID, AxesPage::OnMIN_CC_FOR_Z)
EVT_SPINCTRL(MAX_CC_FOR_Z_ID, AxesPage::OnMAX_CC_FOR_Z)
EVT_SPINCTRL(CC_FOR_Z_ID, AxesPage::OnCC_FOR_Z)
EVT_SPINCTRL(CC_VALUE_FOR_Z_14BIT_ID, AxesPage::On14BIT_CC_VALUE_FOR_Z)

EVT_RADIOBOX(EXPRESSION_FOR_Y_ID, AxesPage::OnEXPRESSION_FOR_Y)
EVT_RADIOBOX(EXPRESSION_FOR_Z_ID, AxesPage::OnEXPRESSION_FOR_Z)
END_EVENT_TABLE()
