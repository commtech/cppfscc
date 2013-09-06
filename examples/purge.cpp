#include <cstdlib> /* EXIT_SUCCESS */
#include <fscc.hpp> /* Fscc::Port */

int main(void)
{
	Fscc::Port p(0);

	/* Purge TX */
	p.Purge(true, false);

	/* Purge RX */
	p.Purge(false, true);

	/* Purge both TX & RX */
	p.Purge(true, true);

	return EXIT_SUCCESS;
}
