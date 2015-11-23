#include <stdio.h>

void main()
{
    int run = 30;

    int period = 10;
    int budget = 5;
    int deadline = 7;

    int cur_budget = 0;     /* current budget */
    int cur_deadline = 0;   /* current deadline for EDF */
    int cur_period = 0;	    /* current period for EDF */

    int time_unit = 0;
    int count, delta;

    count = (time_unit/period) + 1;
    cur_period += (count * period);

    cur_deadline = cur_period - (period - deadline);
    cur_budget = budget;

//    printf("Time = %d  cur_period = %d,    cur_deadline = %d,  cur_budget = %d \n", time_unit, cur_period, cur_deadline, cur_budget);

   
     while(time_unit <= run)
     {
        
	/*if(time_unit == 22)
	{
		period = 20;
		deadline = 12;
                budget = 8;
                printf("Change: Time = %d,  period = %d, deadline = %d, budget = %d \n\n", time_unit, period, deadline, budget);
	}*/

        delta = time_unit - cur_period;

        if ( delta > 0 )
    	{
          count = ( delta/period ) + 1;
          cur_period += count * period;
	  cur_deadline = cur_period - (period - deadline);
          cur_budget = budget;
        }

        printf("Time = %d  cur_period = %d,    cur_deadline = %d,  cur_budget = %d \n", time_unit, cur_period, cur_deadline, cur_budget);

        
        if(cur_budget > 0) 
        	cur_budget--;
                      
        time_unit++;

//        printf("Time = %d  cur_period = %d,    cur_deadline = %d,  cur_budget = %d \n", time_unit, cur_period, cur_deadline, cur_budget);
     }
}
