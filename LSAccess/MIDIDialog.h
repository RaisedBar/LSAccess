// MIDIDialog.h
// Custom dialog class definition for the selection of MIDI ports
// Author:  T A Burgess
// Raised Bar Ltd.
// http://www.raisedbar.net

// #define _SCL_SECURE_NO_WARNINGS

#ifndef MIDIDIALOG_H
#define MIDIDIALOG_H

#pragma once

#include <wx/msw/winundef.h> 

#include <RtMidi.h>
#include <wx/msw/winundef.h> 

#include <wx/msgdlg.h>
#include <wx/utils.h> 
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/msw/winundef.h> 

enum MIDI_IO
{
	ID_MIDI_IN_LIST_BOX,
	ID_MIDI_OUT_LIST_BOX
};

const int MIDI_DIALOG_HEIGHT = 460;
const int MIDI_DIALOG_WIDTH = 460;


enum VirtualPorts
{
None,
InOnly,
OutOnly,
Both
};


class MIDIDialog: public wxDialog
{
public:
MIDIDialog(const wxString& title);
MIDIDialog(const wxString& title, int nSelectedInput, int nSelectedOutput);
MIDIDialog(const wxString& title, const bool blnVirtualIn, const bool blnVirtualOut);
MIDIDialog(const wxString& title, const bool blnVirtualIn, int nSelectedPort);
~MIDIDialog();

void SetSelectedInput( int nPortNumber);
int GetSelectedInput();
std::string GetSelectedInputName();

void SetSelectedOutput( int nPortNumber);
int GetSelectedOutput();
std::string GetSelectedOutputName();

private:
	void ListMIDIInPorts();
void ListMIDIInPorts( int nDeviceID);
void ListMIDIOutPorts();
void ListMIDIOutPorts( int nDeviceID);

// Event handlers
void OnAddVirtualInput(wxCommandEvent& event);
void OnAddVirtualOutput(wxCommandEvent& event);
void OnOK(wxCommandEvent& event);
    void OnCancel(wxCommandEvent& event);

RtMidiIn * myMIDIIn;
RtMidiOut * myMIDIOut;
// VirtualPorts myVP;
	bool myVirtualIn, myVirtualOut;
	wxListBox * lbxMIDIIn, * lbxMIDIOut;
DECLARE_EVENT_TABLE()
};

#endif       // MIDIDIALOG_H