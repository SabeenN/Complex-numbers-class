#include <iostream>
#include "complex.h"
#include <string>
#include <cstdlib>

Complex& Complex::operator= (const Complex& src) { //std::cout << "the assignment operator" << std::endl;
     this->i=src.i;
     this->r=src.r;
     return *this;
   }
Complex& Complex::operator+= (const Complex& src){
     long double temp =this->r;
     this-> r = (temp + src.r);
     temp=this->i;
     this-> i = (temp + src.i);
     return *this;
   }
Complex& Complex::operator-= (const Complex& src){
    long double temp =this->r;
    this-> r = (temp - src.r);
    temp=this->i;
    this-> i = (temp - src.i);
    return *this;
   }
Complex& Complex::operator/= (const Complex& src){
     long double tempi=this->i;
     long double tempr=this->r;
     this-> r = (tempi*src.i + tempr*src.r)/((src.i*src.i)+(src.r*src.r));
     this-> i = (src.r*tempi - tempr*src.i)/((src.i*src.i)+(src.r*src.r));
     return *this;
   }
Complex& Complex::operator*= (const Complex& src){
     long double tempi=this->i;
     long double tempr=this->r;
     long double resulti=0;
     long double resultr=0;
     resultr = (tempr*src.r-tempi*src.i);
     resulti = (src.r*tempi + tempr*src.i);
     this->r=resultr;
     this->i=resulti;
     return *this;
}

long double Complex::imag() const{
  return this->i;
}

long double Complex::real() const{
  return this->r;
}

Complex operator+(const Complex& left, const Complex& right){
  Complex sum;
  sum += left;
  sum += right;
  return sum;
}
Complex operator-(const Complex& left, const Complex& right){
  Complex dif;
  dif += left;
  dif -= right;
  return dif;
}
Complex operator*(const Complex& left, const Complex& right){
  Complex prod;
  prod += left;
  prod *= right;
  return prod;
}
Complex operator/(const Complex& left, const Complex& right){
  Complex ratio;
  ratio += left;
  ratio /= right;
  return ratio;
}
std::ostream& operator<< (std::ostream& os, const Complex& c){
  os << "(" << real(c) <<","<< imag(c) << ")";
  return os;
}

//The supported formats are: real, (real) and (real,imaginary)
std::istream& operator>>(std::istream& is, Complex & c){
   std::string jr;
   std::string ji;
   is >> ji;
   jr = ji;
   if (jr.length()==5){
     unsigned int ind=0;
     jr=jr[1];
     ji=ji[3];
     long realpt=std::stol(jr, &ind, 10);
     long imagpt=std::stol(ji, &ind, 10);
     Complex k(realpt,imagpt);
     c=k;
  }else if (jr.length()==3){
    jr=jr[1];
    unsigned int ind=0;
    long realpt=std::stol(jr, &ind, 10);
    Complex k(realpt);
    c=k;
  }else if (jr.length()==1){
    jr=jr[0];
    unsigned int ind=0;
    long realpt=std::stol(jr, &ind, 10);
    Complex k(realpt);
    c=k;
  }
  return is;
}

bool operator==(const Complex& left, const Complex& right){
  if ((real(left)==real(right))&&(imag(left)==imag(right))){
    return true;
  }else{
    return false;
  }
}

bool operator!=(const Complex& left, const Complex& right){
  if ((real(left)==real(right))&&(imag(left)==imag(right))){
    return false;
  }else{
    return true;
  }
}

long double abs(const Complex& arg){
  return std::sqrt(real(arg)*real(arg) + imag(arg)*imag(arg));
}

long double imag(const Complex& arg){
  return arg.imag();
}
long double real(const Complex& arg){
  return arg.real();
}
