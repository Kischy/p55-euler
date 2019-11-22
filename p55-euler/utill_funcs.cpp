#include "pch.h"
#include "utill_funcs.h"



unsigned long long reverseNumber(unsigned long long number)
{
	unsigned long long newNum = 0, rest;

	while (number != 0)
	{
		rest = number % 10;
		newNum *= 10;
		newNum += rest;
		number /= 10;
	}


	return newNum;
}

bool isPalindrom(unsigned long long number)
{
	if (number == reverseNumber(number))
	{
		return true;
	}

	return false;
}

unsigned long long addReversedNumber(unsigned long long number)
{
	return number + reverseNumber(number);
}




