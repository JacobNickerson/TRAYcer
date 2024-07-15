[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<h3 align="center">TRAYcer</h3>

  <p align="center">
    A raytracing scene renderer with colored, ray-traced lighting. Based on <a href="https://raytracing.github.io/books/RayTracingInOneWeekend.html">Ray Tracing in One Weekend</a> (see acknowledgements for citation); TRAYcer features spherical objects, three different materials, a positionable camera, antialiasing, and defocus blurring (also known as depth of field).
    <br />
    <a href="https://github.com/JacobNickerson/TRAYcer"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/JacobNickerson/TRAYcer">View Demo</a>
    ·
    <a href="https://github.com/JacobNickerson/TRAYcer/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    ·
    <a href="https://github.com/JacobNickerson/TRAYcer/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]](https://example.com)


<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* [![CPP][CPP]][CPP-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started
This project was built using WSL (Ubuntu 22.04.2 LTS on Windows 10 x86_64). Your version may differ slightly, but should likely work so long as you have the apt-get package manager.

### Prerequisites

* WSL
  ```sh
  wsl --install
  ```

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/JacobNickerson/TRAYcer.git
   ```
2. Install build-essential for compilation, Make to automate the compilation and file exporting process, and feh to view the exported ppm file
   ```sh
   sudo apt-get install build-essential && sudo apt-get install make && sudo apt-get install feh
   ```
3. Use the included Makefile to compile the program, run it, export the results into .build/images/, and open the image in feh
   ```sh
   make
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

Camera parameters and scene objects can be modified in main.cpp currently. New objects can be added by adding
```cpp
world.add(make_shared<sphere>(point3(double x_coord, double y_coord, double z_coord), double sphere_radius, sphere_material)
```
Where x_coord, y_coord, and z_coord are doubles corresponding to their cartesian coordinates, sphere_radius is a double corresponding to the radius of the sphere being created, and sphere_material is a shared_ptr to a material.
A new material can be created by adding
```cpp
auto material_name = make_shared<material_type>(parameters)
```
Where material_type is a either Lambertian, Metal, or Dielectric. Making a new material will have different parameters depending on the type of material, they are as follows:
<br />
```cpp
make_shared<Lambertian>(Color(double r_val, double g_val, double b_val)
```
```cpp
make_shared<Metal>(Color(double r_val, double g_val, double b_val), double fuzz)
```
```cp
make_shared<Dielectric>(double refraction_index)
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [ ] Standalone Executable
- [ ] GUI
- [ ] RT Weekend 2 Features
    - [ ] Motion Blur
    - [ ] Texture Maps
    - [ ] Perlin Noise
    - [ ] Quadrilaterals
    - [ ] Lights
    - [ ] Transforms
    - [ ] Volumetric Rendering
    - [ ] Increased scene rendering speed
- [ ] Experimental Features
    - [ ] Triangles

See the [open issues](https://github.com/JacobNickerson/TRAYcer/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the Unlicense. See `LICENSE` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Your Name -  JacobNickerson817@gmail.com

Project Link: [https://github.com/JacobNickerson/TRAYcer](https://github.com/JacobNickerson/TRAYcer)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/JacobNickerson/TRAYcer.svg?style=for-the-badge
[contributors-url]: https://github.com/JacobNickerson/TRAYcer/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/JacobNickerson/TRAYcer.svg?style=for-the-badge
[forks-url]: https://github.com/JacobNickerson/TRAYcer/network/members
[stars-shield]: https://img.shields.io/github/stars/JacobNickerson/TRAYcer.svg?style=for-the-badge
[stars-url]: https://github.com/JacobNickerson/TRAYcer/stargazers
[issues-shield]: https://img.shields.io/github/issues/JacobNickerson/TRAYcer.svg?style=for-the-badge
[issues-url]: https://github.com/JacobNickerson/TRAYcer/issues
[license-shield]: https://img.shields.io/github/license/JacobNickerson/TRAYcer.svg?style=for-the-badge
[license-url]: https://github.com/JacobNickerson/TRAYcer/blob/main/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/jacobnickerson817
[product-screenshot]: images/screenshot.png
[CPP]: https://img.shields.io/badge/-C++-blue?style=for-the-badge&logo=cplusplus&logoColor=white
[CPP-url]: https://isocpp.org/
