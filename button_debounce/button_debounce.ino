int pushButton = 2;     //button is connected to pin 2
int ledpin=8;           //led is connected to pin 8(you can change to pin 13 for onboard led)

/*Initialization*/
boolean ledstate=LOW;   
int laststate=0;
int currentstate=0;


void setup() {
  /*setting the configuration for pin direction*/
  pinMode(pushButton, INPUT);
  pinMode(ledpin,OUTPUT);
}

/*Debounce function*/
int debounce(int last)
{
int current=digitalRead(pushButton);

if(current!=last)
{
  delay(10);   //delay can be adjusted but is usually around 5-10ms
  current=digitalRead(pushButton);  
}

return current;  
}


void loop() {

currentstate=debounce(laststate);

if(laststate==0&&currentstate==1)
{
  ledstate=!ledstate;
}

laststate=currentstate;
digitalWrite(ledpin,ledstate);
}
  

