#include <vector>

namespace computing {

    float monte_carlo_integration_1d(float x_low, float x_high, float(*pf)(float x), int iterations=10000);
    float monte_carlo_integration_2d(float x_low, float x_high, float y_low, float y_high, float(*pf)(float x, float y), int iterations=10000);
    float monte_carlo_integration_nd(std::vector<float> lows, std::vector<float> highs, float(*pf)(std::vector<float> params), int iterations=10000);

}