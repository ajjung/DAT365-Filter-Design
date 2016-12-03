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
	void setCutOff(float cutoff);
	void setSampleRate(double sampleRate);
	float highpass(float *in, int size, int n);

private:
	double r;
	double m_cutOff;
	double m_sampleRate;
	double c;
	double a1;
	double a2;
	double a3;
	double b1;
	double b2;
	float *out;
};



#endif  // BIQUAD_H_INCLUDED
