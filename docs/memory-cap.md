# Memory Cap
If your system has limited memory available, there are safety checks in place to 
prevent spurious incoming data from overrunning your system. Each port has an 
option for setting it's input and output memory cap.


###### Driver Support
| Code           | Version
| -------------- | --------
| `fscc-windows` | `v2.0.0` 
| `fscc-linux`   | `v2.0.0` 


## Structure
```c
struct fscc_memory_cap {
    int input;
    int output;
};
```


## Macros
```c
FSCC_MEMORY_CAP_INIT(memcap)
```

| Parameter   | Type                       | Description
| ----------- | -------------------------- | --------------------------------------
| `memcap`    | `struct fscc_memory_cap *` | The memory cap structure to initialize

The `FSCC_MEMORY_CAP_INIT` macro should be called each time you use the 
`struct fscc_memory_cap` structure. An initialized structure will allow you to 
only set/receive the memory cap you need.


## Get
```c
struct fscc_memory_cap GetMemoryCap(void) throw(SystemException)
```

###### Examples
```
#include <fscc.hpp>
...

struct fscc_memory_cap memcap;

FSCC_MEMORY_CAP_INIT(memcap);

memcap = p.GetMemoryCap();
```

At this point `memcap.input` and `memcap.output` would be set to their respective
values.

###### Support
| Code           | Version
| -------------- | --------
| `cfscc`        | `v1.0.0`


## Set
```c
void SetMemoryCap(const struct fscc_memory_cap &memcap) throw(SystemException)
```

###### Examples
```
#include <fscc.hpp>
...

struct fscc_memory_cap memcap;

FSCC_MEMORY_CAP_INIT(memcap);

memcap.input = 1000000; /* 1 MB */
memcap.output = 2000000; /* 2 MB */

p.SetMemoryCap(memcap);
```

###### Support
| Code           | Version
| -------------- | --------
| `cfscc`        | `v1.0.0`


### Additional Resources
- Complete example: [`examples\memory-cap.cpp`](https://github.com/commtech/cppfscc/blob/master/examples/memory-cap/memory-cap.cpp)
- Implemenation details: [`src\fscc.cpp`](https://github.com/commtech/cppfscc/blob/master/src/fscc.cpp)
