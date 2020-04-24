Using the Adafruit Pro Trinket
==============================

Detailed instructions for uploading Arduino code into an Adafruit Pro Trinket can be found at https://learn.adafruit.com/introducing-pro-trinket/starting-the-bootloader.  Here are the important points.

 1. Connect the Pro Trinket's USB port with a good USB data cable (not just a charging cable) to your PC's USB port.
 2. Start the Arduino IDE.
 3. Set the Bootloader to "USBtinyISP".  On Windows hosts, this might require drivers be installed.
 4. Start the build and upload of your code.  Wait a few seconds, then press the RESET button on the Pro Trinket to put it into Bootloader mode; the red light will blink for 10 seconds to indicate it's in Bootloader mode.  If the build completes and the upload starts while the red light is still blinking, your code should upload.  Watch the log at the bottom of the IDE to see if the upload succeeded.  If the upload does NOT start in that 10 seconds, the Pro Trinket will go back to normal mode and start the code already loaded in its flash memory.  It may take practice to get the timing right, my builds usually take longer than 10 seconds.
