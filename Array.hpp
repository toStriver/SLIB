#ifndef ARRAY_H
#define ARRAY_H

#include "Object.h"
#include "Exception.h"

namespace SLIB
{
    template<typename T>
    class Array : public Object
    {
    protected:
        T *m_array;
    public:
        bool get(int i, T& e) const;
        bool set(int i, const T& e);
        T& operator[](int i);
        T operator[](int i) const;
        virtual int length() const = 0;
    };

    template<typename T>
    bool Array<T>::get(int i, T& e) const
    {
        bool ret = ((0 <= i) && (i < length()));

        if(ret)
        {
            e = m_array[i];
        }

        return ret;
    }

    template<typename T>
    bool Array<T>::set(int i, const T& e)
    {
        bool ret = ((0 <= i) && (i < length()));

        if(ret)
        {
            m_array[i] = e;
        }

        return ret;
    }

    template<typename T>
    T& Array<T>::operator[](int i)
    {
        bool ret = ((0 <= i) && (i < length()));

        if(ret)
        {
            return m_array[i];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "The index of array is invalid...");
        }
    }

    template<typename T>
    T Array<T>::operator[](int i) const
    {
        return (const_cast<Array<T>&>(*this))[i];
    }

}

#endif  // ARRAY_H
