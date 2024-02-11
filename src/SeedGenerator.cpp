#include "SeedGenerator.h"

void SeedGenerator::GenerateSeed(Character character, Scenario scenario, Difficulty difficulty, bool mixWeapons)
{
	if (scenario == A)
	{
		ZoneIDByItemID.push_back(1);
		ZoneIDByItemID.push_back(1);
		ZoneIDByItemID.push_back(1);
		ZoneIDByItemID.push_back(1);
		ZoneIDByItemID.push_back(1);
		ZoneIDByItemID.push_back(2);
		ZoneIDByItemID.push_back(2);
		ZoneIDByItemID.push_back(2);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
	}
	else if (scenario == B)
	{
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(2);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
	}

	ZoneIDByItemID.push_back(4);
	ZoneIDByItemID.push_back(4);
	ZoneIDByItemID.push_back(4);
	ZoneIDByItemID.push_back(4);
	ZoneIDByItemID.push_back(5);
	ZoneIDByItemID.push_back(5);

	if (scenario == A)
	{
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
	}
	else if (scenario == B)
	{
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
	}

	ZoneIDByItemID.push_back(7);
	ZoneIDByItemID.push_back(7);
	ZoneIDByItemID.push_back(7);
	ZoneIDByItemID.push_back(7);
	ZoneIDByItemID.push_back(8);
	ZoneIDByItemID.push_back(8);
	ZoneIDByItemID.push_back(8);
	ZoneIDByItemID.push_back(9);
	ZoneIDByItemID.push_back(9);
	ZoneIDByItemID.push_back(9);
	ZoneIDByItemID.push_back(9);
	ZoneIDByItemID.push_back(9);
	ZoneIDByItemID.push_back(9);

	if (scenario == A)
	{
		ZoneIDByItemID.push_back(9);
		ZoneIDByItemID.push_back(1);
		ZoneIDByItemID.push_back(1);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(10);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(11);
		ZoneIDByItemID.push_back(11);
		ZoneIDByItemID.push_back(11);
		ZoneIDByItemID.push_back(11);
		ZoneIDByItemID.push_back(12);
		ZoneIDByItemID.push_back(11);
		ZoneIDByItemID.push_back(11);
		ZoneIDByItemID.push_back(11);
	}
	else if (scenario == B)
	{
		ZoneIDByItemID.push_back(2);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(10);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(6);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(12);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(3);
		ZoneIDByItemID.push_back(1);
	}

	ZoneIDByItemID.push_back(13);
	ZoneIDByItemID.push_back(13);
	ZoneIDByItemID.push_back(14);
	ZoneIDByItemID.push_back(15);
	ZoneIDByItemID.push_back(16);
	ZoneIDByItemID.push_back(16);
	ZoneIDByItemID.push_back(16);
	ZoneIDByItemID.push_back(16);
	ZoneIDByItemID.push_back(16);
	ZoneIDByItemID.push_back(16);
	ZoneIDByItemID.push_back(16);
	ZoneIDByItemID.push_back(51);
	ZoneIDByItemID.push_back(51);
	ZoneIDByItemID.push_back(51);
	ZoneIDByItemID.push_back(51);

	if (character == Leon)
	{
		ZoneIDByItemID.push_back(51);
		ZoneIDByItemID.push_back(51);
	}
	else // replace boiler room with two of the elevator controls room items
	{
		ZoneIDByItemID.push_back(26);
		ZoneIDByItemID.push_back(26);
	}

	ZoneIDByItemID.push_back(16);

	if (character == Leon)
	{
		ZoneIDByItemID.push_back(17); // gunpowder observation room
		ZoneIDByItemID.push_back(17); // bejeweled box observation room
		ZoneIDByItemID.push_back(52); // handgun bullets interrogation room
	}
	else
	{
		ZoneIDByItemID.push_back(52); // gunpowder observation room
		ZoneIDByItemID.push_back(17); // bejeweled box interrogation room
		ZoneIDByItemID.push_back(17); // handgun bullets interrogation room
	}

	ZoneIDByItemID.push_back(18);
	ZoneIDByItemID.push_back(18);
	ZoneIDByItemID.push_back(18);
	ZoneIDByItemID.push_back(18);
	ZoneIDByItemID.push_back(18);
	ZoneIDByItemID.push_back(18);
	ZoneIDByItemID.push_back(18);
	ZoneIDByItemID.push_back(19);
	ZoneIDByItemID.push_back(20);
	ZoneIDByItemID.push_back(20);
	ZoneIDByItemID.push_back(21);
	ZoneIDByItemID.push_back(21);
	ZoneIDByItemID.push_back(21);
	ZoneIDByItemID.push_back(22);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(24);

	if (character == Leon) // jail
	{
		ZoneIDByItemID.push_back(23);
		ZoneIDByItemID.push_back(23);
		ZoneIDByItemID.push_back(25);
		ZoneIDByItemID.push_back(25);
	}
	else // used this for a variety of places for claire
	{
		ZoneIDByItemID.push_back(26);
		ZoneIDByItemID.push_back(49);
		ZoneIDByItemID.push_back(25);
		ZoneIDByItemID.push_back(29);
	}

	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(23);
	ZoneIDByItemID.push_back(26);
	ZoneIDByItemID.push_back(26);

	if (character == Leon) // break room RPD reconnection
	{
		ZoneIDByItemID.push_back(27);
		ZoneIDByItemID.push_back(27);
		ZoneIDByItemID.push_back(27);

		if (scenario == A)
		{
			ZoneIDByItemID.push_back(27);
			ZoneIDByItemID.push_back(27);
			ZoneIDByItemID.push_back(27);
			ZoneIDByItemID.push_back(27);
			ZoneIDByItemID.push_back(27);
			ZoneIDByItemID.push_back(27);
			ZoneIDByItemID.push_back(27);
		}
		else if (scenario == B)
		{
			ZoneIDByItemID.push_back(3);
			ZoneIDByItemID.push_back(3);
			ZoneIDByItemID.push_back(3);
			ZoneIDByItemID.push_back(3);
			ZoneIDByItemID.push_back(3);
			ZoneIDByItemID.push_back(3);
			ZoneIDByItemID.push_back(3);
		}

		ZoneIDByItemID.push_back(28);
		ZoneIDByItemID.push_back(28);
		ZoneIDByItemID.push_back(28);
		ZoneIDByItemID.push_back(28);
		ZoneIDByItemID.push_back(29);
		ZoneIDByItemID.push_back(29);
		ZoneIDByItemID.push_back(29);
	}
	else // claire replacements
	{

		ZoneIDByItemID.push_back(26);
		ZoneIDByItemID.push_back(27);
		ZoneIDByItemID.push_back(29); // 133
		ZoneIDByItemID.push_back(29);
		ZoneIDByItemID.push_back(27);
		ZoneIDByItemID.push_back(29); // 136
		ZoneIDByItemID.push_back(26);
		ZoneIDByItemID.push_back(29); // 138
		ZoneIDByItemID.push_back(26);
		ZoneIDByItemID.push_back(26);
		ZoneIDByItemID.push_back(28);
		ZoneIDByItemID.push_back(29); // 142
		ZoneIDByItemID.push_back(29);

		if (scenario == A)
		{
			ZoneIDByItemID.push_back(28);
			ZoneIDByItemID.push_back(29);
			ZoneIDByItemID.push_back(29);
			ZoneIDByItemID.push_back(29);
		}
		else if (scenario == B)
		{
			ZoneIDByItemID.push_back(3);
			ZoneIDByItemID.push_back(3);
			ZoneIDByItemID.push_back(27);
			ZoneIDByItemID.push_back(27);
		}
	}

	ZoneIDByItemID.push_back(30);
	ZoneIDByItemID.push_back(30);
	ZoneIDByItemID.push_back(30);
	ZoneIDByItemID.push_back(30);
	ZoneIDByItemID.push_back(31);
	ZoneIDByItemID.push_back(31);
	ZoneIDByItemID.push_back(31);
	ZoneIDByItemID.push_back(32);
	ZoneIDByItemID.push_back(33);
	ZoneIDByItemID.push_back(33);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(35);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(34);
	ZoneIDByItemID.push_back(35);
	ZoneIDByItemID.push_back(35);
	ZoneIDByItemID.push_back(35);
	ZoneIDByItemID.push_back(35);
	ZoneIDByItemID.push_back(35);
	ZoneIDByItemID.push_back(36);
	ZoneIDByItemID.push_back(37);
	ZoneIDByItemID.push_back(35);
	ZoneIDByItemID.push_back(35);
	ZoneIDByItemID.push_back(35);
	ZoneIDByItemID.push_back(35);
	ZoneIDByItemID.push_back(38);
	ZoneIDByItemID.push_back(38);
	ZoneIDByItemID.push_back(38);
	ZoneIDByItemID.push_back(38);
	ZoneIDByItemID.push_back(38);
	ZoneIDByItemID.push_back(38);
	ZoneIDByItemID.push_back(38);
	ZoneIDByItemID.push_back(39);
	ZoneIDByItemID.push_back(39);
	ZoneIDByItemID.push_back(39);
	ZoneIDByItemID.push_back(39);
	ZoneIDByItemID.push_back(40);
	ZoneIDByItemID.push_back(40);
	ZoneIDByItemID.push_back(40);
	ZoneIDByItemID.push_back(40);
	ZoneIDByItemID.push_back(40);
	ZoneIDByItemID.push_back(41);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(48);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(42);

	if (scenario == A)
	{
		ZoneIDByItemID.push_back(42);
	}
	else if (scenario == B)
	{
		ZoneIDByItemID.push_back(43);
	}

	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(43);
	ZoneIDByItemID.push_back(43);
	ZoneIDByItemID.push_back(43);
	ZoneIDByItemID.push_back(43);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(42);
	ZoneIDByItemID.push_back(44);
	ZoneIDByItemID.push_back(44);
	ZoneIDByItemID.push_back(44);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(45);
	ZoneIDByItemID.push_back(46);
	ZoneIDByItemID.push_back(46);
	ZoneIDByItemID.push_back(46);
	ZoneIDByItemID.push_back(46);
	ZoneIDByItemID.push_back(46);
	ZoneIDByItemID.push_back(49);

	if (character == Leon)
	{
		ZoneIDByItemID.push_back(49);
	}
	else // for claire this is orphanage ammo
	{
		ZoneIDByItemID.push_back(29);
	}

	ZoneIDByItemID.push_back(49);
	ZoneIDByItemID.push_back(50);
	ZoneIDByItemID.push_back(47);
	ZoneIDByItemID.push_back(47);
	ZoneIDByItemID.push_back(18); // extra shotgun shells in stars office that I missed

	// hardcore extras
	// ZoneIDByItemID.push_back(23); no ada change
	ZoneIDByItemID.push_back(39); // lab reception entrance
	ZoneIDByItemID.push_back(46); // escape typewriter
	ZoneIDByItemID.push_back(52); // interrogation room ribbon
	ZoneIDByItemID.push_back(29); // sherry ink ribbon
	ZoneIDByItemID.push_back(29); // office after sherry

	// B-side extras
	ZoneIDByItemID.push_back(18); // acp ammo STARS office
	ZoneIDByItemID.push_back(1);  // red herb, outside fire escape
	ZoneIDByItemID.push_back(1);  // blue herb, outside fire escape
	ZoneIDByItemID.push_back(2);  // hand grenade, guard room
	ZoneIDByItemID.push_back(2);  // acp ammo, guard room

	// B side Claire extras
	ZoneIDByItemID.push_back(3); // knife outside break room
	ZoneIDByItemID.push_back(3); // blue herb inside break room
	ZoneIDByItemID.push_back(3); // white gunpowder inside break room
	ZoneIDByItemID.push_back(3); // acp ammo, break room
	ZoneIDByItemID.push_back(3); // fuse, break room

	// added special knife / spade zone logic

	if (scenario == B)
	{
		ZoneRequiredItems[2][0].push_back(71); // bolt cutters to guard room
		ZoneRequiredItems[3][0].push_back(43); // courtyard key
	}

	// safety deposit boxes
	ZoneRequiredItems[4][0].push_back(50);
	ZoneRequiredItems[4][0].push_back(101); // portable safes

	// shotgun cabinet
	ZoneRequiredItems[5][0].push_back(66); // weapons locker key

	uint32_t fuseid = 139;
	uint32_t heartid = 139;
	uint32_t clubid = 88;
	uint32_t squarecrankpos = 119;

	if (scenario == B && character == Claire)
	{
		fuseid = 265;
		clubid = 146;
		squarecrankpos = 147;
	}

	if (scenario == B && character == Leon)
	{
		heartid = 131;
	}

	if (scenario == A)
	{

		// elliot zone

		if (character == Leon) // claire can't go around the medallion way
		{
			ZoneRequiredItems[6][1].push_back(53);
			ZoneRequiredItems[6][1].push_back(71); // spade key + bolt cutters
			ZoneRequiredItems[6][2].push_back(2);
			ZoneRequiredItems[6][2].push_back(58);
			ZoneRequiredItems[6][2].push_back(63); // 3 medallions, we don't have to worry about the fuze and square crank due to logic
		}
		else
		{
			ZoneRequiredItems[6][0].push_back(53);
			ZoneRequiredItems[6][0].push_back(71); // spade key + bolt cutters
		}
	}
	else if (scenario == B)
	{
		ZoneRequiredItems[6][0].push_back(43);     // courtyard key
		ZoneRequiredItems[6][1].push_back(53);     // spade key
		ZoneRequiredItems[6][2].push_back(fuseid); // fuse
	}

	if (scenario == A)
	{

		// detonator zone
		ZoneRequiredItems[7][0].push_back(71); // bolt cutters

		ZoneRequiredItems[7][1].push_back(4); // one of the knives
		ZoneRequiredItems[7][2].push_back(20);
		ZoneRequiredItems[7][3].push_back(60);
		ZoneRequiredItems[7][4].push_back(135);
		ZoneRequiredItems[7][5].push_back(155);
		ZoneRequiredItems[7][6].push_back(190);
		ZoneRequiredItems[7][7].push_back(196);
		ZoneRequiredItems[7][8].push_back(217);
		ZoneRequiredItems[7][9].push_back(240);
	}
	else if (scenario == B)
	{
		ZoneRequiredItems[7][0].push_back(43); // courtyard key

		ZoneRequiredItems[7][1].push_back(53); // spade key
		ZoneRequiredItems[7][1].push_back(71); // bolt cutters

		ZoneRequiredItems[7][2].push_back(fuseid); // fuse
		ZoneRequiredItems[7][2].push_back(71);     // bolt cutters

		ZoneRequiredItems[7][3].push_back(53);      // spade key
		ZoneRequiredItems[7][3].push_back(clubid);  // club key
		ZoneRequiredItems[7][3].push_back(heartid); // heart key

		ZoneRequiredItems[7][4].push_back(fuseid);  // fuse
		ZoneRequiredItems[7][4].push_back(clubid);  // club key
		ZoneRequiredItems[7][4].push_back(heartid); // heart key
	}

	if (scenario == A)
	{

		// records room
		if (character == Leon) // claire has heart key
		{
			ZoneRequiredItems[8][0].push_back(clubid); // club key
		}
		else
		{
			ZoneRequiredItems[8][0].push_back(71);      // bolt cutters
			ZoneRequiredItems[8][0].push_back(heartid); // heart key
		}

		ZoneRequiredItems[8][1].push_back(4); // one of the knives
		ZoneRequiredItems[8][2].push_back(20);
		ZoneRequiredItems[8][3].push_back(60);
		ZoneRequiredItems[8][4].push_back(135);
		ZoneRequiredItems[8][5].push_back(155);
		ZoneRequiredItems[8][6].push_back(190);
		ZoneRequiredItems[8][7].push_back(196);
		ZoneRequiredItems[8][8].push_back(217);
		ZoneRequiredItems[8][9].push_back(240);
	}
	else if (scenario == B)
	{
		ZoneRequiredItems[8][0].push_back(43); // courtyard key

		ZoneRequiredItems[8][1].push_back(clubid); // club key
		ZoneRequiredItems[8][1].push_back(53);     // spade key

		ZoneRequiredItems[8][2].push_back(88);     // club key
		ZoneRequiredItems[8][2].push_back(fuseid); // fuse

		ZoneRequiredItems[8][3].push_back(heartid); // heart key
		ZoneRequiredItems[8][3].push_back(71);      // bolt cutters
		ZoneRequiredItems[8][3].push_back(53);      // spade key

		ZoneRequiredItems[8][4].push_back(heartid); // heart key
		ZoneRequiredItems[8][4].push_back(71);      // bolt cutters
		ZoneRequiredItems[8][4].push_back(fuseid);  // fuse
	}

	// east office
	ZoneRequiredItems[9][0].push_back(71); // bolt cutters

	if (scenario == A)
	{

		if (character == Leon) // claire can't go around the medallion way
		{
			ZoneRequiredItems[9][1].push_back(53); // spade key
			ZoneRequiredItems[9][2].push_back(2);
			ZoneRequiredItems[9][2].push_back(58);
			ZoneRequiredItems[9][2].push_back(63); // 3 medallions
		}
		else
		{
			ZoneRequiredItems[9][0].push_back(53); // spade key
		}
	}
	else if (scenario == B)
	{
		ZoneRequiredItems[9][0].push_back(43); // courtyard key
	}

	// maiden statue item
	ZoneRequiredItems[10][0].push_back(30);
	ZoneRequiredItems[10][0].push_back(95); // detonator + battery

	if (scenario == B)
	{
		ZoneRequiredItems[10][0].push_back(43);     // courtyard key
		ZoneRequiredItems[10][1].push_back(53);     // spade key
		ZoneRequiredItems[10][2].push_back(fuseid); // fuse
	}

	if (scenario == A)
	{
		// helicopter crash zone
		ZoneRequiredItems[11][0].push_back(53); // spade key
	}
	else if (scenario == B)
	{

		// upper heart key access
		if (character == Claire)
		{

			ZoneRequiredItems[11][0].push_back(43);      // courtyard key
			ZoneRequiredItems[11][0].push_back(heartid); // heart key

			ZoneRequiredItems[11][1].push_back(squarecrankpos); // square crank

			ZoneRequiredItems[11][2].push_back(36);     // mechanical jack handle
			ZoneRequiredItems[11][2].push_back(fuseid); // fuse

			ZoneRequiredItems[11][3].push_back(36); // mechanical jack handle
			ZoneRequiredItems[11][3].push_back(53); // spade key
		}
		// there are no items for leon to get with the heart key
	}

	if (scenario == A)
	{
		// scepter
		ZoneRequiredItems[12][0].push_back(53);
		ZoneRequiredItems[12][0].push_back(61);
		ZoneRequiredItems[12][0].push_back(67); // spade key + statue arm + red book
	}
	else if (scenario == B)
	{
		ZoneRequiredItems[12][0].push_back(43); // courtyard key
		ZoneRequiredItems[12][0].push_back(61); // red book
		ZoneRequiredItems[12][0].push_back(67); // arm
	}

	// outer clock tower
	ZoneRequiredItems[13][0].push_back(36); // mechanic jack handle

	if (scenario == A)
	{
		ZoneRequiredItems[13][1].push_back(4); // one of the knives
		ZoneRequiredItems[13][2].push_back(20);
		ZoneRequiredItems[13][3].push_back(60);
		ZoneRequiredItems[13][4].push_back(135);
		ZoneRequiredItems[13][5].push_back(155);
		ZoneRequiredItems[13][6].push_back(190);
		ZoneRequiredItems[13][7].push_back(196);
		ZoneRequiredItems[13][8].push_back(217);
		ZoneRequiredItems[13][9].push_back(240);
	}
	else if (scenario == B)
	{
		ZoneRequiredItems[13][0].push_back(43);     // courtyard key
		ZoneRequiredItems[13][1].push_back(53);     // spade key
		ZoneRequiredItems[13][2].push_back(fuseid); // fuse
	}

	// upstairs clock tower

	ZoneRequiredItems[14] = ZoneRequiredItems[13];

	ZoneRequiredItems[14][0].push_back(77); // large gear
	ZoneRequiredItems[14][0].push_back(2);
	ZoneRequiredItems[14][0].push_back(58);
	ZoneRequiredItems[14][0].push_back(63); // 3 medallions also

	// solved clock tower

	ZoneRequiredItems[15] = ZoneRequiredItems[14];

	ZoneRequiredItems[15][0].push_back(74); // small gear

	if (scenario == A)
	{
		// rooftop access area
		ZoneRequiredItems[16][1].push_back(4);
		ZoneRequiredItems[16][1].push_back(36); // one of the knives and mechanic handle
		ZoneRequiredItems[16][2].push_back(20);
		ZoneRequiredItems[16][2].push_back(36);
		ZoneRequiredItems[16][3].push_back(60);
		ZoneRequiredItems[16][3].push_back(36);
		ZoneRequiredItems[16][4].push_back(135);
		ZoneRequiredItems[16][4].push_back(36);
		ZoneRequiredItems[16][5].push_back(155);
		ZoneRequiredItems[16][5].push_back(36);
		ZoneRequiredItems[16][6].push_back(190);
		ZoneRequiredItems[16][6].push_back(36);
		ZoneRequiredItems[16][7].push_back(196);
		ZoneRequiredItems[16][7].push_back(36);
		ZoneRequiredItems[16][8].push_back(217);
		ZoneRequiredItems[16][8].push_back(36);
		ZoneRequiredItems[16][9].push_back(240);
		ZoneRequiredItems[16][9].push_back(36);
		// OR
		if (character == Leon) // leon can get around it
		{
			ZoneRequiredItems[16][10].push_back(53);
			ZoneRequiredItems[16][10].push_back(2);
			ZoneRequiredItems[16][10].push_back(58);
			ZoneRequiredItems[16][10].push_back(63); // spade key + 3 medallions
		}
	}
	else if (scenario == B)
	{
		ZoneRequiredItems[16][0].push_back(43); // courtyard key

		ZoneRequiredItems[16][1].push_back(squarecrankpos); // square crank

		ZoneRequiredItems[16][2].push_back(36);     // mechanical jack handle
		ZoneRequiredItems[16][2].push_back(fuseid); // fuse

		ZoneRequiredItems[16][3].push_back(36); // mechanical jack handle
		ZoneRequiredItems[16][3].push_back(53); // spade key
	}

	if (scenario == A)
	{

		// Observation / Interrogation Room
		if (character == Leon)
		{
			ZoneRequiredItems[17][0].push_back(clubid); // club key
		}
		else
		{
			ZoneRequiredItems[17][0].push_back(heartid); // heart key
		}

		// AND
		ZoneRequiredItems[17][1].push_back(4);
		ZoneRequiredItems[17][1].push_back(36); // one of the knives and mechanic handle
		ZoneRequiredItems[17][2].push_back(20);
		ZoneRequiredItems[17][2].push_back(36);
		ZoneRequiredItems[17][3].push_back(60);
		ZoneRequiredItems[17][3].push_back(36);
		ZoneRequiredItems[17][4].push_back(135);
		ZoneRequiredItems[17][4].push_back(36);
		ZoneRequiredItems[17][5].push_back(155);
		ZoneRequiredItems[17][5].push_back(36);
		ZoneRequiredItems[17][6].push_back(190);
		ZoneRequiredItems[17][6].push_back(36);
		ZoneRequiredItems[17][7].push_back(196);
		ZoneRequiredItems[17][7].push_back(36);
		ZoneRequiredItems[17][8].push_back(217);
		ZoneRequiredItems[17][8].push_back(36);
		ZoneRequiredItems[17][9].push_back(240);
		ZoneRequiredItems[17][9].push_back(36);
		// OR
		if (character == Leon) // leon also needs spade key
		{
			ZoneRequiredItems[17][10].push_back(53);
		}

		// ZoneRequiredItems[17][10].push_back(2); ZoneRequiredItems[17][10].push_back(58); ZoneRequiredItems[17][10].push_back(63); //3 medallions, I don't think this should be here?
	}
	else if (scenario == B)
	{
		ZoneRequiredItems[17] = ZoneRequiredItems[16];

		// Observation / Interrogation Room
		if (character == Leon)
		{
			ZoneRequiredItems[17][0].push_back(clubid); // club key
		}
		else
		{
			ZoneRequiredItems[17][0].push_back(heartid); // heart key
		}
	}

	if (scenario == A)
	{

		// interrogation room needs medallions
		ZoneRequiredItems[52] = ZoneRequiredItems[17];
		ZoneRequiredItems[52][0].push_back(2);
		ZoneRequiredItems[52][0].push_back(58);
		ZoneRequiredItems[52][0].push_back(63);
	}
	else if (scenario == B)
	{

		ZoneRequiredItems[52][0].push_back(43); // courtyard key

		ZoneRequiredItems[52][1].push_back(squarecrankpos); // square crank

		ZoneRequiredItems[52][2].push_back(36);     // mechanical jack handle
		ZoneRequiredItems[52][2].push_back(fuseid); // fuse

		ZoneRequiredItems[52][3].push_back(36); // mechanical jack handle
		ZoneRequiredItems[52][3].push_back(53); // spade key

		// dupe the three above for different key
		ZoneRequiredItems[52][4].push_back(squarecrankpos); // square crank

		ZoneRequiredItems[52][5].push_back(36);     // mechanical jack handle
		ZoneRequiredItems[52][5].push_back(fuseid); // fuse

		ZoneRequiredItems[52][6].push_back(36); // mechanical jack handle
		ZoneRequiredItems[52][6].push_back(53); // spade key

		if (character == Leon)
		{
			ZoneRequiredItems[52][1].push_back(heartid); // heart key
			ZoneRequiredItems[52][2].push_back(heartid); // heart key
			ZoneRequiredItems[52][3].push_back(heartid); // heart key

			ZoneRequiredItems[52][4].push_back(clubid); // club key
			ZoneRequiredItems[52][4].push_back(2);
			ZoneRequiredItems[52][4].push_back(58);
			ZoneRequiredItems[52][4].push_back(63); // medallions

			ZoneRequiredItems[52][5].push_back(clubid); // club key
			ZoneRequiredItems[52][5].push_back(2);
			ZoneRequiredItems[52][5].push_back(58);
			ZoneRequiredItems[52][5].push_back(63); // medallions

			ZoneRequiredItems[52][6].push_back(clubid); // club key
			ZoneRequiredItems[52][6].push_back(2);
			ZoneRequiredItems[52][6].push_back(58);
			ZoneRequiredItems[52][6].push_back(63); // medallions
		}
		else
		{
			ZoneRequiredItems[52][1].push_back(clubid); // club key
			ZoneRequiredItems[52][2].push_back(clubid); // club key
			ZoneRequiredItems[52][3].push_back(clubid); // club key

			ZoneRequiredItems[52][4].push_back(heartid); // heart key
			ZoneRequiredItems[52][4].push_back(2);
			ZoneRequiredItems[52][4].push_back(58);
			ZoneRequiredItems[52][4].push_back(63); // medallions

			ZoneRequiredItems[52][5].push_back(heartid); // heart key
			ZoneRequiredItems[52][5].push_back(2);
			ZoneRequiredItems[52][5].push_back(58);
			ZoneRequiredItems[52][5].push_back(63); // medallions

			ZoneRequiredItems[52][6].push_back(heartid); // heart key
			ZoneRequiredItems[52][6].push_back(2);
			ZoneRequiredItems[52][6].push_back(58);
			ZoneRequiredItems[52][6].push_back(63); // medallions
		}
	}

	// outside stars office
	ZoneRequiredItems[18][0].push_back(41); // valve

	if (scenario == B)
	{
		ZoneRequiredItems[18][0].push_back(43);     // courtyard key
		ZoneRequiredItems[18][1].push_back(53);     // spade key
		ZoneRequiredItems[18][2].push_back(fuseid); // fuse
	}

	// stars office back room
	ZoneRequiredItems[19] = ZoneRequiredItems[18];
	ZoneRequiredItems[19][0].push_back(68); // scepter

	if (scenario == A)
	{
		ZoneRequiredItems[19][0].push_back(91); // bejeweled box
	}
	else
	{
		ZoneRequiredItems[19][0].push_back(50); // bejeweled box
	}

	// linen room
	ZoneRequiredItems[20] = ZoneRequiredItems[18];
	ZoneRequiredItems[20][0].push_back(126); // diamond key

	// pre-g1 underground access
	ZoneRequiredItems[21][0].push_back(2);
	ZoneRequiredItems[21][0].push_back(58);
	ZoneRequiredItems[21][0].push_back(63); // 3 medallions
	ZoneRequiredItems[21][0].push_back(75);
	ZoneRequiredItems[21][0].push_back(132); // boxed electronic parts
	ZoneRequiredItems[21][0].push_back(167); // tbar valve
	ZoneRequiredItems[21][0].push_back(170); // sewer key

	if (scenario == B)
	{
		// do everything in one go here
		for (uint32_t i = 21; i < 29; i++)
		{
			ZoneRequiredItems[21][0].push_back(43);     // courtyard key
			ZoneRequiredItems[21][1].push_back(53);     // spade key
			ZoneRequiredItems[21][2].push_back(fuseid); // fuse
		}
	}

	// underground stars box
	ZoneRequiredItems[22][0].push_back(2);
	ZoneRequiredItems[22][0].push_back(58);
	ZoneRequiredItems[22][0].push_back(63); // 3 medallions
	ZoneRequiredItems[22][0].push_back(75);
	ZoneRequiredItems[22][0].push_back(132); // boxed electronic parts
	ZoneRequiredItems[22][0].push_back(167); // tbar valve
	ZoneRequiredItems[22][0].push_back(170); // sewer key
	ZoneRequiredItems[22][0].push_back(68);
	ZoneRequiredItems[22][0].push_back(91); // scepter, bejeweled box

	// post G1-underground
	ZoneRequiredItems[23][0].push_back(2);
	ZoneRequiredItems[23][0].push_back(58);
	ZoneRequiredItems[23][0].push_back(63); // 3 medallions

	// police car boot
	ZoneRequiredItems[24][0].push_back(2);
	ZoneRequiredItems[24][0].push_back(58);
	ZoneRequiredItems[24][0].push_back(63);  // 3 medallions
	ZoneRequiredItems[24][0].push_back(127); // car key

	// jail cell access / parking key access for claire
	ZoneRequiredItems[25][0].push_back(2);
	ZoneRequiredItems[25][0].push_back(58);
	ZoneRequiredItems[25][0].push_back(63); // 3 medallions
	ZoneRequiredItems[25][0].push_back(75);
	ZoneRequiredItems[25][0].push_back(132); // boxed electronic parts

	// adding large and small gear here to prevent black screen soft lock
	ZoneRequiredItems[25][0].push_back(77);
	ZoneRequiredItems[25][0].push_back(74);

	// firing range lockers
	ZoneRequiredItems[26][0].push_back(2);
	ZoneRequiredItems[26][0].push_back(58);
	ZoneRequiredItems[26][0].push_back(63);  // 3 medallions
	ZoneRequiredItems[26][0].push_back(126); // diamond key

	if (scenario == A)
	{

		if (character == Leon) // leon only backtracking
		{
			// square crank rpd access
			ZoneRequiredItems[27][0].push_back(2);
			ZoneRequiredItems[27][0].push_back(58);
			ZoneRequiredItems[27][0].push_back(63);             // 3 medallions
			ZoneRequiredItems[27][0].push_back(squarecrankpos); // square crank
		}
		else
		{
			ZoneRequiredItems[27][0].push_back(2);
			ZoneRequiredItems[27][0].push_back(58);
			ZoneRequiredItems[27][0].push_back(63);      // 3 medallions
			ZoneRequiredItems[27][0].push_back(heartid); // heart key
		}
	}
	else if (scenario == B)
	{
		ZoneRequiredItems[27][0].push_back(2);
		ZoneRequiredItems[27][0].push_back(58);
		ZoneRequiredItems[27][0].push_back(63);             // 3 medallions
		ZoneRequiredItems[27][0].push_back(squarecrankpos); // square crank
	}

	// outside RPD
	ZoneRequiredItems[28][0].push_back(2);
	ZoneRequiredItems[28][0].push_back(58);
	ZoneRequiredItems[28][0].push_back(63);  // 3 medallions
	ZoneRequiredItems[28][0].push_back(120); // parking key

	// all of the sewer items need these items
	for (uint32_t i = 29; i < 38; i++)
	{
		ZoneRequiredItems[i] = ZoneRequiredItems[28];
	}

	// sewer key zones
	ZoneRequiredItems[31][0].push_back(170); // sewer key

	// lower waterway before slide
	ZoneRequiredItems[32][0].push_back(151); // rook plug

	// water injection room
	ZoneRequiredItems[33][0].push_back(151);
	ZoneRequiredItems[33][0].push_back(170); // rook plug + sewer key

	// sewer main zone
	if (character == Leon) // only Leon needs this
	{
		ZoneRequiredItems[34][1].push_back(151); // rook plug
	}

	// ZoneRequiredItems[34][2].push_back(167); //tbar valve //taken out

	// bottom waterway access
	ZoneRequiredItems[35][0].push_back(167); // tbar valve

	// king plug get
	ZoneRequiredItems[36][0].push_back(167); // tbar valve
	ZoneRequiredItems[36][0].push_back(177); // queen plug

	// flamethrower
	ZoneRequiredItems[37][0].push_back(167); // tbar valve
	ZoneRequiredItems[37][0].push_back(177); // queen plug
	ZoneRequiredItems[37][0].push_back(178); // king plug

	// g2 fight access
	ZoneRequiredItems[38][0].push_back(151); // rook plug
	ZoneRequiredItems[38][0].push_back(177); // queen plug
	ZoneRequiredItems[38][0].push_back(178); // king plug
	ZoneRequiredItems[38][0].push_back(163); // bishop plug
	ZoneRequiredItems[38][0].push_back(164); // knight plug
	ZoneRequiredItems[38][0].push_back(165); // pawn plug

	// all of the lab items need these items
	for (uint32_t i = 39; i < 50; i++)
	{

		if (i != 47) // not film hiding place
		{
			ZoneRequiredItems[i] = ZoneRequiredItems[38];
		}
	}

	// nap room hip pouch
	ZoneRequiredItems[41][0].push_back(221); // signal modulator

	// main lab access
	ZoneRequiredItems[42][0].push_back(199); // upgrade chip general staff

	// signal modulator zones
	ZoneRequiredItems[43][0].push_back(199); // upgrade chip general staff
	ZoneRequiredItems[43][0].push_back(221); // signal modulator

	// senior staff access
	ZoneRequiredItems[44][0].push_back(199); // upgrade chip general staff
	ZoneRequiredItems[44][0].push_back(208); // upgrade chip senior staff

	// g3 access
	ZoneRequiredItems[45][0].push_back(199); // upgrade chip general staff
	ZoneRequiredItems[45][0].push_back(208); // upgrade chip senior staff
	ZoneRequiredItems[45][0].push_back(221); // signal modulator

	// same for escape
	ZoneRequiredItems[46] = ZoneRequiredItems[45];
	ZoneRequiredItems[49] = ZoneRequiredItems[45];

	// dispersal cartridge zones
	ZoneRequiredItems[48][0].push_back(199); // upgrade chip general staff
	ZoneRequiredItems[48][0].push_back(221); // signal modulator
	ZoneRequiredItems[48][0].push_back(204); // dispersal cartridge (empty)

	// film hiding place in stars office
	ZoneRequiredItems[47][0].push_back(2);
	ZoneRequiredItems[47][0].push_back(58);
	ZoneRequiredItems[47][0].push_back(63); // 3 medallions
	ZoneRequiredItems[47][0].push_back(181);
	ZoneRequiredItems[47][0].push_back(41); // film hiding place, valve

	// press office hiding place
	ZoneRequiredItems[50][0].push_back(2);
	ZoneRequiredItems[50][0].push_back(58);
	ZoneRequiredItems[50][0].push_back(63);  // 3 medallions
	ZoneRequiredItems[50][0].push_back(181); // film hiding place
	ZoneRequiredItems[50][1].push_back(53);
	ZoneRequiredItems[50][1].push_back(71); // spade key + bolt cutters

	if (scenario == B)
	{
		ZoneRequiredItems[47][0].push_back(43);     // courtyard key
		ZoneRequiredItems[47][1].push_back(53);     // spade key
		ZoneRequiredItems[47][2].push_back(fuseid); // fuse

		ZoneRequiredItems[50][0].push_back(43);     // courtyard key
		ZoneRequiredItems[50][1].push_back(53);     // spade key
		ZoneRequiredItems[50][2].push_back(fuseid); // fuse
	}

	// fallen down the ladder zone
	ZoneRequiredItems[51] = ZoneRequiredItems[16]; // roof access
	ZoneRequiredItems[51][0].push_back(2);
	ZoneRequiredItems[51][0].push_back(58);
	ZoneRequiredItems[51][0].push_back(63); // 3 medallions

	// DISALLOWED ZONES

	// medallions
	for (uint32_t i = 21; i < 47; ++i)
	{
		DisallowedZoneMap[2].push_back(i);  // lion
		DisallowedZoneMap[58].push_back(i); // maiden
		DisallowedZoneMap[63].push_back(i); // unicorn
	}

	DisallowedZoneMap[30].push_back(10); // detonator, no battery
	DisallowedZoneMap[95].push_back(10); // battery

	DisallowedZoneMap[36].push_back(13); // mechanic jack handle
	DisallowedZoneMap[36].push_back(14);
	DisallowedZoneMap[36].push_back(15);

	DisallowedZoneMap[41].push_back(18); // valve
	DisallowedZoneMap[41].push_back(19);
	DisallowedZoneMap[41].push_back(20);

	// main hall fuse (43), not lab

	if (scenario == A)
	{
		DisallowedZoneMap[50].push_back(4); // portable safes
	}
	else
	{
		DisallowedZoneMap[50].push_back(19); // bejeweled box in B scenario
		DisallowedZoneMap[50].push_back(22);
	}

	DisallowedZoneMap[101].push_back(4);

	if (scenario == A)
	{

		DisallowedZoneMap[53].push_back(11); // spade key
		DisallowedZoneMap[53].push_back(12);
	}

	DisallowedZoneMap[61].push_back(12); // red book

	DisallowedZoneMap[66].push_back(5); // weapons locker key

	DisallowedZoneMap[67].push_back(12); // statue's left arm

	DisallowedZoneMap[68].push_back(19); // scepter

	DisallowedZoneMap[71].push_back(7); // bolt cutters

	if (scenario == A)
	{

		if (character == Claire) // claire can't have the bolt cutters be in these locations
		{
			DisallowedZoneMap[71].push_back(6);
			DisallowedZoneMap[71].push_back(50);
		}
	}
	else
	{
		DisallowedZoneMap[71].push_back(2); // guard room b scenario
	}

	DisallowedZoneMap[74].push_back(15); // small gear

	DisallowedZoneMap[75].push_back(25); // boxed electronic parts
	DisallowedZoneMap[132].push_back(25);

	DisallowedZoneMap[77].push_back(14); // large gear
	DisallowedZoneMap[77].push_back(15);

	DisallowedZoneMap[clubid].push_back(8); // club key
	DisallowedZoneMap[clubid].push_back(17);

	if (scenario == A)
	{
		DisallowedZoneMap[91].push_back(19); // bejeweled box
		DisallowedZoneMap[91].push_back(22);
	}
	else
	{
		DisallowedZoneMap[50].push_back(19); // bejeweled box
		DisallowedZoneMap[50].push_back(22);
	}

	// this below section is for getting out of the RPD basement, here I need to add logic that can allow the crank / keys to be in other places as long as the player can use those items to get the medallions.
	// square crank
	for (uint32_t i = 1; i < 38; i++)
	{
		if (i != 23)
		{

			if (character == Leon)
			{
				DisallowedZoneMap[119].push_back(i);
			}
			else
			{
				DisallowedZoneMap[126].push_back(i); // diamond key

				if (i != 26) // heart key escape
				{
					DisallowedZoneMap[heartid].push_back(i);
				}
			}
		}
	}

	DisallowedZoneMap[119].push_back(47);
	DisallowedZoneMap[119].push_back(50);
	DisallowedZoneMap[119].push_back(51);
	DisallowedZoneMap[119].push_back(52);

	// parking garage key card can only be in one place so don't bother

	if (character == Leon) // this is only needed for Leon, Claires is already set
	{
		DisallowedZoneMap[126].push_back(20); // diamond key
		DisallowedZoneMap[126].push_back(26);
	}
	else
	{
		// claire can't have the diamond key be in the hidden item locations
		DisallowedZoneMap[126].push_back(47);
		DisallowedZoneMap[126].push_back(50);
		// claire also can't have the heart key be in certain places
		DisallowedZoneMap[heartid].push_back(50);
		DisallowedZoneMap[heartid].push_back(51);
		DisallowedZoneMap[heartid].push_back(52);
	}

	DisallowedZoneMap[126].push_back(51);
	DisallowedZoneMap[126].push_back(52);

	DisallowedZoneMap[127].push_back(24); // car key

	if (scenario == A)
	{

		// fuse break room hallway (139), not lab
		for (uint32_t i = 1; i < 38; i++)
		{
			if (i != 23 && i != 27)
			{
				DisallowedZoneMap[139].push_back(i);
				DisallowedZoneMap[43].push_back(i); // main hall fuse too
			}
		}

		DisallowedZoneMap[139].push_back(47);
		DisallowedZoneMap[139].push_back(50);
		DisallowedZoneMap[139].push_back(51);
		DisallowedZoneMap[139].push_back(52);
		DisallowedZoneMap[43].push_back(47);
		DisallowedZoneMap[43].push_back(50);
		DisallowedZoneMap[43].push_back(51);
		DisallowedZoneMap[43].push_back(52);
	}

	// rook piece has it's own special logic, but also not labs

	// bishop, knight, pawn, all not labs

	// t-bar valve
	DisallowedZoneMap[167].push_back(35);
	DisallowedZoneMap[167].push_back(36);
	DisallowedZoneMap[167].push_back(37);
	DisallowedZoneMap[167].push_back(50);
	DisallowedZoneMap[167].push_back(51);
	DisallowedZoneMap[167].push_back(52);

	// also t-bar valve and sewer key as both are needed for RPD sewer back access
	for (uint32_t i = 1; i < 34; ++i)
	{
		DisallowedZoneMap[167].push_back(i);
		DisallowedZoneMap[170].push_back(i);
	}

	// sewer key
	DisallowedZoneMap[170].push_back(31);
	DisallowedZoneMap[170].push_back(33);
	DisallowedZoneMap[170].push_back(50);
	DisallowedZoneMap[170].push_back(51);
	DisallowedZoneMap[170].push_back(52);

	// queen plug
	DisallowedZoneMap[177].push_back(36);
	DisallowedZoneMap[177].push_back(37);

	// king plug
	DisallowedZoneMap[178].push_back(37);

	// film - hiding place, doesn't matter atm

	// do all the lab denials here
	for (uint32_t i = 38; i < 50; ++i)
	{
		DisallowedZoneMap[2].push_back(i);  // lion
		DisallowedZoneMap[58].push_back(i); // maiden
		DisallowedZoneMap[63].push_back(i); // unicorn
		DisallowedZoneMap[30].push_back(i); // detonator, no battery
		DisallowedZoneMap[95].push_back(i); // battery
		DisallowedZoneMap[36].push_back(i); // mechanic jack handle
		DisallowedZoneMap[41].push_back(i); // valve
		DisallowedZoneMap[43].push_back(i); // main fuse hall
		DisallowedZoneMap[50].push_back(i); // portable safes
		DisallowedZoneMap[101].push_back(i);
		DisallowedZoneMap[53].push_back(i); // spade key
		DisallowedZoneMap[61].push_back(i); // red book
		DisallowedZoneMap[66].push_back(i); // weapons locker key
		DisallowedZoneMap[67].push_back(i); // statue's left arm
		DisallowedZoneMap[68].push_back(i); // scepter
		DisallowedZoneMap[71].push_back(i); // bolt cutters
		DisallowedZoneMap[74].push_back(i); // small gear
		DisallowedZoneMap[75].push_back(i); // boxed electronic parts
		DisallowedZoneMap[132].push_back(i);
		DisallowedZoneMap[77].push_back(i);  // large gear
		DisallowedZoneMap[88].push_back(i);  // club key
		DisallowedZoneMap[91].push_back(i);  // bejeweled box
		DisallowedZoneMap[119].push_back(i); // square crank
		DisallowedZoneMap[126].push_back(i); // diamond key

		DisallowedZoneMap[heartid].push_back(i); // relief

		DisallowedZoneMap[127].push_back(i);    // car key
		DisallowedZoneMap[fuseid].push_back(i); // fuse break room hallway
		DisallowedZoneMap[163].push_back(i);    // bishop
		DisallowedZoneMap[164].push_back(i);    // knight
		DisallowedZoneMap[165].push_back(i);    // pawn
		DisallowedZoneMap[167].push_back(i);    // t-bar valve
		DisallowedZoneMap[170].push_back(i);    // sewer key
		DisallowedZoneMap[177].push_back(i);    // queen plug
		DisallowedZoneMap[178].push_back(i);    // king plug
		DisallowedZoneMap[181].push_back(i);    // film, hiding place
	}

	// sewer transition area
	DisallowedZoneMap[2].push_back(29);  // lion
	DisallowedZoneMap[58].push_back(29); // maiden
	DisallowedZoneMap[63].push_back(29); // unicorn
	DisallowedZoneMap[30].push_back(29); // detonator, no battery
	DisallowedZoneMap[95].push_back(29); // battery
	DisallowedZoneMap[36].push_back(29); // mechanic jack handle
	DisallowedZoneMap[41].push_back(29); // valve
	DisallowedZoneMap[43].push_back(29); // main fuse hall
	DisallowedZoneMap[50].push_back(29); // portable safes
	DisallowedZoneMap[101].push_back(29);
	DisallowedZoneMap[53].push_back(29); // spade key
	DisallowedZoneMap[61].push_back(29); // red book
	DisallowedZoneMap[66].push_back(29); // weapons locker key
	DisallowedZoneMap[67].push_back(29); // statue's left arm
	DisallowedZoneMap[68].push_back(29); // scepter
	DisallowedZoneMap[71].push_back(29); // bolt cutters
	DisallowedZoneMap[74].push_back(29); // small gear
	DisallowedZoneMap[75].push_back(29); // boxed electronic parts
	DisallowedZoneMap[132].push_back(29);
	DisallowedZoneMap[77].push_back(29);  // large gear
	DisallowedZoneMap[88].push_back(29);  // club key
	DisallowedZoneMap[91].push_back(29);  // bejeweled box
	DisallowedZoneMap[119].push_back(29); // square crank
	DisallowedZoneMap[126].push_back(29); // diamond key

	DisallowedZoneMap[heartid].push_back(29); // relief

	DisallowedZoneMap[127].push_back(29);    // car key
	DisallowedZoneMap[fuseid].push_back(29); // fuse break room hallway
	DisallowedZoneMap[163].push_back(29);    // bishop
	DisallowedZoneMap[164].push_back(29);    // knight
	DisallowedZoneMap[165].push_back(29);    // pawn
	DisallowedZoneMap[167].push_back(29);    // t-bar valve
	DisallowedZoneMap[170].push_back(29);    // sewer key
	DisallowedZoneMap[177].push_back(29);    // queen plug
	DisallowedZoneMap[178].push_back(29);    // king plug
	DisallowedZoneMap[181].push_back(29);    // film, hiding place

	// LAB STUFF

	// first we deny rpd + sewers for all
	// first we deny rpd + sewers for all
	for (uint32_t i = 1; i < 39; i++)
	{

		DisallowedZoneMap[199].push_back(i); // upgrade chip (general staff)
		DisallowedZoneMap[204].push_back(i); // dispersal cartridge (empty)
		DisallowedZoneMap[208].push_back(i); // upgrade chip (senior staff)
		DisallowedZoneMap[221].push_back(i); // signal modulator
		DisallowedZoneMap[246].push_back(i); // joint plug
	}

	// also the extra shotgun shells I fucked up
	DisallowedZoneMap[199].push_back(250); // upgrade chip (general staff)
	DisallowedZoneMap[204].push_back(250); // dispersal cartridge (empty)
	DisallowedZoneMap[208].push_back(250); // upgrade chip (senior staff)
	DisallowedZoneMap[221].push_back(250); // signal modulator
	DisallowedZoneMap[246].push_back(250); // joint plug

	// general staff chip, special logic

	// dispersal cartridge
	DisallowedZoneMap[204].push_back(44);
	DisallowedZoneMap[204].push_back(45);
	DisallowedZoneMap[204].push_back(46);
	DisallowedZoneMap[204].push_back(47);
	DisallowedZoneMap[204].push_back(48);
	DisallowedZoneMap[204].push_back(49);
	DisallowedZoneMap[204].push_back(50);
	DisallowedZoneMap[204].push_back(51);
	DisallowedZoneMap[204].push_back(52);

	// upgrade chip (senior staff)
	DisallowedZoneMap[208].push_back(44);
	DisallowedZoneMap[208].push_back(45);
	DisallowedZoneMap[208].push_back(46);
	DisallowedZoneMap[208].push_back(47);
	DisallowedZoneMap[208].push_back(48);
	DisallowedZoneMap[208].push_back(49);
	DisallowedZoneMap[208].push_back(50);
	DisallowedZoneMap[208].push_back(51);
	DisallowedZoneMap[208].push_back(52);

	// signal modulator
	DisallowedZoneMap[221].push_back(41);
	DisallowedZoneMap[221].push_back(43);
	DisallowedZoneMap[221].push_back(45);
	DisallowedZoneMap[221].push_back(46);
	DisallowedZoneMap[221].push_back(47);
	DisallowedZoneMap[221].push_back(48);
	DisallowedZoneMap[221].push_back(49);
	DisallowedZoneMap[221].push_back(50);
	DisallowedZoneMap[221].push_back(51);
	DisallowedZoneMap[221].push_back(52);

	// joint plug
	for (uint32_t i = 39; i < 49; i++)
	{
		DisallowedZoneMap[246].push_back(i); // joint plug
	}

	DisallowedZoneMap[246].push_back(50);
	DisallowedZoneMap[246].push_back(51);
	DisallowedZoneMap[246].push_back(52);

	// main hall

	if (difficulty == Hardcore)
	{
		ItemNames.push_back("Ink Ribbon x2");
	}
	else
	{

		if (scenario == A)
		{
			ItemNames.push_back("Handgun Bullets");
		}
		else
		{
			ItemNames.push_back("ACP Ammo");
		}
	}

	ItemNames.push_back("First Aid Spray");
	ItemNames.push_back("Lion Medallion");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets (upstairs)");
		ItemNames.push_back("Combat Knife (Marvin gift)");

		// reception
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{

		ItemNames.push_back("ACP Ammo (upstairs)");

		if (character == Leon)
		{
			ItemNames.push_back("M19");
		}
		else
		{
			ItemNames.push_back("Quickdraw Army");
		}

		// reception
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Green Herb");

	if (scenario == A)
	{
		// operations room
		ItemNames.push_back("Handgun Bullets");

		// western area 1F
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		// operations room
		ItemNames.push_back("ACP Ammo");

		// western area 1F
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Green Herb");
	ItemNames.push_back("Wooden Boards");

	// west office
	ItemNames.push_back("Gunpowder");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Hip Pouch");

	if (character == Leon)
	{
		ItemNames.push_back("High-Capacity Mag (Matilda)");
	}
	else
	{
		ItemNames.push_back("Speed Loader (SLS 60)");
	}

	// dark room
	ItemNames.push_back("Gunpowder");

	if (difficulty == Hardcore)
	{
		ItemNames.push_back("Ink Ribbon x3");
	}
	else
	{

		if (scenario == A)
		{
			ItemNames.push_back("Handgun Bullets");
		}
		else
		{
			ItemNames.push_back("ACP Ammo");
		}
	}

	ItemNames.push_back("Red Herb");

	// safety deposit room
	ItemNames.push_back("Film: Commemorative");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Combat Knife");
	ItemNames.push_back("Gunpowder");
	ItemNames.push_back("Hip Pouch");

	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Shells (Locker)");
		ItemNames.push_back("Shotgun");
		ItemNames.push_back("Shotgun Shells (Shotgun Cupboard)");
	}
	else
	{
		ItemNames.push_back("Flame Rounds (Locker)");
		ItemNames.push_back("GM 79");
		ItemNames.push_back("Flame Rounds (GM 79 Cupboard)");
	}

	if (scenario == A)
	{
		// press room
		ItemNames.push_back("Handgun Bullets");

		// east closet ambush
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		// press room
		ItemNames.push_back("ACP Ammo");

		// east closet ambush
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Wooden Boards");

	// bathroom
	ItemNames.push_back("First Aid Spray");

	// detonator room
	ItemNames.push_back("Detonator (No Battery)");
	ItemNames.push_back("Green Herb");
	ItemNames.push_back("Flash Grenade");
	ItemNames.push_back("Wooden Boards");

	// records room
	ItemNames.push_back("Hand Grenade");

	if (difficulty == Hardcore)
	{
		ItemNames.push_back("Ink Ribbon x2");
	}
	else
	{
		ItemNames.push_back("Gunpowder");
	}

	ItemNames.push_back("Mechanic Jack Handle");

	// east office

	if (difficulty == Hardcore)
	{
		ItemNames.push_back("Ink Ribbon x2");
	}
	else
	{
		ItemNames.push_back("Green Herb");
	}

	ItemNames.push_back("Flash Grenade");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Gunpowder");
	ItemNames.push_back("Valve");

	if (character == Leon)
	{
		ItemNames.push_back("Yellow Gunpowder");
	}
	else
	{
		ItemNames.push_back("White Gunpowder");
	}

	if (scenario == A)
	{
		ItemNames.push_back("Fuse (Main Hall)");
	}
	else
	{
		ItemNames.push_back("Courtyard Key");
	}

	// waiting room
	ItemNames.push_back("Green Herb");

	if (character == Leon)
	{
		ItemNames.push_back("Muzzle Brake (Matilda)");
	}
	else
	{
		ItemNames.push_back("High-Capacity Mag (JMB Hp3)");
	}

	// western area 2F

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Red Herb");

	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Shells");
		ItemNames.push_back("Shotgun Shells");
	}
	else
	{
		ItemNames.push_back("Flame Rounds");
		ItemNames.push_back("Flame Rounds");
	}

	if (scenario == A)
	{

		ItemNames.push_back("Portable Safe");

		// western area 3F
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{

		ItemNames.push_back("Bejeweled Box");

		// western area 3F
		ItemNames.push_back("ACP Ammo");
	}

	if (character == Leon)
	{
		ItemNames.push_back("Mag Ammo");
	}
	else
	{
		ItemNames.push_back("Submachinegun Ammo");
	}

	ItemNames.push_back("Spade Key");

	// west storage room
	ItemNames.push_back("Gunpowder");
	ItemNames.push_back("Wooden Boards");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	if (difficulty == Hardcore)
	{
		ItemNames.push_back("Hip Pouch (REMOVED IN HARDCORE)");
	}
	else
	{
		ItemNames.push_back("Hip Pouch");
	}

	// maiden statue area
	ItemNames.push_back("Maiden Medallion");

	// library

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Combat Knife");
	ItemNames.push_back("Red Book");

	// lounge
	if (scenario == A)
	{
		ItemNames.push_back("Gunpowder");
	}
	else
	{
		ItemNames.push_back("Lion Statue Film Box");
	}

	ItemNames.push_back("Unicorn Medallion");

	// chopper crash area
	ItemNames.push_back("Wooden Boards");
	ItemNames.push_back("Green Herb");

	// art room
	ItemNames.push_back("Weapons Locker Key");
	ItemNames.push_back("Statue's Left Arm");
	ItemNames.push_back("Scepter");

	// fire escape

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Wooden Boards");
	ItemNames.push_back("Bolt Cutters");

	// Main Hall 3F
	ItemNames.push_back("Green Herb");

	// Raccoon Area West
	ItemNames.push_back("Large Gunpowder");

	// clock tower
	ItemNames.push_back("Small Gear");
	ItemNames.push_back("Boxed Electronic Part");

	// east storage room
	ItemNames.push_back("Blue Herb");
	ItemNames.push_back("Large Gear");

	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Shells");
	}
	else
	{
		ItemNames.push_back("Flame Rounds");
	}

	// east area 3F

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Flash Grenade");
	ItemNames.push_back("Wooden Boards");

	// balcony
	ItemNames.push_back("Blue Herb");

	// roof area

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Red Herb");
	ItemNames.push_back("Green Herb (Left)");
	ItemNames.push_back("Green Herb (Right)");

	if (character == Leon)
	{

		// boiler room
		if (difficulty == Hardcore)
		{
			ItemNames.push_back("Ink Ribbon x1");
		}
		else
		{
			ItemNames.push_back("Gunpowder");
		}

		ItemNames.push_back("Club Key");
	}
	else
	{
		ItemNames.push_back("Blue Herb");
		ItemNames.push_back("Shoulder Stock (GM 79)");
	}

	// outside observation room
	if (character == Leon)
	{
		ItemNames.push_back("Yellow Gunpowder");
	}
	else
	{
		ItemNames.push_back("White Gunpowder");
	}

	// observation room
	ItemNames.push_back("Gunpowder");

	if (scenario == A)
	{
		ItemNames.push_back("Bejeweled Box");

		// interrogation room
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{

		ItemNames.push_back("Portable Safe");

		// interrogation room
		ItemNames.push_back("ACP Ammo");
	}

	// outside stars office
	ItemNames.push_back("Gunpowder");

	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Shells");
	}
	else
	{
		ItemNames.push_back("Flame Rounds");
	}

	// stars office
	ItemNames.push_back("Battery");
	ItemNames.push_back("Red Herb");
	ItemNames.push_back("Flash Grenade");
	ItemNames.push_back("First Aid Spray");

	if (character == Leon)
	{
		ItemNames.push_back("Yellow Gunpowder");
		ItemNames.push_back("Lightning Hawk");
	}
	else
	{
		ItemNames.push_back("White Gunpowder");
		ItemNames.push_back("MQ 11");
	}

	// linen room
	ItemNames.push_back("Portable Safe");
	ItemNames.push_back("Gunpowder");

	// secret room
	ItemNames.push_back("Gunpowder");

	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Shells");
	}
	else
	{
		ItemNames.push_back("Flame Rounds");
	}

	// underground stairs
	ItemNames.push_back("Hand Grenade");

	if (character == Leon)
	{
		ItemNames.push_back("Long Barrel (Lightning Hawk)");
	}
	else
	{
		ItemNames.push_back("Suppressor (MQ-11)");
	}

	// machinery room

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets (Top Left)");
	}
	else
	{
		ItemNames.push_back("ACP Ammo (Top Left)");
	}

	ItemNames.push_back("Hand Grenade");
	ItemNames.push_back("Green Herb (Top Left)");
	ItemNames.push_back("Red Herb");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets (Bottom Left)");
	}
	else
	{
		ItemNames.push_back("ACP Ammo (Bottom Left)");
	}

	ItemNames.push_back("Green Herb (Bottom Right)");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets (Bottom Right)");
	}
	else
	{
		ItemNames.push_back("ACP Ammo (Bottom Right)");
	}

	ItemNames.push_back("Gunpowder");
	ItemNames.push_back("Green Herb (Up Ladder)");

	// operators room
	if (difficulty == Hardcore)
	{
		ItemNames.push_back("Ink Ribbon x1");
	}
	else
	{
		ItemNames.push_back("Hip Pouch");
	}

	// parking garage
	if (character == Leon)
	{
		ItemNames.push_back("Gun Stock (Matilda)");
	}
	else
	{
		ItemNames.push_back("JMB Hp3");
	}

	if (character == Leon)
	{

		// Jail entrance
		if (scenario == A)
		{
			ItemNames.push_back("Handgun Bullets");
		}
		else
		{
			ItemNames.push_back("ACP Ammo");
		}

		// Jail
		ItemNames.push_back("Square Crank");
		ItemNames.push_back("Parking Garage Key Card");
		ItemNames.push_back("First Aid Spray");
	}
	else
	{

		ItemNames.push_back("White Gunpowder");
		ItemNames.push_back("Minigun");
		ItemNames.push_back("Parking Garage Key Card");
		ItemNames.push_back("First Aid Spray");
	}

	// outside kennel
	ItemNames.push_back("Blue Herb");

	// kennel
	if (character == Leon)
	{
		ItemNames.push_back("Yellow Gunpowder");
	}
	else
	{
		ItemNames.push_back("White Gunpowder");
	}

	// morgue
	ItemNames.push_back("Red Herb");
	ItemNames.push_back("Flash Grenade");
	ItemNames.push_back("Diamond Key");

	// firing range
	ItemNames.push_back("Car Key");

	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Shells");
	}
	else
	{
		ItemNames.push_back("Flame Rounds");
	}

	// firing range lockers
	ItemNames.push_back("Film: 3F Locker");
	ItemNames.push_back("Red Herb");

	if (character == Leon)
	{

		// generator room

		if (scenario == A)
		{
			ItemNames.push_back("Green Herb");
		}
		else
		{
			ItemNames.push_back("Heart Key (replaces Green Herb)");
		}

		ItemNames.push_back("Boxed Electronic Part");
		ItemNames.push_back("Gunpowder");

		// outside break room
		ItemNames.push_back("Shotgun Shells");
		ItemNames.push_back("Combat Knife");

		// break room
		ItemNames.push_back("Blue Herb");

		if (scenario == A)
		{
			ItemNames.push_back("Handgun Bullets");
		}
		else
		{
			ItemNames.push_back("ACP Ammo");
		}

		ItemNames.push_back("Mag Ammo");
		ItemNames.push_back("Fuse (Break Room Hallway)");

		ItemNames.push_back("Yellow Gunpowder");

		// outside RPD
		ItemNames.push_back("Green Herb");

		// gun shop
		ItemNames.push_back("Hand Grenade");

		if (scenario == A)
		{
			ItemNames.push_back("Handgun Bullets");
		}
		else
		{
			ItemNames.push_back("ACP Ammo");
		}

		ItemNames.push_back("Long Barrel (W-870)");

		// sewer entrance
		ItemNames.push_back("Hand Grenade");

		if (scenario == A)
		{
			ItemNames.push_back("Handgun Bullets");
		}
		else
		{
			ItemNames.push_back("ACP Ammo");
		}

		if (difficulty == Hardcore)
		{
			ItemNames.push_back("Ink Ribbon x2");
		}
		else
		{
			if (scenario == A)
			{
				ItemNames.push_back("Handgun Bullets");
			}
			else
			{
				ItemNames.push_back("ACP Ammo");
			}
		}
	}
	else
	{

		ItemNames.push_back("Green Herb");
		ItemNames.push_back("Boxed Electronic Part");
		ItemNames.push_back("Green Herb");
		ItemNames.push_back("High-Powered Rounds (SLS 60)");
		ItemNames.push_back("Combat Knife");
		ItemNames.push_back("Blue Herb");
		ItemNames.push_back("Submachinegun Ammo");
		ItemNames.push_back("Submachinegun Ammo");
		ItemNames.push_back("Lovers Relief");

		if (difficulty == Hardcore)
		{
			ItemNames.push_back("Ink Ribbon x1");
		}
		else
		{
			ItemNames.push_back("White Gunpowder");
		}

		ItemNames.push_back("Green Herb");
		ItemNames.push_back("Hand Grenade");
		ItemNames.push_back("Submachinegun Ammo");

		if (scenario == A)
		{

			ItemNames.push_back("UNUSED");
			ItemNames.push_back("UNUSED");
			ItemNames.push_back("UNUSED");
			ItemNames.push_back("UNUSED");
		}
		else
		{

			ItemNames.push_back("Flame Rounds");
			ItemNames.push_back("Submachinegun Ammo");
			ItemNames.push_back("Club Key");
			ItemNames.push_back("Square Crank");
		}
	}

	// upper walkway
	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Shells");
	}
	else
	{
		ItemNames.push_back("High-Powered Rounds (SLS 60)");
	}

	// rook bridge area
	ItemNames.push_back("USS Digital Video Casette");
	ItemNames.push_back("Rook Plug");

	// workers break room
	ItemNames.push_back("Gunpowder");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	// RPD Access Room
	if (character == Leon)
	{
		ItemNames.push_back("Mag Ammo");
	}
	else
	{
		ItemNames.push_back("High-Powered Rounds (SLS 60)");
	}

	// Lower Waterway Pre-Slide
	ItemNames.push_back("Combat Knife");

	// water injection chamber
	ItemNames.push_back("Large Gunpowder");

	if (character == Leon)
	{

		if (difficulty == Hardcore)
		{
			ItemNames.push_back("Ink Ribbon x2");
		}
		else
		{
			ItemNames.push_back("Yellow Gunpowder");
		}

		// lower waterway
		ItemNames.push_back("Yellow Gunpowder");
	}
	else
	{

		if (difficulty == Hardcore)
		{
			ItemNames.push_back("Ink Ribbon x2");
		}
		else
		{
			ItemNames.push_back("White Gunpowder");
		}

		// lower waterway
		ItemNames.push_back("White Gunpowder");
	}

	ItemNames.push_back("Blue Herb");

	if (character == Leon)
	{
		// control room
		ItemNames.push_back("Shotgun Shells");
		ItemNames.push_back("Mag Ammo");
	}
	else
	{
		ItemNames.push_back("Flame Rounds");
		ItemNames.push_back("Submachinegun Ammo");
	}

	// monitor room
	if (difficulty == Hardcore)
	{
		ItemNames.push_back("Ink Ribbon x2");
	}
	else
	{
		if (scenario == A)
		{
			ItemNames.push_back("Handgun Bullets");
		}
		else
		{
			ItemNames.push_back("ACP Ammo");
		}
	}

	ItemNames.push_back("Bishop Plug");
	ItemNames.push_back("Knight Plug");
	ItemNames.push_back("Pawn Plug");

	// treatment pool room
	ItemNames.push_back("Red Herb");
	ItemNames.push_back("T-Bar Valve");
	ItemNames.push_back("Blue Herb");

	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Stock (W-870)");
	}
	else
	{
		ItemNames.push_back("Reinforced Frame (SLS 60)");
	}

	// bottom waterway overpass
	ItemNames.push_back("Sewer Key");
	ItemNames.push_back("Green Herb");
	ItemNames.push_back("Hand Grenade");

	// bottom waterway
	ItemNames.push_back("Green Herb");

	if (character == Leon)
	{
		ItemNames.push_back("Mag Ammo");
	}
	else
	{
		ItemNames.push_back("Submachinegun Ammo");
	}

	// supplies storage room
	ItemNames.push_back("Red Herb");
	ItemNames.push_back("Blue Herb");
	ItemNames.push_back("Queen Plug");
	ItemNames.push_back("King Plug");

	if (character == Leon)
	{
		ItemNames.push_back("Flamethrower");
	}
	else
	{
		ItemNames.push_back("Spark Shot");
	}

	// work room

	if (difficulty == Hardcore)
	{
		ItemNames.push_back("Hip Pouch (REMOVED IN HARDCORE)");
	}
	else
	{
		ItemNames.push_back("Hip Pouch");
	}

	ItemNames.push_back("Film - Hiding Place");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	// work room lift
	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Shells");
	}
	else
	{
		ItemNames.push_back("High-Powered Rounds (SLS 60)");
	}

	// outside garbage room
	ItemNames.push_back("Blue Herb");
	ItemNames.push_back("Green Herb");

	// main power room
	ItemNames.push_back("Red Herb");

	// g2 fight room
	if (character == Leon)
	{
		ItemNames.push_back("Mag Ammo");
	}
	else
	{
		ItemNames.push_back("Submachinegun Ammo");
	}

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Flash Grenade");
	ItemNames.push_back("Combat Knife");

	// security room
	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Shells");
	}
	else
	{
		ItemNames.push_back("Flame Rounds");
	}

	// cafeteria
	ItemNames.push_back("Hand Grenade");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	if (character == Leon)
	{
		ItemNames.push_back("Flamethrower Fuel");
	}
	else
	{
		ItemNames.push_back("Needle Cartridges");
	}

	// kitchen
	ItemNames.push_back("Large Gunpowder");
	ItemNames.push_back("Combat Knife");

	// nap room
	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Shells");
		ItemNames.push_back("Regulator (Flamethrower)");
	}
	else
	{
		ItemNames.push_back("Flame Rounds");
		ItemNames.push_back("High Voltage Condenser (Spark Shot)");
	}

	ItemNames.push_back("Upgrade Chip (General Staff)");
	ItemNames.push_back("Hip Pouch");

	// lobby
	if (difficulty == Hardcore)
	{
		ItemNames.push_back("Ink Ribbon x2");
	}
	else
	{
		ItemNames.push_back("Green Herb");
	}

	ItemNames.push_back("Gunpowder");

	// first plant room
	if (character == Leon)
	{
		ItemNames.push_back("Yellow Gunpowder");
	}
	else
	{
		ItemNames.push_back("White Gunpowder");
	}

	// greenhouse control room
	ItemNames.push_back("Dispersal Cartridge (Empty)");
	ItemNames.push_back("Flash Grenade");

	// greenhouse
	ItemNames.push_back("Red Herb");
	ItemNames.push_back("Blue Herb");
	ItemNames.push_back("Upgrade Chip (Senior Staff)");

	// drug testing lab
	ItemNames.push_back("Large Gunpowder");
	ItemNames.push_back("Hand Grenade");

	// underneath greenhouse
	ItemNames.push_back("Large Gunpowder");

	// lounge
	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Shells");
	}
	else
	{
		ItemNames.push_back("Flame Rounds");
	}

	ItemNames.push_back("Trophy");
	ItemNames.push_back("Green Herb");

	// server room
	if (character == Leon)
	{
		ItemNames.push_back("Flamethrower Fuel");
		ItemNames.push_back("Yellow Gunpowder");
	}
	else
	{
		ItemNames.push_back("Flame Rounds");
		ItemNames.push_back("White Gunpowder");
	}

	ItemNames.push_back("Combat Knife");

	// low temp testing lab
	ItemNames.push_back("Gunpowder");

	// modulator room
	if (character == Leon)
	{
		ItemNames.push_back("Yellow Gunpowder");
	}
	else
	{
		ItemNames.push_back("White Gunpowder");
	}

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	ItemNames.push_back("Signal Modulator");

	// biotesting lab
	ItemNames.push_back("Lab Digital Video Cassette");
	ItemNames.push_back("Hand Grenade");
	ItemNames.push_back("Blue Herb");

	if (difficulty == Hardcore)
	{
		ItemNames.push_back("Removed Item in Hardcore");
	}
	else
	{

		if (character == Leon)
		{
			ItemNames.push_back("Yellow Gunpowder");
		}
		else
		{
			ItemNames.push_back("White Gunpowder");
		}
	}

	// p4 level testing lab
	ItemNames.push_back("Large Gunpowder");

	if (character == Leon)
	{
		ItemNames.push_back("Yellow Gunpowder");
	}
	else
	{
		ItemNames.push_back("White Gunpowder");
	}

	if (difficulty == Hardcore)
	{
		ItemNames.push_back("Ink Ribbon x1");
	}
	else
	{
		ItemNames.push_back("Red Herb");
	}

	// bioreactors room
	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets (Top Left)");
	}
	else
	{
		ItemNames.push_back("ACP Ammo (Top Left)");
	}

	ItemNames.push_back("First Aid Spray");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets (Bottom Left)");
	}
	else
	{
		ItemNames.push_back("ACP Ammo (Bottom Left)");
	}

	if (character == Leon)
	{
		ItemNames.push_back("Mag Ammo");
	}
	else
	{
		ItemNames.push_back("High-Powered Rounds (SLS 60)");
	}

	ItemNames.push_back("Flash Grenade (Bottom Left)");

	if (character == Leon)
	{
		ItemNames.push_back("Flamethrower Fuel");
	}
	else
	{
		ItemNames.push_back("Needle Cartridges");
	}

	ItemNames.push_back("Hand Grenade");
	ItemNames.push_back("Flash Grenade (Top Right)");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets (Bottom Right, Left)");
		ItemNames.push_back("Handgun Bullets (Bottom Right, Right)");
	}
	else
	{
		ItemNames.push_back("ACP Ammo (Bottom Right, Left)");
		ItemNames.push_back("ACP Ammo (Bottom Right, Right)");
	}

	// monitor room
	ItemNames.push_back("First Aid Spray");
	ItemNames.push_back("Combat Knife");

	// pump room
	ItemNames.push_back("Blue Herb");
	ItemNames.push_back("Green Herb");

	if (scenario == A)
	{
		ItemNames.push_back("Handgun Bullets");
	}
	else
	{
		ItemNames.push_back("ACP Ammo");
	}

	// escape shaft
	ItemNames.push_back("Red Herb");

	if (character == Leon)
	{
		if (scenario == A)
		{
			ItemNames.push_back("Handgun Bullets");
		}
		else
		{
			ItemNames.push_back("ACP Ammo");
		}
	}
	else
	{
		ItemNames.push_back("Submachinegun Ammo");
	}

	ItemNames.push_back("Joint Plug");

	// extra
	if (character == Leon)
	{
		ItemNames.push_back("Flamethrower Fuel x400");
		ItemNames.push_back("Wooden Box");
	}
	else
	{
		ItemNames.push_back("Needle Cartridges x7");
		ItemNames.push_back("High-Capacity Mag (MQ-11)");
	}

	ItemNames.push_back("Film: Rising Rookie");

	if (character == Leon)
	{
		ItemNames.push_back("Shotgun Shells");
	}
	else
	{
		ItemNames.push_back("Flame Rounds");
	}

	// hardcore extra ink ribbons, adding all these into the seed every time now.
	// if (difficulty == Hardcore)
	{

		ItemNames.push_back("Ink Ribbon x1"); // lab reception
		ItemNames.push_back("Ink Ribbon x1"); // escape typewriter
		ItemNames.push_back("Ink Ribbon x2"); // interrogation room

		// claire gets two more
		// if (character == Claire)
		{
			ItemNames.push_back("Ink Ribbon x1"); // sherry in ribbon
			ItemNames.push_back("Ink Ribbon x2"); // office area after doing Sherry bit before sewers
		}
	}

	if (scenario == B)
	{

		ItemNames.push_back("ACP Ammo");     // stars office ammo, b scenario
		ItemNames.push_back("Red Herb");     // outside fire escape, b scenario
		ItemNames.push_back("Blue Herb");    // outside fire escape, b scenario
		ItemNames.push_back("Hand Grenade"); // guard room, b scenario
		ItemNames.push_back("ACP Ammo");     // guard room, b scenario

		if (character == Claire)
		{
			ItemNames.push_back("Combat Knife");              // outside break room, claire b scenario
			ItemNames.push_back("Blue Herb");                 // break room, claire b scenario
			ItemNames.push_back("White Gunpowder");           // break room, claire b scenario
			ItemNames.push_back("ACP Ammo");                  // break room, claire b scenario
			ItemNames.push_back("Fuse (Break Room Hallway)"); // break room, claire b scenario
		}
		else
		{
			ItemNames.push_back("UNUSED");
			ItemNames.push_back("UNUSED");
			ItemNames.push_back("UNUSED");
			ItemNames.push_back("UNUSED");
			ItemNames.push_back("UNUSED");
		}
	}
	else
	{
		ItemNames.push_back("UNUSED");
		ItemNames.push_back("UNUSED");
		ItemNames.push_back("UNUSED");
		ItemNames.push_back("UNUSED");
		ItemNames.push_back("UNUSED");
		ItemNames.push_back("UNUSED");
		ItemNames.push_back("UNUSED");
		ItemNames.push_back("UNUSED");
		ItemNames.push_back("UNUSED");
		ItemNames.push_back("UNUSED");
	}

	m_ListLength = ItemNames.size();

	unsigned int n = std::thread::hardware_concurrency();

	logger->LogMessage("Generating seed using %d threads, application may be unresponsive while generating seed...", n);

	// n = 1; //I use this for debugging

	if (n == 0)
	{
		n = 1;
	}

	std::vector<SeedShuffler *> shufflers;
	shufflers.reserve(n);
	for (unsigned int i = 0; i < n; ++i)
	{
		SeedShuffler *newInstance = new SeedShuffler(character, scenario, difficulty, m_ListLength, m_HasFoundSeed, ItemNames, DisallowedZoneMap, ZoneIDByItemID, ZoneRequiredItems);
		shufflers.push_back(newInstance);
		m_Futures.push_back(std::async(&SeedShuffler::AsyncShuffle, newInstance, i));
	}

	bool alldone = false;

	while (alldone == false)
	{

		for (auto &e : m_Futures)
		{

			std::future_status status;

			status = e.wait_for(std::chrono::milliseconds(250));

			// ProcessMessage();

			if (status == std::future_status::timeout)
			{
				logger->LogMessage(" .");
			}
			else if (status == std::future_status::ready)
			{

				std::vector<uint32_t> result = e.get();

				if (result.empty())
				{
					// logger->LogMessage("Thread closed!\n");
				}
				else
				{
					logger->LogMessage("Seed generated!\n");
					finalList = result;
					CreateCheatSheetVector(character, scenario, difficulty, mixWeapons);
					alldone = true;

					if (mixWeapons)
					{
						MixWeapons(character, scenario, difficulty);
					}

					WriteDataToFile(character, scenario, difficulty, mixWeapons);
					break;
				}
			}
		}
	}
	for (unsigned int i = 0; i < n; ++i)
		delete shufflers[i];
	shufflers.clear();

	logger->LogMessage("All Finished!\n");

	// logger->LogMessage("done after %d attempts!\n", total);
	// WriteDataToFile(character, scenario, difficulty, mixWeapons);
}

void SeedGenerator::MixWeapons(Character character, Scenario scenario, Difficulty UNUSED(difficulty))
{

	logger->LogMessage("Shuffling Weapons/Ammo/Powders...");

	std::vector<uint32_t> weaponsandupgrades;

	weaponsandupgrades.push_back(266); // shotgun
	weaponsandupgrades.push_back(267); // lightning hawk
	weaponsandupgrades.push_back(268); // flamethrower
	weaponsandupgrades.push_back(269); // grenade launcher
	weaponsandupgrades.push_back(270); // MQ 11
	weaponsandupgrades.push_back(271); // JMP Hp3
	weaponsandupgrades.push_back(272); // Spark Shot
	weaponsandupgrades.push_back(273); // Minigun

	if (character == Claire)
	{
		weaponsandupgrades.push_back(274); // Leon's Rocket Launcher
		weaponsandupgrades.push_back(275); // Leon's Matilda
	}
	else
	{
		weaponsandupgrades.push_back(276); // Claire's SLS
	}

	weaponsandupgrades.push_back(277); // speed loader
	weaponsandupgrades.push_back(278); // high-capacity mag (matilda)
	weaponsandupgrades.push_back(279); // muzzle brake (matilda)
	weaponsandupgrades.push_back(280); // Long Barrel Lightning Hawk
	weaponsandupgrades.push_back(281); // Long Barrel W-870
	weaponsandupgrades.push_back(282); // Shotgun Stock W-870
	weaponsandupgrades.push_back(283); // Flamethrower Regulator
	weaponsandupgrades.push_back(284); // Red Dot Lightning Hawk
	weaponsandupgrades.push_back(285); // HP3 mag
	weaponsandupgrades.push_back(286); // MQ 11 supressor
	weaponsandupgrades.push_back(287); // SLS reinforcement upgrade
	weaponsandupgrades.push_back(288); // high voltage condenser
	weaponsandupgrades.push_back(289); // MQ 11 ammo expander
	weaponsandupgrades.push_back(290); // Shoulder Stock (GM 79)
	weaponsandupgrades.push_back(291); // gun stock, matilda

	// all the other stuff

	for (uint32_t i = 0; i < 40; ++i)
	{

		m_AmmoGunpowderList.push_back(292); // handgun ammo

		if (i < 2)
		{
			m_AmmoGunpowderList.push_back(293); // Needle cartridge, regular
		}

		if (i < 3)
		{
			m_AmmoGunpowderList.push_back(294); // flamethrower fuel, regular
		}

		if (i < 5)
		{
			m_AmmoGunpowderList.push_back(295); // SLS ammo
		}

		if (i < 6)
		{
			m_AmmoGunpowderList.push_back(296); // large gunpowder
		}

		if (i < 7)
		{
			m_AmmoGunpowderList.push_back(297); // mag ammo
		}

		if (i < 8)
		{
			m_AmmoGunpowderList.push_back(298); // knife
			m_AmmoGunpowderList.push_back(299); // submachine gun rounds
		}

		if (i < 9)
		{
			m_AmmoGunpowderList.push_back(300); // hand grenade
			m_AmmoGunpowderList.push_back(301); // flash grenade
		}

		if (i < 12)
		{
			m_AmmoGunpowderList.push_back(302); // yellow gunpowder
		}

		if (i < 13)
		{
			m_AmmoGunpowderList.push_back(303); // flame rounds
			m_AmmoGunpowderList.push_back(304); // white gunpowder
		}

		if (i < 16)
		{
			m_AmmoGunpowderList.push_back(305); // shotgun shells
		}

		if (i < 17)
		{
			m_AmmoGunpowderList.push_back(306); // gunpowder
		}
	}

	m_AmmoGunpowderList.push_back(307); // flamethrower fuel, large
	m_AmmoGunpowderList.push_back(308); // needle cartridge x7

	weaponsandupgrades.push_back(309); // quickdraw army
	weaponsandupgrades.push_back(310); // m19

	// weapons and upgrades
	ItemNames.push_back("Shotgun");
	ItemNames.push_back("Lightning Hawk");
	ItemNames.push_back("Flamethrower");
	ItemNames.push_back("GM 79");
	ItemNames.push_back("MQ 11");
	ItemNames.push_back("JMB Hp3");
	ItemNames.push_back("Spark Shot");
	ItemNames.push_back("Minigun");
	ItemNames.push_back("Rocket Launcher");
	ItemNames.push_back("Matilda");
	ItemNames.push_back("SLS 60");
	ItemNames.push_back("Speed Loader (SLS 60)");
	ItemNames.push_back("High-Capacity Mag (Matilda)");
	ItemNames.push_back("Muzzle Brake (Matilda)");
	ItemNames.push_back("Long Barrel (Lightning Hawk)");
	ItemNames.push_back("Long Barrel (W-870)");
	ItemNames.push_back("Shotgun Stock (W-870)");
	ItemNames.push_back("Regulator (Flamethrower)");
	ItemNames.push_back("Wooden Box");
	ItemNames.push_back("High-Capacity Mag (JMB Hp3)");
	ItemNames.push_back("Suppressor (MQ-11)");
	ItemNames.push_back("Reinforced Frame (SLS 60)");
	ItemNames.push_back("High-Capacity Mag (MQ-11)");
	ItemNames.push_back("High Voltage Condenser (Spark Shot)");
	ItemNames.push_back("Shoulder Stock (GM 79)");
	ItemNames.push_back("Gun Stock (Matilda)");

	// the rest
	ItemNames.push_back("Handgun Bullets");
	ItemNames.push_back("Needle Cartridges");
	ItemNames.push_back("Flamethrower Fuel");
	ItemNames.push_back("High-Powered Rounds (SLS 60)");
	ItemNames.push_back("Large Gunpowder");
	ItemNames.push_back("Mag Ammo");
	ItemNames.push_back("Combat Knife");
	ItemNames.push_back("Submachinegun Ammo");
	ItemNames.push_back("Hand Grenade");
	ItemNames.push_back("Flash Grenade");
	ItemNames.push_back("Yellow Gunpowder");
	ItemNames.push_back("Flame Rounds");
	ItemNames.push_back("White Gunpowder");
	ItemNames.push_back("Shotgun Shells");
	ItemNames.push_back("Gunpowder");
	ItemNames.push_back("Flamethrower Fuel x400");
	ItemNames.push_back("Needle Cartridges x7");
	ItemNames.push_back("Quickdraw Army");
	ItemNames.push_back("M19");

	std::vector<std::string> namestoremove;

	namestoremove.push_back("Handgun Bullets");
	namestoremove.push_back("Handgun Bullets (upstairs)");
	namestoremove.push_back("Handgun Bullets (Top Left)");
	namestoremove.push_back("Handgun Bullets (Bottom Left)");
	namestoremove.push_back("Handgun Bullets (Bottom Right)");
	namestoremove.push_back("Handgun Bullets (Bottom Right, Left)");
	namestoremove.push_back("Handgun Bullets (Bottom Right, Right)");

	namestoremove.push_back("ACP Ammo");
	namestoremove.push_back("ACP Ammo (upstairs)");
	namestoremove.push_back("ACP Ammo (Top Left)");
	namestoremove.push_back("ACP Ammo (Bottom Left)");
	namestoremove.push_back("ACP Ammo (Bottom Right)");
	namestoremove.push_back("ACP Ammo (Bottom Right, Left)");
	namestoremove.push_back("ACP Ammo (Bottom Right, Right)");

	// marvin knife in A scenario needs to not be shuffled!
	if (scenario == B)
	{
		namestoremove.push_back("Combat Knife");
	}

	namestoremove.push_back("Shotgun");
	namestoremove.push_back("Long Barrel (W-870)");
	namestoremove.push_back("Shotgun Stock (W-870)");
	namestoremove.push_back("Shotgun Shells");
	namestoremove.push_back("Shotgun Shells (Locker)");
	namestoremove.push_back("Shotgun Shells (Shotgun Cupboard)");

	namestoremove.push_back("Lightning Hawk");
	namestoremove.push_back("Long Barrel (Lightning Hawk)");
	namestoremove.push_back("Wooden Box");
	namestoremove.push_back("Mag Ammo");

	namestoremove.push_back("Flamethrower");
	namestoremove.push_back("Flamethrower Fuel");
	namestoremove.push_back("Flamethrower Fuel x400");
	namestoremove.push_back("Regulator (Flamethrower)");

	namestoremove.push_back("GM 79");
	namestoremove.push_back("Shoulder Stock (GM 79)");
	namestoremove.push_back("Flame Rounds");
	namestoremove.push_back("Flame Rounds (Locker)");
	namestoremove.push_back("Flame Rounds (GM 79 Cupboard)");

	namestoremove.push_back("Spark Shot");
	namestoremove.push_back("Needle Cartridges");
	namestoremove.push_back("Needle Cartridges x7");
	namestoremove.push_back("High Voltage Condenser (Spark Shot)");

	namestoremove.push_back("Flash Grenade");
	namestoremove.push_back("Flash Grenade (Bottom Left)");
	namestoremove.push_back("Flash Grenade (Top Right)");

	namestoremove.push_back("MQ 11");
	namestoremove.push_back("Submachinegun Ammo");
	namestoremove.push_back("Suppressor (MQ-11)");
	namestoremove.push_back("High-Capacity Mag (MQ-11)");

	namestoremove.push_back("Hand Grenade");

	namestoremove.push_back("Gunpowder");
	namestoremove.push_back("Large Gunpowder");
	namestoremove.push_back("Yellow Gunpowder");
	namestoremove.push_back("White Gunpowder");

	namestoremove.push_back("Muzzle Brake (Matilda)");
	namestoremove.push_back("High-Capacity Mag (Matilda)");
	namestoremove.push_back("Gun Stock (Matilda)");

	namestoremove.push_back("Speed Loader (SLS 60)");
	namestoremove.push_back("Reinforced Frame (SLS 60)");
	namestoremove.push_back("High-Powered Rounds (SLS 60)");

	namestoremove.push_back("JMB Hp3");
	namestoremove.push_back("High-Capacity Mag (JMB Hp3)");

	namestoremove.push_back("Minigun");

	namestoremove.push_back("Quickdraw Army");
	namestoremove.push_back("M19");

	std::vector<uint32_t> swaptargets;

	srand(time(0));

	for (uint32_t i = 0; i < m_ListLength; ++i)
	{
		// if we find something on the list
		if (std::find(namestoremove.begin(), namestoremove.end(), ItemNames[finalList[i]]) != namestoremove.end())
		{
			finalList[i] = -1;
			swaptargets.push_back(i);
		}
	}

	while (swaptargets.empty() == false)
	{

		if (weaponsandupgrades.empty() == false)
		{

			uint32_t randomweapon = std::rand() % weaponsandupgrades.size();

			uint32_t randomlocation = std::rand() % swaptargets.size();

			finalList[swaptargets[randomlocation]] = weaponsandupgrades[randomweapon];

			weaponsandupgrades.erase(weaponsandupgrades.begin() + randomweapon);
			swaptargets.erase(swaptargets.begin() + randomlocation);
		}
		else if (m_AmmoGunpowderList.empty() == false)
		{

			uint32_t randomitem = std::rand() % m_AmmoGunpowderList.size();

			uint32_t randomlocation = std::rand() % swaptargets.size();

			finalList[swaptargets[randomlocation]] = m_AmmoGunpowderList[randomitem];

			m_AmmoGunpowderList.erase(m_AmmoGunpowderList.begin() + randomitem);
			swaptargets.erase(swaptargets.begin() + randomlocation);
		}
		else
		{
			// really shouldn't get here
			logger->LogMessage("ERROR ITEMS RAN OUT!\n");
		}
	}

	logger->LogMessage("done!\n");
}

std::unique_ptr<char[]> SeedGenerator::FormatCharArray(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int size = vsnprintf(nullptr, 0, format, args) + sizeof(char);
	std::unique_ptr<char[]> returnValue = std::unique_ptr<char[]>(new char[size]);
	vsnprintf(returnValue.get(), size, format, args);
	va_end(args);
	return returnValue;
}

std::unique_ptr<std::string> SeedGenerator::FormatString(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int size = vsnprintf(nullptr, 0, format, args) + sizeof(char);
	std::unique_ptr<std::string> returnValue = std::unique_ptr<std::string>(new std::string(size, '\0'));
	vsnprintf(returnValue.get()->data(), size, format, args);
	va_end(args);
	return returnValue;
}

FILE *SeedGenerator::OpenFile(const char *filename, const char *mode)
{
	FILE *file;
	errno_t err;

	if (!(err = fopen_s(&file, filename, mode)))
	{
		auto msg = FormatCharArray("Unable to open file %s with mode %s: %d", filename, mode, err).get();
		logger->LogMessage(msg);
		// throw new std::runtime_error(msg);
		return nullptr;
	}

	return file;
}

// void SeedGenerator::PrintCheatSheetItemToFile(FILE *file, const int itemId)
// {
// 	fprintf(file, "\t%s is replaced with %s\n", ItemNames[itemId], ItemNames[finalList[itemId]]);
// }

std::unique_ptr<std::string> SeedGenerator::CheatSheetItemToString(const uint32_t itemId)
{
	return FormatString("\t%s is replaced with %s\n", ItemNames[itemId], ItemNames[finalList[itemId]]);
}

std::vector<std::string> SeedGenerator::GetCheatSheet(void)
{
	return finalCheatSheet;
}

void SeedGenerator::CreateCheatSheetVector(Character character, Scenario scenario, Difficulty difficulty, bool mixWeapons)
{
	finalCheatSheet.clear();

	finalCheatSheet.push_back("Version 0.6.8 Beta\n");

	if (mixWeapons)
	{
		finalCheatSheet.push_back("Mixed Weapons / Ammo / Gunpowder Enabled, Items removed are at the bottom of the Cheat Sheet\n");
	}

	for (uint32_t i = 0; i < m_ListLength; ++i)
	{
		if (i == 0)
		{
			finalCheatSheet.push_back("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~RPD & SEWERS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

			if (scenario == B)
			{
				finalCheatSheet.push_back("B SCENARIO ENTRANCE\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(257).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(258).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(71).get());

				finalCheatSheet.push_back("GUARD ROOM\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(4).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(259).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(260).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(43).get());

				finalCheatSheet.push_back("MAIN HALL\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(57).get());
			}
			else
			{
				finalCheatSheet.push_back("MAIN HALL\n");
			}
		}
		else if (i == 5)
		{
			finalCheatSheet.push_back("RECEPTION\n");
		}
		else if (i == 7)
		{
			finalCheatSheet.push_back("OPERATIONS ROOM\n");
		}
		else if (i == 8)
		{
			finalCheatSheet.push_back("WESTERN AREA 1F\n");
		}
		else if (i == 11)
		{
			finalCheatSheet.push_back("WEST OFFICE\n");
		}
		else if (i == 15)
		{
			finalCheatSheet.push_back("DARK ROOM\n");
		}
		else if (i == 18)
		{
			finalCheatSheet.push_back("SAFETY DEPOSIT ROOM\n");
		}
		else if (i == 26)
		{
			finalCheatSheet.push_back("PRESS ROOM\n");
		}
		else if (i == 27)
		{
			finalCheatSheet.push_back("EAST CLOSET AMBUSH\n");
		}
		else if (i == 29)
		{
			finalCheatSheet.push_back("BATHROOM\n");
		}
		else if (i == 30)
		{
			finalCheatSheet.push_back("DETONATOR ROOM\n");
		}
		else if (i == 34)
		{
			finalCheatSheet.push_back("RECORDS ROOM\n");
		}
		else if (i == 37)
		{
			finalCheatSheet.push_back("EAST OFFICE\n");
		}
		else if (i == 44)
		{
			finalCheatSheet.push_back("WAITING ROOM\n");
		}
		else if (i == 46)
		{
			finalCheatSheet.push_back("WESTERN AREA 2F\n");
		}
		else if (i == 51)
		{
			finalCheatSheet.push_back("WESTERN AREA 3F\n");
		}
		else if (i == 54)
		{
			finalCheatSheet.push_back("WEST STORAGE ROOM\n");
		}
		else if (i == 58)
		{
			finalCheatSheet.push_back("MAIDEN STATUE AREA\n");
		}
		else if (i == 59)
		{
			finalCheatSheet.push_back("LIBRARY\n");
		}
		else if (i == 62)
		{
			finalCheatSheet.push_back("LOUNGE\n");
		}
		else if (i == 64)
		{
			finalCheatSheet.push_back("CHOPPER CRASH AREA\n");
		}
		else if (i == 66)
		{
			finalCheatSheet.push_back("ART ROOM\n");
		}
		else if (i == 69)
		{
			finalCheatSheet.push_back("FIRE ESCAPE\n");
		}
		else if (i == 72)
		{
			finalCheatSheet.push_back("MAIN HALL 3F\n");
		}
		else if (i == 73)
		{
			finalCheatSheet.push_back("BEHIND CLOCK TOWER\n");
		}
		else if (i == 74)
		{
			finalCheatSheet.push_back("CLOCK TOWER\n");
		}
		else if (i == 76)
		{
			finalCheatSheet.push_back("EAST STORAGE ROOM\n");
		}
		else if (i == 79)
		{
			finalCheatSheet.push_back("EAST AREA 3F\n");
		}
		else if (i == 82)
		{
			finalCheatSheet.push_back("BALCONY\n");
		}
		else if (i == 83)
		{
			finalCheatSheet.push_back("ROOF AREA\n");
		}
		else if (i == 87)
		{

			if (character == Leon)
			{
				finalCheatSheet.push_back("BOILER ROOM\n");
			}
		}
		else if (i == 89)
		{
			finalCheatSheet.push_back("OUTSIDE OBSERVATION ROOM\n");
		}
		else if (i == 90)
		{
			finalCheatSheet.push_back("OBSERVATION ROOM\n");
		}
		else if (i == 92)
		{
			finalCheatSheet.push_back("INTERROGATION ROOM\n");

			if (difficulty == Hardcore)
			{
				finalCheatSheet.push_back(*CheatSheetItemToString(253).get());
			}
		}
		else if (i == 93)
		{
			finalCheatSheet.push_back("OUTSIDE STARS OFFICE\n");
		}
		else if (i == 95)
		{
			finalCheatSheet.push_back("STARS OFFICE\n");
			finalCheatSheet.push_back(*CheatSheetItemToString(250).get()); // shotgun shells mistake override
		}
		else if (i == 101)
		{
			finalCheatSheet.push_back("LINEN ROOM\n");
		}
		else if (i == 103)
		{
			finalCheatSheet.push_back("SECRET ROOM\n");
		}
		else if (i == 105)
		{
			finalCheatSheet.push_back("UNDERGROUND STAIRS\n");
		}
		else if (i == 107)
		{
			finalCheatSheet.push_back("MACHINERY ROOM\n");
		}
		else if (i == 116)
		{
			finalCheatSheet.push_back("OPERATORS ROOM\n");
		}
		else if (i == 117)
		{
			finalCheatSheet.push_back("PARKING GARAGE\n");
		}
		else if (i == 118)
		{
			if (character == Leon)
			{
				finalCheatSheet.push_back("JAIL ENTRANCE\n");
			}
		}
		else if (i == 119)
		{
			if (character == Leon)
			{
				finalCheatSheet.push_back("JAIL\n");
			}
		}
		else if (i == 122)
		{
			finalCheatSheet.push_back("OUTSIDE KENNEL\n");
		}
		else if (i == 123)
		{
			finalCheatSheet.push_back("KENNEL\n");
		}
		else if (i == 124)
		{
			finalCheatSheet.push_back("MORGUE\n");
		}
		else if (i == 127)
		{
			finalCheatSheet.push_back("FIRING RANGE\n");
		}
		else if (i == 129)
		{
			finalCheatSheet.push_back("FIRING RANGE LOCKERS\n");
		}
		else if (i == 131)
		{
			if (character == Leon)
			{
				finalCheatSheet.push_back("GENERATOR ROOM\n");
			}
			else
			{
				if (scenario == B)
				{
					finalCheatSheet.push_back("GENERATOR ROOM\n");
					finalCheatSheet.push_back(*CheatSheetItemToString(146).get());
					finalCheatSheet.push_back(*CheatSheetItemToString(147).get());
				}

				finalCheatSheet.push_back("ELEVATOR CONTROLS ROOM\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(87).get()); // claire item sequence break
				finalCheatSheet.push_back(*CheatSheetItemToString(88).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(118).get());
			}
		}
		else if (i == 134)
		{
			if (character == Claire && scenario == B)
			{
				finalCheatSheet.push_back("OUTSIDE BREAK ROOM\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(261).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(144).get());

				finalCheatSheet.push_back("BREAK ROOM\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(262).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(263).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(264).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(145).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(265).get());
			}
			if (character == Leon)
			{
				finalCheatSheet.push_back("OUTSIDE BREAK ROOM\n");
			}
			else
			{
				finalCheatSheet.push_back("PATH TO CHIEF'S OFFICE\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(131).get()); // claire item sequence break

				finalCheatSheet.push_back("CHIEF'S OFFICE\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(137).get());
			}
		}
		else if (i == 135)
		{
			if (character == Leon)
			{
				// do nothing
			}
			else
			{
				finalCheatSheet.push_back("HEART ROOM EAST STORAGE\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(135).get()); // claire item sequence break
				finalCheatSheet.push_back(*CheatSheetItemToString(132).get());
			}
		}
		else if (i == 136)
		{
			if (character == Leon)
			{
				finalCheatSheet.push_back("BREAK ROOM\n");
			}
			else
			{
				finalCheatSheet.push_back("PRIVATE COLLECTION ROOM\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(120).get()); // claire item sequence break
				finalCheatSheet.push_back(*CheatSheetItemToString(140).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(139).get());
			}
		}
		else if (i == 141)
		{
			finalCheatSheet.push_back("OUTSIDE RPD\n");
		}
		else if (i == 142)
		{
			if (character == Leon)
			{
				finalCheatSheet.push_back("GUN SHOP\n");
			}
			else
			{
				finalCheatSheet.push_back("BASKETBALL COURT\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(133).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(138).get());
			}
		}
		else if (i == 145)
		{
			if (character == Leon)
			{
				finalCheatSheet.push_back("SEWER ENTRANCE\n");
			}
			else
			{
				finalCheatSheet.push_back("OUTSIDE BUS\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(136).get());

				finalCheatSheet.push_back("BUS\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(142).get());

				if (difficulty == Hardcore)
				{
					finalCheatSheet.push_back("ORPHANAGE\n");
					finalCheatSheet.push_back(*CheatSheetItemToString(254).get());
				}

				finalCheatSheet.push_back("ORPHANAGE UPSTAIRS\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(121).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(245).get());

				finalCheatSheet.push_back("OFFICE AREA (AFTER SHERRY / MR X CHASE)\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(134).get());
				finalCheatSheet.push_back(*CheatSheetItemToString(143).get());

				if (difficulty == Hardcore)
				{
					finalCheatSheet.push_back(*CheatSheetItemToString(255).get());
				}
			}
		}
		else if (i == 148)
		{
			finalCheatSheet.push_back("UPPER WATERWAY\n");
		}
		else if (i == 150)
		{
			finalCheatSheet.push_back("ROOK BRIDGE AREA\n");
		}
		else if (i == 152)
		{
			finalCheatSheet.push_back("WORKERS BREAK ROOM\n");
		}
		else if (i == 154)
		{
			finalCheatSheet.push_back("RPD ACCESS ROOM\n");
		}
		else if (i == 155)
		{
			finalCheatSheet.push_back("LOWER WATERWAY PRE-SLIDE\n");
		}
		else if (i == 156)
		{
			finalCheatSheet.push_back("WATER INJECTION CHAMBER\n");
		}
		else if (i == 158)
		{
			finalCheatSheet.push_back("LOWER WATERWAY\n");
		}
		else if (i == 160)
		{
			finalCheatSheet.push_back("CONTROL ROOM\n");
		}
		else if (i == 162)
		{
			finalCheatSheet.push_back("MONITOR ROOM\n");
		}
		else if (i == 166)
		{
			finalCheatSheet.push_back("TREATMENT POOL ROOM\n");
		}
		else if (i == 170)
		{
			finalCheatSheet.push_back("BOTTOM WATERWAY OVERPASS\n");
		}
		else if (i == 173)
		{
			finalCheatSheet.push_back("BOTTOM WATERWAY\n");
		}
		else if (i == 175)
		{
			finalCheatSheet.push_back("SUPPLIES STORAGE ROOM\n");
		}
		else if (i == 180)
		{
			finalCheatSheet.push_back("WORKROOM\n");
		}
		else if (i == 183)
		{
			finalCheatSheet.push_back("WORKROOM LIFT\n");
		}
		else if (i == 184)
		{
			finalCheatSheet.push_back("OUTSIDE GARBAGE ROOM\n");
		}
		else if (i == 186)
		{
			finalCheatSheet.push_back("MAIN POWER ROOM\n");
		}
		else if (i == 187)
		{
			finalCheatSheet.push_back("G2 FIGHT ROOM\n");
		}
		else if (i == 191)
		{
			finalCheatSheet.push_back("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LAB AREA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

			if (difficulty == Hardcore)
			{
				finalCheatSheet.push_back("RECEPTION\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(251).get());
			}

			finalCheatSheet.push_back("SECURITY ROOM\n");
		}
		else if (i == 192)
		{
			finalCheatSheet.push_back("CAFETERIA\n");
		}
		else if (i == 195)
		{
			finalCheatSheet.push_back("KITCHEN\n");
		}
		else if (i == 197)
		{
			finalCheatSheet.push_back("NAP ROOM\n");
		}
		else if (i == 201)
		{
			finalCheatSheet.push_back("LOBBY\n");
		}
		else if (i == 203)
		{
			finalCheatSheet.push_back("FIRST PLANT ROOM\n");
		}
		else if (i == 204)
		{
			finalCheatSheet.push_back("GREENHOUSE CONTROL ROOM\n");
		}
		else if (i == 206)
		{
			finalCheatSheet.push_back("GREENHOUSE\n");
		}
		else if (i == 209)
		{
			finalCheatSheet.push_back("DRUG TESTING LAB\n");
		}
		else if (i == 211)
		{
			finalCheatSheet.push_back("UNDERNEATH GREENHOUSE\n");
		}
		else if (i == 212)
		{
			finalCheatSheet.push_back("LOUNGE\n");
		}
		else if (i == 215)
		{
			finalCheatSheet.push_back("SERVER ROOM\n");
		}
		else if (i == 218)
		{
			finalCheatSheet.push_back("LOW-TEMP TESTING LAB\n");
		}
		else if (i == 219)
		{
			finalCheatSheet.push_back("MODULATOR ROOM\n");
		}
		else if (i == 222)
		{
			finalCheatSheet.push_back("BIOTESTING LAB\n");
		}
		else if (i == 226)
		{
			finalCheatSheet.push_back("P-4 LEVEL TESTING LAB\n");
		}
		else if (i == 229)
		{
			finalCheatSheet.push_back("BIOREACTORS ROOM\n");
		}
		else if (i == 239)
		{
			finalCheatSheet.push_back("MONITOR ROOM\n");
		}
		else if (i == 241)
		{
			finalCheatSheet.push_back("PUMP ROOM\n");
		}
		else if (i == 244)
		{

			if (difficulty == Hardcore)
			{
				finalCheatSheet.push_back(*CheatSheetItemToString(252).get());
			}

			if (character == Leon)
			{
				finalCheatSheet.push_back("ESCAPE SHAFT\n");
			}
			else
			{
				finalCheatSheet.push_back("TURNTABLE\n");
				finalCheatSheet.push_back(*CheatSheetItemToString(119).get());
			}
		}
		else if (i == 247)
		{
			finalCheatSheet.push_back("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~EXTRA~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			finalCheatSheet.push_back("HIDDEN ITEMS - PRESS ROOM\n");
		}
		else if (i == 248)
		{
			finalCheatSheet.push_back("HIDDEN ITEMS - STARS OFFICE\n");
		}
		else if (i == 250)
		{
			// finalCheatSheet.push_back("SHOTGUN SHELLS IN THE STARS OFFICE THAT I FORGOT ABOUT I'M SORRY D:\n");
			break;
		}

		if (character == Leon)
		{

			bool condition = true;

			if (scenario == B)
			{
				condition = condition && (i != 4 && i != 71 && i != 131 && i != 213);
			}

			if (condition)
			{
				finalCheatSheet.push_back(*CheatSheetItemToString(i).get());
			}
		}
		else
		{

			if (ItemNames[i] != "UNUSED")
			{

				bool condition = (i != 87 && i != 88 && i != 118 && i != 119 && i != 120 && i != 121 && i != 131 && i != 132 && i != 133 && i != 134 && i != 135 && i != 136 && i != 137 && i != 138 && i != 139 && i != 140 && i != 142);

				if (scenario == B)
				{
					condition = condition && (i != 4 && i != 43 && i != 57 && i != 71 && i != 146 && i != 147 && i != 213);
				}

				if (condition)
				{
					finalCheatSheet.push_back(*CheatSheetItemToString(i).get());
				}
			}
		}
	}

	if (mixWeapons)
	{
		finalCheatSheet.push_back("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DISCARDED ITEMS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		while (m_AmmoGunpowderList.empty() == false)
		{
			finalCheatSheet.push_back(*FormatString("%s\n", ItemNames[m_AmmoGunpowderList.back()]).get());
			m_AmmoGunpowderList.pop_back();
		}
	}
}

void SeedGenerator::WriteDataToFile(Character character, Scenario scenario, Difficulty difficulty, bool UNUSED(mixWeapons))
{
	// ItemList
	{
		std::unique_ptr<char[]> itemListFileName = FormatCharArray("ItemList%s%s%s.txt", magic_enum::enum_name(character), magic_enum::enum_name(scenario), magic_enum::enum_name(difficulty));

		logger->LogMessage("Writing to %s . . .", itemListFileName.get());
		FILE *itemListFile = OpenFile(itemListFileName.get(), "w");
		for (size_t i = 0; i < finalList.size(); ++i)
			fprintf(itemListFile, "%d\n", finalList[i]);
		fflush(itemListFile);
		fclose(itemListFile);
		logger->LogMessage("done!\n");
	}

	// CheatSheet
	{
		std::unique_ptr<char[]> cheatSheetFileName = FormatCharArray("CheatSheet%s%s%s.txt", magic_enum::enum_name(character), magic_enum::enum_name(scenario), magic_enum::enum_name(difficulty));

		logger->LogMessage("Writing to %s . . .", cheatSheetFileName.get());
		FILE *cheatSheetFile = OpenFile(cheatSheetFileName.get(), "w");
		for (size_t i = 0; i < finalCheatSheet.size(); ++i)
			fprintf(cheatSheetFile, "%s\n", finalCheatSheet[i].c_str());
		fflush(cheatSheetFile);
		fclose(cheatSheetFile);
		logger->LogMessage("done!\n");
	}

	logger->LogMessage("done!\n");
}

std::vector<uint32_t> SeedGenerator::GetSeed(void)
{
	return finalList;
}
