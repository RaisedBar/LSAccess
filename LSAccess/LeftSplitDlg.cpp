// LeftSplitDlg.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "LeftSplitDlg.h"


LeftSplitDlg::LeftSplitDlg( const wxString& title)
       : wxDialog(NULL, -1, title, wxDefaultPosition, wxSize(250, 230))
	   {  
		wxPanel * myPanel = new wxPanel(this, -1);
		wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

		// Controls
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN, L"Channel per note &1");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN, L"Channel per note &2");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN, L"Channel per note &3");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN, L"Channel per note &4");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN, L"Channel per note &5");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN, L"Channel per note &6");;
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN, L"Channel per note &7");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN, L"Channel per note &8");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN, L"Channel per note &9");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN, L"Channel per note 10");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN, L"Channel per note &11");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN, L"Channel per note &12");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN, L"Channel per note 13");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN, L"Channel per note 14");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN, L"Channel per note 15");
		chkSPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN, L"Channel per note 16");
		// Value is a MIDI channel number:
		cboSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN = new wxComboBox(myPanel, SPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN, L"MIDI per row lowest channel");
		// Value is from LSBendRange
		wxStaticText * lblSPLIT_LEFT_BEND_RANGE_NRPN = new wxStaticText(myPanel, wxID_ANY, L"&Bend Range:");
					cboSPLIT_LEFT_BEND_RANGE_NRPN = new wxComboBox(myPanel, SPLIT_LEFT_BEND_RANGE_NRPN, L"MIDI per row lowest channel");
					chkSPLIT_LEFT_BEND_TOGGLE_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_BEND_TOGGLE_NRPN, L"Enable &pitch bend");
					chkSPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN, L"&Quantize pitch bend");
		// Value is from LSPitchQuantize
					rdoSPLIT_LEFT_PITCH_QUANTIZE_NRPN = new wxRadioButton(myPanel, SPLIT_LEFT_PITCH_QUANTIZE_NRPN, L"&Quantize pitch bend type");
		// Toggles:
		chkSPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN, L"&&Reset pitch on release");
		chkSPLIT_LEFT_SEND_Y_NRPN = new wxCheckBox(myPanel, SPLIT_LEFT_SEND_Y_NRPN, L"Send &Y");
		// Values are constrained by MIN_CC and MAX_CC
		// CC 1 or CC 74 are recommended, any CC is possible though
		cboSPLIT_LEFT_CC_FOR_Y_NRPN = new wxComboBox(myPanel, SPLIT_LEFT_CC_FOR_Y_NRPN, L"CC for &Y");
		// Toggle:
		wxCheckBox * chkSPLIT_LEFT_RELATIVE_Y_NRPN;
		wxCheckBox * chkSPLIT_LEFT_RELATIVE_Z_NRPN;
		// Value is an LSExpressionZ
		wxTextCtrl  * txtSPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN;
		// Values are constrained by MIN_CC and MAX_CC
		// CC 11 is recommended, any CC is possible though
		cboSPLIT_LEFT_CC_FOR_Z_NRPN = new wxComboBox(myPanel, SPLIT_LEFT_CC_FOR_Z_NRPN, L"CC for &Z");
		// Values are defined in LSColor
		wxRadioButton * rdoSPLIT_LEFT_COLOR_MAIN_NRPN;
		wxRadioButton * rdoSPLIT_LEFT_COLOR_ACCENT_NRPN;
		wxRadioButton * rdoSPLIT_LEFT_COLOR_PLAYED_NRPN;
		wxRadioButton * rdoSPLIT_LEFT_COLOR_LOWROW_NRPN;
		// Value is an LSLowRowMode
		wxRadioButton * rdoSPLIT_LEFT_LOWROW_MODE_NRPN;
		// Value is an LSSpecial:
		wxTextCtrl  * txtSPLIT_LEFT_SPECIAL_NRPN;
		// Value is an LSOctave
		wxRadioButton * rdoSPLIT_LEFT_OCTAVE_NRPN;
		// Values are from LSPitch
		wxRadioButton * rdoSPLIT_LEFT_PITCH_TRANSPOSE_NRPN;
		wxRadioButton * rdoSPLIT_LEFT_TRANSPOSE_LIGHTS_NRPN;
		// Value is an LSExpressionY
		wxTextCtrl  * txtSPLIT_LEFT_EXPRESSION_FOR_Y_NRPN;
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		cboSPLIT_LEFT_CC_FOR_FADER1_NRPN;
		wxComboBox * cboSPLIT_LEFT_CC_FOR_FADER2_NRPN;
		wxComboBox * cboSPLIT_LEFT_CC_FOR_FADER3_NRPN;
		wxComboBox * cboSPLIT_LEFT_CC_FOR_FADER4_NRPN;
		wxComboBox * cboSPLIT_LEFT_CC_FOR_FADER5_NRPN;
		wxComboBox * cboSPLIT_LEFT_CC_FOR_FADER6_NRPN;
		wxComboBox * cboSPLIT_LEFT_CC_FOR_FADER7_NRPN;
		wxComboBox * cboSPLIT_LEFT_CC_FOR_FADER8_NRPN;
		// Value is an LSLowRowBehaviour
		wxRadioButton * rdoSPLIT_LEFT_LOWROW_X_BEHAVIOUR_NRPN;
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		wxComboBox * cboSPLIT_LEFT_CC_FOR_LOWROW_NRPN;
		// Value is an LSLowRowBehaviour
		wxRadioButton * rdiSPLIT_LEFT_LOWROW_XYZ_BEHAVIOUR_NRPN;
		// Value is constrained by MIN_FADER_CC and MAX_FADER_CC
		wxComboBox * cboSPLIT_LEFT_CC_FOR_LOWROW_XYZ_NRPN;
		wxComboBox * cboSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Y_NRPN;
		wxComboBox * cboSPLIT_LEFT_CC_FOR_LOWROW_XYZ_Z_NRPN;
		// Values are constrained by MIN_CC and MAX_CC
		wxComboBox * cboSPLIT_LEFT_MIN_CC_FOR_Y_NRPN;
		wxComboBox * cboSPLIT_LEFT_MAX_CC_FOR_Y_NRPN;
		wxComboBox * cboSPLIT_LEFT_MIN_CC_FOR_Z_NRPN;
		wxComboBox * cboSPLIT_LEFT_MAX_CC_FOR_Z_NRPN;
		wxComboBox * cboSPLIT_LEFT_14BIT_CC_VALUE_FOR_Z_NRPN;
		wxComboBox * cboSPLIT_LEFT_INITIAL_RELATIVE_VALUE_FOR_Y_NRPN;
		// Value is an LSChannelOrder
		wxRadioButton * rdoSPLIT_LEFT_CHANNEL_PER_ROW_ORDER;
		// Value is an LSAnimation
		wxRadioButton * txtSPLIT_LEFT_TOUCH_ANIMATION;
				// Toggle:
		wxCheckBox * chkSPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN;
		wxCheckBox * chkSPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN;
		wxCheckBox * chkSPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN;
		// Value is an LSPatternNumber
		wxRadioButton * rdoSPLIT_LEFT_SEQUENCER_PATTERN_NRPN;
		wxCheckBox * chkSPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN;
		
		// Dialog buttons
wxBoxSizer * hBoxButtons= new wxBoxSizer( wxHORIZONTAL);
wxButton * OKButton = new wxButton(myPanel, wxID_OK, L"&OK", wxDefaultPosition, wxSize( wxDefaultSize));
wxButton * CancelButton = new wxButton(myPanel, wxID_CANCEL, L"&Cancel", wxDefaultPosition, wxSize( wxDefaultSize));
OKButton->SetDefault(); 
hBoxButtons->Add( OKButton, 0, wxEXPAND);
hBoxButtons->Add( CancelButton, 0, wxEXPAND);

wxBoxSizer * vBox1 = new wxBoxSizer( wxVERTICAL);
vBox1->Add( hBoxSettings);
vBox1->Add( hBoxButtons);	

myPanel->SetSizer( vBox1);
vBox1->SetSizeHints( this );
myPanel->Fit();
vBox1->Fit( myPanel);
Centre();
this->Maximize();
}


// Event handlers:

void LeftSplitDlg::OnOK( wxCommandEvent& event)
		{
	EndModal( wxID_OK);
		}

		
		void LeftSplitDlg::OnCancel( wxCommandEvent& event)
		{
		EndModal( wxID_CANCEL);
		}

		
		// We need to implement an event table in which the events received by a wxNewSurfaceDialog are routed to their respective handler functions 

	BEGIN_EVENT_TABLE(LeftSplitDlg, wxDialog)
		EVT_BUTTON( wxID_OK, LeftSplitDlg::OnOK)
	    EVT_BUTTON( wxID_CANCEL, LeftSplitDlg::OnCancel)
END_EVENT_TABLE()
