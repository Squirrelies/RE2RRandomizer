#include "Randomizer.h"

const static char *logItemFormat = "\"%s\",\"%d\",\"0x%X\",\"%s\",\"%d\",\"0x%X\",\"%d\",\"0x%X\",\"%d\",\"0x%X\",\"%d\",\"0x%X\",\"%s\",\"%s\",\"%s\",\"%s\"\n";
void Randomizer::ItemPickup(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *itemToReplace, app_ropeway_gamemastering_InventoryManager_PrimitiveItem *currentItem, GUID *itemPositionGuid)
{
	if (logger == nullptr || itemLog == nullptr ||
	    itemToReplace == nullptr || currentItem == nullptr || itemPositionGuid == nullptr)
		return;

	logger->LogMessage("[RE2R-R] Randomizer::ItemPickup(%s: %p, *%s: %s, *%s: %s) called.\n",
	                   RE2RR_NAMEOF(itemToReplace), itemToReplace,
	                   RE2RR_NAMEOF(currentItem), currentItem->ToString().c_str(),
	                   RE2RR_NAMEOF(itemPositionGuid), GUIDToString(itemPositionGuid).c_str());
	itemLog->LogMessage(logItemFormat,
	                    RE2RREnums::EnumItemTypeToString(currentItem->ItemId).c_str(), currentItem->ItemId, currentItem->ItemId,
	                    RE2RREnums::EnumWeaponTypeToString(currentItem->WeaponId).c_str(), currentItem->WeaponId, currentItem->WeaponId,
	                    currentItem->WeaponParts, currentItem->WeaponParts,
	                    currentItem->BulletId, currentItem->BulletId,
	                    currentItem->Count, currentItem->Count,
	                    GUIDToString(itemPositionGuid).c_str(),
	                    RE2RREnums::EnumMapPartsIDToString(mapPartsId).c_str(),
	                    RE2RREnums::EnumMapIDToString(mapId).c_str(),
	                    RE2RREnums::EnumFloorIDToString(floorId).c_str());
}

bool Randomizer::ChangeArea(RE2RREnums::MapPartsID mapPartsId, RE2RREnums::MapID mapId, RE2RREnums::FloorID floorId)
{
	bool returnValue = this->mapPartsId != mapPartsId || this->mapId != mapId || this->floorId != floorId;
	if (returnValue)
	{
		this->mapPartsId = mapPartsId;
		this->mapId = mapId;
		this->floorId = floorId;
	}
	return returnValue;
}

void Randomizer::RandomizeItem(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *currentItem, app_ropeway_gamemastering_InventoryManager_PrimitiveItem newItem)
{
	if (currentItem == nullptr)
		return;

	logger->LogMessage("[RE2R-R] Randomizer::RandomizeItem().\n\tOld: %s.\n\tNew: %s.\n\t%s -> %s\n", currentItem->ToString().c_str(), newItem.ToString().c_str(), RE2RREnums::EnumItemTypeToString(currentItem->ItemId).c_str(), RE2RREnums::EnumItemTypeToString(newItem.ItemId).c_str());
	*currentItem = newItem;
}

std::string GUIDToString(GUID *guid)
{
	if (guid == nullptr)
		return {};

	char guid_string[(sizeof(GUID) * 2) + 4 + 1]; // (16 bytes (4+2+2+8) * 2 for character representation) + 4 hyphens + 1 null terminator = 37 bytes/chars.

	snprintf(
	    guid_string, sizeof(guid_string),
	    "%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
	    guid->Data1,
	    guid->Data2,
	    guid->Data3,
	    guid->Data4[0], guid->Data4[1],
	    guid->Data4[2], guid->Data4[3], guid->Data4[4], guid->Data4[5], guid->Data4[6], guid->Data4[7]);
	return std::string(guid_string);
}
