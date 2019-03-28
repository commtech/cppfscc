/*
Copyright 2019 Commtech, Inc.

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software and associated documentation files (the "Software"), to deal 
in the Software without restriction, including without limitation the rights 
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in 
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
THE SOFTWARE.
*/

#ifndef SYSEXEPTION_HPP
#define SYSEXEPTION_HPP

#include <stdexcept>

namespace Fscc {

class SystemException : public std::runtime_error
{
public:
    SystemException(const std::string& error_msg = "");

    unsigned error_code(void) const throw();

private:
    unsigned _error_code;
};

class PortNotFoundException : public SystemException
{
public:
    PortNotFoundException(unsigned port_num);
};

class InvalidAccessException : public SystemException
{
public:
    InvalidAccessException(void);
};

class TimeoutException : public SystemException
{
public:
    TimeoutException(void);
};

class BufferTooSmallException : public SystemException
{
public:
    BufferTooSmallException(void);
};

class IncorrectModeException : public SystemException
{
public:
    IncorrectModeException(void);
};

class InvalidParameterException : public SystemException
{
public:
    InvalidParameterException(void);
};

} /* namespace Fscc */

#endif
