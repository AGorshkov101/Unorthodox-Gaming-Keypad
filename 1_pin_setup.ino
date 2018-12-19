void pin_setup(){

  /////// Buttons
  pinMode(selPinFw, INPUT);  
  pinMode(selPinBk, INPUT);
  pinMode(spacePin, INPUT);
  digitalWrite(selPinFw, HIGH);
  digitalWrite(selPinBk, HIGH); 
  digitalWrite(spacePin, HIGH);
   
  ////// Joystick
  pinMode(horzPin, INPUT);  
  pinMode(vertPin, INPUT);

  
  delay(500);  // short delay to let outputs settle
  vertZero = analogRead(vertPin);  // get the initial values
  horzZero = analogRead(horzPin);  // Joystick should be in neutral position when reading these
}
