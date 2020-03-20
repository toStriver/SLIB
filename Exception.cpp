#include "Exception.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>

namespace SLIB
{
    void Exception::init(const char* message, const char* file, int line)
    {
        m_message = message ? strdup(message) : NULL;

        if(file != NULL)
        {
            char s[16] = {0};

            //atos(line, s, 10);
            sprintf(s, "%d", line);
            m_location = static_cast<char*>( malloc(strlen(file) + strlen(s) + 2) );    // +2 -> 冒号和结束符；
            if(m_location != NULL)
            {
                strcpy(m_location, file);
                strcat(m_location, ":");
                strcat(m_location, s);
            }
            // 内存空间申请失败，最好的做法是什么也不做；若此时抛出异常，会造成死循环（在 Exceptino 类中抛出 exception 类族异常）；
        }
        else
        {
            m_location = NULL;
        }
    }

    Exception::Exception(const char* message)
    {
        init(message, NULL, 0);        
    }

    Exception::Exception(const char* file, int line)
    {
        init(NULL, file, line);
    }

    Exception::Exception(const char* message, const char* file, int line)
    {
        init(message, file, line);
    }

    Exception::Exception(const Exception& e)
    {
        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }

    Exception& Exception::operator=(const Exception& e)
    {
        if(this != &e)  // 避免自赋值操作
        {
            free(m_message);
            free(m_location);
            
            m_message = strdup(e.m_message);
            m_location = strdup(e.m_location);
        }

        return *this;
    }

    const char* Exception::message() const
    {
        return m_message;
    }

    const char* Exception::location() const
    {
        return m_location;
    }

    Exception::~Exception()
    {
        free(m_message);
        free(m_location);

        m_message = NULL;
        m_location = NULL;
    }

}