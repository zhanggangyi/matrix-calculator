#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#define MAXSIZE 30
#include <stdexcept>
#include <string.h>
#include <memory>
#include "field.h"

using namespace std;

//向量类
template <typename T>
class Vector {
private:
	const T defaultElem = T{};

public:
	int dimension;
	T element[MAXSIZE];
	Vector();
	Vector<T>& operator= (const Vector<T> & other);
};
template <typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& other)
{
	dimension = other.dimension;
	for (int i = 1; i <= dimension; i++)
	{
		element[i] = other.element[i];
	}
	return *this;
}
template <typename T>
Vector<T>::Vector()
{
	dimension = 0;
	for (int i = 0; i < MAXSIZE; i++)
		element[i] = defaultElem;
}
//线性空间类
template <typename T>
class Space {
private:
	const T defaultElem = T{};
public:
	int dimension;
	Vector<T> base[MAXSIZE];
	Vector<T> par_solution;
	Space();
	Space<T>& operator= (const Space<T>& other);
};
template <typename T>
Space<T>::Space()
{
	dimension = 0;
}
template <typename T>
Space<T>& Space<T>::operator= (const Space<T>& other)
{
	dimension = other.dimension;
	for (int i = 1; i <= dimension; i++)
	{
		base[i] = other.base[i];
	}
	return *this;
}

//多项式类
template <typename T>
class Polynomial {
private:
	const T defaultElem = T{};
public:
	int deg;
	T coe[MAXSIZE];
	Polynomial();
	Polynomial operator+(const Polynomial& other);
	Polynomial operator-(const Polynomial& other);
	Polynomial operator-();
	Polynomial operator*(const Polynomial& other);
	Polynomial operator/(const Polynomial& other);
	Polynomial& operator+=(const Polynomial& other);
	Polynomial& operator-=(const Polynomial& other);
	Polynomial& operator*=(const Polynomial& other);
	Polynomial& operator/=(const Polynomial& other);
	Polynomial operator%(const Polynomial& other);
	Polynomial& operator=(const Polynomial& other);
	bool operator==(const Polynomial& other);

	void print();
};

template <typename T>
class Matrix;
template <typename T>
Matrix<T> operator*(T n, const Matrix<T>& m);

//矩阵类
template <typename T>
class Matrix {
protected:
	const T defaultElem = T{};
public:
	T element[MAXSIZE][MAXSIZE];
	int row;
	int column;
	Matrix();                                       //构造函数
	//初等行变换
	void rPermutation(int i, int j);                //置换
	void rDiagonal(T k, int j);                      //数乘
	void rTriangular(T k, int i, int j);              //倍加（将第j行的k倍加到第i行）
	//初等列变换
	void cPermutation(int i, int j);                 //置换
	void cDiagoal(T k, int j);                      //数乘
	void cTriangular(T k, int i, int j);             //倍加（将第j列的k倍加到第i列）
    Matrix ref(bool mode)   const;            //mode=0 行阶梯型 mode=1 行最简型
    int getrank() const ; //(返回矩阵的秩rank）
	Space<T> solveLinearEquations() ;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
    Matrix operator-() const;                              //取负号
    friend Matrix operator*<T>(T n, const Matrix& m);
    Matrix operator*(T n) const;
    Matrix operator*(const Matrix& other) const;
    Matrix& operator=(const Matrix& other);
    Matrix<T> inv() const;											  //逆矩阵
    T determinant() const;                                //行列式
    Polynomial<T> eigenpoly();							  //特征多项式
    void rcf();                                           //有理标准型
    void nor();                                           //法式
    Polynomial<T> minimalpoly() ;                       //极小多项式
    Vector<Polynomial<T>> get_factor(bool mode) ;                // mode=0 行列式因子  mode=1 不变因子
    Matrix<Polynomial<T>>* toLambdaMatrix();                    //转化为特征矩阵
	void scan();
	void print();
};


//矩阵类构造函数
template <typename T>
Matrix<T>::Matrix() {
	row = 0;
	column = 0;

	for (int i = 0; i < MAXSIZE; i++) {
		for (int j = 0; j < MAXSIZE; j++) {
			element[i][j] = defaultElem;
		}
	}
}
//初等行变换
template <typename T>
void Matrix<T>::rPermutation(int i, int j)              //置换
{
	T temp; int a;
	for (a = 1; a <= column; a++)
	{
		temp = element[i][a];
		element[i][a] = element[j][a];
		element[j][a] = temp;
	}
}
template <typename T>
void Matrix<T>::rDiagonal(T k, int j)                    //数乘
{
	int a;
	for (a = 1; a <= column; a++)
		element[j][a] *= k;
}
template <typename T>
void Matrix<T>::rTriangular(T k, int i, int j)              //倍加（将第j行的k倍加到第i行）
{
	int a;
	for (a = 1; a <= column; a++)
		element[i][a] += element[j][a] * k;
}

//初等列变换
template <typename T>
void Matrix<T>::cPermutation(int i, int j)                 //置换
{
	T temp; int a;
	for (a = 1; a <= row; a++)
	{
		temp = element[a][i];
		element[a][i] = element[a][j];
		element[a][j] = temp;
	}
}
template <typename T>
void Matrix<T>::cDiagoal(T k, int j)                     //数乘
{
	int a;
	T temp;
	for (a = 1; a <= row; a++)
		element[a][j] *= temp;
}
template <typename T>
void Matrix<T>::cTriangular(T k, int i, int j)             //倍加（将第j列的k倍加到第i列）
{
	int a;
	for (a = 1; a <= row; a++)
		element[a][i] += element[a][j] * k;
}

template <typename T>
Matrix<T> Matrix<T>::ref(bool mode) const                //mode=0 行阶梯型 mode=1 行最简型(返回矩阵的秩rank）
{
	int i, j, k;	//定义循环变量
	T temp;
	int rank = 0;	//矩阵的秩 
    Matrix<T> A=*this;

    for (i = 1; i <= A.column; i++)
	{
        for (j = rank + 1; j <= A.row && A.element[rank + 1][i] == defaultElem; j++)
            if (!(A.element[j][i] == defaultElem))
			{
                A.rPermutation(rank + 1, j);
				break;
			}

        if (!(A.element[rank + 1][i] == defaultElem))
		{
			rank++;
            for (j = rank + 1; j <= A.row; j++)
                if (!(A.element[j][i] == defaultElem))
				{
                    temp = A.element[j][i] / A.element[rank][i];
                    A.rTriangular(-temp, j, rank);
				}
		}
	}

	for (i = 1; i <= rank; i++)
	{
        for (j = 1; A.element[i][j] == defaultElem; j++);
        A.rDiagonal(A.element[i][j].rec(), i);
	}

	if (mode == 1)
	{
		for (i = 1; i <= rank; i++)
		{
            for (j = 1; A.element[i][j] == defaultElem; j++);
			for (k = i - 1; k >= 1; k--)
                A.rTriangular(-A.element[k][j], k, i);
		}
	}
    return A;
}

template <typename T>
 int Matrix<T>::getrank() const
 {
     int i, j, k;	//定义循环变量
     T temp;
     int rank = 0;	//矩阵的秩
     Matrix<T> A=*this;

     for (i = 1; i <= A.column; i++)
     {
         for (j = rank + 1; j <= A.row && A.element[rank + 1][i] == defaultElem; j++)
             if (!(A.element[j][i] == defaultElem))
             {
                 A.rPermutation(rank + 1, j);
                 break;
             }

         if (!(A.element[rank + 1][i] == defaultElem))
         {
             rank++;
             for (j = rank + 1; j <= A.row; j++)
                 if (!(A.element[j][i] == defaultElem))
                 {
                     temp = A.element[j][i] / A.element[rank][i];
                     A.rTriangular(-temp, j, rank);
                 }
         }
     }

     for (i = 1; i <= rank; i++)
     {
         for (j = 1; A.element[i][j] == defaultElem; j++);
         A.rDiagonal(A.element[i][j].rec(), i);
     }

     return rank;
 }

template <typename T>
Space<T>  Matrix<T>::solveLinearEquations() 
{
	Space<T> S;
	int not_key_column[30]{ 0 };
	bool is_keycolumn[30]{ 0 };

	int i, j, k;	//定义循环变量
	T temp;

	Matrix B;		//系数矩阵 
	B.column = column - 1;
	B.row = row;

	for (i = 1; i <= B.row; i++)
		for (j = 1; j <= B.column; j++)
			B.element[i][j] = element[i][j];

	//化成行最简 
    int rank1 = getrank();
    int rank2 = B.getrank;
    B=B.ref(1);
	if (rank1 != rank2)
	{
		S.dimension = -1;				//无解	
		return S;
	}
	else
	{
		for (i = 1; i <= rank1; i++)
		{
			for (j = 1; B.element[i][j] == defaultElem; j++);
			is_keycolumn[j] = true;
		}
		//寻找非key column
		for (i = 1, j = 1; i <= B.column; i++)
			if (!is_keycolumn[i])
			{
				not_key_column[j] = i;
				j++;
			}

		S.dimension = column - 1 - rank1;
		//求特解eta 
		S.par_solution.dimension = column - 1;
		for (i = 1; i <= rank1; i++)
		{
			for (j = 1; j <= column - 1; j++)
			{
				if (is_keycolumn[j] && element[i][j].judge())
				{
					S.par_solution.element[j] = element[i][column];
				}
				else if (!is_keycolumn[j])
				{
					S.par_solution.element[j] = defaultElem;
				}
			}
		}

		//求通解 
		for (i = 1; i <= row; i++)
		{
			element[i][column] = defaultElem;
		}
		for (i = 1; i <= S.dimension; i++)
		{
			S.base[i].dimension = column - 1;
			for (k = 1; k <= rank1; k++)
				for (j = 1; j <= column - 1; j++)
				{
					if (is_keycolumn[j] && element[k][j].judge())
						S.base[i].element[j] = -(element[k][not_key_column[i]]);

					else if (j == not_key_column[i])
					{
						S.base[i].element[j].assign();
					}
					else if (!is_keycolumn[j])
					{
						S.base[i].element[j] = defaultElem;
					}
				}
		}
		return S;
	}
}

template <typename T>
Matrix<T> Matrix<T>:: operator+(const Matrix& other) const                      //矩阵加法
{
	Matrix <T> A;
    if (column != other.column || row != other.row){
        throw length_error{"矩阵加法中矩阵的大小不匹配"};
        return A;
    }
	else
	{
        A.column = column;
		A.row = row;
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= column; j++)
				A.element[i][j] = element[i][j] + other.element[i][j];
		return A;
	}
}

template <typename T>
Matrix<T> Matrix<T>::  operator-(const Matrix& other) const                    //矩阵减法
{
	Matrix <T> A;
    if (column != other.column || row != other.row){
        throw length_error{"矩阵减法中矩阵的大小不匹配"};
        return A;
    }
	else
	{
		A.column = column;
		A.row = row;
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= column; j++)
				A.element[i][j] = element[i][j] - other.element[i][j];
		return A;
	}
}

template <typename T>
Matrix<T>& Matrix<T>:: operator+=(const Matrix& other)
{
	if (column != other.column || row != other.row)
        throw length_error{"矩阵加法中矩阵的大小不匹配"};
	else
	{
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= column; j++)
				element[i][j] += other.element[i][j];
	}
    return *this;
}
template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& other)
{
	if (column != other.column || row != other.row)
        throw length_error{"矩阵减法中矩阵的大小不匹配"};
	else
	{
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= column; j++)
				element[i][j] -= other.element[i][j];
	}
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>:: operator-() const
{
    Matrix <T> A;
    A.column = column;
    A.row = row;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= column; j++)
            A.element[i][j] = -element[i][j];
    return A;
}

template<typename T>
Matrix<T> operator*(T n, const Matrix<T> &m)
{
    Matrix <T> A;
    A.column = m.column;
    A.row = m.row;
    for (int i = 1; i <= m.row; i++)
        for (int j = 1; j <= m.column; j++)
            A.element[i][j] = m.element[i][j] * n;
    return m;
}


template <typename T>
Matrix<T> Matrix<T>::operator*(T n) const						//数乘
{
    Matrix <T> A;
    A.column = column;
    A.row = row;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= column; j++)
            A.element[i][j] = element[i][j] * n;
    return A;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other) const
{
    Matrix<T> A;
	if (column != other.row)
        throw length_error{"矩阵乘法中第一个矩阵的列数与第二个矩阵的行数不相等"};
	else
	{
        A.row = row;
        A.column = other.column;
        for (int i = 1; i <= A.row; i++)
            for (int j = 1; j <= A.column; j++)
				for (int k = 1; k <= column; k++)
                    A.element[i][j] += element[i][k] * other.element[k][j];
	}
    return A;
}
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other)
{
	column = other.column;
	row = other.row;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= column; j++)
		{
			element[i][j] = other.element[i][j];
		}
	}
	return *this;
}

template<typename T>
Polynomial<T>::Polynomial()
{
	deg = 0;
	for (int i = 0; i < MAXSIZE; i++)
	{
		coe[i] = defaultElem;
	}
}
template<typename T>
Polynomial<T> Polynomial<T>::operator+(const Polynomial& other)
{
	Polynomial<T> result;
	if (deg < other.deg)
	{
		int i;
		for (i = 0; i <= deg; i++)
		{
			result.coe[i] = coe[i] + other.coe[i];
		}
		for (; i <= other.deg; i++)
		{
			result.coe[i] = other.coe[i];
		}
		for (i = other.deg; i > 0; i--)
		{
			if (!(result.coe[i] == defaultElem))
				break;
		}
		result.deg = i;
		return result;
	}
	else
	{
		int i;
		for (i = 0; i <= other.deg; i++)
		{
			result.coe[i] = coe[i] + other.coe[i];
		}
		for (; i <= deg; i++)
		{
			result.coe[i] = coe[i];
		}
		for (i = deg; i > 0; i--)
		{
			if (!(result.coe[i] == defaultElem))
				break;
		}
		result.deg = i;
		return result;
	}
}
template<typename T>
Polynomial<T> Polynomial<T>:: operator-(const Polynomial& other)
{
	Polynomial temp = other;
	return *this + (-temp);
}
template<typename T>
Polynomial<T> Polynomial<T>::operator-()
{
	Polynomial<T> result;
	result.deg = deg;
	for (int i = 0; i <= deg; i++)
	{
		result.coe[i] = -coe[i];
	}
	return result;
}
template<typename T>
Polynomial<T> Polynomial<T>::operator*(const Polynomial& other)
{
	int i, j;
	Polynomial<T> result;

	for (i = 0; i <= deg; i++)
		for (j = 0; j <= other.deg; j++)
			result.coe[i + j] += coe[i] * other.coe[j];

	for (i = deg + other.deg; i > 0; i--)
	{
		if (!(result.coe[i] == defaultElem))
			break;
	}
	result.deg = i;
	return result;
}
template<typename T>
Polynomial<T> Polynomial<T>::operator/(const Polynomial& other)
{
	Polynomial<T> quotient;		//商
	quotient.deg = 0;
	int i;

	if (deg == 0 && other.deg == 0)
	{
		quotient.coe[0] = coe[0] / other.coe[0];
		return quotient;
	}
	else if (deg < other.deg)
		return quotient;
	else
	{
		Polynomial<T> f = *this;
		Polynomial<T> temp;
		temp.deg = deg - other.deg;
		temp.coe[temp.deg] = coe[deg] / other.coe[other.deg];
		quotient += temp;
		f -= temp * other;
		return f / other + quotient;
	}
}
template<typename T>
Polynomial<T>& Polynomial<T>:: operator+=(const Polynomial& other)
{
	*this = *this + other;
	return *this;
}
template<typename T>
Polynomial<T>& Polynomial<T>:: operator-=(const Polynomial& other)
{
	*this = *this - other;
	return *this;
}
template<typename T>
Polynomial<T>& Polynomial<T>:: operator*=(const Polynomial& other)
{
	*this = *this * other;
	return *this;
}
template<typename T>
Polynomial<T>& Polynomial<T>:: operator/=(const Polynomial& other)
{
	*this = *this / other;
	return *this;
}
template<typename T>
Polynomial<T> Polynomial<T>:: operator%(const Polynomial& other)
{
	Polynomial<T> result;
	result = *this - (*this / other )* other;
	return result;
}
template<typename T>
Polynomial<T>& Polynomial<T>:: operator=(const Polynomial& other)
{
	deg = other.deg;
	for (int i = 0; i <= deg; i++)
	{
		coe[i] = other.coe[i];
	}
	for (int i = deg + 1; i < MAXSIZE; i++)
	{
		coe[i] = defaultElem;
	}
	return *this;
}
template<typename T>
bool Polynomial<T>::operator==(const Polynomial& other)
{
	if (other.deg != deg)
		return false;
	else
	{
		for (int i = 0; i <= deg; i++)
			if (coe[i] != other.coe[i])
				return false;
		return true;
	}
}


template<typename T>
Matrix<T> Matrix<T>::inv() const
{
	Matrix<T> result;
    Matrix<T> A=*this;

    int i, j;	//定义循环变量
	//赋值增广矩阵	
	result = *this;
	result.column*= 2;
	
	for (i = 1; i <= result.row; i++)
		for (j = this->column + 1; j <= this->column * 2; j++)
		{
			if (j - i == this->column)
			{
				result.element[i][j].assign();
			}
			else
			{
				result.element[i][j] = defaultElem;
			}
		}
    result=result.ref(true);
	
    for (i = 1; i <= A.row; i++)
        for (j = 1; j <= A.column; j++)
            A.element[i][j] = result.element[i][j + A.column];
    return A;
}
template<typename T>
T Matrix<T>::determinant() const                               //行列式
{
	int i, j, k, q;	//定义循环变量，行数，列数
	T temp;
	int rank = 0;	//矩阵的秩 
	T result;
	result.assign();
    Matrix<T> A = *this;


	for (i = 1; i <= this->column; i++)
	{
		for (j = rank + 1; j <= this->row && A.element[rank + 1][i] == defaultElem; j++)
			if (!(A.element[j][i] == defaultElem))
			{
				A.rPermutation(rank + 1, j);
				result = -result;
				break;
			}
		if (!(A.element[rank + 1][i] == defaultElem))
		{
			rank++;
			for (j = rank + 1; j <= this->row; j++)
				if (!(A.element[j][i] == defaultElem))
				{
					temp = A.element[j][i] / A.element[rank][i];
					A.rTriangular(-temp, j, rank);
				}
		}
	}
	for (i = 1; i <= this->column; i++)
		result *= A.element[i][i];

	return result;
}
template <typename T>
Polynomial<T> Matrix<T>::eigenpoly()                     //特征多项式
{
    Matrix<Polynomial<T>>* A;

	A = toLambdaMatrix();
	Polynomial<T> temp;
	Polynomial<T> temp1;
	Polynomial<T> eigenpoly;
	eigenpoly.coe[0].assign();

	A->nor();		//没问题了
	for (int i = 1; i <= this->column; i++)
		if (!(A->element[i][i].deg == 0 && A->element[i][i].coe[0] == defaultElem))
			eigenpoly *= A->element[i][i];

	if (eigenpoly.coe[eigenpoly.deg].judge() == false)
	{
		temp.deg = 0;
		temp.coe[0] = eigenpoly.coe[eigenpoly.deg];
		eigenpoly = eigenpoly / temp;
	}
	return eigenpoly;
}

template <typename T>
void Matrix<T>::nor()
{
    T temp;
    T quotient;
	T temp2;
	temp2.deg = 0;
	int i, j, k;
	int min_deg;
	int pos_row, pos_column;

	bool finish = false;		//若矩阵剩下位置全为0则结束
	bool done = false;

	int size;
	size = std::min(this->column, this->row);

	for (i = 1; i <= size && !finish; i++)
	{
		finish = true;
		for (j = i; j <= this->row; j++)
			for (k = i; k <= this->column; k++)
			{
				if (this->element[j][k].deg > 0)
					finish = false;
                else if (!(this->element[j][k].coe[0] == defaultElem))
					finish = false;
			}

		if (finish)
			break;

		min_deg = 33;
		for (j = i; j <= this->row; j++)
			for (k = i; k <= this->column; k++)
				if (this->element[j][k].deg < min_deg)
				{
					if (this->element[j][k].deg == 0)
					{
                        if (!(this->element[j][k].coe[0] == defaultElem))
							min_deg = this->element[j][k].deg;
					}
					else
						min_deg = this->element[j][k].deg;
				}

		if (min_deg != 0)
		{
			for (j = i; j <= this->row; j++)
				for (k = i; k <= this->column; k++)
					if (this->element[j][k].deg == min_deg)
					{
						pos_row = j;
						pos_column = k;
						break;
					}
		}
		else
		{
			for (j = i; j <= this->row; j++)
				for (k = i; k <= this->column; k++)
                    if (!(this->element[j][k].coe[0] == defaultElem) && this->element[j][k].deg == 0)
					{
						pos_row = j;
						pos_column = k;
						break;
					}
		}

		this->cPermutation(i, pos_column);
		this->rPermutation(i, pos_row);

		done = false;
		while (!done)
		{
			done = true;
			for (j = i; j <= this->row && done; j++)
				for (k = i; k <= this->column && done; k++)
				{
					temp = this->element[j][k] % this->element[i][i];
                    if (!(temp.deg == 0 && temp.coe[0] == defaultElem))
					{
						if (j == i)
						{
							quotient = this->element[j][k] / this->element[i][i];

							this->cTriangular(-quotient, k, i);
							this->cPermutation(i, k);
							done = false;
						}
						else if (k == i)
						{
							quotient = this->element[j][k] / this->element[i][i];

							this->rTriangular(-quotient, j, i);
							this->rPermutation(i, j);
							done = false;
						}
						else
						{
							//先把j，i化为0
							quotient = this->element[j][i] / this->element[i][i];
							this->rTriangular(-quotient, j, i);
							//设置一个常数多项式1
							temp.coe[0].assign();
							temp.deg = 0;
							this->rTriangular(temp, i, j);
							//接下来等同于处理i k的操作 
							quotient = this->element[i][k] / this->element[i][i];
							this->cTriangular(-quotient, k, i);
							this->cPermutation(i, k);
							done = false;
						}
					}
				}
		}

		for (j = i + 1; j <= this->row; j++)
		{
			quotient = this->element[j][i] / this->element[i][i];
			this->rTriangular(-quotient, j, i);
		}
		for (k = i + 1; k <= this->column; k++)
		{
			quotient = this->element[i][k] / this->element[i][i];
			this->cTriangular(-quotient, k, i);
		}

	}
	//首一化
	for (i = 1; i <= size; i++)
	{
		if (!(this->element[i][i].coe[this->element[i][i].deg].judge() ) )
		{
			temp2.coe[0] = ( this->element[i][i].coe[this->element[i][i].deg].rec() );
			this->rDiagonal(temp2, i);
		}
	}
	return;
}

template <typename T>
void Matrix<T>::rcf() //有理标准型
{
	int i, j, k, pos;
	Polynomial<T> temp;

    Matrix<T> B;
	B = *this;

	pos = 1;
	for (i = 1; i <= this->row; i++)
	{
		for (j = 1; j <= this->column; j++)
		{
			this->element[i][j] = defaultElem;
		}
	}

	for (i = 1; i <= this->row; i++)
	{
		temp = B.get_factor(1).element[i];
		if (temp.deg != 0)
		{
			for (j = pos; j <= pos + temp.deg - 2; j++)
			{
				this->element[j][j + 1].assign();
			}
			j = pos + temp.deg - 1;
			for (k = pos; k <= pos + temp.deg - 1; k++)
			{
				this->element[j][k] = -temp.coe[k - pos];
			}
			pos += temp.deg;
		}
	}
}
template <typename T>
Polynomial<T> Matrix<T>::minimalpoly()                    //极小多项式
{
    Matrix<T> A;
	A = *this;
    Vector<Polynomial<T>> g;
	g = A.get_factor(1);
	Polynomial<T> result;
	result= g.element[this->column];
	return result;
}

template <typename T>
Vector<Polynomial<T>> Matrix<T>::get_factor(bool mode)               // mode=0 行列式因子  mode=1 不变因子
{
	int i, j;
    Vector<Polynomial<T>> g_factor;		//不变因子
    Vector<Polynomial<T>> D_factor; 	//行列式因子
	Polynomial<T> temp;
    Matrix<Polynomial<T>> *B;
	B = toLambdaMatrix();

	g_factor.dimension = B->column;
	D_factor.dimension = B->column;

	B->nor();
	for (i = 1; i <= B->column; i++)
		g_factor.element[i] = B->element[i][i];

	temp = g_factor.element[1];
	for (i = 1; i <= B->column; i++)
	{
		D_factor.element[i] = temp;
		if (i != B->column)
			temp *= g_factor.element[i + 1];
	}
	delete(B);
	if (mode == 1)
		return g_factor;
	else
		return D_factor;
}
template <typename T>
Matrix<Polynomial<T>>* Matrix<T>::toLambdaMatrix()
{
    Matrix<Polynomial<T>>* result = new Matrix<Polynomial<T>>{};
	result->column = this->column;
	result->row = this->row;
	int i, j, k;
	for (i = 1; i <= this->row; i++)
		for (j = 1; j <= this->column; j++)
		{
			if (i == j)
			{
				result->element[i][j].deg = 1;
				result->element[i][j].coe[0] = -this->element[i][j];
				result->element[i][j].coe[1].assign();
			}
			else
			{
				result->element[i][j].deg = 0;
				result->element[i][j].coe[0] = -this->element[i][j];
			}
		}
	return result;
}


//所有IO


template <typename T>
void Polynomial<T>::print()
{
	const char variable[5] = "λ";
	int i;
	for (i = deg; i >= 0; i--)
	{
		if (i != 1 && i != 0 && i != deg)
		{
			if (coe[i] > defaultElem)
			{
				if (coe[i].judge())
				{
					printf("+");
					printf("%s", variable);
					printf("^%d", i);
				}
				else
				{
					printf("+");
					coe[i].print();
					printf("%s", variable);
					printf("^%d", i);
				}
			}
			else if (coe[i] < defaultElem)
			{
				if ((-coe[i]).judge())
				{
					printf("-");
					printf("%s", variable);
					printf("^%d", i);
				}
				else
				{
					coe[i].print();
					printf("%s", variable);
					printf("^%d", i);
				}
			}
		}
		else if (i == deg)
		{
			if (i != 1 && i != 0)
			{
				if (coe[i].judge())
				{
					printf("%s", variable);
					printf("^%d", i);
				}
				else if ((-coe[i]).judge())
				{
					printf("-");
					printf("%s", variable);
					printf("^%d", i);
				}
				else
				{
					coe[i].print();
					printf("%s", variable);
					printf("^%d", i);
				}
			}
			else if (i == 1)
			{
				if (coe[i].judge())
				{
					printf("%s", variable);
				}
				else if ((-coe[i]).judge())
				{
					printf("-");
					printf("%s", variable);
				}
				else
				{
					coe[i].print();
					printf("%s", variable);
				}
			}
			else if (i == 0)
				coe[i].print();
		}
		else if (i == 1)			//普通的一次项 
		{
			if (coe[i] > defaultElem)
			{
				if (coe[i].judge())
				{
					printf("+");
					printf("%s", variable);
				}
				else
				{
					printf("+");
					coe[i].print();
					printf("%s", variable);
				}
			}
			else if (coe[i] < defaultElem)
			{
				if ((-coe[i]).judge())
				{
					printf("-");
					printf("%s", variable);
				}
				else
				{
					coe[i].print();
					printf("%s", variable);
				}
			}
		}
		else if (i == 0)
		{
			if (coe[i] > defaultElem)
			{
				printf("+");
				coe[i].print();
			}
			else if (coe[i] < defaultElem)
			{
				coe[i].print();
			}
		}

	}
	return;
}
template <typename T>
void Matrix<T>::scan()
{
	printf("\n");
	int i, j;
	
	printf("请输入矩阵的规模\n");
	scanf("%d%d", &row, &column);
	fflush(stdin);

	printf("请输入矩阵元素\n");
	for (i = 1; i <= row; i++)
		for (j = 1; j <= column; j++)
			element[i][j].scan();
	fflush(stdin);
	return;
}

template <typename T>
void Matrix<T>::print()
{
	int i, j;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= column; j++)
		{
			element[i][j].print();
			printf("\t");
		}
		printf("\n");
	}
	return;
}

#endif // MATRIX_H

