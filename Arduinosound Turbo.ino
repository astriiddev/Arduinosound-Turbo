int8_t samp = 0x80;                 //sets initial sample output to 0db

void setup() {

  DDRD = B11111111;                 // sets pins D0-D7 as outputs
  DDRB = B0000;                     // sets pins D8-D11 as inputs

  ADMUX = B01100011;                // voltage reference = 5V | Left adjusted result | Input from A3
  ADCSRA = B11111100;               // ADC on | Start conversion | set Interrupt flag | enable interrupt | Clock prescaler = 16 (1Mhz ADC clock)

}

ISR (ADC_vect) {                    //interrupt request for ADC register

  do {
    ADCSRA = B11111011;             // ADC on | Start conversion | set Interrupt flag | enable interrupt | Clock prescaler = 12 (1.33Mhz ADC clock)
    samp = ADCH;                    // save analog read data
  }
  while ((PINB & B0001) == 1);      // on HIGH pulse of sample rate clock (AMIGA strobe, pin 1)

  do{
    PORTD = samp;                   // outputs analog read data accross D0 (LSB) to D7 (MSB)
  }

  while ((PINB & B0001) == 0);      // on HIGH pulse of sample rate clock (AMIGA strobe, pin 1)
 
}

void loop() {
}
