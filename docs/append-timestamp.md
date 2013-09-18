# Append Timestamp

###### Support
| Code           | Version
| -------------- | --------
| `fscc-windows` | `v2.4.0` 
| `fscc-linux`   | `v2.4.0` 
| `cppfscc`      | `v1.0.0`


## Get
```c++
bool GetAppendTimestamp(void) throw();
```

###### Examples
```c++
#include <fscc.hpp>
...

bool status;

status = p.GetAppendStatus();
```


## Enable
```c++
void EnableAppendTimestamp(void) throw();
```

###### Examples
```c++
#include <fscc.hpp>
...

p.EnableAppendStatus()
```


## Disable
```c++
void EnableAppendTimestamp(void) throw();
```

###### Examples
```c++
#include <fscc.hpp>
...

p.DisableAppendStatus()
```


### Additional Resources
- Complete example: [`examples\append-timestamp.cpp`](https://github.com/commtech/cppfscc/blob/master/examples/append-timestamp.cpp)
- Implemenation details: [`src\fscc.cpp`](https://github.com/commtech/cppfscc/blob/master/src/fscc.cpp)
