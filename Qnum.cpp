#include"field.h"
#include<string>
using namespace std;
Qnum toRational(QString s)
{
    string str=s.toStdString();
    int fenzi_ = 0, fenmu_ = 0, i;
    int sign = 1, is_int = 1;
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '-')
            sign = -1;
        else if (str[i] == '/')
        {
            fenzi_ *= sign;
            sign = 1;
            is_int = 0;
        }
        else if (str[i] >= '0' && str[i] <= '9' && is_int)
        {
            fenzi_ *= 10;
            fenzi_ += str[i] - '0';
        }
        else if (str[i] >= '0' && str[i] <= '9' && !is_int)
        {
            fenmu_ *= 10;
            fenmu_ += str[i] - '0';
        }
    }
    if (is_int)
        fenzi_ *= sign;
    if (fenmu_ == 0)
        fenmu_ = 1;

    Qnum Qnum_(fenzi_,fenmu_);
    return Qnum_;
}

QString toQstring(const Qnum& num)
{
    QString str1,str2;
    QString bias("/");
    if (num.fenmu < 0)
    {

        str1=QString::number(-num.fenzi);
        str2=QString::number(-num.fenmu);
    }
    else if (num.fenmu > 0)
    {
        str1=QString::number(num.fenzi);
        str2=QString::number(num.fenmu);
    }

    if(num.fenzi==0)
    {
       str1=QString::number(num.fenzi);
       return str1;
    }
    else if(num.fenmu==1||num.fenmu==-1)
    {
        str1=QString::number(num.fenzi);
        return str1;
    }
    else
    {
        str1.append(bias);
        str1.append(str2);
        return str1;
    }
}

Qnum::Qnum()
{
	fenzi = 0;
    fenmu = 1;
}

Qnum::Qnum(int fenzi_, int fenmu_)
{
    fenzi = fenzi_;
    fenmu = fenmu_;
}

Double Qnum::toDouble() const
{
    Double result;
    result.value = (double)fenzi / fenmu;
	return result;
}
Qnum Qnum:: operator +(const Qnum& other) const
{
	Qnum result;
	int g;
	result.fenzi = fenzi * other.fenmu + other.fenzi * fenmu;
	result.fenmu = fenmu * other.fenmu;
	g = gcd(result.fenzi, result.fenmu);
	result.fenzi /= g; result.fenmu /= g;
	return result;
}
Qnum Qnum:: operator -() const
{
	Qnum result;
	result.fenmu = fenmu;
	result.fenzi = -fenzi;
	return result;
}
Qnum Qnum::operator -(const Qnum& other) const
{
	Qnum temp = other;
	return *this + (-temp);
}

Qnum Qnum::operator *(const Qnum& other) const
{
	int g;
	Qnum result;
	result.fenzi = fenzi * other.fenzi;
	result.fenmu = fenmu * other.fenmu;
	g = gcd(result.fenzi, result.fenmu);
	result.fenzi /= g; result.fenmu /= g;
	return result;
}
Qnum Qnum::operator /(const Qnum& other) const
{
	Qnum result;
	result.fenmu = fenmu * other.fenzi;
	result.fenzi = fenzi * other.fenmu;
	int g = gcd(result.fenmu, result.fenzi);
	result.fenmu /= g; result.fenzi /= g;
	return result;
}
Qnum& Qnum::operator +=(const Qnum& other)
{
	*this = *this + other;
	return *this;
}
Qnum& Qnum::operator -=(const Qnum& other)
{
	*this = *this - other;
	return *this;
}
Qnum& Qnum::operator *=(const Qnum& other)
{
	*this = *this * other;
	return *this;
}
Qnum& Qnum::operator /=(const Qnum& other)
{
	*this = *this / other;
	return *this;
}
bool Qnum::operator ==(const Qnum& other) const
{
	if (fenzi * other.fenmu == fenmu * other.fenzi)
		return true;
	else
		return false;
}
Qnum& Qnum::operator =(const Qnum& other)
{
	this->fenmu = other.fenmu;
	this->fenzi = other.fenzi;
	return *this;
}
bool Qnum::operator >(const Qnum& other) const
{
    if (fenmu * other.fenmu > 0)
        return fenzi * other.fenmu > fenmu * other.fenzi;
	else
        return fenzi * other.fenmu < fenmu * other.fenzi;

}
bool Qnum::operator <(const Qnum& other) const
{
    if (fenmu * other.fenmu > 0)
        return fenzi * other.fenmu < fenmu * other.fenzi;
    else
        return fenzi * other.fenmu > fenmu * other.fenzi;
}
Qnum Qnum::rec()
{
	Qnum result;
	result.fenmu = fenzi;
	result.fenzi = fenmu;

	return result;
}
bool Qnum::judge()
{
	if (fenmu == fenzi)
		return true;
	else
		return false;
}
Qnum& Qnum::assign()
{
	fenmu = 1;
	fenzi = 1;
	return *this;
}
void Qnum::print()
{
	if (fenmu == 1 || fenmu == -1)
		printf("%d", fenzi * fenmu);
	else if (fenmu < 0)
		printf("%d/%d", -fenzi, -fenmu);
	else if (fenmu > 0)
		printf("%d/%d", fenzi, fenmu);
	return;
}

int gcd(int m, int n)
{
	m = abs(m); n = abs(n);
	if (m * n == 0)
	{
		if (m == 0)
			return n;
		else
			return m;
	}
	else
	{
		if (m > n)
			return gcd(m % n, n);
		else
			return gcd(m, n % m);
	}
}

