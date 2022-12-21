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

int count=0;

void IN()
{
    	count++;
	_delay_ms(500);
}
void OUT()
{
  	count--;
	_delay_ms(500);
}


int main ()
{
	DDRF |= (1 << OUTPUT);
	DDRB |= (1 << WHITE_I) | (1 << BLUE_I) | (1 << GREEN_I);
	DDRF &= ~((1 << WHITE_P) | (1 << BLUE_P) | (1 << GREEN_P));
	PORTF |= (1 << WHITE_P) | (1 << BLUE_P) | (1 << GREEN_P);
	PORTB |= (1 << WHITE_I); // Включаем белый излучатель
	PORTB |= (1 << GREEN_I); // Включаем зеленый излучатель
	// Главный цикл работы МК
	while (1)
	{
		
		if ((PINF & (1 << WHITE_P)) == 0){
			_delay_ms(100);
			if ( PINF & ( 1 << GREEN_P)) == 0{
				IN();
			}
		}
		if ((PINF & (1 << GREEN_P)) == 0){
			_delay_ms(100);
			if ( PINF & ( 1 << WHITE_P)) == 0{
				OUT();
			}
		}
			
	}
}
