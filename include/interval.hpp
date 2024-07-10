#ifndef INTERVAL_H
#define INTERVAL_H

#include "rtweekend.h"

class interval {
  public:
    double min, max;
    static const interval empty, universe;

    // Default interval is empty
    interval() : min(+infinity), max(-infinity) {} 

    interval(double min, double max) : min(min), max(max) {}

    double size() const; 

    bool contains(double x) const; 

    bool surrounds(double x) const; 

    double clamp(double x) const; 
};
  

#endif
