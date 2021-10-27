#include "stats.h"
#include "prompt.h"
#include <math.h>


int emailAlertCallCount = 0;
int ledAlertCallCount = 0;


struct Stats_list compute_statistics_list(const float* numberset, int setlength) 
{
    struct Stats_list s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    float min = numberset[0];
    float max = numberset[0];
    int loopcount = 0;
    float Numbertotal = 0;
    
// finding min, max 
 for(loopcount=0;loopcount<setlength;loopcount++)
 {
     // Minimum number assignment
     if(numberset[loopcount]<min) 
     {
        min= numberset[loopcount];
     }
     // Maximum number assignment
    if(numberset[loopcount]> max) 
    {
       max= numberset[loopcount];
    }
    // Average number assignment
    Numbertotal = Numbertotal + numberset[loopcount];
  }
    s.average = Numbertotal/setlength;
    s.min = min;
    s.max = max;

    return s;
}


void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    // checking compute status greater then threshold
    if(computedStats.max > maxThreshold)
    {
	// calling the led alert function
        alerters[0]();
	alerters[1]();
    }
}

