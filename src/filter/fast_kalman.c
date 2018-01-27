#include <math.h>
#include "fast_kalman.h"
#include "gyro.h"
#include "includes.h"


fastKalman_t fastKalmanFilterStateRate[3];
filterTypedef_t filterType;

void initFilter(fastKalman_t *filter, float q, float r, float p, float intialValue) {
    filter->q     = q * 0.001f; //add multiplier to make tuning easier
	filter->r     = r;    //add multiplier to make tuning easier
	filter->p     = p;    //add multiplier to make tuning easier
	filter->x     = intialValue;   //set intial value, can be zero if unknown
	filter->lastX = intialValue;   //set intial value, can be zero if unknown
	filter->k     = 0.0f;          //kalman gain,
    filter->gyroDfkfDataPtr = 0;  
}

void fast_kalman_init(float q, float r, float p, float intialValue, filterTypedef_t type)
{
    filterType = type;
	initFilter(&fastKalmanFilterStateRate[0], q, r, p, intialValue);
	initFilter(&fastKalmanFilterStateRate[1], q, r, p, intialValue);
	initFilter(&fastKalmanFilterStateRate[2], q, r, p, intialValue);
}


float noiseEstimate(float data[], uint32_t size)
{
    uint32_t i;
    float sum = 0.0, sumOfSquares = 0.0, stdDev;
    for (int i = size+1; i >= 0; i--)
    {
        sum += data[i];
        sumOfSquares += powf(data[i], 2);
    }

    arm_sqrt_f32((sumOfSquares-powf(sum, 2))/(float)size, &stdDev);
    return (stdDev * 0.003f);
}

float distanceEstimate(float data[], uint32_t size)
{
	float largest = -10000.0f;
	float smallest = 10000.0f;
	float range;

	//find the range
	for(int x=size;x>=0;x--)
	{
		if(data[x]>largest)
			largest = data[x];

		if(data[x]<smallest)
			smallest = data[x];
	}

	range = largest - smallest;

	return (range * 0.001f);
}

static void _fast_kalman_pdate(fastKalman_t *axisFilter, float input)
{
    //project the state ahead using acceleration
    axisFilter->x += (axisFilter->x - axisFilter->lastX);

    //update last state
    axisFilter->lastX = axisFilter->x;

	//prediction update
	axisFilter->p = axisFilter->p + axisFilter->q;

	//measurement update
	axisFilter->k = axisFilter->p / (axisFilter->p + axisFilter->r);
	axisFilter->x += axisFilter->k * (input - axisFilter->x);
	axisFilter->p = (1.0f - axisFilter->k) * axisFilter->p;
}

//for(int x=2;x>=0;x--)
//{
//	fast_kalman_pdate(&filter[x], input[x]);
//}

float fast_kalman_pdate(filterAxisTypedef_t axis, float input)
{
    if (filterType == STD_DEV_ESTIMATION) {
        fastKalmanFilterStateRate[axis].r = noiseEstimate(fastKalmanFilterStateRate[axis].gyroDfkfData, 6);
    } else if (filterType == DISTANCE_ESTIMATION) {
        fastKalmanFilterStateRate[axis].r = distanceEstimate(fastKalmanFilterStateRate[axis].gyroDfkfData, 6);
    } 
    fastKalmanFilterStateRate[axis].gyroDfkfData[fastKalmanFilterStateRate[axis].gyroDfkfDataPtr] = input;
    _fast_kalman_pdate(&fastKalmanFilterStateRate[axis], input);
    fastKalmanFilterStateRate[axis].gyroDfkfDataPtr++;
	if (fastKalmanFilterStateRate[axis].gyroDfkfDataPtr > 5)
    {
		fastKalmanFilterStateRate[axis].gyroDfkfDataPtr=0;
    }
    return fastKalmanFilterStateRate[axis].x;
}