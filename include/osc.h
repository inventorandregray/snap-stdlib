#ifndef SNAP_OSC_H
#define SNAP_OSC_H

#include <cmath>

#ifndef SAMPLE_RATE
#define SAMPLE_RATE 44100.0f
#endif

#define PI 3.14159265358979323846f
#define TWO_PI (2.0f * PI)

// Simple sine oscillator
class SineOsc {
    float phase;
    float freq;
public:
    SineOsc(float f = 440.0f) : phase(0.0f), freq(f) {}
    void setFreq(float f) { freq = f; }
    void process(int n, float** /*in*/, float** out) {
        float* out0 = out[0];
        for (int i=0; i<n; ++i) {
            out0[i] = sinf(phase);
            phase += TWO_PI * freq / SAMPLE_RATE;
            if (phase >= TWO_PI) phase -= TWO_PI;
        }
    }
};

#endif
