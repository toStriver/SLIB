#ifndef STATICARRAY_H
#define STATICARRAY_H

#include "Array.hpp"

namespace SLIB
{
    template<typename T, int N>
    class StaticArray : public Array<T>
    {
    protected:
        T m_space[N];
    public:
        StaticArray();
        StaticArray(const StaticArray<T, N>& e);
        StaticArray<T, N>& operator=(const StaticArray<T, N>& e);
        int length() const;
    };

    template<typename T, int N>
    StaticArray<T, N>::StaticArray()
    {
        this->m_array = m_space;
    }

    template<typename T, int N>
    StaticArray<T, N>::StaticArray(const StaticArray<T, N>& e)
    {
        this->m_array = m_space;

        for(int i = 0; i < N; i++)
        {
            m_space[i] = e.m_space[i];
        }
    }

    template<typename T, int N>
    StaticArray<T, N>& StaticArray<T, N>::operator=(const StaticArray<T, N>& e)
    {
        if(this != &e)
        {
            for(int i = 0; i < N; i++)
            {
                m_space[i] = e.m_space[i];
            }
        }

        return *this;
    }

    template<typename T, int N>
    int StaticArray<T, N>::length() const
    {
        return N;
    }
}

#endif  // STATICARRAY_H
