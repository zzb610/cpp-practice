#include <iostream>
class Fraction
{
public:
    Fraction(int num, int den = 1) : m_numberator(num), m_denominator(den) {}
    Fraction operator+(const Fraction& f)
    {
        // not really
        return Fraction(0);
    }
private:
    int m_numberator;
    int m_denominator;
};
int main(int, char **)
{
    Fraction f(3,5);
    Fraction d2 = f+4;
}
