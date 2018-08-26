// GlobalsPowerMIDIPage.cpp

#include "GlobalsPowerMIDIPage.h"

GlobalsPowerMIDIPage::GlobalsPowerMIDIPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetGlobalSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	// Value is an LS_MIDIDevice
		wxRadioBox * wrbGLOBAL_MIDI_DEVICE_IO = new wxRadioBox(myPanel, GLOBAL_MIDI_DEVICE_IO_ID, L"MIDI connection", wxDefaultPosition, wxDefaultSize, WXSIZEOF(MIDIDeviceConnections), MIDIDeviceConnections, m_Settings.GetGLOBAL_MIDI_DEVICE_IO(), wxRA_SPECIFY_ROWS);
	// Toggle:
	wxCheckBox * chkDEVICE_MIDI_THRU = new wxCheckBox(myPanel, DEVICE_MIDI_THRU_ID, L"MIDI &Thru");
	// Value is constrained by MIN_MIDI_BYTE_DELAY and MAX_MIDI_BYTE_DELAY
	wxSpinCtrl * wscDEVICE_MIN_BYTE_INTERVAL_VALUE = new wxSpinCtrl(myPanel, DEVICE_MIN_BYTE_INTERVAL_VALUE_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_MIDI_BYTE_DELAY, MIN_MIDI_BYTE_DELAY, m_Settings.GetDEVICE_MIN_BYTE_INTERVAL_VALUE(), "Max. value for Y-axis");
// toggle
	wxCheckBox * chkDEVICE_USER_FIRMWARE_MODE = new wxCheckBox(myPanel, DEVICE_USER_FIRMWARE_MODE_ID, L"User firmware mode");

		myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


