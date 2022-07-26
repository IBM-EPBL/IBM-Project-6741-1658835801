float temp;
int tempPin = 0;
int led = 13;               
int sensor = 2;             
int state = LOW;            
int val = 0;       
int  valor_limite = 650;
const int buzzer = 6;


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);      
  pinMode(sensor, INPUT); 
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
   temp = analogRead(tempPin);
   temp = temp * 0.48828125;
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); 
   Serial.print("*C");
   Serial.println();
   delay(1000); 
   Serial.println(analogRead(A1));
   if(analogRead(A1) > valor_limite){ 
    digitalWrite(8, LOW); 
    digitalWrite(7, HIGH); 
    tone(buzzer, 1200);
    delay(500);
  }
  else{ 
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW); 
    noTone(buzzer);
    delay(500);
    }
  delay (1000);
   
  val = digitalRead(sensor);  
  if (val == HIGH) {          
    digitalWrite(led, HIGH);  
    delay(500);               
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;      
    }
  } 
  else {
      digitalWrite(led, LOW); 
      delay(500);             
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;     
        
 
    }
  }
}