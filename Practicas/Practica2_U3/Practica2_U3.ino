
int x = A3; 
int y = A1;
int z = A2;
int PULSADOR = 2;


int Actuador1 = 11;
int Actuador2 = 12;
int Actuador3 = 13;

void setup() {
  pinMode(Actuador1, OUTPUT);
  pinMode(Actuador2, OUTPUT);
  pinMode(Actuador3, OUTPUT);

  Serial.begin(9600); //UART
  Serial.setTimeout(100);
}

int v1, v2, v3;
void loop() {

  v1 = analogRead(x); // X   XX  XXX   XXXX
  v2 = analogRead(y);
  v3 = analogRead(z);
  
  if(v1 >= 470 && v1<= 530 ){ v1 =0;}
  else if(v1 > 530 ){ v1 =1;}
  else { v1 =-1;}

  if(v2 >= 470 && v2<= 530 ){ v2 =0;}
  else if(v2 > 530 ){ v2 =1;}
  else { v2 =-1;}
  
  Serial.println("H" + String(v1) + "R" + String(v2) + "R" + String(v3) + "T"); //R <- 
  delay(100);
}
