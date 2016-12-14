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
	biquad();
	void setGain(float gain);
	void setCutOff(float cutoff);
	void setSampleRate(double sampleRate);
	void highpass(float *in, int size);

private:
	double r;
	double m_gain;
	double m_cutOff;
	double m_sampleRate;
	float *out;
	float v1 = 0;
	float v2 = 0;
};



#endif  // BIQUAD_H_INCLUDED
