// MIDI.cpp 
// implementation of the MIDI utility class

#include "stdafx.h"
#include "MIDI.h"


MIDI::MIDI()
{}


MIDI::MIDI( std::vector <unsigned char> vMIDIMessage, bool blnSysEx)
:
vMIDIBytes( vMIDIMessage)
{}


MIDI::~MIDI()
{}


// Extracts the last complete message from the internal vector
std::vector <unsigned char> MIDI::LastCompleteMessage()
{
bool blnIsSysEx = false;
std::vector <unsigned char> vLastMessage;

int nSize = vMIDIBytes.size();

	if (nSize > 3)   // Possible SysEx
{
	// Check for end of SysEx 
 int nSysExEnd = -1;

for ( int i = nSize; i >= 0; i--)
{
if (vMIDIBytes[ i] == MIDI_EOX)
{
	nSysExEnd = i;
}
}  // end for
	
if (nSysExEnd >= 0)
	{
		// Yes, the last message was a SysEx, but was it complete?
						int nSysExStart = -1;

		// Search back for the start point of the message
			for (int i = nSysExEnd; i >= 0; i--)
			{
				if (vMIDIBytes[ i] == MIDI_SYSEX)
				{
					nSysExStart = i;
				}
			}  // end for
			
			// If we have both a start and an end position
if ((nSysExStart > -1) && (nSysExEnd > -1))
{
	blnIsSysEx = true;

	for (int i = nSysExStart; i <= nSysExEnd; i++)
	{
		vLastMessage.push_back( vMIDIBytes[ i]);
	}  // end for
}   // end if both positions found
		}   // if EOX found 
}  // if nSize > 3	
		
if (blnIsSysEx == false)
		{
			// Last message is made up of the last 3 bytes - need to do more work to deal with RPN and NRPN, which are not supported here
						int nPosition = vMIDIBytes.size() -3;
						
						int nStatus = vMIDIBytes[ nPosition];
int nCmd = nStatus & MIDI_CODE_MASK;
int nChannel = nStatus & MIDI_CHN_MASK;
int nData1 = vMIDIBytes[ nPosition +1];
int nData2 = vMIDIBytes[ nPosition +2];

// We want to interpret note on/off pairs consistently, so we'll convert note off messages to note on with velocity zero
if (nCmd == MIDI_CMD_NOTE_OFF)
{
nCmd = MIDI_CMD_NOTE_ON;
nStatus = (nCmd << 4) + nChannel;
nData2 = 0;
}

						vLastMessage.push_back( nStatus);
												vLastMessage.push_back( nData1);
						vLastMessage.push_back( nData2);
			}  // if not blnIsSysEx
		
	return vLastMessage;
	}


int MIDI::ShortMsgStatus( std::vector <unsigned char> myMessage)
{
	unsigned int nSize = myMessage.size();
	
	if (nSize != 3)
	{
		return -1;
	}
	else
	{
		return myMessage[ 0];
	}
		}


std::wstring MIDI::StatusCommandString( std::vector <unsigned char> vBuffer)
{
	std::wstring wstrOut;

	switch (vBuffer.at( 0))
	{
	case MIDI_REALTIME:
		{
		wstrOut = wstrRealTime;
		}
		break;

	case MIDI_CHAN_MODE:
		{
wstrOut = wstrChannelMode;
		}
		break;

	case MIDI_POLY_TOUCH:
				{
		wstrOut = wstrPolyAfterTouch;
				}
		break;

	case MIDI_SYSEX:
				{
		wstrOut = wstrSysEx;
				}
		break;

	case MIDI_Q_FRAME:
{
		wstrOut = wstrQFrame;
}
		break;

	case MIDI_SONG_POINTER:
			{
		wstrOut = wstrSongPointer;
}
		break;

	case MIDI_SONG_SELECT:
			{
		wstrOut = wstrSongSelect;
}
		break;

	case MIDI_TUNE_REQ:
			{
		wstrOut = wstrTuneRequest;
}
		break;

/*
case MIDI_TIME_CLOCK:
			{
		wstrOut = wstrTimeClock;
			}
		break;
*/
		/*
case MIDI_START:
			{
		wstrOut = wstrStart;
			}
		break;
*/
case MIDI_CONTINUE:
			{
		wstrOut = wstrContinue;
			}
		break;

case MIDI_STOP:
			{
		wstrOut = wstrContinue;
			}
		break;

case MIDI_ACTIVE_SENSING:
			{
		wstrOut = wstrActiveSensing;
			}
		break;

case MIDI_SYS_RESET:
			{
		wstrOut = wstrSystemReset;
			}
		break;

case MIDI_CMD_NOTE_OFF:
	{
	wstrOut = wstrNoteOff;
	}
	break;

case MIDI_CMD_NOTE_ON:
	{
wstrOut = wstrNoteOnDescription;
	}
	break;

case MIDI_CMD_POLY_AFTER_TOUCH:
	{
wstrOut = wstrPolyAfterTouch;
	}
	break;

case MIDI_CMD_CONTROL_CHANGE:
	{
		wstrOut = wstrCC;
	}
	break;

case MIDI_CMD_PROGRAM_CHANGE:
	{
		wstrOut = wstrProgramChange;
}
	break;

case MIDI_CMD_CHANNEL_PRESSURE:
{
wstrOut = wstrChannelPressure;
}
break;

case MIDI_CMD_PITCH_WHEEL:
	{
		wstrOut = wstrPitchWheel;
	}
	break;

	// RPN and NRPN controller values:
// RPN 98 and 99, 
// NRPN  100 and 101

	default:
		{
wstrOut = wstrUnknownStatus;
		}
	break;
	}  // end switch
	
	return wstrOut;
}


std::wstring MIDI::ControllerString( unsigned char nData1)
{
std::wstring wstrOut;

switch( nData1)
{
case CC_BANK_SELECT_MSB: 
	{
		wstrOut = wstrBankSelectMSB;
	}
	break;

case CC_MOD_WHEEL_MSB: 
	{
		wstrOut = wstrModWheelMSB;
	}
	break;

case CC_BREATH_MSB: 
	{
		wstrOut = wstrBreathMSB;
	}
	break;

case CC_FOOT_MSB: 
	{
		wstrOut = wstrFootCtrlMSB;
	}
	break;

		case CC_PORTAMENTO_TIME_MSB: 
			{
				wstrOut = wstrPortamentoTimeMSB;
			}
			break;

case CC_DATA_ENTRY_MSB: 
	{
		wstrOut = wstrDataEntryMSB;
	}
	break;

case CC_VOLUME_MSB: 
	{
		wstrOut = wstrVolumeMSB;
	}
	break;

case CC_BALANCE_MSB: 
	{
		wstrOut = wstrBalanceMSB;
	}
	break;

case CC_PAN_MSB: 
	{
		wstrOut = wstrPanMSB;
	}
	break;

case CC_EXPRESSION_MSB: 
	{
wstrOut = wstrExpressionMSB;
	}
	break;

case CC_EFFECT_1_MSB: 
	{
		wstrOut = wstrEffect1MSB;
	}
	break;

case CC_EFFECT_2_MSB: 
	{
		wstrOut = wstrEffect2MSB;
	}
	break;

case CC_GP_1_MSB:
	{
		wstrOut = wstrGP1MSB;
	}
	break;

case CC_GP_2_MSB: 
{
		wstrOut = wstrGP2MSB;
	}
	break;

case CC_GP_3_MSB: 
	{
		wstrOut = wstrGP3MSB;
	}
	break;

case CC_GP_4_MSB: 
	{
		wstrOut = wstrGP4MSB;
	}
	break;

case CC_BANK_SELECT_LSB: 
	{
		wstrOut = wstrBankSelectLSB;
	}
	break;

case CC_MOD_WHEEL_LSB: 
	{
		wstrOut = wstrModWheelLSB;
	}
	break;

case CC_BREATH_LSB: 
	{
		wstrOut = wstrBreathLSB;
	}
	break;

case CC_FOOT_LSB:
	{
		wstrOut = wstrFootCtrlLSB;
	}
	break;

case CC_PORTAMENTO_TIME_LSB: 
	{
		wstrOut = wstrPortamentoTimeLSB;
	}
	break;

case CC_DATA_ENTRY_LSB: 
	{
		wstrOut = wstrDataEntryLSB;
	}
	break;

case CC_VOLUME_LSB:
	{
		wstrOut = wstrVolumeLSB;
	}
	break;

case CC_BALANCE_LSB:
	{
		wstrOut = wstrBalanceLSB;
	}
	break;

case CC_PAN_LSB:
	{
		wstrOut = wstrPanLSB;
	}
	break;

case CC_EXPRESSION_LSB:
	{
		wstrOut = wstrExpressionLSB;
	}
	break;

case CC_EFFECT_1_LSB:
	{
		wstrOut = wstrEffect1LSB;
	}
	break;

case CC_EFFECT_2_LSB: 
	{
		wstrOut = wstrEffect2LSB;
	}
	break;

case CC_GP_1_LSB: 
	{
		wstrOut = wstrGP1LSB;
	}
	break;

case CC_GP_2_LSB: 
		{
		wstrOut = wstrGP2LSB;
	}
	break;

	case CC_GP_3_LSB: 
	{
		wstrOut = wstrGP3LSB;
	}
	break;

case CC_GP_4_LSB:
	{
		wstrOut = wstrGP4LSB;
	}
	break;

case CC_SUSTAIN_PEDAL: 
	{
		wstrOut = wstrSustainPedal;
	}
	break;

	case CC_PORTAMENTO_TOGGLE:
	{
		wstrOut = wstrPortamentoToggle;
	}
	break;

case CC_SOSTENUTO_TOGGLE: 
	{
		wstrOut = wstrSostenutoToggle;
	}
	break;

case CC_SOFT_PEDAL_TOGGLE: 
	{
		wstrOut = wstrSoftPedalToggle;
	}
	break;

case CC_LEGATO_FOOT_SWITCH: 
	{
		wstrOut = wstrLegatoFootswitch;
	}
	break;

case CC_HOLD_2: 
	{
		wstrOut = wstrHold2;
	}
	break;

case CC_VARIATION: 
	{
		wstrOut = wstrVariation;
	}
	break;

case CC_TIMBRE: 
	{
		wstrOut = wstrTimbre;
	}
	break;

case CC_RELEASE_TIME: 
	{
		wstrOut = wstrReleaseTime;
	}
	break;

case CC_ATTACK_TIME: 
	{
		wstrOut = wstrAttackTime;
	}
	break;

case CC_BRIGHTNESS: 
	{
		wstrOut = wstrBrightness;
	}
	break;

case DECAY_TIME: 
	{
		wstrOut = wstrDecayTime;
	}
	break;

case CC_VIBRATO_RATE: 
	{
		wstrOut = wstrVibratoRate;
	}
	break;

case CC_VIBRATO_DEPTH:
	{
		wstrOut = wstrVibratoDepth;
	}
	break;

case CC_VIBRATO_DELAY: 
	{
		wstrOut = wstrVibratoDelay;
	}
	break;

case CC_GP_5: 
	{
		wstrOut = wstrGP5;
	}
	break;

case CC_GP_6:
	{
		wstrOut = wstrGP6;
	}
	break;

case CC_GP_7:
	{
		wstrOut = wstrGP7;
	}
	break;

case CC_GP_8:
	{
		wstrOut = wstrGP8;
	}
	break;

case CC_PORTAMENTO_CTRL:
	{
		wstrOut = wstrPortamentoCtrl;
	}
	break;

case CC_FX1_DEPTH: 
	{
		wstrOut = wstrFX1Depth;
	}
	break;

case CC_FX2_DEPTH: 
	{
		wstrOut = wstrFX2Depth;
	}
	break;

case CC_FX3_DEPTH: 
	{
		wstrOut = wstrFX3Depth;
	}
	break;

case CC_FX4_DEPTH: 
	{
		wstrOut = wstrFX4Depth;
	}
	break;

case CC_FX5_DEPTH: 
	{
		wstrOut = wstrFX5Depth;
	}
	break;

case CC_DATA_INCREMENT: 
	{
		wstrOut = wstrDataIncrement;
	}
	break;

case CC_DATA_DECREMENT: 
	{
		wstrOut = wstrDataDecrement;
	}
	break;

case CC_NRPN_PARAM_LSB:
	{
		wstrOut = wstrNRPNLSB;
	}
	break;

case CC_NRPN_PARAM_MSB:
	{
		wstrOut = wstrNRPNMSB;
	}
	break;

case CC_RPN_LSB: 
	{
		wstrOut = wstrRPNLSB;
	}
	break;

case CC_RPN_MSB: 
	{
		wstrOut = wstrRPNMSB;
	}
	break;

case CC_ALL_SOUND_OFF: 
	{
		wstrOut = wstrAllSoundOff;
	}
	break;

case CC_RESET_ALL_CTRL: 
	{
		wstrOut = wstrResetAllCtrl;
	}
	break;

case CC_LOCAL_CONTROL_TOGGLE: 
	{
		wstrOut = wstrLocalCtrlOnOff;
	}
	break;

case CC_ALL_NOTES_OFF: 
	{
		wstrOut = wstrAllNotesOff;
	}
	break;

case CC_OMNI_OFF: 
	{
		wstrOut = wstrOmniOff;
	}
	break;

case CC_OMNI_ON: 
	{
		wstrOut = wstrOmniOn;
	}
	break;

case CC_MONO_ON: 
	{
		wstrOut = wstrMonoOn;
	}
	break;

case CC_POLY_ON: 
	{
		wstrOut = wstrPolyOn;
	}
	break;

default:
{
	wstrOut = wstrUnassignedCC;
	wstrOut.push_back( nData1);
}
break;
}  // end switch

return wstrOut;
}


unsigned char MIDI::ShortMsgStatus( int nCommandNibble, int nChannelNibble)
{
return (nCommandNibble * 16) + nChannelNibble;
}


unsigned char MIDI::ShortMsgChannelNibble( std::vector <unsigned char> myMessage)
{
unsigned char nTemp = ShortMsgStatus( myMessage);

if (nTemp < 0)
{
	return nTemp;
}
else
{
return (nTemp & MIDI_CHN_MASK);
}
}


	unsigned char MIDI::ShortMsgCommandNibble( std::vector <unsigned char> myMessage)
	{
unsigned char nTemp = ShortMsgStatus( myMessage);
		
if (nTemp < 0)
	{
		return nTemp;
}
else
	{
		return (nTemp & MIDI_CODE_MASK) /16;	
}
	}


unsigned char MIDI::ShortMsgData1( std::vector <unsigned char> myMessage)
{
unsigned int nSize = myMessage.size();
	
	if (nSize != 3)
	{
		return -1;
	}
	else
	{
		return myMessage[ 1];
	}
		}


unsigned char MIDI::ShortMsgData2( std::vector <unsigned char> myMessage)
{
unsigned int nSize = myMessage.size();
	
	if (nSize != 3)
	{
		return -1;
	}
	else
	{
		return myMessage[ 2];
	}
		}


std::vector <unsigned char> MIDI::SysExAddressBytes( std::vector <unsigned char> vMessage)
{
std::vector <unsigned char> vResult;
vResult.clear();

if (IsValidSysEx( vMessage) == false)
	{
		return vResult;
}
else
{
		return vMessage;
}
}


std::vector <unsigned char> MIDI::SysExValueBytes( std::vector <unsigned char> vMessage)
{
std::vector <unsigned char> vResult;
vResult.clear();

if (IsValidSysEx( vMessage) == false)
	{
		return vResult;
}
else
{
			unsigned int nFirstAddressByte = 4;
// Increase offset if a 3-byte manufacturer ID is being used
if (SysExManufacturerID( vMessage)[ 0] == 0x00)
{
nFirstAddressByte = nFirstAddressByte + 2;
}
unsigned int nFirstValueByte = nFirstAddressByte + nAddressBytes +1;

for (unsigned int i = 0; i < vMessage.size(); i++)
{
	if (( i >= nFirstValueByte) && (vMessage[ i] != MIDI_EOX))
{
		vResult.push_back( vMessage[ i]);
}
}
return vResult;
}  // end if sysex
}


std::vector <unsigned char> MIDI::SysExManufacturerID( std::vector <unsigned char> vMessage)
{
std::vector <unsigned char> vResult;
vResult.clear();

if (IsValidSysEx( vMessage) == false)
	{
return vResult;
}
else
{
int nIDByte1 = vMessage[ 1]; 
vResult.push_back( nIDByte1);	

if (nIDByte1 == 00)  // Need 2 more bytes
{
vResult.push_back( vMessage[ 2]);
vResult.push_back( vMessage[ 3]);
}

return vResult;
}  // end if sysex
}


bool MIDI::IsValidSysEx( std::vector <unsigned char> vMessage)
	{
/*
int nStart = -1;
	int nEnd = -1;
	
	for (int i = vMessage.size() -1; i >= 0; i--)
	{
if (vMessage[ i] == MIDI_SYSEX)
{
nStart = i;
}

if (vMessage[ i] == MIDI_EOX)
{
nEnd = i;
}
}  // end for
	
	if ((nStart > -1) && (nEnd > -1))
{
return true;
}
else
{
return false;
}
*/
if ((vMessage[ 0] == MIDI_SYSEX)
	&& (vMessage[ (vMessage.size() -1)] == MIDI_EOX))
{
return true;
}
else
{
	return false;
	}
}


bool MIDI::IsValidStatus( std::vector <unsigned char> myMessage)
	{
		return (this->ShortMsgStatus( myMessage) >= 0);
}


bool MIDI::IsValidChannelNumber( std::vector <unsigned char> myMessage)
	{
		int nTemp = this->ShortMsgChannelNibble( myMessage);

		if ((nTemp < 0) || (nTemp > 15))
		{
			return false;
		}
		else
		{
			return true;
		}
}


bool MIDI::IsValidData1Value( std::vector <unsigned char> myMessage)
	{
		int nTemp = this->ShortMsgData1( myMessage);

		if ((nTemp < 0) || (nTemp > 127))
		{
			return false;
		}
		else
		{
			return true;
		}
		}


bool MIDI::IsValidData2Value( std::vector <unsigned char> myMessage)
	{
		int nTemp = this->ShortMsgData2( myMessage);

		if ((nTemp < 0) || (nTemp > 127))
		{
			return false;
		}
		else
		{
			return true;
		}
		}


bool MIDI::IsValidSysExHeader( std::vector <unsigned char> vMyBytes)
	{
if (vMyBytes[ 0] == MIDI_SYSEX)
{
		return true;
}
else
{
return false;
}
}


std::string MIDI::MIDIHash()
	{
std::string strResult;

if (vMIDIBytes.size() == 0)  // the MIDI object was constructed with no data
{
	std::string strEmpty;
	strEmpty.clear();
	return strEmpty;
}

// Does the vector represent a SysEx header?
if (IsValidSysExHeader( vMIDIBytes))
{
strResult = SysExHash( vMIDIBytes);	
}
	else
		{
strResult = ShortMIDIHash( vMIDIBytes);
}  // end if SysEx
	
return strResult;
}


std::string MIDI::SysExHash( std::vector <unsigned char> vBytes)
{
std::string strResult = strSysExHashPrefix;

for (unsigned int i = 0; i < vBytes.size(); i++)
{
// std::string strByte = boost::lexical_cast <std::string> (static_cast<unsigned int> ( vBytes.at( i)));
	std::string strByte = std::to_string(vBytes.at(i));

	strResult.append( strByte);
strResult.append( HASH_DELIMITER);
}

return strResult;
}


std::string MIDI::ShortMIDIHash( std::vector <unsigned char> vBytes)
{
std::string strResult;

if (vBytes.size() == 3)   // Single-message format
{
	int nStatus = vBytes[ 0];
	int nCmd= nStatus & MIDI_CODE_MASK;
	int nChannel = nStatus & MIDI_CHN_MASK;
int nData1 = vBytes[ 1];
int nData2 = vBytes[ 2];

switch (nCmd)
{
	// Messages where both data bytes are used to form an MSB/LSB pair
case MIDI_CMD_PITCH_WHEEL:
// case ID_RPN:
// case ID_NRPN:
{
// std::string strMsg = boost::lexical_cast <std::string> (nCmd);
// 	std::string strChannel =boost::lexical_cast <std::string> (nChannel);
		strResult = strDoubleHashPrefix;
std::string strCmd = std::to_string( nCmd);
			strResult.append( strCmd);
strResult.append(  HASH_DELIMITER);
std::string strChannel = std::to_string( nChannel);
	strResult.append( strChannel);
}
break;

default:
// case		NOTE_ON:
// case NOTE_OFF:
	// case CC:
{
std::string strCmd = std::to_string( nCmd);
std::string strChannel = std::to_string( nChannel);
std::string strData1 = std::to_string( nData1);
	strResult.append( strCmd);
strResult.append( HASH_DELIMITER);
strResult.append( strChannel);
strResult.append( HASH_DELIMITER);
strResult.append( strData1);
}
break;
}  // end switch
}
else   // Message more than 3 bytes long
{
// case ID_NOTE_ON_OFF:
}  // end if message is 3 bytes long
return strResult;
}


std::string MIDI::NibbledShortMIDIHash( std::vector <unsigned char> vBytes, int nNibbles)
{
std::string strResult;
strResult.clear();

/*
if (vBytes.size() != 3)   // Not a short message
{
	return strResult;
}
*/

std::vector <unsigned char> vNibbles;

for (unsigned int i = 0; i < vBytes.size(); i++)
{
	unsigned char nByte = vBytes.at( i);

if (nByte == NIBBLE_RANGE_MARKER)
	{
	vNibbles.push_back( (nByte));
break;
}
	
else if (nByte == NIBBLE_WILD_CARD_MARKER)
	{
	vNibbles.push_back( (nByte));
break;
}
	
else
	{
		int nHighNibble = nByte >> 4;		
int 	nLowNibble = nByte & MIDI_CHN_MASK;	
	
if (nHighNibble == 4)
	{
nLowNibble = nLowNibble + 0;
}

if (vNibbles.size() < (unsigned int) nNibbles)
{
	vNibbles.push_back( (nHighNibble));
	}
	else
	{
		break;
	}

if (vNibbles.size() < (unsigned int) nNibbles)
{
	vNibbles.push_back( nLowNibble);
	}
	else
	{
		break;
	}
}  // end if tests
}  // end for

strResult = strNibbleHashPrefix;

for (unsigned int i = 0; i < vNibbles.size(); i++)
{
std::string strByte = std::to_string( vNibbles.at( i));
		strResult.append( strByte);
strResult.append( HASH_DELIMITER);
}

return strResult;
}


unsigned char MIDI::ShortMsgData1HighNibble( std::vector <unsigned char> myMessage)
{
int nTemp = ShortMsgData1( myMessage);
		
if (nTemp < 0)
	{
		return nTemp;
}
else
	{
		return ( (unsigned char) nTemp & MIDI_CODE_MASK);	
}
}


unsigned char MIDI::ShortMsgData1LowNibble( std::vector <unsigned char> myMessage)
{
int nTemp = ShortMsgData1( myMessage);
		
if (nTemp < 0)
	{
		return nTemp;
}
else
	{
		return (nTemp  & MIDI_CHN_MASK);
}
}


int MIDI::NibbledMessageValue( std::string strHash, std::vector <unsigned char> vBuffer)
{
int nNibbleValue = -1;

if (strHash.empty())
	{
return nNibbleValue;		
}

// Is this a valid nibble-based hash value?
if (strHash.substr( 0, 1).compare( strNibbleHashPrefix) != 0)
{
	return nNibbleValue;		
}

int nEndPos = strHash.find( NIBBLE_WILD_CARD_MARKER);

if (nEndPos < 0)
{
	return nNibbleValue;		
}

// Find the nibble position of the wild card representing the value - each nibble has a trailing full stop
unsigned int nNibbleCount = 0;

for (int i = 0; i < nEndPos; i++)
{
	std::string strTemp = strHash.substr( i, 1);
	
		if (strTemp.compare( ".") == 0)
	{
nNibbleCount++;    // Finished another byte, so increment the position counter
	}
		}  // end for

if (nNibbleCount > 0)
	{
		// Get the corresponding nibble from the vector		
// nNibbleCount = nNibbleCount -1;  
unsigned int nBytePos = nNibbleCount / 2;
		unsigned int nNibblePos = nNibbleCount % 2;
		unsigned int nByteValue = vBuffer.at( nBytePos);

		if (nNibblePos == 0)
		{
					nNibbleValue = (nByteValue & MIDI_CODE_MASK) /16;
}
		else
		{
			nNibbleValue = nByteValue & MIDI_CHN_MASK;
		}
}  // end if nPos > -1

return nNibbleValue;
}


unsigned char MIDI::GetMSB(unsigned int nValue)
{
	return ((unsigned char)nValue & 0xFFFF0000) /128;
}

unsigned char MIDI::GetLSB(unsigned int nValue)
{
	return ((unsigned char)nValue & 0x0000FFFF);
}


std::string MIDI::GetNoteName(unsigned char nNoteNumber)
{
	std::string strNoteName;
	int nOctaveNumber = ((nNoteNumber + 12) / 12) - 1;

	switch (nNoteNumber % 12)
	{
	case 0: 
	{
		strNoteName = "C sharp";
	}
	break;

	case 1: 
	{
		strNoteName = "D";
	}
	break;
	
	case 2: 
	{
	strNoteName = "D sharp"; 
	}
	break;

	case 3: 
	{
		strNoteName = "E";
	}
	break;

	case 4: 
	{
		strNoteName = "F";
	}
	break;

	case 5: 
	{
		strNoteName = "F sharp";
	}
	break;

	case 6: 
	{
		strNoteName = "G";
	}
	break;

	case 7: 
	{
		strNoteName = "G sharp";
	}
	break;

	case 8: 
	{
		strNoteName = "A";
	}
	break;

	case 9: 
	{
		strNoteName = "A sharp";
	}
	break;

	case 10: 
	{
		strNoteName = "B";
	}
	break;

	case 11:
	{
		strNoteName = "C";
	}
	break;

	default:
	{
		strNoteName = "";
	}
	break;
		}  // end switch
	return strNoteName.append(std::to_string(nOctaveNumber));
}


std::wstring MIDI::GetWideNoteName(unsigned char nNoteNumber)
{
	std::wstring wstrNoteName;
	int nOctaveNumber = ((nNoteNumber + 12) / 12) - 1;

	switch (nNoteNumber % 12)
	{
	case 0:
	{
		wstrNoteName = L"C#";
	}
	break;

	case 1:
	{
		wstrNoteName = L"D";
	}
	break;

	case 2:
	{
		wstrNoteName = L"D#";
	}
	break;

	case 3:
	{
		wstrNoteName = L"E";
	}
	break;

	case 4:
	{
		wstrNoteName = L"F";
	}
	break;

	case 5:
	{
		wstrNoteName = L"F#";
	}
	break;

	case 6:
	{
		wstrNoteName = L"G";
	}
	break;

	case 7:
	{
		wstrNoteName = L"G#";
	}
	break;

	case 8:
	{
		wstrNoteName = L"A";
	}
	break;

	case 9:
	{
		wstrNoteName = L"A#";
	}
	break;

	case 10:
	{
		wstrNoteName = L"B";
	}
	break;

	case 11:
	{
		wstrNoteName = L"C";
	}
	break;

	default:
	{
		wstrNoteName = L"";
	}
	break;
	}  // end switch
	return wstrNoteName.append(std::to_wstring(nOctaveNumber));
}


