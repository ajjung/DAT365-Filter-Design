/*
  ==============================================================================

    Biquad.cpp
    Created: 6 Nov 2016 5:01:38pm
    Author:  Anthony

  ==============================================================================
*/

#include "Biquad.h"

void biquad::calculate(double z0, double p0, double theta0, double *coeff)
{
	// zeros
	b1 = (z0 + z0) * cos(theta0);
	b2 = (z0 * z0);

	// poles
	a1 = (-1) * (p0 + p0) * cos(theta0);
	a2 = (-1) * (p0 * p0);

	coeff[0] = 1;
	coeff[1] = b1;
	coeff[2] = b2;
	coeff[3] = a1;
	coeff[4] = a2;
}

float biquad::highpass(double in, double z0, double p0, double theta0)
{
	calculate(z0, p0, theta0, coeff);

	a[0] = 0.0;
	a[1] = 0.0;
	b[0] = 0.0;
	b[1] = 0.0;

	out = in * coeff[0] + b[0] * coeff[1] + b[1] * coeff[2] + a[0] * coeff[3] + a[1] * coeff[4];
	a[1] = a[0];
	a[0] = out;
	b[1] = b[0];
	b[0] = in;

	return out;
}