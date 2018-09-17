// GlobalsPowerMIDIPage.cpp

#include "stdafx.h"
#include "GlobalsPowerMIDIPage.h"

GlobalsPowerMIDIPage::GlobalsPowerMIDIPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument(pLinnStrument),
	pMyParent(parent)
{
		wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	// Value is an LS_MIDIDevice
	wxStaticText * lblGLOBAL_MIDI_DEVICE_IO = new wxStaticText(this, wxID_ANY, L"&Connection:");
	wrbGLOBAL_MIDI_DEVICE_IO = new wxRadioBox(this, GLOBAL_MIDI_DEVICE_IO_ID, L"MIDI connection", wxDefaultPosition, wxDefaultSize, WXSIZEOF(MIDIDeviceConnections), MIDIDeviceConnections, pMyLinnStrument->GetGLOBAL_MIDI_DEVICE_IO(), wxRA_SPECIFY_ROWS);
	hBox1->Add(lblGLOBAL_MIDI_DEVICE_IO, 0, wxEXPAND);
	hBox1->Add(wrbGLOBAL_MIDI_DEVICE_IO, 0, wxEXPAND);

		// Toggle:
	chkDEVICE_MIDI_THRU = new wxCheckBox(this, DEVICE_MIDI_THRU_ID, L"MIDI &Thru");
	chkDEVICE_MIDI_THRU->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetDEVICE_MIDI_THRU()));
	hBox1->Add(chkDEVICE_MIDI_THRU, 0, wxEXPAND);

	// Value is constrained by MIN_MIDI_BYTE_DELAY and MAX_MIDI_BYTE_DELAY
	wxStaticText * lblDEVICE_MIN_BYTE_INTERVAL_VALUE = new wxStaticText(this, wxID_ANY, L"&Min. interval between bytes:");
	wscDEVICE_MIN_BYTE_INTERVAL_VALUE = new wxSpinCtrl(this, DEVICE_MIN_BYTE_INTERVAL_VALUE_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_MIDI_BYTE_DELAY, MIN_MIDI_BYTE_DELAY, pMyLinnStrument->GetDEVICE_MIN_BYTE_INTERVAL_VALUE(), "Max. value for Y-axis");
	hBox1->Add(lblDEVICE_MIN_BYTE_INTERVAL_VALUE, 0, wxEXPAND);
	hBox1->Add(wscDEVICE_MIN_BYTE_INTERVAL_VALUE, 0, wxEXPAND);

	// toggle
	chkDEVICE_USER_FIRMWARE_MODE = new wxCheckBox(this, DEVICE_USER_FIRMWARE_MODE_ID, L"User firmware mode");
	chkDEVICE_USER_FIRMWARE_MODE->SetValue(LinnStrument::LSToggle(pMyLinnStrument->GetDEVICE_USER_FIRMWARE_MODE()));
	hBox1->Add(chkDEVICE_USER_FIRMWARE_MODE, 0, wxEXPAND);
			this->SetSizerAndFit(hBox1);
	}


// Event handlers

void GlobalsPowerMIDIPage::OnGLOBAL_MIDI_DEVICE_IO(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_MIDI_DEVICE_IO(wrbGLOBAL_MIDI_DEVICE_IO->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_MIDI_DEVICE_IO_NRPN, pMyLinnStrument->GetGLOBAL_MIDI_DEVICE_IO());
}


void GlobalsPowerMIDIPage::OnDEVICE_MIDI_THRU(wxCommandEvent& event)
{
	pMyLinnStrument->SetDEVICE_MIDI_THRU(LinnStrument::LSToggle(chkDEVICE_MIDI_THRU->GetValue()));
	pMyLinnStrument->SendNRPN(DEVICE_MIDI_THRU_NRPN, pMyLinnStrument->GetDEVICE_MIDI_THRU());
}


void GlobalsPowerMIDIPage::OnDEVICE_USER_FIRMWARE_MODE(wxCommandEvent& event)
{
	pMyLinnStrument->SetDEVICE_USER_FIRMWARE_MODE(LinnStrument::LSToggle(chkDEVICE_USER_FIRMWARE_MODE->GetValue()));
	pMyLinnStrument->SendNRPN(DEVICE_USER_FIRMWARE_MODE_NRPN, pMyLinnStrument->GetDEVICE_USER_FIRMWARE_MODE());
}


void GlobalsPowerMIDIPage::OnDEVICE_MIN_BYTE_INTERVAL_VALUE(wxSpinEvent& event)
{
	pMyLinnStrument->SetDEVICE_MIN_BYTE_INTERVAL_VALUE(wscDEVICE_MIN_BYTE_INTERVAL_VALUE->GetValue());
	pMyLinnStrument->SendNRPN(DEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN, pMyLinnStrument->GetDEVICE_MIN_BYTE_INTERVAL_VALUE());
}


// Event table
BEGIN_EVENT_TABLE(GlobalsPowerMIDIPage, wxPanel)
EVT_CHECKBOX(DEVICE_MIDI_THRU_ID, GlobalsPowerMIDIPage::OnDEVICE_MIDI_THRU)
EVT_CHECKBOX(DEVICE_USER_FIRMWARE_MODE_ID, GlobalsPowerMIDIPage::OnDEVICE_USER_FIRMWARE_MODE)
EVT_SPINCTRL(DEVICE_MIN_BYTE_INTERVAL_VALUE_ID, GlobalsPowerMIDIPage::OnDEVICE_MIN_BYTE_INTERVAL_VALUE)
EVT_RADIOBOX(GLOBAL_MIDI_DEVICE_IO_ID, GlobalsPowerMIDIPage::OnGLOBAL_MIDI_DEVICE_IO)
END_EVENT_TABLE()
