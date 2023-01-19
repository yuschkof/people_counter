#define F_CPU 16000000UL // Директива установки частоты процессора
#include <avr/io.h>		 // Библиотека для работы с портами ввода-вывода
#include <util/delay.h>	 // Библиотека для работы с паузой

#define WHITE_P PE0 // Приемник Белый
#define BLUE_P PE1// Приемник Синий
#define GREEN_P PE2 // Приемник Зеленый

#define WHITE_I PB6 // Излучатель Белый
#define BLUE_I PB5 // Излучатель Синий
#define GREEN_I PB0 // Излучатель Зеленый

int count=0;


void IN() {
    count++;
    /*PORTB |= (1 << WHITE_I);
	PORTB &= ~(1 << BLUE_I);
	PORTB |= (1 << GREEN_I);*/
}
void OUT() {
	if(count > 0) {
		count--;
	}
	/*PORTB |= (1 << GREEN_I);
	PORTB &= ~(1 << BLUE_I);
	PORTB |= (1 << WHITE_I);*/
}



int main () {
    DDRB |= (1 << WHITE_I) | (1 << BLUE_I) | (1 << GREEN_I);
    DDRE &= ~((1 << WHITE_P) | (1 << BLUE_P) | (1 << GREEN_P));
    PORTE |= ((1 << WHITE_P) | (1 << BLUE_P) | (1 << GREEN_P));
    PORTB |= (1 << WHITE_I); // Включаем белый излучатель
    PORTB |= (1 << GREEN_I); // Включаем зеленый излучатель
    DDRF = 0b11111111;
    // Главный цикл работы МК
    _delay_ms(500);
    int a[] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000}; //массив цифр от 0 до 9
    while (1) {

        /*if ((PIND & (1 << WHITE_P)) == 0) {
			PORTB &= ~(1 << WHITE_I);
            PORTB |= (1 << BLUE_I);
            PORTB &= ~(1 << GREEN_I);
            start = GetLocalTime(&st);
            while (GetLocalTime(&st) - start < 5){
				if ((PIND & (1 << BLUE_P)) == 0) {
					IN();
					p++;
					break;
				}
			}
			
			if (p == 0){
				PORTB |= (1 << WHITE_I);
				PORTB &= ~(1 << BLUE_I);
				PORTB |= (1 << GREEN_I);
			}
			p = 0;
		}
		
		if ((PIND & (1 << GREEN_P)) == 0) {
			PORTB &= ~(1 << GREEN_I);
			PORTB &= ~(1 << WHITE_I);
			PORTB |= (1 << BLUE_I);
			start = time();
           	while (time() - start < 5){
				if ((PIND & (1 << BLUE_P)) == 0) {
					OUT();
					p++;
					break;
				}
			}
			
			if (p == 0){
				PORTB |= (1 << GREEN_I);
				PORTB &= ~(1 << BLUE_I);
				PORTB |= (1 << WHITE_I);
			}
			p = 0;
		}*/
		if (count >= 0 && count < 10) {
			PORTF = a[count];
		}	
		
		if ((PINE & (1 << GREEN_P)) == 0) {
			IN();
			_delay_ms(500);
		}
		else if ((PINE & (1 << WHITE_P)) == 0) {
			OUT();
			_delay_ms(500);
		}
	}     
}
