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

#define RE2RR_NAMEOF(name) #name

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

#include <array>
#include <stdint.h>
#include <string>
#include <vector>

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

	// app_ropeway_gamemastering_InventoryManager_PrimitiveItem(uint32_t ItemId, uint32_t WeaponId, uint32_t WeaponParts, uint32_t BulletId, uint32_t Count)
	// {
	// 	this->ItemId = ItemId;
	// 	this->WeaponId = WeaponId;
	// 	this->WeaponParts = WeaponParts;
	// 	this->BulletId = BulletId;
	// 	this->Count = Count;
	// }

	template <typename... TInt>
	app_ropeway_gamemastering_InventoryManager_PrimitiveItem(TInt &&...args)
	{
		static_assert(sizeof...(args) <= sizeof(app_ropeway_gamemastering_InventoryManager_PrimitiveItem), "Constructor requires less than or equal number of elements to the sizeof this struct.");
		std::vector<uint8_t> argsArray = {static_cast<uint8_t>(args)...};

		memset((void *)this, 0, sizeof(app_ropeway_gamemastering_InventoryManager_PrimitiveItem));

		for (size_t i = 0; i < argsArray.size(); ++i)
			*((uint8_t *)this + i) = argsArray[i];
	}

	std::string ToString()
	{
		const char *toStringFormat = "{ \"%s\": %d, \"%s\": %d, \"%s\": %d, \"%s\": %d, \"%s\": %d }";

		int bufferSize = snprintf(NULL, 0, toStringFormat,
		                          RE2RR_NAMEOF(ItemId), ItemId,
		                          RE2RR_NAMEOF(WeaponId), WeaponId,
		                          RE2RR_NAMEOF(WeaponParts), WeaponParts,
		                          RE2RR_NAMEOF(BulletId), BulletId,
		                          RE2RR_NAMEOF(Count), Count);
		char *toString = (char *)malloc(bufferSize + 1);
		snprintf(toString, bufferSize + 1, toStringFormat,
		         RE2RR_NAMEOF(ItemId), ItemId,
		         RE2RR_NAMEOF(WeaponId), WeaponId,
		         RE2RR_NAMEOF(WeaponParts), WeaponParts,
		         RE2RR_NAMEOF(BulletId), BulletId,
		         RE2RR_NAMEOF(Count), Count);
		std::string returnValue = std::string(toString);
		free(toString);

		return returnValue;
	}
};

#endif