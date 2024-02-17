#include "Randomizer.h"

const static char *logItemFormat = "\"%s\",\"%d\",\"0x%X\",\"%s\",\"%d\",\"0x%X\",\"%d\",\"0x%X\",\"%d\",\"0x%X\",\"%d\",\"0x%X\",\"%s\"\n";
void Randomizer::ItemPickup(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *currentItem, GUID *itemPositionGuid)
{
	logger->LogMessage("[RE2R-R] Randomizer::ItemPickup(*currentItem: %s, itemPositionGuid: %s) called.\n", currentItem->ToString().c_str(), GUIDToString(itemPositionGuid).c_str());
	itemLog->LogMessage(logItemFormat,
	                    RE2RREnums::EnumItemTypeToString(currentItem->ItemId).c_str(), currentItem->ItemId, currentItem->ItemId,
	                    RE2RREnums::EnumWeaponTypeToString(currentItem->WeaponId).c_str(), currentItem->WeaponId, currentItem->WeaponId,
	                    currentItem->WeaponParts, currentItem->WeaponParts,
	                    currentItem->BulletId, currentItem->BulletId,
	                    currentItem->Count, currentItem->Count,
	                    GUIDToString(itemPositionGuid).c_str());
	// SetItemByGUID(currentItem, itemPositionGuid);
}

void Randomizer::RandomizeItem(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *currentItem, app_ropeway_gamemastering_InventoryManager_PrimitiveItem newItem)
{
	logger->LogMessage("[RE2R-R] Randomizer::RandomizeItem().\n\tOld: %s.\n\tNew: %s.\n\t%s -> %s\n", currentItem->ToString().c_str(), newItem.ToString().c_str(), RE2RREnums::EnumItemTypeToString(currentItem->ItemId).c_str(), RE2RREnums::EnumItemTypeToString(newItem.ItemId).c_str());
	//*currentItem = newItem;
}

// Returns a vector of uint8_t representing the app.ropeway.gamemastering.InventoryManager.PrimitiveItem structure 0x10-0x24 (0x14).
app_ropeway_gamemastering_InventoryManager_PrimitiveItem Randomizer::GetItemByType(uint32_t type)
{
	if (type == 0 || type == 3 || type == 5 || type == 7 || type == 8 || type == 12 || type == 16 || type == 19 || type == 26 || type == 27 || type == 39 || type == 46 || type == 51 || type == 56 || type == 59 || type == 69 || type == 79 || type == 83 || type == 92 || type == 107 || type == 111 || type == 113 || type == 118 || type == 137 || type == 143 || type == 146 || type == 147 || type == 148 || type == 153 || type == 162 || type == 182 || type == 188 || type == 193 || type == 220 || type == 229 || type == 231 || type == 237 || type == 238 || type == 243 || type == 245 || type == 256 || type == 260 || type == 264)
	{
		if (*difficulty == RE2RREnums::Difficulty::Hardcore)
		{
			if (type == 16)
			{
				return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
			}
			else if (type == 0)
			{
				return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
			}
		}
		else if (*scenario == RE2RREnums::Scenario::B)
		{
			if (type == 16 || type == 0)
			{
				return {0x1A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00};
			}
		}
		if (*character == RE2RREnums::Character::Leon)
		{
			if (*scenario == RE2RREnums::Scenario::A)
			{
				if (*difficulty == RE2RREnums::Difficulty::Hardcore)
				{
					return {0x0F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
				}
				else
				{
					return {0x0F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00};
				}
			}
			else
			{
				if (*difficulty == RE2RREnums::Difficulty::Hardcore)
				{
					return {0x1A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
				}
				else
				{
					return {0x1A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00};
				}
			}
		}
		else
		{
			if (type == 146)
			{
				return {0xA0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
			}
			else if (type == 147)
			{
				return {0x50, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
			}
			else if (type == 118)
			{
				return {0x27, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
			}
			else if (type == 143 || type == 137 || type == 245)
			{
				if (*difficulty == RE2RREnums::Difficulty::Hardcore)
				{
					return {0x11, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x00};
				}
				else
				{
					return {0x11, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x00};
				}
			}
			else
			{
				if (*scenario == RE2RREnums::Scenario::A)
				{
					if (*difficulty == RE2RREnums::Difficulty::Hardcore)
					{
						return {0x0F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
					}
					else
					{
						return {0x0F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00};
					}
				}
				else
				{
					if (*difficulty == RE2RREnums::Difficulty::Hardcore)
					{
						return {0x1A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
					}
					else
					{
						return {0x1A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00};
					}
				}
			}
		}
	}

	if (type == 1 || type == 29 || type == 98 || type == 121 || type == 230 || type == 239)
	{
		return {0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 2)
	{
		return {0x76, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 4 || type == 20 || type == 60 || type == 135 || type == 155 || type == 190 || type == 196 || type == 217 || type == 240 || type == 261)
	{
		if (*scenario == RE2RREnums::Scenario::B && type == 4)
		{
			if (*character == RE2RREnums::Character::Leon)
			{
				return {0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x07, 0x00};
			}
			else
			{
				return {0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x05, 0x00};
			}
		}
		else
		{
			return {0x00, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x03};
		}
	}

	if (type == 6 || type == 9 || type == 31 || type == 37 || type == 44 || type == 65 || type == 72 || type == 85 || type == 86 || type == 109 || type == 112 || type == 115 || type == 131 || type == 141 || type == 171 || type == 173 || type == 185 || type == 201 || type == 214 || type == 242)
	{
		if (*difficulty == RE2RREnums::Difficulty::Hardcore)
		{
			if (type == 37)
			{
				return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
			}
		}
		if (*scenario == RE2RREnums::Scenario::B && type == 131 && *character == RE2RREnums::Character::Leon)
		{
			return {0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x02, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 10 || type == 28 || type == 33 || type == 55 || type == 64 || type == 70 || type == 81)
	{
		return {0x21, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 11 || type == 15 || type == 21 || type == 35 || type == 40 || type == 54 || type == 62 || type == 87 || type == 90 || type == 93 || type == 102 || type == 103 || type == 114 || type == 133 || type == 152 || type == 202 || type == 218)
	{
		if (*scenario == RE2RREnums::Scenario::B && type == 62)
		{
			return {0x28, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			if (*difficulty == RE2RREnums::Difficulty::Hardcore)
			{
				if (type == 35)
				{
					return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
				}
				else if (type == 37)
				{
					return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
				}
			}
			if (*character == RE2RREnums::Character::Leon)
			{
				return {0x24, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
			}
			else
			{
				if (type == 87)
				{
					return {0x04, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
				}
				else if (type == 133)
				{
					return {0x02, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
				}
				else
				{
					return {0x24, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
				}
			}
		}
	}

	if (type == 13 || type == 22 || type == 57 || type == 116 || type == 180 || type == 200)
	{
		if (*difficulty == RE2RREnums::Difficulty::Hardcore)
		{
			if (type == 116)
			{
				return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
			}
		}
	}

	if (type == 14)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x30, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x33, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 17 || type == 47 || type == 84 || type == 96 || type == 110 || type == 124 || type == 130 || type == 166 || type == 175 || type == 186 || type == 206 || type == 228 || type == 244 || type == 257)
	{
		return {0x03, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 18)
	{
		return {0x4A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 23 || type == 25 || type == 48 || type == 49 || type == 78 || type == 94 || type == 104 || type == 128 || type == 134 || type == 149 || type == 160 || type == 183 || type == 191 || type == 197 || type == 212 || type == 250)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			if (*difficulty == RE2RREnums::Difficulty::Hardcore)
			{
				return {0x10, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
			}
			else
			{
				return {0x10, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
			}
		}
		else
		{
			if (type == 149 || type == 183 || type == 134)
			{
				if (*difficulty == RE2RREnums::Difficulty::Hardcore)
				{
					return {0x1B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
				}
				else
				{
					return {0x1B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
				}
			}
			else
			{
				if (*difficulty == RE2RREnums::Difficulty::Hardcore)
				{
					return {0x17, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
				}
				else
				{
					return {0x17, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
				}
			}
		}
	}

	if (type == 24)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x00, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00};
		}
		else
		{
			return {0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00};
		}
	}

	if (type == 30)
	{
		return {0x22, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 32 || type == 38 || type == 80 || type == 97 || type == 125 || type == 189 || type == 205 || type == 233 || type == 236)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 34 || type == 105 || type == 108 || type == 142 || type == 145 || type == 172 || type == 192 || type == 210 || type == 223 || type == 235 || type == 259)
	{
		if (*scenario == RE2RREnums::Scenario::B && *character == RE2RREnums::Character::Claire && type == 145)
		{
			if (*difficulty == RE2RREnums::Difficulty::Hardcore)
			{
				return {0x11, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x00};
			}
			else
			{
				return {0x11, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x00};
			}
		}
		else
		{
			return {0x00, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 36)
	{
		return {0x4F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 41)
	{
		return {0x56, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 42 || type == 89 || type == 99 || type == 123 || type == 140 || type == 157 || type == 158 || type == 203 || type == 216 || type == 219 || type == 225 || type == 227 || type == 263)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x26, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x27, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 43)
	{
		if (*scenario == RE2RREnums::Scenario::A)
		{
			return {0xF0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x83, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 45)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x31, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x36, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 50 || type == 101)
	{
		if (*scenario == RE2RREnums::Scenario::B && type == 50)
		{
			return {0x5B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x70, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 52 || type == 138 || type == 154 || type == 161 || type == 174 || type == 187 || type == 232)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			if (*difficulty == RE2RREnums::Difficulty::Hardcore)
			{
				return {0x12, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
			}
			else
			{
				return {0x12, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00};
			}
		}
		else
		{
			if (type == 154 || type == 232)
			{
				if (*difficulty == RE2RREnums::Difficulty::Hardcore)
				{
					return {0x1B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
				}
				else
				{
					return {0x1B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
				}
			}
			else
			{
				if (*difficulty == RE2RREnums::Difficulty::Hardcore)
				{
					return {0x11, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x00};
				}
				else
				{
					return {0x11, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x00};
				}
			}
		}
	}

	if (type == 53)
	{
		return {0x52, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 58)
	{
		return {0x7C, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 61)
	{
		return {0x72, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 63)
	{
		return {0x51, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 66)
	{
		return {0x54, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 67)
	{
		return {0x73, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 68)
	{
		return {0x58, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 71)
	{
		return {0xF4, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 73 || type == 156 || type == 195 || type == 209 || type == 211 || type == 226)
	{
		return {0x25, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 74)
	{
		return {0x81, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 75)
	{
		return {0x87, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 76 || type == 82 || type == 122 || type == 136 || type == 159 || type == 168 || type == 176 || type == 184 || type == 207 || type == 224 || type == 241 || type == 258 || type == 262)
	{
		return {0x04, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 77)
	{
		return {0x82, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 88)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0xA0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x40, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 91)
	{
		if (*scenario == RE2RREnums::Scenario::A)
		{
			return {0x5B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x70, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 95)
	{
		return {0x23, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 100)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x03, 0x00};
		}
		else
		{
			return {0x00, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x14, 0x00};
		}
	}

	if (type == 106)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x3E, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x3C, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 117)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x32, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0D, 0x00};
		}
	}

	if (type == 119)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x50, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x00, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1D, 0x00, 0x00, 0x00, 0x90, 0x01};
		}
	}

	if (type == 120)
	{
		return {0x53, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 126)
	{
		return {0x77, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 127)
	{
		return {0x25, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x78};
	}

	if (type == 129)
	{
		return {0x4B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 132)
	{
		return {0x88, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 139)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0xF1, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 144)
	{
		if (*scenario == RE2RREnums::Scenario::B && *character == RE2RREnums::Character::Claire)
		{
			if (*difficulty == RE2RREnums::Difficulty::Hardcore)
			{
				return {0x17, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
			}
			else
			{
				return {0x17, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
			}
		}
		else
		{
			return {0x38, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 150)
	{
		return {0xAA, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 151)
	{
		return {0x5E, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x00};
	}

	if (type == 163)
	{
		return {0x5D, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x00};
	}

	if (type == 164)
	{
		return {0x84, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x00};
	}

	if (type == 165)
	{
		return {0x85, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x00};
	}

	if (type == 167)
	{
		return {0xB0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 169)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x37, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x35, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 170)
	{
		return {0xC2, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 177)
	{
		return {0x86, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x00};
	}

	if (type == 178)
	{
		return {0x5F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x00};
	}

	if (type == 179)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x00, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x90, 0x01};
		}
		else
		{
			return {0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x07, 0x00};
		}
	}

	if (type == 181)
	{
		return {0x48, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 194 || type == 215 || type == 234)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x19, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x00};
		}
		else
		{
			if (type == 215)
			{
				if (*difficulty == RE2RREnums::Difficulty::Hardcore)
				{
					return {0x17, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
				}
				else
				{
					return {0x17, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
				}
			}
			else
			{
				return {0x18, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00};
			}
		}
	}

	if (type == 198)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x41, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x42, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 199)
	{
		return {0xC6, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 204)
	{
		return {0xB3, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 208)
	{
		return {0xC7, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 213)
	{
		return {0xBE, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 221)
	{
		return {0xBD, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 222)
	{
		return {0xCB, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 246)
	{
		return {0xB7, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 247)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x19, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x01};
		}
		else
		{
			return {0x18, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00};
		}
	}

	if (type == 248)
	{
		if (*character == RE2RREnums::Character::Leon)
		{
			return {0x26, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x3A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (type == 249)
	{
		return {0x49, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 251 || type == 252 || type == 255)
	{
		return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 254 || type == 253)
	{
		return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
	}

	if (type == 265)
	{
		return {0xF1, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 266)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00};
	}

	if (type == 267)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x03, 0x00};
	}

	if (type == 268)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x90, 0x01};
	}

	if (type == 269)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00};
	}

	if (type == 270)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x14, 0x00};
	}

	if (type == 271)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0D, 0x00};
	}

	if (type == 272)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x07, 0x00};
	}

	if (type == 273)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1D, 0x00, 0x00, 0x00, 0x90, 0x01};
	}

	if (type == 274)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x04, 0x00};
	}

	if (type == 275)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x0A, 0x00};
	}

	if (type == 276)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x05, 0x00};
	}

	if (type == 277)
	{
		return {0x33, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 278)
	{
		return {0x30, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 279)
	{
		return {0x31, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 280)
	{
		return {0x3E, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 281)
	{
		return {0x38, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 282)
	{
		return {0x37, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 283)
	{
		return {0x41, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 284)
	{
		return {0x26, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 285)
	{
		return {0x36, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 286)
	{
		return {0x3C, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 287)
	{
		return {0x35, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 288)
	{
		return {0x42, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 289)
	{
		return {0x3A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 290)
	{
		return {0x40, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 291)
	{
		return {0x32, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 292)
	{
		if (*scenario == RE2RREnums::Scenario::A)
		{
			if (*difficulty == RE2RREnums::Difficulty::Hardcore)
			{
				return {0x0F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
			}
			else
			{
				return {0x0F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00};
			}
		}
		else
		{
			if (*difficulty == RE2RREnums::Difficulty::Hardcore)
			{
				return {0x1A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
			}
			else
			{
				return {0x1A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00};
			}
		}
	}

	if (type == 293)
	{
		return {0x18, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00};
	}

	if (type == 294)
	{
		return {0x19, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x00};
	}

	if (type == 295)
	{
		if (*difficulty == RE2RREnums::Difficulty::Hardcore)
		{
			return {0x1B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
		}
		else
		{
			return {0x1B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
		}
	}

	if (type == 296)
	{
		return {0x25, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 297)
	{
		if (*difficulty == RE2RREnums::Difficulty::Hardcore)
		{
			return {0x12, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
		}
		else
		{
			return {0x12, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00};
		}
	}

	if (type == 298)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x03};
	}

	if (type == 299)
	{
		if (*difficulty == RE2RREnums::Difficulty::Hardcore)
		{
			return {0x11, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x00};
		}
		else
		{
			return {0x11, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x00};
		}
	}

	if (type == 300)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 301)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 302)
	{
		return {0x26, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 303)
	{
		if (*difficulty == RE2RREnums::Difficulty::Hardcore)
		{
			return {0x17, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x17, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
		}
	}

	if (type == 304)
	{
		return {0x27, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 305)
	{
		if (*difficulty == RE2RREnums::Difficulty::Hardcore)
		{
			return {0x10, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
		}
		else
		{
			return {0x10, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
		}
	}

	if (type == 306)
	{
		return {0x24, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (type == 307)
	{
		return {0x19, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x01};
	}

	if (type == 308)
	{
		return {0x18, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00};
	}

	if (type == 309)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x05, 0x00};
	}

	if (type == 310)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x07, 0x00};
	}

	// return {};
	// return app_ropeway_gamemastering_InventoryManager_PrimitiveItem(19, -1, 0, 0, 0);
	logger->LogMessage("Randomizer::GetItemByType(%s: %d) failed to find a match!\n", RE2RR_NAMEOF(type), type);
	return {0x13, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
}

/*
    uint32_t ItemId;      // 0x10-0x13
    uint32_t WeaponId;    // 0x14-0x17
    uint32_t WeaponParts; // 0x18-0x1B
    uint32_t BulletId;    // 0x1C-0x1F
    uint32_t Count;       // 0x20-0x23
*/

void Randomizer::SetItemByGUID(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *currentItem, GUID *itemPositionGuid)
{
	uint8_t *uniqueID = (uint8_t *)itemPositionGuid;

	if (uniqueID[0] == 0x00)
	{
		if (uniqueID[1] == 0x7D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[145 - 1]));
			//--claire's flame rounds outside break room, b scenario
		}
	}

	if (uniqueID[0] == 0x01)
	{
		if (uniqueID[1] == 0x3A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[39 - 1]));
			// flash grenade, east office
		}
		if (uniqueID[1] == 0xBD)
		{
			RandomizeItem(currentItem, GetItemByType(seed[196 - 1]));
			// large gunpowder, kitchen
		}
	}

	if (uniqueID[0] == 0x02)
	{
		if (uniqueID[1] == 0x5C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[244 - 1]));
			// ACP ammo, pump room, b scenario
		}
		if (uniqueID[1] == 0x80)
		{
			RandomizeItem(currentItem, GetItemByType(seed[183 - 1]));
			// ACP Ammo, Workroom, b scenario
		}
		if (uniqueID[1] == 0x8A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[79 - 1]));
			// flame rounds, east storage room. claire
		}
		if (uniqueID[1] == 0xF4)
		{
			RandomizeItem(currentItem, GetItemByType(seed[203 - 1]));
			// gunpowder, Lobby
		}
	}

	if (uniqueID[0] == 0x03)
	{
		RandomizeItem(currentItem, GetItemByType(seed[157 - 1]));
		// large gunpowder, water injection chamber
	}

	if (uniqueID[0] == 0x04)
	{
		if (uniqueID[1] == 0x28)
		{
			RandomizeItem(currentItem, GetItemByType(seed[146 - 1]));
			// hand grenade, sewer entrance
		}
		if (uniqueID[1] == 0x33)
		{
			RandomizeItem(currentItem, GetItemByType(seed[74 - 1]));
			// large gunpowder, racoon area west
		}
		if (uniqueID[1] == 0x81)
		{
			RandomizeItem(currentItem, GetItemByType(seed[155 - 1]));
			// mag ammo, rpd access room
		}
	}

	if (uniqueID[0] == 0x05)
	{
		if (uniqueID[1] == 0xB8)
		{
			// B8 is rook re-pickup
			// debug_continueFromBreakpoint(co_run);
		}
		if (uniqueID[1] == 0xF7)
		{
			RandomizeItem(currentItem, GetItemByType(seed[248 - 1]));
			// extra flamethrower fuel, hiding place press room
		}
	}

	if (uniqueID[0] == 0x07)
	{
		RandomizeItem(currentItem, GetItemByType(seed[33 - 1]));
		// flash grenade, detonator room
	}

	if (uniqueID[0] == 0x08)
	{
		if (uniqueID[1] == 0x80)
		{
			RandomizeItem(currentItem, GetItemByType(seed[44 - 1]));
			// courtyard key, guard room, b scenario
		}
		if (uniqueID[1] == 0x0E)
		{
			RandomizeItem(currentItem, GetItemByType(seed[220 - 1]));
			// yellow gunpowder, modulator room
		}
		if (uniqueID[1] == 0x30)
		{
			RandomizeItem(currentItem, GetItemByType(seed[206 - 1]));
			// flash grenade, greenhouse control room
		}
	}

	if (uniqueID[0] == 0x0A)
	{
		if (uniqueID[1] == 0x4F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[197 - 1]));
			// knife, kitchen
		}
		if (uniqueID[1] == 0xF8)
		{
			RandomizeItem(currentItem, GetItemByType(seed[27 - 1]));
			// handgun bullets, press room
		}
	}

	if (uniqueID[0] == 0x0C)
	{
		if (uniqueID[1] == 0x7A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[195 - 1]));
			// flamethrower fuel, cafeteria
		}
		if (uniqueID[1] == 0xB6)
		{
			RandomizeItem(currentItem, GetItemByType(seed[159 - 1]));
			// yellow gunpowder, lower waterway
		}
	}

	if (uniqueID[0] == 0x0D)
	{
		if (uniqueID[1] == 0x43)
		{
			RandomizeItem(currentItem, GetItemByType(seed[135 - 1]));
			// SLS rounds, office
		}
	}

	if (uniqueID[0] == 0x0E)
	{
		if (uniqueID[1] == 0x72)
		{
			RandomizeItem(currentItem, GetItemByType(seed[150 - 1]));
			// SLS rounds, upper walkway
		}
	}

	if (uniqueID[0] == 0x0F)
	{
		if (uniqueID[1] == 0x9C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[257 - 1]));
			// ACP Ammo, Stars Office, B scenario
		}
		if (uniqueID[1] == 0x6D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[232 - 1]));
			// ACP Ammo (Bottom Left), Bioreactor's Room, B scenario
		}
	}

	if (uniqueID[0] == 0x11)
	{
		if (uniqueID[1] == 0x82)
		{
			RandomizeItem(currentItem, GetItemByType(seed[38 - 1]));
			// ink ribbon x2, east office, hardcore
		}
		if (uniqueID[1] == 0x86)
		{
			RandomizeItem(currentItem, GetItemByType(seed[175 - 1]));
			// submachinegun ammo, bottom waterway, claire
		}
	}

	if (uniqueID[0] == 0x12)
	{
		RandomizeItem(currentItem, GetItemByType(seed[12 - 1]));
		// gunpowder, west office
	}

	if (uniqueID[0] == 0x13)
	{
		if (uniqueID[1] == 0x13)
		{
			RandomizeItem(currentItem, GetItemByType(seed[54 - 1]));
			// spade key, western area 3F
		}
		if (uniqueID[1] == 0x83)
		{
			RandomizeItem(currentItem, GetItemByType(seed[115 - 1]));
			// gunpowder (up ladder), machinery room
		}
	}

	if (uniqueID[0] == 0x14)
	{
		if (uniqueID[1] == 0xC0)
		{
			RandomizeItem(currentItem, GetItemByType(seed[26 - 1]));
			// Shotgun Shells (shotgun cupboard), safety deposit room
		}
		if (uniqueID[1] == 0xDD)
		{
			RandomizeItem(currentItem, GetItemByType(seed[5 - 1]));
			// Quickdraw army, guardroom B scenario Claire
		}
		if (uniqueID[1] == 0xF1)
		{
			RandomizeItem(currentItem, GetItemByType(seed[88 - 1]));
			// ink ribbon x1, boiler room, Leon Hardcore
		}
	}

	if (uniqueID[0] == 0x15)
	{
		if (uniqueID[1] == 0xE7 && *scenario == RE2RREnums::Scenario::B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[165 - 1]));
			// knight plug, b scenario
		}
		else if (uniqueID[1] == 0xE7)
		{
			// E7 is knight repickup
			// debug_continueFromBreakpoint(co_run);
		}
		if (uniqueID[1] == 0x2C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[187 - 1]));
			// red herb, main power room
		}
		if (uniqueID[1] == 0x55)
		{
			RandomizeItem(currentItem, GetItemByType(seed[217 - 1]));
			// yellow gunpowder, server room
		}
		if (uniqueID[1] == 0x94)
		{
			RandomizeItem(currentItem, GetItemByType(seed[148 - 1]));
			// handgun bullets second, sewer entrance
		}
		if (uniqueID[1] == 0xDC)
		{
			RandomizeItem(currentItem, GetItemByType(seed[186 - 1]));
			// green herb, outside garbage room
		}
	}

	if (uniqueID[0] == 0x16)
	{
		if (uniqueID[1] == 0x15)
		{
			RandomizeItem(currentItem, GetItemByType(seed[1 - 1]));
			// handgun bullets, main hall
		}
		if (uniqueID[1] == 0x1A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[37 - 1]));
			// mechanic jack handle, records room
		}
		if (uniqueID[1] == 0xD8)
		{
			RandomizeItem(currentItem, GetItemByType(seed[214 - 1]));
			// Trophy, Low Temp Testing Lab, B scenario
		}
	}

	if (uniqueID[0] == 0x19)
	{
		RandomizeItem(currentItem, GetItemByType(seed[172 - 1]));
		// green herb, bottom waterway overpass
	}

	if (uniqueID[0] == 0x1A)
	{
		if (uniqueID[1] == 0x66)
		{
			RandomizeItem(currentItem, GetItemByType(seed[129 - 1]));
			// firing range, flame rounds, claire
		}
		if (uniqueID[1] == 0xC3)
		{
			RandomizeItem(currentItem, GetItemByType(seed[147 - 1]));
			// handgun bullets first, sewer entrance
		}
	}

	if (uniqueID[0] == 0x1C)
	{
		if (uniqueID[1] == 0x9D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[235 - 1]));
			// needles, bioreactors room
		}
	}

	if (uniqueID[0] == 0x1D)
	{
		if (uniqueID[1] == 0x49)
		{
			RandomizeItem(currentItem, GetItemByType(seed[68 - 1]));
			// statue's left arm, art room
		}
		if (uniqueID[1] == 0xF1)
		{
			RandomizeItem(currentItem, GetItemByType(seed[264 - 1]));
			// white gunpowder, break room b scenario claire
		}
	}

	if (uniqueID[0] == 0x1E)
	{
		if (uniqueID[1] == 0x33)
		{
			RandomizeItem(currentItem, GetItemByType(seed[228 - 1]));
			// white gunpowder, p-4 level testing lab, claire
		}
		if (uniqueID[1] == 0x3C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[226 - 1]));
			// yellow gunpowder, biotesting lab
		}
		if (uniqueID[1] == 0x94)
		{
			RandomizeItem(currentItem, GetItemByType(seed[235 - 1]));
			// flamethrower fuel, bioreactors room
		}
		if (uniqueID[1] == 0xB5)
		{
			RandomizeItem(currentItem, GetItemByType(seed[120 - 1]));
			// square crank, jail
		}
	}

	if (uniqueID[0] == 0x1F)
	{
		if (uniqueID[1] == 0x03)
		{
			RandomizeItem(currentItem, GetItemByType(seed[25 - 1]));
			// grenade launcher, weapons locker, claire
		}
		if (uniqueID[1] == 0x4D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[247 - 1]));
			// joint plug, Escape Shaft
		}
		if (uniqueID[1] == 0xEF)
		{
			RandomizeItem(currentItem, GetItemByType(seed[93 - 1]));
			// handgun bullets, interrogation room
		}
		if (uniqueID[1] == 0xFE)
		{
			RandomizeItem(currentItem, GetItemByType(seed[125 - 1]));
			// red herb, morgue
		}
	}

	if (uniqueID[0] == 0x20)
	{
		if (uniqueID[1] == 0x46)
		{
			RandomizeItem(currentItem, GetItemByType(seed[251 - 1]));
			// flame rounds, STARS office, claire
		}
		if (uniqueID[1] == 0xA8)
		{
			RandomizeItem(currentItem, GetItemByType(seed[134 - 1]));
			// green herb, basketball court
		}
	}

	if (uniqueID[0] == 0x21)
	{
		if (uniqueID[1] == 0x17)
		{
			RandomizeItem(currentItem, GetItemByType(seed[194 - 1]));
			// ACP Ammo, Cafeteria, B Scenario
		}
		if (uniqueID[1] == 0x7A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[158 - 1]));
			// yellow gunpowder, water injection chamber
		}
	}

	if (uniqueID[0] == 0x22)
	{
		if (uniqueID[1] == 0x7F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[92 - 1]));
			// portable safe, observation room, b scenario
		}
	}

	if (uniqueID[0] == 0x23)
	{
		RandomizeItem(currentItem, GetItemByType(seed[119 - 1]));
		// handgun bullets, jail entrance
	}

	if (uniqueID[0] == 0x24)
	{
		if (uniqueID[1] == 0x04)
		{
			RandomizeItem(currentItem, GetItemByType(seed[98 - 1]));
			// flash grenade, STARS office
		}
		if (uniqueID[1] == 0x9C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[72 - 1]));
			// bolt cutters, outside fire escape, b scenario
		}
		if (uniqueID[1] == 0x97)
		{
			RandomizeItem(currentItem, GetItemByType(seed[140 - 1]));
			// relief, private collection room
		}
		if (uniqueID[1] == 0xF0)
		{
			RandomizeItem(currentItem, GetItemByType(seed[100 - 1]));
			// white gunpowder, STARS office, claire
		}
	}

	if (uniqueID[0] == 0x25)
	{
		if (uniqueID[1] == 0x36)
		{
			RandomizeItem(currentItem, GetItemByType(seed[174 - 1]));
			// green herb, bottom waterway
		}
		if (uniqueID[1] == 0xF0)
		{
			RandomizeItem(currentItem, GetItemByType(seed[85 - 1]));
			// red herb, roof area
		}
	}

	if (uniqueID[0] == 0x26)
	{
		if (uniqueID[1] == 0x27)
		{
			RandomizeItem(currentItem, GetItemByType(seed[155 - 1]));
			// sls ammo, RPD access room, claire
		}
	}

	if (uniqueID[0] == 0x27)
	{
		if (uniqueID[1] == 0x8C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[47 - 1]));
			// ACP ammo, western area 2F, b scenario
		}
	}

	if (uniqueID[0] == 0x29)
	{
		if (uniqueID[1] == 0x0C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[251 - 1]));
			// shotgun shells, stars office
		}
		if (uniqueID[1] == 0x89)
		{
			RandomizeItem(currentItem, GetItemByType(seed[150 - 1]));
			// shotgun shells, upper walkway
		}
		if (uniqueID[1] == 0x94)
		{
			RandomizeItem(currentItem, GetItemByType(seed[50 - 1]));
			// flame rounds, valve room, not in locker, claire
		}
	}

	if (uniqueID[0] == 0x2A)
	{
		RandomizeItem(currentItem, GetItemByType(seed[81 - 1]));
		// flash grenade, east area 3F
	}

	if (uniqueID[0] == 0x2B)
	{
		RandomizeItem(currentItem, GetItemByType(seed[215 - 1]));
		// green herb, Lounge
	}

	if (uniqueID[0] == 0x2C)
	{
		RandomizeItem(currentItem, GetItemByType(seed[42 - 1]));
		// valve, east office
	}

	if (uniqueID[0] == 0x2D)
	{
		RandomizeItem(currentItem, GetItemByType(seed[97 - 1]));
		// red herb, STARS office
	}

	if (uniqueID[0] == 0x2E)
	{
		if (uniqueID[1] == 0x00)
		{
			RandomizeItem(currentItem, GetItemByType(seed[92 - 1]));
			// portable safe claire b scenario interrogation room
		}
	}

	if (uniqueID[0] == 0x2F)
	{
		if (uniqueID[1] == 0x26)
		{
			RandomizeItem(currentItem, GetItemByType(seed[24 - 1]));
			// shotgun shells (locker), safety deposit room
		}
		if (uniqueID[1] == 0x30)
		{
			RandomizeItem(currentItem, GetItemByType(seed[233 - 1]));
			// mag ammo, bioreactors room
		}
	}

	if (uniqueID[0] == 0x30)
	{
		if (uniqueID[1] == 0x1F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[55 - 1]));
			// gunpowder, west storage room
		}
		if (uniqueID[1] == 0xC9)
		{
			RandomizeItem(currentItem, GetItemByType(seed[21 - 1]));
			// combat knife, safety deposit room
		}
		if (uniqueID[1] == 0xFE)
		{
			RandomizeItem(currentItem, GetItemByType(seed[230 - 1]));
			// handgun bullets (top left), bioreactor's room, B scenario
		}
	}

	if (uniqueID[0] == 0x31)
	{
		RandomizeItem(currentItem, GetItemByType(seed[171 - 1]));
		// sewer key, bottom way overpass
	}

	if (uniqueID[0] == 0x32)
	{
		if (uniqueID[1] == 0x15)
		{
			RandomizeItem(currentItem, GetItemByType(seed[6 - 1]));
			// ACP ammo, reception, B scenario
		}
	}

	if (uniqueID[0] == 0x33)
	{
		if (uniqueID[1] == 0xBF)
		{
			RandomizeItem(currentItem, GetItemByType(seed[188 - 1]));
			// submachinegun ammo, g2 fight, claire
		}
	}

	if (uniqueID[0] == 0x34)
	{
		if (uniqueID[1] == 0xDC)
		{
			RandomizeItem(currentItem, GetItemByType(seed[246 - 1]));
			// submachinegun ammo, orphanage, claire
		}
		if (uniqueID[1] == 0xFD)
		{
			RandomizeItem(currentItem, GetItemByType(seed[18 - 1]));
			// red herb, dark room
		}
	}

	if (uniqueID[0] == 0x36)
	{
		RandomizeItem(currentItem, GetItemByType(seed[245 - 1]));
		// red herb, escape shaft
	}

	if (uniqueID[0] == 0x38)
	{
		if (uniqueID[1] == 0x15)
		{
			RandomizeItem(currentItem, GetItemByType(seed[48 - 1]));
			// red herb, western area 2F
		}
		if (uniqueID[1] == 0x92)
		{
			RandomizeItem(currentItem, GetItemByType(seed[86 - 1]));
			// green herb (left), roof area
		}
		if (uniqueID[1] == 0xE0)
		{
			RandomizeItem(currentItem, GetItemByType(seed[161 - 1]));
			// flame rounds, control room, claire
		}
	}

	if (uniqueID[0] == 0x3A)
	{
		if (uniqueID[1] == 0x64)
		{
			RandomizeItem(currentItem, GetItemByType(seed[161 - 1]));
			// shotgun shells, control room
		}
		if (uniqueID[1] == 0xA4)
		{
			RandomizeItem(currentItem, GetItemByType(seed[82 - 1]));
			// wooden boards, east area 3F
		}
	}

	if (uniqueID[0] == 0x3C)
	{
		if (uniqueID[1] == 0x22)
		{
			RandomizeItem(currentItem, GetItemByType(seed[179 - 1]));
			// King Plug, supplies storage room
		}
		if (uniqueID[1] == 0x3C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[229 - 1]));
			// Red Herb, P-4 Level Testing Lab
		}
		if (uniqueID[1] == 0x84)
		{
			RandomizeItem(currentItem, GetItemByType(seed[17 - 1]));
			// Handgun Bullets, dark room
		}
		if (uniqueID[1] == 0x8D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[90 - 1]));
			// white gunpowder, outside observation room, claire
		}
		if (uniqueID[1] == 0x98)
		{
			RandomizeItem(currentItem, GetItemByType(seed[61 - 1]));
			// Knife, Library
		}
	}

	if (uniqueID[0] == 0x3D)
	{
		if (uniqueID[1] == 0x1B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[208 - 1]));
			// blue herb, greenhouse
		}
		if (uniqueID[1] == 0x5D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[31 - 1]));
			// detonator (no battery), detonator room
		}
	}

	if (uniqueID[0] == 0x40)
	{
		if (uniqueID[1] == 0x8C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[77 - 1]));
			// blue herb, east storage room
		}
		if (uniqueID[1] == 0xB5)
		{
			RandomizeItem(currentItem, GetItemByType(seed[129 - 1]));
			// shotgun shells, firing range
		}
		if (uniqueID[1] == 0xF7)
		{
			RandomizeItem(currentItem, GetItemByType(seed[233 - 1]));
			// sls rounds, bioreactor's room, claire
		}
	}

	if (uniqueID[0] == 0x43)
	{
		if (uniqueID[1] == 0x60)
		{
			RandomizeItem(currentItem, GetItemByType(seed[126 - 1]));
			// flash grenade, morgue
		}
		if (uniqueID[1] == 0x6F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[180 - 1]));
			// spark shot, claire
		}
		if (uniqueID[1] == 0x6B)
		{
			// repickup of stars badge in the computer is here, 43 6B
			// debug_continueFromBreakpoint(co_run);
		}
		if (uniqueID[1] == 0x82)
		{
			RandomizeItem(currentItem, GetItemByType(seed[185 - 1]));
			// blue herb, outside garbage room
		}
		if (uniqueID[1] == 0x85)
		{
			RandomizeItem(currentItem, GetItemByType(seed[123 - 1]));
			// blue herb, outside kennel
		}
	}

	if (uniqueID[0] == 0x44)
	{
		if (uniqueID[1] == 0x4E)
		{
			RandomizeItem(currentItem, GetItemByType(seed[106 - 1]));
			// Hand Grenade, underground stairs
		}
		if (uniqueID[1] == 0x9D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[76 - 1]));
			// boxed electronic part, Clock Tower
		}
	}

	if (uniqueID[0] == 0x45)
	{
		RandomizeItem(currentItem, GetItemByType(seed[63 - 1]));
		// gunpowder, lounge
	}

	if (uniqueID[0] == 0x46)
	{
		RandomizeItem(currentItem, GetItemByType(seed[165 - 1]));
		// Knight piece, monitor room
	}

	if (uniqueID[0] == 0x47)
	{
		if (uniqueID[1] == 0xB4)
		{
			RandomizeItem(currentItem, GetItemByType(seed[192 - 1]));
			// flame rounds, security room, claire
		}
		if (uniqueID[1] == 0xF4)
		{
			RandomizeItem(currentItem, GetItemByType(seed[144 - 1]));
			// handgun bullets, gun shop
		}
	}

	if (uniqueID[0] == 0x48)
	{
		if (uniqueID[1] == 0x20)
		{
			RandomizeItem(currentItem, GetItemByType(seed[108 - 1]));
			// Handgun Bullets (Top Left), Machinery Room
		}
		if (uniqueID[1] == 0x50)
		{
			RandomizeItem(currentItem, GetItemByType(seed[222 - 1]));
			// Signal Modulator, Modulator Room
		}
	}

	if (uniqueID[0] == 0x49)
	{
		if (uniqueID[1] == 0xD6)
		{
			RandomizeItem(currentItem, GetItemByType(seed[162 - 1]));
			// submachinegun ammo, control room, claire
		}
	}

	if (uniqueID[0] == 0x4A)
	{
		if (uniqueID[1] == 0xCB)
		{
			RandomizeItem(currentItem, GetItemByType(seed[120 - 1]));
			// turntable minigun, claire
		}
	}

	if (uniqueID[0] == 0x4C)
	{
		if (uniqueID[1] == 0x13)
		{
			RandomizeItem(currentItem, GetItemByType(seed[28 - 1]));
			// handgun bullets, east closet ambush
		}
		if (uniqueID[1] == 0x33)
		{
			RandomizeItem(currentItem, GetItemByType(seed[241 - 1]));
			// combat knife, monitor room
		}
	}

	if (uniqueID[0] == 0x4E)
	{
		if (uniqueID[1] == 0x10)
		{
			RandomizeItem(currentItem, GetItemByType(seed[191 - 1]));
			// knife, g2 fight room
		}
		if (uniqueID[1] == 0x28)
		{
			RandomizeItem(currentItem, GetItemByType(seed[111 - 1]));
			// red herb, machinery room
		}
		if (uniqueID[1] == 0x2B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[136 - 1]));
			// knife, heart room east storage, claire
		}
		if (uniqueID[1] == 0x75)
		{
			RandomizeItem(currentItem, GetItemByType(seed[22 - 1]));
			// gunpowder, safety deposit room
		}
		if (uniqueID[1] == 0x79)
		{
			RandomizeItem(currentItem, GetItemByType(seed[200 - 1]));
			// upgrade chip (general staff), nap room
		}
	}

	if (uniqueID[0] == 0x51)
	{
		if (uniqueID[1] == 0xB4)
		{
			RandomizeItem(currentItem, GetItemByType(seed[223 - 1]));
			// lab digital video cassette, biotesting lab
		}
		if (uniqueID[1] == 0xF5)
		{
			RandomizeItem(currentItem, GetItemByType(seed[134 - 1]));
			// gunpowder, generator room
		}
	}

	if (uniqueID[0] == 0x52)
	{
		RandomizeItem(currentItem, GetItemByType(seed[80 - 1]));
		// handgun bullets, east area 3F
	}

	if (uniqueID[0] == 0x54)
	{
		RandomizeItem(currentItem, GetItemByType(seed[20 - 1]));
		// handgun bullets, safety deposit room
	}

	if (uniqueID[0] == 0x57)
	{
		if (uniqueID[1] == 0x6C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[259 - 1]));
			// blue herb, outside fire escape, b scenario
		}
	}

	if (uniqueID[0] == 0x58)
	{
		if (uniqueID[1] == 0x25)
		{
			// large gear after clock tower is here, 58 25
			// debug_continueFromBreakpoint(co_run);
		}
		if (uniqueID[1] == 0x40)
		{
			RandomizeItem(currentItem, GetItemByType(seed[170 - 1]));
			// shotgun stock (w-870)
		}
	}

	if (uniqueID[0] == 0x59)
	{
		RandomizeItem(currentItem, GetItemByType(seed[35 - 1]));
		// hand grenade, records room
	}

	if (uniqueID[0] == 0x5A)
	{
		RandomizeItem(currentItem, GetItemByType(seed[153 - 1]));
		// gunpowder, worker's break room
	}

	if (uniqueID[0] == 0x5B)
	{
		if (uniqueID[1] == 0xB4)
		{
			RandomizeItem(currentItem, GetItemByType(seed[159 - 1]));
			// white gunpowder, lower waterway
		}
		if (uniqueID[1] == 0xE1)
		{
			RandomizeItem(currentItem, GetItemByType(seed[204 - 1]));
			// white gunpowder, first plant room, claire
		}
	}

	if (uniqueID[0] == 0x5C)
	{
		RandomizeItem(currentItem, GetItemByType(seed[160 - 1]));
		// blue herb, lower waterway
	}

	if (uniqueID[0] == 0x5D)
	{
		if (uniqueID[1] == 0x36)
		{
			RandomizeItem(currentItem, GetItemByType(seed[164 - 1]));
			// bishop piece, monitor room
		}
		if (uniqueID[1] == 0xB5)
		{
			RandomizeItem(currentItem, GetItemByType(seed[14 - 1]));
			// hip pouch, west office
		}
		if (uniqueID[1] == 0xFD)
		{
			RandomizeItem(currentItem, GetItemByType(seed[99 - 1]));
			// fas, stars office
		}
	}

	if (uniqueID[0] == 0x5E)
	{
		if (uniqueID[1] == 0x3F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[1 - 1]));
			// acp ammo, main hall B scenario
		}
		if (uniqueID[1] == 0x8B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[113 - 1]));
			// green herb(bottom right), machinery room
		}
		if (uniqueID[1] == 0xA6)
		{
			RandomizeItem(currentItem, GetItemByType(seed[254 - 1]));
			// ink ribbon x2, interrogation room hardcore
		}
	}

	if (uniqueID[0] == 0x5F)
	{
		if (uniqueID[1] == 0xE5)
		{
			if (*character == RE2RREnums::Character::Claire)
			{
				RandomizeItem(currentItem, GetItemByType(seed[262 - 1]));
				// knife, outside break room
			}
			else
			{
				RandomizeItem(currentItem, GetItemByType(seed[136 - 1]));
				// knife, outside break room
			}
		}
	}

	if (uniqueID[0] == 0x60)
	{
		if (uniqueID[1] == 0xAB)
		{
			RandomizeItem(currentItem, GetItemByType(seed[231 - 1]));
			// fas, bioreactor's room
		}
		if (uniqueID[1] == 0xD4)
		{
			RandomizeItem(currentItem, GetItemByType(seed[58 - 1]));
			// hip pouch, main hall, b scenario
		}
	}

	if (uniqueID[0] == 0x61)
	{
		if (uniqueID[1] == 0x7E)
		{
			RandomizeItem(currentItem, GetItemByType(seed[49 - 1]));
			// flame rounds in locker in valve room claire
		}
		if (uniqueID[1] == 0xD2)
		{
			RandomizeItem(currentItem, GetItemByType(seed[92 - 1]));
			// bejeweled box, interrogation room, claire
		}
	}

	if (uniqueID[0] == 0x62)
	{
		if (uniqueID[1] == 0x05)
		{
			RandomizeItem(currentItem, GetItemByType(seed[247 - 1]));
			// turntable joint plug, claire
		}
		if (uniqueID[1] == 0x25)
		{
			RandomizeItem(currentItem, GetItemByType(seed[109 - 1]));
			// hand grenade, machinery room
		}
		if (uniqueID[1] == 0xD1)
		{
			RandomizeItem(currentItem, GetItemByType(seed[7 - 1]));
			// green herb, reception
		}
	}

	if (uniqueID[0] == 0x65)
	{
		if (uniqueID[1] == 0x04)
		{
			RandomizeItem(currentItem, GetItemByType(seed[202 - 1]));
			// green herb, lobby
		}
		if (uniqueID[1] == 0xC3)
		{
			RandomizeItem(currentItem, GetItemByType(seed[252 - 1]));
			// Ink Ribbon x1, Lab Reception, Hardcore
		}
	}

	if (uniqueID[0] == 0x66)
	{
		if (uniqueID[1] == 0x5A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[226 - 1]));
			// white gunpowder, biotesting lab, claire
		}
		if (uniqueID[1] == 0xA6)
		{
			RandomizeItem(currentItem, GetItemByType(seed[89 - 1]));
			// shoulder stock (GM 79), elevator controls room, claire
		}
	}

	if (uniqueID[0] == 0x68)
	{
		if (uniqueID[1] == 0xA4)
		{
			// A4 is ada ID wristband
			// debug_continueFromBreakpoint(co_run);
		}
		if (uniqueID[1] == 0xCF)
		{
			RandomizeItem(currentItem, GetItemByType(seed[245 - 1]));
			// turntable red herb, claire
		}
		if (uniqueID[1] == 0xEC)
		{
			RandomizeItem(currentItem, GetItemByType(seed[204 - 1]));
			// yellow gunpowder, first plant room
		}
		if (uniqueID[1] == 0xFD)
		{
			RandomizeItem(currentItem, GetItemByType(seed[8 - 1]));
			// handgun bullets, operations room
		}
	}

	if (uniqueID[0] == 0x6B)
	{
		if (uniqueID[1] == 0x01)
		{
			RandomizeItem(currentItem, GetItemByType(seed[149 - 1]));
			// ACP Ammo, Upper Walkway, B scenario
		}
		if (uniqueID[1] == 0x5B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[199 - 1]));
			// regulator (flamethrower), nap room
		}
	}

	if (uniqueID[0] == 0x6C)
	{
		RandomizeItem(currentItem, GetItemByType(seed[29 - 1]));
		// wooden boards, east closet ambush
	}

	if (uniqueID[0] == 0x6D)
	{
		if (uniqueID[1] == 0xFE)
		{
			RandomizeItem(currentItem, GetItemByType(seed[258 - 1]));
			// Red Herb, Outside Fire Escape, B Scenario
		}
	}

	if (uniqueID[0] == 0x6E)
	{
		if (uniqueID[1] == 0x99)
		{
			RandomizeItem(currentItem, GetItemByType(seed[105 - 1]));
			// flame rounds, secret room, claire
		}
		if (uniqueID[1] == 0x2D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[137 - 1]));
			// blue herb, outside bus, claire
		}
		if (uniqueID[1] == 0xDA)
		{
			RandomizeItem(currentItem, GetItemByType(seed[243 - 1]));
			// green herb, pump room
		}
	}

	if (uniqueID[0] == 0x6F)
	{
		if (uniqueID[1] == 0xB8)
		{
			RandomizeItem(currentItem, GetItemByType(seed[114 - 1]));
			// ACP ammo (bottom right), machinery room, b scenario
		}
	}

	if (uniqueID[0] == 0x70)
	{
		if (uniqueID[1] == 0x53)
		{
			RandomizeItem(currentItem, GetItemByType(seed[23 - 1]));
			// hip pouch, safety deposit room
		}
		if (uniqueID[1] == 0x9F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[239 - 1]));
			// ACP ammo, bottom right, right, bioreactor's room, b scenario
		}
	}

	if (uniqueID[0] == 0x71)
	{
		RandomizeItem(currentItem, GetItemByType(seed[205 - 1]));
		// dispersal cartridge (empty), greenhouse control room
	}

	if (uniqueID[0] == 0x72)
	{
		if (uniqueID[1] == 0xC6)
		{
			RandomizeItem(currentItem, GetItemByType(seed[192 - 1]));
			// shotgun that spawns at lab if you don't pick it up
		}
		if (uniqueID[1] == 0x5E)
		{
			RandomizeItem(currentItem, GetItemByType(seed[131 - 1]));
			// red herb, firing range lockers
		}
		if (uniqueID[1] == 0x93)
		{
			RandomizeItem(currentItem, GetItemByType(seed[53 - 1]));
			// mag ammo, western area 3F
		}
	}

	if (uniqueID[0] == 0x73)
	{
		if (uniqueID[1] == 0x30)
		{
			RandomizeItem(currentItem, GetItemByType(seed[211 - 1]));
			// hand grenade, drug testing lab
		}
		if (uniqueID[1] == 0x44)
		{
			RandomizeItem(currentItem, GetItemByType(seed[23 - 1]));
			// hip pouch, safety deposit room
		}
	}

	if (uniqueID[0] == 0x74)
	{
		if (uniqueID[1] == 0x24)
		{
			RandomizeItem(currentItem, GetItemByType(seed[234 - 1]));
			// flash grenade (bottom left), bioreactor's room
		}
		if (uniqueID[1] == 0x40)
		{
			RandomizeItem(currentItem, GetItemByType(seed[104 - 1]));
			// ink ribbon, secret room hardcore
		}
	}

	if (uniqueID[0] == 0x75)
	{
		RandomizeItem(currentItem, GetItemByType(seed[149 - 1]));
		// handgun bullets, upper walkway
	}

	if (uniqueID[0] == 0x76)
	{
		RandomizeItem(currentItem, GetItemByType(seed[118 - 1]));
		// gun stock (matilda), parking garage
	}

	if (uniqueID[0] == 0x78)
	{
		RandomizeItem(currentItem, GetItemByType(seed[214 - 1]));
		// trophy, lounge
	}

	if (uniqueID[0] == 0x79)
	{
		if (uniqueID[1] == 0x2C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[116 - 1]));
			// green herb (up ladder), machinery room
		}
		if (uniqueID[1] == 0xC1)
		{
			RandomizeItem(currentItem, GetItemByType(seed[19 - 1]));
			// film commemorative, claire
		}
		if (uniqueID[1] == 0x77)
		{
			RandomizeItem(currentItem, GetItemByType(seed[246 - 1]));
			// handgun bullets, escape shaft
		}
		if (uniqueID[1] == 0xAD)
		{
			RandomizeItem(currentItem, GetItemByType(seed[188 - 1]));
			// mag ammo, G2 fight room
		}
		if (uniqueID[1] == 0xD3)
		{
			RandomizeItem(currentItem, GetItemByType(seed[182 - 1]));
			// film - hiding place, workroom
		}
	}

	if (uniqueID[0] == 0x7A)
	{
		if (uniqueID[1] == 0x02)
		{
			RandomizeItem(currentItem, GetItemByType(seed[225 - 1]));
			// blue herb, biotesting lab
		}
		if (uniqueID[1] == 0x58)
		{
			RandomizeItem(currentItem, GetItemByType(seed[87 - 1]));
			// green herb(right), roof area
		}
	}

	if (uniqueID[0] == 0x7B)
	{
		if (uniqueID[1] == 0x00)
		{
			RandomizeItem(currentItem, GetItemByType(seed[53 - 1]));
			// submachinegun ammo, western area 3F
		}
		if (uniqueID[1] == 0x8E)
		{
			RandomizeItem(currentItem, GetItemByType(seed[88 - 1]));
			// blue herb, elevator controls room, claire
		}
	}

	if (uniqueID[0] == 0x7C)
	{
		if (uniqueID[1] == 0x24)
		{
			RandomizeItem(currentItem, GetItemByType(seed[41 - 1]));
			// gunpowder, east office
		}
		if (uniqueID[1] == 0xB9)
		{
			RandomizeItem(currentItem, GetItemByType(seed[141 - 1]));
			// white gunpowder, private collection room, claire
		}
	}

	if (uniqueID[0] == 0x7D)
	{
		if (uniqueID[1] == 0x09)
		{
			RandomizeItem(currentItem, GetItemByType(seed[143 - 1]));
			// hand grenade, gun shop
		}
		if (uniqueID[1] == 0x9C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[93 - 1]));
			// ACP ammo, interrogation room, b scenario
		}
		if (uniqueID[1] == 0xB3)
		{
			RandomizeItem(currentItem, GetItemByType(seed[32 - 1]));
			// green herb, detonator room
		}
	}

	if (uniqueID[0] == 0x7F)
	{
		if (uniqueID[1] == 0x0B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[180 - 1]));
			// flamethrower, supplies storage room
		}
		if (uniqueID[1] == 0x8F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[45 - 1]));
			// green herb, waiting room
		}
	}

	if (uniqueID[0] == 0x80)
	{
		if (uniqueID[1] == 0x7F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[105 - 1]));
			// shotgun shells, secret room
		}
		if (uniqueID[1] == 0xCC)
		{
			RandomizeItem(currentItem, GetItemByType(seed[13 - 1]));
			// handgun bullets, west office
		}
		if (uniqueID[1] == 0xF4)
		{
			RandomizeItem(currentItem, GetItemByType(seed[43 - 1]));
			// white gunpowder, east office, claire
		}
	}

	if (uniqueID[0] == 0x81)
	{
		RandomizeItem(currentItem, GetItemByType(seed[232 - 1]));
		// handgun bullets (bottom left), bioreactors room
	}

	if (uniqueID[0] == 0x83)
	{
		RandomizeItem(currentItem, GetItemByType(seed[114 - 1]));
		// handgun bullets (bottom right), machinery room
	}

	if (uniqueID[0] == 0x84)
	{
		RandomizeItem(currentItem, GetItemByType(seed[168 - 1]));
		// t-bar valve, treatment pool room
	}

	if (uniqueID[0] == 0x85)
	{
		// 1C is ada item
		if (uniqueID[1] == 0x1C)
		{
			// flamethrower every time
			RandomizeItem(currentItem, GetItemByType(268));
		}
		if (uniqueID[1] == 0xF8)
		{
			RandomizeItem(currentItem, GetItemByType(seed[177 - 1]));
			// blue herb, supplies storage room
		}
	}

	if (uniqueID[0] == 0x86)
	{
		RandomizeItem(currentItem, GetItemByType(seed[34 - 1]));
		// wooden boards, detonator room
	}

	if (uniqueID[0] == 0x87)
	{
		if (uniqueID[1] == 0x90)
		{
			RandomizeItem(currentItem, GetItemByType(seed[30 - 1]));
			// fas, bathroom
		}
		if (uniqueID[1] == 0xB9)
		{
			RandomizeItem(currentItem, GetItemByType(seed[121 - 1]));
			// parking garage key card, jail
		}
	}

	if (uniqueID[0] == 0x88)
	{
		if (uniqueID[1] == 0x5A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[244 - 1]));
			// handgun bullets, pump room
		}
		if (uniqueID[1] == 0x82)
		{
			RandomizeItem(currentItem, GetItemByType(seed[44 - 1]));
			// fuse (main hall), east office
		}
		if (uniqueID[1] == 0xC9)
		{
			RandomizeItem(currentItem, GetItemByType(seed[213 - 1]));
			// flame rounds, lounge, claire
		}
	}

	if (uniqueID[0] == 0x8A)
	{
		if (uniqueID[1] == 0xEF)
		{
			RandomizeItem(currentItem, GetItemByType(seed[24 - 1]));
			// flame rounds in locker 208
		}
	}

	if (uniqueID[0] == 0x8B)
	{
		if (uniqueID[1] == 0xAF)
		{
			RandomizeItem(currentItem, GetItemByType(seed[237 - 1]));
			// flash grenade (top right), bioreactors room
		}
	}

	if (uniqueID[0] == 0x8C)
	{
		RandomizeItem(currentItem, GetItemByType(seed[66 - 1]));
		// green herb, chopper crash area
	}

	if (uniqueID[0] == 0x8D)
	{
		if (uniqueID[1] == 0x74)
		{
			RandomizeItem(currentItem, GetItemByType(seed[249 - 1]));
			// wooden box, stars office, claire
		}
		if (uniqueID[1] == 0x8B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[60 - 1]));
			// handgun bullets, library
		}
	}

	if (uniqueID[0] == 0x8E)
	{
		if (uniqueID[1] == 0x1C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[216 - 1]));
			// flame rounds, server room, claire
		}
		if (uniqueID[1] == 0xF6)
		{
			RandomizeItem(currentItem, GetItemByType(seed[148 - 1]));
			// ACP Ammo (second), Sewer Entrance, Leon B Scenario
		}
	}

	if (uniqueID[0] == 0x8F)
	{
		if (uniqueID[1] == 0x35)
		{
			if (*character == RE2RREnums::Character::Claire)
			{
				RandomizeItem(currentItem, GetItemByType(seed[263 - 1]));
				// blue herb, break room claire b scenario
			}
			else
			{
				RandomizeItem(currentItem, GetItemByType(seed[137 - 1]));
				// blue herb, break room
			}
		}
		if (uniqueID[1] == 0xB4)
		{
			RandomizeItem(currentItem, GetItemByType(seed[57 - 1]));
			// handgun bullets, west storage room
		}
		if (uniqueID[1] == 0xED)
		{
			RandomizeItem(currentItem, GetItemByType(seed[130 - 1]));
			// film 3F locker, firing range lockers
		}
		if (uniqueID[1] == 0xFF)
		{
			RandomizeItem(currentItem, GetItemByType(seed[107 - 1]));
			// suppressor, underground stairs, claire
		}
	}

	if (uniqueID[0] == 0x90)
	{
		if (uniqueID[1] == 0x81)
		{
			RandomizeItem(currentItem, GetItemByType(seed[162 - 1]));
			// mag ammo, control room
		}
		if (uniqueID[1] == 0x9B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[176 - 1]));
			// red herb, supplies storage room
		}
	}

	if (uniqueID[0] == 0x91)
	{
		// 52 is ada item
		if (uniqueID[1] == 0x52)
		{
			// yellow gunpowder every time
			RandomizeItem(currentItem, GetItemByType(302));
		}
		if (uniqueID[1] == 0x87)
		{
			RandomizeItem(currentItem, GetItemByType(seed[154 - 1]));
			// handgun bullets
		}
		if (uniqueID[1] == 0xC1)
		{
			RandomizeItem(currentItem, GetItemByType(seed[57 - 1]));
			// acp ammo, west storage room, b scenario
		}
		if (uniqueID[1] == 0xF6)
		{
			RandomizeItem(currentItem, GetItemByType(seed[75 - 1]));
			// small gear
		}
	}

	if (uniqueID[0] == 0x93)
	{
		if (uniqueID[1] == 0x58)
		{
			RandomizeItem(currentItem, GetItemByType(seed[21 - 1]));
			// combat knife, locker 103, claire
		}
	}

	if (uniqueID[0] == 0x94)
	{
		if (uniqueID[1] == 0x0C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[183 - 1]));
			// handgun bullets, workroom
		}
		if (uniqueID[1] == 0x67)
		{
			RandomizeItem(currentItem, GetItemByType(seed[63 - 1]));
			// lion statue film, lounge, b scenario
		}
		if (uniqueID[1] == 0x85)
		{
			RandomizeItem(currentItem, GetItemByType(seed[60 - 1]));
			// ACP ammo, library, b scenario
		}
	}

	if (uniqueID[0] == 0x95)
	{
		if (uniqueID[1] == 0x9F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[5 - 1]));
			// M19, guard room, b scenario
		}
	}

	if (uniqueID[0] == 0x96)
	{
		if (uniqueID[1] == 0x2A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[89 - 1]));
			// club key, boiler room
		}
		if (uniqueID[1] == 0x61)
		{
			RandomizeItem(currentItem, GetItemByType(seed[193 - 1]));
			// hand grenade, cafeteria
		}
	}

	if (uniqueID[0] == 0x97)
	{
		if (uniqueID[1] == 0xDD)
		{
			// DD is king in sewer after final placement
			// debug_continueFromBreakpoint(co_run);
		}
		if (uniqueID[1] == 0xDE)
		{
			RandomizeItem(currentItem, GetItemByType(seed[103 - 1]));
			// gunpowder, linen room
		}
	}

	if (uniqueID[0] == 0x98)
	{
		if (uniqueID[1] == 0x69)
		{
			// nice
			RandomizeItem(currentItem, GetItemByType(seed[20 - 1]));
			// ACP Ammo, Safety deposit room, B scenario
		}
		if (uniqueID[1] == 0x8E)
		{
			RandomizeItem(currentItem, GetItemByType(seed[239 - 1]));
			// handgun bullets (bottom right, right), bioreactors room
		}
	}

	if (uniqueID[0] == 0x99)
	{
		if (uniqueID[1] == 0x5A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[70 - 1]));
			// ACP ammo, fire escape, b scenario
		}
		if (uniqueID[1] == 0x5F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[210 - 1]));
			// large gunpowder, drug testing lab
		}
	}

	if (uniqueID[0] == 0x9A)
	{
		if (uniqueID[1] == 0x15)
		{
			RandomizeItem(currentItem, GetItemByType(seed[69 - 1]));
			// scepter, art room
		}
		if (uniqueID[1] == 0x4D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[15 - 1]));
			// speed loader for claire
		}
		if (uniqueID[1] == 0x7A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[65 - 1]));
			// wooden boards, chopper crash area
		}
		if (uniqueID[1] == 0x86)
		{
			RandomizeItem(currentItem, GetItemByType(seed[198 - 1]));
			// flame rounds, nap room, claire
		}
		if (uniqueID[1] == 0x93)
		{
			RandomizeItem(currentItem, GetItemByType(seed[91 - 1]));
			// gunpowder, observation room
		}
	}

	if (uniqueID[0] == 0x9B)
	{
		if (uniqueID[1] == 0x09)
		{
			RandomizeItem(currentItem, GetItemByType(seed[67 - 1]));
			// weapons locker key, art room
		}
		if (uniqueID[1] == 0x14)
		{
			RandomizeItem(currentItem, GetItemByType(seed[169 - 1]));
			// blue herb, treatment pool room
		}
		if (uniqueID[1] == 0x61)
		{
			RandomizeItem(currentItem, GetItemByType(seed[110 - 1]));
			// green herb (top left), machinery room
		}
	}

	if (uniqueID[0] == 0x9C)
	{
		if (uniqueID[1] == 0x13)
		{
			RandomizeItem(currentItem, GetItemByType(seed[94 - 1]));
			// gunpowder, outside stars office
		}
		if (uniqueID[1] == 0x24)
		{
			RandomizeItem(currentItem, GetItemByType(seed[209 - 1]));
			// upgrade chip (senior staff), greenhouse
		}
		if (uniqueID[1] == 0x95)
		{
			RandomizeItem(currentItem, GetItemByType(seed[145 - 1]));
			// long barrel (w-870), gun shop
		}
		if (uniqueID[1] == 0xA6)
		{
			RandomizeItem(currentItem, GetItemByType(seed[195 - 1]));
			// needle cartridges, cafeteria, claire
		}
	}

	if (uniqueID[0] == 0x9D)
	{
		if (uniqueID[1] == 0x65)
		{
			RandomizeItem(currentItem, GetItemByType(seed[40 - 1]));
			// east office, acp ammo, b scenario
		}
	}

	if (uniqueID[0] == 0x9E)
	{
		if (uniqueID[1] == 0x31)
		{
			RandomizeItem(currentItem, GetItemByType(seed[118 - 1]));
			// JMB Hp3 car boot, claire
		}
	}

	if (uniqueID[0] == 0x9F)
	{
		if (uniqueID[1] == 0x85)
		{
			RandomizeItem(currentItem, GetItemByType(seed[144 - 1]));
			// ACP Ammo, Gun Shop, Leon B scenario
		}
		if (uniqueID[1] == 0xC7)
		{
			RandomizeItem(currentItem, GetItemByType(seed[28 - 1]));
			// ACP Ammo, east closet ambush b scenario
		}
	}

	if (uniqueID[0] == 0xA0)
	{
		if (uniqueID[1] == 0x0F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[224 - 1]));
			// hand grenade, biotesting lab
		}
	}

	if (uniqueID[0] == 0xA1)
	{
		if (uniqueID[1] == 0x17)
		{
			RandomizeItem(currentItem, GetItemByType(seed[107 - 1]));
			// long barrel (lightning hawk), underground stairs
		}
		if (uniqueID[1] == 0x8E)
		{
			RandomizeItem(currentItem, GetItemByType(seed[4 - 1]));
			// ACP ammo upstairs main hall b scenario
		}
	}

	if (uniqueID[0] == 0xA3)
	{
		RandomizeItem(currentItem, GetItemByType(seed[104 - 1]));
		// gunpowder, secret room
	}

	if (uniqueID[0] == 0xA4)
	{
		RandomizeItem(currentItem, GetItemByType(seed[194 - 1]));
		// handgun bullets, cafeteria
	}

	if (uniqueID[0] == 0xA5)
	{
		if (uniqueID[1] == 0x8D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[58 - 1]));
			// hip pouch, west storage room
		}
		if (uniqueID[1] == 0xD3)
		{
			// repickup of stars badge in the basement is here, A5 D3
			// debug_continueFromBreakpoint(co_run);
		}
	}

	if (uniqueID[0] == 0xA6)
	{
		if (uniqueID[1] == 0x22)
		{
			// keys in garage
			// debug_continueFromBreakpoint(co_run);
		}
	}

	if (uniqueID[0] == 0xA7)
	{
		if (uniqueID[1] == 0x8C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[52 - 1]));
			// ACP ammo, western area 3F, b scenario
		}
	}

	if (uniqueID[0] == 0xA8)
	{
		RandomizeItem(currentItem, GetItemByType(seed[151 - 1]));
		// uss digital video cassette, rook bridge area
	}

	if (uniqueID[0] == 0xA9)
	{
		RandomizeItem(currentItem, GetItemByType(seed[135 - 1]));
		// shotgun shells, outside break room
	}

	if (uniqueID[0] == 0xAA)
	{
		if (uniqueID[1] == 0x5B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[78 - 1]));
			// large gear, east storage room
		}
		if (uniqueID[1] == 0x81)
		{
			RandomizeItem(currentItem, GetItemByType(seed[163 - 1]));
			// ACP Ammo, monitor room, B Scenario
		}
		if (uniqueID[1] == 0x87)
		{
			RandomizeItem(currentItem, GetItemByType(seed[1 - 1]));
			// ink ribbon in main hall hardcore
		}
	}

	if (uniqueID[0] == 0xAB)
	{
		if (uniqueID[1] == 0xA7)
		{
			RandomizeItem(currentItem, GetItemByType(seed[240 - 1]));
			// fas, monitor room
		}
		if (uniqueID[1] == 0xB6)
		{
			RandomizeItem(currentItem, GetItemByType(seed[49 - 1]));
			// shotgun shells, western area 2F
		}
	}

	if (uniqueID[0] == 0xAC)
	{
		if (uniqueID[1] == 0x74)
		{
			RandomizeItem(currentItem, GetItemByType(seed[238 - 1]));
			// handgun bullets (bottom right, left), bioreactors room
		}
		if (uniqueID[1] == 0x3E)
		{
			RandomizeItem(currentItem, GetItemByType(seed[184 - 1]));
			// SLS ammo, workroom lift, claire
		}
	}

	if (uniqueID[0] == 0xAD)
	{
		if (uniqueID[1] == 0x54)
		{
			RandomizeItem(currentItem, GetItemByType(seed[167 - 1]));
			// red herb, treatment pool room
		}
		if (uniqueID[1] == 0x9F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[83 - 1]));
			// blue herb, balcony
		}
		if (uniqueID[1] == 0xEC)
		{
			RandomizeItem(currentItem, GetItemByType(seed[119 - 1]));
			// ACP Ammo, Jail Entrance, B scenario Leon
		}
	}

	if (uniqueID[0] == 0xAF)
	{
		RandomizeItem(currentItem, GetItemByType(seed[175 - 1]));
		// mag ammo, bottom waterway
	}

	if (uniqueID[0] == 0xB0)
	{
		if (uniqueID[1] == 0xC8)
		{
			RandomizeItem(currentItem, GetItemByType(seed[256 - 1]));
			// office ink ribbon after sherry, hardcore
		}
	}

	if (uniqueID[0] == 0xB1)
	{
		if (uniqueID[1] == 0x35)
		{
			RandomizeItem(currentItem, GetItemByType(seed[158 - 1]));
			// white gunpowder, water injection chamber, claire
		}
	}

	if (uniqueID[0] == 0xB2)
	{
		if (uniqueID[1] == 0xC1)
		{
			RandomizeItem(currentItem, GetItemByType(seed[227 - 1]));
			// large gunpowder, p4 level testing lab
		}
		if (uniqueID[1] == 0xE3)
		{
			RandomizeItem(currentItem, GetItemByType(seed[181 - 1]));
			// hip pouch, workroom
		}
	}

	if (uniqueID[0] == 0xB3)
	{
		if (uniqueID[1] == 0x71)
		{
			RandomizeItem(currentItem, GetItemByType(seed[8 - 1]));
			// ACP ammo, operations room B scenario
		}
		if (uniqueID[1] == 0xCA)
		{
			RandomizeItem(currentItem, GetItemByType(seed[236 - 1]));
			// hand grenade, bioreactor's room
		}
	}

	if (uniqueID[0] == 0xB5)
	{
		if (uniqueID[1] == 0xD3)
		{
			RandomizeItem(currentItem, GetItemByType(seed[139 - 1]));
			// submachinegun ammo, basketball court, claire
		}
	}

	if (uniqueID[0] == 0xB6)
	{
		RandomizeItem(currentItem, GetItemByType(seed[47 - 1]));
		// handgun bullets, western area 2F
	}

	if (uniqueID[0] == 0xB7)
	{
		if (uniqueID[1] == 0xBF)
		{
			RandomizeItem(currentItem, GetItemByType(seed[222 - 1]));
			// signal modulator, lab main shaft, b scenario
		}
		if (uniqueID[1] == 0xD0)
		{
			RandomizeItem(currentItem, GetItemByType(seed[133 - 1]));
			// boxed electronic part, east storage, claire only
		}
	}

	if (uniqueID[0] == 0xBB)
	{
		// A2 is ada item
		if (uniqueID[1] == 0xA2)
		{
			// white gunpowder every time
			RandomizeItem(currentItem, GetItemByType(304));
		}
		if (uniqueID[1] == 0x6F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[124 - 1]));
			// yellow gunpowder, kennel
		}
		if (uniqueID[1] == 0x82)
		{
			RandomizeItem(currentItem, GetItemByType(seed[108 - 1]));
			// ACP ammo (top left), machinery room, b scenario
		}
	}

	if (uniqueID[0] == 0xBC)
	{
		RandomizeItem(currentItem, GetItemByType(seed[43 - 1]));
		// yellow gunpowder, east office
	}

	if (uniqueID[0] == 0xBD)
	{
		if (uniqueID[1] == 0x16)
		{
			RandomizeItem(currentItem, GetItemByType(seed[147 - 1]));
			// ACP Ammo (first), Sewer Entrance, b scenario Leon
		}
	}

	if (uniqueID[0] == 0xBE)
	{
		if (uniqueID[1] == 0x51)
		{
			RandomizeItem(currentItem, GetItemByType(seed[26 - 1]));
			// flame rounds in weapons locker, claire
		}
	}

	if (uniqueID[0] == 0xBF)
	{
		if (uniqueID[1] == 0x38)
		{
			RandomizeItem(currentItem, GetItemByType(seed[56 - 1]));
			// wooden boards, west storage room
		}
		if (uniqueID[1] == 0xE4)
		{
			RandomizeItem(currentItem, GetItemByType(seed[4 - 1]));
			// handgun bullets (upstairs), main hall
		}
	}

	if (uniqueID[0] == 0xC1)
	{
		RandomizeItem(currentItem, GetItemByType(seed[19 - 1]));
		// film: commemorative, safety deposit room
	}

	if (uniqueID[0] == 0xC2)
	{
		if (uniqueID[1] == 0x5E)
		{
			RandomizeItem(currentItem, GetItemByType(seed[3 - 1]));
			// lion medal, main hall
		}
		if (uniqueID[1] == 0xFB)
		{
			RandomizeItem(currentItem, GetItemByType(seed[148 - 1]));
			// ink ribbon x2
		}
	}

	if (uniqueID[0] == 0xC4)
	{
		if (uniqueID[1] == 0x80)
		{
			RandomizeItem(currentItem, GetItemByType(seed[70 - 1]));
			// handgun bullets, fire escape
		}
		if (uniqueID[1] == 0xC0)
		{
			RandomizeItem(currentItem, GetItemByType(seed[166 - 1]));
			// pawn piece, monitor room
		}
		if (uniqueID[1] == 0xCD)
		{
			RandomizeItem(currentItem, GetItemByType(seed[22 - 1]));
			// gunpowder in 102 locker, claire
		}
	}

	if (uniqueID[0] == 0xC5)
	{
		if (uniqueID[1] == 0xAC)
		{
			RandomizeItem(currentItem, GetItemByType(seed[158 - 1]));
			// Ink ribbon x2, water injection chamber, hardcore
		}
	}

	if (uniqueID[0] == 0xC6)
	{
		if (uniqueID[1] == 0x19)
		{
			RandomizeItem(currentItem, GetItemByType(seed[189 - 1]));
			// ACP Ammo, G2 Fight Room, B scenario
		}
		if (uniqueID[1] == 0x1D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[84 - 1]));
			// ACP Ammo, Roof Area, B scenario
		}
		if (uniqueID[1] == 0xA4)
		{
			RandomizeItem(currentItem, GetItemByType(seed[112 - 1]));
			// handgun bullets (bottom left), machinery room
		}
		if (uniqueID[1] == 0xBC)
		{
			RandomizeItem(currentItem, GetItemByType(seed[249 - 1]));
			// wooden box, stars office
		}
		if (uniqueID[1] == 0xCB)
		{
			RandomizeItem(currentItem, GetItemByType(seed[173 - 1]));
			// hand grenade, bottom waterway overpass
		}
	}

	if (uniqueID[0] == 0xC7)
	{
		if (uniqueID[1] == 0x7D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[219 - 1]));
			// gunpowder, low-temp testing lab
		}
		if (uniqueID[1] == 0xF4)
		{
			RandomizeItem(currentItem, GetItemByType(seed[141 - 1]));
			// yellow gunpowder, break room
		}
	}

	if (uniqueID[0] == 0xC8)
	{
		if (uniqueID[1] == 0x1A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[51 - 1]));
			// portable safe, western area 2F
		}
		if (uniqueID[1] == 0xE5)
		{
			RandomizeItem(currentItem, GetItemByType(seed[95 - 1]));
			// flame rounds outside stars office, claire
		}
	}

	if (uniqueID[0] == 0xC9)
	{
		if (uniqueID[1] == 0xBE)
		{
			RandomizeItem(currentItem, GetItemByType(seed[199 - 1]));
			// high voltage condenser, nap room, claire
		}
	}

	if (uniqueID[0] == 0xCA)
	{
		if (uniqueID[1] == 0x96)
		{
			RandomizeItem(currentItem, GetItemByType(seed[124 - 1]));
			// white gunpowder, kennel, claire
		}
	}

	if (uniqueID[0] == 0xCC)
	{
		if (uniqueID[1] == 0xEE)
		{
			RandomizeItem(currentItem, GetItemByType(seed[132 - 1]));
			// green herb, path to chief's office, claire
		}
	}

	if (uniqueID[0] == 0xCD)
	{
		RandomizeItem(currentItem, GetItemByType(seed[95 - 1]));
		// shotgun shells, outside stars office
	}

	if (uniqueID[0] == 0xCE)
	{
		if (uniqueID[1] == 0x56)
		{
			RandomizeItem(currentItem, GetItemByType(seed[101 - 1]));
			// mq11, stars office, claire
		}
	}

	if (uniqueID[0] == 0xCF)
	{
		if (uniqueID[1] == 0x29)
		{
			RandomizeItem(currentItem, GetItemByType(seed[190 - 1]));
			// flash grenade, g2 fight room
		}
		if (uniqueID[1] == 0x68)
		{
			RandomizeItem(currentItem, GetItemByType(seed[141 - 1]));
			// Ink ribbon x1, private collection room hardcore claire
		}
		if (uniqueID[1] == 0x8E)
		{
			// 8E is final rocket launcher
			// debug_continueFromBreakpoint(co_run);
		}
		if (uniqueID[1] == 0x9E)
		{
			RandomizeItem(currentItem, GetItemByType(seed[132 - 1]));
			// green herb, generator room
		}
		if (uniqueID[1] == 0xB0)
		{
			RandomizeItem(currentItem, GetItemByType(seed[64 - 1]));
			// unicorn medallion, lounge
		}
	}

	if (uniqueID[0] == 0xD1)
	{
		RandomizeItem(currentItem, GetItemByType(seed[59 - 1]));
		// maiden medallion
	}

	if (uniqueID[0] == 0xD3)
	{
		RandomizeItem(currentItem, GetItemByType(seed[122 - 1]));
		// fas, jail
	}

	if (uniqueID[0] == 0xD4)
	{
		if (uniqueID[1] == 0x24)
		{
			RandomizeItem(currentItem, GetItemByType(seed[6 - 1]));
			// handgun bullets, reception
		}
		if (uniqueID[1] == 0x27)
		{
			RandomizeItem(currentItem, GetItemByType(seed[184 - 1]));
			// shotgun shells, workroom lift
		}
		if (uniqueID[1] == 0x46)
		{
			RandomizeItem(currentItem, GetItemByType(seed[117 - 1]));
			// hip pouch, operators room
		}
		if (uniqueID[1] == 0x98)
		{
			RandomizeItem(currentItem, GetItemByType(seed[25 - 1]));
			// shotgun, safety deposit room
		}
		if (uniqueID[1] == 0xC3)
		{
			if (*character == RE2RREnums::Character::Claire)
			{
				RandomizeItem(currentItem, GetItemByType(seed[265 - 1]));
				// acp ammo, break room claire B
			}
			else
			{
				RandomizeItem(currentItem, GetItemByType(seed[138 - 1]));
				// handgun bullets, break room
			}
		}
		if (uniqueID[1] == 0xEE)
		{
			RandomizeItem(currentItem, GetItemByType(seed[72 - 1]));
			// bolt cutters, fire escape
		}
	}

	if (uniqueID[0] == 0xD5)
	{
		RandomizeItem(currentItem, GetItemByType(seed[50 - 1]));
		// shotgun shells, western area 2F
	}

	if (uniqueID[0] == 0xD6)
	{
		if (uniqueID[1] == 0x9A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[112 - 1]));
			// ACP ammo (bottom left), machinery room, b scenario
		}
		if (uniqueID[1] == 0xBB)
		{
			RandomizeItem(currentItem, GetItemByType(seed[119 - 1]));
			// white gunpowder, elevator controls room, claire
		}
	}

	if (uniqueID[0] == 0xD7)
	{
		if (uniqueID[1] == 0x98)
		{
			RandomizeItem(currentItem, GetItemByType(seed[96 - 1]));
			// battery, stars office
		}
		// 7A is Ada ink ribbon hardcore
	}

	if (uniqueID[0] == 0xD8)
	{
		RandomizeItem(currentItem, GetItemByType(seed[102 - 1]));
		// portable safe, linen room
	}

	if (uniqueID[0] == 0xD9)
	{
		if (uniqueID[1] == 0x88)
		{
			RandomizeItem(currentItem, GetItemByType(seed[198 - 1]));
			// shotgun shells, nap room
		}
		if (uniqueID[1] == 0xE2)
		{
			RandomizeItem(currentItem, GetItemByType(seed[220 - 1]));
			// white gunpowder, modulator room, claire
		}
	}

	if (uniqueID[0] == 0xDA)
	{
		if (uniqueID[1] == 0x11)
		{
			RandomizeItem(currentItem, GetItemByType(seed[238 - 1]));
			// ACP ammo (bottom right, left), Bioreactor's room, b scenario
		}
		else
		{
			// gotta check this isn't 0x11 at some point
			RandomizeItem(currentItem, GetItemByType(seed[250 - 1]));
			// rising rookie film, stars office hiding place
		}
	}

	if (uniqueID[0] == 0xDB)
	{
		if (uniqueID[1] == 0x39)
		{
			RandomizeItem(currentItem, GetItemByType(seed[15 - 1]));
			// high capacity mag (matilda), west office
		}
		if (uniqueID[1] == 0xA0)
		{
			RandomizeItem(currentItem, GetItemByType(seed[79 - 1]));
			// shotgun shells, east storage room
		}
	}

	if (uniqueID[0] == 0xDC)
	{
		if (uniqueID[1] == 0x05)
		{
			RandomizeItem(currentItem, GetItemByType(seed[38 - 1]));
			// green herb, east office
		}
		if (uniqueID[1] == 0xCC)
		{
			RandomizeItem(currentItem, GetItemByType(seed[207 - 1]));
			// red herb, greenhouse
		}
	}

	if (uniqueID[0] == 0xDD)
	{
		// 5F is ada
		if (uniqueID[1] == 0x5F)
		{
			// leons rocket launcher every time
			RandomizeItem(currentItem, GetItemByType(274));
		}
		if (uniqueID[1] == 0x34)
		{
			RandomizeItem(currentItem, GetItemByType(seed[40 - 1]));
			// handgun bullets, east office
		}
	}

	if (uniqueID[0] == 0xE1)
	{
		if (uniqueID[1] == 0x34)
		{
			RandomizeItem(currentItem, GetItemByType(seed[202 - 1]));
			// Ink Ribbon x2, Lobby hardcore
		}
		if (uniqueID[1] == 0xC4)
		{
			if (*character == RE2RREnums::Character::Claire)
			{
				RandomizeItem(currentItem, GetItemByType(seed[266 - 1]));
				// fuse (break room hallway) claire b scenario
			}
			else
			{
				RandomizeItem(currentItem, GetItemByType(seed[140 - 1]));
				// fuse (break room hallway)
			}
		}
	}

	if (uniqueID[0] == 0xE3)
	{
		if (uniqueID[1] == 0x80)
		{
			RandomizeItem(currentItem, GetItemByType(seed[213 - 1]));
			// shotgun shells, lounge
		}
		if (uniqueID[1] == 0xE9)
		{
			RandomizeItem(currentItem, GetItemByType(seed[221 - 1]));
			// handgun bullets, modulator room
		}
	}

	if (uniqueID[0] == 0xE5)
	{
		if (uniqueID[1] == 0x22)
		{
			RandomizeItem(currentItem, GetItemByType(seed[11 - 1]));
			// wooden boards, western area 1F
		}
		if (uniqueID[1] == 0x76)
		{
			RandomizeItem(currentItem, GetItemByType(seed[228 - 1]));
			// yellow gunpowder, p-4 level testing lab
		}
	}

	if (uniqueID[0] == 0xE6)
	{
		if (uniqueID[1] == 0x43)
		{
			RandomizeItem(currentItem, GetItemByType(seed[146 - 1]));
			// submachine gun ammo, break room, claire b scenario
		}
		if (uniqueID[1] == 0xF9)
		{
			RandomizeItem(currentItem, GetItemByType(seed[261 - 1]));
			// ACP ammo, guardroom, b scenario
		}
	}

	if (uniqueID[0] == 0xE7)
	{
		if (uniqueID[1] == 0x92)
		{
			RandomizeItem(currentItem, GetItemByType(seed[260 - 1]));
			// hand grenade, guardroom, b scenario
		}
		if (uniqueID[1] == 0xDB)
		{
			RandomizeItem(currentItem, GetItemByType(seed[27 - 1]));
			// ACP Ammo, Press Room B scenario
		}
	}

	if (uniqueID[0] == 0xE8)
	{
		if (uniqueID[1] == 0x5D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[242 - 1]));
			// blue herb, pump room
		}
		if (uniqueID[1] == 0xB2)
		{
			RandomizeItem(currentItem, GetItemByType(seed[16 - 1]));
			// gunpowder, dark room
		}
		if (uniqueID[1] == 0xFA)
		{
			RandomizeItem(currentItem, GetItemByType(seed[144 - 1]));
			// submachinegun ammo, outside office, claire
		}
	}

	if (uniqueID[0] == 0xE9)
	{
		if (uniqueID[1] == 0xBA)
		{
			RandomizeItem(currentItem, GetItemByType(seed[143 - 1]));
			// hand grenade, bus, claire only
		}
		if (uniqueID[1] == 0xF0)
		{
			RandomizeItem(currentItem, GetItemByType(seed[163 - 1]));
			// handgun bullets, monitor room
		}
	}

	if (uniqueID[0] == 0xEA)
	{
		if (uniqueID[1] == 0x6C)
		{
			RandomizeItem(currentItem, GetItemByType(seed[138 - 1]));
			// submachine ammo, chief's office, claire
		}
		if (uniqueID[1] == 0xEF)
		{
			RandomizeItem(currentItem, GetItemByType(seed[122 - 1]));
			// FAS, orphanage
		}
	}

	if (uniqueID[0] == 0xEB)
	{
		if (uniqueID[1] == 0xA2)
		{
			RandomizeItem(currentItem, GetItemByType(seed[128 - 1]));
			// car key, firing range
		}
		if (uniqueID[1] == 0xAA)
		{
			RandomizeItem(currentItem, GetItemByType(seed[36 - 1]));
			// ink ribbon x2, records room hardcore
		}
	}

	if (uniqueID[0] == 0xEC)
	{
		if (uniqueID[1] == 0x3B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[253 - 1]));
			// ink ribbon x1, escape area typewriter hardcore
		}
		if (uniqueID[1] == 0x4E)
		{
			RandomizeItem(currentItem, GetItemByType(seed[152 - 1]));
			// rook piece, rook bridge area
		}
		if (uniqueID[1] == 0xC9)
		{
			RandomizeItem(currentItem, GetItemByType(seed[229 - 1]));
			// Ink ribbon x1, p-4 level testing lab hardcore
		}
	}

	if (uniqueID[0] == 0xEE)
	{
		if (uniqueID[1] == 0x30)
		{
			RandomizeItem(currentItem, GetItemByType(seed[71 - 1]));
			// wooden boards, fire escape
		}
		if (uniqueID[1] == 0xE5)
		{
			RandomizeItem(currentItem, GetItemByType(seed[100 - 1]));
			// yellow gunpowsder, stars office
		}
	}

	if (uniqueID[0] == 0xEF)
	{
		if (uniqueID[1] == 0x1F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[255 - 1]));
			// Ink Ribbon x1, Sherry hardcore
		}
		if (uniqueID[1] == 0x2A)
		{
			RandomizeItem(currentItem, GetItemByType(seed[88 - 1]));
			// gunpowder, boiler room
		}
		if (uniqueID[1] == 0x8B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[216 - 1]));
			// flamethrower fuel, server room
		}
	}

	if (uniqueID[0] == 0xF0)
	{
		if (uniqueID[1] == 0xAD)
		{
			RandomizeItem(currentItem, GetItemByType(seed[156 - 1]));
			// Knife, lower waterway pre-slide
		}
		if (uniqueID[1] == 0xAE)
		{
			RandomizeItem(currentItem, GetItemByType(seed[230 - 1]));
			// handgun bullets (top left), bioreactors room
		}
	}

	if (uniqueID[0] == 0xF1)
	{
		if (uniqueID[1] == 0x8E)
		{
			RandomizeItem(currentItem, GetItemByType(seed[46 - 1]));
			// muzzle brake (matilda), waiting room
		}
		if (uniqueID[1] == 0x90)
		{
			RandomizeItem(currentItem, GetItemByType(seed[217 - 1]));
			// white gunpowder, server room, claire
		}
	}

	if (uniqueID[0] == 0xF2)
	{
		if (uniqueID[1] == 0xE0)
		{
			RandomizeItem(currentItem, GetItemByType(seed[20 - 1]));
			// handgun bullets in locker, claire
		}
	}

	if (uniqueID[0] == 0xF3)
	{
		// 01 is bishop repickup in sewer, only work in B scenario
		if (uniqueID[1] == 0x01 && *scenario == RE2RREnums::Scenario::B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[164 - 1]));
			// bishop, B scenario only plz
		}
		if (uniqueID[1] == 0x69)
		{
			// 69 is queen
			// debug_continueFromBreakpoint(co_run);
		}
		if (uniqueID[1] == 0x04)
		{
			RandomizeItem(currentItem, GetItemByType(seed[192 - 1]));
			// shotgun shells, security room
		}
		if (uniqueID[1] == 0x31)
		{
			RandomizeItem(currentItem, GetItemByType(seed[10 - 1]));
			// green herb, western area 1F
		}
		if (uniqueID[1] == 0x98)
		{
			RandomizeItem(currentItem, GetItemByType(seed[142 - 1]));
			// green herb, outside RPD
		}
	}

	if (uniqueID[0] == 0xF4)
	{
		if (uniqueID[1] == 0x66)
		{
			RandomizeItem(currentItem, GetItemByType(seed[212 - 1]));
			// large gunpowder, underneath greenhouse
		}
		if (uniqueID[1] == 0xB5)
		{
			RandomizeItem(currentItem, GetItemByType(seed[127 - 1]));
			// diamond key, morgue
		}
		if (uniqueID[1] == 0xE3)
		{
			RandomizeItem(currentItem, GetItemByType(seed[73 - 1]));
			// green herb, main hall 3F
		}
	}

	if (uniqueID[0] == 0xF5)
	{
		RandomizeItem(currentItem, GetItemByType(seed[101 - 1]));
		// lightning hawk, stars office
	}

	if (uniqueID[0] == 0xF6)
	{
		if (uniqueID[1] == 0xE5)
		{
			RandomizeItem(currentItem, GetItemByType(seed[163 - 1]));
			// Ink ribbon x2, monitor room hardcore
		}
		if (uniqueID[1] == 0xF2)
		{
			RandomizeItem(currentItem, GetItemByType(seed[139 - 1]));
			// mag ammo, break room
		}
	}

	if (uniqueID[0] == 0xF7)
	{
		RandomizeItem(currentItem, GetItemByType(seed[36 - 1]));
		// gunpowder, records room
	}

	if (uniqueID[0] == 0xF8)
	{
		if (uniqueID[1] == 0x34)
		{
			RandomizeItem(currentItem, GetItemByType(seed[133 - 1]));
			// boxed electronic part, generator room
		}
		if (uniqueID[1] == 0x3F)
		{
			RandomizeItem(currentItem, GetItemByType(seed[84 - 1]));
			// handgun bullets, roof area
		}
		if (uniqueID[1] == 0x72)
		{
			RandomizeItem(currentItem, GetItemByType(seed[201 - 1]));
			// hip pouch, nap room
		}
		if (uniqueID[1] == 0x79)
		{
			// doll in sherry segment
			// debug_continueFromBreakpoint(co_run);
		}
		if (uniqueID[1] == 0xAB)
		{
			RandomizeItem(currentItem, GetItemByType(seed[51 - 1]));
			// Bejeweled Box, western area 2F, b scenario
		}
	}

	if (uniqueID[0] == 0xF9)
	{
		if (uniqueID[1] == 0x08)
		{
			RandomizeItem(currentItem, GetItemByType(seed[2 - 1]));
			// fas, main hall
		}
		if (uniqueID[1] == 0x55)
		{
			RandomizeItem(currentItem, GetItemByType(seed[178 - 1]));
			// queen plug, supplies storage room
		}
		if (uniqueID[1] == 0x6D)
		{
			RandomizeItem(currentItem, GetItemByType(seed[52 - 1]));
			// handgun bullets, western area 3F
		}
	}

	if (uniqueID[0] == 0xFA)
	{
		RandomizeItem(currentItem, GetItemByType(seed[90 - 1]));
		// yellow gunpowder, outside observation room
	}

	if (uniqueID[0] == 0xFB)
	{
		if (uniqueID[1] == 0x67)
		{
			RandomizeItem(currentItem, GetItemByType(seed[189 - 1]));
			// handgun bullets, g2 fight room
		}
		if (uniqueID[1] == 0xBC)
		{
			RandomizeItem(currentItem, GetItemByType(seed[9 - 1]));
			// handgun bullets, western area 1F
		}
	}

	if (uniqueID[0] == 0xFC)
	{
		if (uniqueID[1] == 0x9B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[5 - 1]));
			// knife (marvin), main hall
		}
		if (uniqueID[1] == 0xCB)
		{
			RandomizeItem(currentItem, GetItemByType(seed[9 - 1]));
			// ACP ammo, western area 1F B scenario
		}
		if (uniqueID[1] == 0xF0)
		{
			RandomizeItem(currentItem, GetItemByType(seed[218 - 1]));
			// knife, server room
		}
	}

	if (uniqueID[0] == 0xFD)
	{
		if (uniqueID[1] == 0x29)
		{
			RandomizeItem(currentItem, GetItemByType(seed[20 - 1]));
			// acp ammo, locker room claire B scenario
		}
		if (uniqueID[1] == 0x94)
		{
			RandomizeItem(currentItem, GetItemByType(seed[62 - 1]));
			// red book, library
		}
	}

	if (uniqueID[0] == 0xFE)
	{
		if (uniqueID[1] == 0x9B)
		{
			RandomizeItem(currentItem, GetItemByType(seed[246 - 1]));
			// ACP Ammo, Escape Shaft, Leon B scenario
		}
		if (uniqueID[1] == 0xEA)
		{
			RandomizeItem(currentItem, GetItemByType(seed[92 - 1]));
			// bejeweled box, observation room
		}
	}
}

std::string GUIDToString(GUID *guid)
{
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
