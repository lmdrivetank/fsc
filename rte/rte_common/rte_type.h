#ifndef _RTE_TYPE_H_
#define _RTE_TYPE_H_

#include <stdint.h>
#include <stdbool.h>
//ad request
typedef uint8_t Te_adr_u8;
#define	TE_ADR_NONE			0
#define	TE_ADR_ADPREPARE	1
#define	TE_ADR_ADEXIT		2
#define	TE_ADR_ADENGAGE		3
#define	TE_ADR_ADOFF		4
#define	TE_ADR_FALLBACK		5
#define	TE_ADR_MRC			6
#define	TE_ADR_COUNT		7

// ad state
typedef uint8_t Te_ads_u8;
typedef uint8_t Te_cybertron_u8;
#define	TE_ADS_IDLE         0
#define	TE_ADS_INIT         1
#define	TE_ADS_TERMINATE    2
#define	TE_ADS_READY        3
#define	TE_ADS_ADPREPARE    4
#define	TE_ADS_ADEXIT       5
#define	TE_ADS_ADREADY      6
#define	TE_ADS_ADENGAGE     7
#define	TE_ADS_ADOFF        8
#define	TE_ADS_ADRUN        9
#define	TE_ADS_FALLBACK     10
#define	TE_ADS_MRC          11
#define	TE_ADS_COUNT        12

typedef uint8_t Te_admerge_state_u8;
#define TE_AD_MERGE_NONE    0
#define TE_AD_MERGE_LEFT    1
#define TE_AD_MERGE_RIGHT   2
#define TE_AD_MERGE_COUNT   3

typedef uint16_t Te_AdFaultSpecies_u16;
#define TE_ADFAULT_SPECIED_NONE		0
#define TE_ADFAULT_SPECIED_FIRST	1
#define TE_ADFAULT_SPECIED_COUNT	2

typedef struct 
{
	Te_adr_u8 ad_request;
	Te_ads_u8 ad_state;
	Te_admerge_state_u8 merge_request;
	Te_admerge_state_u8 merge_status;
	Te_AdFaultSpecies_u16 ad_fault;
} Ad_Status_S;

// aa
typedef Te_adr_u8 Te_aa_request_u8;
typedef Te_ads_u8 Te_aa_state_u8;
typedef Te_admerge_state_u8 Te_aa_merge_state_u8;
typedef Ad_Status_S AA_Status_S;

// cybertron
typedef Te_adr_u8 Te_cybertron_r_u8;
typedef Te_ads_u8 Te_cybertron_s_u8;
typedef Te_admerge_state_u8 Te_CybertronMerge_state_u8;




typedef enum Te_lean_r
{
    Te_lean_r_none,
    Te_lean_r_init,
    Te_lean_r_terminate,
    Te_lean_r_enable,
    Te_lean_r_disable,

    Te_lean_r_count
};
typedef uint8_t Te_lean_r_u8;
typedef enum Te_lean_s
{
    Te_lean_s_idle,
    Te_lean_s_init,
    Te_lean_s_terminate,
    Te_lean_s_ready,
    Te_lean_s_enable,
    Te_lean_s_disable,
    Te_lean_s_run,

    Te_lean_s_count
};
typedef uint8_t Te_lean_s_u8;


typedef Te_adr_u8 Te_vci_r_u8;
typedef Te_ads_u8 Te_vci_s_u8;


typedef uint8_t Te_ControlSwitch_u8;
#define Te_ControlSwitch_Cybertron      0
#define Te_ControlSwitch_LeanControl    1

#endif