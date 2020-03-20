#include <iostream>
#include <SmartPointer.hpp>
#include <Exception.h>
#include <Object.h>

using namespace std;
using namespace SLIB;

class Test : public Object
{
public:
    int i;
    Test(int i = 0);
};

Test::Test(int i)
{
    this->i = i;
}

int main()
{
    SmartPointer<Test> *sp1 = new SmartPointer<Test>(); // 在创建对象后（void* operator new(unsigned int size) ），再调用类的构造函数

    delete sp1; // 在销毁对象前(void operator delete(unsigned int size) )，会调用类的析构函数

    // 通过宏替换可提高代码的移植性，比如这样注释，宏代码相当于没有调用
    // #define THROW_EXCEPTION(eType, eInfo) //注释掉...(throw eType(eInfo, __FILE__, __LINE__))
    //THROW_EXCEPTION(InvalidParameterException, "it will throw an exception...");

    cout << "main() end " << endl;

    return 0;
}
