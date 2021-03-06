PowerBook PCB for BlueSCSI [TbA.V3]
Designed by: Tech by Androda, LLC

Big Changes:
* Termination Chips instead of resistors + voltage regulator
* Updated TRM_SELECT jumper area
 * 1 means jumper present
 * 0 means no jumper
 * 0001 is termination fully disabled and all pins isolated, labeled OFF
 * 0010 is Short Cable termination (good for powerbooks), labeled SC, 1mA termination current
 * 1100 is Normal Termination, labeled ON, full 24mA termination current

Tested on:
* PowerBook 180, boots 7.5.3 rascsi image
* PowerBook 540, boots 7.5.3 rascsi image

As always, compatibility cannot be guaranteed.

Height clearance can be a problem, you may need to bend the boot selector jumpers.

Note the 'USB Here' silkscreen, the USB port on the blue pill goes on that end.  The other way to say it is that the programming headers on the blue pill are on the same end as the 40 pin hard drive connector.

For the three-pin connector, bridge the L side to use Logic Power, or M to use Motor Power.  Some laptops may require the M setting.

Sleep Mode is untested.  Use at your own risk.