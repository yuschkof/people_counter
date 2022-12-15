#define F_CPU 16000000UL // Директива установки частоты процессора
#include <avr/io.h>		 // Библиотека для работы с портами ввода-вывода
#include <util/delay.h>	 // Библиотека для работы с паузой

#define WHITE_P PF1 // Приемник Белый
#define BLUE_P PF2 // Приемник Синий
#define GREEN_P PF3 // Приемник Зеленый

#define WHITE_I PB6 // Излучатель Белый
#define BLUE_I PB5 // Излучатель Синий
#define GREEN_I PB0 // Излучатель Зеленый

#define OUTPUT PF4 // Вывод 1


int main ()
{
	DDRF |= (1 << OUTPUT);
	DDRB |= (1 << WHITE_I) | (1 << BLUE_I) | (1 << GREEN_I);
	DDRF &= ~((1 << WHITE_P) | (1 << BLUE_P) | (1 << GREEN_P));
	PORTF |= (1 << WHITE_P) | (1 << BLUE_P) | (1 << GREEN_P);
	PORTB |= (1 << PB6);
	PORTB |= (1 << PB0);
	// Главный цикл работы МК
	while (1)
	{
		
		if ((PINF & (1 << PF1)) == 0){
			PORTB |=  (1 << PB5);
			PORTB &= ~(1 << PB0);
			PORTB &= ~(1 << PB6);
			if ( PINF & ( 1 << PF2)) == 0{
				count++;
			PORTF |= (1 << PF4);
			}
		}
		else {
			PORTB |= (1 << PB6);
			PORTF &= ~(1 << PF4);
			PORTB |= (1 << PB0);
			PORTB &= ~(1 << PB5);
		}
			
	}
}
