# gSOAP_Samples
Samples herein are used for demostrating gSOAP on windows.

If you expect to see some working samples right away, here is the right place:)

Assume you have installed gSOAP into C:\gsoap_2.8.83\gsoap-2.8\gsoap\import. If you use a different version, change the Additional Include settings in Visual Studio accordingly.

1. a commandline client application (calcClient001 project)
2. a standalone C++ server application - SOAP 1.1 (calcStandaloneServer project)
3. a standalone C server application - SOAP 1.1 (calcStandaloneServer_clang project)
4. a standalone C++ server application - SOAP 1.2 (calcStandaloneServer_soap12 project)
5. ISAPI extension to host gSOAP service on IIS Web Servre (mod-gsoap-isapi project), e.g. POST http://localhost/gsoap/mod_gsoap.dll?calc