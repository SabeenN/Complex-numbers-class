#ifndef COMPLEX

#include <cmath>
#include <numeric>
class Complex {
public:
   Complex ():r(0),i(0) {} //default
   Complex (const Complex &rhs) { } // copy
   Complex (double r):r(r),i(0) {} // Complex(real)
   constexpr Complex(double r, double i):r(r),i(i) {}//Complex(real,imag)
   long double imag() const;
   long double real() const;
   Complex& operator= (const Complex& src);
   Complex& operator*= (const Complex& src);
   Complex& operator/= (const Complex& src);
   Complex& operator-= (const Complex& src);
   Complex& operator+= (const Complex& src);
 private:
   double r;
   double i;
};
Complex operator+(const Complex& left, const Complex& right);
Complex operator-(const Complex& left, const Complex& right);
Complex operator*(const Complex& left, const Complex& right);
Complex operator/(const Complex& left, const Complex& right);
std::ostream& operator<< (std::ostream& os, const Complex& c);
std::istream& operator>> (std::istream& is, Complex& c);
bool operator==(const Complex& left, const Complex& right);
bool operator!=(const Complex& left, const Complex& right);
long double abs(const Complex& arg);
long double imag(const Complex& arg);
long double real(const Complex& arg);

constexpr Complex operator""_i(long double arg){
  return Complex(0,arg);
}
constexpr Complex operator""_i(unsigned long long arg){
  return Complex(0,arg);
}
#endif
