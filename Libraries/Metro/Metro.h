

#ifndef Metro_h
#define Metro_h


class Metro
{

public:
  Metro(unsigned long interval_millis);
  void interval(unsigned long interval_millis);
  char check();
	void reset();
	
private:
  unsigned long  previous_millis, interval_millis;

};

#endif


