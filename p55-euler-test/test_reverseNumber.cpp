#include "pch.h"



#include "../p55-euler/utill_funcs.h"


TEST(TestReverseNumber, OnInputOneDigitNumberReturnsTheNumber)
{
	EXPECT_EQ(0, reverseNumber(0));
	EXPECT_EQ(2, reverseNumber(2));
	EXPECT_EQ(9, reverseNumber(9));

}

TEST(TestReverseNumber, SomeTwoDigitTestCases)
{
	EXPECT_EQ(01, reverseNumber(10));
	EXPECT_EQ(29, reverseNumber(92));
	EXPECT_EQ(88, reverseNumber(88));

}

TEST(TestReverseNumber, SomeThreeDigitTestCases)
{
	EXPECT_EQ(101, reverseNumber(101));
	EXPECT_EQ(129, reverseNumber(921));
	EXPECT_EQ(881, reverseNumber(188));

}

TEST(TestReverseNumber, SomeFourDigitTestCases)
{
	EXPECT_EQ(1076, reverseNumber(6701));
	EXPECT_EQ(2944, reverseNumber(4492));
	EXPECT_EQ(1881, reverseNumber(1881));

}