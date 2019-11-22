#pragma once

#include <deque>

class LychrelNumbers
{
	struct possLychrelNum
	{
		unsigned long long num;
		bool wasTested = false;
		bool isLychrel = true;
	};

	std::deque<possLychrelNum> nums;

	unsigned long long No_of_Numbers_to_check = 10000;

public:
	LychrelNumbers()
	{
		nums.resize(No_of_Numbers_to_check);

		for (size_t i = 0; i < No_of_Numbers_to_check; ++i)
		{
			nums.at(i).num = i;
		}
	}
	



};

