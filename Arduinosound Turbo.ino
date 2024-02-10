static uint8_t samp = 0x80;

void setup() 
{
  DDRD = B11111111;
  DDRB = B0000;

  ADMUX  = B01100011;
  ADCSRA = B11111011;
}

ISR (ADC_vect) 
{
  while ((PINB & B0001))  samp = ADCH;                     
  while (!(PINB & B0001)) PORTD = samp;                 
}

void loop() {}
