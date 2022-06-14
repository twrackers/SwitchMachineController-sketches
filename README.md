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

## To do ##

- Considering adding another command code to trigger the initialization of the outputs.  In the current version, the outputs are set to the *Main* route state in the `setup()` function when the processor powers up.  If there are multiple switch machine controllers on the same power circuit, they will probably try to move their turnouts at about the same time.  This can cause too great a current load on the 12 volt turnout power supply, making switching unreliable.  An "init" command code would be used to delay the initialization of the outputs until each controller is commanded to initialize.
- <s>Coming soon I will update the code to also support the [Adafruit Itsy Bitsy 32u4](https://www.adafruit.com/product/3677) microcontroller, which is promoted as an updated replacement for their Pro Trinket.  The Itsy Bitsy has enough additional digital I/O pins available that I can assign some of them to setting some of the bits in the controller's I<sup>2</sup>C address.  This way multiple controllers can share an I<sup>2</sup>C bus while running the same code image, using the additional I/O pins and jumpers to assign them unique addresses.</s> These changes were implemented and tested on 6/14/2022.