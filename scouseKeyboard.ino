/* 
   Adapted from "Buttons to USB Keyboard Example"

   You must select Keyboard from the "Tools > USB Type" menu to compile

   This example code is in the public domain.
*/

#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.

// for the keyboard pins 6, 7 & 8 are connected, 8 is not used
Bounce button0 = Bounce(6, 10);
Bounce button1 = Bounce(7, 10);  // 10 = 10 ms debounce time
//Bounce button2 = Bounce(8, 10);


void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
//  pinMode(8, INPUT_PULLUP);
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
//  button2.update();

  // Check each button for "falling" edge.
  // Type a message on the Keyboard when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (button0.fallingEdge()) {
    Keyboard.print("A ");
  }
  if (button1.fallingEdge()) {
    Keyboard.print("Calm down ");
  }
//  if (button2.fallingEdge()) {
//    Keyboard.print("It's not the same without our Te... ");
//  }


  // Check each button for "rising" edge
  // Type a message on the Keyboard when each button releases.
  // For many types of projects, you only care when the button
  // is pressed and the release isn't needed.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
//  if (button0.risingEdge()) {
//    Keyboard.println("B0 release");
//  }
//  if (button1.risingEdge()) {
//    Keyboard.println("B1 release");
//  }
//  if (button2.risingEdge()) {
//    Keyboard.println("B2 release");
//  }

}

