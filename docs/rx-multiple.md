# RX Multiple

###### Driver Support
| Code           | Version
| -------------- | --------
| `fscc-windows` | `v2.2.9` 
| `fscc-linux`   | `v2.2.4` 


## Get
```c++
bool GetRxMultiple(void) throw(SystemException)
```

###### Examples
```c++
#include <fscc.h>
...

bool status;

status = p.GetRxMultiple();
```

###### Support
| Code           | Version
| -------------- | --------
| `cfscc`        | `v1.0.0`


## Enable
```c++
void EnableRxMultiple(void) throw(SystemException)
```

###### Examples
```c++
#include <fscc.h>
...

p.EnableRxMultiple();
```

###### Support
| Code           | Version
| -------------- | --------
| `cfscc`        | `v1.0.0`


## Disable
```c++
void DisableRxMultiple(void) throw(SystemException)
```

###### Examples
```c++
#include <fscc.h>
...

p.DisableRxMultiple();
```

###### Support
| Code           | Version
| -------------- | --------
| `cfscc`        | `v1.0.0`


### Additional Resources
- Complete example: [`examples\rx-multiple.cpp`](https://github.com/commtech/cfscc/blob/master/examples/rx-multiple/rx-multiple.cpp)
- Implemenation details: [`src\fscc.cpp`](https://github.com/commtech/cfscc/blob/master/src/fscc.cpp)
