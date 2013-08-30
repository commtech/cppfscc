# RX Multiple

###### Driver Support
| Code           | Version
| -------------- | --------
| `fscc-windows` | `v2.2.9` 
| `fscc-linux`   | `v2.2.4` 


## Get
```c++
bool GetRxMultiple(void) throw(SystemException);
```

###### Examples
```c++
#include <fscc.hpp>
...

bool status;

status = p.GetRxMultiple();
```

###### Support
| Code      | Version
| --------- | --------
| `cppfscc` | `v1.0.0`


## Enable
```c++
void EnableRxMultiple(void) throw(SystemException);
```

###### Examples
```c++
#include <fscc.hpp>
...

p.EnableRxMultiple();
```

###### Support
| Code      | Version
| --------- | --------
| `cppfscc` | `v1.0.0`


## Disable
```c++
void DisableRxMultiple(void) throw(SystemException);
```

###### Examples
```c++
#include <fscc.hpp>
...

p.DisableRxMultiple();
```

###### Support
| Code      | Version
| --------- | --------
| `cppfscc` | `v1.0.0`


### Additional Resources
- Complete example: [`examples\rx-multiple.cpp`](https://github.com/commtech/cppfscc/blob/master/examples/rx-multiple.cpp)
- Implemenation details: [`src\fscc.cpp`](https://github.com/commtech/cppfscc/blob/master/src/fscc.cpp)
