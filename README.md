# Arduino Battery Monitor
Is your battery going flat in your battery-powered Arduino ATMega328P project?

### See https://www.youtube.com/ralphbacon video #160
#### (Direct link to video: https://youtu.be/C-VnvjEP0-k)

$8 off your first order at LCSC Electronics with https://lcsc.com?href=ralphsbacon&source=referral

Get a timely warning before your batteries go flat!

Battery-powered, Deep Sleep Arduino (ATMega328P) projects are great but how do you know when the batteries are nearly depleted?

<img src="/images/www.maxpixel.net-Batteries-Battery-Flat-Battery-Full-Charge-1688883.jpg" width="25%" align="right" />  

In the last **video #159** we explored a simple, battery-powered PIR project using an ATMega328P, as found in every Arduino UNO and Nano. Many times I was asked how I could detect the battery voltage and warn the user that it was time to replace the batteries.

In this video I show how we can do that with no extra components, all by the magic of the bandgap voltage set on the AREF pin, either internally or externally.

ATMEL decided not to precalibrate the AREF voltage (cheapskates!) so each chip has to calibrated first using a one line sketch. Easy stuff. And whilst reading the voltage might look a bit esoteric, you don't have to understand all the code - just use it as a function in your sketch or include a small library. All this right here in the GitHub!

### LINKS    LINKS    LINKS
<img src="/images/Capacitors.JPG" width="15%" align="left">500pcs 10 Values 0.1uF~10uF 50V Ceramic Capacitor Assortment Kit $8.35  
http://s.click.aliexpress.com/e/3N1yt07m  
Take a good look around before purchasing!  

<img src="/images/Tantalum.JPG" width="15%" align="left">100Pcs 10Value 16V Tantalum Capacitor Assorted  
https://www.banggood.com/100Pcs-10Value-16V-Tantalum-Capacitor-Assorted-Kit-Box-Assorstment-p-1026880.html?p=FQ040729393382015118&utm_campaign=25129675&utm_content=3897  
Same goes for here!  
<br />
<br />
ATMega328P **Data Sheet**  
https://www.sparkfun.com/datasheets/Components/SMD/ATMega328.pdf

What's a **Bandgap Voltage Reference?**  
https://en.wikipedia.org/wiki/Bandgap_voltage_reference

Nick Gammon's page on **ADC**  
http://www.gammon.com.au/adc

Arduino Forum on the same subject  
https://forum.arduino.cc/index.php?topic=331178.msg2285210#msg2285210

Arduino's page on **Reference Voltage** (AREF)  
https://www.arduino.cc/reference/en/language/functions/analog-io/analogreference/

If you like this video please give it a thumbs up, share it and if you're not already subscribed please consider doing so and joining me on my Arduinite journey

My channel and blog are here:  
\------------------------------------------------------------------  
https://www.youtube.com/RalphBacon  
https://ralphbacon.blog  
\------------------------------------------------------------------
