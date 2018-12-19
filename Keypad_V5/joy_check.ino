void joy_check(){

  vertValue = analogRead(vertPin) - vertZero;  // read vertical offset
  horzValue = analogRead(horzPin) - horzZero;  // read horizontal offset
  
  if (vertValue > trigger){
    Keyboard.press(joy_up);
  }
  else if (vertValue < -trigger){
    Keyboard.press(joy_down);
  }
  else{
    Keyboard.release(joy_up);
    Keyboard.release(joy_down);
  }
  
  if (horzValue > trigger){
    Keyboard.press(joy_back);
  }
  else if (horzValue < -trigger){
    Keyboard.press(joy_forward);
  }
  else{
    Keyboard.release(joy_back);
    Keyboard.release(joy_forward);
  }
  
  ////// if the joystick button is pressed 

   //FW Button 
  if ((digitalRead(selPinFw) == 0) && (!mouseClickFlag)){   
    mouseClickFlag = 1;
    Keyboard.press(joy_butt_fw);
  }
  else if ((digitalRead(selPinFw))&&(mouseClickFlag)){ 
    mouseClickFlag = 0;
    Keyboard.release(joy_butt_fw);
  }

  //BK Button
  if ((digitalRead(selPinBk) == 0) && (!mouseClickFlag1)){   
    mouseClickFlag1 = 1;
    Keyboard.press(joy_butt_bk);
  }
  else if ((digitalRead(selPinBk))&&(mouseClickFlag1)){ 
    mouseClickFlag1 = 0;
    Keyboard.release(joy_butt_bk);
  }

    //space Button
  if (digitalRead(spacePin) == 0){   
    Keyboard.press(space_butt);
  }
  else if (digitalRead(spacePin)){ 
    Keyboard.release(space_butt);
  }

  //Serial.print(horzValue);
  //Serial.print('_');
}
