// LSGlobals.h
// LinnStrument global settings

#pragma once

// Toggle:
const unsigned int GLOBAL_SPLIT_ACTIVE_NRPN = 200;
// Value is LSSplitType
const unsigned int GLOBAL_SELECTED_SPLIT_NRPN = 201;
// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
const unsigned int GLOBAL_SPLIT_COLUMN_NRPN = 202;
// Toggles:
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_C_NRPN = 203;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_NRPN = 204;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_D_NRPN = 205;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_NRPN = 206;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_E_NRPN = 207;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_F_NRPN = 208;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_NRPN = 209;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_G_NRPN = 210;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_NRPN = 211;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_A_NRPN = 212;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_NRPN = 213;
const unsigned int GLOBAL_MAIN_NOTE_LIGHT_B_NRPN = 214;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_C_NRPN = 215;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_NRPN = 216;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_D_NRPN = 217;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_NRPN = 218;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_E_NRPN = 219;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_F_NRPN = 220;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_NRPN = 221;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_G_NRPN = 222;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_NRPN = 223;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_A_NRPN = 224;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_NRPN = 225;
const unsigned int GLOBAL_ACCENT_NOTE_LIGHT_B_NRPN = 226;
// Value is LSRowOffsetType
const unsigned int GLOBAL_ROW_OFFSET_NRPN = 227;
// Value is LSVelocityRange
const unsigned int GLOBAL_VELOCITY_SENSITIVITY_NRPN = 232;
// Value is LSPressureRange
const unsigned int GLOBAL_PRESSURE_SENSITIVITY_NRPN = 233;
// Value is LSMIDIDevice
const unsigned int GLOBAL_MIDI_DEVICE_IO_NRPN = 234;
// Value is LSArpDirection
const unsigned int GLOBAL_ARP_DIRECTION_NRPN = 235;
// Value is LSArpTempoNoteType
const unsigned int GLOBAL_ARP_TEMPO_NOTE_VALUE_NRPN = 236;
// Value is LSGlobalArpOctaveExtension
const unsigned int GLOBAL_ARP_OCTAVE_EXTENSION_NRPN = 237;
// Value_NRPN = 1 - 360  (applies when receiving no MIDI clock)
const unsigned int GLOBAL_CLOCK_BPM_NRPN = 238;
// Value is LSPresetNumber
const unsigned int GLOBAL_SETTINGS_PRESET_LOAD_NRPN = 243;
// Toggles:
const unsigned int GLOBAL_PRESSURE_AFTERTOUCH_NRPN = 244;
const unsigned int DEVICE_USER_FIRMWARE_MODE_NRPN = 245;
const unsigned int DEVICE_LEFT_HANDED_NRPN = 246;
// Value is constrained by MIN_LIGHTS_PRESET and MAX_LIGHTS_PRESET 
const unsigned int GLOBAL_ACTIVE_LIGHTS_PRESET_NRPN = 247;
// Values are constrained by MIN_CC and MAX_CC
const unsigned int GLOBAL_MIN_VELOCITY_VALUE_NRPN = 249;
const unsigned int GLOBAL_MAX_VELOCITY_VALUE_NRPN = 250;
const unsigned int GLOBAL_FIXED_VELOCITY_VALUE_NRPN = 251;
// Value range_NRPN =     0 - 512  
const unsigned int DEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN = 252;
// Value is LSCustomRowOffset
const unsigned int GLOBAL_CUSTOM_ROW_OFFSET_NRPN = 253;
// Toggle:
const unsigned int DEVICE_MIDI_THRU_NRPN = 254;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW1_NRPN = 263;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW2_NRPN = 264;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW3_NRPN = 265;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW4_NRPN = 266;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW5_NRPN = 267;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW6_NRPN = 268;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW7_NRPN = 269;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW8_NRPN = 270;

enum class LS_MIDIDevice
{
	MIDI_DIN_JACKS = 0,
	USB = 1
};

const wxString MIDIDeviceConnections[] =
{
	L"DIN jacks",
	L"USB"
};

class LSGlobalSettings
{
public:
	LSGlobalSettings()
	{
		this->InitFromMIDI();
	};

	unsigned int GetLS_MIDIDeviceIndex(LS_MIDIDevice device)
	{
		switch (device)
		{
		case LS_MIDIDevice::MIDI_DIN_JACKS:
		{
			return 0;
			break;
		}
		case LS_MIDIDevice::USB:
		{
			return 1;
			break;
		}

		default:
		{
			return 1;
			break;
		}
		}
	};

	void InitFromMIDI()
	{
	};
	
	unsigned int GetGLOBAL_SPLIT_ACTIVE()
	{
		return m_GLOBAL_SPLIT_ACTIVE;
	}

	void SetGLOBAL_SPLIT_ACTIVE(unsigned int nValue)
	{
		m_GLOBAL_SPLIT_ACTIVE = nValue;
	}

	// Value is LSSplitType
	unsigned int GetGLOBAL_SELECTED_SPLIT()
	{
		return m_GLOBAL_SELECTED_SPLIT;
	}

	void SetGLOBAL_SELECTED_SPLIT(unsigned int nValue)
	{
		m_GLOBAL_SELECTED_SPLIT = nValue;
	}

	unsigned int GetLSPresetNumber()
	{
		return m_LSPresetNumber;
	}
	
	void SetLSPresetNumber(unsigned int nValue)
	{
		m_LSPresetNumber = nValue;
	};

// Values are constrained by MIN_CC and MAX_CC
	unsigned int GetVolume(LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			return m_LEFT_VOLUME;
		}
		else
		{
			return m_RIGHT_VOLUME;
		}
	}

void SetVolume( unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_VOLUME = nValue;
		}
		else
		{
			m_RIGHT_VOLUME = nValue;
		}
	}

	unsigned int GetMIDIProgram( LSSplitType split)
{
	if (split == LSSplitType::LEFT)
	{
		return m_LEFT_PROGRAM;
	}
	else
	{
		return m_RIGHT_PROGRAM;
	}
	}
	
	void SetMIDIProgram(unsigned int nValue, LSSplitType split)
	{
		if (split == LSSplitType::LEFT)
		{
			m_LEFT_PROGRAM = nValue;
		}
		else
		{
			m_RIGHT_PROGRAM = nValue;
		}
	}

	// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
	unsigned int GetGLOBAL_SPLIT_COLUMN()
	{
		return m_GLOBAL_SPLIT_COLUMN;
	}

void SetGLOBAL_SPLIT_COLUMN(unsigned int nValue)
	{
	m_GLOBAL_SPLIT_COLUMN = nValue;
	}

	// Toggles:
	
unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_C()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_C;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_C_SHARP()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_C_SHARP;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_D()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_D;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_D_SHARP()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_D_SHARP;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_E()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_E;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_F()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_F;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_F_SHARP()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_F_SHARP;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_G()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_G;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_G_SHARP()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_G_SHARP;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_A()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_A;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_A_SHARP()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_A_SHARP;
	}

	unsigned int GetGLOBAL_MAIN_NOTE_LIGHT_B()
	{
		return m_GLOBAL_MAIN_NOTE_LIGHT_B;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_C(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_C = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_C_SHARP(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_C_SHARP = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_D(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_D = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_D_SHARP(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_D_SHARP = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_E(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_E = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_F(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_F = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_F_SHARP(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_F_SHARP = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_G(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_G = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_G_SHARP(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_G_SHARP = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_A(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_A = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_A_SHARP(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_A_SHARP = nValue;
	}

	void SetGLOBAL_MAIN_NOTE_LIGHT_B(unsigned int nValue)
	{
		m_GLOBAL_MAIN_NOTE_LIGHT_B = nValue;
	}


	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_C()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_C;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_D()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_D;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_E()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_E;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_F()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_F;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_G()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_G;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_A()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_A;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP;
	}

	unsigned int GetGLOBAL_ACCENT_NOTE_LIGHT_B()
	{
		return m_GLOBAL_ACCENT_NOTE_LIGHT_B;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_C(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_C = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_D(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_D = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_E(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_E = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_F(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_F = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_G(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_G = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_A(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_A = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP = nValue;
	}

	void SetGLOBAL_ACCENT_NOTE_LIGHT_B(unsigned int nValue)
	{
		m_GLOBAL_ACCENT_NOTE_LIGHT_B = nValue;
	}

	// Value is LSRowOffsetType
	unsigned int GetGLOBAL_ROW_OFFSET()
	{
		return m_GLOBAL_ROW_OFFSET;
	}

	void SetGLOBAL_ROW_OFFSET(unsigned int nValue)
	{
		m_GLOBAL_ROW_OFFSET = nValue;
	}

		// Value is LSVelocityRange
	unsigned int GetGLOBAL_VELOCITY_SENSITIVITY()
	{
		return m_GLOBAL_VELOCITY_SENSITIVITY;
	}

	void SetGLOBAL_VELOCITY_SENSITIVITY(unsigned int nValue)
	{
		m_GLOBAL_VELOCITY_SENSITIVITY = nValue;
	}

	// Value is LSPressureRange
	unsigned int GetGLOBAL_PRESSURE_SENSITIVITY()
	{
		return m_GLOBAL_PRESSURE_SENSITIVITY;
	}

	void SetGLOBAL_PRESSURE_SENSITIVITY(unsigned int nValue)
	{
		m_GLOBAL_PRESSURE_SENSITIVITY = nValue;
	}

	// Value is LSMIDIDevice
	unsigned int GetGLOBAL_MIDI_DEVICE_IO()
	{
		return m_GLOBAL_MIDI_DEVICE_IO;
	}

	void SetGLOBAL_MIDI_DEVICE_IO(unsigned int nValue)
	{
		m_GLOBAL_MIDI_DEVICE_IO = nValue;
	}

	// Value is LSArpDirection
	unsigned int GetGLOBAL_ARP_DIRECTION()
	{
		return m_GLOBAL_ARP_DIRECTION;
	}

	void SetGLOBAL_ARP_DIRECTION(unsigned int nValue)
	{
		m_GLOBAL_ARP_DIRECTION = nValue;
	}

	// Value is LSArpTempoNoteType
	unsigned int GetGLOBAL_ARP_TEMPO_NOTE_VALUE()
	{
		return m_GLOBAL_ARP_TEMPO_NOTE_VALUE;
	}

	void SetGLOBAL_ARP_TEMPO_NOTE_VALUE(unsigned int nValue)
	{
		m_GLOBAL_ARP_TEMPO_NOTE_VALUE = nValue;
	}

	// Value is LSGlobalArpOctaveExtension
	unsigned int GetGLOBAL_ARP_OCTAVE_EXTENSION()
	{
		return m_GLOBAL_ARP_OCTAVE_EXTENSION;
	}

	void SetGLOBAL_ARP_OCTAVE_EXTENSION(unsigned int nValue)
	{
		m_GLOBAL_ARP_OCTAVE_EXTENSION = nValue;
	}

	// Value = 1 - 360  (applies when receiving no MIDI clock)
	unsigned int GetGLOBAL_CLOCK_BPM()
	{
		return m_GLOBAL_CLOCK_BPM;
	}

	void SetGLOBAL_CLOCK_BPM(unsigned int nValue)
	{
		m_GLOBAL_CLOCK_BPM = nValue;
	}

	// Value is LSPresetNumber
	unsigned int GetGLOBAL_SETTINGS_PRESET_LOAD()
	{
		return m_GLOBAL_SETTINGS_PRESET_LOAD;
	}

	void SetGLOBAL_SETTINGS_PRESET_LOAD(unsigned int nValue)
	{
		m_GLOBAL_SETTINGS_PRESET_LOAD = nValue;
	}

	// Toggles:
	unsigned int GetGLOBAL_PRESSURE_AFTERTOUCH()
	{
		return m_GLOBAL_PRESSURE_AFTERTOUCH;
	}

	void SetGLOBAL_PRESSURE_AFTERTOUCH(unsigned int nValue)
	{
		m_GLOBAL_PRESSURE_AFTERTOUCH = nValue;
	}

	unsigned int GetDEVICE_USER_FIRMWARE_MODE()
	{
		return m_DEVICE_USER_FIRMWARE_MODE;
	}

	void SetDEVICE_USER_FIRMWARE_MODE(unsigned int nValue)
	{
		m_DEVICE_USER_FIRMWARE_MODE = nValue;
	}

	unsigned int GetDEVICE_LEFT_HANDED()
	{
		return m_DEVICE_LEFT_HANDED;
	}

	void SetDEVICE_LEFT_HANDED(unsigned int nValue)
	{
		m_DEVICE_LEFT_HANDED = nValue;
	}

	// Value is constrained by MIN_LIGHTS_PRESET and MAX_LIGHTS_PRESET 
	unsigned int GetGLOBAL_ACTIVE_LIGHTS_PRESET()
	{
		return m_GLOBAL_ACTIVE_LIGHTS_PRESET;
	}

	void SetGLOBAL_ACTIVE_LIGHTS_PRESET(unsigned int nValue)
	{
		m_GLOBAL_ACTIVE_LIGHTS_PRESET = nValue;
	}

										  // Values are constrained by MIN_CC and MAX_CC
	unsigned int GetGLOBAL_MIN_VELOCITY_VALUE()
	{
		return m_GLOBAL_MIN_VELOCITY_VALUE;
	}

	void SetGLOBAL_MIN_VELOCITY_VALUE(unsigned int nValue)
	{
		m_GLOBAL_MIN_VELOCITY_VALUE = nValue;
	}

	unsigned int GetGLOBAL_MAX_VELOCITY_VALUE()
	{
		return m_GLOBAL_MAX_VELOCITY_VALUE;
	}

	void SetGLOBAL_MAX_VELOCITY_VALUE(unsigned int nValue)
	{
		m_GLOBAL_MAX_VELOCITY_VALUE = nValue;
	}

	unsigned int GetGLOBAL_FIXED_VELOCITY_VALUE()
	{
		return m_GLOBAL_FIXED_VELOCITY_VALUE;
	}

	void SetGLOBAL_FIXED_VELOCITY_VALUE(unsigned int nValue)
	{
		m_GLOBAL_FIXED_VELOCITY_VALUE = nValue;
	}

	// Value range =     0 - 512  
	unsigned int GetDEVICE_MIN_BYTE_INTERVAL_VALUE()
	{
		return m_DEVICE_MIN_BYTE_INTERVAL_VALUE;
	}

	void SetDEVICE_MIN_BYTE_INTERVAL_VALUE(unsigned int nValue)
	{
		m_DEVICE_MIN_BYTE_INTERVAL_VALUE = nValue;
	}

	// Value is LSCustomRowOffset
	unsigned int GetGLOBAL_CUSTOM_ROW_OFFSET()
	{
		return m_GLOBAL_CUSTOM_ROW_OFFSET;
	}

	void SetGLOBAL_CUSTOM_ROW_OFFSET(unsigned int nValue)
	{
		m_GLOBAL_CUSTOM_ROW_OFFSET = nValue;
	}

	// Toggle:
	unsigned int GetDEVICE_MIDI_THRU()
	{
		return m_DEVICE_MIDI_THRU;
	}

	void SetDEVICE_MIDI_THRU(unsigned int nValue)
	{
		m_DEVICE_MIDI_THRU = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW1()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW1;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW1(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW1 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW2()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW2;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW2(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW2 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW3()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW3;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW3(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW3 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW4()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW4;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW4(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW4 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW5()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW5;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW5(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW5 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW6()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW6;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW6(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW6 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW7()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW7;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW7(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW7 = nValue;
	}

	unsigned int GetGLOBAL_GUITAR_NOTE_TUNING_ROW8()
	{
		return m_GLOBAL_GUITAR_NOTE_TUNING_ROW8;
	}

	void SetGLOBAL_GUITAR_NOTE_TUNING_ROW8(unsigned int nValue)
	{
		m_GLOBAL_GUITAR_NOTE_TUNING_ROW8 = nValue;
	}

	void QueryGLOBAL_SPLIT_ACTIVE()
	{

	}

	void QueryGLOBAL_SELECTED_SPLIT()
	{

	}

	void QueryGLOBAL_SPLIT_COLUMN()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_C()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_C_SHARP()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_D()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_D_SHARP()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_E()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_F()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_F_SHARP()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_G()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_G_SHARP()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_A()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_A_SHARP()
	{

	}

	void QueryGLOBAL_MAIN_NOTE_LIGHT_B()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_C()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_C_SHARP()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_D()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_D_SHARP()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_E()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_F()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_F_SHARP()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_G()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_G_SHARP()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_A()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_A_SHARP()
	{

	}

	void QueryGLOBAL_ACCENT_NOTE_LIGHT_B()
	{

	}

	void QueryGLOBAL_ROW_OFFSET()
	{

	}

	void QueryGLOBAL_VELOCITY_SENSITIVITY()
	{

	}

	void QueryGLOBAL_PRESSURE_SENSITIVITY()
	{

	}

	void QueryGLOBAL_MIDI_DEVICE_IO()
	{

	}

	void QueryGLOBAL_ARP_DIRECTION()
	{

	}

	void QueryGLOBAL_ARP_TEMPO_NOTE_VALUE()
	{

	}

	void QueryGLOBAL_ARP_OCTAVE_EXTENSION()
	{

	}

	void QueryGLOBAL_CLOCK_BPM()
	{

	}

	void QueryGLOBAL_SETTINGS_PRESET_LOAD()
	{

	}

	void QueryGLOBAL_PRESSURE_AFTERTOUCH()
	{

	}

	void QueryDEVICE_USER_FIRMWARE_MODE()
	{

	}

	void QueryDEVICE_LEFT_HANDED()
	{

	}

	void QueryGLOBAL_ACTIVE_LIGHTS_PRESET()
	{

	}

	void QueryGLOBAL_MIN_VELOCITY_VALUE()
	{

	}

	void QueryGLOBAL_MAX_VELOCITY_VALUE()
	{

	}

	void QueryGLOBAL_FIXED_VELOCITY_VALUE()
	{

	}

	void QueryDEVICE_MIN_BYTE_INTERVAL_VALUE()
	{

	}

	void QueryGLOBAL_CUSTOQueryROW_OFFSET()
	{

	}

	void QueryDEVICE_MIDI_THRU()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW1()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW2()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW3()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW4()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW5()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW6()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW7()
	{

	}

	void QueryGLOBAL_GUITAR_NOTE_TUNING_ROW8()
	{

	}

	void QueryLSPresetNumber()
	{

	}

	void QueryLEFT_PROGRAM()
	{

	}

	void QueryRIGHT_PROGRAM()
	{

	}

	void QueryLEFT_VOLUME()
	{

	}

	void QueryRIGHT_VOLUME()
	{

	}


private:
				unsigned int m_GLOBAL_SPLIT_ACTIVE;
				// Value is LSSplitType
				unsigned int m_GLOBAL_SELECTED_SPLIT;
				// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
				unsigned int m_GLOBAL_SPLIT_COLUMN;
				// Toggles:
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_C;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_C_SHARP;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_D;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_D_SHARP;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_E;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_F;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_F_SHARP;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_G;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_G_SHARP;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_A;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_A_SHARP;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_B;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_C;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_D;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_E;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_F;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_G;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_A;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_B;
				// Value is LSRowOffsetType
				unsigned int m_GLOBAL_ROW_OFFSET;
				// Value is LSVelocityRange
				unsigned int m_GLOBAL_VELOCITY_SENSITIVITY;
				// Value is LSPressureRange
				unsigned int m_GLOBAL_PRESSURE_SENSITIVITY;
				// Value is LSMIDIDevice
				unsigned int m_GLOBAL_MIDI_DEVICE_IO;
				// Value is LSArpDirection
				unsigned int m_GLOBAL_ARP_DIRECTION;
				// Value is LSArpTempoNoteType
				unsigned int m_GLOBAL_ARP_TEMPO_NOTE_VALUE;
				// Value is LSGlobalArpOctaveExtension
				unsigned int m_GLOBAL_ARP_OCTAVE_EXTENSION;
				// Value = 1 - 360  (applies when receiving no MIDI clock)
				unsigned int m_GLOBAL_CLOCK_BPM;
				// Value is LSPresetNumber
				unsigned int m_GLOBAL_SETTINGS_PRESET_LOAD;
				// Toggles:
				unsigned int m_GLOBAL_PRESSURE_AFTERTOUCH;
				unsigned int m_DEVICE_USER_FIRMWARE_MODE;
				unsigned int m_DEVICE_LEFT_HANDED;
				// Value is constrained by MIN_LIGHTS_PRESET and MAX_LIGHTS_PRESET 
				unsigned int m_GLOBAL_ACTIVE_LIGHTS_PRESET;
													  // Values are constrained by MIN_CC and MAX_CC
				unsigned int m_GLOBAL_MIN_VELOCITY_VALUE;
				unsigned int m_GLOBAL_MAX_VELOCITY_VALUE;
				unsigned int m_GLOBAL_FIXED_VELOCITY_VALUE;
				// Value range =     0 - 512  
				unsigned int m_DEVICE_MIN_BYTE_INTERVAL_VALUE;
				// Value is LSCustomRowOffset
				unsigned int m_GLOBAL_CUSTOM_ROW_OFFSET;
				// Toggle:
				unsigned int m_DEVICE_MIDI_THRU;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW1;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW2;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW3;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW4;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW5;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW6;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW7;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW8;
				unsigned int m_LSPresetNumber;
				unsigned int m_LEFT_PROGRAM, m_RIGHT_PROGRAM;
				unsigned int m_LEFT_VOLUME, m_RIGHT_VOLUME;
				};
