PowerBook BlueSCSI Version 4 [F1.TbA.PB.V4]
Designed by: Tech by Androda, LLC

Big Changes:
* All surface-mount components
* No jumpers!  The dual diode means logic or motor power will power the device with no selection necessary.
* Termination enable jumper is removed as well, because PowerBooks need termination 'always-on'
* Back to discrete resistors plus voltage regulator.  The termination ICs used on the previous V3 design were very hard to reliably get working first try, likely due to invisible corrosion from sitting in a warehouse for decades.  I could get them to work with some individual pin rework after the first round of soldering, but it was taking a very long time.

Tested on:
* PowerBook 180, boots 7.5.3 rascsi image
* PowerBook 540, boots 7.5.3 rascsi image

This design is *specifically for PowerBooks*.  Termination power *cannot be disabled* and this design is incompatible with any system where the hard drive is required to not terminate the bus.

If you need a version which allows termination to be disabled, try V3.

Height clearance is probably not an issue now that the mounting bracket is flush with the bottom of the PCB.

Note the 'USB Here' silkscreen, the USB port on the blue pill goes on that end.  The other way to say it is that the programming headers on the blue pill are on the same end as the 40 pin hard drive connector.

Mounting screws are M3.  With standard 1.6mm PCB thickness, the screws I use stick out about 1mm, and the mounting bracket is that thick to try and keep screws from sticking out the bottom.

Sleep Mode is untested.  Use at your own risk.

Notes on assembly:
Getting the SMD 40-pin connector to sit nicely and work properly is kind of hard.  Note that the black plastic part of the connector just barely overhangs the end of the PCB.  Place a scrap PCB of the same thickness underneath that tiny overhang before you hot air solder the connector into place.  This way it won't tip when hit with airflow.

On the two 20-pin rows, I suggest sticking the pins through the blue pill's header rows to align them properly.  Then set down on the PCB and solder just the ends.  That will ensure the rows are aligned and hold them in place for whatever solering technique you prefer.  Hot air tends to melt the plastic on these, so manual soldering may be most reliable.