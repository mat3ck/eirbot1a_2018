#define MODE  PA5
#define BOB9  PORTB
#define BOB18 PA1
#define BOT   PA6
#define DECL  PA4
#define LED   PA0


byte count = 0;
long temp = 0;
byte state = 0b0;
byte test_count = 1;

void led(int t);

void setup() {
  // initialize Timer1
  cli();         // disable global interrupts
  TCCR1A = 0;    // set entire TCCR1A register to 0
  TCCR1B = 0;    // set entire TCCR1A register to 0

  // enable Timer1 overflow interrupt:
  bitSet(TIMSK1, TOIE1);

  TCNT1 = 0;

  // set 1024 prescaler
  bitSet(TCCR1B, CS12);
  bitSet(TCCR1B, CS10);

  sei(); // enable all interrupts
  
  pinMode(MODE, INPUT_PULLUP);
  pinMode(DECL, INPUT);
  pinMode(BOT, INPUT);
  pinMode(BOB18, OUTPUT);
  pinMode(LED, OUTPUT);
  DDRB = 1;
  BOB9 = 0;
  digitalWrite(BOB18,LOW);
  digitalWrite(LED, LOW);
  temp = millis();
  delay(1000);
}

ISR(TIM1_OVF_vect) {      // interrupt overflow routine
  // preload timer
  TCNT1 = 0;
  if(test_count ==0)
    count++;
}

void loop() {
  main_prog();
  delay(10);
  
}

void main_prog(){
  if(digitalRead(BOT) == HIGH){
    digitalWrite(BOB18,HIGH);
    BOB9 = 1;
    if(digitalRead(MODE) == LOW){
      led(5000);
    }
    else if(digitalRead(MODE) == HIGH){
      led(500);
      if(digitalRead(DECL)==LOW && test_count){
        TCNT1 = 50000;
        test_count = 0;
      }
      while(count >= 13){
        count = 30;
        digitalWrite(LED,HIGH);
        digitalWrite(BOB18,LOW);
        BOB9 = 0;
        delay(1000);
      }
    }
  }else{
    digitalWrite(BOB18,LOW);
    BOB9 = 0;
    led(100);
  }
}

void led(int t){
  if(millis() >= temp + t){
    state = ~state;
    temp = millis();
  }
  digitalWrite(LED,state);
}

