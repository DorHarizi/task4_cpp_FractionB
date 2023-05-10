#include "doctest.h"
#include "sources/Fraction.hpp"
#include <stdexcept>
#include <sstream>

using namespace std;
using namespace ariel;

TEST_CASE("Constructors"){
    Fraction num1;
    Fraction num2(2, 3);
    Fraction num3(2.5);

    CHECK(num1.getNumerator() == 0);
    CHECK(num1.getDenominator() == 1);

    CHECK(num2.getNumerator() == 2);
    CHECK(num2.getDenominator() == 3);

    CHECK(num3.getNumerator() == 5);
    CHECK(num3.getDenominator() == 2);
}

TEST_CASE("Copy fuction"){
    Fraction num1(2, 3);
    Fraction num2(num1);
    CHECK(num1.getNumerator() == num2.getNumerator());
    CHECK(num1.getDenominator() == num2.getDenominator());
}

TEST_CASE("Getters"){
    Fraction num1(5, 2);
    Fraction num2(7, 3);
    Fraction num3(20, 5);

    CHECK(num1.getNumerator() == 5);
    CHECK(num1.getDenominator() == 2);

    CHECK(num2.getNumerator() == 7);
    CHECK(num2.getDenominator() == 3);

    CHECK(num3.getNumerator() == 4);
    CHECK(num3.getDenominator() == 1);
}

TEST_CASE("Binary operators"){
    SUBCASE("operator: +"){
        Fraction num1(5, 2);
        Fraction num2(7, 3);
        Fraction tmp1 = num1 + num2;
        Fraction tmp2(29, 6);
        CHECK(tmp1 == tmp2);

        tmp1 = tmp1 + float(3.5);
        tmp2 = Fraction(25, 3);
        CHECK(tmp1 == tmp2);

        tmp1 = float(9.3) + tmp1;
        tmp2 = Fraction(529, 30);
        CHECK(tmp1 == tmp2);
    }

    SUBCASE("operator: -"){
        Fraction num1(5, 2);
        Fraction num2(7, 3);
        Fraction tmp1 = num1 - num2;
        Fraction tmp2(1, 6);
        CHECK(tmp1 == tmp2);

        tmp1 = tmp1 - float(3.5);
        tmp2 = Fraction(10, -3);
        CHECK(tmp1 == tmp2);

        tmp1 = float(9.3) - tmp1;
        tmp2 = Fraction(379, 30);
        CHECK(tmp1 == tmp2);
    }

    SUBCASE("operator: *"){
        Fraction num1(5, 2);
        Fraction num2(7, 3);
        Fraction tmp1 = num1 * num2;
        Fraction tmp2(35, 6);
        CHECK(tmp1 == tmp2);

        tmp1 = tmp1 * float(3.5);
        tmp2 = Fraction(245, 12);
        CHECK(tmp1 == tmp2);

        tmp1 = float(9.3) * tmp1;
        tmp2 = Fraction(1519, 8);
        CHECK(tmp1 == tmp2);
    }

    SUBCASE("operator: /"){
        Fraction num1(5, 2);
        Fraction num2(7, 3);
        Fraction tmp1 = num1 / num2;
        Fraction tmp2(15, 14);
        CHECK(tmp1 == tmp2);

        tmp1 = tmp1 / float(3.5);
        tmp2 = Fraction(15, 49);
        CHECK(tmp1 == tmp2);

        tmp1 = float(9.3) / tmp1;
        tmp2 = Fraction(1519, 50);
        CHECK(tmp1 == tmp2);
    }

    SUBCASE("operator: ++(int)"){
        Fraction num1(5, 2);
        Fraction num2(7, 3);
        Fraction num3 = ++num1;
        Fraction num4 = ++num2;

        CHECK(num1.getNumerator() == 7);
        CHECK(num1.getDenominator() == 2);
       
        CHECK(num3.getNumerator() == 7);
        CHECK(num3.getDenominator() == 2);

        CHECK(num2.getNumerator() == 10);
        CHECK(num2.getDenominator() == 3);

        CHECK(num4.getNumerator() == 10);
        CHECK(num4.getDenominator() == 3);
    }

    SUBCASE("operator: ++()"){
        Fraction num1(5, 2);
        Fraction num2(7, 3);
        Fraction num3 = num1++;
        Fraction num4 = num2++;

        CHECK(num1.getNumerator() == 7);
        CHECK(num1.getDenominator() == 2);
       
        CHECK(num3.getNumerator() == 5);
        CHECK(num3.getDenominator() == 2);

        CHECK(num2.getNumerator() == 10);
        CHECK(num2.getDenominator() == 3);

        CHECK(num4.getNumerator() == 7);
        CHECK(num4.getDenominator() == 3);
    }

    SUBCASE("operator: --(int)"){
        Fraction num1(5, 2);
        Fraction num2(7, 3);
        Fraction num3 = --num1;
        Fraction num4 = --num2;

        CHECK(num1.getNumerator() == 3);
        CHECK(num1.getDenominator() == 2);
       
        CHECK(num3.getNumerator() == 3);
        CHECK(num3.getDenominator() == 2);

        CHECK(num2.getNumerator() == 4);
        CHECK(num2.getDenominator() == 3);

        CHECK(num4.getNumerator() == 4);
        CHECK(num4.getDenominator() == 3);
    }

    SUBCASE("operator: --()"){
        Fraction num1(5, 2);
        Fraction num2(7, 3);
        Fraction num3 = num1--;
        Fraction num4 = num2--;

        CHECK(num1.getNumerator() == 3);
        CHECK(num1.getDenominator() == 2);
       
        CHECK(num3.getNumerator() == 5);
        CHECK(num3.getDenominator() == 2);

        CHECK(num2.getNumerator() == 4);
        CHECK(num2.getDenominator() == 3);

        CHECK(num4.getNumerator() == 7);
        CHECK(num4.getDenominator() == 3);
    }
}

TEST_CASE("Comparison operators"){
    SUBCASE("operator: =="){
        Fraction num1(10, 2);
        Fraction num2(5, 1);
        Fraction tmp1(29, 6);
        Fraction tmp2(29, 6);

        CHECK(tmp1 == tmp2);
        CHECK(num1 == num2);
    }

    SUBCASE("operator: !="){
        Fraction num1(11, 2);
        Fraction num2(5, 1);
        Fraction num3(22, 6);
        Fraction num4(297, 6);

        CHECK(num1 != num2);
        CHECK(num1 != num3);
        CHECK(num1 != num4);

        CHECK(num2 != num1);
        CHECK(num2 != num3);
        CHECK(num2 != num4);

        CHECK(num3 != num2);
        CHECK(num3 != num1);
        CHECK(num3 != num4);

        CHECK(num4 != num2);
        CHECK(num4 != num3);
        CHECK(num4 != num1);
    }

    SUBCASE("operator: <"){
        Fraction num1(11, 2);
        Fraction num2(5, 1);
        Fraction num3(22, 6);
        Fraction num4(297, 6);

        CHECK(num2 < num1);
        CHECK(num3 < num1);
        CHECK(num1 < num4);
        CHECK(num3 < num2);
        CHECK(num2 < num4);
        CHECK(num3 < num4);

        CHECK(float(4.6) < num1);
        CHECK(float(4.9) < num2);
        CHECK(float(2) < num3);
        CHECK(float(41.8) < num4);

        CHECK(num1 < float(1000));
        CHECK(num2 < float(1000));
        CHECK(num3 < float(1000));
        CHECK(num4 < float(1000));
    }

    SUBCASE("operator: >"){
        Fraction num1(11, 2);
        Fraction num2(5, 1);
        Fraction num3(22, 6);
        Fraction num4(297, 6);

        CHECK(num1 > num2);
        CHECK(num1 > num3);
        CHECK(num4 > num1);
        CHECK(num2 > num3);
        CHECK(num4 > num2);
        CHECK(num4 > num3);

        CHECK(float(1000) > num1);
        CHECK(float(1000) > num2);
        CHECK(float(1000) > num3);
        CHECK(float(1000) > num4);

        CHECK(num1 > float(4.6));
        CHECK(num2 > float(4.9));
        CHECK(num3 > float(2));
        CHECK(num4 > float(41.8));
    }

    SUBCASE("operator: <="){
        Fraction num1(11, 2);
        Fraction num2(5, 1);
        Fraction num3(22, 6);
        Fraction num4(297, 6);

        CHECK(num2 <= num1);
        CHECK(num3 <= num1);
        CHECK(num1 <= num4);
        CHECK(num3 <= num2);
        CHECK(num2 <= num4);
        CHECK(num3 <= num4);

        CHECK(float(4.6) <= num1);
        CHECK(float(5) <= num2);
        CHECK(float(2) <= num3);
        CHECK(float(41.8) <= num4);

        CHECK(num1 <= float(1000));
        CHECK(num2 <= float(5));
        CHECK(num3 <= float(1000));
        CHECK(num4 <= float(1000));
    }

    SUBCASE("operator: >="){
        Fraction num1(11, 2);
        Fraction num2(5, 1);
        Fraction num3(22, 6);
        Fraction num4(297, 6);

        CHECK(num1 >= num2);
        CHECK(num1 >= num3);
        CHECK(num4 >= num1);
        CHECK(num2 >= num3);
        CHECK(num4 >= num2);
        CHECK(num4 >= num3);

        CHECK(float(1000) >= num1);
        CHECK(float(5) >= num2);
        CHECK(float(1000) >= num3);
        CHECK(float(1000) >= num4);

        CHECK(num1 >= float(4.6));
        CHECK(num2 >= float(5));
        CHECK(num3 >= float(2));
        CHECK(num4 >= float(41.8));
    }
}

TEST_CASE("I/O operators"){
    SUBCASE("operator: <<")
    {
        Fraction num1(2, 3);
        Fraction num2;
        std::ostringstream output1;
        std::ostringstream output2;
        output1 << num1;
        output2 << num2;
        // CHECK_EQ(output1.str(), "2/3");
        // CHECK_EQ(output2.str(), "0/1");
    }
}