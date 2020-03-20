#include "Object.h"
#include <cstdlib>
#include <iostream>

using namespace std;

namespace SLIB
{
    void* Object::operator new(unsigned int size) throw()
    {
        cout << "size : " << size << endl;
        return malloc(size);
    }

    void Object::operator delete(void* p)
    {
        cout << "void Object::operator delete(void* p)" << endl;
        free(p);
    }

    void* Object::operator new[](unsigned int size) throw()
    {
        cout << "size : " << size << endl;
        return malloc(size);
    }

    void Object::operator delete[](void* p)
    {
        cout << "void Object::operator delete[](void* p)" << endl;
        free(p);
    }

    Object::~Object()
    {
        
    }


}
