#ifndef MCASETTINGS_H
#define MCASETTINGS_H

#include "DIMHW.h"
#include "cstring"

// Defines
#define DEF_MCACAPS_SUPPORTS_MCS_CHANNEL 0x01
#define DEF_MCACAPS_SUPPORTS_PRESET_COUNTS 0x02
#define DEF_MCACAPS_SUPPORTS_PRESET_COUNTS_ROI 0x04
#define DEF_MCACAPS_SUPPORTS_EXT_COUNTER 0x08
#define DEF_MCACAPS_SUPPORTS_ICR_COUNTS 0x10
#define DEF_MCACAPS_SUPPORTS_BLR_RATE 0x20
#define DEF_MCACAPS_SUPPORTS_PUR_GUARD 0x40
#define DEF_MCACAPS_SUPPORTS_TRP_GUARD 0x80
#define DEF_MCACAPS_SUPPORTS_EXTENDED_LT 0x100
#define DEF_MCACAPS_SUPPORTS_GPIO 0x200
#define DEF_MCACAPS_SUPPORTS_ANALOG_PZ 0x400

struct MCASettings
{
    int iNumChannels;	// current spectrum size: 256, 512, 1024, 2048 or 4096
    int iMCAmode;		// zero means PHA, else is MCS

    float sAcqPreset;	// in seconds, with 0.1 second resolution (note: Single)
    int iAcqCounts;		// Value for Preset on Counts
    float sDwell;		// just to differentiate between PHA preset and MCS preset (0.1 sec resolution)
    int iAcqMode;		// zero means Real Time, else is Live Time

    int iGainDigital;	// in power of two units, e.g. 6 represents a gain of 2^6=64
    int iGainCoarse;	// in power of two units, e.g. 3 represents a gain of 2^3=8
    int iGainFine;		// in DAC units, 0..4095 corresponding to x1..x2

    int iLLD;			// in channels
    int iULD;			// in channels
    int iSCAL;			// in channels when in MCS
    int iSCAH;			// in channels when in MCS
    int iPHAL;			// Lower limit (channels) for PHA window used in PHA Preset on Counts Mode
    int iPHAH;			// Upper limit (channels) for PHA window used in PHA Preset on Counts Mode

    int iThreshold;		// in sampling ADC bits (not necessarily the end resolution bits)

    int iRiseTime;		// in sampling rate units (40ns)
    int iFlatTop;		// in sampling rate units (40ns)
    int iPZcanc;		// in sampling rate units (40ns)
    int iInpPolarity;	// either zero (negative, normal for PMT) or one (positive)
    int iBLRenable;		// either zero (disabled) or non-zero (enabled)
    int iPURenable;		// either zero (disabled) or non-zero (enabled)

    int iBLRrate;		// in sampling rate units
    int iPURguard;		// in sampling rate units
    int iTRPguard;		// in sampling rate units
    int iAnalogPZ;		// In DAC units, 0..4095
    int iLTtrim;		// 0 to 1000, 500 being the common setting
    int iGPIO1mode;
    int iGPIO1polarity; // 0 = positive (normal), else negative (inverted)
    int iGPIO2mode;
    int iGPIO2polarity; // 0 = positive (normal), else negative (inverted)

    int iADCrate;		// ADC sampling rate in samples/sec

    float sHVvalue;		// in Volts
    int iHVstatus;		// 0 = OFF, else ON

                        // Device capabilities
    int iMCAcaps;
    // Calibration
    float sOffset;
    float sSlope;
    float sQuadratic;

    // Max values
    float sHVmax;		// in Volts
    int iGainCoarseMax;    // Maximum coarse gain value
    float iGainFineMax; // Maximum fine gain value
    float iNumChannelsMax; // Maximum channels
    bool bTopaz;        // bMCA subtype Topaz (for I/O)
};

// Load/Save
static bool ReadMCAParams(HANDLE hMCA, MCASettings& settings)
{
    int iRet = 0;
    int iTemp = 0;
    float asCalFactors[3];

    // Load all the parameters
    if (!hMCA)
        return false;

    // First clear all parameters from the structure
    settings.iNumChannels = 0;
    settings.iMCAmode = 0;
    settings.iAcqCounts = 0;
    settings.iGainCoarse = 0;
    settings.iGainFine = 0;
    settings.iGainDigital = 0;
    settings.iRiseTime = 0;
    settings.iFlatTop = 0;
    settings.iPZcanc = 0;
    settings.iThreshold = 0;
    settings.iLLD = 0;
    settings.iULD = 0;
    settings.iSCAL = 0;
    settings.iSCAH = 0;
    settings.iPHAL = 0;
    settings.iPHAH = 0;
    settings.iInpPolarity = 0;
    settings.iBLRenable = 0;
    settings.iPURenable = 0;
    settings.sHVvalue = 0;
    settings.iHVstatus = 0;
    settings.sOffset = 0;
    settings.sSlope = 0;
    settings.sQuadratic = 0;
    settings.iADCrate = 0;
    settings.iLTtrim = 0;
    settings.iAnalogPZ = 0;
    settings.iPURguard = 0;
    settings.iTRPguard = 0;
    settings.iGPIO1mode = 0;
    settings.iGPIO1polarity = 0;
    settings.iGPIO2mode = 0;
    settings.iGPIO2polarity = 0;

    settings.sHVmax = 1500.0f;
    settings.iNumChannelsMax = 4096;
    settings.iGainCoarseMax = 3;
    settings.iGainFineMax = 4096;
    settings.bTopaz = false;

    // Get MCA parameters
    char szValue[DEF_MCA_STRING_LENGTH];
    iRet = GetParam(hMCA, DEF_MCA_PARAM_SERIAL_NUMBER, szValue, DEF_MCA_STRING_LENGTH);
    if (!strncmp(szValue, "08", 2) || !strncmp(szValue, "10", 2))
    {
        settings.iNumChannelsMax = 16384;
        settings.iGainCoarseMax = 7;
        settings.iGainFineMax = 16384;        
    }
    if (!strncmp(szValue, "06", 2))
    {
        settings.bTopaz = true;
    }

    settings.iMCAcaps = (DEF_MCACAPS_SUPPORTS_MCS_CHANNEL | DEF_MCACAPS_SUPPORTS_PRESET_COUNTS | DEF_MCACAPS_SUPPORTS_PRESET_COUNTS_ROI);

    iRet = GetParam(hMCA, DEF_MCA_PARAM_NUM_CHANNELS, &settings.iNumChannels, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_MCA_MODE, &settings.iMCAmode, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_ACQ_MODE_EX, &settings.iAcqMode, 4);		// 0x01 set = LT, 0x01 clear = RT
                                                                                    // 0x02 set on Time Preset (as above)
                                                                                    // 0x04 set on Counts Preset
                                                                                    // If both 0x02 and 0x04 are set then both modes are available and the device
                                                                                    // will stop acquisition when the first criteria is reached (time or counts)
    if (iRet != MCA_SUCCESS)
    {
        // early device, the functionality is not supported
        settings.iMCAcaps &= (~DEF_MCACAPS_SUPPORTS_PRESET_COUNTS);
        iRet = GetParam(hMCA, DEF_MCA_PARAM_ACQ_MODE, &settings.iAcqMode, 4);
        // translate old meaning of AcqMode to new
        settings.iAcqMode = settings.iAcqMode | 2;    // set the time preset bit, counts preset is clear
    }

    iRet = GetParam(hMCA, DEF_MCA_PARAM_ACQ_PRESET, &settings.sAcqPreset, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_ACQ_PRESET, &settings.sDwell, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_PRESET_COUNTS, &settings.iAcqCounts, 4);

    iRet = GetParam(hMCA, DEF_MCA_PARAM_GAIN_COARSE, &settings.iGainCoarse, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_GAIN_FINE, &settings.iGainFine, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_GAIN_DIGITAL, &settings.iGainDigital, 4);

    iRet = GetParam(hMCA, DEF_MCA_PARAM_RISE_TIME, &settings.iRiseTime, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_FLAT_TOP, &settings.iFlatTop, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_PZ_ADJ, &settings.iPZcanc, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_THRESHOLD, &settings.iThreshold, 4);

    iRet = GetParam(hMCA, DEF_MCA_PARAM_PHA_LLD, &settings.iLLD, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_PHA_ULD, &settings.iULD, 4);
    // as well as for MCS
    iRet = GetParam(hMCA, DEF_MCA_PARAM_PHA_LLD, &settings.iSCAL, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_PHA_ULD, &settings.iSCAH, 4);

    // Limits for Preset Count
    if ((settings.iMCAcaps & DEF_MCACAPS_SUPPORTS_PRESET_COUNTS) != 0)
    {
        iRet = GetParam(hMCA, DEF_MCA_PARAM_PHA_PRESET_LLD, &settings.iPHAL, 4);
        iRet = GetParam(hMCA, DEF_MCA_PARAM_PHA_PRESET_ULD, &settings.iPHAH, 4);
        if (iRet != MCA_SUCCESS)
        {
            settings.iMCAcaps &= (~DEF_MCACAPS_SUPPORTS_PRESET_COUNTS_ROI);
            iRet = GetParam(hMCA, DEF_MCA_PARAM_PHA_LLD, &settings.iPHAL, 4);
            iRet = GetParam(hMCA, DEF_MCA_PARAM_PHA_ULD, &settings.iPHAH, 4);
        }
    }
    else
    {
        settings.iPHAL = 0;
        settings.iPHAH = 0;
    }

    iRet = GetParam(hMCA, DEF_MCA_PARAM_INP_POLARITY, &settings.iInpPolarity, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_BLR_ENABLE, &settings.iBLRenable, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_PUR_ENABLE, &settings.iPURenable, 4);

    // High voltage
    iRet = GetParam(hMCA, DEF_MCA_PARAM_HV_VALUE, &settings.sHVvalue, 4);
    iRet = GetParam(hMCA, DEF_MCA_PARAM_HV_STATUS, &settings.iHVstatus, 4);

    // Get the calibration
    iRet = GetParam(hMCA, DEF_MCA_PARAM_CALIBRATION, &asCalFactors[0], 12);
    settings.sOffset = asCalFactors[0];
    settings.sSlope = asCalFactors[1];
    settings.sQuadratic = asCalFactors[2];

    // Get the ADC rate
    iRet = GetParam(hMCA, DEF_MCA_PARAM_ADC_SAMPLING_RATE, &settings.iADCrate, 4);
    if (iRet != MCA_SUCCESS || settings.iADCrate == 0)
    {
        settings.iADCrate = 25000000;
    }

    // Get HVmax
    iRet = GetParam(hMCA, DEF_MCA_PARAM_HV_INFO, &iTemp, 4);
    if (iRet != MCA_SUCCESS || iTemp == 0)
        settings.sHVmax = 1500;
    else
        settings.sHVmax = (float)iTemp / 10.0f;

    // Test for extended bMCA and Topaz-X features
    iRet = GetParam(hMCA, DEF_MCA_PARAM_ICR_COUNTS, &iTemp, 4);
    if (iRet == MCA_SUCCESS)
    {
        settings.iMCAcaps |= DEF_MCACAPS_SUPPORTS_ICR_COUNTS;
    }

    iRet = GetParam(hMCA, DEF_MCA_PARAM_LT_TRIM, &iTemp, 4);
    if (iRet == MCA_SUCCESS)
    {
        settings.iMCAcaps |= DEF_MCACAPS_SUPPORTS_EXTENDED_LT;
        settings.iLTtrim = iTemp;
    }
    else
    {
        settings.iLTtrim = 0;
    }

    iRet = GetParam(hMCA, DEF_MCA_PARAM_ANALOG_PZ_ADJ, &iTemp, 4);
    if (iRet == MCA_SUCCESS)
    {
        settings.iMCAcaps |= DEF_MCACAPS_SUPPORTS_ANALOG_PZ;
        settings.iAnalogPZ = iTemp;
    }
    else
    {
        settings.iAnalogPZ = 0;
    }

    iRet = GetParam(hMCA, DEF_MCA_PARAM_PUR_GUARD, &iTemp, 4);
    if (iRet == MCA_SUCCESS)
    {
        settings.iMCAcaps |= DEF_MCACAPS_SUPPORTS_PUR_GUARD;
        settings.iPURguard = iTemp;
    }
    else
    {
        settings.iPURguard = 0;
    }

    iRet = GetParam(hMCA, DEF_MCA_PARAM_TRP_GUARD, &iTemp, 4);
    if (iRet == MCA_SUCCESS)
    {
        settings.iMCAcaps |= DEF_MCACAPS_SUPPORTS_TRP_GUARD;
        settings.iTRPguard = iTemp;
    }
    else
    {
        settings.iTRPguard = 0;
    }

    settings.iGPIO1mode = 0;
    settings.iGPIO1polarity = 0;
    settings.iGPIO2mode = 0;
    settings.iGPIO2polarity = 0;

    iRet = GetParam(hMCA, DEF_MCA_PARAM_GPIO1_MODE, &iTemp, 4);
    if (iRet == MCA_SUCCESS)
    {
        settings.iMCAcaps |= DEF_MCACAPS_SUPPORTS_GPIO;  // this implies support for external acq control
        settings.iGPIO1mode = iTemp & 0x7F;
        settings.iGPIO1polarity = ((iTemp & DEF_MCA_GPIO_POLARITY_NEGATIVE) != 0) ? 1 : 0;
        iRet = GetParam(hMCA, DEF_MCA_PARAM_GPIO2_MODE, &iTemp, 4);
        if (iRet == MCA_SUCCESS)
        {
            settings.iGPIO2mode = iTemp & 0x7F;
            settings.iGPIO2polarity = ((iTemp & DEF_MCA_GPIO_POLARITY_NEGATIVE) != 0) ? 1 : 0;
        }
    }
    else
    {
        // Check if TOPAZ
        if (settings.bTopaz)
        {
            iRet = GetParam(hMCA, DEF_MCA_PARAM_EXT_IO_MODE, &iTemp, 4);
            if (iRet == MCA_SUCCESS)
            {
                settings.iMCAcaps |= DEF_MCACAPS_SUPPORTS_EXT_COUNTER;
                settings.iGPIO1mode = (iTemp == 0) ? 0 : 1;
            }
        }
    }
    return true;
}
static bool WriteMCAParams(HANDLE hMCA, MCASettings settings)
{
    int iRet = 0;
    int iFunc = 0;
    float asCalFactors[3];

    if (!hMCA)
        return false;

    iRet = SetParam(hMCA, DEF_MCA_PARAM_NUM_CHANNELS, &settings.iNumChannels, 4);
    iRet = SetParam(hMCA, DEF_MCA_PARAM_MCS_CHANNELS, &settings.iNumChannels, 4);
    iRet = SetParam(hMCA, DEF_MCA_PARAM_MCA_MODE, &settings.iMCAmode, 4);

    if ((settings.iMCAcaps & DEF_MCACAPS_SUPPORTS_PRESET_COUNTS) != 0)
    {
        iRet = SetParam(hMCA, DEF_MCA_PARAM_ACQ_MODE_EX, &settings.iAcqMode, 4);
        // Set Preset on counts indistnguishly
        iRet = SetParam(hMCA, DEF_MCA_PARAM_PRESET_COUNTS, &settings.iAcqCounts, 4);
        if ((settings.iMCAcaps & DEF_MCACAPS_SUPPORTS_PRESET_COUNTS_ROI) != 0)
        {
            iRet = SetParam(hMCA, DEF_MCA_PARAM_PHA_PRESET_LLD, &settings.iPHAL, 4);
            iRet = SetParam(hMCA, DEF_MCA_PARAM_PHA_PRESET_ULD, &settings.iPHAH, 4);
        }
        else
        {
            iRet = SetParam(hMCA, DEF_MCA_PARAM_PHA_LLD, &settings.iPHAL, 4);
            iRet = SetParam(hMCA, DEF_MCA_PARAM_PHA_ULD, &settings.iPHAH, 4);
        }
    }
    else
    {
        settings.iAcqMode &= 1;
        iRet = SetParam(hMCA, DEF_MCA_PARAM_ACQ_MODE, &settings.iAcqMode, 4);
    }

    iRet = SetParam(hMCA, DEF_MCA_PARAM_GAIN_COARSE, &settings.iGainCoarse, 4);
    iRet = SetParam(hMCA, DEF_MCA_PARAM_GAIN_FINE, &settings.iGainFine, 4);
    iRet = SetParam(hMCA, DEF_MCA_PARAM_GAIN_DIGITAL, &settings.iGainDigital, 4);

    iRet = SetParam(hMCA, DEF_MCA_PARAM_RISE_TIME, &settings.iRiseTime, 4);
    iRet = SetParam(hMCA, DEF_MCA_PARAM_FLAT_TOP, &settings.iFlatTop, 4);
    iRet = SetParam(hMCA, DEF_MCA_PARAM_PZ_ADJ, &settings.iPZcanc, 4);
    iRet = SetParam(hMCA, DEF_MCA_PARAM_THRESHOLD, &settings.iThreshold, 4);

    if (settings.iMCAmode != 0)    // PHA (0) or MCS (1)
    {
        iRet = SetParam(hMCA, DEF_MCA_PARAM_ACQ_PRESET, &settings.sDwell, 4);
        iRet = SetParam(hMCA, DEF_MCA_PARAM_PHA_LLD, &settings.iSCAL, 4);
        iRet = SetParam(hMCA, DEF_MCA_PARAM_PHA_ULD, &settings.iSCAH, 4);
    }
    else
    {
        iRet = SetParam(hMCA, DEF_MCA_PARAM_ACQ_PRESET, &settings.sAcqPreset, 4);
        iRet = SetParam(hMCA, DEF_MCA_PARAM_PHA_LLD, &settings.iLLD, 4);
        iRet = SetParam(hMCA, DEF_MCA_PARAM_PHA_ULD, &settings.iULD, 4);
    }

    iRet = SetParam(hMCA, DEF_MCA_PARAM_INP_POLARITY, &settings.iInpPolarity, 4);
    iRet = SetParam(hMCA, DEF_MCA_PARAM_BLR_ENABLE, &settings.iBLRenable, 4);
    iRet = SetParam(hMCA, DEF_MCA_PARAM_PUR_ENABLE, &settings.iPURenable, 4);

    iRet = SetParam(hMCA, DEF_MCA_PARAM_HV_VALUE, &settings.sHVvalue, 4);
    iRet = SetParam(hMCA, DEF_MCA_PARAM_HV_STATUS, &settings.iHVstatus, 4);

    asCalFactors[0] = settings.sOffset;
    asCalFactors[1] = settings.sSlope;
    asCalFactors[2] = settings.sQuadratic;
    iRet = SetParam(hMCA, DEF_MCA_PARAM_CALIBRATION, &asCalFactors, 12);

    // Set advanced MCA parameters
    if ((settings.iMCAcaps & DEF_MCACAPS_SUPPORTS_EXTENDED_LT) != 0)
        iRet = SetParam(hMCA, DEF_MCA_PARAM_LT_TRIM, &settings.iLTtrim, 4);

    if ((settings.iMCAcaps & DEF_MCACAPS_SUPPORTS_ANALOG_PZ) != 0)
        iRet = SetParam(hMCA, DEF_MCA_PARAM_ANALOG_PZ_ADJ, &settings.iAnalogPZ, 4);

    if ((settings.iMCAcaps & DEF_MCACAPS_SUPPORTS_PUR_GUARD) != 0)
        iRet = SetParam(hMCA, DEF_MCA_PARAM_PUR_GUARD, &settings.iPURguard, 4);

    if ((settings.iMCAcaps & DEF_MCACAPS_SUPPORTS_TRP_GUARD) != 0)
        iRet = SetParam(hMCA, DEF_MCA_PARAM_TRP_GUARD, &settings.iTRPguard, 4);

    if ((settings.iMCAcaps & DEF_MCACAPS_SUPPORTS_GPIO) != 0)
    {
        iFunc = settings.iGPIO1mode;
        if (settings.iGPIO1polarity != 0)
            iFunc = iFunc | DEF_MCA_GPIO_POLARITY_NEGATIVE;
        iRet = SetParam(hMCA, DEF_MCA_PARAM_GPIO1_MODE, &iFunc, 4);
        iFunc = settings.iGPIO2mode;
        if (settings.iGPIO2polarity != 0)
            iFunc = iFunc | DEF_MCA_GPIO_POLARITY_NEGATIVE;
        iRet = SetParam(hMCA, DEF_MCA_PARAM_GPIO2_MODE, &iFunc, 4);
        // Re-set acquisition mode to confirm
        if (GetParam(hMCA, DEF_MCA_PARAM_ACQ_MODE_EX, &settings.iAcqMode, 4) == MCA_SUCCESS)
            iRet = SetParam(hMCA, DEF_MCA_PARAM_ACQ_MODE_EX, &settings.iAcqMode, 4);
    }
    else if ((settings.iMCAcaps & DEF_MCACAPS_SUPPORTS_EXT_COUNTER) != 0)
    {
        iFunc = settings.iGPIO1mode;
        iRet = SetParam(hMCA, DEF_MCA_PARAM_EXT_IO_MODE, &iFunc, 4);
    }
    return true;
}

#endif // MCASETTINGS_H
