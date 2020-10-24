# SwitchMachineController-sketches

The *SwitchMachineController* sketch is written to run on an Adafruit Pro Trinket (5V version), but can be easily customized to work on other Arduino-class boards.  It receives command bytes via I<sup>2</sup>C from a bus controller to control up to 4 KATO Unitrack solenoid-type switch machines.  

There are four types of commands recognized:

- move to *Main route* (requires switch-machine selection code)
- move to *Diverging route* (requires switch-machine selection code)
- refresh all switch machine positions to their most recently commanded routes, either *Main* or *Diverging*.
- reset all switch machine positions to *Main route*

The controller activates switch machines in sequence so that at most one solenoid is energized at any given moment.  The controller also permits the solenoids to be energized for only 20 milliseconds when throwing (or refreshing) the points.  Except in the case of a refresh cycle, a switch machine will not be activated if a received command tries to move the switch machine to the position it's already in.

## Installation ##

To install these files:

1. Find where your Arduino IDE stores sketches.  To do this, in the IDE click *File -> Preferences*.  The "Sketchbook location" is what you want.
2. From the top page of this repository, [https://github.com/twrackers/SwitchMachineController-sketches](https://github.com/twrackers/SwitchMachineController-sketches), click the green `Code` button, then click `Download ZIP`.
3. Open the downloaded `.zip` file.  You will see a single directory named `SwitchMachineController-sketches-main`.  Do an `Extract all` into your sketchbook directory.
4. Rename the directory you just created to simply `SwitchMachineController`.  The Arduino IDE requires that the sketch file (`SwitchMachineController.ino`) be located inside a directory of the same name, without the `.ino` part.

## Dependencies ##

The *SwitchMachineController* sketch uses the following libraries.

- *FIFO* library, [https://github.com/twrackers/FIFO](https://github.com/twrackers/FIFO)
- *StateMachine* library, [http://https://github.com/twrackers/StateMachine-library](http://https://github.com/twrackers/StateMachine-library)
- *SwitchMachine* library, [http://https://github.com/twrackers/SwitchMachine-library](http://https://github.com/twrackers/SwitchMachine-library) (includes `Triad.h`)
