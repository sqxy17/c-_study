#include "24_模板的分离编译.h"

//template<class T>
//void add(T x,T y)//这里无法通过编译,因为不知道T是什么类型,也就是说这里在传入两个double类型的数据之后,没有把函数进行实例化,也就是没有转换成汇编代码
////总的原因就是这里无法将函数模板进行实例化,也就没法生成汇编代码,这个函数就没有地址,
//{
//    cout<<x+y<<endl;
//}
//
////解决办法一      -----显式的实例化出来.但是这种方式的缺陷是用什么类型就要实例化出来这个类型的函数,虽然double能用了,但是char又不能使用了
////也就是说,体现不出泛型的意义了
//template
//void add<double>(double,double);      //----也就是显式的将这个类型的函数实例化出来

//所以最好的解决方式就是声明和定义放在一起






template<class T>//也就是说在.h的里面,类的内部只有函数的声明,但是定义却在这个cpp的文件里面,所以出现的错误和类模板的错误是一样的
A<T>::A()
:_con(0)
{}
//能在主函数中使用  A<int>*之类的定义一个指针,不能用A<int>之类的来实例化对象


//解决方法一:显式实例化
//template
//class A<int>;

//也可以实例化这个构造函数
//template
//A<int>::A();


//总了来说尽量是将模板的声明和定义,函数或者类都放在一起


void sub(int x,int y)
{
    cout<<x-y<<endl;
}
