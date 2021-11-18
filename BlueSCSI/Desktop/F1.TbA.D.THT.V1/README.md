Desktop BlueSCSI, Through-hole type with active termination and external LED support, {F1.TbA.D.THTV1}

Tested on (with termination enabled):
* LC II, boots RaSCSI 7.5.3 image
* LC III, boots RaSCSI 7.5.3 image
* Mac IIci, boots RaSCSI 7.5.3 image
* Quadra 700, boots RaSCSI 7.5.3 image
* Beige G3 Minitower, boots Mac OS 9.2 (copied my boot drive onto it)

^ All of the above tests were run with the BlueSCSI™ as the only internal hard drive.

The zip file here is the PCB design, and production runs have been made of this using JLCPCB.

Termination is of the 'active' style, hence the voltage regulator and resistor packs.  To enable termination, install the resistor packs with their dots in the center (silkscreen dots are on the board).  Resistor pack closer to the floppy power connector faces the SCSI port.  Resistor pack closer to the voltage regulator faces the blue pill module.

An external status LED is supported, connect it to the 2.54mm headers.  Tested with a Quadra 700 original LED, red to + side, works fine.

Note that the 'USB Here' silkscreen marker, USB port on the blue pill goes on that end.  So the programming headers are over by the voltage regulator.

The USE_TWPR jumper enables (when installed) the use of the termination power line in the scsi cable.  If you won't want to use the scsi cable's termination power source, remove this jumper and plug in a berg floppy power cable.  If the jumper is removed and no floppy power cable is installed, you will get a dim red power LED and the device will not work.

You are reminded that this design is offered without warranty of any kind, and is under a Non-Commercial-Use license.