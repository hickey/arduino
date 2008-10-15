Installation
--------------------------------------------------------------------------------

To install the DateTime libraries, unzip the files into your
Arduino hardware/libraries folder.

Here is what the directory structure should look like:
...hardware/libraries/DateTime/readme.txt   (this file)
...hardware/libraries/DateTime                            (the DateTime library folder)
...hardware/libraries/DateTime/DateTime.cpp               (the library implementation file)
...hardware/libraries/DateTime/DateTime.h                 (the library header file)
.. hardware/libraries/DateTime/keywords.txt               (the syntax coloring file)
...hardware/libraries/DateTimeStrings                     (the DateTimeStrings library folder)
...hardware/libraries/DateTimeStrings/DateTimeStrings.cpp (the library implementation file)
...hardware/libraries/DateTimeStrings/DateTimeStrings.h   (the library header file)
.. hardware/libraries/DateTimeStrings/keywords.txt        (the syntax coloring file)

copy the example sketch to your Arduino sketch directory
...hardware/libraries/DateTime/ArduinoSketch/             (directory containing the example test sketch)

Optional, copy the next file to your Processing directory if you want to use this example code
...hardware/libraries/DateTime/Processing/                (directory containing the Processing sketch)


Building
--------------------------------------------------------------------------------

After this library is installed, you just have to start the Arduino sketch.

To use this library in a sketch, go to the Sketch | Import Library menu and
select DateTime.  This will add a corresponding line to the top of your sketch:
#include <DateTime.h>. 

You should also import the DateTimeStrings library if you use the string
 representation of day of week and months.

To stop using this library, delete that line and any included fonts from your sketch.

If you want to make any changes to the library you must delete .o file before recompiling your sketch for the changes to be recognized by your sketch.

