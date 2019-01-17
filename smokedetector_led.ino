int firethres = 800;
int smokethres = 200;
void setup() {
  // put your setup code here, to run once:

pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);
Serial.begin(9600);
}

void loop() {
int smokesensor = analogRead(A0);
int firesensor = analogRead(A1);
Serial.print(smokesensor);
Serial.print("\t");
Serial.print(firesensor);
Serial.println("");
 
if (smokesensor > smokethres && firesensor > firethres)
{
  digitalWrite(12,LOW);  
  digitalWrite(13,LOW);
  for (int i = 3; i <= 10;i++)
  {
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
  }
  
}
else if (smokesensor > smokethres && firesensor < firethres)
{ 
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  tone(13,1000,500);
  delay(10);
  tone(13,2000,500);
  for (int i = 3; i <= 10;i++)
  {
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
  }

 }
else
{
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW); 
  for (int i = 3; i <= 10;i++)
  {
    digitalWrite(i,LOW);
   
  }

}
delay(100);
}
