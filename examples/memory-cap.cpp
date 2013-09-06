#include <cstdlib> /* EXIT_SUCCESS */
#include <fscc.hpp> /* Fscc::Port */

int main(void)
{
    Fscc::MemoryCap m;
	Fscc::Port p(0);

	m.input = 1000000; // 1 MB
	m.output = 2000000; // 2 MB

    p.SetMemoryCap(m);
    m = p.GetMemoryCap();

	return EXIT_SUCCESS;
}
