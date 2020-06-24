#pragma once

#include "adm_type.h"

typedef enum Te_hmi_adreq
{
	Te_hmi_adreq_none,
	Te_hmi_adreq_poweron,
	Te_hmi_adreq_poweroff,
	Te_hmi_adreq_engage,
	Te_hmi_adreq_takeover,
	Te_hmi_adreq_driver_lose_attention,
	 
	Te_hmi_adreq_count
};
typedef char Te_hmi_adreq_u8;
typedef enum Te_hmi_adres
{
	Te_hmi_adres_idle,
	Te_hmi_adres_poweron_doing,
	Te_hmi_adres_poweroff_doing,
	Te_hmi_adres_adready,
	Te_hmi_adres_engaging,
	Te_hmi_adres_engaged,
	Te_hmi_adres_takeover_fallwarning,
	Te_hmi_adres_takeover_succeed,
	Te_hmi_adres_attention_warning,

	Te_hmi_adreq_count
};
typedef char Te_hmi_adres_u8;

typedef enum Te_hmi_ota_note
{
	Te_hmi_ota_note_downloading,
	Te_hmi_ota_note_downloaded,
	Te_hmi_ota_note_upgrading,
	Te_hmi_ota_note_upgrade_succeed,
	Te_hmi_ota_note_upgrade_failed,

	Te_hmi_ota_note_count
};

typedef enum Te_hmi_ota_permit
{
	Te_hmi_ota_permit_download,
	Te_hmi_ota_permit_upgrade,

	Te_hmi_ota_permit_count
};

