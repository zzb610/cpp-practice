#include <iostream>

class Fraction
{
public:
    Fraction(int num, int den = 1) : m_numberator(num), m_denominator(den) {}

    operator double() const
    {
        return (double)(m_numberator) / m_denominator;
    }

private:
    int m_numberator;
    int m_denominator;
};

int main(int, char **)
{
    Fraction f(3, 5);
    double d = 4 + f;
    std::cout << d << std::endl;
}
