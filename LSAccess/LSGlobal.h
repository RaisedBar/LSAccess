// LSGlobal.h
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
// Value is LSSwitchAssignment
const unsigned int GLOBAL_SWITCH1_ASSIGN_NRPN = 228;
const unsigned int GLOBAL_SWITCH2_ASSIGN_NRPN = 229;
const unsigned int GLOBAL_FOOT_LEFT_ASSIGN_NRPN = 230;
const unsigned int GLOBAL_FOOT_RIGHT_ASSIGN_NRPN = 231;
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
// Value = 1 - 360  (applies when receiving no MIDI clock)
const unsigned int GLOBAL_CLOCK_BPM_NRPN = 238;
// Toggle:
const unsigned int GLOBAL_SWITCH1_BOTH_SPLITS_NRPN = 239;
const unsigned int GLOBAL_SWITCH2_BOTH_SPLITS_NRPN = 240;
const unsigned int GLOBAL_FOOT_LEFT_BOTH_SPLITS_NRPN = 241;
const unsigned int GLOBAL_FOOT_RIGHT_BOTH_SPLITS_NRPN = 242;
// Value is LSPresetNumber
const unsigned int GLOBAL_SETTINGS_PRESET_LOAD_NRPN = 243;
// Toggles:
const unsigned int GLOBAL_PRESSURE_AFTERTOUCH_NRPN = 244;
const unsigned int DEVICE_USER_FIRMWARE_MODE_NRPN = 245;
const unsigned int DEVICE_LEFT_HANDED_NRPN = 246;
// Value is constrained by MIN_LIGHTS_PRESET and MAX_LIGHTS_PRESET 
const unsigned int GLOBAL_ACTIVE_LIGHTS_PRESET_NRPN = 247;
// Values are constrained by MIN_CC and MAX_CC
const unsigned int GLOABAL_CC_FOR_CC65 = 248;  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
									  // Values are constrained by MIN_CC and MAX_CC
const unsigned int GLOBAL_MIN_VELOCITY_VALUE_NRPN = 249;
const unsigned int GLOBAL_MAX_VELOCITY_VALUE_NRPN = 250;
const unsigned int GLOBAL_FIXED_VELOCITY_VALUE_NRPN = 251;
// Value range =     0 - 512  
const unsigned int DEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN = 252;
// Value is LSCustomRowOffset
const unsigned int GLOBAL_CUSTOM_ROW_OFFSET = 253;
// Toggle:
const unsigned int DEVICE_MIDI_THRU_NRPN = 254;
// Values are constrained by MIN_CC and MAX_CC
const unsigned int GLOBAL_CC_FOR_LEFT_FOOT_CC65 = 255;
const unsigned int GLOBAL_CC_FOR_RIGHT_FOOT_CC65 = 256;
const unsigned int GLOBAL_CC_FOR_SWITCH1_CC65 = 257;
const unsigned int GLOBAL_CC_FOR_SWITCH2_CC65 = 258;
const unsigned int GLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN = 259;
const unsigned int GLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN = 260;
const unsigned int GLOBAL_CC_FOR_SWITCH1_SUSTAIN = 261;
const unsigned int GLOBAL_CC_FOR_SWITCH2_SUSTAIN = 262;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW1 = 263;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW2 = 264;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW3 = 265;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW4 = 266;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW5 = 267;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW6 = 268;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW7 = 269;
const unsigned int GLOBAL_GUITAR_NOTE_TUNING_ROW8 = 270;

class LSGlobalSettings
{
public:
	LSGlobalSettings();

			private:
				unsigned int m_GLOBAL_SPLIT_ACTIVE_NRPN;
				// Value is LSSplitType
				unsigned int m_GLOBAL_SELECTED_SPLIT_NRPN;
				// Value is constrained by MIN_SPLIT_COLUMN and MAX_SPLIT_COLUMN  
				unsigned int m_GLOBAL_SPLIT_COLUMN_NRPN;
				// Toggles:
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_C_NRPN;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_C_SHARP_NRPN;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_D_NRPN;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_D_SHARP_NRPN;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_E_NRPN;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_F_NRPN;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_F_SHARP_NRPN;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_G_NRPN;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_G_SHARP_NRPN;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_A_NRPN;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_A_SHARP_NRPN;
				unsigned int m_GLOBAL_MAIN_NOTE_LIGHT_B_NRPN;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_C_NRPN;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_C_SHARP_NRPN;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_D_NRPN;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_D_SHARP_NRPN;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_E_NRPN;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_F_NRPN;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_F_SHARP_NRPN;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_G_NRPN;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_G_SHARP_NRPN;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_A_NRPN;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_A_SHARP_NRPN;
				unsigned int m_GLOBAL_ACCENT_NOTE_LIGHT_B_NRPN;
				// Value is LSRowOffsetType
				unsigned int m_GLOBAL_ROW_OFFSET_NRPN;
				// Value is LSSwitchAssignment
				unsigned int m_GLOBAL_SWITCH1_ASSIGN_NRPN;
				unsigned int m_GLOBAL_SWITCH2_ASSIGN_NRPN;
				unsigned int m_GLOBAL_FOOT_LEFT_ASSIGN_NRPN;
				unsigned int m_GLOBAL_FOOT_RIGHT_ASSIGN_NRPN;
				// Value is LSVelocityRange
				unsigned int m_GLOBAL_VELOCITY_SENSITIVITY_NRPN;
				// Value is LSPressureRange
				unsigned int m_GLOBAL_PRESSURE_SENSITIVITY_NRPN;
				// Value is LSMIDIDevice
				unsigned int m_GLOBAL_MIDI_DEVICE_IO_NRPN;
				// Value is LSArpDirection
				unsigned int m_GLOBAL_ARP_DIRECTION_NRPN;
				// Value is LSArpTempoNoteType
				unsigned int m_GLOBAL_ARP_TEMPO_NOTE_VALUE_NRPN;
				// Value is LSGlobalArpOctaveExtension
				unsigned int m_GLOBAL_ARP_OCTAVE_EXTENSION_NRPN;
				// Value = 1 - 360  (applies when receiving no MIDI clock)
				unsigned int m_GLOBAL_CLOCK_BPM_NRPN;
				// Toggle:
				unsigned int m_GLOBAL_SWITCH1_BOTH_SPLITS_NRPN;
				unsigned int m_GLOBAL_SWITCH2_BOTH_SPLITS_NRPN;
				unsigned int m_GLOBAL_FOOT_LEFT_BOTH_SPLITS_NRPN;
				unsigned int m_GLOBAL_FOOT_RIGHT_BOTH_SPLITS_NRPN;
				// Value is LSPresetNumber
				unsigned int m_GLOBAL_SETTINGS_PRESET_LOAD_NRPN;
				// Toggles:
				unsigned int m_GLOBAL_PRESSURE_AFTERTOUCH_NRPN;
				unsigned int DEVICE_USER_FIRMWARE_MODE_NRPN;
				unsigned int DEVICE_LEFT_HANDED_NRPN;
				// Value is constrained by MIN_LIGHTS_PRESET and MAX_LIGHTS_PRESET 
				unsigned int m_GLOBAL_ACTIVE_LIGHTS_PRESET_NRPN;
				// Values are constrained by MIN_CC and MAX_CC
				unsigned int GLOABAL_CC_FOR_CC65;  // Changes the CC for all switches - Legacy option, see NRPN 255 - 258
													  // Values are constrained by MIN_CC and MAX_CC
				unsigned int m_GLOBAL_MIN_VELOCITY_VALUE_NRPN;
				unsigned int m_GLOBAL_MAX_VELOCITY_VALUE_NRPN;
				unsigned int m_GLOBAL_FIXED_VELOCITY_VALUE_NRPN;
				// Value range =     0 - 512  
				unsigned int DEVICE_MIN_BYTE_INTERVAL_VALUE_NRPN;
				// Value is LSCustomRowOffset
				unsigned int m_GLOBAL_CUSTOM_ROW_OFFSET;
				// Toggle:
				unsigned int DEVICE_MIDI_THRU_NRPN;
				// Values are constrained by MIN_CC and MAX_CC
				unsigned int m_GLOBAL_CC_FOR_LEFT_FOOT_CC65;
				unsigned int m_GLOBAL_CC_FOR_RIGHT_FOOT_CC65;
				unsigned int m_GLOBAL_CC_FOR_SWITCH1_CC65;
				unsigned int m_GLOBAL_CC_FOR_SWITCH2_CC65;
				unsigned int m_GLOBAL_CC_FOR_LEFT_FOOT_SUSTAIN;
				unsigned int m_GLOBAL_CC_FOR_RIGHT_FOOT_SUSTAIN;
				unsigned int m_GLOBAL_CC_FOR_SWITCH1_SUSTAIN;
				unsigned int m_GLOBAL_CC_FOR_SWITCH2_SUSTAIN;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW1;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW2;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW3;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW4;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW5;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW6;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW7;
				unsigned int m_GLOBAL_GUITAR_NOTE_TUNING_ROW8;
				};
