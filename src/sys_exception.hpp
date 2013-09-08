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

#ifndef SYSEXEPTION_HPP
#define SYSEXEPTION_HPP

#include <stdexcept>

class SystemException : public std::runtime_error
{
public:
        SystemException(unsigned error_code, const std::string& error_msg = ""); //TODO throw(?)

        unsigned error_code(void) const throw();

private:
        unsigned _error_code;
};

class PortNotFoundException : public SystemException
{
public:
        PortNotFoundException(unsigned port_num); //TODO throw(?)

        unsigned port_num(void) const throw();

private:
        unsigned _port_num;
};

class InsufficientPermissionsException : public SystemException
{
public:
        InsufficientPermissionsException(void); //TODO throw(?)
};

#endif