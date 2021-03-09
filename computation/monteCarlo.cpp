#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "monteCarlo.h"

namespace computing {

    float monte_carlo_integration_1d(float x_low, float x_high, float(*pf)(float x), int iterations) {
        unsigned seed;
        seed = time(0);
        srand(seed);
        double integration = 0;
        for (unsigned i = 1; i <= iterations; i++) {
            float sample = x_low + (x_high - x_low) * (rand() / double(RAND_MAX));
            float sample_value = pf(sample);
            integration += sample_value;
        }
        return integration * (x_high - x_low) / iterations;
    }

    float monte_carlo_integration_2d(float x_low, float x_high, float y_low, float y_high, float(*pf)(float x, float y), int iterations) {
        unsigned seed;
        seed = time(0);
        srand(seed);
        double integration = 0;
        for(int i=0; i < iterations; i++) {
            float sample_x = x_low + (x_high - x_low) * (rand() / double(RAND_MAX));
            float sample_y = y_low + (y_high - y_low) * (rand() / double(RAND_MAX));
            float sample_value = pf(sample_x, sample_y);
            integration += sample_value;
        }
        return integration / iterations * (x_high - x_low) * (y_high - y_low); 
    }

    float monte_carlo_integration_nd(std::vector<float> lows, std::vector<float> highs, float(*pf)(std::vector<float> params), int iterations) {
        unsigned seed;
        seed = time(0);
        srand(seed);
        double integration = 0;
        float volume = 1;
        for(int i=0;i<lows.size(); i++) {
            volume *= highs[i] - lows[i];
        }
        for(int i=0; i < iterations; i++) {
            std::vector<float> sample;
            for(int i=0;i<lows.size(); i++) {
                sample.push_back(lows[i] + (highs[i] - lows[i]) * (rand() / double(RAND_MAX)));
            }
            float sample_value = pf(sample);
            integration += sample_value;
        }
        return integration / iterations * volume; 
    }

}


int main(int argc, char **argv) {
    return 0;
}