#ifndef COMPUTATION_H
#define COMPUTATION_H

#include <stdexcept>
#include <basestructure.h>
#include <string.h>

// 五维函数指针数组，解决复杂的类型解析及计算
// 第一维：运算符类型，第二维：第一操作数类型，第三维：第一操作数数字类型，四五维同二三维，为第二操作数
extern Var (*func[100][10][5][10][5])(const Var&, const Var&);

// 初始化所有运算
void initComputaion();

#endif // COMPUTATION_H
