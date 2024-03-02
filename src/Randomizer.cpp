#include "Randomizer.h"

void Randomizer::ItemPickup(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *itemToReplace, app_ropeway_gamemastering_InventoryManager_PrimitiveItem *currentItem, GUID *itemPositionGuid)
{
	if (logger == nullptr ||
	    itemToReplace == nullptr || currentItem == nullptr || itemPositionGuid == nullptr)
		return;

	logger->LogMessage("[RE2R-R] Randomizer::ItemPickup(%s: %p, *%s: %s, *%s: %s) called.\n",
	                   RE2RR_NAMEOF(itemToReplace), itemToReplace,
	                   RE2RR_NAMEOF(currentItem), currentItem->ToString().c_str(),
	                   RE2RR_NAMEOF(itemPositionGuid), GUIDToString(itemPositionGuid).c_str());
	logger->LogMessage("[RE2R-R] GetItemByItemMapKey() returned: %s.\n",
	                   GetItemByItemMapKey(ItemMapKey{.ItemPositionGUID = *itemPositionGuid, .Scenario = *this->scenario, .Difficulty = *this->difficulty}).ToString().c_str());
	SetLastInteracted(currentItem, itemPositionGuid);
}

void Randomizer::SetLastInteracted(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *item, GUID *itemPositionGuid)
{
	this->lastInteractedItem = *item;
	this->lastInteractedItemPositionGuid = *itemPositionGuid;
}

app_ropeway_gamemastering_InventoryManager_PrimitiveItem *Randomizer::GetLastInteractedItem()
{
	return &this->lastInteractedItem;
}

GUID *Randomizer::GetLastInteractedItemPositionGuid()
{
	return &this->lastInteractedItemPositionGuid;
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

RE2RREnums::Difficulty Randomizer::GetDifficulty()
{
	if (difficulty != nullptr)
		return *difficulty;
	else
		return RE2RREnums::Difficulty::NORMAL;
}

RE2RREnums::Scenario Randomizer::GetScenario()
{
	if (scenario != nullptr)
		return *scenario;
	else
		return RE2RREnums::Scenario::INVALID;
}

RE2RREnums::MapPartsID Randomizer::GetMapPartsID()
{
	return mapPartsId;
}

RE2RREnums::MapID Randomizer::GetMapID()
{
	return mapId;
}

RE2RREnums::FloorID Randomizer::GetFloorID()
{
	return floorId;
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
