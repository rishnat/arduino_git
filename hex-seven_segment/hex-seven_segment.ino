/*A hexadecimal seven segment display*/
/*Description:Will display value from 0 to F with a delay of 500ms*/
/*Tested on Arduino Uno*/


/*constant table for values to be displayed*/
const int disp[16]={63,6,91,79,102,109,125,7,127,111,119,124,88,94,121,113};
unsigned int i;

void setup() {

/*configuring pin 2 to 8 as output (If you have a BCD to 7-segment decoder then only four pins are required)*/

for(i=2;i<=8;i++)
{
pinMode(i,OUTPUT);
}
}

void loop() {
unsigned int temp,rem;
unsigned int j;
for(i=0;i<16;i++)
{
  temp=disp[i];
  for(j=2;j<=8;j++)
  {
    rem=temp%2;
    temp=temp/2;
    digitalWrite(j,rem);
    
  }
  delay(500); /*delay of 500ms between adjacent values*/
}


}
