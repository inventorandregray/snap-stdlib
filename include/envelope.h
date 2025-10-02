#ifndef SNAP_ENVELOPE_H
#define SNAP_ENVELOPE_H

#ifndef SAMPLE_RATE
#define SAMPLE_RATE 44100.0f
#endif

enum EnvState { ENV_IDLE, ENV_ATTACK, ENV_DECAY, ENV_SUSTAIN, ENV_RELEASE };

class ADSR {
    EnvState state;
    float attack, decay, sustain, release;
    float level;
public:
    ADSR(float a=0.1f,float d=0.2f,float s=0.7f,float r=0.3f)
      : state(ENV_IDLE), attack(a),decay(d),sustain(s),release(r),level(0) {}

    void gateOn(){ state=ENV_ATTACK; }
    void gateOff(){ state=ENV_RELEASE; }

    void process(int n,float** in,float** out){
        float* in0=in?in[0]:0; 
        float* out0=out[0];
        for(int i=0;i<n;++i){
            switch(state){
                case ENV_ATTACK: 
                    level+=1.0f/(attack*SAMPLE_RATE); 
                    if(level>=1.0f){level=1.0f; state=ENV_DECAY;} 
                    break;
                case ENV_DECAY:  
                    level-= (1.0f-sustain)/(decay*SAMPLE_RATE); 
                    if(level<=sustain){level=sustain; state=ENV_SUSTAIN;} 
                    break;
                case ENV_SUSTAIN: 
                    break;
                case ENV_RELEASE: 
                    level-= sustain/(release*SAMPLE_RATE); 
                    if(level<=0){level=0; state=ENV_IDLE;} 
                    break;
                case ENV_IDLE: 
                    level=0; 
                    break;
            }
            out0[i]= level * (in0?in0[i]:1.0f);
        }
    }
};

#endif
