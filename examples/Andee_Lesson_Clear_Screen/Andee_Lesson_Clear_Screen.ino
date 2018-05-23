/************************************************************
  [ Andee ]
  ================
  Clear Screen

  Use the Clear Screen command to everything on the Dashboard

  Contact us at andee@annikken.com if there are 
  bugs in this sketch or if you need help with the 
  Annikken Andee
************************************************************/

// Always include these libraries.  Andee needs them
// to work with the Arduino!
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <AndeeESP32.h>

AndeeHelper ClearButton;
AndeeHelper objectA;
AndeeHelper objectB;
AndeeHelper objectC;
void setup()
{
  Andee.begin();  // Setup the board to start broadcasting as an Annikken Andee peripheral
  setInitialData();  // Define the UI objects and customise their appearance
}
 
void setInitialData()
{ 
  ClearButton.setId(0);
  ClearButton.setType(BUTTON_IN);
  ClearButton.setCoord(79, 79, 20, 20);
  ClearButton.setTitle("Clear Screen");
  ClearButton.setColor("FFFF8000");

  objectA.setId(1);
  objectA.setType(DATA_OUT);
  objectA.setCoord(2, 2, 96, 23);
  objectA.setTitle("Obj A");
  objectA.setData("Clear Screen Demo");
  objectA.setUnit("");
  objectA.setTitleTextColor("FF53868B");
  objectA.setTitleColor("FF00C5CD");
  objectA.setTextColor("FF53868B");
  objectA.setColor("FF00F5FF");

  objectB.setId(2);
  objectB.setType(DATA_OUT);
  objectB.setCoord(2, 27, 96, 23);
  objectB.setTitle("Obj B");
  objectB.setData("Press Clear button to clear screen");
  objectB.setUnit("");
  objectB.setTitleTextColor("FF53868B");
  objectB.setTitleColor("FF00C5CD");
  objectB.setTextColor("FF53868B");
  objectB.setColor("FF00F5FF");

  objectC.setId(3);
  objectC.setType(DATA_OUT);
  objectC.setCoord(2, 52, 96, 23);
  objectC.setTitle("Obj C");
  objectC.setData("UI will reappear after 2 seconds");
  objectC.setUnit("");
  objectC.setTitleTextColor("FF53868B");
  objectC.setTitleColor("FF00C5CD");
  objectC.setTextColor("FF53868B");
  objectC.setColor("FF00F5FF");
}
 
void loop()
{
  Andee.poll();//required in every Andee sketch
  if (Andee.isConnected() == true)
  {    
    objectA.update();
    objectB.update();
    objectC.update();
    ClearButton.update();
    delay(200);//delay is needed or else board will be crash
   
    if (ClearButton.isPressed()) {
      ClearButton.ack();
      Andee.clear(); // Remove all the UI on the Screen
      delay(2000); // Wait for 3s before redrawing
    }
  }
}



