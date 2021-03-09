#include <iostream>

namespace computing {
    float newton(float(*pf)(float x), float(*dpf)(float x), unsigned iterations=10000, bool verbose=false);
}