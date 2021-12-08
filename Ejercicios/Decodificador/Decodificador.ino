unsigned int Sensores[] = {A0,A1,A2,A3,A4};
unsigned int Actuadores[] = {5,6,7,8,9};
int cantidad;
void setup() {
  // put your setup code here, to run once:
  pinMode(Actuadores[0],OUTPUT);
  pinMode(Actuadores[1],OUTPUT);
  pinMode(Actuadores[2],OUTPUT);
  pinMode(Actuadores[3],OUTPUT);
  pinMode(Actuadores[4],OUTPUT);

  Serial.begin(9600); //UART
  Serial.setTimeout(100);
  cantidad = 5;
}

 int valores[5];
 int dato;
 int residuo = 0;
 String resultado = "";
 String aux;
 
void loop() {

  for(int i = 0; i < cantidad ; i++)
  {
    valores[i] = analogRead(Actuadores[i]);  
  }
  
  valores[0] = 30;
  valores[1] = 40;
  valores[2] = 50;
  valores[3] = 60;
  valores[4] = 70;


  if (Serial.available() > 0) {
    dato = Serial.readString().toInt();   
    resultado = "H";
    for(int i = 0; i < cantidad ;i++)
    {
      residuo = dato%2;
      dato = dato/2;
      
      if(residuo != 0)
      {
       // aux = valores[cantidad - i -1];
        aux = valores[ i ];
        resultado = resultado + aux;
        resultado = resultado + "R";
      }
    }
    resultado = resultado;
    resultado = resultado.substring(0,resultado.length()-1) +"T";
    Serial.println(resultado); 
    
  }

}
