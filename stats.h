
struct Stats_list
{
   float average;
   float min;
   float max;
};

                                                                                        
struct Stats compute_statistics_list(const float* numberset, int setlength);

typedef void (*alerter_funcptr)();

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);
