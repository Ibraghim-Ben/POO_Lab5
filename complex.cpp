#include <iostream>
#include <cmath>

class Complex {
private:
    double re;
    double im;

public:
    Complex() : re(0.0), im(0.0) {}
    Complex(double r) : re(r), im(0.0) {}
    Complex(double r, double i) : re(r), im(i) {}

    double real() const { return re; }
    double imag() const { return im; }
    void setReal(double r) { re = r; }
    void setImag(double i) { im = i; }

    double modulus() const { return std::sqrt(re * re + im * im); }
    Complex conjugate() const { return Complex(re, -im); }

    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator-(const Complex& other) const {
        return Complex(re - other.re, im - other.im);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            re * other.re - im * other.im,
            re * other.im + im * other.re
        );
    }

    Complex operator/(const Complex& other) const {
        double denom = other.re * other.re + other.im * other.im;
        return Complex(
            (re * other.re + im * other.im) / denom,
            (im * other.re - re * other.im) / denom
        );
    }

    Complex operator+(double d) const { return Complex(re + d, im); }
    Complex operator-(double d) const { return Complex(re - d, im); }
    Complex operator*(double d) const { return Complex(re * d, im * d); }
    Complex operator/(double d) const { return Complex(re / d, im / d); }

    bool operator==(const Complex& other) const {
        const double eps = 1e-9;
        return std::fabs(re - other.re) < eps && std::fabs(im - other.im) < eps;
    }

    bool operator!=(const Complex& other) const { return !(*this == other); }

    friend Complex operator+(double d, const Complex& c) {
        return Complex(d + c.re, c.im);
    }

    friend Complex operator-(double d, const Complex& c) {
        return Complex(d - c.re, -c.im);
    }

    friend Complex operator*(double d, const Complex& c) {
        return Complex(d * c.re, d * c.im);
    }

    friend Complex operator/(double d, const Complex& c) {
        double denom = c.re * c.re + c.im * c.im;
        return Complex((d * c.re) / denom, (-d * c.im) / denom);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.re;
        if (c.im >= 0) os << " + " << c.im << "i";
        else           os << " - " << -c.im << "i";
        return os;
    }
};

int main() {
    double re1, im1, re2, im2;

    std::cout << "Introdu partea reala a primului numar complex: ";
    std::cin >> re1;
    std::cout << "Introdu partea imaginara a primului numar complex: ";
    std::cin >> im1;

    std::cout << "Introdu partea reala a celui de-al doilea numar complex: ";
    std::cin >> re2;
    std::cout << "Introdu partea imaginara a celui de-al doilea numar complex: ";
    std::cin >> im2;

    Complex a(re1, im1);
    Complex b(re2, im2);

    Complex c = a + b;
    Complex d = a - b;
    Complex e = a * b;
    Complex f = a / b;
    Complex conj = a.conjugate();
    double mod = a.modulus();

    std::cout << "\na = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << c << "\n";
    std::cout << "a - b = " << d << "\n";
    std::cout << "a * b = " << e << "\n";
    std::cout << "a / b = " << f << "\n";
    std::cout << "Conjugatul lui a = " << conj << "\n";
    std::cout << "|a| = " << mod << "\n";
    std::cout << "a == b ? " << ((a == b) ? "true" : "false") << "\n";

    return 0;
}
