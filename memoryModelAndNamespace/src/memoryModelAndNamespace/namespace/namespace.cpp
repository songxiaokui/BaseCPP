//
// Created by 宋晓奎 on 2023/12/19.
//

#include "namespace.h"

void fetch();
void fetch()
{
    cout << "this is global fetch() calling" << endl;
}


char pail[] = "global pail";



void usingNameSpace();
void usingNameSpace()
{
    Jill::fetch();
    Jack::fetch();
    // 全局作用域函数调用
    ::fetch();

    cout << "Jill:pail = " << Jill::pail << endl;
    cout << "Jack:pail = " << Jack::pail << endl;
    cout << "Global::pail = " << ::pail << endl;

}

void localVariableSubstitution(void);
void localVariableSubstitution(void)
{
    cout << "global variable pail is: " << pail << endl;  // is equal ::pail
    using Jill::pail;
    cout << "local variable substitution: pail is: " << pail << endl;
}

void Namespace(void)
{
    cout << "This is namespace file ." << endl;
    // 概念理解
    // 1. 声明区域（可以在其中声明的区域）（全局变量的声明区域为所有变量，自动变量的声明区域在当前所在代码块）
    // 2. 潜在作用域（从声明开始一致到声明区域结束）
    // 3. 作用域（变量对程序可见的范围为作用域，同名变量隐藏区域不是作用域）

    // 定义命名空间的函数与变量
    usingNameSpace();
    // 命名空间可以是全局的 也可以位于另一个命名空间 但不能在代码块中
    // 默认情况下 名称空间内声明的名称为外部链接性
    // 全局名称空间：文件级别声明 全局变量就是全局名称空间
    // 使用名称空间的内容: 使用作用域解析运算符 ::


    // using声明与using编译指令
    // 目的: 简化对名称空间内名称的使用
    // using声明: 声明就是使指定的标识符可用
    // using编译指令: 使整个名称空间可用
    localVariableSubstitution();

    // using编译指令的使用:
    // 使用 using namespace 名称空间;
    using namespace Jill;
    // cout << "Jill namespace pail: " << pail << endl;  // 产生二义性
    // 与 ::pail 产生冲突 不知道是使用 Jill中的pail 还是使用全局中的pail
    // 正确使用: 增加作用域解析运算符 指定明确的命名空间
    cout << "Jill::pail: " << Jill::pail << endl;
    cout << "Global::pail: " << ::pail << endl;

    // 注意: 如果一个名称已经在代码块中声明 则不能再使用using 声明进行该名称的声明
    /*
    int pail;
    using Jill::pail;
    using Jack::pail;

     // 上述代码会报错
    */

    {
        using namespace Jill;
        // 局部变量会隐藏全局pail与Jill命名空间下的pail
        double pail = 1.11;
        cout << "pail: " << pail << endl;
        // 使用作用域解析运算符 可以正常使用全局pail和指定名称空间下的pail
        cout << "Global pail:" << ::pail << endl;
        // Jill::pail
        cout << "namespace variable use: " << Jill::pail << endl;
    }

    // 通常来说: 使用using声明比using 编译指令安全,using声明只导入了指定的名称

    // using编译指令注意的问题:
    // 1. using namespace 名称空间;放在代码卡内，名称空间的所有名称只在代码块生效
    // 2. using namespace 名称空间; 放在全局名称名称空间,方便但是容易被局部变量隐藏
    // 3. 尽量使用 作用域解析运算符方式使用或者使用using 声明只引入需要的名称
}