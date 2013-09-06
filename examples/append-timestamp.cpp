#include <cstdlib> /* EXIT_SUCCESS */
#include <fscc.hpp> /* Fscc::Port */

int main(void)
{
	Fscc::Port p(0);

    bool status = p.GetAppendTimestamp();
    
	p.EnableAppendTimestamp();
	p.DisableAppendTimestamp();

	return EXIT_SUCCESS;
}
