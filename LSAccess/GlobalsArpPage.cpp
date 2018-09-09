// GlobalsArpPage.cpp

#include "stdafx.h"
#include "GlobalsArpPage.h"

GlobalsArpPage::GlobalsArpPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
	:wxPanel(parent),
	pMyLinnStrument( pLinnStrument),
pMyParent(parent)
{
				wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBox1 = new wxBoxSizer(wxHORIZONTAL);

	// Controls
		// Value is constrained by MIN_TEMPO and MAX_TEMPO
	wscGLOBAL_CLOCK_BPM = new wxSpinCtrl(myPanel, GLOBAL_CLOCK_BPM_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_TEMPO, MAX_TEMPO, pMyLinnStrument->GetGLOBAL_CLOCK_BPM(), L"&Tempo");
	hBox1->Add(wscGLOBAL_CLOCK_BPM, 0, wxEXPAND);
	// Value is an LSArpDirection
	wrbGLOBAL_ARP_DIRECTION = new wxRadioBox(myPanel, GLOBAL_ARP_DIRECTION_ID, L"&Direction", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ArpDirections), ArpDirections, pMyLinnStrument->GetGLOBAL_ARP_DIRECTION(), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbGLOBAL_ARP_DIRECTION, 0, wxEXPAND);
	// Value is an LSArpTempoNoteType
	wrbGLOBAL_ARP_TEMPO_NOTE_VALUE = new wxRadioBox(myPanel, GLOBAL_ARP_TEMPO_NOTE_VALUE_ID, L"&Note value", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ArpTempoNoteTypes), ArpTempoNoteTypes, LinnStrument::LSArpTempoNoteTypeToInt( pMyLinnStrument->GetGLOBAL_ARP_TEMPO_NOTE_VALUE()), wxRA_SPECIFY_ROWS);
	hBox1->Add(wrbGLOBAL_ARP_TEMPO_NOTE_VALUE, 0, wxEXPAND);
	// Value is an LSGlobalArpOctaveExtension
		wrbGLOBAL_ARP_OCTAVE_EXTENSION = new wxRadioBox(myPanel, GLOBAL_ARP_OCTAVE_EXTENSION_ID, L"&Octave extension", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ArpOctaveExtensions), ArpOctaveExtensions, pMyLinnStrument->GetGLOBAL_ARP_OCTAVE_EXTENSION(), wxRA_SPECIFY_ROWS);
		hBox1->Add(wrbGLOBAL_ARP_OCTAVE_EXTENSION, 0, wxEXPAND);

	myPanel->SetSizer(hBox1);
	hBox1->SetSizeHints(this);
	myPanel->Fit();
	hBox1->Fit(myPanel);
}


// Event handlers

void GlobalsArpPage::OnGLOBAL_ARP_DIRECTION(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ARP_DIRECTION(wrbGLOBAL_ARP_DIRECTION->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_ARP_DIRECTION_NRPN, pMyLinnStrument->GetGLOBAL_ARP_DIRECTION());
	}


void GlobalsArpPage::OnGLOBAL_ARP_TEMPO_NOTE_VALUE(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ARP_TEMPO_NOTE_VALUE( LinnStrument::IntToLSArpTempoNoteType(wrbGLOBAL_ARP_TEMPO_NOTE_VALUE->GetSelection()));
	pMyLinnStrument->SendNRPN(GLOBAL_ARP_TEMPO_NOTE_VALUE_NRPN, pMyLinnStrument->GetGLOBAL_ARP_TEMPO_NOTE_VALUE());
}


void GlobalsArpPage::OnGLOBAL_ARP_OCTAVE_EXTENSION(wxCommandEvent& event)
{
	pMyLinnStrument->SetGLOBAL_ARP_OCTAVE_EXTENSION(wrbGLOBAL_ARP_OCTAVE_EXTENSION->GetSelection());
	pMyLinnStrument->SendNRPN(GLOBAL_ARP_OCTAVE_EXTENSION_NRPN, pMyLinnStrument->GetGLOBAL_ARP_OCTAVE_EXTENSION());
}


void GlobalsArpPage::OnGLOBAL_CLOCK_BPM(wxSpinEvent& event)
{
	pMyLinnStrument->SetGLOBAL_CLOCK_BPM(wscGLOBAL_CLOCK_BPM->GetValue());
	pMyLinnStrument->SendNRPN(GLOBAL_CLOCK_BPM_NRPN, pMyLinnStrument->GetGLOBAL_CLOCK_BPM());
}


// Event table
BEGIN_EVENT_TABLE(GlobalsArpPage, wxPanel)
EVT_SPINCTRL(GLOBAL_CLOCK_BPM_ID, GlobalsArpPage::OnGLOBAL_CLOCK_BPM)
EVT_RADIOBOX(GLOBAL_ARP_DIRECTION_ID, GlobalsArpPage::OnGLOBAL_ARP_DIRECTION)
EVT_RADIOBOX(GLOBAL_ARP_TEMPO_NOTE_VALUE_ID, GlobalsArpPage::OnGLOBAL_ARP_TEMPO_NOTE_VALUE)
EVT_RADIOBOX(GLOBAL_ARP_OCTAVE_EXTENSION_ID, GlobalsArpPage::OnGLOBAL_ARP_OCTAVE_EXTENSION)
END_EVENT_TABLE()
