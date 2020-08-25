#include <cxxtest/TestSuite.h>


#include "complex.h"
#include <climits>
#include <sstream>
class MyTestSuite : public CxxTest::TestSuite {
  public:
    void test1 () {
      Complex x= 1 + 9_i;
      TS_ASSERT_EQUALS(x.real(), 1);
      TS_ASSERT_EQUALS(x.imag(), 9);
    }

    void test2() {
      Complex x = 7 - 2_i;
      Complex y(6, 2);
      Complex z = x + y + y + x;
      TS_ASSERT_EQUALS(z.real(),26);
      TS_ASSERT_EQUALS(z.imag(),0);
    }

    void test3(){
      Complex k = 3 + 5_i;  //3,5
      k -= 5 + 1_i * Complex(5, 3); //+1
      Complex o = Complex(6, 6)/ 6 ; //1
      k *= o;
      TS_ASSERT_EQUALS(k.real(),1);
      TS_ASSERT_EQUALS(k.imag(),1);
    }
    void test4() {
      Complex y= 1 + 7_i;
      Complex t = 10 - 7_i*y;
      t += y -= y;

      TS_ASSERT_EQUALS(t.real(),59);
      TS_ASSERT_EQUALS(t.imag(),-7);
     }
     void test5() {
       Complex x = 7 - 3_i;
       x *= x;
       long double absx = abs(x);
       Complex y;
       y = x;
       y /= 2_i;
       long double absy = abs(y);
       TS_ASSERT_EQUALS(x.real(),40);
       TS_ASSERT_EQUALS(x.imag(),-42);
       TS_ASSERT_EQUALS(absx,58);
       TS_ASSERT_EQUALS(y.real(),-21);
       TS_ASSERT_EQUALS(y.imag(),-20);
       TS_ASSERT_EQUALS(absy,29);
       bool val = x==y;
       bool val2 = x!=y;
       TS_ASSERT_EQUALS(val, 0);
       TS_ASSERT_EQUALS(val2,1);
     }
     void test6() {
       Complex y(2,2);
       Complex j= y+(y-y)+(y*y)+(y/2);
       TS_ASSERT_EQUALS(j.real(),3);
       TS_ASSERT_EQUALS(j.imag(),11);
       Complex k;
       k += y += y += y;
       TS_ASSERT_EQUALS(k.real(),8);
       TS_ASSERT_EQUALS(k.imag(),8);
     }

     void test7(){
       Complex y(INT_MAX,INT_MAX);
       Complex u(INT_MIN,INT_MIN);
       Complex t= y+u;
       TS_ASSERT_EQUALS(t.real(),-1);
       TS_ASSERT_EQUALS(t.imag(),-1);
       long double absy=abs(y);
       TS_ASSERT_DIFFERS(y,3037000498.56);
     }

     //void test8(){
    //  Complex y(INT_MAX,INT_MAX);
      // y /= 0;
      // TS_ASSERT_IS_NAN(y.real());
  //     TS_ASSERT_IS_NAN(y.imag());
  //   }

  void test9() {
    Complex c;
    std::cout << "Enter a complex number. The supported formats are real, (real) and (real,imaginary)" <<std::endl;
    std::cin >> c;
    std::cout<< c;
    TS_ASSERT_EQUALS(c.real(),5);
    TS_ASSERT_EQUALS(c.imag(),4);
    }
};

//generera testfilen /info/DD2387/labs/cxxtest/cxxtestgen.py --error-printer -o simple_testrunner.cpp simple.cxxtest.cpp
//kompilera programmet g++ -std=c++11 -g -Wall -Wunused-but-set-variable -c complex.cpp -o complex.out
//koppla ihop testfilen och programmet:g++ -std=c++11 -o simple_test.out -I /info/DD2387/labs/cxxtest/ simple_testrunner.cpp complex.out
