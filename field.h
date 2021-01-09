#pragma once
//����
#include <iostream>
#include <algorithm>
#include <cmath>
#include <QString>
#include <QStringList>
#include <string.h>

class Double;

//��������
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

//ʵ����
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
	  Double rec();							//����
	  bool judge();                            //�ж��Ƿ�Ϊ1                                              
	  Double& assign();							//��ֵΪ1
};

class Complex{          //������
public:
    Double re;
    Double im;
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator-() const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);
    Complex& operator=(const Complex& other);
    bool operator==(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator<(const Complex& other) const;					
    bool judge();                            //�ж��Ƿ�Ϊ1
    Complex& assign();							//��ֵΪ1
};
Complex conj(Complex num);		//����
int gcd(int m, int n);
Qnum toRational(QString s);
QString toQstring(const Complex& num);
QString toQstring(const Qnum& num);
