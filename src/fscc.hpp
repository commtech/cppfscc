/*
    Copyright (c) 2019 Commtech, Inc.

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.


*/

#ifndef FSCC_HPP
#define FSCC_HPP

#pragma warning(disable:4290)

#include <string>

#include "sys_exception.hpp"

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef _WIN32
typedef HANDLE fscc_handle;
#else
typedef int fscc_handle;
#endif

#ifndef _WIN32
typedef void OVERLAPPED;
#endif

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

namespace Fscc {
    namespace TxModifiers {
        enum { XF=0, XREP=1, TXT=2, TXEXT=4 };
    }

    struct Registers;
    struct MemoryCap;
    const int UPDATE_VALUE = -2;

    class DLL_EXPORT Port {
    public:
        Port(unsigned port_num) throw(SystemException);

        Port(const Port &other) throw(SystemException); /* Untested */
        Port& operator=(const Port &other) throw(SystemException); /* Untested */

        virtual ~Port(void);

        unsigned GetTxModifiers(void) throw();
        void SetTxModifiers(unsigned modifiers) throw();
        void SetMemoryCap(const MemoryCap &memcap) throw();
        MemoryCap GetMemoryCap(void) throw();
        void SetRegisters(const Registers &regs) throw(SystemException);
        Registers GetRegisters(const Registers &regs) throw();
        void SetClockFrequency(unsigned frequency) throw(SystemException);
        bool GetAppendStatus(void) throw();
        void EnableAppendStatus(void) throw();
        void DisableAppendStatus(void) throw();
        bool GetAppendTimestamp(void) throw();
        void EnableAppendTimestamp(void) throw();
        void DisableAppendTimestamp(void) throw();
        bool GetIgnoreTimeout(void) throw();
        void EnableIgnoreTimeout(void) throw();
        void DisableIgnoreTimeout(void) throw();
        bool GetRxMultiple(void) throw();
        void EnableRxMultiple(void) throw();
        void DisableRxMultiple(void) throw();
        void Purge(bool tx=true, bool rx=false) throw(SystemException);

        int TrackInterrupts(unsigned interrupts, unsigned *matches, OVERLAPPED *o) throw(SystemException);
        unsigned TrackInterrupts(unsigned interrupts) throw(SystemException);
        unsigned TrackInterrupts(unsigned interrupts, unsigned timeout) throw(SystemException);

        int Write(const char *buf, unsigned size, OVERLAPPED *o) throw(SystemException);
        unsigned Write(const char *buf, unsigned size) throw(SystemException);
        unsigned Write(const std::string &str) throw(SystemException);
        int Read(char *buf, unsigned size, OVERLAPPED *o) throw(SystemException);
        unsigned Read(char *buf, unsigned size) throw(SystemException);
        unsigned Read(char *buf, unsigned size, unsigned timeout) throw(SystemException);
        std::string Read(unsigned count=4096) throw(SystemException);
        std::string Read(unsigned count, unsigned timeout) throw(SystemException);

    protected:
        void init(unsigned port_num) throw(SystemException);
        void init(unsigned port_num, fscc_handle h) throw();
        void cleanup(void) throw();

    private:
        fscc_handle _h;
        unsigned _port_num;
        bool _overlapped;
    };

#ifdef _WIN32
    typedef INT64 fscc_register;
#else
    typedef int64_t fscc_register;
#endif

    struct DLL_EXPORT Registers {
        Registers(void);
        void Reset(void);

        /* BAR 0 */
        fscc_register __reserved1[2];

        fscc_register FIFOT;

        fscc_register __reserved2[2];

        fscc_register CMDR;
        fscc_register STAR; /* Read-only */
        fscc_register CCR0;
        fscc_register CCR1;
        fscc_register CCR2;
        fscc_register BGR;
        fscc_register SSR;
        fscc_register SMR;
        fscc_register TSR;
        fscc_register TMR;
        fscc_register RAR;
        fscc_register RAMR;
        fscc_register PPR;
        fscc_register TCR;
        fscc_register VSTR; /* Read-only */

        fscc_register __reserved4[1];

        fscc_register IMR;
        fscc_register DPLLR;

        /* BAR 2 */
        fscc_register FCR;
    };

    struct DLL_EXPORT MemoryCap {
        MemoryCap(void);
        void Reset(void);

        int input;
        int output;
    };

} /* namespace Fscc */

#endif
