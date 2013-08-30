# Append Timestamp

###### Driver Support
| Code           | Version
| -------------- | --------
| `fscc-windows` | `v2.4.0` 
| `fscc-linux`   | `v2.4.0` 


## Get
```c++
bool GetAppendTimestamp(void) throw(SystemException)
```

###### Examples
```c
#include <fscc.hpp>
...

bool status;

status = p.GetAppendStatus();
```

###### Support
| Code           | Version
| -------------- | --------
| `cppfscc`        | `v1.0.0`


## Enable
```c
void EnableAppendTimestamp(void) throw(SystemException)
```

###### Examples
```c
#include <fscc.hpp>
...

p.EnableAppendStatus()
```

###### Support
| Code           | Version
| -------------- | --------
| `cppfscc`        | `v1.0.0`


## Disable
```c
void EnableAppendTimestamp(void) throw(SystemException)
```

###### Examples
```c
#include <fscc.hpp>
...

p.DisableAppendStatus()
```

###### Support
| Code           | Version
| -------------- | --------
| `cppfscc`        | `v1.0.0`


### Additional Resources
- Complete example: [`examples\append-timestamp.c`](https://github.com/commtech/cppfscc/blob/master/examples/append-timestamp/append-timestamp.c)
- Implemenation details: [`src\fscc.c`](https://github.com/commtech/cppfscc/blob/master/src/fscc.cpp)
