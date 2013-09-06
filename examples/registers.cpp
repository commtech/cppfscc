#include <cstdlib> /* EXIT_SUCCESS */
#include <fscc.hpp> /* Fscc::Port */

int main(void)
{
    Fscc::Registers r;
	Fscc::Port p(0);

	r.CCR0 = 0x0011201c;
	r.BGR = 10;

    p.SetRegisters(r);
    
    r.Reset();

	/* Mark the CCR1 and CCR2 elements to retrieve values */
	r.CCR1 = Fscc::UPDATE_VALUE;
	r.CCR2 = Fscc::UPDATE_VALUE;

    r = p.GetRegisters(r);

	return EXIT_SUCCESS;
}
