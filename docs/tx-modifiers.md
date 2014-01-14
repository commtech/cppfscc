# TX Modifiers

| Modifiers | Value | Description
| -------- | ------ | -----------
| `XF`     | `0`    | Normal transmit (disable modifiers)
| `XREP`   | `1`    | Transmit frame repeatedly
| `TXT`    | `2`    | Transmit frame on timer
| `TXEXT`  | `4`    | Transmit frame on external signal

###### Support
| Code           | Version
| -------------- | --------
| `fscc-windows` | `v2.0.0` 
| `fscc-linux`   | `v2.0.0` 
| `cppfscc`      | `v1.0.0`


## Get
```c++
unsigned GetTxModifiers(void) throw();
```

###### Examples
```c++
#include <fscc.hpp>
...

unsigned modifiers;

modifiers = p.GetTxModifiers();
```


## Set
```c++
void SetTxModifiers(unsigned modifiers) throw();
```

| Parameter   | Type           | Description
| ------------| -------------- | ----------------------------
| `modifiers` | `unsigned int` | The modifiers values to set

###### Examples
```c++
#include <fscc.hpp>
...

p.SetTxModifiers(Fscc::TXT | Fscc::XREP);
```


### Additional Resources
- Complete example: [`examples\tx-modifiers.cpp`](https://github.com/commtech/cppfscc/blob/master/examples/tx-modifiers.cpp)
- Implemenation details: [`src\fscc.cpp`](https://github.com/commtech/cppfscc/blob/master/src/fscc.cpp)
