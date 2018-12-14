# PCA9555
Arduino Library to approach PCA9555 I2C expander with digitalRead, digitalWrite, pinMode and interrupt masking functions.

##Installation:
* a) Just download the zip file
* b) move PCA9555_LIB to the Users Arduino library (usually My documents\Arduino\Libraries)
* c) Create a new sketch and copy the example file into your sketch 
* d) Compile, download and done.

## Support functions:

* pinMode() same as standard Arduino
* digitalRead() same as Arduino
* digitalWrite() same as Arduino
* enableInterruptOnPin() Mask in pin for Interrupt
* disableInterruptOnPin() Mask out pin from Interrupt
* setInterruptCallback() Sets the callback to call if Interrupt happens
* interruptCallback() Callback to add to host interrupt.
* whatPinsInterrupted() Details what pin caused the interrupt if masked in.
 
## Additional
The code supports either pinnumbers 0 - 15 or ED0 - ED15. This to stay more or less in sync with Arduino.


