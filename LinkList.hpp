#ifndef LINKLIST_H
#define LINKLIST_H

#include "List.hpp"
#include "Exception.h"

namespace SLIB
{
    template <typename T>
    class LinkList : public List<T>
    {
    protected:
        struct Node : public Object
        {
            T value;    // 数据域
            Node* next; // 指针域
        };
        Node m_header;  // 头结点

        int m_length;   // 链表的长度
    public:
        LinkList();
        ~LinkList();
        virtual bool insert(int i, const T& e);
        virtual bool insert(const T& e);
        virtual bool remove(int i);
        virtual bool set(int i, const T& e);
        virtual bool get(int i, T& e) const;
        T get(int i) const;

        virtual int length() const;
        virtual void clear();
    };

    template<typename T>
    LinkList<T>::LinkList()
    {
        m_header.next = 0;
        m_length = 0;
    }

    template<typename T>
    bool LinkList<T>::insert(int i, const T& e)
    {
        bool ret = (0 <= i) && (i <= m_length);

        if(ret)
        {
            Node *node = new Node();

            if(node)
            {
                Node* current = &m_header;

                // 循环结束，current 从头结点 移动到 第（i-1）个结点，有效结点从第 0 个结点开始
                for(int pos = 0; pos < i; pos++)
                {
                    current = current->next;    // 移动到下一个结点
                }

                node->value = e;
                node->next = current->next;
                current->next = node;

                m_length++;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoryException, "No memory to insert new element...");
            }
        }

        return ret;
    }

    template<typename T>
    bool LinkList<T>::insert(const T& e)
    {
        return insert(m_length, e);
    }

    template<typename T>
    bool LinkList<T>::remove(int i)
    {
        bool ret = (0 <= i) && (i < m_length);

        if(ret)
        {
            Node* current = &m_header;

            for(int pos = 0; pos < i; pos++)
            {
                current = current->next;
            }

            Node* toDel = current->next;
            current->next = toDel->next;

            delete toDel;

            m_length--;
        }

        return ret;
    }

    template<typename T>
    bool LinkList<T>::set(int i, const T& e)
    {
        bool ret = (0 <= i) && (i < m_length);

        if(ret)
        {
            Node* current = &m_header;

            for(int pos = 0; pos < i; pos++)
            {
                current = current->next;
            }

            current->next->value = e;
        }

        return ret;
    }

    template<typename T>
    bool LinkList<T>::get(int i, T& e) const
    {
        bool ret = (0 <= i) && (i < m_length);

        if(ret)
        {
            Node* current = const_cast<Node*>(&m_header);

            for(int pos = 0; pos < i; pos++)
            {
                current = current->next;
            }

            e = current->next->value;
        }

        return ret;
    }

    template<typename T>
    T LinkList<T>::get(int i) const
    {
        T ret;

        if(get(i, ret))
        {
            return ret;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException, "the target location is illegal...");
        }
    }

    template<typename T>
    int LinkList<T>::length() const
    {
        return m_length;
    }

    template<typename T>
    void LinkList<T>::clear()
    {
        while(m_header.next)
        {
            Node* toDel = m_header.next;
            m_header.next = toDel->next;
            delete toDel;
        }

        m_length = 0;
    }

    template<typename T>
    LinkList<T>:: ~LinkList()
    {
        clear();
    }
}

#endif  // LINKLIST_H
