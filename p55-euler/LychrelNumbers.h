#pragma once

#include <deque>
#include "utill_funcs.h"


class LychrelNumbers
{


	struct possLychrelNum
	{
		unsigned long long num;
		bool wasTested = false;
		bool isLychrel = true;
		size_t numOfIterations = 0;
	};

	std::deque<possLychrelNum> nums;

	const unsigned long long No_of_Numbers_to_check = 10000;
	const size_t max_iterations = 50;

	bool allNumbersWhereTested(std::deque<possLychrelNum*> num_ptrs)
	{
		for (auto const& num_ptr : num_ptrs)
		{
			if (num_ptr->wasTested == false)
			{
				return false;
			}
		}

		return true;
	}

	void setToNotALychrelNumber(possLychrelNum & num)
	{
		if (num.wasTested == false)
		{
			num.isLychrel = false;
			num.wasTested = true;
		}

	}
	void increaseIndexAndSetToTestedIfMaxIterReached(possLychrelNum & num)
	{
		if (num.wasTested == false)
		{
			num.numOfIterations++;
			if (num.numOfIterations >= max_iterations)
			{
				num.wasTested = true;
			}
		}
	}

	unsigned long long getNewNumberAndCheckForLychrelNumber(unsigned long long oldNum,std::deque<possLychrelNum*> num_ptrs)
	{
		unsigned long long newNum = addReversedNumber(oldNum);

		if (isPalindrom(newNum))
		{
			for (auto& num_ptr : num_ptrs)
			{
				setToNotALychrelNumber(*num_ptr);
			}
		}
		else
		{
			for (auto& num_ptr : num_ptrs)
			{
				increaseIndexAndSetToTestedIfMaxIterReached(*num_ptr);
			}

			if (newNum < No_of_Numbers_to_check)
			{
				num_ptrs.push_back(&nums.at(newNum));
			}
		}
			 
		return newNum;
	}


	void setLychrelNumbers(unsigned long long num)
	{
		std::deque<possLychrelNum*> num_ptrs;
		num_ptrs.push_back(&nums.at(num));

		unsigned long long currNum = nums.at(num).num;

		while (!allNumbersWhereTested(num_ptrs))
		{
			currNum = getNewNumberAndCheckForLychrelNumber(currNum,num_ptrs);
		}

	}


public:
	LychrelNumbers()
	{
		nums.resize(No_of_Numbers_to_check);

		for (size_t i = 0; i < No_of_Numbers_to_check; ++i)
		{
			nums.at(i).num = i;
		}
	}

	bool isLychrelNumber(unsigned long long num)
	{
		if (num < No_of_Numbers_to_check)
		{
			if (nums.at(num).wasTested)
			{
				return nums.at(num).isLychrel;
			}
			else
			{
				setLychrelNumbers(num);
				return nums.at(num).isLychrel;
			}
		}
		else
		{
			throw std::invalid_argument("Number is higher than the highest number that can be tested.");
		}
	}

	void setAllLychrelNumbers()
	{
		for (const auto& num : nums)
		{
			setLychrelNumbers(num.num);
		}
	}

	unsigned long long getNumberOfLychrelNumbers()
	{
		unsigned long long count = 0;

		for (const auto& num : nums)
		{
			if (num.isLychrel)
			{
				count++;
			}
		}

		return count;
	}
	



};

