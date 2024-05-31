#include "Strings.h"
#include <gtest/gtest.h>

TEST(GetStringSizeTests, CorrectValueA)
{
	EXPECT_EQ(GetStringSizeA("123"), (size_t)4);
}

TEST(GetStringSizeTests, CorrectValueW)
{
	EXPECT_EQ(GetStringSizeW(L"123"), (size_t)8);
}

int wmain(int argc, wchar_t *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
