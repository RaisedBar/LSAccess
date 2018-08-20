// LSMemory.cpp

#include "LSMemory.h"

LSMemoryLocation::LSMemoryLocation()
{}


LSPerSplitSettings LSMemoryLocation::GetPerSplitSettings()
{
	return m_PerSplitSettings;
}


LSOctaveTransposeSettings LSMemoryLocation::GetOctaveTransposeSettings()
{
	return m_OctaveTransposeSettings;
}


LSGlobalSettings LSMemoryLocation::GetGlobalSettings()
{
	return m_GlobalSettings;

}


