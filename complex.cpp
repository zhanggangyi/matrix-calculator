#include "field.h"
Complex Complex::operator+(const Complex& other) const
{
    Complex result;
    result.re=this->re+other.re;
    result.im=this->im+other.im;
    return result;
}
Complex Complex::operator-(const Complex& other) const
{
    Complex result;
    result.re=this->re-other.re;
    result.im=this->im-other.im;
    return result;
}
Complex Complex::operator-() const
{
    Complex result;
    result.re=-this->re;
    result.im=-this->im;
    return result;
}
Complex Complex::operator*(const Complex& other) const
{
    Complex result;
    result.re=this->re*other.re-this->im*other.im;
    result.im=this->re*other.im+this->im*other.re;
    return result;
}
/*
Complex Complex::operator/(const Complex& other) const
{
    Complex result;
    result=*this*conj(other);
    Double fenmu=(other*conj(other)).re;
    result.re/=fenmu;
    result.im/=fenmu;
    return result;
}

Complex& Complex::operator+=(const Complex& other)
{
    *this=*this+other;
    return *this;
}
Complex& Complex::operator-=(const Complex& other)
{
    *this=*this-other;
    return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
    *this=*this*other;
    return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
    *this=*this/other;
    return *this;
}

Complex& Complex::operator=(const Complex& other)
{
    this->im=other.im;
    this->re=other.re;
    return *this;
}

bool Complex::operator==(const Complex& other) const
{
    if(this->im==other.im&&this->re==other.re)
        return true;
    else
        return false;
}

bool judge();                            //判断是否为1
{
}
Complex& assign();							//赋值为1
Complex conj(Complex num);
QString toQstring(const Complex& num);
*/
