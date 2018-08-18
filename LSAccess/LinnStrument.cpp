// LinnStrument.cpp

#include "LinnStrument.h"
#include <wx/msgdlg.h>

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
	unsigned int nTest = m_MIDIIn->getPortCount();
		wxMessageBox( wxString::Format( "%d", nTest), L"Test");

		for ( nID = 0; nID < (int) m_MIDIIn->getPortCount(); nID++)
	{
		wxMessageBox(m_MIDIIn->getPortName(nID), L"Test");
			   					if (m_MIDIIn->getPortName(nID).compare(LSUSBName) == 0)
		{
			return nID;
		}
	}  // end for
		
	return -1;
}


int LinnStrument::GetUSBOutPortID()
{
	int nID = -1;

	return nID;
	}


void LinnStrument::ProcessMessage(std::vector <unsigned char> myMessage)
{
}


void LinnStrument::SendCC(unsigned char CCNumber, unsigned char CCValue)
{
}


void LinnStrument::SendNRPN(unsigned int NRPNNumber, unsigned int NRPNValue)
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
