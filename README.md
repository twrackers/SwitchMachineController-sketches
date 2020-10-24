# SwitchMachineController-sketches

The *SwitchMachineController* sketch is written to run on an Adafruit Pro Trinket (5V version), but can be easily customized to work on other Arduino-class boards.  It receives command bytes via I<sup>2</sup>C from a bus controller to control up to 4 KATO Unitrack solenoid-type switch machines.  

There are four types of commands recognized:

- move to *Main route* (requires switch-machine selection code)
- move to *Diverging route* (requires switch-machine selection code)
- refresh all switch machine positions to their most recently commanded routes, either *Main* or *Diverging*.
- reset all switch machine positions to *Main route*

The controller activates switch machines in sequence so that at most one solenoid is energized at any given moment.  The controller also permits the solenoids to be energized for only 20 milliseconds when throwing (or refreshing) the points.  Except in the case of a refresh cycle, a switch machine will not be activated if a received command tries to move the switch machine to the position it's already in.

## Installation ##

To install this sketch and all its files, clone this repository or download it as a .ZIP file.
- If you have cloned the repository, rename the top directory from *SwitchMachineController-sketches-main* to *SwitchMachineController*.  Then move the whole directory to wherever you store your Arduino IDE sketches.
- If you have downloaded the repository in a .ZIP file, rename the .ZIP file in the same way, removing "-sketches-main" from its name.  Then extract all files into a directory named "SwitchMachineController" within your IDE's *sketches* directory.

## Dependencies ##

The *SwitchMachineController* sketch uses the following libraries.

- *FIFO* library, [https://github.com/twrackers/FIFO](https://github.com/twrackers/FIFO)
- *StateMachine* library, [http://https://github.com/twrackers/StateMachine-library](http://https://github.com/twrackers/StateMachine-library)
- *SwitchMachine* library, [http://https://github.com/twrackers/SwitchMachine-library](http://https://github.com/twrackers/SwitchMachine-library) (includes `Triad.h`)
