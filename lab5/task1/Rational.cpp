#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator can not be zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

//Числитель
int CRational::GetNumerator() const
{
	return m_numerator;
}

//Знаменатель
int CRational::GetDenominator() const
{
	return m_denominator;
}

// Нормализует рациональное число
void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

// Вычисляет наибольший общий делитель (greatest common denominator) чисел a и b
unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}


//Реализовать метод ToDouble()
double CRational::ToDouble() const
{
	return static_cast<double> (m_numerator) / (m_denominator);
}


//Реализовать унарный + и унарный -
CRational const CRational::operator +() const
{
	return *this;
}


CRational const CRational::operator -()
{
	m_numerator = -m_numerator;
	return *this;
}


//Реализовать бинарный +
CRational const operator+(CRational const& first, CRational const& second)
{
	int numerator = first.GetNumerator() * second.GetDenominator() + first.GetDenominator() * second.GetNumerator();
	int denomirator = first.GetDenominator() * second.GetDenominator();
	return CRational(numerator, denomirator);
}


//Реализовать бинарный -
CRational const operator-(CRational const& first, CRational const& second)
{
	int numerator = first.GetNumerator() * second.GetDenominator() - first.GetDenominator() * second.GetNumerator();
	int denomirator = first.GetDenominator() * second.GetDenominator();
	return CRational(numerator, denomirator);
}


//Реализовать оператор +=
CRational const CRational::operator +=(CRational const& first)
{
	*this = *this + first;
	return *this;
}


//Реализовать оператор -=
CRational const CRational::operator -=(CRational const& first)
{
	*this = *this - first;
	return *this;
}


//Реализация оператора *
CRational const operator *(CRational const& first, CRational const& second)
{
	return CRational((first.GetNumerator() * second.GetNumerator()),
					 (first.GetDenominator() * second.GetDenominator()));
}


//Реализация оператора /
CRational const operator /(CRational const& first, CRational const& second)
{
	return CRational((first.GetNumerator() * second.GetDenominator()),
		(first.GetDenominator() * second.GetNumerator()));
}


//Реализовать оператор *=
CRational const CRational::operator *=(CRational const& first)
{
	*this = *this * first;
	return *this;
}


//Реализовать оператор /=
CRational const CRational::operator /=(CRational const& first)
{
	*this = *this / first;
	return *this;
}


//Реализовать операторы == и !=
bool const operator ==(CRational const& first, CRational const& second)
{
	return (first.GetNumerator() == second.GetNumerator()) &&
		(first.GetDenominator() == second.GetDenominator());
}

bool const operator !=(CRational const& first, CRational const& second)
{
	return (first.GetNumerator() != second.GetNumerator()) ||
		(first.GetDenominator() != second.GetDenominator());
}


//Реализовать операторы <, >, <=, >=
bool const operator <(CRational const& first, CRational const& second)
{
	return ((first.GetNumerator() * second.GetDenominator()) < (first.GetDenominator() * second.GetNumerator()));
}

bool const operator >(CRational const& first, CRational const& second)
{
	return ((first.GetNumerator() * second.GetDenominator()) > (first.GetDenominator() * second.GetNumerator()));
}

bool const operator <=(CRational const& first, CRational const& second)
{
	return !(first > second);
}

bool const operator >=(CRational const& first, CRational const& second)
{
	return !(first < second);
}


//Реализовать оператор вывода рационального числа в выходной поток 
std::ostream & operator <<(std::ostream &stream, CRational const& rational)
{
	return(stream << rational.GetNumerator() << '/'
		  << rational.GetDenominator());
}


//Реализовать оператор ввода рационального числа из входного потока 
std::istream & operator >> (std::istream &stream, CRational & rational)
{
	unsigned numerator = 0;
	unsigned denominator = 1;
	if ((stream >> numerator) && (stream.get() == '/') && (stream >> denominator))
	{
		rational = CRational(numerator, denominator);
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}
	return stream;
}