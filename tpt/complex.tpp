namespace mjnp {
    /* Affectation par copie */
    template <typename value_t>
    complex<value_t> & complex<value_t>::operator=(const complex<value_t> & rhs) {
        // std::cout << "Complex number at " << this << " assigned by copy.\n";
        this->_real = rhs._real; this->_imag = rhs._imag;
        return *this;
    }
    /* Comparaison d'un nombre complexe avec le nombre complexe courant */
    template <typename value_t>
    bool complex<value_t>::operator==(const complex<value_t> & rhs) const {
        bool val = (this->_real == rhs._real and this->_imag == rhs._imag)?true:false;
        return val;
    }
    /* Addition d'un nombre complexe dans le nombre complexe courant */
    template <typename value_t>
    complex<value_t> & complex<value_t>::operator+=(const complex<value_t> & rhs) {
        this->_real += rhs._real; this->_imag += rhs._imag;
        return *this;
    }
    /* Addition d'un scalaire dans le nombre complexe courant */
    template <typename value_t>
    complex<value_t> & complex<value_t>::operator+=(const value_t & rhs) {
        this->_real += rhs;
        return *this;
    }
    /* Addition de deux nombres complexes */
    template <typename value_t>
    complex<value_t> complex<value_t>::operator+(const complex<value_t> & rhs) const {
        // return complex<value_t>(this->_real + rhs._real, this->_imag + rhs._imag);
        return complex<value_t>(*this) += rhs;
    }
    /* Addition d'un nombre complexe et d'un scalaire */
    template <typename value_t>
    complex<value_t> complex<value_t>::operator+(const value_t & rhs) const {
        return complex<value_t>(*this) += rhs;
    }
    /* Soustraction d'un nombre complexe dans le nombre complexe courant */
    template <typename value_t>
    complex<value_t> & complex<value_t>::operator-=(const complex<value_t> & rhs) {
        this->_real -= rhs._real; this->_imag -= rhs._imag;
        return *this;
    }
    /* Soustraction d'un scalaire dans le nombre complexe courant */
    template <typename value_t>
    complex<value_t> & complex<value_t>::operator-=(const value_t & rhs) {
        this->_real -= rhs;
        return *this;
    }
    /* Soustraction de deux nombres complexes */
    template <typename value_t>
    complex<value_t> complex<value_t>::operator-(const complex<value_t> & rhs) const {
        return complex<value_t>(*this) -= rhs;
    }
    /* Soustration d'un nombre complexe et d'un scalaire */
    template <typename value_t>
    complex<value_t> complex<value_t>::operator-(const value_t & rhs) const {
        return complex<value_t>(*this) -= rhs;
    }
    /* Multiplication d'un nombre complexe dans le nombre complexe courant */
    template <typename value_t>
    complex<value_t> & complex<value_t>::operator*=(const complex<value_t> & rhs) {
        auto lhs_real_part(this->_real), rhs_real_part(rhs._real);
        auto lhs_imag_part(this->_imag), rhs_imag_part(rhs._imag);
        this->_real = lhs_real_part * rhs_real_part - lhs_imag_part * rhs_imag_part;
        this->_imag = lhs_real_part * rhs_imag_part + rhs_real_part * lhs_imag_part;
        return *this;
    }
    /* Multiplication d'un scalaire dans le nombre complexe courant */
    template <typename value_t>
    complex<value_t> & complex<value_t>::operator*=(const value_t & rhs) {
        this->_real *= rhs; this->_imag *= rhs;
        return *this;
    }
    /* Multiplication de deux nombres complexes */
    template <typename value_t>
    complex<value_t> complex<value_t>::operator*(const complex<value_t> & rhs) const {
        return complex<value_t>(*this) *= rhs;
    }
    /* Multiplication d'un nombre complexe et d'un scalaire */
    template <typename value_t>
    complex<value_t> complex<value_t>::operator*(const value_t & rhs) const {
        return complex<value_t>(*this) *= rhs;
    }
    /* Division d'un nombre complexe dans le nombre complexe courant */
    template <typename value_t>
    complex<value_t> & complex<value_t>::operator/=(const complex<value_t> & rhs) {
        auto lhs_real_part(this->_real), rhs_real_part(rhs._real);
        auto lhs_imag_part(this->_imag), rhs_imag_part(rhs._imag);
        auto rhs_norm = norm(rhs);
        this->_real = (lhs_real_part * rhs_real_part + lhs_imag_part * rhs_imag_part) / rhs_norm;
        this->_imag = (rhs_real_part * lhs_imag_part - lhs_real_part * rhs_imag_part) / rhs_norm;
        return *this;
    }
    /* Division d'un scalaire dans le nombre complexe courant */
    template <typename value_t>
    complex<value_t> & complex<value_t>::operator/=(const value_t & rhs) {
        this->_real /= rhs; this->_imag /= rhs;
        return *this;
    }
    /* Division de deux nombres complexes */
    template <typename value_t>
    complex<value_t> complex<value_t>::operator/(const complex<value_t> & rhs) const {
        return complex<value_t>(*this) /= rhs;
    }
    /* Division d'un nombre complexe et d'un scalaire */
    template <typename value_t>
    complex<value_t> complex<value_t>::operator/(const value_t & rhs) const {
        return complex<value_t>(*this) /= rhs;
    }
    /* Flux de sortie d'un nombre complexe */
    template <typename value_t>
    auto operator<<(std::ostream & os, const complex<value_t> & c) -> decltype(os) {
        const auto real_part = c._real, imag_part(c._imag);
	    std::ostringstream oss;
        if(real_part == value_t(0) and imag_part == value_t(0)) oss << 0;
        else {
            if(real_part != value_t(0)) oss << real_part; // ou oss << (real_part == value_t(0)?"":std::to_string(real_part));
            if(imag_part != value_t(0)) {
                if(std::signbit(imag_part)) {
                    oss << (imag_part == value_t(-1)?"-i":std::to_string(imag_part) + 'i');
                    // if(imag_part == value_t(-1)) oss << "-i";
                    // else oss << imag_part << 'i';
                }
                else {
                    if(imag_part == value_t(1) and real_part != value_t(0)) oss << "+i";
                    else if(imag_part == value_t(1) and real_part == value_t(0)) oss << 'i';
                    else oss << (real_part != value_t(0)?"+":"") << imag_part << 'i';

                }
            }
        }
        os << oss.str();
        return os;
    }
}
