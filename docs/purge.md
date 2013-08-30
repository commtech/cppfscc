# Purge
Between the hardware FIFO and the driver's software buffers there are multiple places data could 
be stored, excluding your application code. If you ever need to clear this data and start fresh, 
there are a couple of methods you can use.

###### Driver Support
| Code           | Version
| -------------- | --------
| `fscc-windows` | `v2.0.0` 
| `fscc-linux`   | `v2.0.0` 


## Execute
```c++
void Purge(bool tx, bool rx) throw(SystemException);
```

###### Examples
Purge both the transmit and receive data.
```c++
#include <fscc.hpp>
...

p.Purge(true, true);
```

Purge only the transmit data.
```c++
#include <fscc.hpp>
...

p.Purge(true, false);
```

Purge only the receive data.
```c++
#include <fscc.hpp>
...

p.Purge(false, true);
```

###### Support
| Code      | Version
| --------- | --------
| `cppfscc` | `v1.0.0`


### Additional Resources
- Complete example: [`examples\purge.cpp`](https://github.com/commtech/cppfscc/blob/master/examples/purge.cpp)
- Implemenation details: [`src\fscc.cpp`](https://github.com/commtech/cppfscc/blob/master/src/fscc.cpp)
