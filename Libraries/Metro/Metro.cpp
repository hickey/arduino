
#include "WProgram.h"
#include "Metro.h"


Metro::Metro(unsigned long interval_millis)
{
	interval(interval_millis);
	reset();
}

void Metro::interval(unsigned long interval_millis)
{
  this->interval_millis = interval_millis;
}

char Metro::check()
{


  if (millis() - this->previous_millis >= this->interval_millis) {
    // As suggested by benjamin.soelberg@gmail.com, the following line was changed
    // FROM:
    // this->previous_millis = millis();
    // TO: 
    this->previous_millis += this->interval_millis; 
    
    return 1;
  }
  
  
  
  return 0;

}

void Metro::reset() 
{
 
  this->previous_millis = millis();

}


