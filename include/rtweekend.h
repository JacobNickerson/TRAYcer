#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <random>


// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {  // Returns a random real number in [0,1)
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {  // Returns a random real in [min, max)
    return min + (max-min)*random_double();
}

inline double linear_to_gamma(double linear_component) {
    if (linear_component > 0) {
        return sqrt(linear_component);
    } else {
        return 0;
    }
}

// CPP std Usings
using std::fabs;
using std::make_shared;
using std::shared_ptr;
using std::sqrt;

#endif