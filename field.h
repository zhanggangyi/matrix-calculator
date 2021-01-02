#pragma once
//数域
#include <iostream>
#include <algorithm>
#include <cmath>
#include <QString>
#include <QStringList>
#include <string.h>

class Double;

//有理数类
class Qnum {
public:
    int fenmu;
    int fenzi;
	Qnum();
    Qnum(int fenzi_, int fenmu_);
    Double toDouble() const;
    Qnum operator +(const Qnum& other) const;
    Qnum operator -(const Qnum& other) const;
    Qnum operator -() const;
    Qnum operator *(const Qnum& other) const;
    Qnum operator /(const Qnum& other) const;
	Qnum& operator +=(const Qnum& other);
	Qnum& operator -=(const Qnum& other);
	Qnum& operator *=(const Qnum& other);
	Qnum& operator /=(const Qnum& other);
    bool operator ==(const Qnum& other) const;
	Qnum& operator =(const Qnum& other);
    bool operator >(const Qnum& other) const;
    bool operator <(const Qnum& other) const;
	Qnum rec();
	bool judge();
	Qnum& assign();

	void scan();
	void print();
};

//实数类
class Double {

public:
      double value;
	  Double();
      Double operator+(const Double& other) const;
      Double operator-(const Double& other) const;
      Double operator-() const;
      Double operator*(const Double& other) const;
      Double operator/(const Double& other) const;
      Double& operator+=(const Double& other);
	  Double& operator-=(const Double& other);
	  Double& operator*=(const Double& other);
	  Double& operator/=(const Double& other);
	  Double& operator=(const Double& other);
      bool operator==(const Double& other) const;
      bool operator>(const Double& other) const;
      bool operator<(const Double& other) const;
	  Double rec();							//倒数
	  bool judge();                            //判断是否为1                                              
	  Double& assign();							//赋值为1
};

int gcd(int m, int n);
Qnum toRational(QString s);
QString toQstring(const Qnum& num);
