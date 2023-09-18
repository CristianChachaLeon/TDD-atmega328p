#include "unity_fixture.h"

#ifdef ATMEGA_328P                                                  
#include <avr/io.h>                                                 
#endif

#ifdef ATMEGA_328P
static int uart_putchar(char c, FILE *stream);
static FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL,_FDEV_SETUP_WRITE);                                                                                                                                                                                         
static int uart_putchar(char c, FILE *stream)
{                                                                                                                                                                                                                          
	if (c == '\n')
		uart_putchar('\r', stream);
	loop_until_bit_is_set(UCSR0A, UDRE0); 
    UDR0 = c;                                                                                                                                                                                                                                                                   return 0;                                                                                                                                                                                                                                                                     
}                                                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                                  
void init_uart()                                                    
{                                                                   
    // Operation mode Async                                         
    UCSR0C &= ~(1 << UMSEL00);                                      
    UCSR0C &= ~(1 << UMSEL01);                                      
                                                                    
    // Not parity                                                   
    UCSR0C &= ~(1 << UPM00);                                        
    UCSR0C &= ~(1 << UPM01);                                        
                                                                    
    // One stop bit                                                 
    UCSR0C &= ~(1 << USBS0);                                        
                                                                    
    // Frame 8bits                                                  
    UCSR0C |= (1 << UCSZ00);                                        
    UCSR0C |= (1 << UCSZ01);                                        
    UCSR0B &= ~(1 << UCSZ02);                                       
                                                                    
    // Double speed                                                 
    UCSR0A |= (1 << U2X0);                                          
    // Baudrate                                                     
    UBRR0 = (F_CPU / 8 / 115200) - 1;                               
                                                                    
    // Enable TX Y RX                                               
    UCSR0B |= (1 << TXEN0);                                         
    UCSR0B |= (1 << RXEN0);                                         
}                                                                   
                                                                    
#endif 

static void RunAllTests(void)
{
	RUN_TEST_GROUP(led);

}


int main(int argc, const char* argv[])
{
	#ifdef ATMEGA_328P
	init_uart();
	stdout = &uart_output;
	printf("cross compilation-test in atmega328p\n");
	argc = 2;   //accept 2 argument (./Test -v)
	argv[1] = "-v"; // add log  like argument to ./Test
	#endif
	return UnityMain(argc, argv, RunAllTests);
}

