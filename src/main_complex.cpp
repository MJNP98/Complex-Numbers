#include "../include/complex.hpp"
#include <cassert>

int main() {
    mjnp::complex c0;
    mjnp::complex<double> c1(1), c2(0, -1), c3(0, 1), c4(-1, -1);
    mjnp::complex<double> c5(1, 1), c6(2, -2), c7(-3, 3), c8(4, -4);
    std::cout << "c0 = " << c0 << '\n';
    std::cout << "c1 = " << c1 << '\n';
    std::cout << "c2 = " << c2 << '\n';
    std::cout << "c3 = " << c3 << '\n';
    std::cout << "c4 = " << c4 << '\n';
    std::cout << "c5 = " << c5 << '\n';
    std::cout << "c6 = " << c6 << '\n';
    std::cout << "c7 = " << c7 << '\n';
    std::cout << "c8 = " << c8 << '\n';

    std::cout << "c1 == c2 ? " << std::boolalpha << (c1 == c2) << '\n';
    std::cout << "3 + c1 + c3 + 1 = " << 3. + (c1 + c3) + 1 << '\n';
    std::cout << "3 - (c2 - c4) - 1 = " << 3. - (c2 - c4) - 1 << '\n';
    std::cout << "c3 * c3 = " << c3 * c3 << '\n';
    std::cout << "-1 * (c3 * c5) * 2 = " << -1. * (c3 * c5) * 2 << '\n';
    std::cout << "(c1 / c3) / 2 = " << (c1 / c3) / 2 << '\n';
    std::cout << "1 / c3 = " << 1. / c3 << '\n';

    std::cout << "-c6 = " << -c6 << '\n';

    c4 += c5;
    std::cout << "c4 += c5 = " << c4 << '\n';
    c4 += 4;
    std::cout << "c4 += 4 = " << c4 << '\n';
    c5 -= c6;
    std::cout << "c5 -= c6 = " << c5 << '\n';
    c5 -= 2;
    std::cout << "c5 -= 2 = " << c5 << '\n';
    c6 *= c7;
    std::cout << "c6 *= c7 = " << c6 << '\n';
    c6 *= -2;
    std::cout << "c6 *= -2 = " << c6 << '\n';
    c7 /= c8;
    std::cout << "c7 /= c8 = " << c7 << '\n';
    c7 /= .75;
    std::cout << "c7 /= 3/4 = " << c7 << '\n';

    std::cout << "Conjugué de c8 : " << mjnp::conj(c8) << '\n';
    std::cout << "Modification de la partie réelle et de la partie imaginaire de c8 :\n";
    c8.real(-8); c8.imag(8);
    std::cout << "c8 = " << c8 << '\n';
    /* Appel au constructeur par copie */
    auto c9(c4); // auto c9 = c4;
    std::cout << "c9 == c4 ? " << std::boolalpha << (c9 == c4) << '\n';
    /* Affectation par copie */
    c9 = c0;
    std::cout << "c9 == c4 ? " << std::boolalpha << (c9 == c4) << '\n';

    auto c2_squared_modulus(mjnp::norm(c2));
    std::cout << "|c2| = " << mjnp::abs(c2) << '\n';
    std::cout << "|c2|^2 = " << c2_squared_modulus << '\n';
    assert(c2_squared_modulus == c2 * mjnp::conj(c2));
    auto c8_squared_modulus(mjnp::norm(c8));
    std::cout << "|c8| = " << mjnp::abs(c8) << '\n';
    std::cout << "|c8|^2 = " << mjnp::norm(c8) << '\n';
    assert(c8_squared_modulus == c8 * mjnp::conj(c8));

    return EXIT_SUCCESS;
}
