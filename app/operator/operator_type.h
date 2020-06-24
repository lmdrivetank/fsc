#pragma once

typedef struct Ts_adu_context
{
    // no state total
	struct Ts_adm *pAdm;
	struct Ts_HealthMonitor *pHealthMonitor;
	struct Ts_PowerManager *pPowerManager;    
	struct Ts_UpgradeManager *pUpgradeManager;
	struct Ts_V2xManager *pV2xManager;
	struct Ts_ItManager *pItManager;          
};

// ad
