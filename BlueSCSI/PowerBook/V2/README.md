PowerBook adapter for BlueSCSI version 2.0.

You will note that there are two sets of Zip files in this folder.  SideMount has the SD card pointing out to the side, where the other zip has the SD card sticking out between the blue pill header rows (under the USB port).  There's just enough room to fit it in there without impacting anything else.

Tested on:
* PowerBook 180, boots 7.5.3 rascsi image
* PowerBook 540, boots 7.5.3 rascsi image
* PowerBook 520 with PPC upgrade, boots 7.5.3 rascsi image

Note that testing with termination jumper removed didn't work at all in my powerbook 180.  The termination design isn't perfect and the board might not work at all with termination disabled.  You have been warned, and are reminded that these board design files are offered as-is with no warranty at all.

Height clearance can be a problem, you may need to bend the boot selector jumpers.

A 3d printed mount is being designed for these that will be posted once it's ready.

Note that the 'USB Here' silkscreen is under where the SD card holder goes.  USB port on the blue pill goes on that end.  The other way to say it is that the programming headers on the blue pill are on the same end as the 40 pin har drive connector.

For the three-pin connector, bridge the L side to use Logic Power, or M to use Motor Power.  I would suggest using Logic Power exclusively as I suspect that some PowerBooks turn off Motor Power when in sleep mode.

Sleep Mode is untested.  Use at your own risk.