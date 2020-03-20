#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "Object.h"

namespace SLIB
{
    template <typename T>
    class SmartPointer : public Object
    {
    private:
        T* m_pointer;
    public:
        SmartPointer(T *pointer = 0);
        SmartPointer(const SmartPointer<T>& obj);
        SmartPointer<T>& operator=(const SmartPointer<T>& obj);
        T* operator->();
        T& operator*();
        ~SmartPointer();
    };

    template <typename T>
    SmartPointer<T>::SmartPointer(T* pointer)
    {
        m_pointer = pointer;
    }

    template <typename T>
    SmartPointer<T>::SmartPointer(const SmartPointer<T>& obj)
    {
        m_pointer = obj.m_pointer;
        const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
    }

    template <typename T>
    SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& obj)
    {
        if(this != &obj)
        {
            delete m_pointer;
            m_pointer = obj.m_pointer;
            const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
        }

        return *this;
    }

    template <typename T>
    T* SmartPointer<T>::operator->()
    {
        return m_pointer;
    }

    template <typename T>
    T& SmartPointer<T>::operator*()
    {
        return *m_pointer;
    }

    template <typename T>
    SmartPointer<T>::~SmartPointer()
    {
        delete m_pointer;
    }
}

#endif
