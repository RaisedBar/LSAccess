// LSSwitches.h

#pragma once

// Value is LSSwitchAssignment
const unsigned int SWITCH1_ASSIGN_NRPN = 228;
const unsigned int SWITCH2_ASSIGN_NRPN = 229;
const unsigned int FOOT_LEFT_ASSIGN_NRPN = 230;
const unsigned int FOOT_RIGHT_ASSIGN_NRPN = 231;
// Toggle:
const unsigned int SWITCH1_BOTH_SPLITS_NRPN = 239;
const unsigned int SWITCH2_BOTH_SPLITS_NRPN = 240;
const unsigned int FOOT_LEFT_BOTH_SPLITS_NRPN = 241;
const unsigned int FOOT_RIGHT_BOTH_SPLITS_NRPN = 242;
// Values are constrained by MIN_CC and MAX_CC
const unsigned int CC_FOR_CC65 = 248;  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
// Values are constrained by MIN_CC and MAX_CC
const unsigned int CC_FOR_LEFT_FOOT_CC65 = 255;
const unsigned int CC_FOR_RIGHT_FOOT_CC65 = 256;
const unsigned int CC_FOR_SWITCH1_CC65 = 257;
const unsigned int CC_FOR_SWITCH2_CC65 = 258;
const unsigned int CC_FOR_LEFT_FOOT_SUSTAIN = 259;
const unsigned int CC_FOR_RIGHT_FOOT_SUSTAIN = 260;
const unsigned int CC_FOR_SWITCH1_SUSTAIN = 261;
const unsigned int CC_FOR_SWITCH2_SUSTAIN = 262;


class LSSwitchSettings
{
public:
	LSSwitchSettings()
	{};

	// Value is LSSwitchAssignment
	unsigned int GetSWITCH1_ASSIGN()
	{
		return m_SWITCH1_ASSIGN;
	}

	void SetSWITCH1_ASSIGN(unsigned int nValue)
	{
		m_SWITCH1_ASSIGN = nValue;
	}

	unsigned int GetSWITCH2_ASSIGN()
	{
		return m_SWITCH2_ASSIGN;
	}

	void SetSWITCH2_ASSIGN(unsigned int nValue)
	{
		m_SWITCH2_ASSIGN = nValue;
	}

	unsigned int GetFOOT_LEFT_ASSIGN()
	{
		return m_FOOT_LEFT_ASSIGN;
	}

	void SetFOOT_LEFT_ASSIGN(unsigned int nValue)
	{
		m_FOOT_LEFT_ASSIGN = nValue;
	}

	unsigned int GetFOOT_RIGHT_ASSIGN()
	{
		return m_FOOT_RIGHT_ASSIGN;
	}

	void SetFOOT_RIGHT_ASSIGN(unsigned int nValue)
	{
		m_FOOT_RIGHT_ASSIGN = nValue;
	}

	unsigned int GetSWITCH1_BOTH_SPLITS()
	{
		return m_SWITCH1_BOTH_SPLITS;
	}

	void SetSWITCH1_BOTH_SPLITS(unsigned int nValue)
	{
		m_SWITCH1_BOTH_SPLITS = nValue;
	}
			
	unsigned int GetSWITCH2_BOTH_SPLITS()
		{
			return m_SWITCH2_BOTH_SPLITS;
		}

	void SetSWITCH2_BOTH_SPLITS(unsigned int nValue)
	{
		m_SWITCH2_BOTH_SPLITS = nValue;
	}


	unsigned int GetFOOT_LEFT_BOTH_SPLITS()
	{
		return m_FOOT_LEFT_BOTH_SPLITS;
	}

	void SetFOOT_LEFT_BOTH_SPLITS(unsigned int nValue)
	{
		m_FOOT_LEFT_BOTH_SPLITS = nValue;
	}

	unsigned int GetFOOT_RIGHT_BOTH_SPLITS()
	{
		return m_FOOT_RIGHT_BOTH_SPLITS;
	}

	void SetFOOT_RIGHT_BOTH_SPLITS(unsigned int nValue)
	{
		m_FOOT_RIGHT_BOTH_SPLITS = nValue;
	}

	// Values are constrained by MIN_CC and MAX_CC
	unsigned int GetCC_FOR_LEFT_FOOT_CC65()
	{
		return m_CC_FOR_LEFT_FOOT_CC65;
	}

	void SetCC_FOR_LEFT_FOOT_CC65(unsigned int nValue)
	{
		m_CC_FOR_LEFT_FOOT_CC65 = nValue;
	}

	unsigned int GetCC_FOR_RIGHT_FOOT_CC65()
	{
		return m_CC_FOR_RIGHT_FOOT_CC65;
	}

	void SetCC_FOR_RIGHT_FOOT_CC65(unsigned int nValue)
	{
		m_CC_FOR_RIGHT_FOOT_CC65 = nValue;
	}

	unsigned int GetCC_FOR_SWITCH1_CC65()
	{
		return m_CC_FOR_SWITCH1_CC65;
	}

	void SetCC_FOR_SWITCH1_CC65(unsigned int nValue)
	{
		m_CC_FOR_SWITCH1_CC65 = nValue;
	}

	unsigned int GetCC_FOR_SWITCH2_CC65()
	{
		return m_CC_FOR_SWITCH2_CC65;
	}

	void SetCC_FOR_SWITCH2_CC65(unsigned int nValue)
	{
		m_CC_FOR_SWITCH2_CC65 = nValue;
	}

	unsigned int GetCC_FOR_LEFT_FOOT_SUSTAIN()
	{
		return m_CC_FOR_LEFT_FOOT_SUSTAIN;
	}

	void SetCC_FOR_LEFT_FOOT_SUSTAIN(unsigned int nValue)
	{
		m_CC_FOR_LEFT_FOOT_SUSTAIN = nValue;
	}

	unsigned int GetCC_FOR_RIGHT_FOOT_SUSTAIN()
	{
		return m_CC_FOR_RIGHT_FOOT_SUSTAIN;
	}

	void SetCC_FOR_RIGHT_FOOT_SUSTAIN(unsigned int nValue)
	{
		m_CC_FOR_RIGHT_FOOT_SUSTAIN = nValue;
	}

	unsigned int GetCC_FOR_SWITCH1_SUSTAIN()
	{
		return m_CC_FOR_SWITCH1_SUSTAIN;
	}

	void SetCC_FOR_SWITCH1_SUSTAIN(unsigned int nValue)
	{
		m_CC_FOR_SWITCH1_SUSTAIN = nValue;
	}

	unsigned int GetCC_FOR_SWITCH2_SUSTAIN()
	{
		return m_CC_FOR_SWITCH2_SUSTAIN;
	}

	void SetCC_FOR_SWITCH2_SUSTAIN(unsigned int nValue)
	{
		m_CC_FOR_SWITCH2_SUSTAIN = nValue;
	}


private:
	// Value is LSSwitchAssignment
	unsigned int m_SWITCH1_ASSIGN;
	unsigned int m_SWITCH2_ASSIGN;
	unsigned int m_FOOT_LEFT_ASSIGN;
	unsigned int m_FOOT_RIGHT_ASSIGN;
	// Toggle:
	unsigned int m_SWITCH1_BOTH_SPLITS;
	unsigned int m_SWITCH2_BOTH_SPLITS;
	unsigned int m_FOOT_LEFT_BOTH_SPLITS;
	unsigned int m_FOOT_RIGHT_BOTH_SPLITS;
	// Values are constrained by MIN_CC and MAX_CC
	unsigned int m_CC_FOR_LEFT_FOOT_CC65;
	unsigned int m_CC_FOR_RIGHT_FOOT_CC65;
	unsigned int m_CC_FOR_SWITCH1_CC65;
	unsigned int m_CC_FOR_SWITCH2_CC65;
	unsigned int m_CC_FOR_LEFT_FOOT_SUSTAIN;
	unsigned int m_CC_FOR_RIGHT_FOOT_SUSTAIN;
	unsigned int m_CC_FOR_SWITCH1_SUSTAIN;
	unsigned int m_CC_FOR_SWITCH2_SUSTAIN;
};
