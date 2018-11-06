// Speech.mm

// Speech implementation for Mac



#include "Speech.h"

#include <AppKit/NSSpeechSynthesizer.h>

#include <foundation/foundation.h>




/* the indirection avoids declaring the variable of type
 NSSpeechSynthesizer* (which is an Obj-C type) in the header */


struct SpeechSynthesizerImpl

{
	
NSSpeechSynthesizer* synth;

};



Speech::Speech()

:
// instantiate the private implementation (PIMPL) object

impl(new SpeechSynthesizerImpl()),

blnMutedSpeech( false)

{
	
// instantiate the wrapped synthesizer
	
impl->synth = [[NSSpeechSynthesizer alloc] init];
	
	
wxstrVoiceName = wstrDefaultVoiceName;
	
fRate = 300.0;
	
fVolume = 0.75;
	

SetVoice ( wxstrVoiceName);

SetRate( fRate);

SetVolume( fVolume);

}




Speech::Speech( const wxString wxstrVoice)
:

// instantiate the private implementation (PIMPL) 
object
impl(new SpeechSynthesizerImpl()),

blnMutedSpeech( false)

{
	
// instantiate the wrapped synthesizer
	
impl->synth = [[NSSpeechSynthesizer alloc] initWithVoice: wxCFStringRef( wxstrVoice).AsNSString()];

}




Speech::~Speech()

{
	
[impl->synth release];
	delete impl;

}




float Speech::GetRate() const

{
	
return [impl->synth rate];

}




void Speech::SetRate( float myRate)

{
	
fRate = myRate;
	
[impl->synth setRate:fRate];

}




float Speech::GetVolume() const

{
	
return [impl->synth volume];

}




void Speech::SetVolume( float myVolume)

{
	
fVolume = myVolume;
	
[impl->synth setVolume:fVolume];

}




unsigned long Speech::GetVoiceCount()

{
	 
NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];

/* 	 NSArray * aVoices = [[NSSpeechSynthesizer alloc] init]; */
	
NSArray * aVoices;
	
aVoices = [NSSpeechSynthesizer availableVoices];
	 
unsigned long nCount = [aVoices count];
	 
[pool release];
	
return nCount;

}




wxString Speech::GetVoice( unsigned int nVoiceIndex)

{
	
wxString wxstrVoice;
	 
NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
	
//  NSArray *aVoices = [[NSSpeechSynthesizer alloc] init];
	
NSArray *aVoices;
	 aVoices = [NSSpeechSynthesizer availableVoices];

	
NSString * nsstrVoice = [aVoices objectAtIndex:nVoiceIndex];
	
// long nVoiceNumber =[aVoices
	
	 
wxstrVoice =  wxCFStringRef::AsString( nsstrVoice);
	 
wxstrVoiceName = wxstrVoice;
	 
[pool release];
	 
return wxstrVoice;
	 
}
	 
	 
	 

wxString Speech::GetVoice() const
	 
{
	 
// return wxCFStringRef( [impl->synth voice]).AsString();
	 
return wxstrVoiceName;
	 
}
	 

	 

void Speech::SetVoice( wxString wxstrVoice)
	 
{
	 
wxstrVoiceName = wxstrVoice;
	 
[impl->synth setVoice:wxCFStringRef( wxstrVoice).AsNSString()];
	 
}
	 
	 
	 

bool Speech::LoadSpeechParameters()
	 
{
	 
bool blnResult = false;
	 
SpeechParameters myParameters;
	 
path myPath( SpeechPath());
		 
		 
try
		 
{
			 
if (! exists( myPath))    // does the path actually exist?
			 
{
				 
return blnResult;
			 
}  
// if exists

			 
if (! is_directory( myPath))      
// myPath must be a directory
			 
{
				 
return blnResult;
			 
}  // if directory
		 
}  // end try
		 
catch (const filesystem_error &error)
		 
{
			 
wxMessageBox( error.what(), wstrErrorTitle, wxOK | wxICON_ERROR);
			 
return blnResult;
		 
}

		 

// Directory exists so process the desired file
		 
myPath /= wstrSpeechConfigFileName;

		 
try
	 
{
	 
myParameters = LoadData <SpeechParameters> (myPath, false);
		 
blnResult = true;
	 
}
	 
catch( ...)
	 
{
	 
return blnResult;
	 
}
	 
	 

if (blnResult)
	 
{
	 
SetVoice( myParameters.GetVoice());
	 
SetRate( myParameters.GetRate());
	 
SetVolume( myParameters.GetVolume());
	 
}
	 
	
return blnResult;

}




bool Speech::SaveSpeechParameters()

{
	
bool blnResult = false;
	 
SpeechParameters myParameters;
	
path myPath( SpeechPath());
	
	

try
	
{
		
if (! exists( myPath))    // does the path actually exist?
		
{
			
return blnResult;
		
}  // if exists
		
		
if (! is_directory( myPath))      // myPath must be a directory
		
{
			
return blnResult;
		
}  // if directory
	
}  // end try
	
catch (const filesystem_error &error)
	
{
		wxMessageBox( error.what(), wstrErrorTitle, wxOK | wxICON_ERROR);
		
return blnResult;
	
}
	
	
// Directory exists so process the desired file
	
myPath /= wstrSpeechConfigFileName;
	
	 
myParameters.SetVoice( wxstrVoiceName.ToStdWstring());
	 
myParameters.SetRate( fRate);
	 
myParameters.SetVolume( fVolume);
	 
	 
try
	 
{
	 SaveData <SpeechParameters> ( myParameters, myPath, false);
		 
blnResult = true;
		 
return blnResult;
	 
}
	 
catch( ...)
	 
{
		 
return blnResult;	 
}

}




bool Speech::IsMuted()
	 
{
	 
return blnMutedSpeech;
}
	 
	 
	 

void Speech::Mute( bool blnMute)
	 
{
	 
blnMutedSpeech = blnMute;
	 
}
	 
	 


HRESULT Speech::Speak( wstring wstrText)

{
 
if (IsMuted())
	
{
 		
return S_OK;
	
}
	
else
	
{
		
[impl->synth startSpeakingString: wxCFStringRef( wstrText).AsNSString()];
	
}
	
return S_OK;

}



HRESULT Speech::Speak( std::wstring wstrText, bool blnSilence)

{
	
if (IsMuted())
	
{
		
return S_OK;
	
}
	
else
	
{
		
if (blnSilence)
		
{
 			
[impl->synth stopSpeaking];
		
}
		
		
[impl->synth startSpeakingString: wxCFStringRef( wstrText).AsNSString()];
	
}
	
return S_OK;

}



HRESULT Speech::Silence()

{
	
if (IsMuted())
	
{
		
return S_OK;
	
}
	
	
[impl->synth stopSpeaking];
	
return S_OK;

}




