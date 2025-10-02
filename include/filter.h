#ifndef SNAP_FILTER_H
#define SNAP_FILTER_H

#include <cmath>

#ifndef SAMPLE_RATE
#define SAMPLE_RATE 44100.0f
#endif

class OnePoleLP {
    float a0, b1, z1;
public:
    OnePoleLP(float cutoff=1000.0f) : z1(0.0f) {
        setCutoff(cutoff);
    }
    void setCutoff(float cutoff) {
        float x = expf(-2.0f * 3.14159265f * cutoff / SAMPLE_RATE);
        a0 = 1.0f - x;
        b1 = x;
    }
    void process(int n, float** in, float** out) {
        float* in0 = in[0]; 
        float* out0 = out[0];
        for (int i=0; i<n; ++i) {
            z1 = a0 * in0[i] + b1 * z1;
            out0[i] = z1;
        }
    }
};

#endif
