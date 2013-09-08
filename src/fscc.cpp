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

#include <cstdio>

#include <fscc.h>

#include "fscc.hpp"

namespace Fscc {

/// <param name="port_num">Used to indicate status.</param>
Port::Port(unsigned port_num)
{
    init(port_num, true);
}

Port::~Port(void)
{
    cleanup();
}

void Port::init(unsigned port_num, bool overlapped, HANDLE h)
{
    _port_num = port_num;
    _overlapped = overlapped;
    _h = h;
} 

void Port::init(unsigned port_num, bool overlapped)
{
    _port_num = port_num;
    _overlapped = overlapped;

    int e = fscc_connect(port_num, overlapped, &_h);

    switch (e) {
    case ERROR_SUCCESS:
        break;

    case ERROR_FILE_NOT_FOUND:
        throw PortNotFoundException(port_num);

    case ERROR_ACCESS_DENIED:
        throw InsufficientPermissionsException();

    default:
        throw SystemException(e);
    }
} 

void Port::cleanup(void)
{
    int e = fscc_disconnect(_h);

    if (e)
        throw SystemException(e);
} 

Port::Port(const Port &other)
{
    init(other._port_num, other._overlapped);
}

Port& Port::operator=(const Port &other)
{
    if (this != &other) {
        HANDLE h2;
        int e = fscc_connect(other._port_num, other._overlapped, &h2);

        if (e) {
            throw SystemException(e);
        }
        else {
            cleanup();
            init(other._port_num, other._overlapped, h2);
        }
    }

    return *this;
}

int Port::Write(const char *buf, unsigned size, OVERLAPPED *o)
{
    unsigned bytes_written = 0;

    int e = fscc_write(_h, (char *)buf, size, &bytes_written, o);

    if (e >= 1 && e != 997)
        throw SystemException(e);

    return e;
}

unsigned Port::Write(const char *buf, unsigned size) 
{
    OVERLAPPED o;
    DWORD bytes_written = 0;

    memset(&o, 0, sizeof(o));

    Write(buf, size, &o);

    GetOverlappedResult(_h, &o, &bytes_written, true);

    return bytes_written;
}

unsigned Port::Write(const std::string &s)
{
    return Write(s.c_str(), s.length());
}

int Port::Read(char *buf, unsigned size, OVERLAPPED *o)
{
    unsigned bytes_read;

    int e = fscc_read(_h, buf, size, &bytes_read, o);

    if (e >= 1 && e != 997)
        throw SystemException(e);

    return bytes_read;
}

unsigned Port::Read(char *buf, unsigned size)
{
    OVERLAPPED o;
    DWORD bytes_read = 0;

    Read(buf, size, (OVERLAPPED *)0);

    GetOverlappedResult(_h, &o, &bytes_read, true);

    return bytes_read;
}

unsigned Port::Read(char *buf, unsigned size, unsigned timeout)
{
    unsigned bytes_read;

    int e = fscc_read_with_timeout(_h, buf, size, &bytes_read, timeout);

    if (e >= 1)
        throw SystemException(e);

    return bytes_read;
}

unsigned Port::GetTxModifiers(void) throw(SystemException)
{
    unsigned modifiers;

    int e = fscc_get_tx_modifiers(_h, &modifiers);

    if (e)
        throw SystemException(e);

    return modifiers;
}

void Port::SetTxModifiers(unsigned modifiers)
{
    int e = fscc_set_tx_modifiers(_h, modifiers);

    if (e)
        throw SystemException(e);
}

void Port::SetMemoryCap(const MemoryCap &memcap) throw(SystemException)
{
    struct fscc_memory_cap m;

    memcpy(&m, &memcap, sizeof(m));

    int e = fscc_set_memory_cap(_h, &m);

    if (e)
        throw SystemException(e);
}

MemoryCap Port::GetMemoryCap(void) throw(SystemException)
{
    struct MemoryCap memcap;

    int e = fscc_get_memory_cap(_h, (struct fscc_memory_cap *)&memcap);

    if (e)
        throw SystemException(e);

    return memcap;
}

void Port::SetRegisters(const Registers &regs) throw(SystemException)
{
    struct fscc_registers r;

    memcpy(&r, &regs, sizeof(r));

    int e = fscc_set_registers(_h, &r);

    if (e)
        throw SystemException(e);
}

Registers Port::GetRegisters(const Registers &regs) throw(SystemException)
{
    int e = fscc_get_registers(_h, (struct fscc_registers *)&regs);

    if (e)
        throw SystemException(e);

    return regs;
}

void Port::SetClockFrequency(unsigned frequency) throw(SystemException)
{
    int e = fscc_set_clock_frequency(_h, frequency);

    if (e)
        throw SystemException(e);
}

bool Port::GetAppendStatus(void) throw(SystemException)
{
    unsigned status;

    int e = fscc_get_append_status(_h, &status);

    if (e)
        throw SystemException(e);

    return status != 0;
}

void Port::EnableAppendStatus(void) throw(SystemException)
{
    int e = fscc_enable_append_status(_h);

    if (e)
        throw SystemException(e);
}

void Port::DisableAppendStatus(void) throw(SystemException)
{
    int e = fscc_disable_append_status(_h);

    if (e)
        throw SystemException(e);
}

bool Port::GetAppendTimestamp(void) throw(SystemException)
{
    unsigned status;

    int e = fscc_get_append_timestamp(_h, &status);

    if (e)
        throw SystemException(e);

    return status != 0;
}

void Port::EnableAppendTimestamp(void) throw(SystemException)
{
    int e = fscc_enable_append_timestamp(_h);

    if (e)
        throw SystemException(e);
}

void Port::DisableAppendTimestamp(void) throw(SystemException)
{
    int e = fscc_disable_append_timestamp(_h);

    if (e)
        throw SystemException(e);
}

bool Port::GetIgnoreTimeout(void) throw(SystemException)
{
    unsigned status;

    int e = fscc_get_ignore_timeout(_h, &status);

    if (e)
        throw SystemException(e);

    return status != 0;
}

void Port::EnableIgnoreTimeout(void) throw(SystemException)
{
    int e = fscc_enable_ignore_timeout(_h);

    if (e)
        throw SystemException(e);
}

void Port::DisableIgnoreTimeout(void) throw(SystemException)
{
    int e = fscc_disable_ignore_timeout(_h);

    if (e)
        throw SystemException(e);
}

bool Port::GetRxMultiple(void) throw(SystemException)
{
    unsigned status;

    int e = fscc_get_rx_multiple(_h, &status);

    if (e)
        throw SystemException(e);

    return status != 0;
}

void Port::EnableRxMultiple(void) throw(SystemException)
{
    int e = fscc_enable_rx_multiple(_h);

    if (e)
        throw SystemException(e);
}

void Port::DisableRxMultiple(void) throw(SystemException)
{
    int e = fscc_disable_rx_multiple(_h);

    if (e)
        throw SystemException(e);
}

void Port::Purge(bool tx, bool rx) throw(SystemException)
{
    int e = fscc_purge(_h, tx, rx);

    if (e)
        throw SystemException(e);
}

Registers::Registers()
{
    Reset();
}

void Registers::Reset(void)
{
    FIFOT = -1;

    CMDR = -1;
    STAR = -1; /* Read-only */
    CCR0 = -1;
    CCR1 = -1;
    CCR2 = -1;
    BGR = -1;
    SSR = -1;
    SMR = -1;
    TSR = -1;
    TMR = -1;
    RAR = -1;
    RAMR = -1;
    PPR = -1;
    TCR = -1;
    VSTR = -1;

    IMR = -1;
    DPLLR = -1;

    /* BAR 2 */
    FCR = -1;
}

MemoryCap::MemoryCap()
{
    Reset();
}

void MemoryCap::Reset(void)
{
    input = -1;
    output = -1;
}

} /* namespace FSCC */