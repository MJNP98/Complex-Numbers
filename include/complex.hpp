#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <sstream>
#include <cmath>
#include <utility>

namespace mjnp {
    template <typename value_t = double>
    class complex {
        public:
            /* Constructeur par defaut */
            complex(value_t real = value_t(0), value_t imag = value_t(0)): _real(real), _imag(imag) {
                // std::cout << "Complex number at " << this << " created by default.\n";
            }
            /* Constructeur par copie */
            complex(const complex & c): _real(c._real), _imag(c._imag) {
                // std::cout << "Complex number at " << this << " created by copy.\n";
            }
            /* Affectation par copie */
            complex & operator=(const complex &);
            /* Constructeur par deplacement */
            // complex(complex &&);
            /* Affectation par deplacement */
            // complex & operator=(complex &&);
            /* Recuperation de la partie reelle d'un nombre complexe */
            value_t real() const { return _real; };
            /* Recuperation de la partie imaginaire d'un nombre complexe */
            value_t imag() const { return _imag; };
            /* Modification de la partie reelle d'un nombre complexe */
            void real(value_t val) { _real = val; }; // value_t & real() { return _real; };
            /* Modification de la partie imaginaire d'un nombre complexe */
            void imag(value_t val) { _imag = val; }; // value_t & imag() { return _imag; };
            /* Operateur arithmetique unaire retourant la valeur de l'argument */
            complex operator+() const { return *this; }
            /* Operateur arithmetique unaire retourant l'oppose de la valeur de l'argument */
            complex operator-() const { return complex(-this->_real, -this->_imag); }
            /* Comparaison d'un nombre complexe avec le nombre complexe courant */
            bool operator==(const complex &) const;
            /* Addition d'un nombre complexe dans le nombre complexe courant */
            complex & operator+=(const complex &);
            /* Addition d'un scalaire dans le nombre complexe courant */
            complex & operator+=(const value_t &);
            /* Addition de deux nombres complexes */
            complex operator+(const complex &) const;
            /* Addition d'un nombre complexe et d'un scalaire */
            complex operator+(const value_t &) const;
            /* Soustraction d'un nombre complexe dans le nombre complexe courant */
            complex & operator-=(const complex &);
            /* Soustraction d'un scalaire dans le nombre complexe courant */
            complex & operator-=(const value_t &);
            /* Soustraction de deux nombres complexes */
            complex operator-(const complex &) const;
            /* Soustration d'un nombre complexe et d'un scalaire */
            complex operator-(const value_t &) const;
            /* Multiplication d'un nombre complexe dans le nombre complexe courant */
            complex & operator*=(const complex &);
            /* Multiplication d'un scalaire dans le nombre complexe courant */
            complex & operator*=(const value_t &);
            /* Multiplication de deux nombres complexes */
            complex operator*(const complex &) const;
            /* Multiplication d'un nombre complexe et d'un scalaire */
            complex operator*(const value_t &) const;
            /* Division d'un nombre complexe dans le nombre complexe courant */
            complex & operator/=(const complex &);
            /* Division d'un scalaire dans le nombre complexe courant */
            complex & operator/=(const value_t &);
            /* Division de deux nombres complexes */
            complex operator/(const complex &) const;
            /* Division d'un nombre complexe et d'un scalaire */
            complex operator/(const value_t &) const;
            /* Flux de sortie d'un nombre complexe */
            friend std::ostream & operator<< <value_t>(std::ostream &, const complex &);
            /* Destructeur par defaut */
            ~complex() { } //{ std::cout << "Complex number at " << this << " destroyed.\n"; }
        private:
            /* Partie reelle d'un nombre complexe */
            value_t _real;
            /* Partie imaginaire d'un nombre complexe */
            value_t _imag;
    };

    /* Addition d'un scalaire et d'un nombre complexe */
    template <typename value_t>
    complex<value_t> operator+(const value_t & lhs, const complex<value_t> & rhs) {
        return rhs + lhs;
    }
    /* Soustraction d'un scalaire et d'un nombre complexe */
    template <typename value_t>
    complex<value_t> operator-(const value_t & lhs, const complex<value_t> & rhs) {
        // return -rhs += complex<value_t>(lhs);
        // return complex<value_t>(lhs - rhs.real(), -rhs.imag());
        return complex<value_t>(lhs) -= rhs;
    }
    /* Multiplication d'un scalaire et d'un nombre complexe */
    template <typename value_t>
    complex<value_t> operator*(const value_t & lhs, const complex<value_t> & rhs) {
        // return complex<value_t>(lhs * rhs.real(), lhs * rhs.imag());
        // return complex<value_t>(lhs) *= rhs;
        return rhs * lhs;
    }
    /* Division d'un scalaire et d'un nombre complexe */
    template <typename value_t>
    complex<value_t> operator/(const value_t & lhs, const complex<value_t> & rhs) {
        return complex<value_t>(lhs) /= rhs;
    }
    /* Conjugue d'un nombre complexe */
    template <typename value_t>
    auto conj(const complex<value_t> & c) {
        return complex<value_t>(c.real(), -c.imag());
    }
    /* d'un nombre complexe */
    template <typename value_t>
    value_t norm(const complex<value_t> & c) {
        value_t c_real_part(c.real()), c_imag_part(c.imag());
        return c_real_part * c_real_part + c_imag_part * c_imag_part;
    }
    /* Module d'un nombre complexe */
    template <typename value_t>
    value_t abs(const complex<value_t> & c) {
        return std::sqrt(norm(c));
    }
}

#include "../tpt/complex.tpp"

#endif
