#include "gsoapWinInet.h"
#include "soapcalcProxy.h"
#include "calc.nsmap"
#include "stdafx.h"

/* the Web service endpoint URL */
const char server[] = "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi";

int main(int argc, char **argv)
{
	if (argc < 4)
	{
		fprintf(stderr, "Usage: [add|sub|mul|div|pow] num num\n");
		exit(1);
	}
	calcProxy calc(server);
	soap_register_plugin(calc.soap, wininet_plugin);
	calc.soap->recv_timeout = 60;

	double a, b, result;
	a = strtod(argv[2], NULL);
	b = strtod(argv[3], NULL);
	int ret = 0;
	switch (*argv[1])
	{
	case 'a':
		std::cout << a << " + " << b;
		ret = calc.add(a, b, result);		
		break;
	case 's':
		std::cout << a << " - " << b;
		ret = calc.sub(a, b, result);
		break;
	case 'm':
		std::cout << a << " * " << b;
		calc.mul(a, b, result);
		break;
	case 'd':
		std::cout << a << " / " << b;
		calc.div(a, b, result);
		break;
	case 'p':
		std::cout << a << " ^ " << b;
		calc.pow(a, b, result);
		break;
	default:
		fprintf(stderr, "Unknown command\n");
		exit(1);
	}
	if (calc.soap->error)
		calc.soap_stream_fault(std::cerr);
	else
		std::cout << " = " << result << std::endl;
	calc.destroy(); /* clean up */
	getchar();
	return 0;
}