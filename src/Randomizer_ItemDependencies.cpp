#include "Randomizer.h"

static std::unordered_map<int32_t, std::list<GUID>, std::hash<int32_t>, std::equal_to<int32_t>> zoneItemGUIDs =
    {

};

// ZoneItemDependencyKey - int32_t ZoneId, RE2RItem[n] ItemsRequired (to exist in this zone to progress)
// std::list<GUID> - List of item position GUIDs that one or more of the zone items must exist in.
