int pinA = 24;
int pinB = 25;
int pinC = 26;
int pinD = 27;
int pinE = 28;
int pinF = 29;
int pinG = 30;
int pinp=31;
int C1 = 22;
int C2 = 23;

void setup() {                

  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(C1, OUTPUT);  
  pinMode(C2, OUTPUT);  
pinMode(pinp, OUTPUT);  }
void loop() {
  digitalWrite(C1,HIGH);
  digitalWrite(C2, HIGH);
    digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);
  digitalWrite(pinp, HIGH);   
  delay(1000);              
   digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
  digitalWrite(pinp, LOW);   
  delay(1000);      
}