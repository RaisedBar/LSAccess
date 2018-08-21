// ColorsPage.cpp

#include "ColorsPage.h"

ColorsPage::ColorsPage(wxBookCtrlBase *parent, LinnStrument * pLinnStrument, const LSSplitType split)
	:wxPanel(parent),
	pMyLinnStrument(new LinnStrument),
	pMyParent(new wxBookCtrl())
{
	pMyLinnStrument = pLinnStrument;
	m_Settings = pMyLinnStrument->GetPerSplitSettings();
	pMyParent = parent;
	wxPanel * myPanel = new wxPanel(this, -1);
	wxBoxSizer * hBoxSettings = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	wxString ColorNames[] =
	{
		L"Off",
			L"RED",
	L"YELLOW",
	L"GREEN",
	"CYAN",
	L"BLUE",
	L"MAGENTA",
	L"BLACK",
	L"WHITE",
	L"ORANGE",
	L"LIME",
	L"PINK",
	// Values higher than pink (11) set the color to default
	L"DEFAULT"
	};

	wrbcCOLOR_MAIN = new wxRadioBox(myPanel, Color_MAIN_ID, L"Main color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, 0, wxRA_SPECIFY_ROWS);
	wrbcCOLOR_ACCENT = new wxRadioBox(myPanel, Color_ACCENT_ID, L"Accent color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, 0, wxRA_SPECIFY_ROWS);
	wrbcCOLOR_PLAYED = new wxRadioBox(myPanel, Color_PLAYED_ID, L"Played color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, 0, wxRA_SPECIFY_ROWS);
	wrbc_COLOR_LOWROW = new wxRadioBox(myPanel, Color_LOWROW_ID, L"&Low row color:", wxDefaultPosition, wxDefaultSize, WXSIZEOF( ColorNames), ColorNames, 0, wxRA_SPECIFY_ROWS);
	
		myPanel->SetSizer(hBoxSettings);
	hBoxSettings->SetSizeHints(this);
	myPanel->Fit();
	hBoxSettings->Fit(myPanel);
}


