/*
 *  MachTiming.c
 *  Objective-Gems
 *
 * From: http://macresearch.org/tutorial_performance_and_time
 *
 * Public Domain
 */

#include "MachTiming.h"

double mach_absolute_difference_seconds(uint64_t endTime, uint64_t startTime)
{
    uint64_t difference = endTime - startTime;
    static double conversion = 0.0;
    
    if(0 == conversion)
    {
        mach_timebase_info_data_t info;
        kern_return_t errorCode = mach_timebase_info(&info);
		
		//Convert the timebase into seconds
        if(0 == errorCode)
		{
			conversion = 1e-9 * (double)info.numer / (double)info.denom;
		}
    }
    
    return conversion * (double)difference;
}
