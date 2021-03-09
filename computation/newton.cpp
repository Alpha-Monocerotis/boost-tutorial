#include "newton.h"

namespace computing {
    float newton(float(*pf)(float x), float(*dpf)(float x), unsigned iterations, bool verbose) { 
        int sol = 1;
        for(int i = 0; i < iterations; i++) {
            sol = sol - pf(sol) / dpf(sol);
            if(verbose)
                std::cout << "Iterations " << iterations << " :sol = " << sol << std::endl;
        }
        return sol;
    }
}