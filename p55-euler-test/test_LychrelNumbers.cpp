#include "pch.h"



#include "../p55-euler/LychrelNumbers.h"


using namespace testing;

class TestLychrelNumbers : public Test
{
public:
	LychrelNumbers lychrelNums;
};

TEST_F(TestLychrelNumbers, KnownTestCases)
{
	EXPECT_TRUE(lychrelNums.isLychrelNumber(4994));
	EXPECT_TRUE(lychrelNums.isLychrelNumber(196));
	EXPECT_FALSE(lychrelNums.isLychrelNumber(47));
	EXPECT_FALSE(lychrelNums.isLychrelNumber(0));
	EXPECT_FALSE(lychrelNums.isLychrelNumber(349));
}