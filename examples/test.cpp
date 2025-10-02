#include "osc.h"
#include "filter.h"
#include "envelope.h"
#include <iostream>

int main() {
    float* out[1]; 
    float buffer[64]; 
    out[0] = buffer;
    float* in[1]; 
    in[0] = buffer;

    SineOsc osc(220.0f);
    OnePoleLP lp(800.0f);
    ADSR env;

    osc.process(64, 0, out);
    env.gateOn();
    env.process(64, out, out);
    lp.process(64, out, out);

    std::cout << "First sample: " << buffer[0] << std::endl;
    return 0;
}
