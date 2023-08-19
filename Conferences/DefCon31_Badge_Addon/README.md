# DefCon 31 Badge Addon
 This was my quick attempt to get something ready for DefCon 31.  The process of getting the PCB outline imported to KiCAD was not easy.

# What does it do?
 It's a "[Heat Index](https://www.weather.gov/safety/heat-index)" calculator and indicator.  The Heat Index is a way to calculate the temperature it "feels like" based on the combination of temperature and humidity in your current environment.
 
 The LED flashes about once per second (internal oscillators being as they are), with a color based on the calculated Heat Index.  Note that these temperatures are all in Fahrenheit.  Blue for < 80 degrees, Green for 81 to 90 degrees, Yellow for 91 to 104 degrees, Red for 105 to 125 degrees, and Purple for anything above that.

 The "yellow" color doesn't work very well due to lack of time in figuring out good PWM mixing values.  I use the term PWM loosely here, it's basically manual PWM due to issues with getting hardware PWM working properly
 
 Battery life isn't great, I was unable to get STOP mode with RTC wake working properly, even with a supposed "template" for doing so from the manufacturer.  Instead it uses SLEEP mode with a hardware timer wakeup, and the battery lasts about 12 hours.

 It's also a breakout board in that I routed all the additional pins to standard 2.54mm header strip positions.  So go ahead and reflash this as something more useful later on.  :)
 
# Is it useful?
 Kind of.  Maybe.  Was a good project for learning the [STM32Duino](https://github.com/stm32duino/Arduino_Core_STM32) framework, and for discovering that basically nothing in Arduino is as easy as it sounds when trying to use hardware peripherals.
 
# What chips are those?
* SHTC3 Temperature and Humidity Sensor
* STM32F030 Microcontroller
* Osram LRTBR48G LED
 
# License
 Licensed Creative Commons Attribution-NonCommercial-ShareAlike 4.0.
 https://creativecommons.org/licenses/by-nc-sa/4.0/
 https://creativecommons.org/licenses/by-nc-sa/4.0/deed.fr



