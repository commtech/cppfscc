/*
    Copyright (C) 2013 Commtech, Inc.

    This file is part of cppfscc.

    cppfscc is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    cppfscc is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with cppfscc.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <Windows.h>

#include <fscc.h>

#include "sys_exception.hpp"

namespace Fscc {

SystemException::SystemException(unsigned error_code, const std::string& error_msg) : _error_code(error_code), std::runtime_error(error_msg)
{
}

unsigned SystemException::error_code(void) const throw()
{
    return _error_code;
}

//TODO: Portable
PortNotFoundException::PortNotFoundException(unsigned port_num) : _port_num(port_num), SystemException(ERROR_FILE_NOT_FOUND, "Port not found")
{
}

unsigned PortNotFoundException::port_num(void) const throw()
{
    return _port_num;
}


TimeoutException::TimeoutException(void) : SystemException(FSCC_TIMEOUT, "Port timed out")
{
}


BufferTooSmallException::BufferTooSmallException(void) : SystemException(FSCC_BUFFER_TOO_SMALL, "Buffer too small")
{
}

} /* namespace FSCC */