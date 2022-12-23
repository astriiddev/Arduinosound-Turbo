# Arduinosound-Turbo
Arduino-based 8-bit sampler for Commodore Amiga and similar devices. The attached arduino code will program an Arduino Nano or Uno to act as an 8-bit parallel analog-to-digital converter to be used with the Commodore Amiga 500's parallel port. The overall module is based around the Technosound Turbo sampler module with an added stereo preamp and thus has the Arduino mimic the funtionality of the ZN449e ADC chip.

The full version of the sampler module has been tested and proven to be working on an Amiga 500 in both Technosound Turbo and OctaMED programs. The arduino is able to convert analog signals to 8-bit digital at even the max sample rate provided in Technosound Turbo: 32khz for stereo and 50khz for mono.

In order to improve speed of the Arduino's ADC and not waste clock cycles, the code has been kept minimal, utilizing interrupt requests, port manipulation, and low level programming to work around the Arduino's default 10-bit 9.6khz sample rate.

Be sure to power the module and plug it into the parallel port BEFORE powering on the Amiga. I am not responsible for any damages done to your Amiga, parallel port, or 8520 CIA chip.

# The Circuitry
The layouts included are designed for perf boards to allow general hobbyists to build their own sampler module without needing to have a printed circuit board manufactured. The full version of the module will fit on a standard 5cm x 7cm perf board. A mini version without a preamp or stereo capabilities is also provided for beginner hobbyists or hobbyists who want to build a quick and easy module. The mini version will only record in mono and will typically not provide full range of volume without an external preamp. 

The full version is more advanced but will record in stereo and provide the full range of volume (and then some). A gain knob can be added by substituting the 100k resistors at pins 2 & 3 and 6 & 7 of the op amp with either two seperate 100k potentiometers or one dual gang 100k potentiometer (as per the schematic). An LM1458 dual op amp was used in testing but equivalent dual op amps; such as the 4558, TL072, TL082, etc; will also work. I personally prefer the sound of the LM1458 but that is entirely subjective and others may prefer the sonic capabilities of a different op amp.

The arduino will need an external supply as the parallel port on the Amiga does not supply enough current. Likewise, the preamp needs a voltage higher than 5V in order to provide enough gain. A 9V - 12V supply is recommended to power both the arduino and the preamp. I use a One Spot guitar pedal power supply in my build. If you are building the mini version, a 7V - 12V supply can be used instead or, as there's no added preamp, the Arduino can be powered by the 5V USB power.

On the layout for an arduino nano, the order of pins D0 and D1 are swapped. This has already been accounted for in both the full module's layout as well as the mini module's layout. The arduino code assigns analog input A3 as the pin for the audio in; please keep this in mind when building your module.

NOTE 1: The layout for the MINI is untested. It is based on the same principle as the full module and shouldn't have any issues. However, please let me know if there's any errors or mistakes in the mini layout.

NOTE 2: both layouts assume header sockets for the nano are used to mount the nano. If you wish to solder the nano to the board, mount the resistors that appear underneath the nano to the back of the perfboard. You can add electrical tape or kapton tape to the soldered pads to prevent any possible short between the front-facing pads and the nano. If you use header sockets for the nano, the resistors can be mounted to the front of the perfboard underneath the nano without risk of the nano touching the resistors.

# Resources Used
1.  Open Amiga Sampler by echolevel https://github.com/echolevel/open-amiga-sampler
2.  Arduino Fast(er) Sampling Rate by Wildan S. Nahar https://blog.wildan.us/2017/11/03/arduino-fast-er-sampling-rate/
3.  analogRead() registers by garretlab https://garretlab.web.fc2.com/en/arduino/inside/hardware/arduino/avr/cores/arduino/wiring_analog.c/analogRead.html
4.  Technosound Turbo circuit board photos from Amiga Hardware Database http://amiga.resource.cx/exp/technosound
5.  ZN449e 8-bit Parallel ADC datasheet https://datasheetspdf.com/pdf-file/371755/ETC/ZN449E/1
