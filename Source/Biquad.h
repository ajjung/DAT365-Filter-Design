/*
  ==============================================================================

    Biquad.h
    Created: 6 Nov 2016 5:01:38pm
    Author:  Anthony

  ==============================================================================
*/

#ifndef BIQUAD_H_INCLUDED
#define BIQUAD_H_INCLUDED

#include <math.h>

class biquad
{
public:
	void calculate(double z0, double p0, double theta0, double *coeff);
	float highpass(double in, double z0, double p0, double theta0);

private:
	double b1, b2, a1, a2;
	double a[2], b[2];
	double coeff[5];
	float out;
};



#endif  // BIQUAD_H_INCLUDED
