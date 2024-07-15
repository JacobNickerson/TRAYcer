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

        virtual bool scatter(const ray& r_in, const hit_record& rec, Color& attenuation, ray& scattered) const {
            return false;
        }
};

class Lambertian : public Material {
    private:
        Color albedo;
    
    public:
        Lambertian(const Color& albedo) : albedo(albedo) {}

        bool scatter(const ray& r_in, const hit_record& rec, Color& attenuation, ray& scattered) const override;
};

class Metal : public Material {
    private:
        Color albedo;
        double fuzz;

    public:
        Metal(const Color& albedo, double fuzz) : albedo(albedo), fuzz(std::min(fuzz, 1.0)) {}

        bool scatter(const ray& r_in, const hit_record& rec, Color& attenuation, ray& scattered) const override; 
};

class Dielectric : public Material {
    public:
        Dielectric(double refraction_index) : refraction_index(refraction_index) {}

        bool scatter(const ray& r_in, const hit_record& rec, Color& attenuation, ray& scattered) const override;

    private:
        double refraction_index;

        // Approximated using the Schlick Approximation
        static double reflectance(double cosine, double refraction_index);
};

#endif