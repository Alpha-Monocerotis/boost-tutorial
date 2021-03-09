#include <iostream>

#include "computation/monteCarlo.h"
#include "computation/newton.h"

float func(float x) {
    return x * x * 3;
} 

int main(int argc, char **argv) {
    std::cout << computing::monte_carlo_integration_1d(10, 20, func) << std::endl;
    return 0;
}