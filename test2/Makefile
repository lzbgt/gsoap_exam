CC=g++
CFLAGS+=

LIBS=-lpthread -lgsoap++

%.o: %.c soapH.h soapStub.h soapService.h
	$(CC) -c -o $@ $< $(CFLAGS)

#ws_calc: $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
all: soapcpp2 ws_calc
ws_calc: ws_calc.cpp soapC.cpp  soapcalcService.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean wsdl2h soapcpp2 gitpush

clean:
	mkdir -p bak
	mv calc.h ws_calc.cpp bak
	rm -f *.o ws_calc ws_calc_m *.h *.cpp *.xml *.nsmap *.wsdl *.xsd
	mv bak/* .
	rm -fr bak

wsdl2h:
	wsdl2h calc.h

soapcpp2:
	soapcpp2 -j -S calc.h

gitpush:
	git status; git add . ;git commit -m"new"; git push