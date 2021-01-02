#include"field.h"

Double::Double()
{
	value = 0.0;
}
Double Double::operator+(const Double& other) const
{
	Double result;
	result.value = value + other.value;
	return result;
}
Double Double::operator-(const Double& other) const
{
	Double result;
	result.value = value + other.value;
	return result;
}
Double Double::operator-() const
{
	Double result;
	result.value = -value ;
	return result;
}
Double Double::operator*(const Double& other) const
{
	Double result;
	result.value = value * other.value;
	return result;
}
Double Double::operator/(const Double& other) const
{
	Double result;
	result.value = value / other.value;
	return result;
}
Double& Double::operator+=(const Double& other)
{
	value += other.value;
	return *this;
}
Double& Double::operator-=(const Double& other)
{
	value -= other.value;
	return *this;
}
Double& Double::operator*=(const Double& other)
{
	value *= other.value;
	return *this;
}
Double& Double::operator/=(const Double& other)
{
	value /= other.value;
	return *this;
}
Double& Double::operator=(const Double& other)
{
	value = other.value;
	return *this;
}
bool Double::operator==(const Double& other) const
{
	if (abs(value - other.value) < 1e-6)
		return true;
	else
		return false;
}
bool Double::operator>(const Double& other) const
{
	if (value > other.value)
		return true;
	else
		return false;
}
bool Double::operator<(const Double& other) const
{
	if (value < other.value)
		return true;
	else
		return false;
}


Double Double:: rec()
{
	Double result;
	result.value = 1.0 / value;
	return result;
}
bool Double::judge()
{
	if (abs(value - 1) < 1e-6)
		return true;
	else
		return false;
}
Double& Double::assign()
{
	value = 1.0;
	return *this;
}
