
void setup() {
  // agar dapat kiirim file dari laptop ke arduino uno
  Serial.begin(9600);
  // mengatur agar pin 2 dapat mengeluarkan output
  pinMode(2, OUTPUT);
   // mengatur agar pin 3 dapat mengeluarkan output
  pinMode(3, OUTPUT); 
   // mengatur agar pin 4 dapat mengeluarkan output
  pinMode(4, OUTPUT); 
}


void loop() {
  //inisialiasiasi  variabel untuk potensiometer

  int sensorValue = analogRead(A0);
  //mencetak ke layar hasil potensiometer
  Serial.println(sensorValue);

  // Blink each LED
  //menyalakan pin 2
  digitalWrite(2, HIGH);  
  //delay 1 detik
  delay(1000);    
  //mematikan pin 2                 
  digitalWrite(2, LOW); 
   delay(1000);         
  digitalWrite(3, HIGH);  
   delay(1000);                 
  digitalWrite(3, LOW);    
   delay(1000);               
  digitalWrite(4, HIGH);            
 delay(1000);       
  digitalWrite(4, LOW);            
  delay(1000);                     
}
