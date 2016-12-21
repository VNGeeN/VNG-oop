#pragma once

//Класс, моделирующий рациональное число
class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	int GetNumerator() const;

	int GetDenominator() const;

	double ToDouble() const;

	CRational const operator +() const;
	CRational const operator -();

	CRational const operator +=(CRational const& first);
	CRational const operator -=(CRational const& first);

	CRational const operator *=(CRational const& first);
	CRational const operator /=(CRational const& first);
private:
	int m_numerator;
	int m_denominator;

	void Normalize();
};

unsigned GCD(unsigned a, unsigned b);
CRational const operator +(CRational const& first, CRational const& second);
CRational const operator -(CRational const& first, CRational const& second);
CRational const operator *(CRational const& first, CRational const& second);
CRational const operator /(CRational const& first, CRational const& second);
bool const operator ==(CRational const& first, CRational const& second);
bool const operator !=(CRational const& first, CRational const& second);

bool const operator <(CRational const& first, CRational const& second);
bool const operator >(CRational const& first, CRational const& second);
bool const operator <=(CRational const& first, CRational const& second);
bool const operator >=(CRational const& first, CRational const& second);
bool const operator >=(CRational const& first, CRational const& second);

std::ostream & operator <<(std::ostream &stream, CRational const& rational);
std::istream & operator >>(std::istream &stream, CRational & rational);