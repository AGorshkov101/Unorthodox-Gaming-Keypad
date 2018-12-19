  #include <Keyboard.h>
#include <HID.h>
#include <Keypad.h>

//////////////////////////////// SETUP CUSTOM KEY BNDINGS HERE /////////////////////////////////////
////////////////////////// DUPLICATES MAY CAUSE UNDESIRED RESULTS //////////////////////////////////

char keymap[] = {KEY_ESC, 'm', '3', '1',
                 KEY_LEFT_SHIFT, 'a', 'w', 'd',
                 'q', '6', 's', 'i'};
                                                                                             
int joy_up = KEY_TAB;
int joy_down = KEY_LEFT_CTRL;
int joy_forward = 'e';
int joy_back = 'r';

int joy_butt_fw = 'o';
int joy_butt_bk = 'x';

int space_butt = ' ';


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


/////// Button Variable Setup /////////////////////////////////////////////////////////////////////
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

char keys[ROWS][COLS] = {
{keymap[0],keymap[4],keymap[8]},
{keymap[1],keymap[5],keymap[9]},
{keymap[2],keymap[6],keymap[10]},
{keymap[3],keymap[7],keymap[11]}
};
byte rowPins[ROWS] = {3, 4, 5, 6}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {7, 8, 9}; //connect to the column pinouts of the kpd

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

///// Joystick Variable Setup //////////////////////////////////////////////////////////////////////

int horzPin = A0;  // Analog output of horizontal joystick pin
int vertPin = A1;  // Analog output of vertical joystick pin
int selPinFw = 15;  // select  pin of joystick
int selPinBk = 14;
int spacePin = 16;

int vertZero, horzZero;  
int vertValue, horzValue;  
const int trigger = 200;
int mouseClickFlag = 0;
int mouseClickFlag1 = 0;

///// Initialize //////////////////////////////////////////////////////////////////////
void setup(){
  Serial.begin(9600);
  pin_setup();
}

///// Code //////////////////////////////////////////////////////////////////////
void loop(){
  
  /////// Buttons
  butt_check();

  ///// Joystick
  joy_check();
  
}
