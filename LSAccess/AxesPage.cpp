// AxesPage.cpp
#include "stdafx.h"
#include "AxesPage.h"

AxesPage::AxesPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	m_Split(split),
	pMyLinnStrument( pLinnStrument),
	pMyParent(parent)
	{
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * vBox1 = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer * hBoxY = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer * hBoxZ = new wxBoxSizer(wxHORIZONTAL);

	// Controls
				// toggles
	chkSEND_Y = new wxCheckBox(myPanel, SEND_Y_ID, L"&Send Y-axis timbre messages");
	chkSEND_Y->SetValue( LinnStrument::LSToggle( pMyLinnStrument->GetSEND_Y(split)));
	hBoxY->Add(chkSEND_Y, 0, wxEXPAND);
			
	// Values are constrained by MIN_CC and MAX_CC
		// CC 1 or CC 74 are recommended, any CC is possible though
	wxStaticText * lblCC_FOR_Y = new wxStaticText(myPanel, wxID_ANY, L"CC for Y:");
	wscCC_FOR_Y = new wxSpinCtrl(myPanel, CC_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetCC_FOR_Y(split), "Y-axis message");
	hBoxY->Add(lblCC_FOR_Y, 0, wxEXPAND);
	hBoxY->Add(wscCC_FOR_Y, 0, wxEXPAND);

	// Values are constrained by MIN_CC and MAX_CC
	wxStaticText * lblMIN_CC_FOR_Y = new wxStaticText(myPanel, wxID_ANY, L"Min. Y value:");
	wscMIN_CC_FOR_Y = new wxSpinCtrl(myPanel, MIN_CC_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetMIN_CC_FOR_Y(split), "Min. CC value for Y-axis");
	hBoxY->Add(lblMIN_CC_FOR_Y, 0, wxEXPAND);
	hBoxY->Add(wscMIN_CC_FOR_Y, 0, wxEXPAND);

	wxStaticText * lblMAX_CC_FOR_Y = new wxStaticText(myPanel, wxID_ANY, L"Max. Y value:");
	wscMAX_CC_FOR_Y = new wxSpinCtrl(myPanel, MAX_CC_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetMAX_CC_FOR_Y(split), "Max. value for Y-axis");
	hBoxY->Add(lblMAX_CC_FOR_Y, 0, wxEXPAND);
	hBoxY->Add(wscMAX_CC_FOR_Y, 0, wxEXPAND);
	
	// Toggle:
	chkRELATIVE_Y = new wxCheckBox(myPanel, RELATIVE_Y_ID, L"Relative &Y");
	chkRELATIVE_Y->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetRELATIVE_Y(split)));
	hBoxY->Add(chkRELATIVE_Y, 0, wxEXPAND);
			
	// Value is an LSExpressionY
	wxStaticText * lblEXPRESSION_FOR_Y = new wxStaticText(myPanel, wxID_ANY, L"Expression for Y:");
	wrbEXPRESSION_FOR_Y = new wxRadioBox(myPanel, EXPRESSION_FOR_Y_ID, L"MIDI Expression for Y", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ExpressionY), ExpressionY, pMyLinnStrument->GetEXPRESSION_FOR_Y(split), wxRA_SPECIFY_ROWS);
	hBoxY->Add(lblEXPRESSION_FOR_Y, 0, wxEXPAND);
	hBoxY->Add(wrbEXPRESSION_FOR_Y, 0, wxEXPAND);
				
	wxStaticText * lblINITIAL_RELATIVE_VALUE_FOR_Y = new wxStaticText(myPanel, wxID_ANY, L"Initial relative value for Y:");
	wscINITIAL_RELATIVE_VALUE_FOR_Y = new wxSpinCtrl(myPanel, INITIAL_RELATIVE_VALUE_FOR_Y_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetINITIAL_RELATIVE_VALUE_FOR_Y(split), "&Initial relative value for Y-axis");
	hBoxY->Add(lblINITIAL_RELATIVE_VALUE_FOR_Y, 0, wxEXPAND);
	hBoxY->Add(wscINITIAL_RELATIVE_VALUE_FOR_Y, 0, wxEXPAND);
				
				// toggle
		chkSEND_Z = new wxCheckBox(myPanel, SEND_Z_ID, L"&Send Z-axis loudness messages");
		chkSEND_Z->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetSEND_Z(split)));
		hBoxZ->Add(chkSEND_Z, 0, wxEXPAND);
				
		// Values are constrained by MIN_CC and MAX_CC
			// CC 11 is recommended, any CC is possible though
		wxStaticText * lblCC_FOR_Z = new wxStaticText(myPanel, wxID_ANY, L"CC for Z:");
		wscCC_FOR_Z = new wxSpinCtrl(myPanel, CC_FOR_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetCC_FOR_Z(split), "CC for Z");
		hBoxZ->Add(lblCC_FOR_Z, 0, wxEXPAND);
		hBoxZ->Add(wscCC_FOR_Z, 0, wxEXPAND);

		// Values are constrained by MIN_CC and MAX_CC
		wxStaticText * lblMIN_CC_FOR_Z = new wxStaticText(myPanel, wxID_ANY, L"Min. Z value:");
		wscMIN_CC_FOR_Z = new wxSpinCtrl(myPanel, MIN_CC_FOR_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetMIN_CC_FOR_Z(split), "Min. CC value for Z-axis");
		hBoxZ->Add(lblMIN_CC_FOR_Z, 0, wxEXPAND);
		hBoxZ->Add(wscMIN_CC_FOR_Z, 0, wxEXPAND);
		
		wxStaticText * lblMAX_CC_FOR_Z = new wxStaticText(myPanel, wxID_ANY, L"Max. Z value:");
		wscMAX_CC_FOR_Z = new wxSpinCtrl(myPanel, MAX_CC_FOR_Z_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->GetMAX_CC_FOR_Z(split), "Min. CC value for Z-axis");
		hBoxZ->Add(lblMAX_CC_FOR_Z, 0, wxEXPAND);
		hBoxZ->Add(wscMAX_CC_FOR_Z, 0, wxEXPAND);
		
		/*
		chkRELATIVE_Z = new wxCheckBox(myPanel, RELATIVE_Z_ID, L"&Relative &Z");
		chkRELATIVE_Z->SetValue(pMyLinnStrument->GetRELATIVE_Z(split));
		hBoxZ->Add(chkRELATIVE_Z, 0, wxEXPAND);
		*/

		// Value is an LSExpressionZ
		wxStaticText * lblEXPRESSION_FOR_Z = new wxStaticText(myPanel, wxID_ANY, L"Expression for Z:");
		wrbEXPRESSION_FOR_Z = new wxRadioBox(myPanel, EXPRESSION_FOR_Z_ID, L"MIDI Expression for Z", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ExpressionZ), ExpressionZ, pMyLinnStrument->GetEXPRESSION_FOR_Z(split), wxRA_SPECIFY_ROWS);
		hBoxZ->Add(lblEXPRESSION_FOR_Z, 0, wxEXPAND);
		hBoxZ->Add(wrbEXPRESSION_FOR_Z, 0, wxEXPAND);
		
		wxStaticText * lbl14BIT_CC_VALUE_FOR_Z = new wxStaticText(myPanel, wxID_ANY, L"14-bit CC value for Z:");
		wsc14BIT_CC_VALUE_FOR_Z = new wxSpinCtrl(myPanel, CC_VALUE_FOR_Z_14BIT_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_CC, MAX_CC, pMyLinnStrument->Get14BIT_CC_VALUE_FOR_Z(split), "14-&bit CC value for Z");
		hBoxZ->Add(lbl14BIT_CC_VALUE_FOR_Z, 0, wxEXPAND);
		hBoxZ->Add(wsc14BIT_CC_VALUE_FOR_Z, 0, wxEXPAND);

		vBox1->Add(hBoxY, 0, wxEXPAND);
		vBox1->Add(hBoxZ, 0, wxEXPAND);
				myPanel->SetSizerAndFit(vBox1);
			}


// Event handlers

void AxesPage::OnSEND_Y(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEND_Y(LinnStrument::LSToggle( chkSEND_Y->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEND_Y_NRPN, pMyLinnStrument->GetSEND_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEND_Y_NRPN, pMyLinnStrument->GetSEND_Y(m_Split));
	}
		}


void AxesPage::OnMIN_CC_FOR_Y(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIN_CC_FOR_Y(wscMIN_CC_FOR_Y->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MIN_CC_FOR_Y_NRPN, pMyLinnStrument->GetMIN_CC_FOR_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MIN_CC_FOR_Y_NRPN, pMyLinnStrument->GetMIN_CC_FOR_Y(m_Split));
	}
}


void AxesPage::OnMAX_CC_FOR_Y(wxSpinEvent& event)
{
	pMyLinnStrument->SetMAX_CC_FOR_Y(wscMAX_CC_FOR_Y->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MAX_CC_FOR_Y_NRPN, pMyLinnStrument->GetMAX_CC_FOR_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MAX_CC_FOR_Y_NRPN, pMyLinnStrument->GetMAX_CC_FOR_Y(m_Split));
	}
}


void AxesPage::OnCC_FOR_Y(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_Y(wscCC_FOR_Y->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_Y_NRPN, pMyLinnStrument->GetCC_FOR_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_Y_NRPN, pMyLinnStrument->GetCC_FOR_Y(m_Split));
	}
}


void AxesPage::OnRELATIVE_Y(wxCommandEvent& event)
{
	pMyLinnStrument->SetRELATIVE_Y(LinnStrument::LSToggle(chkRELATIVE_Y->GetValue()),  m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_RELATIVE_Y_NRPN, pMyLinnStrument->GetRELATIVE_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_RELATIVE_Y_NRPN, pMyLinnStrument->GetRELATIVE_Y(m_Split));
	}
}


void AxesPage::OnEXPRESSION_FOR_Y(wxCommandEvent& event)
{
	pMyLinnStrument->SetEXPRESSION_FOR_Y(wrbEXPRESSION_FOR_Y->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_EXPRESSION_FOR_Y_NRPN, pMyLinnStrument->GetEXPRESSION_FOR_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_EXPRESSION_FOR_Y_NRPN, pMyLinnStrument->GetEXPRESSION_FOR_Y(m_Split));
	}
}


void AxesPage::OnINITIAL_RELATIVE_VALUE_FOR_Y(wxSpinEvent& event)
{
	pMyLinnStrument->SetINITIAL_RELATIVE_VALUE_FOR_Y(wscINITIAL_RELATIVE_VALUE_FOR_Y->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN, pMyLinnStrument->GetINITIAL_RELATIVE_VALUE_FOR_Y(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN, pMyLinnStrument->GetINITIAL_RELATIVE_VALUE_FOR_Y(m_Split));
	}
}


void AxesPage::OnSEND_Z(wxCommandEvent& event)
{
	pMyLinnStrument->SetSEND_Z(LinnStrument::LSToggle(chkSEND_Z->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_SEND_Z_NRPN, pMyLinnStrument->GetSEND_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_SEND_Z_NRPN, pMyLinnStrument->GetSEND_Z(m_Split));
	}
}


void AxesPage::OnMIN_CC_FOR_Z(wxSpinEvent& event)
{
	pMyLinnStrument->SetMIN_CC_FOR_Z(wscMIN_CC_FOR_Z->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MIN_CC_FOR_Z_NRPN, pMyLinnStrument->GetMIN_CC_FOR_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MIN_CC_FOR_Z_NRPN, pMyLinnStrument->GetMIN_CC_FOR_Z(m_Split));
	}
}


void AxesPage::OnMAX_CC_FOR_Z(wxSpinEvent& event)
{
	pMyLinnStrument->SetMAX_CC_FOR_Y(wscMAX_CC_FOR_Y->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MAX_CC_FOR_Z_NRPN, pMyLinnStrument->GetMAX_CC_FOR_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MAX_CC_FOR_Z_NRPN, pMyLinnStrument->GetMAX_CC_FOR_Z(m_Split));
	}
}


void AxesPage::OnCC_FOR_Z(wxSpinEvent& event)
{
	pMyLinnStrument->SetCC_FOR_Z(wscCC_FOR_Z->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_CC_FOR_Z_NRPN, pMyLinnStrument->GetCC_FOR_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_CC_FOR_Z_NRPN, pMyLinnStrument->GetCC_FOR_Z(m_Split));
	}
}


/*
void AxesPage::OnRELATIVE_Z(wxCommandEvent& event)
{
	pMyLinnStrument->SetRELATIVE_Z(LinnStrument::LSToggle(chkRELATIVE_Z->GetValue()), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_REL, pMyLinnStrument->GetRELATIVE_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_RELATIVE_Z_NRPN, pMyLinnStrument->GetRELATIVE_Z(m_Split));
	}
}
*/


void AxesPage::OnEXPRESSION_FOR_Z(wxCommandEvent& event)
{
	pMyLinnStrument->SetEXPRESSION_FOR_Z(wrbEXPRESSION_FOR_Z->GetSelection(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN, pMyLinnStrument->GetEXPRESSION_FOR_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_MIDI_EXPRESSION_FOR_Z_NRPN, pMyLinnStrument->GetEXPRESSION_FOR_Z(m_Split));
	}
}


void AxesPage::On14BIT_CC_VALUE_FOR_Z(wxSpinEvent& event)
{
	pMyLinnStrument->Set14BIT_CC_VALUE_FOR_Z(wsc14BIT_CC_VALUE_FOR_Z->GetValue(), m_Split);
	if (m_Split == LSSplitType::LEFT)
	{
		pMyLinnStrument->SendNRPN(SPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN, pMyLinnStrument->Get14BIT_CC_VALUE_FOR_Z(m_Split));
	}
	else
	{
		pMyLinnStrument->SendNRPN(SPLIT_RIGHT_14BIT_CC_VALUE_FOR_Z_NRPN, pMyLinnStrument->Get14BIT_CC_VALUE_FOR_Z(m_Split));
	}
}


// Event table
BEGIN_EVENT_TABLE(AxesPage, wxPanel)
EVT_CHECKBOX(SEND_Y_ID, AxesPage::OnSEND_Y)
EVT_CHECKBOX(RELATIVE_Y_ID, AxesPage::OnRELATIVE_Y)
EVT_CHECKBOX(SEND_Z_ID, AxesPage::OnSEND_Z)
// EVT_CHECKBOX(RELATIVE_Z_ID, AxesPage::OnRELATIVE_Z)

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
