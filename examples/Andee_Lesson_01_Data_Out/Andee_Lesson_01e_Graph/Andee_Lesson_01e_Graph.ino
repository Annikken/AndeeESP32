/************************************************************
  [ Andee ]
  ================
  Lesson 01e
  Display your values in a graph

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
float pi = 3.142;
int counter = 0;

// The setup() function is meant to tell Arduino what to do
// only when it starts up.
void setup()
{
  Andee.begin();  // Setup the board to start broadcasting as an Annikken Andee peripheral
  setInitialData();  // Define the UI objects and customise their appearance
}

// This is the function meant to define the types and the apperance of
// all the objects on your smartphone
void setInitialData()
{

  // The First Data_Out Widget
  objectA.setId(0);
  objectA.setType(DATA_OUT);
  objectA.setCoord(0, 0, 100, 20);
  objectA.setTitle("Instruction");
  objectA.setData("Long Press the UI Below");
  objectA.setUnit("to view Graph");
  objectA.setTitleTextColor("FFFFFFFF");
  objectA.setTitleColor("50FFFFFF");
  objectA.setTextColor("FFFFFFFF");
  objectA.setColor("FFFF8000");

  // This widget will plot a sin graph
  objectB.setId(1);
  objectB.setType(DATA_OUT);
  objectB.setCoord(35, 50, 30, 30);
  objectB.setTitle("Sin Graph");
  objectB.setData("0");
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
    float sinValue = sin(((float)counter / 20) * (2 * pi));
    objectB.setData(sinValue,2); // 2 decimal places

    counter++;
    if (counter == 20) {
      counter = 0;
    }
    objectB.update();
    delay(200);//delay is needed or else board will be crash
  }  
}



