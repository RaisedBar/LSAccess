// GlobalsArpPage.cpp

#include "GlobalsArpPage.h"

GlobalsArpPage::GlobalsArpPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument)
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
		// Value is constrained by MIN_TEMPO and MAX_TEMPO
	wxSpinCtrl * wscGLOBAL_CLOCK_BPM = new wxSpinCtrl(myPanel, GLOBAL_CLOCK_BPM_ID, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS | wxSP_WRAP, MIN_TEMPO, MAX_TEMPO, m_Settings.GetGLOBAL_CLOCK_BPM(), L"&Tempo");
	// Value is an LSArpDirection
	wxRadioBox * wrbGLOBAL_ARP_DIRECTION = new wxRadioBox(myPanel, GLOBAL_ARP_DIRECTION_ID, L"&Direction", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ArpDirections), ArpDirections, m_Settings.GetGLOBAL_ARP_DIRECTION(), wxRA_SPECIFY_ROWS);
	// Value is an LSArpTempoNoteType
	wxRadioBox * wrbGLOBAL_ARP_TEMPO_NOTE_VALUE = new wxRadioBox(myPanel, GLOBAL_ARP_TEMPO_NOTE_VALUE_ID, L"&Note value", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ArpTempoNoteTypes), ArpTempoNoteTypes, m_Settings.GetGLOBAL_ARP_TEMPO_NOTE_VALUE(), wxRA_SPECIFY_ROWS);
	// Value is an LSGlobalArpOctaveExtension
		wxRadioBox * wrbGLOBAL_ARP_OCTAVE_EXTENSION = new wxRadioBox(myPanel, GLOBAL_ARP_OCTAVE_EXTENSION_ID, L"&Octave extension", wxDefaultPosition, wxDefaultSize, WXSIZEOF(ArpOctaveExtensions), ArpOctaveExtensions, m_Settings.GetGLOBAL_ARP_OCTAVE_EXTENSION(), wxRA_SPECIFY_ROWS);

	myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


