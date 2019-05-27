#include "soapWSHttpBinding_USCOREICalculatorService.h"
#include "soapwstService.h"
#include "wst.nsmap"

int port = 8088;

int main()
{
	WSHttpBinding_USCOREICalculatorService myService;
  myService.soap->send_timeout = myService.soap->recv_timeout = 5; // 5 sec socket idle timeout
  myService.soap->transfer_timeout = 30;                         // 30 sec message transfer timeout
  while (myService.run(port))
    myService.soap_stream_fault(std::cerr);
  myService.destroy();
  return 0;
}

/* service operation function */
int WSHttpBinding_USCOREICalculatorService::Add(_tns__Add *tns__Add, _tns__AddResponse &tns__AddResponse)
{
	double a = *(tns__Add->n1);
	double b = *(tns__Add->n2);
	tns__AddResponse.AddResult = new double();
	*(tns__AddResponse.AddResult) = a + b;
	return SOAP_OK;
}

/* service operation function */
int WSHttpBinding_USCOREICalculatorService::Subtract(_tns__Subtract *tns__Subtract, _tns__SubtractResponse &tns__SubtractResponse)
{
	double a = *(tns__Subtract->n1);
	double b = *(tns__Subtract->n2);
	tns__SubtractResponse.SubtractResult = new double();
	*(tns__SubtractResponse.SubtractResult) = a - b;
	return SOAP_OK;
} 
/* service operation function */
int WSHttpBinding_USCOREICalculatorService::Multiply(_tns__Multiply *tns__Multiply, _tns__MultiplyResponse &tns__MultiplyResponse)
{
	double a = *(tns__Multiply->n1);
	double b = *(tns__Multiply->n2);
	tns__MultiplyResponse.MultiplyResult = new double();
	*(tns__MultiplyResponse.MultiplyResult) = a + b;
	return SOAP_OK;
} 
/* service operation function */
int WSHttpBinding_USCOREICalculatorService::Divide(_tns__Divide *tns__Divide, _tns__DivideResponse &tns__DivideResponse)
{
	double a = *(tns__Divide->n1);
	double b = *(tns__Divide->n2);
	if (b) {
		tns__DivideResponse.DivideResult = new double();
		*(tns__DivideResponse.DivideResult) = a / b;
	}
	else
		return soap_senderfault("Division by zero", NULL);
	return SOAP_OK;
}

int wstService::RequestSecurityToken(struct wst__RequestSecurityTokenType *wst__RequestSecurityToken, struct wst__RequestSecurityTokenResponseType *wst__RequestSecurityTokenResponse) {
	return SOAP_OK;
}

int wstService::RequestSecurityTokenResponse(struct wst__RequestSecurityTokenResponseType *wst__RequestSecurityTokenResponse, struct wst__RequestSecurityTokenResponseCollectionType *wst__RequestSecurityTokenResponseCollection) {
	return SOAP_OK;
}

int wstService::RequestSecurityTokenCollection(struct wst__RequestSecurityTokenCollectionType *wst__RequestSecurityTokenCollection, struct wst__RequestSecurityTokenResponseCollectionType *wst__RequestSecurityTokenResponseCollection) {
	return SOAP_OK;
}