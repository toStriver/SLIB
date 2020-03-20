#ifndef OBJECT_H
#define OBJECT_H

namespace SLIB
{
    class Object
    {
    public:
        void* operator new(unsigned int size) throw();
        void operator delete(void* p);
        void* operator new[](unsigned int size) throw();
        void operator delete[](void* p);
        virtual ~Object() = 0;
    };

}

#endif
