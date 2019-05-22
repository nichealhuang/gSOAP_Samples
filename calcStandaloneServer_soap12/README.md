# gSOAP_Samples/calcStandaloneServer
A gSOAP calc standalone server in C++ language 

# WSDL incl. SOAP 1.2 
calc-soap12.wsdl
According to [gSOAP guide](https://www.genivia.com/doc/guide/html/index.html#switching), if the wsdl includes SOAP 1.2 namespace, the commands will auto switch the generated code for us.

# gSOAP Commands to generate code files from wsdl
```
wsdl2h -o calc.h calc-soap12.wsdl
```

The following custom build command is assigned to calc.h so every time it compiles, it will regenerate all stub files.
```
soapcpp2 -j -SL -I \path\to\gsoap\gsoap_2.8.83\gsoap-2.8\gsoap\import calc.h
```

# Service Endpoint
When started, the service will listen on http://localhost:8088 via SOAP 1.2.
You can use fiddler to verify the request and response.
