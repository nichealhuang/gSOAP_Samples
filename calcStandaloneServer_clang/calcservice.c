#include "calc.nsmap" // XML namespace mapping table (only needed once at the global level)
#include "soapH.h"    // server stubs, serializers, etc.

int main()
{
	struct soap *soap = soap_new1(SOAP_XML_INDENT);
	if (soap_serve(soap) != SOAP_OK)
		soap_print_fault(soap, stderr);
	soap_destroy(soap); // delete managed deserialized C++ instances
	soap_end(soap);     // delete other managed data
	soap_free(soap);    // free the soap struct context data
}
int ns__add(struct soap *soap, double a, double b, double *result)
{
	*result = a + b;
	return SOAP_OK;
}
int ns__sub(struct soap *soap, double a, double b, double *result)
{
	*result = a - b;
	return SOAP_OK;
}
int ns__mul(struct soap *soap, double a, double b, double *result)
{
	*result = a * b;
	return SOAP_OK;
}
int ns__div(struct soap *soap, double a, double b, double *result)
{
	if (b == 0.0)
	{
		char *msg = (char*)soap_malloc(soap, 1024);
		snprintf(msg, 1024, "Trying to divide %f by zero", a);
		return soap_sender_fault(soap, msg, NULL);
	}
	*result = a / b;
	return SOAP_OK;
}
int ns__pow(struct soap *soap, double a, double b, double *result)
{
	*result = pow(a, b);
	// soap_errno is like errno, but compatible with Win32
	if (soap_errno == EDOM)
	{
		char *msg = (char*)soap_malloc(soap, 1024);
		snprintf(msg, 1024, "<error xmlns=\"http://tempuri.org/\">Can't take power of %f to %f</error>", a, b);
		return soap_sender_fault(soap, "Power function domain error", msg);
	}
	return SOAP_OK;
}