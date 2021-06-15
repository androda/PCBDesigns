Mac Portable BlueSCSI™ V0 (prototype, design verification)

Tested on a non-backlit portable to boot System 7.1.

Termination is of the 'active' style, hence the voltage regulator and resistors.  Not likely to work with termination disabled, so leave the TERMPWR jumper installed.

The parts list says 110 ohm resistors, but because the portable's internal SCSI cable is pretty short you may be able to use 1k resistors instead.  I have tried it both ways, and the portable boots up fine.

Note that the 'USB Here' silkscreen marker, USB port on the blue pill goes on that end.  USB port should be by the voltage regulator.

You are reminded that this design is offered under a non-commercial license without warranty of any kind.