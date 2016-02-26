#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  int i = 0;
  DDRD |= 1 << PIND2;
  while (1)
  {
    PORTD ^= 1 << PIND2;
    _delay_ms(1000);
    PORTD &= ~(1 << PIND2);
    _delay_ms(1000);



  }
}
