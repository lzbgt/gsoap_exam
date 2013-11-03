CC=g++
CFLAGS+=

LIBS=-lpthread -lgsoap++

%.o: %.c soapH.h soapStub.h
	$(CC) -c -o $@ $< $(CFLAGS)

#ws_calc: $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
all: soapcpp2 ws_calc ws_calc_m
ws_calc: ws_calc.cpp soapC.cpp soapServer.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

ws_calc_m: ws_calc_m.cpp soapC.cpp soapServer.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean wsdl2h soapcpp2 gitpush

clean:
	mkdir -p bak
	mv calc.h ws_calc.cpp ws_calc_m.cpp bak
	rm -f *.o ws_calc ws_calc_m *.h *.cpp *.xml *.nsmap *.wsdl *.xsd
	mv bak/* .
	rm -fr bak

wsdl2h:
	wsdl2h calc.h

soapcpp2:
	soapcpp2 calc.h

gitpush:
	git status; git add . ;git commit -m"new"; git push