Desktop BlueSCSI™, {F1.TbA.DSK.V1}

Tested on (with termination enabled):
* LC II, boots RaSCSI 7.5.3 image
* LC III, boots RaSCSI 7.5.3 image
* Mac IIci, boots RaSCSI 7.5.3 image
* Quadra 700, boots RaSCSI 7.5.3 image
* Beige G3 Minitower, boots RaSCSI 7.5.3 image

^ All of the above tests were run with the BlueSCSI™ as the only internal hard drive.

Termination is of the 'active' style, hence the voltage regulator and resistors.  Unknown if it works with termination disabled, so just leave it on unless you feel like testing that.  The bus is supposed to be terminated anyway.

A 3d printed mount is being designed for these that will be posted once it's ready.

Note that the 'USB Here' silkscreen marker, USB port on the blue pill goes on that end.  So the programming headers are down next to the SD card slot.

There are two three-pin-wide jumper blocks, with labels SCSI and Floppy

* Jumper between SCSI port and berg floppy connector controls which power source is used to run the SCSI emulator CPU
** It's a tight fit
** SCSI side uses term power line from the SCSI cable
** Floppy side uses floppy power connector
* Jumper over nearer the USB port on the little blue module controls which power source is used to run the scsi bus terminator
** SCSI side uses term power line from SCSI cable
** Floppy side uses floppy power

You are reminded that this design is offered without warranty of any kind.