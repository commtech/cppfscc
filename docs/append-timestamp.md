# Append Timestamp

###### Driver Support
| Code           | Version
| -------------- | --------
| `fscc-windows` | `v2.4.0` 
| `fscc-linux`   | `v2.4.0` 


## Get
```c++
bool GetAppendTimestamp(void) throw(SystemException);
```

###### Examples
```c++
#include <fscc.hpp>
...

bool status;

status = p.GetAppendStatus();
```

###### Support
| Code      | Version
| --------- | --------
| `cppfscc` | `v1.0.0`


## Enable
```c++
void EnableAppendTimestamp(void) throw(SystemException);
```

###### Examples
```c++
#include <fscc.hpp>
...

p.EnableAppendStatus()
```

###### Support
| Code      | Version
| --------- | --------
| `cppfscc` | `v1.0.0`


## Disable
```c++
void EnableAppendTimestamp(void) throw(SystemException);
```

###### Examples
```c++
#include <fscc.hpp>
...

p.DisableAppendStatus()
```

###### Support
| Code      | Version
| --------- | --------
| `cppfscc` | `v1.0.0`


### Additional Resources
- Complete example: [`examples\append-timestamp.cpp`](https://github.com/commtech/cppfscc/blob/master/examples/append-timestamp/append-timestamp.cpp)
- Implemenation details: [`src\fscc.cpp`](https://github.com/commtech/cppfscc/blob/master/src/fscc.cpp)
