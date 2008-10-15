/*
  String.h - String library for Wiring/Arduino - implementation
  (cc) 2006 Tom Igoe .  Some rights reserved.
  
  Created 20 Oct 2006
  Version 0.1
*/

// include description files for other libraries used (if any)
#include <string.h>

// include core Wiring API
#include "WProgram.h"

// include this library's description file
#include "TextString.h"

   
  
// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

TextString::TextString(int strLength)
{
  // initialize this instance's variables
     _thisString = (char*)malloc(strLength+1);
     _strLength = strLength;
     
 // put zeroes in the string:
 	 free(_thisString);  
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

/*
	getArray() returns the string itself, as a pointer:
*/
char* TextString::getArray(void) {
	return _thisString;
}

void TextString::setArray(char* thatString) {

 //clear();
  strncpy(_thisString,thatString,strlen(_thisString)+1);
}

/*
	getCharAt returns the character at a given position in the string:
*/
char TextString::getCharAt(int charNum) {
	char thisChar;						// the character to return
	int length = strlen(_thisString);	// the length of the string (not the whole array)
	
	// as long as charNum isn't bigger than the string length:
	if (length > charNum) {
		// get the character
		thisChar =  _thisString[charNum];
	} else {
		// if charNum is higher than the string length, return 0:
		thisChar = 0;
	}
	return thisChar;
}

/*
	setCharAt() sets a character anywhere in the array.
	note that it can set characters beyond the current strlen().
*/
void TextString::setCharAt(int charNum, char thisChar) {
	
	if (_strLength > charNum) {	
		_thisString[charNum] = thisChar;
	}
}

/*
	clear() fills the string with zeros, so that the string's 
	length appears to be 0 again when you ask for length().
*/
void TextString::clear(void) {
  int length = strlen(_thisString);
  for (int  c = 0; c < length; c++) {
    _thisString[c] = '\0'; 
  }
}

/*
	equals() compares string to another given string
*/
int TextString::equals( char *thatString) {
  char match = 0;		// whether or not the strings match
  
  // strcmp() returns the comparison value of two strings.  0 means they're the same:
  int comparison = strcmp(_thisString, thatString);
  
  // if the comparison returns 0, you have a match:
  match = (comparison == 0);
  return match;
}
/*
	returns whether a given substring us 
*/
int TextString::contains(char* subString)
{
  char * subStringPointer;
  subStringPointer = strstr (_thisString,subString);
  return (subStringPointer != 0);
}

/*
split() should split the string on a given delimiter and return an array
of the chunks.  e.g. 
string = "tom, dick, harry"
string.split() = {"tom", "dick", "harry"}

char** TextString::split(char delimiter) {

}
*/

/*
	length() returns the length of the string to the last non-zero byte.
	in other words, it returns the length of the string in the array, not
	the length of the whole array
*/
int TextString::length(void) {
  int length = strlen(_thisString);
  return length;
}

/*
	trim()  trims off return, newline, space, tab, vertical tab
	from both beginning and end:
*/

char* TextString::trim(void) {
   char * trimmedString = trimRight();
	trimmedString = trimLeft();
	return _thisString;
}

/*
	trim()  trims off return, newline, space, tab, vertical tab
	from the end of the string:
*/
char* TextString::trimRight(void) {

	// get the position of the last non-zero byte:
	int stringIndex = strlen(_thisString) - 1;
	
	// trim from the end of the string:
	while  (_thisString[stringIndex] == '\t' || 	// tab
		    _thisString[stringIndex] == '\r' || 	// carriage return
		    _thisString[stringIndex] == '\n' || 	// newline
		    _thisString[stringIndex] == ' ' || 		// space
		    _thisString[stringIndex] == 0x11) 		// vertical tab
		    {
		    	_thisString[stringIndex] = '\0';
		    	stringIndex--;
		    }
	return _thisString;
}

/*
	trim()  trims off return, newline, space, tab, vertical tab
	from the beginning if the string:
*/
char* TextString::trimLeft(void) {

	// get the position of the last non-zero byte:
	int stringIndex = 0;
	
	// trim from the end of the string:
	while  (_thisString[stringIndex] == '\t' || 	// tab
		    _thisString[stringIndex] == '\r' || 	// carriage return
		    _thisString[stringIndex] == '\n' || 	// newline
		    _thisString[stringIndex] == ' ' || 		// space
		    _thisString[stringIndex] == 0x11) 		// vertical tab
		    {
		    	stringIndex++;
		    }
	
			memmove(_thisString, _thisString+stringIndex, strlen(_thisString));
	
	return _thisString;
}

/*
	version() returns the version of the library:
*/
char* TextString::version(void) {
	return "0.1";
}
// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library

