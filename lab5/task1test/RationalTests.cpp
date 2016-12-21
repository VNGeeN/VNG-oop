// task1tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task1/Rational.h"

BOOST_AUTO_TEST_CASE(Test_GCD)
{
	BOOST_CHECK_EQUAL(GCD(2, 3), 1u);
	BOOST_CHECK_EQUAL(GCD(3, 2), 1u);
	BOOST_CHECK_EQUAL(GCD(10, 6), 2u);
	BOOST_CHECK_EQUAL(GCD(6, 10), 2u);
	BOOST_CHECK_EQUAL(GCD(0, 7), 7u);
	BOOST_CHECK_EQUAL(GCD(2, 0), 2u);
	BOOST_CHECK_EQUAL(GCD(0, 0), 1u);
}

void VerificationRational(const CRational & r, int expectedNumerator, int expectedDenominator)
{
	BOOST_CHECK_EQUAL(r.GetNumerator(), expectedNumerator);
	BOOST_CHECK_EQUAL(r.GetDenominator(), expectedDenominator);
}

BOOST_AUTO_TEST_SUITE(rational_number)
	BOOST_AUTO_TEST_CASE(is_zero_by_default)
	{
		VerificationRational(CRational(), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_transform_from_integer)
	{
		VerificationRational(CRational(5), 5, 1);
		VerificationRational(CRational(-7), -7, 1);
		VerificationRational(CRational(0), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_with_numerator_and_denominator)
	{
		VerificationRational(CRational(3, 4), 3, 4);
		VerificationRational(CRational(-3, 4), -3, 4);
		VerificationRational(CRational(3, -4), -3, 4);
		VerificationRational(CRational(-3, -4), 3, 4);
	}
	BOOST_AUTO_TEST_CASE(is_normalized_after_construction)
	{
		VerificationRational(CRational(5, 10), 1, 2);
		VerificationRational(CRational(12, 4), 3, 1);
	}
	BOOST_AUTO_TEST_CASE(cant_have_zero_denominator)
	{
		BOOST_REQUIRE_THROW(CRational(1, 0), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(can_be_converted_to_double)
	{
	    CRational rational(1, 5);
		BOOST_CHECK_CLOSE_FRACTION(rational.ToDouble(), 0.2, DBL_EPSILON);
	}

	BOOST_AUTO_TEST_SUITE(unar_operators)
		BOOST_AUTO_TEST_CASE(unar_plus)
		{
			VerificationRational(+CRational(1, 5), 1, 5);
		}
		BOOST_AUTO_TEST_CASE(unar_minus)
		{
			VerificationRational(-CRational(7, 8), -7, 8);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(binary_operator_plus)
		BOOST_AUTO_TEST_CASE(can_sum_two_rational_numbers)
		{
			VerificationRational(CRational(1, 3) + CRational(1, 6), 1, 2);
		}
	BOOST_AUTO_TEST_SUITE_END()
	
	BOOST_AUTO_TEST_SUITE(binary_minus)
		BOOST_AUTO_TEST_CASE(can_substract_two_rational_numbers)
		{
			VerificationRational(CRational(3, 5) - CRational(2, 5), 1, 5);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(operator_plus_equal)
		BOOST_AUTO_TEST_CASE(can_sum_two_rational_numbers)
		{
			VerificationRational(CRational(1, 3) += CRational(1, 6), 1, 2);
		}
	BOOST_AUTO_TEST_SUITE_END()
	
	BOOST_AUTO_TEST_SUITE(operator_minus_equal)
		BOOST_AUTO_TEST_CASE(can_substract_two_rational_numbers)
		{
			VerificationRational(CRational(3, 5) -= CRational(2, 5), 1, 5);
		}
	BOOST_AUTO_TEST_SUITE_END()
	
	BOOST_AUTO_TEST_SUITE(operator_multiply)
		BOOST_AUTO_TEST_CASE(can_multiply_two_rational_numbers)
		{
			VerificationRational(CRational(1, 6) * CRational(3, 5), 1, 10);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(operator_multiply_equal)
		BOOST_AUTO_TEST_CASE(can_multiply_two_rational_numbers)
		{
			VerificationRational(CRational(1, 6) *= CRational(3, 5), 1, 10);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(operator_division)
		BOOST_AUTO_TEST_CASE(can_divide_rational_number_by_rational_number)
		{
			VerificationRational(CRational(1, 6) / CRational(3, 5), 5, 18);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(operator_division_equal)
		BOOST_AUTO_TEST_CASE(can_divide_rational_number_by_rational_number)
		{
			VerificationRational(CRational(1, 6) /= CRational(3, 5), 5, 18);
		}
	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_SUITE(operator_equal)
		BOOST_AUTO_TEST_CASE(compares_equal)
		{
			BOOST_CHECK(CRational(1, 6) == CRational(1, 6));
			BOOST_CHECK(4 == CRational(4, 1));
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(operator_unequal)
		BOOST_AUTO_TEST_CASE(compares_unequal)
		{
			BOOST_CHECK(CRational(1, 3) != CRational(3, 1));
			BOOST_CHECK(CRational(3, 4) != CRational(3, 8));
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(compare_operators)
		BOOST_AUTO_TEST_CASE(less)
		{
			BOOST_CHECK(CRational(2, 5) < CRational(1, 2));
		}
		BOOST_AUTO_TEST_CASE(less_equal)
		{
			BOOST_CHECK(CRational(2, 5) <= CRational(1, 2));
			BOOST_CHECK(CRational(2, 5) <= CRational(2, 5));
		}
		BOOST_AUTO_TEST_CASE(more)
		{
			BOOST_CHECK(CRational(1, 2) > CRational(1, 4));
		}
		BOOST_AUTO_TEST_CASE(more_equal)
		{
			BOOST_CHECK(CRational(10, 5) >= 2);
			BOOST_CHECK(CRational(2, 3) >= CRational(1, 6));
		}
	BOOST_AUTO_TEST_SUITE_END()

//Реализовать оператор вывода рационального числа в выходной поток 
	BOOST_AUTO_TEST_SUITE(output_operator)
		BOOST_AUTO_TEST_CASE(can_write_rational_number_to_ostream)
		{
			boost::test_tools::output_test_stream output;
			output << CRational(3, 4);
			BOOST_CHECK(output.is_equal("3/4"));
		}
	BOOST_AUTO_TEST_SUITE_END()


//Реализовать оператор ввода рационального числа из входного потока
	BOOST_AUTO_TEST_SUITE(input_operator)
		BOOST_AUTO_TEST_CASE(can_read_rational_number_from_istream)
		{
			std::istringstream stream("1/2");
			CRational rational;
			stream >> rational;
			VerificationRational(rational, 1, 2);
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
