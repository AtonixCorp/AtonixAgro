// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

void onAtonixAgroChange();

String atonixAgro;

void initProperties(){

  ArduinoCloud.addProperty(atonixAgro, READWRITE, ON_CHANGE, onAtonixAgroChange);

}

////////////////////////////ATTENTION!!!////////////////////////////////
// ATTENTION: No device is currently associated to this Thing,        //
// hence the Connection Handler code could not be generated           //
// Please associate an existing or new device or manually create your //
// instance of Connection Handler                                     //
// Eg.                                                                // 
// WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);   //
////////////////////////////////////////////////////////////////////////

#error "No device is currently associated to this Thing, hence the Connection Handler code could not be generated"
