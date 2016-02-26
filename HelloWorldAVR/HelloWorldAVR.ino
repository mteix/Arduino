#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRD |= 1 << PINB3;
  while (1)
  {
    PORTD ^= 1 << PIND5;  //Dig 2 to 4
    PORTD ^= 1 << PIND3;
    PORTD ^= 1 << PIND4;
    _delay_ms(1000);
  }
}
