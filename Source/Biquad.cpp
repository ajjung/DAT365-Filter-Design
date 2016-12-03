/*
  ==============================================================================

    Biquad.cpp
    Created: 6 Nov 2016 5:01:38pm
    Author:  Anthony

  ==============================================================================
*/

#include "Biquad.h"

void biquad::setSampleRate(double sampleRate)
{
	m_sampleRate = sampleRate;
}

void biquad::setCutOff(float cutoff)
{
	m_cutOff = cutoff;
}

float biquad::highpass(float *in, int size, int n)
{
	out = new float[size];
	float r_value = 2;
	r = sqrt(r_value);
	double f = m_cutOff;

	c = tan(3.14 * f / m_sampleRate);
	a1 = 1.0 / (1.0 + r * c + c * c);
	a2 = -2 * a1;
	a3 = a1;
	b1 = 2.0 * (c*c - 1.0) * a1;
	b2 = (1.0 - r * c + c * c) * a1;

	out[n] = a1 * in[n] + a2 * in[n - 1] + a3 * in[n - 2] - b1 * out[n - 1] - b2 * out[n - 2];

	return out[n];
}