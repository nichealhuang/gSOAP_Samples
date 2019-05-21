# gSOAP_Samples/calcClient101
The official client sample console application demostrating gSOAP
[Original Link](https://www.genivia.com/examples/calc++/index.html)

# gSOAP Commands to generate code files from wsdl
```
wsdl2h -o calc.h calc.wsdl
```

```
soapcpp2 -j -CL -I \path\to\gsoap\gsoap_2.8.83\gsoap-2.8\gsoap\import calc.h
```

# Service Endpoint
This client will call the remote service at http://websrv.cs.fsu.edu/~engelen/calcserver.cgi via SOAP 1.1 and no WS-Addressing.

# Caution
Default calcclient.cpp code from original link won't be able to successuflly get the result from the server.
However, after adding gSOAP Wininet plugin, it works fine.