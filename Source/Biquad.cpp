/*
  ==============================================================================

    Biquad.cpp
    Created: 6 Nov 2016 5:01:38pm
    Author:  Anthony

  ==============================================================================
*/

#include "Biquad.h"

biquad::biquad() : m_cutOff(0),
m_sampleRate(0)
{
}

void biquad::setGain(float gain)
{
	m_gain = gain * .01;
}

void biquad::setSampleRate(double sampleRate)
{
	m_sampleRate = sampleRate;
}

void biquad::setCutOff(float cutoff)
{
	m_cutOff = cutoff;
}

void biquad::highpass(float* const samples, int size)
{
	double double_Pi = 3.1415926535897931;
	const double n = tan(double_Pi * m_cutOff / m_sampleRate);
	const double nSquared = n * n;
	const double b1 = 1.0 / (1.0 + sqrt(2.0) * n + nSquared);

	// Calculate coefficients
	float b2 = b1 * -2.0;
	float b3 = b1;
	float b4 = 1.0;
	float b5 = b1 * 2.0 * (nSquared - 1.0);
	float b6 = b1 * (1.0 - sqrt(2.0) * n + nSquared);

	float lv1 = v1;
	float lv2 = v2;

	// Process Samples by block
	for (int i = 0; i < size; ++i)
	{
		const float in = samples[i];
		const float out = b1 * in + lv1;
		samples[i] = out * m_gain;

		lv1 = b2 * in - b5 * out + lv2;
		lv2 = b3 * in - b6 * out;
	}

	v1 = lv1;
	v2 = lv2;
}