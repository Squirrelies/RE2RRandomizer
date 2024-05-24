#include "Randomizer.h"

// ItemPositionDependency{.ItemPositionGUID = *StringToGUIDA("00000000-0000-0000-0000-000000000000"), .PrerequisiteItems = [](RE2RREnums::ItemType item) { return item != RE2RREnums::ItemType::KeyStorageRoom; }},
std::list<ItemPositionDependency> itemPositionDependencies =
    {
        ItemPositionDependency{.ItemPositionGUID = *StringToGUIDA("00000000-0000-0000-0000-000000000000"), .PrerequisiteItems = [](RE2RREnums::ItemType item)
                                                                                                           { return item != RE2RREnums::ItemType::KeyStorageRoom; }},
};

// static auto itemPositionsWithNoDependencies = itemPositionDependencies | std::views::filter([](const auto &pair) { return pair.PrerequisiteItemCount == 0; });
