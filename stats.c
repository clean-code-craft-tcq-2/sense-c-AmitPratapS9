#include "stats.h"
#include "prompt.h"
#include <math.h>


int emailAlertCallCount = 0;
int ledAlertCallCount = 0;


struct Stats compute_statistics_list(const float* numberset, int setlength) 
{
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    float min = numberset[0];
    float max = numberset[0];
    int loopcount = 0;
    float Numbertotal = 0;
    
// To find the max, min, average from number
 for(loopcount=0;loopcount<setlength;loopcount++)
 {
     // check for minimum number
     if(numberset[loopcount]<min) 
     {
        min= numberset[loopcount];
     }
    if(numberset[loopcount]> max) 
    {
       max= numberset[loopcount];
    }
    Numbertotal = Numbertotal + numberset[loopcount];
  }
    s.average = Numbertotal/setlength;
    s.min = min;
    s.max = max;

    return s;
}


void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    // check compute status greater then threshold
    if(computedStats.max > maxThreshold)
    {
	// calling the led alert function
        alerters[0]();
	alerters[1]();
    }
}

