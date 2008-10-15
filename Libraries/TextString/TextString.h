/*
  Test.h - Test library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/


// ensure this library description is only included once
#ifndef TextString_h
#define TextString_h

// include types & constants of Wiring core API
#include "WConstants.h"


// library interface description
class TextString
{
  // user-accessible "public" interface
  public:
    TextString(int strLength);		// initialize a TextString of a given length
    void clear(void);				// fill the TextString with zeroes
 	int equals( char *thatString);	// compare to a given string
    int length(void);				// get the length up to the first zero
    int contains(char *subString);	// whether the string contains the substring
    char* trim(void);				// trim whitespace
    char* trimRight(void);			// trim whitespace from the end
    char* trimLeft(void);			// trim whitespace from the beginning
 
    char* getArray(void);			// get the whole char array
    void setArray(char* thatString);	// sets the char array equal to a string
    char getCharAt(int charNum);	// get a given char
    void setCharAt(int charNum, char thisChar);		// set a given char
 
    char* version(void);			// get the library version

  // library-accessible "private" interface
  private: 
  char *_thisString;				// the actual char array
  int _strLength;					// the array length
};

#endif

