#include "basestructure.h"
#include "field.h"

QVector<Var> vars;
Var clipboard;

Var::Var()
{
    name = "missing";
    dataType = NONE_TYPE;
    numType = RATIONAL_NUM;

   //劳资不赋值了
}

Var::Var(QString name_, DataType dataType_, NumType numType_)
{
    name = name_;
    dataType = dataType_;
    numType = numType_;
}

Var::Var(QString s){
    *this = Var();
    if(type_var.match(s).hasMatch()){
        for(const Var& v: vars){
            if(v.name == s){
                *this = v;
            }
        }
    }else{
        dataType = NUM_TYPE;
        if(type_int.match(s).hasMatch()){       //这里可能有点问题
            val.nRational = toRational(s);
        }
        else if(type_real.match(s).hasMatch()){
            val.nReal.value = s.toDouble();
        }
    }
}


Var::Var(Double n)
{
    dataType = NUM_TYPE;
    numType = REAL_NUM;
    val.nReal.value = n.value;
}

Var::Var(Qnum n)
{
    dataType = NUM_TYPE;
    numType = RATIONAL_NUM;
    val.nRational = n;
}

QString Var::toString()
{
    if(dataType == NONE_TYPE)
        return "None";
    else if(dataType == NUM_TYPE){
        switch (numType) {
        case RATIONAL_NUM:
        {
            return toQstring(val.nRational);
        }
        case REAL_NUM:
            return QString::number(val.nReal.value);
        default:
            break;
        }
    }
    else
        return name;
}

void Var::clear()
{
    this->dataType=NONE_TYPE;
    this->numType=RATIONAL_NUM;
}
