# Installation #

The *SwitchMachineController* sketch and its associated source files can be installed by either:

- cloning this repository using Git on your host, or
- downloading the repository as a ZIP file and extracting the files.

For either procedure you need to know where your IDE stores your "sketchbook".

1. Open the Arduino IDE.
2. From the menu click *File* -> *Preferences*.
3. Make note of the "Sketchbook location:" field.  For example, on a Windows system it might say `C:\Users\the_doctor\Arduino`.  In this case, your sketches are stored in `C:\Users\the_doctor\Arduino\sketches`.  Jot this down somewhere, you will need this later.

## Install using Git ##

Git is available for all the same operating systems (Windows, Mac OS X, Linux) which can run the Arduino IDE.  Git graphical user interfaces for most if not all of these operating systems exist, but they're different enough that it's not practical to include instructions for all of them.  What *is* available on all systems is the Git command line interface.  So here are the instructions for using the Git CLI.

1. If you haven't already, download and install Git for your operating system.  Git can be downloaded from [https://git-scm.com/downloads](https://git-scm.com/downloads).
2. Open a command shell on your host.  On my Windows system, I use Git Bash, which installs with Git.
3. Change to your `sketches` directory.  From Git Bash, that might look like:

	`$ cd /c/Users/the_doctor/Arduino/sketches`
1. If you want to organize your sketches into subdirectories, you can create a new subdirectory in `sketches` or use one that's already there.  If you don't want to use a subdirectory, just skip this step entirely.

	- Create a new directory if it doesn't already exist.  Skip this to use an existing directory.

		`$ mkdir MySketchGroup`

	- Go to the directory.

		`$ cd MySketchGroup`
	
1. From a web browser, go to this sketch's repository at [https://github.com/twrackers/SwitchMachineController-sketches](https://github.com/twrackers/SwitchMachineController-sketches).
2. Click on the green `Code` button, then under "Clone" click on the little clipboard symbol on the right.  This copies the URL of the repository to your clipboard.
1. In your command shell, type "git clone ", then paste the URL from the previous step into your command line.  You should see:

	`$ git clone https://github.com/twrackers/SwitchMachineController-sketches.git`
1. Hit `Enter` to clone the repository into your desired directory from steps 3 (and maybe 4) above.
2. If your Arduino IDE is running, close it now.
3. If you type `ls -l` in your command shell, you will see a list of sketch directories, including one named `SwitchMachineController-sketches-main`.  It needs to be renamed:
 
	`$ mv SwitchMachineController-sketches-main SwitchMachineController`
1. You can now start the Arduino IDE again.  If from the menu you click *File* -> *Sketchbook*, you should be able to navigate to `SwitchMachineController`.

## Install from ZIP file ##

1. From a web browser, go to this sketch's repository at [https://github.com/twrackers/SwitchMachineController-sketches](https://github.com/twrackers/SwitchMachineController-sketches).
2. Click on the green `Code` button, then click `Download ZIP`.  You will end up with a file named `SwitchMachineController-sketches-main.zip`.
3. Open the ZIP file.  You will see a single folder with the same name, but without the `.zip` at the end.
4. Extract all the files to the same directory where the ZIP file is located.  You will now have a directory named `SwitchMachineController-sketches-main`.
5. Rename this new directory to simply `SwitchMachineController`.  At this point you can archive the ZIP file somewhere or delete it.
2. If your Arduino IDE is running, close it now.
6. Move the `SwitchMachineController` directory, either to your sketchbook location (see step 3 from top of this page), or to a subdirectory under your sketchbook location if you like grouping your sketches.
7. You can now start the Arduino IDE again.  If from the menu you click *File* -> *Sketchbook*, you should be able to navigate to `SwitchMachineController`.
