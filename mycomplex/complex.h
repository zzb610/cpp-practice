#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class complex;

complex &__doapl(complex *, const complex &);
complex &__doami(complex *, const complex &);
complex &__doaml(complex *, const complex &);

double real(const complex &);
double imag(const complex &);

class complex
{
public:
    complex(double r, double i) : re(r), im(i) {}

    complex &operator+=(const complex &);
    complex &operator-=(const complex &);
    complex &operator*=(const complex &);

    double real() const { return re; };
    double imag() const { return im; }

private:
    double re;
    double im;
    friend complex &__doapl(complex *, const complex &);
    friend complex &__doami(complex *, const complex &);
    friend complex &__doaml(complex *, const complex &);
};
// local var 函数的返回值不能 pass by ref
inline complex operator+(const complex &x, const complex &y)
{
    return complex(real(x) + real(y), imag(x) + imag(y));
}
inline complex operator+(const complex &x, double y)
{
    return complex(real(x) + y, imag(x));
}
inline complex operator+(double x, const complex &y)
{
    return complex(x + real(y), imag(y));
}
inline complex operator+(const complex &x)
{
    return x;
}
inline complex operator-(const complex &x, const complex &y)
{
    return complex(real(x) - real(y), imag(x) - imag(y));
}
inline complex operator-(const complex &x, double y)
{
    return complex(real(x) - y, imag(x));
}
inline complex operator-(double x, const complex &y)
{
    return complex(x - real(y), imag(y));
}
inline complex operator-(const complex &x)
{
    return complex(-real(x), -imag(x));
}
inline complex operator*(const complex &x, const complex &y)
{
    return complex(real(x) * real(y) - imag(x) * imag(y), real(x) * imag(y) + real(y) * imag(x));
}
inline complex operator*(const complex &x, double y)
{
    return complex(real(x) * y, imag(x) * y);
}
inline complex operator*(double x, const complex &y)
{
    return complex(x * real(y), x * imag(y));
}
inline complex operator/(const complex &x, double y)
{
    return complex(real(x) / y, imag(x) / y);
}

inline bool operator==(const complex &x, const complex &y)
{
    return (real(x) == real(y)) && (imag(x) == imag(y));
}
inline bool operator==(const complex &x, double y)
{
    return (real(x) == y) && (imag(x) == 0);
}
inline bool operator==(double x, const complex &y)
{
    return (x == real(y)) && (0 == imag(y));
}

inline bool operator!=(const complex &x, const complex &y)
{
    return (real(x) != real(y)) || (imag(x) != imag(y));
}
inline bool operator!=(const complex &x, double y)
{
    return (real(x) != y) || (imag(x) != 0);
}
inline bool operator!=(double x, const complex &y)
{
    return (x != real(y)) || (0 != imag(y));
}

#include <cmath>

inline complex polar(double r, double t)
{
    return complex(r * cos(t), r * sin(t));
}
// 共轭复数
inline complex conj(const complex &x)
{
    return complex(real(x), -imag(x));
}

inline double norm(const complex &x)
{
    return real(x) * real(x) + imag(x) * imag(x);
}

complex &complex::operator+=(const complex &r)
{
    return __doapl(this, r);
}
complex &complex::operator-=(const complex &r)
{
    return __doami(this, r);
}
complex &complex::operator*=(const complex &r)
{
    return __doaml(this, r);
}
inline complex &__doapl(complex *ths, const complex &r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex &__doami(complex *ths, const complex &r)
{
    ths->re -= r.re;
    ths->im -= r.im;
    return *ths;
}

inline complex &__doaml(complex *ths, const complex &r)
{
    ths->re *= r.re;
    ths->im *= r.im;
    return *ths;
}

inline double real(const complex &x)
{
    return x.real();
}
inline double imag(const complex &x)
{
    return x.imag();
}

#endif // __MYCOMPLEX__
