#ifndef RAY_H
#define RAY_H

#include "vec3.hpp"


class ray {
    public:
        ray() {}

        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

        const point3& origin() const;
        const vec3& direction() const;

        point3 at(double t) const;

    private:
        vec3 dir;
        point3 orig;

};

#endif