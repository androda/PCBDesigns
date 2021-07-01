Newton Internal Serial
Designed by: Tech by Androda, LLC in June 2021

This board is designed to fit into the Newton 2000 or 2100 and give them an internal serial port (something Apple should have included from the factory).

Assembly:
Note that the PCB has more spaces for the Samtec connector than it actually needs.  This is because I got a deal on 17-pin dual-row connectors on eBay and figured it doesn't matter too much to include the extra pads here.  Align your dual-row 16 pin connector such that it sits where the 1 __ ... __ 16 marking is.  The last two pads at edge of board are unused and only there for the 17 pin connector I ended up with.

See the note on the PCB?
* G by a capacitor indicates it's only necessary for the 1323CG (two caps, one each 0.33 and 1uF)
* W indicates that only the 1323CSW needs it (two caps, one each 0.33 and 1uF)
* WG indicates it should be used for both (two caps, one each 0.33 and 1uF)

This board design has not been tested with the 1323CSW chip style.  If you choose that chip, let me know if it works.

All the capacitors look the same, so be careful which ones you put where.

The switch is extremely heat sensitive and likes to melt. Solder all the rest of the surface mount things first, then use the handle of a set of tweezers to cover the body of the switch while hot-air soldering it into place.  That seems to keep the switch itself from melting.  Definitely wait for it to fully cool before actuating the switch or it could flex internally and be ruined.

The serial port's legs are far too long and must be cut down so a minimal amount sticks through the PCB.  PCB is 0.6mm thick, so don't be afraid to cut a whole bunch off the legs.  Also, trim the little flanges around the base of the serial port.  See the pictures folder.

Setup is very basic:
* Open your newton
* Install the board (semi-delicate, this is a very small connector)
    * Use the little 3d printed gasket under the screw hole directly above the Samtec connector
    * Without the gasket you'll flex the board
    * Gasket is necessary because the Samtec connector is just a little taller than the connector which was originally intended to be used for internal expansion devices (no longer available)
    * See the pictures folder
* Screw it in place
    * Screw to use is"1-72" thread, 3/8 inch long
* Flip the switch to always-on
    * PCB indicates which direction this is
* Install Jake Borden's Internal Device Prefs package
    * https://github.com/jake-b/Newton-Internal-WiFi/tree/master/Newton%20Pkg
    * This adds an option to the Newton's Prefs application to enable/disable the internal serial port
* Flip the switch to Software Enable (see pictures)
* Close up your Newton - finished

These instructions and all things related to the Newton Internal Serial board are offered as-is with no warranty of any kind.
You are reminded that these designs are licensed Non-Commercial, for personal use only.


