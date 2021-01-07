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
Complex Complex::operator/(const Complex& other) const
{
    Complex result;
    return result;
}
/*
Complex& Complex::operator+=(const Complex& other);
Complex& Complex::operator-=(const Complex& other);
Complex& Complex::operator*=(const Complex& other);
Complex& Complex::operator/=(const Complex& other);
Complex& Complex::operator=(const Complex& other);
bool Complex::operator==(const Complex& other) const;
bool Complex::operator>(const Complex& other) const;
bool Complex::operator<(const Complex& other) const;
Complex rec();							//倒数
Complex conj();							//共轭
bool judge();                            //判断是否为1
Complex& assign();							//赋值为1

QString toQstring(const Complex& num);
*/
