#define F_CPU 16000000UL // Директива установки частоты процессора
#include <avr/io.h> // Библиотека для работы с портами ввода-вывода
#include <util/delay.h> // Библиотека для работы с паузой

#define WHITE_P PE0 // Приемник Белый
#define BLUE_P PE1// Приемник Синий
#define GREEN_P PE2 // Приемник Зеленый

#define WHITE_I PB6 // Излучатель Белый
#define BLUE_I PB5 // Излучатель Синий
#define GREEN_I PB0 // Излучатель Зеленый

int count = 0;

// функция прибавления объектов
void IN() { 
	if(count < 10) {
		count++;
	}
}

// функция убавления объектов
void OUT() {
	if(count > 0) {
		count--;
	}
}


int main () {
    DDRB |= (1 << WHITE_I) | (1 << BLUE_I) | (1 << GREEN_I);
    DDRE &= ~((1 << WHITE_P) | (1 << BLUE_P) | (1 << GREEN_P));
    PORTE |= ((1 << WHITE_P) | (1 << BLUE_P) | (1 << GREEN_P));
    PORTB |= (1 << WHITE_I); // Включаем белый излучатель
    PORTB |= (1 << GREEN_I); // Включаем зеленый излучатель
    DDRF = 0b11111111;
    
    _delay_ms(500);
    TCNT1 = 0; // таймер 
    TCCR1B = 0b00000100; // настройка предделителя
    int a[] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000}; //массив цифр
    PORTF = a[0];
    // Главный цикл работы МК
    while (1) {
		if ((PINE & (1 << GREEN_P)) == 0) {
			TCNT1 = 0;
			while (TCNT1 <= 30000){
				if((PINE & (1 << WHITE_P)) == 0){
					IN();
					PORTF = a[count];
					break;
				}
			}
			
		}
		if ((PINE & (1 << WHITE_P)) == 0) {
			TCNT1 = 0;
			while (TCNT1 <= 30000){
				if((PINE & (1 << GREEN_P)) == 0){
					OUT();
					PORTF = a[count];
					break;
				}
			}
		}
	}
                
}
