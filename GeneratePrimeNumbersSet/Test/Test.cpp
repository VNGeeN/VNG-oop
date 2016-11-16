#include "stdafx.h"
#include "../GeneratePrimeNumbersSet/GeneratePrimeNumberSet.h"


BOOST_AUTO_TEST_SUITE(GeneratePrimeNumbersSet_function)
	BOOST_AUTO_TEST_CASE(empty_set)
	{
		std::set<int> setCompared = {};
		BOOST_CHECK(GeneratePrimeNumbersSet(0) == setCompared);
 	}
	BOOST_AUTO_TEST_CASE(set_of_prime_numbers_up_to_10)
	{
		std::set<int> setCopared = { 2, 3, 5, 7 };
		BOOST_CHECK(GeneratePrimeNumbersSet(10) == setCopared);
	}
	BOOST_AUTO_TEST_CASE(set_of_prime_numbers_up_to_50)
	{
		std::set<int> setCopared = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
		BOOST_CHECK(GeneratePrimeNumbersSet(50) == setCopared);
	}
	BOOST_AUTO_TEST_SUITE(checking_the_number_of_elements_in_the_set)
		BOOST_AUTO_TEST_CASE(the_limit_of_plurality_equally_to_the_max_number)
		{
			BOOST_CHECK(GeneratePrimeNumbersSet(100000000).size() == 5761455);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()