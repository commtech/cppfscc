#include <cstdlib> /* EXIT_SUCCESS */
#include <fscc.hpp> /* Fscc::Port */

int main(void)
{
	Fscc::Port p(0);

	// Enable transmit repeat & transmit on timer */
    p.SetTxModifiers(Fscc::TxModifiers::TXT | Fscc::TxModifiers::XREP);

	// Enable transmit repeat & transmit on timer */
    p.SetTxModifiers(Fscc::TxModifiers::XF);

    unsigned modifiers = p.GetTxModifiers();

	return EXIT_SUCCESS;
}