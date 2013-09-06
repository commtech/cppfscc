#include <cstdlib> /* EXIT_SUCCESS */
#include <fscc.hpp> /* Fscc::Port */

int main(void)
{
	Fscc::Port p(0);
    
	p.SetClockFrequency(1000000);

	return EXIT_SUCCESS;
}
