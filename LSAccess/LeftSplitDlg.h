// LeftSplitDlg.h
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net

#pragma once

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "LSPerSplit.h"

class LeftSplitDlg: public wxDialog
{
public:
	LeftSplitDlg( const wxString& title);

private:
	// Event handlers:
	void OnOK( wxCommandEvent& event);
void OnCancel( wxCommandEvent& event);
DECLARE_EVENT_TABLE()

// controls
// Toggles:
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_1_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_2_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_3_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_4_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_5_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_6_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_7_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_8_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_9_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_10_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_11_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_12_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_13_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_14_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_15_NRPN;
wxCheckBox * chkSPLIT_LEFT_CHANNEL_PER_NOTE_16_NRPN;
// Value is a MIDI channel number:
wxComboBox * cboSPLIT_LEFT_MIDI_PER_ROW_LOWEST_CHANNEL_NRPN;
// Value is from LSBendRange
wxComboBox * cboSPLIT_LEFT_BEND_RANGE_NRPN;
// Toggles:
wxCheckBox * chkSPLIT_LEFT_BEND_TOGGLE_NRPN;
wxCheckBox * chkSPLIT_LEFT_BEND_QUANTIZE_TOGGLE_NRPN;
// Value is from LSPitchQuantize
wxRadioButton * rdoSPLIT_LEFT_PITCH_QUANTIZE_NRPN;
// Toggles:
wxCheckBox * chkSPLIT_LEFT_RESET_PITCH_ON_RELEASE_NRPN;
wxCheckBox * chkSPLIT_LEFT_SEND_Y_NRPN;
// Values are constrained by MIN_CC and MAX_CC
// CC 1 or CC 74 are recommended, any CC is possible though
wxComboBox * cboSPLIT_LEFT_CC_FOR_Y_NRPN;
// Toggle:
wxCheckBox * chkSPLIT_LEFT_RELATIVE_Y_NRPN;
wxCheckBox * chkSPLIT_LEFT_RELATIVE_Z_NRPN;
// Value is an LSExpressionZ
wxTextCtrl  * txtSPLIT_LEFT_MIDI_EXPRESSION_FOR_Z_NRPN;
// Values are constrained by MIN_CC and MAX_CC
// CC 11 is recommended, any CC is possible though
wxComboBox * cboSPLIT_LEFT_CC_FOR_Z_NRPN;
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
wxComboBox * cboSPLIT_LEFT_CC_FOR_FADER1_NRPN;
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
// Toggles:
wxCheckBox * chkSPLIT_LEFT_SEQUENCER_TOGGLE_PLAY_NRPN;
wxCheckBox * chkSPLIT_LEFT_SEQUENCER_PREVIOUS_PATTERN_NRPN;
wxCheckBox * chkSPLIT_LEFT_SEQUENCER_NEXT_PATTERN_NRPN;
// Value is an LSPatternNumber
wxRadioButton * rdoSPLIT_LEFT_SEQUENCER_PATTERN_NRPN;
wxCheckBox * chkSPLIT_LEFT_SEQUENCER_TOGGLE_MUTE_NRPN;
};
