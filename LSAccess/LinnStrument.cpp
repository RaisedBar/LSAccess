// LinnStrument.cpp

#include "LinnStrument.h"



std::string MIDINoteName(unsigned char nNoteNumber)
{
	std::string strNoteName;
	int nOctaveNumber = ((nNoteNumber + 12) / 12) - 1;

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
	default: strNoteName = "";
	}  // end switch
	return strNoteName.append(std::to_string(nOctaveNumber));
}


void SendCC(unsigned char CCNumber, unsigned char CCValue)
{
}


void SendNRPN(RtMidiOut * pMIDIOut, unsigned int nChannel, unsigned int NRPNNumber, unsigned int NRPNValue)
{
	std::vector<unsigned char> myMessage;
		unsigned char myNRPNParameterMSB, myNRPNParameterLSB;
	unsigned char myNRPNValueMSB, myNRPNValueLSB;

	// Calculate the MSB and LSB values here

	myMessage.push_back((unsigned char)nChannel);
	myMessage.push_back(myNRPNParameterMSB);
	myMessage.push_back(myNRPNParameterLSB);
	pMIDIOut->sendMessage(&myMessage);

	myMessage.push_back((unsigned char)nChannel);
	myMessage.push_back(myNRPNValueMSB);
	myMessage.push_back(myNRPNValueLSB);
	pMIDIOut->sendMessage(&myMessage);

	myMessage.push_back((unsigned char)nChannel);
	myMessage.push_back(RESET_NRPN_CC_MSB);
	myMessage.push_back(127);
	pMIDIOut->sendMessage(&myMessage);

	myMessage.push_back((unsigned char)nChannel);
	myMessage.push_back(RESET_NRPN_CC_LSB);
	myMessage.push_back(127);
	pMIDIOut->sendMessage(&myMessage);
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
		m_MIDIOut = new RtMidiOut();
		m_OutputID = GetUSBOutPortID();
		m_InputID = GetUSBInPortID();

		if ((m_OutputID == -1) || (m_InputID == -1))
		{
			// Prompt for appropriate DIN sockets
			MIDIDialog * pMIDIDialog = new MIDIDialog(L"LinnStrument MIDI I/O jacks");
			if (pMIDIDialog->ShowModal() == wxID_OK)
			{
												m_GlobalSettings.SetGLOBAL_MIDI_DEVICE_IO(m_GlobalSettings.GetLS_MIDIDeviceIndex(LS_MIDIDevice::MIDI_DIN_JACKS));
												m_OutputID = pMIDIDialog->GetSelectedOutput();
													m_InputID = pMIDIDialog->GetSelectedInput();

													if ((m_OutputID != -1) && (m_InputID != -1))
													{
														m_MIDIOut->openPort();
														m_MIDIIn->openPort(pMIDIDialog->GetSelectedInput());
														m_MIDIIn->setCallback(&LSCallback, (void*)this);
													}  // if valid port selections
																}   // if dialog OK
			else
			{
				m_InputID = -1;
				m_OutputID = -1;
			}  // dialog cancelled
		}   
		else  // USB connection detected
		{
			m_GlobalSettings.SetGLOBAL_MIDI_DEVICE_IO(m_GlobalSettings.GetLS_MIDIDeviceIndex(LS_MIDIDevice::USB));
			m_MIDIOut->openPort(m_OutputID);
			m_MIDIIn->openPort(m_InputID);
			m_MIDIIn->setCallback(&LSCallback, (void*)this);
		}
	}  // end try
		catch (RtMidiError &error)
	{
		std::string wstrError( error.getMessage());
		m_InputID = -1;
		m_OutputID = -1;
		m_GlobalSettings.SetGLOBAL_MIDI_DEVICE_IO(m_GlobalSettings.GetLS_MIDIDeviceIndex(LS_MIDIDevice::MIDI_DIN_JACKS));
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
	unsigned char nStatus = MIDI().ShortMsgStatus(myMessage);

	switch (nStatus)
	{
	case MIDI_CMD_NOTE_ON:
	{
		if (m_SpeakNotes)
		{
			unsigned char nNoteNumber = MIDI().ShortMsgData1(myMessage);
			std::string strNoteName = MIDINoteName(nNoteNumber);
			// Announce
					}
}
	break;

		case CC_NRPN_PARAM_MSB:
		{
			m_NRPNParameter = MIDI().ShortMsgData2(myMessage) * 127;
		}
		break;

		case CC_NRPN_PARAM_LSB:
		{
			m_NRPNParameter = m_NRPNParameter + MIDI().ShortMsgData2(myMessage);
		}
		break;

		case CC_NRPN_VALUE_MSB:
		{
			m_NRPNValue = MIDI().ShortMsgData2(myMessage) * 127;
		}
		break;

		case CC_NRPN_VALUE_LSB:
		{
			m_NRPNValue = m_NRPNValue + MIDI().ShortMsgData2(myMessage);
		}
		break;

		default:
			{
			}
			break;
		}  // end switch
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


