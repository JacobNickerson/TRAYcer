#ifndef MATERIAL_H
#define MATERIAL_H

#include "rtweekend.h"
#include "ray.hpp"
#include "color.hpp"
#include "hittable.hpp"

class hit_record;

class Material {
    public:
        virtual ~Material() = default;

        virtual bool scatter(const ray& r, const hit_record& rec, color& attenuation, ray& scattered) const {
            return false;
        }
};

class Lambertian : public Material {
    private:
        color albedo;
    
    public:
        Lambertian(const color& albedo) : albedo(albedo) {}

        bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;
};

class Metal : public Material {
    private:
        color albedo;

    public:
        Metal(const color& albedo) : albedo(albedo) {}

        bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override; 
};

#endif