#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "Array.hpp"
#include "Exception.h"

namespace SLIB
{
    template <typename T>
    class DynamicArray : public Array<T>
    {
    protected:
        int m_length;
    protected:
        void init(T* array, int len);           // 对象构造时的初始化操作
        T* copy(T* array, int len, int newLen); // 在堆空间申请新的内存，并将数组 array 中 min(len, newLen) 个数据拷贝到新的内存中
        void update(T* array, int len);         // 将指定的堆空间作为内部存储数组使用
    public:
        DynamicArray(int length);
        DynamicArray(const DynamicArray<T>& e);
        DynamicArray<T>& operator=(const DynamicArray<T>& e);
        void resize(int length);    // 动态重置数组的长度
        int length() const;
        ~DynamicArray();
    };

    template <typename T>
    /**
     * @brief DynamicArray<T>::init 对象构造时的初始化操作
     * @param array 指向一个输入数组
     * @param len   输入数组的长度
     */
    void DynamicArray<T>::init(T* array, int len)   // O(1)
    {
        if(array)
        {
            this->m_array = array;
            this->m_length = len;
        }
        else
        {
            THROW_EXCEPTION(NullPointerException, "Failure to create dynamic object...");
        }
    }

    template <typename T>
    /**
     * @brief DynamicArray<T>::copy 在堆空间申请新的内存，并将数组 array 中 min(len, newLen) 个数据拷贝到新的内存中
     * @param array     输入数组
     * @param len       输入数组的长度
     * @param newLen    新数组的长度
     * @return          指向一个新数组
     */
    T* DynamicArray<T>::copy(T* array, int len, int newLen) // O(min(len, newLen)) => O(n)
    {
        T* ret = new T[newLen];

        if(ret)
        {
            int size = len < newLen ? len : newLen; // 进行最小数据拷贝，避免内存不足的风险

            for(int i = 0; i < size; i++)
            {
                ret[i] = array[i];
            }
        }
        else
        {
            THROW_EXCEPTION(NullPointerException, "Failure to finish copy operation...");
        }

        return ret;
    }

    template <typename T>
    /**
     * @brief DynamicArray<T>::update   将指定的堆空间作为内部存储数组使用
     * @param array 输入数组
     * @param len   输入数组的长度
     */
    void DynamicArray<T>::update(T* array, int len) // O(1)
    {
        if(array)
        {
           T* temp = this->m_array; // 这样操作可以保证函数异常安全

           this->m_array = array;
           this->m_length = len;

           delete [] temp;
        }
        else
        {
            THROW_EXCEPTION(NullPointerException, "Failure to finish update operation...");
        }
    }

    template <typename T>
    DynamicArray<T>::DynamicArray(int length)   // O(1)
    {
        #if 0
        this->m_array = new T[length];

        if(this->m_array != 0)
        {
            this->m_length = length;
        }
        else
        {
            THROW_EXCEPTION(NullPointerException, "Failure to create dynamic object...");
        }
        #endif

        init(new T[length], length);
    }

    template <typename T>
    DynamicArray<T>::DynamicArray(const DynamicArray<T>& e) // O(n)
    {
        #if 0
        this->m_array = new T[e.m_length];

        if(this->m_array != 0)
        {
            for(int i = 0; i < e.m_length; i++)
            {
                this->m_array[i] = e[i];
            }
            this->m_length = e.m_length;
        }
        else
        {
            THROW_EXCEPTION(NullPointerException, "Failure to create dynamic object...");
        }
        #endif

        init(copy(e.m_array, e.m_length, e.m_length), e.m_length);
    }

    template <typename T>
    DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& e)   // O(n)
    {
        #if 0
        if(this != &e)
        {
            /**
             * @brief
             * 函数异常安全概念：1、不泄露任何资源    2、不允许破坏数据
             * 函数异常安全的基本保证：如果异常被抛出，对象内的任何成员仍然能保持有效状态，没有数据的破坏及资源泄漏
             */
            T* array = new T[e.m_length];

            if(array != 0)
            {
                for(int i = 0; i < e.m_length; i++)
                {
                    array[i] = e.m_array[i];
                }

                T* temp = this->m_array;
                this->m_array = array;
                this->m_length = e.m_length;

                delete [] temp;
            }
            else
            {
                THROW_EXCEPTION(NullPointerException, "Failure to finish copy operation...");
            }
        }
        #endif

        if(this != &e)
        {
            /**
             * @brief update 先设置一个数组，然后将该数组设置到相关的成员变量上
             */
            update(copy(e.m_array, e.m_length, e.m_length), e.m_length);
        }

        return *this;
    }

    template <typename T>
    void DynamicArray<T>::resize(int length)    // O(n)
    {
        #if 0
        if(m_length != length)
        {
            T* array = new T[length];

            if(array != 0)
            {
                int size = this->m_length < length ? this->m_length : length;

                for(int i = 0; i < size; i++)
                {
                    array[i] = this->m_array[i];
                }

                T* temp = this->m_array;
                this->m_array = array;
                this->m_length = length;

                delete [] temp;
            }
            else
            {
                THROW_EXCEPTION(NullPointerException, "Failure to finish resize operation...");
            }
        }
        #endif

        if(m_length != length)
        {
            update(copy(this->m_array, m_length, length), length);
        }
    }

    template <typename T>
    int DynamicArray<T>::length() const // O(1)
    {
        return m_length;
    }

    template <typename T>
    DynamicArray<T>::~DynamicArray()    // O(1)
    {
        delete [] this->m_array;
    }
}

#endif  // DYNAMICARRAY_H
