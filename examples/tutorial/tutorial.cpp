#include <iostream> /* cout, endl */
#include <cstdlib> /* EXIT_SUCCESS, EXIT_FAILURE */
#include <fscc.hpp> /* fscc_connect, fscc_disconnect, fscc_handle
                       fscc_write, fscc_read */

int main(void)
{
	char idata[20] = {0};

    FSCC::Port p(0);

	/* Send "Hello world!" text */
	p.Write("Hello world!");

	/* Read the data back in (with our loopback connector) */
	p.Read(idata, sizeof(idata));

	std::cout << idata << std::endl;

	return EXIT_SUCCESS;

}
