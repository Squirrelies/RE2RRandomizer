#include "Randomizer.h"

void Randomizer::ResetSeed(std::vector<uint32_t> *seed, Difficulty *difficulty, Scenario *scenario, Character *character)
{
	logger->LogMessage("[RE2R-R] Randomizer::ResetSeed(%p, %d, %d, %d) called.\n",
	                   (void *)seed,
	                   difficulty != nullptr ? *difficulty : -1,
	                   scenario != nullptr ? *scenario : -1,
	                   character != nullptr ? *character : -1);
	this->seed = seed;
	this->difficulty = difficulty;
	this->scenario = scenario;
	this->character = character;
}

void Randomizer::ItemPickup(uint32_t *type, GUID *itemPositionGuid)
{
	logger->LogMessage("[RE2R-R] Randomizer::ItemPickup(*type: %ld (0x%lX), itemPositionGuid: %s) called.\n", *type, *type, GUIDToString(itemPositionGuid).c_str());

	uint32_t debugType = 4;
	app_ropeway_gamemastering_InventoryManager_PrimitiveItem newItem = GetItemByType(&debugType); // GetItemByType(type)
	RandomizeItem((app_ropeway_gamemastering_InventoryManager_PrimitiveItem *)type, &newItem);
}

void Randomizer::RandomizeItem(app_ropeway_gamemastering_InventoryManager_PrimitiveItem *currentItem, app_ropeway_gamemastering_InventoryManager_PrimitiveItem *newItem)
{
	for (size_t i = 0; i < sizeof(app_ropeway_gamemastering_InventoryManager_PrimitiveItem); ++i)
		logger->LogMessage("[RE2R-R] Randomizer::RandomizeItem() writing %02X to %p...\n", *((uint8_t *)newItem + i), (void *)((uint8_t *)currentItem + i));
	memcpy((void *)currentItem, (void *)newItem, sizeof(app_ropeway_gamemastering_InventoryManager_PrimitiveItem));
}

// Returns a vector of uint8_t representing the app.ropeway.gamemastering.InventoryManager.PrimitiveItem structure 0x10-0x24 (0x14).
app_ropeway_gamemastering_InventoryManager_PrimitiveItem Randomizer::GetItemByType(uint32_t *type)
{
	if (*type == 0 || *type == 3 || *type == 5 || *type == 7 || *type == 8 || *type == 12 || *type == 16 || *type == 19 || *type == 26 || *type == 27 || *type == 39 || *type == 46 || *type == 51 || *type == 56 || *type == 59 || *type == 69 || *type == 79 || *type == 83 || *type == 92 || *type == 107 || *type == 111 || *type == 113 || *type == 118 || *type == 137 || *type == 143 || *type == 146 || *type == 147 || *type == 148 || *type == 153 || *type == 162 || *type == 182 || *type == 188 || *type == 193 || *type == 220 || *type == 229 || *type == 231 || *type == 237 || *type == 238 || *type == 243 || *type == 245 || *type == 256 || *type == 260 || *type == 264)
	{
		if (*difficulty == Hardcore)
		{
			if (*type == 16)
			{
				return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
			}
			else if (*type == 0)
			{
				return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
			}
		}
		else if (*scenario == B)
		{
			if (*type == 16 || *type == 0)
			{
				return {0x1A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00};
			}
		}
		if (*character == Leon)
		{
			if (*scenario == A)
			{
				if (*difficulty == Hardcore)
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
				if (*difficulty == Hardcore)
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
			if (*type == 146)
			{
				return {0xA0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
			}
			else if (*type == 147)
			{
				return {0x50, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
			}
			else if (*type == 118)
			{
				return {0x27, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
			}
			else if (*type == 143 || *type == 137 || *type == 245)
			{
				if (*difficulty == Hardcore)
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
				if (*scenario == A)
				{
					if (*difficulty == Hardcore)
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
					if (*difficulty == Hardcore)
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

	if (*type == 1 || *type == 29 || *type == 98 || *type == 121 || *type == 230 || *type == 239)
	{
		return {0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 2)
	{
		return {0x76, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 4 || *type == 20 || *type == 60 || *type == 135 || *type == 155 || *type == 190 || *type == 196 || *type == 217 || *type == 240 || *type == 261)
	{
		if (*scenario == B && *type == 4)
		{
			if (*character == Leon)
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

	if (*type == 6 || *type == 9 || *type == 31 || *type == 37 || *type == 44 || *type == 65 || *type == 72 || *type == 85 || *type == 86 || *type == 109 || *type == 112 || *type == 115 || *type == 131 || *type == 141 || *type == 171 || *type == 173 || *type == 185 || *type == 201 || *type == 214 || *type == 242)
	{
		if (*difficulty == Hardcore)
		{
			if (*type == 37)
			{
				return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
			}
		}
		if (*scenario == B && *type == 131 && *character == Leon)
		{
			return {0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x02, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 10 || *type == 28 || *type == 33 || *type == 55 || *type == 64 || *type == 70 || *type == 81)
	{
		return {0x21, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 11 || *type == 15 || *type == 21 || *type == 35 || *type == 40 || *type == 54 || *type == 62 || *type == 87 || *type == 90 || *type == 93 || *type == 102 || *type == 103 || *type == 114 || *type == 133 || *type == 152 || *type == 202 || *type == 218)
	{
		if (*scenario == B && *type == 62)
		{
			return {0x28, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			if (*difficulty == Hardcore)
			{
				if (*type == 35)
				{
					return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
				}
				else if (*type == 37)
				{
					return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
				}
			}
			if (*character == Leon)
			{
				return {0x24, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
			}
			else
			{
				if (*type == 87)
				{
					return {0x04, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
				}
				else if (*type == 133)
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

	if (*type == 13 || *type == 22 || *type == 57 || *type == 116 || *type == 180 || *type == 200)
	{
		if (*difficulty == Hardcore)
		{
			if (*type == 116)
			{
				return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
			}
		}
	}

	if (*type == 14)
	{
		if (*character == Leon)
		{
			return {0x30, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x33, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 17 || *type == 47 || *type == 84 || *type == 96 || *type == 110 || *type == 124 || *type == 130 || *type == 166 || *type == 175 || *type == 186 || *type == 206 || *type == 228 || *type == 244 || *type == 257)
	{
		return {0x03, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 18)
	{
		return {0x4A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 23 || *type == 25 || *type == 48 || *type == 49 || *type == 78 || *type == 94 || *type == 104 || *type == 128 || *type == 134 || *type == 149 || *type == 160 || *type == 183 || *type == 191 || *type == 197 || *type == 212 || *type == 250)
	{
		if (*character == Leon)
		{
			if (*difficulty == Hardcore)
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
			if (*type == 149 || *type == 183 || *type == 134)
			{
				if (*difficulty == Hardcore)
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
				if (*difficulty == Hardcore)
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

	if (*type == 24)
	{
		if (*character == Leon)
		{
			return {0x00, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00};
		}
		else
		{
			return {0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00};
		}
	}

	if (*type == 30)
	{
		return {0x22, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 32 || *type == 38 || *type == 80 || *type == 97 || *type == 125 || *type == 189 || *type == 205 || *type == 233 || *type == 236)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 34 || *type == 105 || *type == 108 || *type == 142 || *type == 145 || *type == 172 || *type == 192 || *type == 210 || *type == 223 || *type == 235 || *type == 259)
	{
		if (*scenario == B && *character == Claire && *type == 145)
		{
			if (*difficulty == Hardcore)
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

	if (*type == 36)
	{
		return {0x4F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 41)
	{
		return {0x56, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 42 || *type == 89 || *type == 99 || *type == 123 || *type == 140 || *type == 157 || *type == 158 || *type == 203 || *type == 216 || *type == 219 || *type == 225 || *type == 227 || *type == 263)
	{
		if (*character == Leon)
		{
			return {0x26, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x27, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 43)
	{
		if (*scenario == A)
		{
			return {0xF0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x83, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 45)
	{
		if (*character == Leon)
		{
			return {0x31, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x36, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 50 || *type == 101)
	{
		if (*scenario == B && *type == 50)
		{
			return {0x5B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x70, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 52 || *type == 138 || *type == 154 || *type == 161 || *type == 174 || *type == 187 || *type == 232)
	{
		if (*character == Leon)
		{
			if (*difficulty == Hardcore)
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
			if (*type == 154 || *type == 232)
			{
				if (*difficulty == Hardcore)
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
				if (*difficulty == Hardcore)
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

	if (*type == 53)
	{
		return {0x52, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 58)
	{
		return {0x7C, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 61)
	{
		return {0x72, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 63)
	{
		return {0x51, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 66)
	{
		return {0x54, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 67)
	{
		return {0x73, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 68)
	{
		return {0x58, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 71)
	{
		return {0xF4, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 73 || *type == 156 || *type == 195 || *type == 209 || *type == 211 || *type == 226)
	{
		return {0x25, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 74)
	{
		return {0x81, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 75)
	{
		return {0x87, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 76 || *type == 82 || *type == 122 || *type == 136 || *type == 159 || *type == 168 || *type == 176 || *type == 184 || *type == 207 || *type == 224 || *type == 241 || *type == 258 || *type == 262)
	{
		return {0x04, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 77)
	{
		return {0x82, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 88)
	{
		if (*character == Leon)
		{
			return {0xA0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x40, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 91)
	{
		if (*scenario == A)
		{
			return {0x5B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x70, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 95)
	{
		return {0x23, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 100)
	{
		if (*character == Leon)
		{
			return {0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x03, 0x00};
		}
		else
		{
			return {0x00, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x14, 0x00};
		}
	}

	if (*type == 106)
	{
		if (*character == Leon)
		{
			return {0x3E, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x3C, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 117)
	{
		if (*character == Leon)
		{
			return {0x32, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0D, 0x00};
		}
	}

	if (*type == 119)
	{
		if (*character == Leon)
		{
			return {0x50, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x00, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1D, 0x00, 0x00, 0x00, 0x90, 0x01};
		}
	}

	if (*type == 120)
	{
		return {0x53, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 126)
	{
		return {0x77, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 127)
	{
		return {0x25, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x78};
	}

	if (*type == 129)
	{
		return {0x4B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 132)
	{
		return {0x88, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 139)
	{
		if (*character == Leon)
		{
			return {0xF1, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 144)
	{
		if (*scenario == B && *character == Claire)
		{
			if (*difficulty == Hardcore)
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

	if (*type == 150)
	{
		return {0xAA, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 151)
	{
		return {0x5E, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x00};
	}

	if (*type == 163)
	{
		return {0x5D, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x00};
	}

	if (*type == 164)
	{
		return {0x84, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x00};
	}

	if (*type == 165)
	{
		return {0x85, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x00};
	}

	if (*type == 167)
	{
		return {0xB0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 169)
	{
		if (*character == Leon)
		{
			return {0x37, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x35, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 170)
	{
		return {0xC2, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 177)
	{
		return {0x86, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x00};
	}

	if (*type == 178)
	{
		return {0x5F, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x69, 0x00};
	}

	if (*type == 179)
	{
		if (*character == Leon)
		{
			return {0x00, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x90, 0x01};
		}
		else
		{
			return {0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x07, 0x00};
		}
	}

	if (*type == 181)
	{
		return {0x48, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 194 || *type == 215 || *type == 234)
	{
		if (*character == Leon)
		{
			return {0x19, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x00};
		}
		else
		{
			if (*type == 215)
			{
				if (*difficulty == Hardcore)
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

	if (*type == 198)
	{
		if (*character == Leon)
		{
			return {0x41, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x42, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 199)
	{
		return {0xC6, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 204)
	{
		return {0xB3, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 208)
	{
		return {0xC7, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 213)
	{
		return {0xBE, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 221)
	{
		return {0xBD, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 222)
	{
		return {0xCB, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 246)
	{
		return {0xB7, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 247)
	{
		if (*character == Leon)
		{
			return {0x19, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x01};
		}
		else
		{
			return {0x18, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00};
		}
	}

	if (*type == 248)
	{
		if (*character == Leon)
		{
			return {0x26, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x3A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
	}

	if (*type == 249)
	{
		return {0x49, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 251 || *type == 252 || *type == 255)
	{
		return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 254 || *type == 253)
	{
		return {0x20, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
	}

	if (*type == 265)
	{
		return {0xF1, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 266)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00};
	}

	if (*type == 267)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x03, 0x00};
	}

	if (*type == 268)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x90, 0x01};
	}

	if (*type == 269)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00};
	}

	if (*type == 270)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x14, 0x00};
	}

	if (*type == 271)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0D, 0x00};
	}

	if (*type == 272)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x07, 0x00};
	}

	if (*type == 273)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1D, 0x00, 0x00, 0x00, 0x90, 0x01};
	}

	if (*type == 274)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x04, 0x00};
	}

	if (*type == 275)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x0A, 0x00};
	}

	if (*type == 276)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x05, 0x00};
	}

	if (*type == 277)
	{
		return {0x33, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 278)
	{
		return {0x30, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 279)
	{
		return {0x31, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 280)
	{
		return {0x3E, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 281)
	{
		return {0x38, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 282)
	{
		return {0x37, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 283)
	{
		return {0x41, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 284)
	{
		return {0x26, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 285)
	{
		return {0x36, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 286)
	{
		return {0x3C, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 287)
	{
		return {0x35, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 288)
	{
		return {0x42, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 289)
	{
		return {0x3A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 290)
	{
		return {0x40, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 291)
	{
		return {0x32, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 292)
	{
		if (*scenario == A)
		{
			if (*difficulty == Hardcore)
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
			if (*difficulty == Hardcore)
			{
				return {0x1A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
			}
			else
			{
				return {0x1A, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00};
			}
		}
	}

	if (*type == 293)
	{
		return {0x18, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00};
	}

	if (*type == 294)
	{
		return {0x19, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x00};
	}

	if (*type == 295)
	{
		if (*difficulty == Hardcore)
		{
			return {0x1B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
		}
		else
		{
			return {0x1B, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
		}
	}

	if (*type == 296)
	{
		return {0x25, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 297)
	{
		if (*difficulty == Hardcore)
		{
			return {0x12, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
		}
		else
		{
			return {0x12, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00};
		}
	}

	if (*type == 298)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x03};
	}

	if (*type == 299)
	{
		if (*difficulty == Hardcore)
		{
			return {0x11, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x00};
		}
		else
		{
			return {0x11, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x64, 0x00};
		}
	}

	if (*type == 300)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 301)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x42, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 302)
	{
		return {0x26, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 303)
	{
		if (*difficulty == Hardcore)
		{
			return {0x17, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
		}
		else
		{
			return {0x17, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
		}
	}

	if (*type == 304)
	{
		return {0x27, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 305)
	{
		if (*difficulty == Hardcore)
		{
			return {0x10, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00};
		}
		else
		{
			return {0x10, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00};
		}
	}

	if (*type == 306)
	{
		return {0x24, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00};
	}

	if (*type == 307)
	{
		return {0x19, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x01};
	}

	if (*type == 308)
	{
		return {0x18, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00};
	}

	if (*type == 309)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x05, 0x00};
	}

	if (*type == 310)
	{
		return {0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x07, 0x00};
	}

	// return {};
	return {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
}

void Randomizer::SetItemByGUID(uint32_t *type, GUID *itemPositionGuid)
{
	// uint8_t *uniqueID = (uint8_t *)itemPositionGuid;

	// if (uniqueID[0] == 0x00)
	// {
	// 	if (uniqueID[1] == 0x7D)
	// 	{
	// 		setItemByID(*seed[145]);
	// 		//--claire's flame rounds outside break room, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x01)
	// {
	// 	if (uniqueID[1] == 0x3A)
	// 	{
	// 		setItemByID(*seed[39]);
	// 		// flash grenade, east office
	// 	}
	// 	if (uniqueID[1] == 0xBD)
	// 	{
	// 		setItemByID(*seed[196]);
	// 		// large gunpowder, kitchen
	// 	}
	// }

	// if (uniqueID[0] == 0x02)
	// {
	// 	if (uniqueID[1] == 0x5C)
	// 	{
	// 		setItemByID(*seed[244]);
	// 		// ACP ammo, pump room, b scenario
	// 	}
	// 	if (uniqueID[1] == 0x80)
	// 	{
	// 		setItemByID(*seed[183]);
	// 		// ACP Ammo, Workroom, b scenario
	// 	}
	// 	if (uniqueID[1] == 0x8A)
	// 	{
	// 		setItemByID(*seed[79]);
	// 		// flame rounds, east storage room. claire
	// 	}
	// 	if (uniqueID[1] == 0xF4)
	// 	{
	// 		setItemByID(*seed[203]);
	// 		// gunpowder, Lobby
	// 	}
	// }

	// if (uniqueID[0] == 0x03)
	// {
	// 	setItemByID(*seed[157]);
	// 	// large gunpowder, water injection chamber
	// }

	// if (uniqueID[0] == 0x04)
	// {
	// 	if (uniqueID[1] == 0x28)
	// 	{
	// 		setItemByID(*seed[146]);
	// 		// hand grenade, sewer entrance
	// 	}
	// 	if (uniqueID[1] == 0x33)
	// 	{
	// 		setItemByID(*seed[74]);
	// 		// large gunpowder, racoon area west
	// 	}
	// 	if (uniqueID[1] == 0x81)
	// 	{
	// 		setItemByID(*seed[155]);
	// 		// mag ammo, rpd access room
	// 	}
	// }

	// if (uniqueID[0] == 0x05)
	// {
	// 	if (uniqueID[1] == 0xB8)
	// 	{
	// 		// B8 is rook re-pickup
	// 		debug_continueFromBreakpoint(co_run);
	// 	}
	// 	if (uniqueID[1] == 0xF7)
	// 	{
	// 		setItemByID(*seed[248]);
	// 		// extra flamethrower fuel, hiding place press room
	// 	}
	// }

	// if (uniqueID[0] == 0x07)
	// {
	// 	setItemByID(*seed[33]);
	// 	// flash grenade, detonator room
	// }

	// if (uniqueID[0] == 0x08)
	// {
	// 	if (uniqueID[1] == 0x80)
	// 	{
	// 		setItemByID(*seed[44]);
	// 		// courtyard key, guard room, b scenario
	// 	}
	// 	if (uniqueID[1] == 0x0E)
	// 	{
	// 		setItemByID(*seed[220]);
	// 		// yellow gunpowder, modulator room
	// 	}
	// 	if (uniqueID[1] == 0x30)
	// 	{
	// 		setItemByID(*seed[206]);
	// 		// flash grenade, greenhouse control room
	// 	}
	// }

	// if (uniqueID[0] == 0x0A)
	// {
	// 	if (uniqueID[1] == 0x4F)
	// 	{
	// 		setItemByID(*seed[197]);
	// 		// knife, kitchen
	// 	}
	// 	if (uniqueID[1] == 0xF8)
	// 	{
	// 		setItemByID(*seed[27]);
	// 		// handgun bullets, press room
	// 	}
	// }

	// if (uniqueID[0] == 0x0C)
	// {
	// 	if (uniqueID[1] == 0x7A)
	// 	{
	// 		setItemByID(*seed[195]);
	// 		// flamethrower fuel, cafeteria
	// 	}
	// 	if (uniqueID[1] == 0xB6)
	// 	{
	// 		setItemByID(*seed[159]);
	// 		// yellow gunpowder, lower waterway
	// 	}
	// }

	// if (uniqueID[0] == 0x0D)
	// {
	// 	if (uniqueID[1] == 0x43)
	// 	{
	// 		setItemByID(*seed[135]);
	// 		// SLS rounds, office
	// 	}
	// }

	// if (uniqueID[0] == 0x0E)
	// {
	// 	if (uniqueID[1] == 0x72)
	// 	{
	// 		setItemByID(*seed[150]);
	// 		// SLS rounds, upper walkway
	// 	}
	// }

	// if (uniqueID[0] == 0x0F)
	// {
	// 	if (uniqueID[1] == 0x9C)
	// 	{
	// 		setItemByID(*seed[257]);
	// 		// ACP Ammo, Stars Office, B scenario
	// 	}
	// 	if (uniqueID[1] == 0x6D)
	// 	{
	// 		setItemByID(*seed[232]);
	// 		// ACP Ammo (Bottom Left), Bioreactor's Room, B scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x11)
	// {
	// 	if (uniqueID[1] == 0x82)
	// 	{
	// 		setItemByID(*seed[38]);
	// 		// ink ribbon x2, east office, hardcore
	// 	}
	// 	if (uniqueID[1] == 0x86)
	// 	{
	// 		setItemByID(*seed[175]);
	// 		// submachinegun ammo, bottom waterway, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x12)
	// {
	// 	setItemByID(*seed[12]);
	// 	// gunpowder, west office
	// }

	// if (uniqueID[0] == 0x13)
	// {
	// 	if (uniqueID[1] == 0x13)
	// 	{
	// 		setItemByID(*seed[54]);
	// 		// spade key, western area 3F
	// 	}
	// 	if (uniqueID[1] == 0x83)
	// 	{
	// 		setItemByID(*seed[115]);
	// 		// gunpowder (up ladder), machinery room
	// 	}
	// }

	// if (uniqueID[0] == 0x14)
	// {
	// 	if (uniqueID[1] == 0xC0)
	// 	{
	// 		setItemByID(*seed[26]);
	// 		// Shotgun Shells (shotgun cupboard), safety deposit room
	// 	}
	// 	if (uniqueID[1] == 0xDD)
	// 	{
	// 		setItemByID(*seed[5]);
	// 		// Quickdraw army, guardroom B scenario Claire
	// 	}
	// 	if (uniqueID[1] == 0xF1)
	// 	{
	// 		setItemByID(*seed[88]);
	// 		// ink ribbon x1, boiler room, Leon Hardcore
	// 	}
	// }

	// if (uniqueID[0] == 0x15)
	// {
	// 	if (uniqueID[1] == 0xE7andscenario == "B")
	// 	{
	// 		setItemByID(*seed[165]);
	// 		// knight plug, b scenario
	// 	}
	// 	else if (uniqueID[1] == 0xE7)
	// 	{
	// 		// E7 is knight repickup
	// 		debug_continueFromBreakpoint(co_run);
	// 	}
	// 	if (uniqueID[1] == 0x2C)
	// 	{
	// 		setItemByID(*seed[187]);
	// 		// red herb, main power room
	// 	}
	// 	if (uniqueID[1] == 0x55)
	// 	{
	// 		setItemByID(*seed[217]);
	// 		// yellow gunpowder, server room
	// 	}
	// 	if (uniqueID[1] == 0x94)
	// 	{
	// 		setItemByID(*seed[148]);
	// 		// handgun bullets second, sewer entrance
	// 	}
	// 	if (uniqueID[1] == 0xDC)
	// 	{
	// 		setItemByID(*seed[186]);
	// 		// green herb, outside garbage room
	// 	}
	// }

	// if (uniqueID[0] == 0x16)
	// {
	// 	if (uniqueID[1] == 0x15)
	// 	{
	// 		setItemByID(*seed[1]);
	// 		// handgun bullets, main hall
	// 	}
	// 	if (uniqueID[1] == 0x1A)
	// 	{
	// 		setItemByID(*seed[37]);
	// 		// mechanic jack handle, records room
	// 	}
	// 	if (uniqueID[1] == 0xD8)
	// 	{
	// 		setItemByID(*seed[214]);
	// 		// Trophy, Low Temp Testing Lab, B scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x19)
	// {
	// 	setItemByID(*seed[172]);
	// 	// green herb, bottom waterway overpass
	// }

	// if (uniqueID[0] == 0x1A)
	// {
	// 	if (uniqueID[1] == 0x66)
	// 	{
	// 		setItemByID(*seed[129]);
	// 		// firing range, flame rounds, claire
	// 	}
	// 	if (uniqueID[1] == 0xC3)
	// 	{
	// 		setItemByID(*seed[147]);
	// 		// handgun bullets first, sewer entrance
	// 	}
	// }

	// if (uniqueID[0] == 0x1C)
	// {
	// 	if (uniqueID[1] == 0x9D)
	// 	{
	// 		setItemByID(*seed[235]);
	// 		// needles, bioreactors room
	// 	}
	// }

	// if (uniqueID[0] == 0x1D)
	// {
	// 	if (uniqueID[1] == 0x49)
	// 	{
	// 		setItemByID(*seed[68]);
	// 		// statue's left arm, art room
	// 	}
	// 	if (uniqueID[1] == 0xF1)
	// 	{
	// 		setItemByID(*seed[264]);
	// 		// white gunpowder, break room b scenario claire
	// 	}
	// }

	// if (uniqueID[0] == 0x1E)
	// {
	// 	if (uniqueID[1] == 0x33)
	// 	{
	// 		setItemByID(*seed[228]);
	// 		// white gunpowder, p-4 level testing lab, claire
	// 	}
	// 	if (uniqueID[1] == 0x3C)
	// 	{
	// 		setItemByID(*seed[226]);
	// 		// yellow gunpowder, biotesting lab
	// 	}
	// 	if (uniqueID[1] == 0x94)
	// 	{
	// 		setItemByID(*seed[235]);
	// 		// flamethrower fuel, bioreactors room
	// 	}
	// 	if (uniqueID[1] == 0xB5)
	// 	{
	// 		setItemByID(*seed[120]);
	// 		// square crank, jail
	// 	}
	// }

	// if (uniqueID[0] == 0x1F)
	// {
	// 	if (uniqueID[1] == 0x03)
	// 	{
	// 		setItemByID(*seed[25]);
	// 		// grenade launcher, weapons locker, claire
	// 	}
	// 	if (uniqueID[1] == 0x4D)
	// 	{
	// 		setItemByID(*seed[247]);
	// 		// joint plug, Escape Shaft
	// 	}
	// 	if (uniqueID[1] == 0xEF)
	// 	{
	// 		setItemByID(*seed[93]);
	// 		// handgun bullets, interrogation room
	// 	}
	// 	if (uniqueID[1] == 0xFE)
	// 	{
	// 		setItemByID(*seed[125]);
	// 		// red herb, morgue
	// 	}
	// }

	// if (uniqueID[0] == 0x20)
	// {
	// 	if (uniqueID[1] == 0x46)
	// 	{
	// 		setItemByID(*seed[251]);
	// 		// flame rounds, STARS office, claire
	// 	}
	// 	if (uniqueID[1] == 0xA8)
	// 	{
	// 		setItemByID(*seed[134]);
	// 		// green herb, basketball court
	// 	}
	// }

	// if (uniqueID[0] == 0x21)
	// {
	// 	if (uniqueID[1] == 0x17)
	// 	{
	// 		setItemByID(*seed[194]);
	// 		// ACP Ammo, Cafeteria, B Scenario
	// 	}
	// 	if (uniqueID[1] == 0x7A)
	// 	{
	// 		setItemByID(*seed[158]);
	// 		// yellow gunpowder, water injection chamber
	// 	}
	// }

	// if (uniqueID[0] == 0x22)
	// {
	// 	if (uniqueID[1] == 0x7F)
	// 	{
	// 		setItemByID(*seed[92]);
	// 		// portable safe, observation room, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x23)
	// {
	// 	setItemByID(*seed[119]);
	// 	// handgun bullets, jail entrance
	// }

	// if (uniqueID[0] == 0x24)
	// {
	// 	if (uniqueID[1] == 0x04)
	// 	{
	// 		setItemByID(*seed[98]);
	// 		// flash grenade, STARS office
	// 	}
	// 	if (uniqueID[1] == 0x9C)
	// 	{
	// 		setItemByID(*seed[72]);
	// 		// bolt cutters, outside fire escape, b scenario
	// 	}
	// 	if (uniqueID[1] == 0x97)
	// 	{
	// 		setItemByID(*seed[140]);
	// 		// relief, private collection room
	// 	}
	// 	if (uniqueID[1] == 0xF0)
	// 	{
	// 		setItemByID(*seed[100]);
	// 		// white gunpowder, STARS office, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x25)
	// {
	// 	if (uniqueID[1] == 0x36)
	// 	{
	// 		setItemByID(*seed[174]);
	// 		// green herb, bottom waterway
	// 	}
	// 	if (uniqueID[1] == 0xF0)
	// 	{
	// 		setItemByID(*seed[85]);
	// 		// red herb, roof area
	// 	}
	// }

	// if (uniqueID[0] == 0x26)
	// {
	// 	if (uniqueID[1] == 0x27)
	// 	{
	// 		setItemByID(*seed[155]);
	// 		// sls ammo, RPD access room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x27)
	// {
	// 	if (uniqueID[1] == 0x8C)
	// 	{
	// 		setItemByID(*seed[47]);
	// 		// ACP ammo, western area 2F, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x29)
	// {
	// 	if (uniqueID[1] == 0x0C)
	// 	{
	// 		setItemByID(*seed[251]);
	// 		// shotgun shells, stars office
	// 	}
	// 	if (uniqueID[1] == 0x89)
	// 	{
	// 		setItemByID(*seed[150]);
	// 		// shotgun shells, upper walkway
	// 	}
	// 	if (uniqueID[1] == 0x94)
	// 	{
	// 		setItemByID(*seed[50]);
	// 		// flame rounds, valve room, not in locker, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x2A)
	// {
	// 	setItemByID(*seed[81]);
	// 	// flash grenade, east area 3F
	// }

	// if (uniqueID[0] == 0x2B)
	// {
	// 	setItemByID(*seed[215]);
	// 	// green herb, Lounge
	// }

	// if (uniqueID[0] == 0x2C)
	// {
	// 	setItemByID(*seed[42]);
	// 	// valve, east office
	// }

	// if (uniqueID[0] == 0x2D)
	// {
	// 	setItemByID(*seed[97]);
	// 	// red herb, STARS office
	// }

	// if (uniqueID[0] == 0x2E)
	// {
	// 	if (uniqueID[1] == 0x00)
	// 	{
	// 		setItemByID(*seed[92]);
	// 		// portable safe claire b scenario interrogation room
	// 	}
	// }

	// if (uniqueID[0] == 0x2F)
	// {
	// 	if (uniqueID[1] == 0x26)
	// 	{
	// 		setItemByID(*seed[24]);
	// 		// shotgun shells (locker), safety deposit room
	// 	}
	// 	if (uniqueID[1] == 0x30)
	// 	{
	// 		setItemByID(*seed[233]);
	// 		// mag ammo, bioreactors room
	// 	}
	// }

	// if (uniqueID[0] == 0x30)
	// {
	// 	if (uniqueID[1] == 0x1F)
	// 	{
	// 		setItemByID(*seed[55]);
	// 		// gunpowder, west storage room
	// 	}
	// 	if (uniqueID[1] == 0xC9)
	// 	{
	// 		setItemByID(*seed[21]);
	// 		// combat knife, safety deposit room
	// 	}
	// 	if (uniqueID[1] == 0xFE)
	// 	{
	// 		setItemByID(*seed[230]);
	// 		// handgun bullets (top left), bioreactor's room, B scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x31)
	// {
	// 	setItemByID(*seed[171]);
	// 	// sewer key, bottom way overpass
	// }

	// if (uniqueID[0] == 0x32)
	// {
	// 	if (uniqueID[1] == 0x15)
	// 	{
	// 		setItemByID(*seed[6]);
	// 		// ACP ammo, reception, B scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x33)
	// {
	// 	if (uniqueID[1] == 0xBF)
	// 	{
	// 		setItemByID(*seed[188]);
	// 		// submachinegun ammo, g2 fight, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x34)
	// {
	// 	if (uniqueID[1] == 0xDC)
	// 	{
	// 		setItemByID(*seed[246]);
	// 		// submachinegun ammo, orphanage, claire
	// 	}
	// 	if (uniqueID[1] == 0xFD)
	// 	{
	// 		setItemByID(*seed[18]);
	// 		// red herb, dark room
	// 	}
	// }

	// if (uniqueID[0] == 0x36)
	// {
	// 	setItemByID(*seed[245]);
	// 	// red herb, escape shaft
	// }

	// if (uniqueID[0] == 0x38)
	// {
	// 	if (uniqueID[1] == 0x15)
	// 	{
	// 		setItemByID(*seed[48]);
	// 		// red herb, western area 2F
	// 	}
	// 	if (uniqueID[1] == 0x92)
	// 	{
	// 		setItemByID(*seed[86]);
	// 		// green herb (left), roof area
	// 	}
	// 	if (uniqueID[1] == 0xE0)
	// 	{
	// 		setItemByID(*seed[161]);
	// 		// flame rounds, control room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x3A)
	// {
	// 	if (uniqueID[1] == 0x64)
	// 	{
	// 		setItemByID(*seed[161]);
	// 		// shotgun shells, control room
	// 	}
	// 	if (uniqueID[1] == 0xA4)
	// 	{
	// 		setItemByID(*seed[82]);
	// 		// wooden boards, east area 3F
	// 	}
	// }

	// if (uniqueID[0] == 0x3C)
	// {
	// 	if (uniqueID[1] == 0x22)
	// 	{
	// 		setItemByID(*seed[179]);
	// 		// King Plug, supplies storage room
	// 	}
	// 	if (uniqueID[1] == 0x3C)
	// 	{
	// 		setItemByID(*seed[229]);
	// 		// Red Herb, P-4 Level Testing Lab
	// 	}
	// 	if (uniqueID[1] == 0x84)
	// 	{
	// 		setItemByID(*seed[17]);
	// 		// Handgun Bullets, dark room
	// 	}
	// 	if (uniqueID[1] == 0x8D)
	// 	{
	// 		setItemByID(*seed[90]);
	// 		// white gunpowder, outside observation room, claire
	// 	}
	// 	if (uniqueID[1] == 0x98)
	// 	{
	// 		setItemByID(*seed[61]);
	// 		// Knife, Library
	// 	}
	// }

	// if (uniqueID[0] == 0x3D)
	// {
	// 	if (uniqueID[1] == 0x1B)
	// 	{
	// 		setItemByID(*seed[208]);
	// 		// blue herb, greenhouse
	// 	}
	// 	if (uniqueID[1] == 0x5D)
	// 	{
	// 		setItemByID(*seed[31]);
	// 		// detonator (no battery), detonator room
	// 	}
	// }

	// if (uniqueID[0] == 0x40)
	// {
	// 	if (uniqueID[1] == 0x8C)
	// 	{
	// 		setItemByID(*seed[77]);
	// 		// blue herb, east storage room
	// 	}
	// 	if (uniqueID[1] == 0xB5)
	// 	{
	// 		setItemByID(*seed[129]);
	// 		// shotgun shells, firing range
	// 	}
	// 	if (uniqueID[1] == 0xF7)
	// 	{
	// 		setItemByID(*seed[233]);
	// 		// sls rounds, bioreactor's room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x43)
	// {
	// 	if (uniqueID[1] == 0x60)
	// 	{
	// 		setItemByID(*seed[126]);
	// 		// flash grenade, morgue
	// 	}
	// 	if (uniqueID[1] == 0x6F)
	// 	{
	// 		setItemByID(*seed[180]);
	// 		// spark shot, claire
	// 	}
	// 	if (uniqueID[1] == 0x6B)
	// 	{
	// 		// repickup of stars badge in the computer is here, 43 6B
	// 		debug_continueFromBreakpoint(co_run);
	// 	}
	// 	if (uniqueID[1] == 0x82)
	// 	{
	// 		setItemByID(*seed[185]);
	// 		// blue herb, outside garbage room
	// 	}
	// 	if (uniqueID[1] == 0x85)
	// 	{
	// 		setItemByID(*seed[123]);
	// 		// blue herb, outside kennel
	// 	}
	// }

	// if (uniqueID[0] == 0x44)
	// {
	// 	if (uniqueID[1] == 0x4E)
	// 	{
	// 		setItemByID(*seed[106]);
	// 		// Hand Grenade, underground stairs
	// 	}
	// 	if (uniqueID[1] == 0x9D)
	// 	{
	// 		setItemByID(*seed[76]);
	// 		// boxed electronic part, Clock Tower
	// 	}
	// }

	// if (uniqueID[0] == 0x45)
	// {
	// 	setItemByID(*seed[63]);
	// 	// gunpowder, lounge
	// }

	// if (uniqueID[0] == 0x46)
	// {
	// 	setItemByID(*seed[165]);
	// 	// Knight piece, monitor room
	// }

	// if (uniqueID[0] == 0x47)
	// {
	// 	if (uniqueID[1] == 0xB4)
	// 	{
	// 		setItemByID(*seed[192]);
	// 		// flame rounds, security room, claire
	// 	}
	// 	if (uniqueID[1] == 0xF4)
	// 	{
	// 		setItemByID(*seed[144]);
	// 		// handgun bullets, gun shop
	// 	}
	// }

	// if (uniqueID[0] == 0x48)
	// {
	// 	if (uniqueID[1] == 0x20)
	// 	{
	// 		setItemByID(*seed[108]);
	// 		// Handgun Bullets (Top Left), Machinery Room
	// 	}
	// 	if (uniqueID[1] == 0x50)
	// 	{
	// 		setItemByID(*seed[222]);
	// 		// Signal Modulator, Modulator Room
	// 	}
	// }

	// if (uniqueID[0] == 0x49)
	// {
	// 	if (uniqueID[1] == 0xD6)
	// 	{
	// 		setItemByID(*seed[162]);
	// 		// submachinegun ammo, control room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x4A)
	// {
	// 	if (uniqueID[1] == 0xCB)
	// 	{
	// 		setItemByID(*seed[120]);
	// 		// turntable minigun, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x4C)
	// {
	// 	if (uniqueID[1] == 0x13)
	// 	{
	// 		setItemByID(*seed[28]);
	// 		// handgun bullets, east closet ambush
	// 	}
	// 	if (uniqueID[1] == 0x33)
	// 	{
	// 		setItemByID(*seed[241]);
	// 		// combat knife, monitor room
	// 	}
	// }

	// if (uniqueID[0] == 0x4E)
	// {
	// 	if (uniqueID[1] == 0x10)
	// 	{
	// 		setItemByID(*seed[191]);
	// 		// knife, g2 fight room
	// 	}
	// 	if (uniqueID[1] == 0x28)
	// 	{
	// 		setItemByID(*seed[111]);
	// 		// red herb, machinery room
	// 	}
	// 	if (uniqueID[1] == 0x2B)
	// 	{
	// 		setItemByID(*seed[136]);
	// 		// knife, heart room east storage, claire
	// 	}
	// 	if (uniqueID[1] == 0x75)
	// 	{
	// 		setItemByID(*seed[22]);
	// 		// gunpowder, safety deposit room
	// 	}
	// 	if (uniqueID[1] == 0x79)
	// 	{
	// 		setItemByID(*seed[200]);
	// 		// upgrade chip (general staff), nap room
	// 	}
	// }

	// if (uniqueID[0] == 0x51)
	// {
	// 	if (uniqueID[1] == 0xB4)
	// 	{
	// 		setItemByID(*seed[223]);
	// 		// lab digital video cassette, biotesting lab
	// 	}
	// 	if (uniqueID[1] == 0xF5)
	// 	{
	// 		setItemByID(*seed[134]);
	// 		// gunpowder, generator room
	// 	}
	// }

	// if (uniqueID[0] == 0x52)
	// {
	// 	setItemByID(*seed[80]);
	// 	// handgun bullets, east area 3F
	// }

	// if (uniqueID[0] == 0x54)
	// {
	// 	setItemByID(*seed[20]);
	// 	// handgun bullets, safety deposit room
	// }

	// if (uniqueID[0] == 0x57)
	// {
	// 	if (uniqueID[1] == 0x6C)
	// 	{
	// 		setItemByID(*seed[259]);
	// 		// blue herb, outside fire escape, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x58)
	// {
	// 	if (uniqueID[1] == 0x25)
	// 	{
	// 		// large gear after clock tower is here, 58 25
	// 		debug_continueFromBreakpoint(co_run);
	// 	}
	// 	if (uniqueID[1] == 0x40)
	// 	{
	// 		setItemByID(*seed[170]);
	// 		// shotgun stock (w-870)
	// 	}
	// }

	// if (uniqueID[0] == 0x59)
	// {
	// 	setItemByID(*seed[35]);
	// 	// hand grenade, records room
	// }

	// if (uniqueID[0] == 0x5A)
	// {
	// 	setItemByID(*seed[153]);
	// 	// gunpowder, worker's break room
	// }

	// if (uniqueID[0] == 0x5B)
	// {
	// 	if (uniqueID[1] == 0xB4)
	// 	{
	// 		setItemByID(*seed[159]);
	// 		// white gunpowder, lower waterway
	// 	}
	// 	if (uniqueID[1] == 0xE1)
	// 	{
	// 		setItemByID(*seed[204]);
	// 		// white gunpowder, first plant room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x5C)
	// {
	// 	setItemByID(*seed[160]);
	// 	// blue herb, lower waterway
	// }

	// if (uniqueID[0] == 0x5D)
	// {
	// 	if (uniqueID[1] == 0x36)
	// 	{
	// 		setItemByID(*seed[164]);
	// 		// bishop piece, monitor room
	// 	}
	// 	if (uniqueID[1] == 0xB5)
	// 	{
	// 		setItemByID(*seed[14]);
	// 		// hip pouch, west office
	// 	}
	// 	if (uniqueID[1] == 0xFD)
	// 	{
	// 		setItemByID(*seed[99]);
	// 		// fas, stars office
	// 	}
	// }

	// if (uniqueID[0] == 0x5E)
	// {
	// 	if (uniqueID[1] == 0x3F)
	// 	{
	// 		setItemByID(*seed[1]);
	// 		// acp ammo, main hall B scenario
	// 	}
	// 	if (uniqueID[1] == 0x8B)
	// 	{
	// 		setItemByID(*seed[113]);
	// 		// green herb(bottom right), machinery room
	// 	}
	// 	if (uniqueID[1] == 0xA6)
	// 	{
	// 		setItemByID(*seed[254]);
	// 		// ink ribbon x2, interrogation room hardcore
	// 	}
	// }

	// if (uniqueID[0] == 0x5F)
	// {
	// 	if (uniqueID[1] == 0xE5)
	// 	{
	// 		if (playingas == "claire")
	// 		{
	// 			setItemByID(*seed[262]);
	// 			// knife, outside break room
	// 		}
	// 		else
	// 		{
	// 			setItemByID(*seed[136]);
	// 			// knife, outside break room
	// 		}
	// 	}
	// }

	// if (uniqueID[0] == 0x60)
	// {
	// 	if (uniqueID[1] == 0xAB)
	// 	{
	// 		setItemByID(*seed[231]);
	// 		// fas, bioreactor's room
	// 	}
	// 	if (uniqueID[1] == 0xD4)
	// 	{
	// 		setItemByID(*seed[58]);
	// 		// hip pouch, main hall, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x61)
	// {
	// 	if (uniqueID[1] == 0x7E)
	// 	{
	// 		setItemByID(*seed[49]);
	// 		// flame rounds in locker in valve room claire
	// 	}
	// 	if (uniqueID[1] == 0xD2)
	// 	{
	// 		setItemByID(*seed[92]);
	// 		// bejeweled box, interrogation room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x62)
	// {
	// 	if (uniqueID[1] == 0x05)
	// 	{
	// 		setItemByID(*seed[247]);
	// 		// turntable joint plug, claire
	// 	}
	// 	if (uniqueID[1] == 0x25)
	// 	{
	// 		setItemByID(*seed[109]);
	// 		// hand grenade, machinery room
	// 	}
	// 	if (uniqueID[1] == 0xD1)
	// 	{
	// 		setItemByID(*seed[7]);
	// 		// green herb, reception
	// 	}
	// }

	// if (uniqueID[0] == 0x65)
	// {
	// 	if (uniqueID[1] == 0x04)
	// 	{
	// 		setItemByID(*seed[202]);
	// 		// green herb, lobby
	// 	}
	// 	if (uniqueID[1] == 0xC3)
	// 	{
	// 		setItemByID(*seed[252]);
	// 		// Ink Ribbon x1, Lab Reception, Hardcore
	// 	}
	// }

	// if (uniqueID[0] == 0x66)
	// {
	// 	if (uniqueID[1] == 0x5A)
	// 	{
	// 		setItemByID(*seed[226]);
	// 		// white gunpowder, biotesting lab, claire
	// 	}
	// 	if (uniqueID[1] == 0xA6)
	// 	{
	// 		setItemByID(*seed[89]);
	// 		// shoulder stock (GM 79), elevator controls room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x68)
	// {
	// 	if (uniqueID[1] == 0xA4)
	// 	{
	// 		// A4 is ada ID wristband
	// 		debug_continueFromBreakpoint(co_run);
	// 	}
	// 	if (uniqueID[1] == 0xCF)
	// 	{
	// 		setItemByID(*seed[245]);
	// 		// turntable red herb, claire
	// 	}
	// 	if (uniqueID[1] == 0xEC)
	// 	{
	// 		setItemByID(*seed[204]);
	// 		// yellow gunpowder, first plant room
	// 	}
	// 	if (uniqueID[1] == 0xFD)
	// 	{
	// 		setItemByID(*seed[8]);
	// 		// handgun bullets, operations room
	// 	}
	// }

	// if (uniqueID[0] == 0x6B)
	// {
	// 	if (uniqueID[1] == 0x01)
	// 	{
	// 		setItemByID(*seed[149]);
	// 		// ACP Ammo, Upper Walkway, B scenario
	// 	}
	// 	if (uniqueID[1] == 0x5B)
	// 	{
	// 		setItemByID(*seed[199]);
	// 		// regulator (flamethrower), nap room
	// 	}
	// }

	// if (uniqueID[0] == 0x6C)
	// {
	// 	setItemByID(*seed[29]);
	// 	// wooden boards, east closet ambush
	// }

	// if (uniqueID[0] == 0x6D)
	// {
	// 	if (uniqueID[1] == 0xFE)
	// 	{
	// 		setItemByID(*seed[258]);
	// 		// Red Herb, Outside Fire Escape, B Scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x6E)
	// {
	// 	if (uniqueID[1] == 0x99)
	// 	{
	// 		setItemByID(*seed[105]);
	// 		// flame rounds, secret room, claire
	// 	}
	// 	if (uniqueID[1] == 0x2D)
	// 	{
	// 		setItemByID(*seed[137]);
	// 		// blue herb, outside bus, claire
	// 	}
	// 	if (uniqueID[1] == 0xDA)
	// 	{
	// 		setItemByID(*seed[243]);
	// 		// green herb, pump room
	// 	}
	// }

	// if (uniqueID[0] == 0x6F)
	// {
	// 	if (uniqueID[1] == 0xB8)
	// 	{
	// 		setItemByID(*seed[114]);
	// 		// ACP ammo (bottom right), machinery room, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x70)
	// {
	// 	if (uniqueID[1] == 0x53)
	// 	{
	// 		setItemByID(*seed[23]);
	// 		// hip pouch, safety deposit room
	// 	}
	// 	if (uniqueID[1] == 0x9F)
	// 	{
	// 		setItemByID(*seed[239]);
	// 		// ACP ammo, bottom right, right, bioreactor's room, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x71)
	// {
	// 	setItemByID(*seed[205]);
	// 	// dispersal cartridge (empty), greenhouse control room
	// }

	// if (uniqueID[0] == 0x72)
	// {
	// 	if (uniqueID[1] == 0xC6)
	// 	{
	// 		setItemByID(*seed[192]);
	// 		// shotgun that spawns at lab if you don't pick it up
	// 	}
	// 	if (uniqueID[1] == 0x5E)
	// 	{
	// 		setItemByID(*seed[131]);
	// 		// red herb, firing range lockers
	// 	}
	// 	if (uniqueID[1] == 0x93)
	// 	{
	// 		setItemByID(*seed[53]);
	// 		// mag ammo, western area 3F
	// 	}
	// }

	// if (uniqueID[0] == 0x73)
	// {
	// 	if (uniqueID[1] == 0x30)
	// 	{
	// 		setItemByID(*seed[211]);
	// 		// hand grenade, drug testing lab
	// 	}
	// 	if (uniqueID[1] == 0x44)
	// 	{
	// 		setItemByID(*seed[23]);
	// 		// hip pouch, safety deposit room
	// 	}
	// }

	// if (uniqueID[0] == 0x74)
	// {
	// 	if (uniqueID[1] == 0x24)
	// 	{
	// 		setItemByID(*seed[234]);
	// 		// flash grenade (bottom left), bioreactor's room
	// 	}
	// 	if (uniqueID[1] == 0x40)
	// 	{
	// 		setItemByID(*seed[104]);
	// 		// ink ribbon, secret room hardcore
	// 	}
	// }

	// if (uniqueID[0] == 0x75)
	// {
	// 	setItemByID(*seed[149]);
	// 	// handgun bullets, upper walkway
	// }

	// if (uniqueID[0] == 0x76)
	// {
	// 	setItemByID(*seed[118]);
	// 	// gun stock (matilda), parking garage
	// }

	// if (uniqueID[0] == 0x78)
	// {
	// 	setItemByID(*seed[214]);
	// 	// trophy, lounge
	// }

	// if (uniqueID[0] == 0x79)
	// {
	// 	if (uniqueID[1] == 0x2C)
	// 	{
	// 		setItemByID(*seed[116]);
	// 		// green herb (up ladder), machinery room
	// 	}
	// 	if (uniqueID[1] == 0xC1)
	// 	{
	// 		setItemByID(*seed[19]);
	// 		// film commemorative, claire
	// 	}
	// 	if (uniqueID[1] == 0x77)
	// 	{
	// 		setItemByID(*seed[246]);
	// 		// handgun bullets, escape shaft
	// 	}
	// 	if (uniqueID[1] == 0xAD)
	// 	{
	// 		setItemByID(*seed[188]);
	// 		// mag ammo, G2 fight room
	// 	}
	// 	if (uniqueID[1] == 0xD3)
	// 	{
	// 		setItemByID(*seed[182]);
	// 		// film - hiding place, workroom
	// 	}
	// }

	// if (uniqueID[0] == 0x7A)
	// {
	// 	if (uniqueID[1] == 0x02)
	// 	{
	// 		setItemByID(*seed[225]);
	// 		// blue herb, biotesting lab
	// 	}
	// 	if (uniqueID[1] == 0x58)
	// 	{
	// 		setItemByID(*seed[87]);
	// 		// green herb(right), roof area
	// 	}
	// }

	// if (uniqueID[0] == 0x7B)
	// {
	// 	if (uniqueID[1] == 0x00)
	// 	{
	// 		setItemByID(*seed[53]);
	// 		// submachinegun ammo, western area 3F
	// 	}
	// 	if (uniqueID[1] == 0x8E)
	// 	{
	// 		setItemByID(*seed[88]);
	// 		// blue herb, elevator controls room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x7C)
	// {
	// 	if (uniqueID[1] == 0x24)
	// 	{
	// 		setItemByID(*seed[41]);
	// 		// gunpowder, east office
	// 	}
	// 	if (uniqueID[1] == 0xB9)
	// 	{
	// 		setItemByID(*seed[141]);
	// 		// white gunpowder, private collection room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x7D)
	// {
	// 	if (uniqueID[1] == 0x09)
	// 	{
	// 		setItemByID(*seed[143]);
	// 		// hand grenade, gun shop
	// 	}
	// 	if (uniqueID[1] == 0x9C)
	// 	{
	// 		setItemByID(*seed[93]);
	// 		// ACP ammo, interrogation room, b scenario
	// 	}
	// 	if (uniqueID[1] == 0xB3)
	// 	{
	// 		setItemByID(*seed[32]);
	// 		// green herb, detonator room
	// 	}
	// }

	// if (uniqueID[0] == 0x7F)
	// {
	// 	if (uniqueID[1] == 0x0B)
	// 	{
	// 		setItemByID(*seed[180]);
	// 		// flamethrower, supplies storage room
	// 	}
	// 	if (uniqueID[1] == 0x8F)
	// 	{
	// 		setItemByID(*seed[45]);
	// 		// green herb, waiting room
	// 	}
	// }

	// if (uniqueID[0] == 0x80)
	// {
	// 	if (uniqueID[1] == 0x7F)
	// 	{
	// 		setItemByID(*seed[105]);
	// 		// shotgun shells, secret room
	// 	}
	// 	if (uniqueID[1] == 0xCC)
	// 	{
	// 		setItemByID(*seed[13]);
	// 		// handgun bullets, west office
	// 	}
	// 	if (uniqueID[1] == 0xF4)
	// 	{
	// 		setItemByID(*seed[43]);
	// 		// white gunpowder, east office, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x81)
	// {
	// 	setItemByID(*seed[232]);
	// 	// handgun bullets (bottom left), bioreactors room
	// }

	// if (uniqueID[0] == 0x83)
	// {
	// 	setItemByID(*seed[114]);
	// 	// handgun bullets (bottom right), machinery room
	// }

	// if (uniqueID[0] == 0x84)
	// {
	// 	setItemByID(*seed[168]);
	// 	// t-bar valve, treatment pool room
	// }

	// if (uniqueID[0] == 0x85)
	// {
	// 	// 1C is ada item
	// 	if (uniqueID[1] == 0x1C)
	// 	{
	// 		// flamethrower every time
	// 		setItemByID("268");
	// 	}
	// 	if (uniqueID[1] == 0xF8)
	// 	{
	// 		setItemByID(*seed[177]);
	// 		// blue herb, supplies storage room
	// 	}
	// }

	// if (uniqueID[0] == 0x86)
	// {
	// 	setItemByID(*seed[34]);
	// 	// wooden boards, detonator room
	// }

	// if (uniqueID[0] == 0x87)
	// {
	// 	if (uniqueID[1] == 0x90)
	// 	{
	// 		setItemByID(*seed[30]);
	// 		// fas, bathroom
	// 	}
	// 	if (uniqueID[1] == 0xB9)
	// 	{
	// 		setItemByID(*seed[121]);
	// 		// parking garage key card, jail
	// 	}
	// }

	// if (uniqueID[0] == 0x88)
	// {
	// 	if (uniqueID[1] == 0x5A)
	// 	{
	// 		setItemByID(*seed[244]);
	// 		// handgun bullets, pump room
	// 	}
	// 	if (uniqueID[1] == 0x82)
	// 	{
	// 		setItemByID(*seed[44]);
	// 		// fuse (main hall), east office
	// 	}
	// 	if (uniqueID[1] == 0xC9)
	// 	{
	// 		setItemByID(*seed[213]);
	// 		// flame rounds, lounge, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x8A)
	// {
	// 	if (uniqueID[1] == 0xEF)
	// 	{
	// 		setItemByID(*seed[24]);
	// 		// flame rounds in locker 208
	// 	}
	// }

	// if (uniqueID[0] == 0x8B)
	// {
	// 	if (uniqueID[1] == 0xAF)
	// 	{
	// 		setItemByID(*seed[237]);
	// 		// flash grenade (top right), bioreactors room
	// 	}
	// }

	// if (uniqueID[0] == 0x8C)
	// {
	// 	setItemByID(*seed[66]);
	// 	// green herb, chopper crash area
	// }

	// if (uniqueID[0] == 0x8D)
	// {
	// 	if (uniqueID[1] == 0x74)
	// 	{
	// 		setItemByID(*seed[249]);
	// 		// wooden box, stars office, claire
	// 	}
	// 	if (uniqueID[1] == 0x8B)
	// 	{
	// 		setItemByID(*seed[60]);
	// 		// handgun bullets, library
	// 	}
	// }

	// if (uniqueID[0] == 0x8E)
	// {
	// 	if (uniqueID[1] == 0x1C)
	// 	{
	// 		setItemByID(*seed[216]);
	// 		// flame rounds, server room, claire
	// 	}
	// 	if (uniqueID[1] == 0xF6)
	// 	{
	// 		setItemByID(*seed[148]);
	// 		// ACP Ammo (second), Sewer Entrance, Leon B Scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x8F)
	// {
	// 	if (uniqueID[1] == 0x35)
	// 	{
	// 		if (playingas == "claire")
	// 		{
	// 			setItemByID(*seed[263]);
	// 			// blue herb, break room claire b scenario
	// 		}
	// 		else
	// 		{
	// 			setItemByID(*seed[137]);
	// 			// blue herb, break room
	// 		}
	// 	}
	// 	if (uniqueID[1] == 0xB4)
	// 	{
	// 		setItemByID(*seed[57]);
	// 		// handgun bullets, west storage room
	// 	}
	// 	if (uniqueID[1] == 0xED)
	// 	{
	// 		setItemByID(*seed[130]);
	// 		// film 3F locker, firing range lockers
	// 	}
	// 	if (uniqueID[1] == 0xFF)
	// 	{
	// 		setItemByID(*seed[107]);
	// 		// suppressor, underground stairs, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x90)
	// {
	// 	if (uniqueID[1] == 0x81)
	// 	{
	// 		setItemByID(*seed[162]);
	// 		// mag ammo, control room
	// 	}
	// 	if (uniqueID[1] == 0x9B)
	// 	{
	// 		setItemByID(*seed[176]);
	// 		// red herb, supplies storage room
	// 	}
	// }

	// if (uniqueID[0] == 0x91)
	// {
	// 	// 52 is ada item
	// 	if (uniqueID[1] == 0x52)
	// 	{
	// 		// yellow gunpowder every time
	// 		setItemByID("302");
	// 	}
	// 	if (uniqueID[1] == 0x87)
	// 	{
	// 		setItemByID(*seed[154]);
	// 		// handgun bullets
	// 	}
	// 	if (uniqueID[1] == 0xC1)
	// 	{
	// 		setItemByID(*seed[57]);
	// 		// acp ammo, west storage room, b scenario
	// 	}
	// 	if (uniqueID[1] == 0xF6)
	// 	{
	// 		setItemByID(*seed[75]);
	// 		// small gear
	// 	}
	// }

	// if (uniqueID[0] == 0x93)
	// {
	// 	if (uniqueID[1] == 0x58)
	// 	{
	// 		setItemByID(*seed[21]);
	// 		// combat knife, locker 103, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x94)
	// {
	// 	if (uniqueID[1] == 0x0C)
	// 	{
	// 		setItemByID(*seed[183]);
	// 		// handgun bullets, workroom
	// 	}
	// 	if (uniqueID[1] == 0x67)
	// 	{
	// 		setItemByID(*seed[63]);
	// 		// lion statue film, lounge, b scenario
	// 	}
	// 	if (uniqueID[1] == 0x85)
	// 	{
	// 		setItemByID(*seed[60]);
	// 		// ACP ammo, library, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x95)
	// {
	// 	if (uniqueID[1] == 0x9F)
	// 	{
	// 		setItemByID(*seed[5]);
	// 		// M19, guard room, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x96)
	// {
	// 	if (uniqueID[1] == 0x2A)
	// 	{
	// 		setItemByID(*seed[89]);
	// 		// club key, boiler room
	// 	}
	// 	if (uniqueID[1] == 0x61)
	// 	{
	// 		setItemByID(*seed[193]);
	// 		// hand grenade, cafeteria
	// 	}
	// }

	// if (uniqueID[0] == 0x97)
	// {
	// 	if (uniqueID[1] == 0xDD)
	// 	{
	// 		// DD is king in sewer after final placement
	// 		debug_continueFromBreakpoint(co_run);
	// 	}
	// 	if (uniqueID[1] == 0xDE)
	// 	{
	// 		setItemByID(*seed[103]);
	// 		// gunpowder, linen room
	// 	}
	// }

	// if (uniqueID[0] == 0x98)
	// {
	// 	if (uniqueID[1] == 0x69)
	// 	{
	// 		// nice
	// 		setItemByID(*seed[20]);
	// 		// ACP Ammo, Safety deposit room, B scenario
	// 	}
	// 	if (uniqueID[1] == 0x8E)
	// 	{
	// 		setItemByID(*seed[239]);
	// 		// handgun bullets (bottom right, right), bioreactors room
	// 	}
	// }

	// if (uniqueID[0] == 0x99)
	// {
	// 	if (uniqueID[1] == 0x5A)
	// 	{
	// 		setItemByID(*seed[70]);
	// 		// ACP ammo, fire escape, b scenario
	// 	}
	// 	if (uniqueID[1] == 0x5F)
	// 	{
	// 		setItemByID(*seed[210]);
	// 		// large gunpowder, drug testing lab
	// 	}
	// }

	// if (uniqueID[0] == 0x9A)
	// {
	// 	if (uniqueID[1] == 0x15)
	// 	{
	// 		setItemByID(*seed[69]);
	// 		// scepter, art room
	// 	}
	// 	if (uniqueID[1] == 0x4D)
	// 	{
	// 		setItemByID(*seed[15]);
	// 		// speed loader for claire
	// 	}
	// 	if (uniqueID[1] == 0x7A)
	// 	{
	// 		setItemByID(*seed[65]);
	// 		// wooden boards, chopper crash area
	// 	}
	// 	if (uniqueID[1] == 0x86)
	// 	{
	// 		setItemByID(*seed[198]);
	// 		// flame rounds, nap room, claire
	// 	}
	// 	if (uniqueID[1] == 0x93)
	// 	{
	// 		setItemByID(*seed[91]);
	// 		// gunpowder, observation room
	// 	}
	// }

	// if (uniqueID[0] == 0x9B)
	// {
	// 	if (uniqueID[1] == 0x09)
	// 	{
	// 		setItemByID(*seed[67]);
	// 		// weapons locker key, art room
	// 	}
	// 	if (uniqueID[1] == 0x14)
	// 	{
	// 		setItemByID(*seed[169]);
	// 		// blue herb, treatment pool room
	// 	}
	// 	if (uniqueID[1] == 0x61)
	// 	{
	// 		setItemByID(*seed[110]);
	// 		// green herb (top left), machinery room
	// 	}
	// }

	// if (uniqueID[0] == 0x9C)
	// {
	// 	if (uniqueID[1] == 0x13)
	// 	{
	// 		setItemByID(*seed[94]);
	// 		// gunpowder, outside stars office
	// 	}
	// 	if (uniqueID[1] == 0x24)
	// 	{
	// 		setItemByID(*seed[209]);
	// 		// upgrade chip (senior staff), greenhouse
	// 	}
	// 	if (uniqueID[1] == 0x95)
	// 	{
	// 		setItemByID(*seed[145]);
	// 		// long barrel (w-870), gun shop
	// 	}
	// 	if (uniqueID[1] == 0xA6)
	// 	{
	// 		setItemByID(*seed[195]);
	// 		// needle cartridges, cafeteria, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x9D)
	// {
	// 	if (uniqueID[1] == 0x65)
	// 	{
	// 		setItemByID(*seed[40]);
	// 		// east office, acp ammo, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0x9E)
	// {
	// 	if (uniqueID[1] == 0x31)
	// 	{
	// 		setItemByID(*seed[118]);
	// 		// JMB Hp3 car boot, claire
	// 	}
	// }

	// if (uniqueID[0] == 0x9F)
	// {
	// 	if (uniqueID[1] == 0x85)
	// 	{
	// 		setItemByID(*seed[144]);
	// 		// ACP Ammo, Gun Shop, Leon B scenario
	// 	}
	// 	if (uniqueID[1] == 0xC7)
	// 	{
	// 		setItemByID(*seed[28]);
	// 		// ACP Ammo, east closet ambush b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0xA0)
	// {
	// 	if (uniqueID[1] == 0x0F)
	// 	{
	// 		setItemByID(*seed[224]);
	// 		// hand grenade, biotesting lab
	// 	}
	// }

	// if (uniqueID[0] == 0xA1)
	// {
	// 	if (uniqueID[1] == 0x17)
	// 	{
	// 		setItemByID(*seed[107]);
	// 		// long barrel (lightning hawk), underground stairs
	// 	}
	// 	if (uniqueID[1] == 0x8E)
	// 	{
	// 		setItemByID(*seed[4]);
	// 		// ACP ammo upstairs main hall b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0xA3)
	// {
	// 	setItemByID(*seed[104]);
	// 	// gunpowder, secret room
	// }

	// if (uniqueID[0] == 0xA4)
	// {
	// 	setItemByID(*seed[194]);
	// 	// handgun bullets, cafeteria
	// }

	// if (uniqueID[0] == 0xA5)
	// {
	// 	if (uniqueID[1] == 0x8D)
	// 	{
	// 		setItemByID(*seed[58]);
	// 		// hip pouch, west storage room
	// 	}
	// 	if (uniqueID[1] == 0xD3)
	// 	{
	// 		// repickup of stars badge in the basement is here, A5 D3
	// 		debug_continueFromBreakpoint(co_run);
	// 	}
	// }

	// if (uniqueID[0] == 0xA6)
	// {
	// 	if (uniqueID[1] == 0x22)
	// 	{
	// 		// keys in garage
	// 		debug_continueFromBreakpoint(co_run);
	// 	}
	// }

	// if (uniqueID[0] == 0xA7)
	// {
	// 	if (uniqueID[1] == 0x8C)
	// 	{
	// 		setItemByID(*seed[52]);
	// 		// ACP ammo, western area 3F, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0xA8)
	// {
	// 	setItemByID(*seed[151]);
	// 	// uss digital video cassette, rook bridge area
	// }

	// if (uniqueID[0] == 0xA9)
	// {
	// 	setItemByID(*seed[135]);
	// 	// shotgun shells, outside break room
	// }

	// if (uniqueID[0] == 0xAA)
	// {
	// 	if (uniqueID[1] == 0x5B)
	// 	{
	// 		setItemByID(*seed[78]);
	// 		// large gear, east storage room
	// 	}
	// 	if (uniqueID[1] == 0x81)
	// 	{
	// 		setItemByID(*seed[163]);
	// 		// ACP Ammo, monitor room, B Scenario
	// 	}
	// 	if (uniqueID[1] == 0x87)
	// 	{
	// 		setItemByID(*seed[1]);
	// 		// ink ribbon in main hall hardcore
	// 	}
	// }

	// if (uniqueID[0] == 0xAB)
	// {
	// 	if (uniqueID[1] == 0xA7)
	// 	{
	// 		setItemByID(*seed[240]);
	// 		// fas, monitor room
	// 	}
	// 	if (uniqueID[1] == 0xB6)
	// 	{
	// 		setItemByID(*seed[49]);
	// 		// shotgun shells, western area 2F
	// 	}
	// }

	// if (uniqueID[0] == 0xAC)
	// {
	// 	if (uniqueID[1] == 0x74)
	// 	{
	// 		setItemByID(*seed[238]);
	// 		// handgun bullets (bottom right, left), bioreactors room
	// 	}
	// 	if (uniqueID[1] == 0x3E)
	// 	{
	// 		setItemByID(*seed[184]);
	// 		// SLS ammo, workroom lift, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xAD)
	// {
	// 	if (uniqueID[1] == 0x54)
	// 	{
	// 		setItemByID(*seed[167]);
	// 		// red herb, treatment pool room
	// 	}
	// 	if (uniqueID[1] == 0x9F)
	// 	{
	// 		setItemByID(*seed[83]);
	// 		// blue herb, balcony
	// 	}
	// 	if (uniqueID[1] == 0xEC)
	// 	{
	// 		setItemByID(*seed[119]);
	// 		// ACP Ammo, Jail Entrance, B scenario Leon
	// 	}
	// }

	// if (uniqueID[0] == 0xAF)
	// {
	// 	setItemByID(*seed[175]);
	// 	// mag ammo, bottom waterway
	// }

	// if (uniqueID[0] == 0xB0)
	// {
	// 	if (uniqueID[1] == 0xC8)
	// 	{
	// 		setItemByID(*seed[256]);
	// 		// office ink ribbon after sherry, hardcore
	// 	}
	// }

	// if (uniqueID[0] == 0xB1)
	// {
	// 	if (uniqueID[1] == 0x35)
	// 	{
	// 		setItemByID(*seed[158]);
	// 		// white gunpowder, water injection chamber, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xB2)
	// {
	// 	if (uniqueID[1] == 0xC1)
	// 	{
	// 		setItemByID(*seed[227]);
	// 		// large gunpowder, p4 level testing lab
	// 	}
	// 	if (uniqueID[1] == 0xE3)
	// 	{
	// 		setItemByID(*seed[181]);
	// 		// hip pouch, workroom
	// 	}
	// }

	// if (uniqueID[0] == 0xB3)
	// {
	// 	if (uniqueID[1] == 0x71)
	// 	{
	// 		setItemByID(*seed[8]);
	// 		// ACP ammo, operations room B scenario
	// 	}
	// 	if (uniqueID[1] == 0xCA)
	// 	{
	// 		setItemByID(*seed[236]);
	// 		// hand grenade, bioreactor's room
	// 	}
	// }

	// if (uniqueID[0] == 0xB5)
	// {
	// 	if (uniqueID[1] == 0xD3)
	// 	{
	// 		setItemByID(*seed[139]);
	// 		// submachinegun ammo, basketball court, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xB6)
	// {
	// 	setItemByID(*seed[47]);
	// 	// handgun bullets, western area 2F
	// }

	// if (uniqueID[0] == 0xB7)
	// {
	// 	if (uniqueID[1] == 0xBF)
	// 	{
	// 		setItemByID(*seed[222]);
	// 		// signal modulator, lab main shaft, b scenario
	// 	}
	// 	if (uniqueID[1] == 0xD0)
	// 	{
	// 		setItemByID(*seed[133]);
	// 		// boxed electronic part, east storage, claire only
	// 	}
	// }

	// if (uniqueID[0] == 0xBB)
	// {
	// 	// A2 is ada item
	// 	if (uniqueID[1] == 0xA2)
	// 	{
	// 		// white gunpowder every time
	// 		setItemByID("304");
	// 	}
	// 	if (uniqueID[1] == 0x6F)
	// 	{
	// 		setItemByID(*seed[124]);
	// 		// yellow gunpowder, kennel
	// 	}
	// 	if (uniqueID[1] == 0x82)
	// 	{
	// 		setItemByID(*seed[108]);
	// 		// ACP ammo (top left), machinery room, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0xBC)
	// {
	// 	setItemByID(*seed[43]);
	// 	// yellow gunpowder, east office
	// }

	// if (uniqueID[0] == 0xBD)
	// {
	// 	if (uniqueID[1] == 0x16)
	// 	{
	// 		setItemByID(*seed[147]);
	// 		// ACP Ammo (first), Sewer Entrance, b scenario Leon
	// 	}
	// }

	// if (uniqueID[0] == 0xBE)
	// {
	// 	if (uniqueID[1] == 0x51)
	// 	{
	// 		setItemByID(*seed[26]);
	// 		// flame rounds in weapons locker, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xBF)
	// {
	// 	if (uniqueID[1] == 0x38)
	// 	{
	// 		setItemByID(*seed[56]);
	// 		// wooden boards, west storage room
	// 	}
	// 	if (uniqueID[1] == 0xE4)
	// 	{
	// 		setItemByID(*seed[4]);
	// 		// handgun bullets (upstairs), main hall
	// 	}
	// }

	// if (uniqueID[0] == 0xC1)
	// {
	// 	setItemByID(*seed[19]);
	// 	// film: commemorative, safety deposit room
	// }

	// if (uniqueID[0] == 0xC2)
	// {
	// 	if (uniqueID[1] == 0x5E)
	// 	{
	// 		setItemByID(*seed[3]);
	// 		// lion medal, main hall
	// 	}
	// 	if (uniqueID[1] == 0xFB)
	// 	{
	// 		setItemByID(*seed[148]);
	// 		// ink ribbon x2
	// 	}
	// }

	// if (uniqueID[0] == 0xC4)
	// {
	// 	if (uniqueID[1] == 0x80)
	// 	{
	// 		setItemByID(*seed[70]);
	// 		// handgun bullets, fire escape
	// 	}
	// 	if (uniqueID[1] == 0xC0)
	// 	{
	// 		setItemByID(*seed[166]);
	// 		// pawn piece, monitor room
	// 	}
	// 	if (uniqueID[1] == 0xCD)
	// 	{
	// 		setItemByID(*seed[22]);
	// 		// gunpowder in 102 locker, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xC5)
	// {
	// 	if (uniqueID[1] == 0xAC)
	// 	{
	// 		setItemByID(*seed[158]);
	// 		// Ink ribbon x2, water injection chamber, hardcore
	// 	}
	// }

	// if (uniqueID[0] == 0xC6)
	// {
	// 	if (uniqueID[1] == 0x19)
	// 	{
	// 		setItemByID(*seed[189]);
	// 		// ACP Ammo, G2 Fight Room, B scenario
	// 	}
	// 	if (uniqueID[1] == 0x1D)
	// 	{
	// 		setItemByID(*seed[84]);
	// 		// ACP Ammo, Roof Area, B scenario
	// 	}
	// 	if (uniqueID[1] == 0xA4)
	// 	{
	// 		setItemByID(*seed[112]);
	// 		// handgun bullets (bottom left), machinery room
	// 	}
	// 	if (uniqueID[1] == 0xBC)
	// 	{
	// 		setItemByID(*seed[249]);
	// 		// wooden box, stars office
	// 	}
	// 	if (uniqueID[1] == 0xCB)
	// 	{
	// 		setItemByID(*seed[173]);
	// 		// hand grenade, bottom waterway overpass
	// 	}
	// }

	// if (uniqueID[0] == 0xC7)
	// {
	// 	if (uniqueID[1] == 0x7D)
	// 	{
	// 		setItemByID(*seed[219]);
	// 		// gunpowder, low-temp testing lab
	// 	}
	// 	if (uniqueID[1] == 0xF4)
	// 	{
	// 		setItemByID(*seed[141]);
	// 		// yellow gunpowder, break room
	// 	}
	// }

	// if (uniqueID[0] == 0xC8)
	// {
	// 	if (uniqueID[1] == 0x1A)
	// 	{
	// 		setItemByID(*seed[51]);
	// 		// portable safe, western area 2F
	// 	}
	// 	if (uniqueID[1] == 0xE5)
	// 	{
	// 		setItemByID(*seed[95]);
	// 		// flame rounds outside stars office, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xC9)
	// {
	// 	if (uniqueID[1] == 0xBE)
	// 	{
	// 		setItemByID(*seed[199]);
	// 		// high voltage condenser, nap room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xCA)
	// {
	// 	if (uniqueID[1] == 0x96)
	// 	{
	// 		setItemByID(*seed[124]);
	// 		// white gunpowder, kennel, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xCC)
	// {
	// 	if (uniqueID[1] == 0xEE)
	// 	{
	// 		setItemByID(*seed[132]);
	// 		// green herb, path to chief's office, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xCD)
	// {
	// 	setItemByID(*seed[95]);
	// 	// shotgun shells, outside stars office
	// }

	// if (uniqueID[0] == 0xCE)
	// {
	// 	if (uniqueID[1] == 0x56)
	// 	{
	// 		setItemByID(*seed[101]);
	// 		// mq11, stars office, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xCF)
	// {
	// 	if (uniqueID[1] == 0x29)
	// 	{
	// 		setItemByID(*seed[190]);
	// 		// flash grenade, g2 fight room
	// 	}
	// 	if (uniqueID[1] == 0x68)
	// 	{
	// 		setItemByID(*seed[141]);
	// 		// Ink ribbon x1, private collection room hardcore claire
	// 	}
	// 	if (uniqueID[1] == 0x8E)
	// 	{
	// 		// 8E is final rocket launcher
	// 		debug_continueFromBreakpoint(co_run);
	// 	}
	// 	if (uniqueID[1] == 0x9E)
	// 	{
	// 		setItemByID(*seed[132]);
	// 		// green herb, generator room
	// 	}
	// 	if (uniqueID[1] == 0xB0)
	// 	{
	// 		setItemByID(*seed[64]);
	// 		// unicorn medallion, lounge
	// 	}
	// }

	// if (uniqueID[0] == 0xD1)
	// {
	// 	setItemByID(*seed[59]);
	// 	// maiden medallion
	// }

	// if (uniqueID[0] == 0xD3)
	// {
	// 	setItemByID(*seed[122]);
	// 	// fas, jail
	// }

	// if (uniqueID[0] == 0xD4)
	// {
	// 	if (uniqueID[1] == 0x24)
	// 	{
	// 		setItemByID(*seed[6]);
	// 		// handgun bullets, reception
	// 	}
	// 	if (uniqueID[1] == 0x27)
	// 	{
	// 		setItemByID(*seed[184]);
	// 		// shotgun shells, workroom lift
	// 	}
	// 	if (uniqueID[1] == 0x46)
	// 	{
	// 		setItemByID(*seed[117]);
	// 		// hip pouch, operators room
	// 	}
	// 	if (uniqueID[1] == 0x98)
	// 	{
	// 		setItemByID(*seed[25]);
	// 		// shotgun, safety deposit room
	// 	}
	// 	if (uniqueID[1] == 0xC3)
	// 	{
	// 		if (playingas == "claire")
	// 		{
	// 			setItemByID(*seed[265]);
	// 			// acp ammo, break room claire B
	// 		}
	// 		else
	// 		{
	// 			setItemByID(*seed[138]);
	// 			// handgun bullets, break room
	// 		}
	// 	}
	// 	if (uniqueID[1] == 0xEE)
	// 	{
	// 		setItemByID(*seed[72]);
	// 		// bolt cutters, fire escape
	// 	}
	// }

	// if (uniqueID[0] == 0xD5)
	// {
	// 	setItemByID(*seed[50]);
	// 	// shotgun shells, western area 2F
	// }

	// if (uniqueID[0] == 0xD6)
	// {
	// 	if (uniqueID[1] == 0x9A)
	// 	{
	// 		setItemByID(*seed[112]);
	// 		// ACP ammo (bottom left), machinery room, b scenario
	// 	}
	// 	if (uniqueID[1] == 0xBB)
	// 	{
	// 		setItemByID(*seed[119]);
	// 		// white gunpowder, elevator controls room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xD7)
	// {
	// 	if (uniqueID[1] == 0x98)
	// 	{
	// 		setItemByID(*seed[96]);
	// 		// battery, stars office
	// 	}
	// 	// 7A is Ada ink ribbon hardcore
	// }

	// if (uniqueID[0] == 0xD8)
	// {
	// 	setItemByID(*seed[102]);
	// 	// portable safe, linen room
	// }

	// if (uniqueID[0] == 0xD9)
	// {
	// 	if (uniqueID[1] == 0x88)
	// 	{
	// 		setItemByID(*seed[198]);
	// 		// shotgun shells, nap room
	// 	}
	// 	if (uniqueID[1] == 0xE2)
	// 	{
	// 		setItemByID(*seed[220]);
	// 		// white gunpowder, modulator room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xDA)
	// {
	// 	if (uniqueID[1] == 0x11)
	// 	{
	// 		setItemByID(*seed[238]);
	// 		// ACP ammo (bottom right, left), Bioreactor's room, b scenario
	// 	}
	// 	else
	// 	{
	// 		// gotta check this isn't 0x11 at some point
	// 		setItemByID(*seed[250]);
	// 		// rising rookie film, stars office hiding place
	// 	}
	// }

	// if (uniqueID[0] == 0xDB)
	// {
	// 	if (uniqueID[1] == 0x39)
	// 	{
	// 		setItemByID(*seed[15]);
	// 		// high capacity mag (matilda), west office
	// 	}
	// 	if (uniqueID[1] == 0xA0)
	// 	{
	// 		setItemByID(*seed[79]);
	// 		// shotgun shells, east storage room
	// 	}
	// }

	// if (uniqueID[0] == 0xDC)
	// {
	// 	if (uniqueID[1] == 0x05)
	// 	{
	// 		setItemByID(*seed[38]);
	// 		// green herb, east office
	// 	}
	// 	if (uniqueID[1] == 0xCC)
	// 	{
	// 		setItemByID(*seed[207]);
	// 		// red herb, greenhouse
	// 	}
	// }

	// if (uniqueID[0] == 0xDD)
	// {
	// 	// 5F is ada
	// 	if (uniqueID[1] == 0x5F)
	// 	{
	// 		setItemByID("274");
	// 		// leons rocket launcher every time
	// 	}
	// 	if (uniqueID[1] == 0x34)
	// 	{
	// 		setItemByID(*seed[40]);
	// 		// handgun bullets, east office
	// 	}
	// }

	// if (uniqueID[0] == 0xE1)
	// {
	// 	if (uniqueID[1] == 0x34)
	// 	{
	// 		setItemByID(*seed[202]);
	// 		// Ink Ribbon x2, Lobby hardcore
	// 	}
	// 	if (uniqueID[1] == 0xC4)
	// 	{
	// 		if (playingas == "claire")
	// 		{
	// 			setItemByID(*seed[266]);
	// 			// fuse (break room hallway) claire b scenario
	// 		}
	// 		else
	// 		{
	// 			setItemByID(*seed[140]);
	// 			// fuse (break room hallway)
	// 		}
	// 	}
	// }

	// if (uniqueID[0] == 0xE3)
	// {
	// 	if (uniqueID[1] == 0x80)
	// 	{
	// 		setItemByID(*seed[213]);
	// 		// shotgun shells, lounge
	// 	}
	// 	if (uniqueID[1] == 0xE9)
	// 	{
	// 		setItemByID(*seed[221]);
	// 		// handgun bullets, modulator room
	// 	}
	// }

	// if (uniqueID[0] == 0xE5)
	// {
	// 	if (uniqueID[1] == 0x22)
	// 	{
	// 		setItemByID(*seed[11]);
	// 		// wooden boards, western area 1F
	// 	}
	// 	if (uniqueID[1] == 0x76)
	// 	{
	// 		setItemByID(*seed[228]);
	// 		// yellow gunpowder, p-4 level testing lab
	// 	}
	// }

	// if (uniqueID[0] == 0xE6)
	// {
	// 	if (uniqueID[1] == 0x43)
	// 	{
	// 		setItemByID(*seed[146]);
	// 		// submachine gun ammo, break room, claire b scenario
	// 	}
	// 	if (uniqueID[1] == 0xF9)
	// 	{
	// 		setItemByID(*seed[261]);
	// 		// ACP ammo, guardroom, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0xE7)
	// {
	// 	if (uniqueID[1] == 0x92)
	// 	{
	// 		setItemByID(*seed[260]);
	// 		// hand grenade, guardroom, b scenario
	// 	}
	// 	if (uniqueID[1] == 0xDB)
	// 	{
	// 		setItemByID(*seed[27]);
	// 		// ACP Ammo, Press Room B scenario
	// 	}
	// }

	// if (uniqueID[0] == 0xE8)
	// {
	// 	if (uniqueID[1] == 0x5D)
	// 	{
	// 		setItemByID(*seed[242]);
	// 		// blue herb, pump room
	// 	}
	// 	if (uniqueID[1] == 0xB2)
	// 	{
	// 		setItemByID(*seed[16]);
	// 		// gunpowder, dark room
	// 	}
	// 	if (uniqueID[1] == 0xFA)
	// 	{
	// 		setItemByID(*seed[144]);
	// 		// submachinegun ammo, outside office, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xE9)
	// {
	// 	if (uniqueID[1] == 0xBA)
	// 	{
	// 		setItemByID(*seed[143]);
	// 		// hand grenade, bus, claire only
	// 	}
	// 	if (uniqueID[1] == 0xF0)
	// 	{
	// 		setItemByID(*seed[163]);
	// 		// handgun bullets, monitor room
	// 	}
	// }

	// if (uniqueID[0] == 0xEA)
	// {
	// 	if (uniqueID[1] == 0x6C)
	// 	{
	// 		setItemByID(*seed[138]);
	// 		// submachine ammo, chief's office, claire
	// 	}
	// 	if (uniqueID[1] == 0xEF)
	// 	{
	// 		setItemByID(*seed[122]);
	// 		// FAS, orphanage
	// 	}
	// }

	// if (uniqueID[0] == 0xEB)
	// {
	// 	if (uniqueID[1] == 0xA2)
	// 	{
	// 		setItemByID(*seed[128]);
	// 		// car key, firing range
	// 	}
	// 	if (uniqueID[1] == 0xAA)
	// 	{
	// 		setItemByID(*seed[36]);
	// 		// ink ribbon x2, records room hardcore
	// 	}
	// }

	// if (uniqueID[0] == 0xEC)
	// {
	// 	if (uniqueID[1] == 0x3B)
	// 	{
	// 		setItemByID(*seed[253]);
	// 		// ink ribbon x1, escape area *typewriter hardcore
	// 	}
	// 	if (uniqueID[1] == 0x4E)
	// 	{
	// 		setItemByID(*seed[152]);
	// 		// rook piece, rook bridge area
	// 	}
	// 	if (uniqueID[1] == 0xC9)
	// 	{
	// 		setItemByID(*seed[229]);
	// 		// Ink ribbon x1, p-4 level testing lab hardcore
	// 	}
	// }

	// if (uniqueID[0] == 0xEE)
	// {
	// 	if (uniqueID[1] == 0x30)
	// 	{
	// 		setItemByID(*seed[71]);
	// 		// wooden boards, fire escape
	// 	}
	// 	if (uniqueID[1] == 0xE5)
	// 	{
	// 		setItemByID(*seed[100]);
	// 		// yellow gunpowsder, stars office
	// 	}
	// }

	// if (uniqueID[0] == 0xEF)
	// {
	// 	if (uniqueID[1] == 0x1F)
	// 	{
	// 		setItemByID(*seed[255]);
	// 		// Ink Ribbon x1, Sherry hardcore
	// 	}
	// 	if (uniqueID[1] == 0x2A)
	// 	{
	// 		setItemByID(*seed[88]);
	// 		// gunpowder, boiler room
	// 	}
	// 	if (uniqueID[1] == 0x8B)
	// 	{
	// 		setItemByID(*seed[216]);
	// 		// flamethrower fuel, server room
	// 	}
	// }

	// if (uniqueID[0] == 0xF0)
	// {
	// 	if (uniqueID[1] == 0xAD)
	// 	{
	// 		setItemByID(*seed[156]);
	// 		// Knife, lower waterway pre-slide
	// 	}
	// 	if (uniqueID[1] == 0xAE)
	// 	{
	// 		setItemByID(*seed[230]);
	// 		// handgun bullets (top left), bioreactors room
	// 	}
	// }

	// if (uniqueID[0] == 0xF1)
	// {
	// 	if (uniqueID[1] == 0x8E)
	// 	{
	// 		setItemByID(*seed[46]);
	// 		// muzzle brake (matilda), waiting room
	// 	}
	// 	if (uniqueID[1] == 0x90)
	// 	{
	// 		setItemByID(*seed[217]);
	// 		// white gunpowder, server room, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xF2)
	// {
	// 	if (uniqueID[1] == 0xE0)
	// 	{
	// 		setItemByID(*seed[20]);
	// 		// handgun bullets in locker, claire
	// 	}
	// }

	// if (uniqueID[0] == 0xF3)
	// {
	// 	// 01 is bishop repickup in sewer, only work in B scenario
	// 	if (uniqueID[1] == 0x01andscenario == "B")
	// 	{
	// 		setItemByID(*seed[164]);
	// 		// bishop, B scenario only plz
	// 	}
	// 	if (uniqueID[1] == 0x69)
	// 	{
	// 		// 69 is queen
	// 		debug_continueFromBreakpoint(co_run);
	// 	}
	// 	if (uniqueID[1] == 0x04)
	// 	{
	// 		setItemByID(*seed[192]);
	// 		// shotgun shells, security room
	// 	}
	// 	if (uniqueID[1] == 0x31)
	// 	{
	// 		setItemByID(*seed[10]);
	// 		// green herb, western area 1F
	// 	}
	// 	if (uniqueID[1] == 0x98)
	// 	{
	// 		setItemByID(*seed[142]);
	// 		// green herb, outside RPD
	// 	}
	// }

	// if (uniqueID[0] == 0xF4)
	// {
	// 	if (uniqueID[1] == 0x66)
	// 	{
	// 		setItemByID(*seed[212]);
	// 		// large gunpowder, underneath greenhouse
	// 	}
	// 	if (uniqueID[1] == 0xB5)
	// 	{
	// 		setItemByID(*seed[127]);
	// 		// diamond key, morgue
	// 	}
	// 	if (uniqueID[1] == 0xE3)
	// 	{
	// 		setItemByID(*seed[73]);
	// 		// green herb, main hall 3F
	// 	}
	// }

	// if (uniqueID[0] == 0xF5)
	// {
	// 	setItemByID(*seed[101]);
	// 	// lightning hawk, stars office
	// }

	// if (uniqueID[0] == 0xF6)
	// {
	// 	if (uniqueID[1] == 0xE5)
	// 	{
	// 		setItemByID(*seed[163]);
	// 		// Ink ribbon x2, monitor room hardcore
	// 	}
	// 	if (uniqueID[1] == 0xF2)
	// 	{
	// 		setItemByID(*seed[139]);
	// 		// mag ammo, break room
	// 	}
	// }

	// if (uniqueID[0] == 0xF7)
	// {
	// 	setItemByID(*seed[36]);
	// 	// gunpowder, records room
	// }

	// if (uniqueID[0] == 0xF8)
	// {
	// 	if (uniqueID[1] == 0x34)
	// 	{
	// 		setItemByID(*seed[133]);
	// 		// boxed electronic part, generator room
	// 	}
	// 	if (uniqueID[1] == 0x3F)
	// 	{
	// 		setItemByID(*seed[84]);
	// 		// handgun bullets, roof area
	// 	}
	// 	if (uniqueID[1] == 0x72)
	// 	{
	// 		setItemByID(*seed[201]);
	// 		// hip pouch, nap room
	// 	}
	// 	if (uniqueID[1] == 0x79)
	// 	{
	// 		// doll in sherry segment
	// 		debug_continueFromBreakpoint(co_run);
	// 	}
	// 	if (uniqueID[1] == 0xAB)
	// 	{
	// 		setItemByID(*seed[51]);
	// 		// Bejeweled Box, western area 2F, b scenario
	// 	}
	// }

	// if (uniqueID[0] == 0xF9)
	// {
	// 	if (uniqueID[1] == 0x08)
	// 	{
	// 		setItemByID(*seed[2]);
	// 		// fas, main hall
	// 	}
	// 	if (uniqueID[1] == 0x55)
	// 	{
	// 		setItemByID(*seed[178]);
	// 		// queen plug, supplies storage room
	// 	}
	// 	if (uniqueID[1] == 0x6D)
	// 	{
	// 		setItemByID(*seed[52]);
	// 		// handgun bullets, western area 3F
	// 	}
	// }

	// if (uniqueID[0] == 0xFA)
	// {
	// 	setItemByID(*seed[90]);
	// 	// yellow gunpowder, outside observation room
	// }

	// if (uniqueID[0] == 0xFB)
	// {
	// 	if (uniqueID[1] == 0x67)
	// 	{
	// 		setItemByID(*seed[189]);
	// 		// handgun bullets, g2 fight room
	// 	}
	// 	if (uniqueID[1] == 0xBC)
	// 	{
	// 		setItemByID(*seed[9]);
	// 		// handgun bullets, western area 1F
	// 	}
	// }

	// if (uniqueID[0] == 0xFC)
	// {
	// 	if (uniqueID[1] == 0x9B)
	// 	{
	// 		setItemByID(*seed[5]);
	// 		// knife (marvin), main hall
	// 	}
	// 	if (uniqueID[1] == 0xCB)
	// 	{
	// 		setItemByID(*seed[9]);
	// 		// ACP ammo, western area 1F B scenario
	// 	}
	// 	if (uniqueID[1] == 0xF0)
	// 	{
	// 		setItemByID(*seed[218]);
	// 		// knife, server room
	// 	}
	// }

	// if (uniqueID[0] == 0xFD)
	// {
	// 	if (uniqueID[1] == 0x29)
	// 	{
	// 		setItemByID(*seed[20]);
	// 		// acp ammo, locker room claire B scenario
	// 	}
	// 	if (uniqueID[1] == 0x94)
	// 	{
	// 		setItemByID(*seed[62]);
	// 		// red book, library
	// 	}
	// }

	// if (uniqueID[0] == 0xFE)
	// {
	// 	if (uniqueID[1] == 0x9B)
	// 	{
	// 		setItemByID(*seed[246]);
	// 		// ACP Ammo, Escape Shaft, Leon B scenario
	// 	}
	// 	if (uniqueID[1] == 0xEA)
	// 	{
	// 		setItemByID(*seed[92]);
	// 		// bejeweled box, observation room
	// 	}
	// }
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
