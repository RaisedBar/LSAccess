// LSMemory.cpp

#include "LSMemory.h"

LSMemoryLocation::LSMemoryLocation(unsigned int nMemoryNumber)
{
	m_MemoryNumber = nMemoryNumber;
}


unsigned int LSMemoryLocation::GetMemoryNumber()
{
	return m_MemoryNumber;
}

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


