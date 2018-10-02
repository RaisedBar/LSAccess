// GlobalsDialog.h
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

#include "wx/xrc/xmlres.h"

#include "LinnStrument.h"
#include "LSConsts.h"
class GlobalsDialog : public wxDialog
{
public:
	GlobalsDialog(wxWindow* parent, const wxString& title, LinnStrument * pLinnStrument);

private:
	void InitSplitPage();
	void InitNoteLightsPage();
	void InitAccentNoteLightsPage();
	void InitArpPage();
	void InitPowerMIDIPage();
	void InitRowTuningsPage();
	void InitVelocityPressurePage();

	// Event handlers
	DECLARE_EVENT_TABLE()

// Split page
	void OnGLOBAL_SPLIT_ACTIVE(wxCommandEvent& event);
	void OnDEVICE_LEFT_HANDED(wxCommandEvent& event);
	void OnGLOBAL_SPLIT_COLUMN(wxSpinEvent& event);

	// Note lights page
	void OnGLOBAL_MAIN_NOTE_LIGHT_C(wxCommandEvent& event);
	void OnGLOBAL_MAIN_NOTE_LIGHT_C_SHARP(wxCommandEvent& event);
	void OnGLOBAL_MAIN_NOTE_LIGHT_D(wxCommandEvent& event);
	void OnGLOBAL_MAIN_NOTE_LIGHT_D_SHARP(wxCommandEvent& event);
	void OnGLOBAL_MAIN_NOTE_LIGHT_E(wxCommandEvent& event);
	void OnGLOBAL_MAIN_NOTE_LIGHT_F(wxCommandEvent& event);
	void OnGLOBAL_MAIN_NOTE_LIGHT_F_SHARP(wxCommandEvent& event);
	void OnGLOBAL_MAIN_NOTE_LIGHT_G(wxCommandEvent& event);
	void OnGLOBAL_MAIN_NOTE_LIGHT_G_SHARP(wxCommandEvent& event);
	void OnGLOBAL_MAIN_NOTE_LIGHT_A(wxCommandEvent& event);
	void OnGLOBAL_MAIN_NOTE_LIGHT_A_SHARP(wxCommandEvent& event);
	void OnGLOBAL_MAIN_NOTE_LIGHT_B(wxCommandEvent& event);
	void OnGLOBAL_ACTIVE_LIGHTS_PRESET(wxSpinEvent& event);

	// Accent note lights page
void OnGLOBAL_ACCENT_NOTE_LIGHT_C(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_D(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_E(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_F(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_G(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_A(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP(wxCommandEvent& event);
	void OnGLOBAL_ACCENT_NOTE_LIGHT_B(wxCommandEvent& event);

	// Row tunings page
	void OnGLOBAL_ROW_OFFSET(wxCommandEvent& event);
	void OnGLOBAL_CUSTOM_ROW_OFFSET(wxCommandEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW1(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW2(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW3(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW4(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW5(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW6(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW7(wxSpinEvent& event);
	void OnGLOBAL_GUITAR_NOTE_TUNING_ROW8(wxSpinEvent& event);

// Velocity/Pressure page
	void OnGLOBAL_VELOCITY_SENSITIVITY(wxCommandEvent& event);
	void OnGLOBAL_PRESSURE_AFTERTOUCH(wxCommandEvent& event);
	void OnGLOBAL_PRESSURE_SENSITIVITY(wxCommandEvent& event);
	void OnGLOBAL_FIXED_VELOCITY_VALUE(wxSpinEvent& event);
	void OnGLOBAL_MAX_VELOCITY_VALUE(wxSpinEvent& event);
	void OnGLOBAL_MIN_VELOCITY_VALUE(wxSpinEvent& event);

	// Arp page
	void OnGLOBAL_ARP_DIRECTION(wxCommandEvent& event);
	void OnGLOBAL_ARP_TEMPO_NOTE_VALUE(wxCommandEvent& event);
	void OnGLOBAL_ARP_OCTAVE_EXTENSION(wxCommandEvent& event);
	void OnGLOBAL_CLOCK_BPM(wxSpinEvent& event);

	// Power/MIDI page
	void OnGLOBAL_MIDI_DEVICE_IO(wxCommandEvent& event);
	void OnDEVICE_MIDI_THRU(wxCommandEvent& event);
	void OnDEVICE_USER_FIRMWARE_MODE(wxCommandEvent& event);
	void OnDEVICE_MIN_BYTE_INTERVAL_VALUE(wxSpinEvent& event);

	// data
	LinnStrument * pMyLinnStrument;
		};
