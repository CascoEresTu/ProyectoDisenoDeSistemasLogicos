void setup()
{
  DDRD = 255;
}
 
void loop()


{
  int x;
  int y;

x= B11111111;
y=B00000000;
  PORTD = x; /
  delay(1000);
  PORTD = y; 
  delay(1000);

Uno=B00000001;


for(int segundos=0; segundos<10; segundos++){
  segundos=segundos++;
if (segundos=9)
{
  segundos=0;
}}
}