# FSCC C++ Library (cppfscc)
This README file is best viewed [online](http://github.com/commtech/cppfscc/).

## Installing Library

##### Downloading Library
- You can use the pre-built library files that are included with the driver
- Or, you can download the latest library version from
[Github releases](https://github.com/commtech/cppfscc/releases).


## Quick Start Guide

Lets get started with a quick programming example for fun.

_This tutorial has already been set up for you at_ [`examples/tutorial.cpp`](examples/tutorial.cpp).

First, drop `cppfscc.dll`, `cppfscc.lib` and `cfscc.dll` into a test directory. Now that those files are copied over, create a new C++ file (named tutorial.cpp) with the following code.

```c++
#include <iostream> /* cout, endl */
#include <cstdlib> /* EXIT_SUCCESS, EXIT_FAILURE */
#include <fscc.hpp> /* fscc_connect, fscc_disconnect, fscc_handle
                       fscc_write, fscc_read */

int main(void)
{
    Fscc::Port p(0);

    // Send "Hello world!" text
    p.Write("Hello world!");

    // Read the data back in (with our loopback connector)
    std::cout << p.Read() << std::endl;

    return EXIT_SUCCESS;
}
```

For this example I will use the Visual Studio command line compiler, but you can use your compiler of choice.

```
# cl /EHsc tutorial.cpp cppfscc.lib /I <CPPFSCC_DIR>\src
```

Now attach the included loopback connector.

```
# tutorial.exe
Hello world!
```

You have now transmitted and received an HDLC frame!


## API Reference

There are likely other configuration options you will need to set up for your own program. All of these options are described on their respective documentation page.

- [Connect](docs/connect.md)
- [Append Status](docs/append-status.md)
- [Append Timestamp](docs/append-timestamp.md)
- [Clock Frequency](docs/clock-frequency.md)
- [Ignore Timeout](docs/ignore-timeout.md)
- [Memory Cap](docs/memory-cap.md)
- [Purge](docs/purge.md)
- [Read](docs/read.md)
- [Registers](docs/registers.md)
- [RX Multiple](docs/rx-multiple.md)
- [Track Interrupts](docs/track-interrupts.md)
- [TX Modifiers](docs/tx-modifiers.md)
- [Write](docs/write.md)


## Build Dependencies
- C++ compiler (G++ & Visual Studio tested)
- [cfscc](https://github.com/commtech/cfscc/) (Included)


## Run-time Dependencies
- OS: Windows XP+ & Linux


## API Compatibility
We follow [Semantic Versioning](http://semver.org/) when creating releases.


## License

Copyright (C) 2014 [Commtech, Inc.](http://commtech-fastcom.com)

Licensed under the [GNU General Public License v3](http://www.gnu.org/licenses/gpl.txt).
