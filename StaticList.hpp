#ifndef STATICLIST_H
#define STATICLIST_H

#include "SeqList.hpp"

namespace SLIB
{
    template <typename T, int N>
    class StaticList : public SeqList<T>
    {
    protected:
        T m_space[N];   // 顺序存储空间，N 为模板参数
    public:
        StaticList();   // 指定父类的具体值
        virtual int capacity() const;
    };

    template<typename T, int N>
    StaticList<T, N>::StaticList()
    {
        this->m_array = m_space;
        this->m_length = 0;
    }

    template<typename T, int N>
    int StaticList<T, N>::capacity() const
    {
        return N;
    }
}

#endif  // STATICLIST_H
