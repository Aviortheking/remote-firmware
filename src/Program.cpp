#include "Program.h"
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

Program::Program() {
    // Startup
    Serial.begin(MONITOR_SPEED);
    Serial.println("Starting BLE work!");
    bleKeyboard.begin();
}

void Program::loop() {
    if(bleKeyboard.isConnected()) {
        Serial.println("Sending 'Hello world'...");
        bleKeyboard.print("Hello world");

        delay(1000);

        Serial.println("Sending Enter key...");
        bleKeyboard.write(KEY_RETURN);

        delay(1000);

        Serial.println("Sending Play/Pause media key...");
        // bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);

        delay(1000);

   //
   // Below is an example of pressing multiple keyboard modifiers
   // which by default is commented out.
    /*Hello world
    Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);Hello world
    Hello world
    Hello world

    delay(100);Hello world

    bleKeyboard.releaseAll();
    */
  }

  Serial.println("Waiting 5 seconds...");
  delay(5000);
}
