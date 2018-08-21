// LinnStrument.cpp

#include "LinnStrument.h"

std::string MIDINoteName(unsigned char nNoteNumber)
{
	std::string strNoteName;
	int nOctaveNumber = ((nNoteNumber +12) / 12) -1;
	
	switch (nNoteNumber % 12)
	{
	case 0: strNoteName = "C";
	case 1: strNoteName = "C#";
			case 2: strNoteName = "D";
			case 3: strNoteName = "D#";
			case 4: strNoteName = "E";
			case 5: strNoteName = "F";
			case 6: strNoteName = "F#";
			case 7: strNoteName = "G";
			case 8: strNoteName = "G#";
			case 9: strNoteName = "A";
			case 10: strNoteName = "A#";
	case 11: strNoteName = "B";
	default: strNoteName= "";
	}  // end switch
	   return strNoteName.append(std::to_string(nOctaveNumber));
	}


void SendCC(unsigned char CCNumber, unsigned char CCValue)
{
}


void SendNRPN(unsigned int NRPNNumber, unsigned int NRPNValue)
{
	/*
		NRPN input
		==========

		NRPN messages are a series of MIDI CC messages that allow changing more parameters than are supported by
		the standard MIDI CC message list. LinnStrument always expects an exact series of 6 MIDI CC messages to be
		received for setting one NRPN to a different value. The first two select the NRPN parameter number, the
		next two set the NRPN parameter value(both MSB and LSB are used), and the last two reset the active NRPN
		parameter number. Failure to reset the NRPN parameter number can result in other MIDI input messages to
		behave unpredictably.

		This is an overview of the message chain :

		1011nnnn   01100011 (99)  0vvvvvvv         NRPN parameter number MSB CC
		1011nnnn   01100010 (98)  0vvvvvvv         NRPN parameter number LSB CC
		1011nnnn   00000110 (6)  0vvvvvvv         NRPN parameter value MSB CC
		1011nnnn   00100110 (38)  0vvvvvvv         NRPN parameter value LSB CC
		1011nnnn   01100101 (101)  01111111 (127)   RPN parameter number Reset MSB CC
		1011nnnn   01100100 (100)  01111111 (127)   RPN parameter number Reset LSB CC
		*/
}


void LSCallback(double deltatime, std::vector< unsigned char > *message, void *pLinnStrument)
{
	LinnStrument * pMyLinnStrument = (LinnStrument*)pLinnStrument;
	pMyLinnStrument->ProcessMessage(*message);
}


LinnStrument::LinnStrument()
{
				try
	{
		m_MIDIIn = new RtMidiIn();

		m_InputID = GetUSBInPortID();
		
		if (m_InputID != -1)
		{
				m_MIDIIn->openPort(m_InputID);
			m_MIDIIn->setCallback(&LSCallback, (void*)this);
		}
	}
	catch (RtMidiError &error)
	{
		std::string wstrError( error.getMessage());
		m_InputID = -1;
	}
		
	try
	{
		m_MIDIOut = new RtMidiOut();
		m_OutputID = GetUSBOutPortID();

		if (m_OutputID != -1)
		{
			m_MIDIOut->openPort(m_OutputID);
		}
	}
	catch (RtMidiError &error)
	{
		std::string wstrError(error.getMessage());
		m_OutputID = -1;
	}
}


LinnStrument::~LinnStrument()
{
	try
	{
		if (m_MIDIIn->isPortOpen())
		{
			m_MIDIIn->closePort();
		}

		if (m_MIDIOut->isPortOpen())
		{
			m_MIDIOut->closePort();
		}
	}
		catch (RtMidiError &error)
	{
		std::string wstrError(error.getMessage());
		m_OutputID = -1;
	}
}


int LinnStrument::GetUSBInPortID()
{
	int nID;
	
		for ( nID = 0; nID < (int) m_MIDIIn->getPortCount(); nID++)
	{
			std::string strTemp = m_MIDIIn->getPortName(nID);
			unsigned int nPos = strTemp.find_last_of(" ");
			strTemp = strTemp.substr(0, nPos);

						if (strTemp.compare(LSUSBName) == 0)
		{
			return nID;
		}
	}  // end for
		
	return -1;
}


int LinnStrument::GetUSBOutPortID()
{
	int nID;

	for (nID = 0; nID < (int)m_MIDIOut->getPortCount(); nID++)
	{
		// C++17 - try using string_view instead: better memory management
				std::string strTemp = m_MIDIOut->getPortName(nID);
		unsigned int nPos = strTemp.find_last_of(" ");
		strTemp = strTemp.substr(0, nPos);

		if (strTemp.compare(LSUSBName) == 0)
		{
			return nID;
		}
	}  // end for

	return -1;
}


void LinnStrument::ProcessMessage(std::vector <unsigned char> myMessage)
{
	if (m_SpeakNotes)
	{
		unsigned char nNoteNumber = 0;
		// MessageBox(NULL, (LPCWSTR) MIDINoteName(nNoteNumber).c_str(), (LPCWSTR) "Test", MB_ICONWARNING | MB_OK);
	}
}

bool LinnStrument::GetSpeakNotes()
{
	return m_SpeakNotes;
	}

void LinnStrument::SetSpeakNotes(bool blnSpeakNotes)
{
	m_SpeakNotes = blnSpeakNotes;
}

LSPerSplitSettings LinnStrument::GetPerSplitSettings()
{
	return m_PerSplitSettings;
}


LSOctaveTransposeSettings LinnStrument::GetOctaveTransposeSettings()
{
	return m_OctaveTransposeSettings;
}


LSGlobalSettings LinnStrument::GetGlobalSettings()
{
	return m_GlobalSettings;

}


