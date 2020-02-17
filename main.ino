
int strobePin  = 7;    // Strobe Pin on the MSGEQ7
int resetPin   = 8;    // Reset Pin on the MSGEQ7
int outPin     = A1;   // Output Pin on the MSGEQ7
int level[7];    

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
 
  // Define our pin modes
  pinMode      (strobePin, OUTPUT);
  pinMode      (resetPin,  OUTPUT);
  pinMode      (outPin,    INPUT);
 
  // Create an initial state for our pins
  digitalWrite (resetPin,  LOW);
  digitalWrite (strobePin, LOW);
  delay        (1);
 
  // Reset the MSGEQ7 as per the datasheet timing diagram
  digitalWrite (resetPin,  HIGH);
  delay        (1);
  digitalWrite (resetPin,  LOW);
  digitalWrite (strobePin, HIGH); 
  delay        (1);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Cycle through each frequency band by pulsing the strobe.
  for (int i = 0; i < 7; i++) {
    digitalWrite       (strobePin, LOW);
    delayMicroseconds  (100);                  // Delay necessary due to timing diagram
    level[i] =         analogRead (outPin);
    digitalWrite       (strobePin, HIGH);
    delayMicroseconds  (1);                    // Delay necessary due to timing diagram  
  }
 
  for (int i = 0; i < 7; i++) {
    Serial.print       (level[i]);
    Serial.print       ("   ");
  }
 
  Serial.println (); 
}
