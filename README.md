# HC-SR501
Arduino communication library for the HC-SR501 PIR (Motion) sensor

#Settings

**Sensitivity** - The detection range

**Time** - The output time for the **L Detection Type**

#Detection Types:

**H** - The sensor will continue to output HIGH signal as long as there is movement

**L** - The sensor will continue to output HIGH signal depending on the **Time setting**

#Notes:

- The delay time is stated to vary between 3 seconds and 5 minutes, but measuring shows that it is not true.
There are signals, which length is around 1.5 seconds, when the knob is turned all the way to the start.
