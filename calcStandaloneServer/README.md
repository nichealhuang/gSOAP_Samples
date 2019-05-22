# gSOAP_Samples/calcStandaloneServer
A gSOAP calc standalone server
[Original Link](https://www.genivia.com/examples/calc++/index.html)

# gSOAP Commands to generate code files from wsdl
```
wsdl2h -o calc.h calc.wsdl
```

```
soapcpp2 -j -SL -I \path\to\gsoap\gsoap_2.8.83\gsoap-2.8\gsoap\import calc.h
```

# Service Endpoint
When started, the service will listen on http://localhost:8088 via SOAP 1.1 and no WS-Addressing.
