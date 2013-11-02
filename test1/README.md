Test project for gsoap

Steps:
Generate files by

\# soapcpp2 calc.h

Complile server app: ws_calc.cpp

\# g++ -DDEBUG ws_calc.cpp soapC.cpp soapServer.cpp -o ws_calc -lgsoap++

\# g++ -DDEBUG ws_calc_m.cpp soapC.cpp soapServer.cpp -o ws_calc -lgsoap++ -lpthread

NOTE: -lgsoap++ for g++, -lgsoap for gcc

Use SoapUI tools to test it.

\# sudo ./ws_calc 8088

