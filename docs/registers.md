# Registers

The FSCC driver is a swiss army knife of sorts with communication. It can
handle many different situations, if configured correctly. Typically to
configure it to handle your specific situation you need to modify the card's
register values.

_For a complete listing of all of the configuration options please see the 
manual._

In HDLC mode some settings are fixed at certain values. If you are in
HDLC mode and after setting/getting your registers some bits don't look correct,
then they are likely fixed. A complete list of the fixed values can be found in 
the CCR0 section of the manual.

All of the registers, except FCR, are tied to a single port. FCR on the other hand 
is shared between two ports on a card. You can differentiate between which FCR 
settings affects what port by the A/B labels. A for port 0 and B for port 1.

You should purge the data stream after changing the registers.
Settings like CCR0 will require being purged for the changes to take 
effect.

###### Driver Support
| Code           | Version
| -------------- | --------
| `fscc-windows` | `v2.0.0` 
| `fscc-linux`   | `v2.0.0` 
| `cppfscc`      | `v1.0.0`


## Structure
```c++
struct Registers {
    /* BAR 0 */
    fscc_register reserved1[2];

    fscc_register FIFOT;

    fscc_register reserved2[2];

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

    fscc_register reserved3[1];

    fscc_register IMR;
    fscc_register DPLLR;

    /* BAR 2 */
    fscc_register FCR;
};
```


## Set
```c++
void SetRegisters(const Registers &r) throw(SystemException);
```

###### Examples
```c++
#include <fscc.hpp>
...

Fscc::Registers r;

r.CCR0 = 0x0011201c;
r.BGR = 10;

p.SetRegisters(r);
```


## Get
```c++
Registers GetRegisters(const Registers &r) throw(SystemException);
```

###### Examples
```c++
#include <fscc.hpp>
...

Registers r;

r.CCR1 = FSCC_UPDATE_VALUE;
r.CCR2 = FSCC_UPDATE_VALUE;

r = p.GetRegisters(r);
```

At this point `r.CCR1` and `r.CCR2` would be set to their respective
values.


### Additional Resources
- Complete example: [`examples\registers.cpp`](https://github.com/commtech/cppfscc/blob/master/examples/registers.cpp)
- Implemenation details: [`src\fscc.cpp`](https://github.com/commtech/cppfscc/blob/master/src/fscc.cpp)
