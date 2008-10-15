This is a C++ library for Arduino 0004+, based on one created by 
Nicholas Zambetti for Wiring 0006+

This library gives you string manipulation and comparison functions.

Initial version 0.1 by Tom Igoe, 20 Oct. 2006.

Installation
--------------------------------------------------------------------------------

To install this library, just place this entire folder as a subfolder in your
Arduino/lib/targets/libraries folder.

When installed, this library should look like:

Arduino/lib/targets/libraries/TextString              (this library's folder)
Arduino/lib/targets/libraries/TextString/TextString.cpp     (the library implementation file)
Arduino/lib/targets/libraries/TextString/TextString.h       (the library description file)
Arduino/lib/targets/libraries/TextString/keywords.txt (the syntax coloring file)
Arduino/lib/targets/libraries/TextString/examples     (the examples in the "open" menu)
Arduino/lib/targets/libraries/TextString/readme.txt   (this file)

Building
--------------------------------------------------------------------------------

After this library is installed, you just have to start the Arduino application. You may see a few warning messages as it's built.

To use this library in a sketch, go to the Sketch | Import Library menu and
select TextString.  This will add a corresponding line to the top of your sketch:

#include <TextString.h>

To stop using this library, delete that line from your sketch.

Geeky information:
After a successful build of this library, a new file named "TextString.o" will appear in "Arduino/lib/targets/libraries/TextString". This file is the built/compiled library code.

If you choose to modify the code for this library (i.e. "TextString.cpp" or "TextString.h"), then you must first 'unbuild' this library by deleting the "TextString.o" file. The new "TextString.o" with your code will appear after the next press of "verify"

