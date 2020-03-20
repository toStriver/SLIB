#ifndef EXECPTION_H
#define EXECPTION_H

#include "Object.h"

namespace SLIB
{
    #define THROW_EXCEPTION(eType, eInfo) (throw eType(eInfo, __FILE__, __LINE__))

    class Exception : public Object
    {
    private:
        char *m_message;
        char *m_location;
    private:
        void init(const char* message, const char* file, int line);
    public:
        Exception(const char* message);
        Exception(const char* file, int line);
        Exception(const char* message, const char* file, int line);
        Exception(const Exception& e);              // 深拷贝实现
        Exception& operator=(const Exception& e);   // 深拷贝实现
        virtual const char* message() const;        // 异常的具体信息
        virtual const char* location() const;       // 异常的位置信息，如文件、行号
        virtual ~Exception() = 0;
    };

    class ArithmeticException : public Exception
    {
    public:
        ArithmeticException() : Exception(0){};
        ArithmeticException(const char* message) : Exception(message){};
        ArithmeticException(const char* file, int line) : Exception(file, line){};
        ArithmeticException(const char* message, const char* file, int line) : Exception(message, file, line){};
        ArithmeticException(const ArithmeticException& e) : Exception(e){};
        ArithmeticException& operator=(const ArithmeticException& e)
        {
            Exception::operator=(e);

            return *this;
        }
    };

    class NullPointerException : public Exception
    {
    public:
        NullPointerException() : Exception(0){};
        NullPointerException(const char* message) : Exception(message){};
        NullPointerException(const char* file, int line) : Exception(file, line){};
        NullPointerException(const char* message, const char* file, int line) : Exception(message, file, line){};
        NullPointerException(const NullPointerException& e) : Exception(e){};
        NullPointerException& operator=(const NullPointerException& e)
        {
            Exception::operator=(e);

            return *this;
        }
    };

    class IndexOutOfBoundsException : public Exception
    {
    public:
        IndexOutOfBoundsException() : Exception(0){};
        IndexOutOfBoundsException(const char* message) : Exception(message){};
        IndexOutOfBoundsException(const char* file, int line) : Exception(file, line){};
        IndexOutOfBoundsException(const char* message, const char* file, int line) : Exception(message, file, line){};
        IndexOutOfBoundsException(const IndexOutOfBoundsException& e) : Exception(e){};
        IndexOutOfBoundsException& operator=(const IndexOutOfBoundsException& e)
        {
            Exception::operator=(e);

            return *this;
        }
    };

    class NoEnoughMemoryException : public Exception
    {
    public:
        NoEnoughMemoryException() : Exception(0){};
        NoEnoughMemoryException(const char* message) : Exception(message){};
        NoEnoughMemoryException(const char* file, int line) : Exception(file, line){};
        NoEnoughMemoryException(const char* message, const char* file, int line) : Exception(message, file, line){};
        NoEnoughMemoryException(const NoEnoughMemoryException& e) : Exception(e){};
        NoEnoughMemoryException& operator=(const NoEnoughMemoryException& e)
        {
            Exception::operator=(e);

            return *this;
        }
    };

    class InvalidParameterException : public Exception
    {
    public:
        InvalidParameterException() : Exception(0){};
        InvalidParameterException(const char* message) : Exception(message){};
        InvalidParameterException(const char* file, int line) : Exception(file, line){};
        InvalidParameterException(const char* message, const char* file, int line) : Exception(message, file, line){};
        InvalidParameterException(const InvalidParameterException& e) : Exception(e){};
        InvalidParameterException& operator=(const InvalidParameterException& e)
        {
            Exception::operator=(e);

            return *this;
        }
    };

    class InvalidOperationException : public Exception
    {
    public:
        InvalidOperationException() : Exception(0){};
        InvalidOperationException(const char* message) : Exception(message){};
        InvalidOperationException(const char* file, int line) : Exception(file, line){};
        InvalidOperationException(const char* message, const char* file, int line) : Exception(message, file, line){};
        InvalidOperationException(const InvalidOperationException& e) : Exception(e){};
        InvalidOperationException& operator=(const InvalidOperationException& e)
        {
            Exception::operator=(e);

            return *this;
        }
    };
}

#endif