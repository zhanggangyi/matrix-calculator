#include <computation.h>

Var (*func[100][10][5][10][5])(const Var&, const Var&);

void initComputaion()
{
    // 初始化所有运算为空指针
    memset(func, 0, sizeof(func));

    /**********************************************定义一元运算******************************************************/

    /************************************************定义取正*******************************************************/
    // 有理数的取正
    func[ADD][NUM_TYPE][RATIONAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        return Var{b1.val.nRational};};
    // 实数的取正
    func[ADD][NUM_TYPE][REAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        return Var{b1.val.nReal};};

    /************************************************定义取负*******************************************************/
    // 有理数的取负
    func[SUB][NUM_TYPE][RATIONAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        return Var{-b1.val.nRational};};
    // 实数的取负
    func[SUB][NUM_TYPE][REAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        return Var{-b1.val.nReal};};


    /**********************************************定义二元运算******************************************************/

    /************************************************定义加法*******************************************************/
    // 有理数与有理数的加法
    func[ADD][NUM_TYPE][RATIONAL_NUM][NUM_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        return Var{b1.val.nRational + b2.val.nRational};};
    // 有理数与实数的加法
    func[ADD][NUM_TYPE][RATIONAL_NUM][NUM_TYPE][REAL_NUM] = [](const Var& b1, const Var& b2){
        Var temp{};
        temp.val.nReal=b1.val.nRational.toDouble();
        return Var{temp.val.nReal + b2.val.nReal};};
    func[ADD][NUM_TYPE][REAL_NUM][NUM_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        Var temp{};
        temp.val.nReal=b2.val.nRational.toDouble();
        return Var{b1.val.nReal + temp.val.nReal};};
    // 实数与实数的加法
    func[ADD][NUM_TYPE][REAL_NUM][NUM_TYPE][REAL_NUM] = [](const Var& b1, const Var& b2){
        return Var{b1.val.nReal + b2.val.nReal};};
    // ~~~~~~~~矩阵加法~~~~~~~~
    // 有理数矩阵加法
    func[ADD][MATRIX_TYPE][RATIONAL_NUM][MATRIX_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        Var result{"result", MATRIX_TYPE, RATIONAL_NUM};
        try{result.val.mRational = b1.val.mRational + b2.val.mRational;}
        catch(const exception& e){throw e;}
        return result;};
    // 实数矩阵加法
    func[ADD][MATRIX_TYPE][REAL_NUM][MATRIX_TYPE][REAL_NUM] = [](const Var& b1, const Var& b2){
        Var result{"result", MATRIX_TYPE, REAL_NUM};
        try{result.val.mReal = b1.val.mReal + b2.val.mReal;}
        catch(const exception& e){throw e;}
        return result;};

    /************************************************定义减法*******************************************************/
    // 有理数与有理数的减法
    func[SUB][NUM_TYPE][RATIONAL_NUM][NUM_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        return Var{b1.val.nRational - b2.val.nRational};};
    // 有理数与实数的减法
    func[SUB][NUM_TYPE][RATIONAL_NUM][NUM_TYPE][REAL_NUM] = [](const Var& b1, const Var& b2){
        Var temp{};
        temp.val.nReal=b1.val.nRational.toDouble();
        return Var{temp.val.nReal - b2.val.nReal};};
    func[SUB][NUM_TYPE][REAL_NUM][NUM_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        Var temp{};
        temp.val.nReal=b2.val.nRational.toDouble();
        return Var{b1.val.nReal - temp.val.nReal};};
    // 实数与实数的减法
    func[SUB][NUM_TYPE][REAL_NUM][NUM_TYPE][REAL_NUM] = [](const Var& b1, const Var& b2){
        return Var{b1.val.nReal - b2.val.nReal};};
    // ~~~~~~~~矩阵减法~~~~~~~~
    // 有理数矩阵减法
    func[SUB][MATRIX_TYPE][RATIONAL_NUM][MATRIX_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        Var result{"result", MATRIX_TYPE, RATIONAL_NUM};
        try{result.val.mRational = b1.val.mRational - b2.val.mRational;}
        catch(const exception& e){throw e;}
        return result;};
    // 实数矩阵减法
    func[SUB][MATRIX_TYPE][REAL_NUM][MATRIX_TYPE][REAL_NUM] = [](const Var& b1, const Var& b2){
        Var result{"result", MATRIX_TYPE, REAL_NUM};
        try{result.val.mReal = b1.val.mReal - b2.val.mReal;}
        catch(const exception& e){throw e;}
        return result;};

    /************************************************定义乘法*******************************************************/
    // 有理数与有理数的乘法
    func[MUL][NUM_TYPE][RATIONAL_NUM][NUM_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        return Var{b1.val.nRational * b2.val.nRational};};
    // 有理数与实数的乘法
    func[MUL][NUM_TYPE][RATIONAL_NUM][NUM_TYPE][REAL_NUM] = [](const Var& b1, const Var& b2){
        Var temp{};
        temp.val.nReal=b1.val.nRational.toDouble();
        return Var{temp.val.nReal * b2.val.nReal};};
    func[MUL][NUM_TYPE][REAL_NUM][NUM_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        Var temp{};
        temp.val.nReal=b2.val.nRational.toDouble();
        return Var{b1.val.nReal * temp.val.nReal};};
    // 实数与实数的乘法
    func[MUL][NUM_TYPE][REAL_NUM][NUM_TYPE][REAL_NUM] = [](const Var& b1, const Var& b2){
        return Var{b1.val.nReal * b2.val.nReal};};
    // ~~~~~~~~矩阵乘法~~~~~~~~
    // 有理数矩阵乘法
    func[MUL][MATRIX_TYPE][RATIONAL_NUM][MATRIX_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        Var result{"result", MATRIX_TYPE, RATIONAL_NUM};
        try{result.val.mRational = b1.val.mRational * b2.val.mRational;}
        catch(const exception& e){throw e;}
        return result;};
    // 实数矩阵乘法
    func[MUL][MATRIX_TYPE][REAL_NUM][MATRIX_TYPE][REAL_NUM] = [](const Var& b1, const Var& b2){
        Var result{"result", MATRIX_TYPE, REAL_NUM};
        try{result.val.mReal = b1.val.mReal * b2.val.mReal;}
        catch(const exception& e){throw e;}
        return result;};


    /************************************************定义除法*******************************************************/

    // 有理数与有理数的除法
    func[DIV][NUM_TYPE][RATIONAL_NUM][NUM_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        return Var{b1.val.nRational / b2.val.nRational};};
    // 有理数与实数的除法
    func[DIV][NUM_TYPE][RATIONAL_NUM][NUM_TYPE][REAL_NUM] = [](const Var& b1, const Var& b2){
        Var temp{};
        temp.val.nReal=b1.val.nRational.toDouble();
        return Var{temp.val.nReal / b2.val.nReal};};
    func[DIV][NUM_TYPE][REAL_NUM][NUM_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        Var temp{};
        temp.val.nReal=b2.val.nRational.toDouble();
        return Var{b1.val.nReal / temp.val.nReal};};
    // 实数与实数的除法
    func[DIV][NUM_TYPE][REAL_NUM][NUM_TYPE][REAL_NUM] = [](const Var& b1, const Var& b2){
        return Var{b1.val.nReal / b2.val.nReal};};


    /************************************************矩阵计算*******************************************************/
    // 实数矩阵求逆
    func[INV][MATRIX_TYPE][REAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        Var result{"result", MATRIX_TYPE, REAL_NUM};
        result.val.mReal = b1.val.mReal.inv();
        return result;};

    //有理数矩阵求逆
    func[INV][MATRIX_TYPE][RATIONAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
        Var result{"result", MATRIX_TYPE, RATIONAL_NUM};
        result.val.mRational = b1.val.mRational.inv();
        return result;};

    // 实数矩阵化简1（行阶梯型）
    func[LREF][MATRIX_TYPE][REAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
    Var result{"result", MATRIX_TYPE, REAL_NUM};
    result.val.mReal = b1.val.mReal.ref(false);
    return result;};

    //有理数矩阵化简1（行阶梯型）
    func[LREF][MATRIX_TYPE][RATIONAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
    Var result{"result", MATRIX_TYPE, RATIONAL_NUM};
    result.val.mRational = b1.val.mRational.ref(false);
    return result;};

    // 实数矩阵化简2（行最简型）
    func[MREF][MATRIX_TYPE][REAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
    Var result{"result", MATRIX_TYPE, REAL_NUM};
    result.val.mReal = b1.val.mReal.ref(true);
    return result;};

    //有理数矩阵化简2（行最简型）
    func[MREF][MATRIX_TYPE][RATIONAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
    Var result{"result", MATRIX_TYPE, RATIONAL_NUM};
    result.val.mRational = b1.val.mRational.ref(true);
    return result;};


    // 实数矩阵化简1（行阶梯型）
    func[DET][MATRIX_TYPE][REAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
    Var result{"result", NUM_TYPE, REAL_NUM};
    result.val.nReal = b1.val.mReal.determinant();
    return result;};

    //有理数矩阵化简1（行阶梯型）
    func[DET][MATRIX_TYPE][RATIONAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
    Var result{"result", NUM_TYPE, RATIONAL_NUM};
    result.val.nRational = b1.val.mRational.determinant();
    return result;};

    //单位矩阵
    /*
    func[DET][MATRIX_TYPE][RATIONAL_NUM][NONE_TYPE][RATIONAL_NUM] = [](const Var& b1, const Var& b2){
    Var result{"result", MATRIX_TYPE, RATIONAL_NUM};
    result.val.nRational = b1.val.mRational.determinant();
    return result;};
    */






































































}
