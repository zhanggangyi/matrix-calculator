#include "myalgorithm.h"

QStringList split(QString input){
    QStringList stringlist;
    QRegularExpressionMatchIterator iter=pattern.globalMatch(input);
    while(iter.hasNext()){
        QRegularExpressionMatch match = iter.next();
        stringlist.append(match.captured(0));
    }
    return stringlist;
}

bool caculate(QStringList expression, VariableManager* manager, QString& rtv){
    QStack<Var> values;
    QString mani, s;
    while(!expression.empty()){
        s = expression.first(); expression.pop_front();
        // 如果是操作符
        if (pattern_operator.match(s).hasMatch()){
            mani = s;
            Var v1 = values.top(); values.pop();
            Var v2 = values.top(); values.pop();
            Var result;
            try{
                run(v2, v1, mani, result);
            }
            catch(const exception& e)
            {
                rtv = e.what();
                return false;
            }
            values.push(result);
        }
        else{
            values.push_back(Var(s));
        }
    }
    Var ans = values.top();
    rtv = ans.toString();
    if(manager->exist(ans.name))
        manager->set(ans.name, ans);
    else
        manager->add(ans);

    return true;
}

QStringList sort_elems(QStringList expression){
    QStack<Manipulator> stack;
    QStringList result;
    QString str;
    Manipulator mani;
    bool binary=false;
    while(!expression.empty()){
        str = expression.first();
        if(pattern_num.match(str).hasMatch() || (!pattern_operator.match(str).hasMatch() &&
                                                 pattern_variable.match(str).hasMatch())){
            result.append(str);
            binary = true;
        }
        else if(pattern_operator.match(str).hasMatch()){
            if(str == "("){
                stack.push(Manipulator{.name="(", .binary=true});
            }
            else if(str == ")"){
                while (stack.top().name != "(") {
                    if(stack.top().binary == false)
                        result.append("None");
                    result.append(stack.top().name);
                    stack.pop();
                }
                stack.pop();
            }
            else{                    
                mani={.name=str, .binary=binary};
                while(!stack.empty() && (operator_priority[mani] > operator_priority[stack.top()]
                      || (operator_priority[mani] == operator_priority[stack.top()]
                      && left_composition[operator_priority[stack.top()]]))){
                    if(stack.top().binary == false)
                        result.append("None");
                    result.append(stack.top().name);
                    stack.pop();
                }
                stack.push(mani);
                binary=false;
            }
        }
        expression.pop_front();
    }
    while(!stack.empty()){
        if(stack.top().binary == false)
            result.append("None");
        result.append(stack.top().name);
        stack.pop();
    }
    return result;
}


void run(Var v1, Var v2, QString oper, Var& result)
{
    Var (*p)(const Var&, const Var&) = func[s2c[oper]][v1.dataType][v1.numType][v2.dataType][v2.numType];
    if(p == nullptr)
        return;
    try{result = p(v1, v2);}
    catch(const exception& e){throw e;}
    return;
}
