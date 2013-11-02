#include "soapH.h" /* get the gSOAP-generated definitions */
#include "calc.nsmap" /* get the gSOAP-generated namespace bindings */
#include <math.h>  
int main(int argc, char*argv[])  
{ 
  int m, s; /* master and slave sockets */
  struct soap *soap = soap_new();
  if (argc < 2)
    soap_serve(soap); /* serve as CGI application */
  else
  { 
    m = soap_bind(soap, NULL, atoi(argv[1]), 100); /* bind to the port supplied as command-line argument */
    if (m < 0)
    { soap_print_fault(soap, stderr);
      exit(-1);
    }
    fprintf(stderr, "Socket connection successful: master socket = %d\n", m);
    for (;;)
    { 
      s = soap_accept(soap);
      fprintf(stderr, "Socket connection successful: slave socket = %d\n", s);
      if (s < 0)
      { soap_print_fault(soap, stderr);
        exit(1);
      } 
      soap_serve(soap);
      soap_end(soap);
    }
  }
  soap_done(soap);
  free(soap);
  return 0;
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

int ns__sqrt(struct soap *soap, double a, double *result)  
{ 
  if (a >= 0)  
  { 
    *result = sqrt(a);  
    return SOAP_OK;  
  }  
  else 
    return soap_sender_fault(soap, "Square root of negative value", "I can only take the square root of non-negative values");    
}
