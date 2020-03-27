#ifndef LIST_H
#define LIST_H

#include "Object.h"

namespace SLIB
{
    template <typename T>
    class List : public Object
    {
    protected:
        List(const List&);              // 禁用拷贝构造函数
        List& operator=(const List& l); // 禁用赋值操作函数
    public:
        List(){}
        virtual bool insert(int i, const T& e) = 0;
        virtual bool insert(const T& e) = 0;    // 在线性表的末尾插入元素
        virtual bool remove(int i) = 0;
        virtual bool set(int i, const T& e) = 0;
        virtual bool get(int i, T& e) const = 0;
        virtual int length() const = 0;
        virtual void clear() = 0;
    };
}

#endif // LIST_H
