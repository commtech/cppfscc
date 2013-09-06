# Memory Cap
If your system has limited memory available, there are safety checks in place to 
prevent spurious incoming data from overrunning your system. Each port has an 
option for setting it's input and output memory cap.


###### Driver Support
| Code           | Version
| -------------- | --------
| `fscc-windows` | `v2.0.0` 
| `fscc-linux`   | `v2.0.0` 
| `cppfscc`      | `v1.0.0`


## Structure
```c++
struct MemoryCap {
    int input;
    int output;
};
```


## Get
```c++
MemoryCap GetMemoryCap(void) throw(SystemException);
```

###### Examples
```c++
#include <fscc.hpp>
...

memcap = p.GetMemoryCap();
```

At this point `memcap.input` and `memcap.output` would be set to their respective
values.


## Set
```c++
void SetMemoryCap(const MemoryCap &memcap) throw(SystemException);
```

###### Examples
```c++
#include <fscc.hpp>
...

MemoryCap memcap;

memcap.input = 1000000; // 1 MB
memcap.output = 2000000; // 2 MB

p.SetMemoryCap(memcap);
```


### Additional Resources
- Complete example: [`examples\memory-cap.cpp`](https://github.com/commtech/cppfscc/blob/master/examples/memory-cap.cpp)
- Implemenation details: [`src\fscc.cpp`](https://github.com/commtech/cppfscc/blob/master/src/fscc.cpp)
