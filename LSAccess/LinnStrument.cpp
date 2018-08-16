// LinnStrument.cpp

#include "LinnStrument.h"

LinnStrument::LinnStrument()
{
m_MIDIIn.setCallback(&LSCallback, (void*)this);
	}


void LinnStrument::ProcessMessage(std::vector <unsigned char> myMessage)
{
}


void LSCallback(double deltatime, std::vector< unsigned char > *message, void *pLinnStrument)
{
	LinnStrument * pMyLinnStrument = (LinnStrument*)pLinnStrument;
	pMyLinnStrument->ProcessMessage(*message);
}
