# SwitchMachineController-sketches
The SwitchMachineController sketch is written to run on an Adafruit Pro Trinket (5V version).  It receives command bytes via I2C from a bus master device to control up to 4 KATO Unitrack solenoid-type switch machines.  There are four types of commands recognized:
- move to Main route (requires switch-machine selection code)
- move to Diverging route (requires switch-machine selection code)
- refresh all switch machine positions to their stored settings
- reset all switch machine positions to Main route

The controller activates switch machines in a serial manner so that at most one solenoid is energized at any given moment.  The controller also permits the solenoids to be energized for only 20 milliseconds when throwing (or refreshing) the points.  Except during a refresh cycle, a switch machine will not be activated if a received command tries to move the switch machine to the position it's already in.
