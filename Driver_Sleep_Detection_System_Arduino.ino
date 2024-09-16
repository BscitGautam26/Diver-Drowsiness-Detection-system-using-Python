
const int buzzer_Pin = 8;
const int led_Pin = 9;
const int dcmotor_Pin = 10;
char sleep_status = 0;

void setup() {
  Serial.begin(9600);  
  pinMode(buzzer_Pin, OUTPUT);
  pinMode(led_Pin, OUTPUT);
  pinMode(dcmotor_Pin, OUTPUT);
  
  digitalWrite(buzzer_Pin, LOW); 
  digitalWrite(led_Pin, LOW);
  digitalWrite(dcmotor_Pin, HIGH);
}
void loop() 
{
    while (Serial.available() > 0) 
  {
    sleep_status = Serial.read();
    if(sleep_status == 'a')
    { 
        digitalWrite(buzzer_Pin, HIGH); 
        digitalWrite(led_Pin, HIGH);
        digitalWrite(dcmotor_Pin, LOW); 
        delay(2000);

        digitalWrite(buzzer_Pin, LOW); 
        digitalWrite(led_Pin, LOW);
        digitalWrite(dcmotor_Pin, LOW); 
        delay(100);
    }
    else if(sleep_status == 'b')
    {
        digitalWrite(buzzer_Pin, LOW); 
        digitalWrite(led_Pin, LOW);
        digitalWrite(dcmotor_Pin, HIGH);
        delay(2000);
    }
    else
    {
      /* Do Nothing */
    }
  }
}
