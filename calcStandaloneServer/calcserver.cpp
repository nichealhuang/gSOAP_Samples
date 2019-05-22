#include "soapcalcService.h"
#include "calc.nsmap"

int port = 8088;

int main()
{
  calcService myService;
  myService.soap->send_timeout = myService.soap->recv_timeout = 5; // 5 sec socket idle timeout
  myService.soap->transfer_timeout = 30;                         // 30 sec message transfer timeout
  while (myService.run(port))
    myService.soap_stream_fault(std::cerr);
  myService.destroy();
  return 0;
}

/* service operation function */
int calcService::add(double a, double b, double &result)
{
  result = a + b;
  return SOAP_OK;
} 
/* service operation function */
int calcService::sub(double a, double b, double &result)
{
  result = a - b;
  return SOAP_OK;
} 
/* service operation function */
int calcService::mul(double a, double b, double &result)
{
  result = a * b;
  return SOAP_OK;
} 
/* service operation function */
int calcService::div(double a, double b, double &result)
{
  if (b)
    result = a / b;
  else
    return soap_senderfault("Division by zero", NULL);
  return SOAP_OK;
} 
/* service operation function */
int calcService::pow(double a, double b, double &result)
{
	result = ::pow(a, b);
	if (soap_errno == EDOM)   /* soap_errno is like errno, but portable */
		return soap_senderfault("Power function domain error", NULL);
	return SOAP_OK;
}