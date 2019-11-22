#include "pch.h"



#include "../p55-euler/utill_funcs.h"


TEST(TestIsPalindrom, OnInputOneDigitNumbersArePalindrom)
{
	EXPECT_TRUE(isPalindrom(0));
	EXPECT_TRUE(isPalindrom(2));
	EXPECT_TRUE(isPalindrom(9));

}

TEST(TestIsPalindrom, SomeTwoDigitTestCases)
{
	EXPECT_FALSE(isPalindrom(10));
	EXPECT_FALSE(isPalindrom(92));
	EXPECT_TRUE(isPalindrom(88));

}

TEST(TestIsPalindrom, SomeThreeDigitTestCases)
{
	EXPECT_TRUE(isPalindrom(101));
	EXPECT_FALSE(isPalindrom(921));
	EXPECT_FALSE(isPalindrom(188));

}

TEST(TestIsPalindrom, SomeFourDigitTestCases)
{
	EXPECT_FALSE(isPalindrom(6701));
	EXPECT_FALSE(isPalindrom(4492));
	EXPECT_TRUE(isPalindrom(1881));

}