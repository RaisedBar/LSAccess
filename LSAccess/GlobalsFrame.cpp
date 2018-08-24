// GlobalsFrame.cpp
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net


#include "GlobalsFrame.h"


GlobalsFrame::GlobalsFrame(const wxString& title, LinnStrument * pLinnStrument)
	: wxFrame(NULL, wxID_ANY, title),
	pMyLinnStrument(new LinnStrument)
{
	pMyLinnStrument = pLinnStrument;

	wxPanel * pPanel = new wxPanel(this);
	wxBoxSizer * vSizer = new wxBoxSizer(wxVERTICAL);
	
	// controls
	wxCheckBox * chkGLOBAL_SPLIT_ACTIVE_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
	WXSpinCtrl * wscGLOBAL_SPLIT_COLUMN_NRPN = new wxSpinCtrl(myPanel, GLOBAL_SPLIT_COLUMN_NRPN_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_SPLIT_COLUMN, Min_SPLIT_COLUMN, m_Settings.GetMIDI_PER_ROW_LOWEST_CHANNEL(), "Split &column");
	// Toggles:
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_C_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_C_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_D_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_D_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_E_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_F_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_F_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_G_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_G_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_A_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_A_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_MAIN_NOTE_LIGHT_B_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_C_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_D_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_E_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_F_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_G_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_A_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_ACCENT_NOTE_LIGHT_B_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	// Value is LSRowOffsetType
wxRadioBox * wrbGLOBAL_ROW_OFFSET_NRPN;
	// Value is LSSwitchAssignment
wxRadioBox * wrbGLOBAL_SWITCH1_ASSIGN_NRPN;
wxRadioBox * wrbGLOBAL_SWITCH2_ASSIGN_NRPN;
wxRadioBox * wrbGLOBAL_FOOT_LEFT_ASSIGN_NRPN;
wxRadioBox * wrbGLOBAL_FOOT_RIGHT_ASSIGN_NRPN;
	// Value is LSVelocityRange
wxRadioBox * wrbGLOBAL_VELOCITY_SENSITIVITY_NRPN;
	// Value is LSPressureRange
wxRadioBox * wrbGLOBAL_PRESSURE_SENSITIVITY_NRPN;
	// Value is LSMIDIDevice
wxRadioBox * wrbGLOBAL_MIDI_DEVICE_IO_NRPN;
	// Value is LSArpDirection
wxRadioBox * wrbGLOBAL_ARP_DIRECTION_NRPN;
	// Value is LSArpTempoNoteType
wxRadioBox * wrbGLOBAL_ARP_TEMPO_NOTE_VALUE_NRPN;
	// Value is LSGlobalArpOctaveExtension
wxRadioBox * wrbGLOBAL_ARP_OCTAVE_EXTENSION_NRPN;
	// Value = 1 - 360  (applies when receiving no MIDI clock)
wxRadioBox * wrbGLOBAL_CLOCK_BPM_NRPN;
	// Toggle:
	wxCheckBox * chkGLOBAL_SWITCH1_BOTH_SPLITS_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_SWITCH2_BOTH_SPLITS_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_FOOT_LEFT_BOTH_SPLITS_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkGLOBAL_FOOT_RIGHT_BOTH_SPLITS_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	// Value is LSPresetNumber
	wxRadioBox * wrbGLOBAL_SETTINGS_PRESET_LOAD_NRPN;
	// Toggles:
	wxCheckBox * chkGLOBAL_PRESSURE_AFTERTOUCH_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkDEVICE_USER_FIRMWARE_MODE_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	wxCheckBox * chkDEVICE_LEFT_HANDED_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	// Value is constrained by MIN_LIGHTS_PRESET and MAX_LIGHTS_PRESET 
	wxRadioBox * wrbGLOBAL_ACTIVE_LIGHTS_PRESET_NRPN;
	// Values are constrained by MIN_CC and MAX_CC
	WXSpinCtrl * wscGLOABAL_CC_FOR_CC65;  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
										  // Values are constrained by MIN_CC and MAX_CC
	WXSpinCtrl * wscGLOBAL_MIN_VELOCITY_VALUE_NRPN;
	WXSpinCtrl * wscGLOBAL_MAX_VELOCITY_VALUE_NRPN;
	WXSpinCtrl * wscGLOBAL_FIXED_VELOCITY_VALUE_NRPN;
	// Value range =     0 - 512  
	WXSpinCtrl * wscDEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN;
	// Value is LSCustomRowOffset
	wxRadioBox * wrbGLOBAL_CUSTOM_ROW_OFFSET;
	// Toggle:
	wxCheckBox * chkDEVICE_MIDI_THRU_NRPN = new wxCheckBox(myPanel, GLOBAL_SPLIT_ACTIVE_NRPN_ID, L"Split &Active");
	// Values are constrained by MIN_CC and MAX_CC
	WXSpinCtrl * wscGLOBAL_CC_FOR_LEFT_FOOT_CC65;
	WXSpinCtrl * wscGLOBAL_CC_FOR_RIGHT_FOOT_CC65;
	WXSpinCtrl * wscGLOBAL_CC_FOR_SWITCH1_CC65;
	WXSpinCtrl * wscGLOBAL_CC_FOR_SWITCH2_CC65;
	WXSpinCtrl * wscGLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN;
	WXSpinCtrl * wscGLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN;
	WXSpinCtrl * wscGLOBAL_CC_FOR_SWITCH1_SUSTAIN;
	WXSpinCtrl * wscGLOBAL_CC_FOR_SWITCH2_SUSTAIN;
	
	pPanel->SetSizer(vSizer);
	pPanel->Layout();
}
		

BEGIN_EVENT_TABLE(GlobalsFrame, wxFrame)
END_EVENT_TABLE()
