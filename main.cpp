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
    SmartPointer<Test> *sp1 = new SmartPointer<Test>(); // 在创建好的内存空间上（void* operator new(unsigned int size) ），调用类的构造函数并创建对象

    delete sp1; // 在析构函数中，销毁资源(void operator delete(unsigned int size) )

    // 通过宏替换可提高代码的移植性，比如这样注释，宏代码相当于没有调用
    // #define THROW_EXCEPTION(eType, eInfo) //注释掉...(throw eType(eInfo, __FILE__, __LINE__))
    //THROW_EXCEPTION(InvalidParameterException, "it will throw an exception...");

    cout << "main() end " << endl;

    return 0;
}
