#ifndef SEQLIST_H
#define SEQLIST_H

#include "List.hpp"
#include "Exception.h"

namespace SLIB
{
    template <typename T>
    class SeqList : public List<T>
    {
    protected:
        T* m_array;     // 顺序存储空间
        int m_length;   // 当前线性表的长度
    public:
        virtual bool insert(int i, const T& e);
        virtual bool insert(const T& e);
        virtual bool remove(int i);
        virtual bool set(int i, const T& e);
        virtual bool get(int i, T& e) const;
        virtual int length() const;
        virtual void clear();

        // 顺序存储线性表的数组访问方式
        T& operator[](int i);
        T operator[](int i) const;

        // 线性存储空间的容量，由子类创建
        virtual int capacity() const = 0;
    };

    template <typename T>
    bool SeqList<T>::insert(int i, const T& e)  // O(n)
    {
        int ret = ( (0 <= i) && (i <= m_length) ) && ( m_length < capacity() );

        if(ret)
        {
            for(int pos = m_length-1; pos >= i; pos--)
            {
                m_array[pos+1] = m_array[pos];
            }
            m_array[i] = e;
            m_length++;
        }

        return ret;
    }

    template<typename T>
    bool SeqList<T>::insert(const T& e) // O(1)
    {
        return insert(m_length, e);
    }

    template <typename T>
    bool SeqList<T>::remove(int i)  // O(n)
    {
        bool ret = (0 <= i) && (i < m_length);

        if(ret)
        {
            for(int pos = i; pos < m_length-1; pos++)
            {
                m_array[pos] = m_array[pos+1];
            }
            m_length--;
        }

        return ret;
    }

    template <typename T>
    bool SeqList<T>::set(int i, const T& e) // O(1)
    {
        bool ret = (0 <= i) && (i < m_length);

        if(ret)
        {
            m_array[i] = e;
        }

        return ret;
    }

    template <typename T>
    bool SeqList<T>::get(int i, T& e) const // O(1)
    {
        bool ret = (0 <= i) && (i < m_length);

        if(ret)
        {
            e = m_array[i];
        }

        return ret;
    }

    template <typename T>
    int SeqList<T>::length() const  // O(1)
    {
        return m_length;
    }

    template <typename T>
    void SeqList<T>::clear()
    {
        m_length = 0;   // 清空意味着线性表中没有任何元素，故线性表的长度为0
    }

    template <typename T>
    T& SeqList<T>::operator[](int i)    // O(1)
    {
        if( (0 <= i) && (i < m_length) )
        {
            return m_array[i];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "the index of array is invalid...");
        }
    }

    template <typename T>
    T SeqList<T>::operator[](int i) const   // O(1)
    {
        // 为了代码复用，此处可以调用 T& SeqList<T>::operator[](int i)函数实现
        // 在const成员函数中调用 非const成员函数的思路：去除当前对象的只读属性
        return ( const_cast< SeqList<T>& >(*this) )[i];
    }
}

#endif // SEQLIST_H
