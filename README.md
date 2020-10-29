# SwitchMachineController #

The *SwitchMachineController* sketch is written to run on an Adafruit Pro Trinket (5V version), but can be easily customized to work on other Arduino-class boards.  It receives command bytes via I<sup>2</sup>C from a bus controller to control up to 4 KATO UNITRACK solenoid-type switch machines.  

There are four types of commands recognized:

- move to *Main route* (requires switch-machine selection code)
- move to *Diverging route* (requires switch-machine selection code)
- refresh all switch machine positions to their most recently commanded routes, either *Main* or *Diverging*.
- reset all switch machine positions to *Main route*

The controller activates switch machines in sequence so that at most one solenoid is energized at any given moment.  The controller also permits the solenoids to be energized for only 20 milliseconds when throwing (or refreshing) the points.  Except in the case of a refresh cycle, a switch machine will not be activated if a received command tries to move the switch machine to the position it's already in.

## Installation ##

Instructions for installing the *SwitchMachineController* sketch can be found in file `INSTALL.md` in this repository at [https://github.com/twrackers/SwitchMachineController-sketches/blob/main/INSTALL.md](https://github.com/twrackers/SwitchMachineController-sketches/blob/main/INSTALL.md).

## Dependencies ##

The *SwitchMachineController* sketch uses the following libraries.

- *FIFO* library, [https://github.com/twrackers/FIFO](https://github.com/twrackers/FIFO)
- *StateMachine* library, [https://github.com/twrackers/StateMachine-library](https://github.com/twrackers/StateMachine-library)
- *SwitchMachine* library, [https://github.com/twrackers/SwitchMachine-library](https://github.com/twrackers/SwitchMachine-library)
