/************************************************************
  [ Andee ]
  ================
  Lesson 01a
  Creating Your First Display Boxes

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

// Every object that appears on your smartphone's screen
// needs to be declared like this:
AndeeHelper objectA;
AndeeHelper objectB;
// We're creating two objects

int counter = 0;

// The setup() function is meant to tell Arduino what to do
// only when it starts up.
void setup()
{
  Andee.begin("Andee");  // Setup the board to start broadcasting as an Annikken Andee peripheral 
  setInitialData();  // Define the UI objects and customise their appearance
}

// This is the function meant to define the types and the apperance of
// all the objects on your smartphone
void setInitialData()
{ 
  
  // The First Data_Out Widget
  objectA.setId(0);           // Each object must have a unique ID number
  objectA.setType(DATA_OUT);  // This defines your object as a display box
  objectA.setCoord(0, 0, 100, 20);
  /* setCoord (x-coord, y-coord, width, height)
     x-coord: From 0.0 (left-most) to 100.0 (right-most)
     y-coord: From 0.0 (top-most)  to 100.0 (bottom-most)
     width:   10.0 (10% of screen width) to 100.0 (100% of screen width)
     height:  10.0 (10% of screen height) to 100.0 (100% of screen height)
  */
  objectA.setTitle("Title Field");
  objectA.setData("Data Field");
  objectA.setUnit("Units Field");
  objectA.setTitleTextColor("FFFFFFFF"); 
  objectA.setTitleColor("50FFFFFF");
  objectA.setTextColor("FFFFFFFF");
  objectA.setColor("FFFF8000");
  /* Color is in AARRGGBB format
   * examples
   * WHITE: "FFFFFFFF"
   * BLACK: "FF000000"
   * RED:   "FFFF0000"
   * GREEN: "FF00FF00"
   * BLUE:  "FF0000FF"
   */

  // Another Data_Out Widget that writes "Hello World"
  objectB.setId(1);            
  objectB.setType(DATA_OUT);  
  objectB.setCoord(35, 50, 30, 30);
  objectB.setTitle("Hello");
  objectB.setData("World!");
  objectB.setUnit("");
  objectB.setTitleTextColor("FF53868B");
  objectB.setTitleColor("FF00C5CD");
  objectB.setTextColor("FF53868B");
  objectB.setColor("FF00F5FF"); 
}

// Arduino will run instructions here repeatedly until you power it off.
void loop()
{
  Andee.poll();//required in every Andee sketch
  if (Andee.isConnected() == true)
  {
    objectA.update();
    objectB.update();
    delay(100);//delay is needed or else the board will be crash
  }
}



