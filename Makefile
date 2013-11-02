CC=g++
CFLAGS+=

LIBS=-lpthread -lgsoap++

%.o: %.c soapH.h soapStub.h
	$(CC) -c -o $@ $< $(CFLAGS)

#ws_calc: $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
all: ws_calc ws_calc_m
ws_calc: ws_calc.cpp soapC.cpp soapServer.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

ws_calc_m: ws_calc_m.cpp soapC.cpp soapServer.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean wsdl2h soapcpp2 gitpush

clean:
	rm -f *.o ws_calc ws_calc_m

wsdl2h:
	wsdl2h calc.h

soapcpp2:
	soapcpp2 calc.h

gitpush:
	git add .
	git commit -m"new"
	git push