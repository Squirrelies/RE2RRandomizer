#define RE2RR_TYPES_CPP
#include "Types.h"
#undef RE2RR_TYPES_CPP

namespace RE2RR::Types
{
	bool operator==(const RE2RItem &lhs, const RE2RItem &rhs)
	{
		return lhs.ItemId == rhs.ItemId &&
		       lhs.WeaponId == rhs.WeaponId &&
		       lhs.WeaponParts == rhs.WeaponParts &&
		       lhs.BulletId == rhs.BulletId &&
		       lhs.Count == rhs.Count;
	}

	bool operator==(const GameModeKey &lhs, const GameModeKey &rhs)
	{
		return lhs.Scenario == rhs.Scenario &&
		       lhs.Difficulty == rhs.Difficulty;
	}

	bool operator==(const RandomizedItem &lhs, const RandomizedItem &rhs)
	{
		return lhs.OriginalGUID == rhs.OriginalGUID &&
		       lhs.ReplacementItem == rhs.ReplacementItem;
	}

	bool operator==(const Seed &lhs, const Seed &rhs)
	{
		return lhs.gameMode == rhs.gameMode &&
		       lhs.seedData == rhs.seedData;
	}
}
