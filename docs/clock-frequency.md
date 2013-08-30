# Clock Frequency
The FSCC device has a programmable clock that can be set anywhere from
20 KHz to 200 MHz. However, this is not the full operational range of an
FSCC port, only the range that the onboard clock can be set to.

Using one of the synchronous modes you can only receive data consistently
up to 30 MHz (when you are using an external clock). If you are transmitting
data using an internal clock, you can safely receive data consistently up to 50 MHz.

Lower clock rates (less than 1 MHz for example) can take a long time for 
the frequency generator to finish. If you run into this situation we 
recommend using a larger frequency and then dividing it down to your 
desired baud rate using the BGR register.

###### Driver Support
| Code           | Version
| -------------- | --------
| `fscc-windows` | `v2.0.0` 
| `fscc-linux`   | `v2.0.0` 


## Set
```c++
void SetClockFrequency(unsigned frequency) throw(SystemException);
```


###### Examples
Set the port's clock frequency to 18.432 MHz.
```c++
#include <fscc.hpp>
...

p.SetClockFrequency(18432000);
```

###### Support
| Code      | Version
| --------- | --------
| `cppfscc` | `v1.0.0`


### Additional Resources
- Complete example: [`examples\clock-frequency.cpp`](https://github.com/commtech/cppfscc/blob/master/examples/clock-frequency/clock-frequency.cpp)
- Implemenation details: [`src\fscc.cpp`](https://github.com/commtech/cppfscc/blob/master/src/fscc.cpp)
