#ifndef RE2RR_TYPES_H
#define RE2RR_TYPES_H

#ifdef __GNUC__
#define UNUSED(x) UNUSED_##x __attribute__((__unused__))
#else
#define UNUSED(x) UNUSED_##x
#endif

#ifdef __GNUC__
#define UNUSED_FUNCTION(x) __attribute__((__unused__)) UNUSED_##x
#else
#define UNUSED_FUNCTION(x) UNUSED_##x
#endif

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include <windows.h>

#include <stdint.h>
#include <string>

enum Character
{
	Leon = 0,
	Claire = 1
};

enum Scenario
{
	A = 0,
	B = 1
};

enum Difficulty
{
	Assisted = 0,
	Standard = 1,
	Hardcore = 2
};

struct app_ropeway_gamemastering_InventoryManager_PrimitiveItem
{
	// uint8_t _Reserved[0x10]; // 0x00-0x0F
	uint32_t ItemId;      // 0x10-0x13
	uint32_t WeaponId;    // 0x14-0x17
	uint32_t WeaponParts; // 0x18-0x1B
	uint32_t BulletId;    // 0x1C-0x1F
	uint32_t Count;       // 0x20-0x23
};

#endif