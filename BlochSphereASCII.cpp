#include "BlochSphereASCII.h"

BlochSphereASCII::BlochSphereASCII(const Qubit& qubit) : q(qubit) {}

void BlochSphereASCII::draw() {
    int size = 21; // Size of the ASCII sphere
    double theta = std::acos(std::abs(q.getAlpha())); // Polar angle
    double phi = std::arg(q.getBeta()); // Azimuthal angle

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double x = (double)(j - size / 2) / (size / 2);
            double y = (double)(i - size / 2) / (size / 2);
            double z2 = 1.0 - x * x - y * y;

            if (z2 > 0) {
                double z = std::sqrt(z2);
                double theta_current = std::acos(z);
                double phi_current = std::atan2(y, x);

                if (std::abs(theta - theta_current) < 0.2 && std::abs(phi - phi_current) < 0.2) {
                    std::cout << "Q"; // Representing the qubit
                }
                else {
                    std::cout << ".";
                }
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
