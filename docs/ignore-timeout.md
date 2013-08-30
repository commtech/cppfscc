# Ignore Timeout

###### Driver Support
| Code           | Version
| -------------- | --------
| `fscc-windows` | `v2.0.0` 
| `fscc-linux`   | `v2.0.0` 


## Get
```c++
bool GetIgnoreTimeout(void) throw(SystemException);
```


###### Examples
```c++
#include <fscc.hpp>
...

bool status;

status = p.GetIgnoreTimeout();
```

###### Support
| Code      | Version
| --------- | --------
| `cppfscc` | `v1.0.0`


## Enable
```c++
void EnableIgnoreTimeout(void) throw(SystemException);
```

###### Examples
```c++
#include <fscc.hpp>
...

p.EnableIgnoreTimeout()
```

###### Support
| Code      | Version
| --------- | --------
| `cppfscc` | `v1.0.0`


## Disable
```c++
void DisableIgnoreTimeout(void) throw(SystemException);
```

###### Examples
```c++
#include <fscc.hpp>
...

p.DisableIgnoreTimeout()
```

###### Support
| Code      | Version
| --------- | --------
| `cppfscc` | `v1.0.0`


### Additional Resources
- Complete example: [`examples\ignore-timeout.cpp`](https://github.com/commtech/cppfscc/blob/master/examples/ignore-timeout.cpp)
- Implemenation details: [`src\fscc.cpp`](https://github.com/commtech/cppfscc/blob/master/src/fscc.cpp)
