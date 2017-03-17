int i=0;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
 
}

void loop() { 
  Serial.print("ON");
  delay(500);
  i++;
  
}

