#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include "SeqList.hpp"
#include "Exception.h"

namespace SLIB
{
    template<typename T>
    class DynamicList : public SeqList<T>
    {
    protected:
        int m_capacity;     // 线性存储空间的容量
    public:
        DynamicList(int capacity);  //申请空间
        virtual int capacity() const;

        void resize(const int capacity);  // 动态设置顺序存储空间的大小，要考虑函数异常安全性问题
        ~DynamicList(); // 归还空间
    };

    template<typename T>
    DynamicList<T>::DynamicList(int capacity)   // O(1)
    {
        this->m_array = new T[capacity];

        if(this->m_array != 0)
        {
            m_capacity = capacity;
            this->m_length = 0;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoryException, "To create DynamicList object results in NULL pointer exception...");
        }
    }

    template<typename T>
    int DynamicList<T>::capacity() const    // O(1)
    {
        return m_capacity;
    }

    template<typename T>
    void DynamicList<T>::resize(const int capacity) // // O(min(m_length, capacity)) => // O(n)
    {
        if(capacity != m_capacity)
        {
            T* array = new T[capacity];

            if(array != 0)
            {
                int length = this->m_length < capacity ? this->m_length : capacity;    // 要尽量保证重置前的数据不丢失，length 为重置后线性表的长度

                for(int i = 0; i < length; i++)
                {
                    array[i] = this->m_array[i];
                }

                // 定义指针变量 temp 完全是为了异常安全性考虑，这样可以保证完成某些必要操作，避免在 delete 的时候抛出异常
                T* temp = this->m_array;

                this->m_array = array;
                this->m_length = length;
                m_capacity = capacity;

                delete [] temp;
            }
            else
            {
                THROW_EXCEPTION(NullPointerException, "To resize DynamicList object results in NULL pointer exception...");
            }
        }
    }

    template<typename T>
    DynamicList<T>::~DynamicList()  // O(1)
    {
        delete [] this->m_array;
    }
}

#endif  // DYNAMICLIST_H
