//-----------------
// Hello World AVR
// Blinking led
//-----------------

#define F_CPU 16000000UL // Директива установки частоты процессора

#include <avr/io.h>		 // Библиотека для работы с портами ввода-вывода
#include <util/delay.h>	 // Библиотека для работы с паузой

int main ()
{
	DDRE |= (1 << PE6);
	PORTE &= ~(1 << PE6);

	// Главный цикл работы МК
	while (1)
	{
		if (PE4 == 0){
			PORTE |=  (1 << PE5);
			PORTE &= ~(1 << PE6);
			while(PE5 == 1){
				
			}
			else(PE5 == 0){
				count++;
			}
		}

		if (PE6 == 0){
			PORTE |=  (1 << PE5);
			PORTE &= ~(1 << PE4);
			while(PE5 == 1){

			}
			else(PE5 == 0){
				count--;
			}
		}
	}
}
