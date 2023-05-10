#include "Fraction.hpp"
#include<algorithm>
#include <cmath>
#include<limits.h>

using namespace std;
using namespace ariel;

int MaxNum =  INT_MAX;
int MinNum = INT_MIN;

// constructors 
Fraction::Fraction(){
    this->numerator = 0;
    this->denominator = 1;
    // cout<<"crate new Fraction()\n"<<endl;
}

Fraction::Fraction(float num){
    int numerator = num *1000;
    int gcd = __gcd(numerator, 1000);
    this->numerator = numerator / gcd;
    this->denominator = 1000 / gcd;
    // cout<<"crate new Fraction("<< num << ")->("<<this->numerator <<","<<this->denominator<<")\n"<<endl;
}

Fraction::Fraction(int numerator, int denominator){
    if (denominator == 0){
            throw invalid_argument("denominator cannot be zero, please try again");
    }
    int gcd = abs(__gcd(numerator, denominator));
    if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator < 0)){
        this->numerator = -numerator / gcd;
        this->denominator = - denominator / gcd;
    }else{
        this->numerator = numerator / gcd;
        this->denominator = denominator / gcd;
    }
    // cout<<"crate new Fraction("<< numerator<<","<< denominator << ")->("<<this->numerator <<","<<this->denominator<<")\n"<<endl;
}

// Getters 
int Fraction::getNumerator()const{
    return this->numerator;
}

int Fraction::getDenominator()const{
    return this->denominator;
}

// binary oprators
Fraction Fraction::operator+(const Fraction &other)const{
    long long new_numerator = static_cast<long>(this->numerator * other.denominator) + static_cast<long>(other.numerator * this->denominator);
    long long new_denominator = static_cast<long>(this->denominator * other.denominator);
    int new_gcd = __gcd(new_numerator, new_denominator);
    if((new_numerator < numeric_limits<int>::min()) || (new_denominator < numeric_limits<int>::min())||
       (new_numerator > numeric_limits<int>::max()) || (new_denominator > numeric_limits<int>::max())){
            throw overflow_error("Overflow haopened");
    }else{
        long long result = static_cast<long>(new_numerator / new_denominator);
        if((result < numeric_limits<int>::min()) || (result > numeric_limits<int>::max())){
            throw overflow_error("Overflow haopened");
        }
    }
    int a = new_numerator;
    int b = new_denominator;
    return Fraction(a / new_gcd, b / new_gcd);
}

Fraction Fraction::operator-(const Fraction &other) const{
    long long new_numerator = static_cast<long>(this->numerator * other.denominator) - static_cast<long>(other.numerator * this->denominator);
    long long new_denominator = static_cast<long>(this->denominator * other.denominator);
    int new_gcd = __gcd(new_numerator, new_denominator);
    if((new_numerator < numeric_limits<int>::min()) || (new_denominator < numeric_limits<int>::min())||
       (new_numerator > numeric_limits<int>::max()) || (new_denominator > numeric_limits<int>::max())){
            throw overflow_error("Overflow haopened");
    }else{
        long long result = static_cast<long>(new_numerator / new_denominator);
        if((result < numeric_limits<int>::min()) || (result > numeric_limits<int>::max())){
            throw overflow_error("Overflow haopened");
        }
    }
    int a = new_numerator;
    int b = new_denominator;
    return Fraction(a / new_gcd, b / new_gcd);
}

Fraction Fraction::operator/(const Fraction &other) const{
    if(other.numerator != 0){
        long long new_numerator = static_cast<long>(this->numerator) * static_cast<long>(other.denominator);
        long long new_denominator = static_cast<long>(other.numerator) * static_cast<long>(this->denominator);
        int new_gcd = __gcd(new_numerator, new_denominator);
        if((new_numerator < numeric_limits<int>::min()) || (new_denominator < numeric_limits<int>::min())||
        (new_numerator > numeric_limits<int>::max()) || (new_denominator > numeric_limits<int>::max())){
                throw overflow_error("Overflow haopened");
        }else{
            long long result = static_cast<long>(new_numerator / new_denominator);
            if((result < numeric_limits<int>::min()) || (result > numeric_limits<int>::max())){
                throw overflow_error("Overflow haopened");
            }
        }
        int a = new_numerator;
        int b = new_denominator;
        return Fraction(a / new_gcd, b / new_gcd);
    }
    else{
        throw runtime_error("can't divide by zero, please try again with anthor Fraction");
    }   
}

Fraction Fraction::operator*(const Fraction &other) const{
    long long new_numerator = static_cast<long>(this->numerator) * static_cast<long>(other.numerator);
    long long new_denominator = static_cast<long>(other.denominator) * static_cast<long>(this->denominator);
    int new_gcd = __gcd(new_numerator, new_denominator);
    if((new_numerator < numeric_limits<int>::min()) || (new_denominator < numeric_limits<int>::min())||
       (new_numerator > numeric_limits<int>::max()) || (new_denominator > numeric_limits<int>::max())){
            throw overflow_error("Overflow haopened");
    }else{
        long long result = static_cast<long>(new_numerator / new_denominator);
        if((result < numeric_limits<int>::min()) || (result > numeric_limits<int>::max())){
            throw overflow_error("Overflow haopened");
        }
    }
    int a = new_numerator;
    int b = new_denominator;
    return Fraction(a / new_gcd, b / new_gcd);
    
}

Fraction ariel::operator+(const Fraction &other, const float num){
    Fraction tmp(num);
    return Fraction(other + tmp);
}

Fraction ariel::operator-(const Fraction &other, const float num){
    Fraction tmp(num);
    return Fraction(other - tmp);
}

Fraction ariel::operator/(const Fraction &other, const float num){
    Fraction tmp(num);
    return Fraction(other / tmp);
}

Fraction ariel::operator*(const Fraction &other, const float num){
    Fraction tmp(num);
    return Fraction(other * tmp);
}

Fraction ariel::operator+(const float num, const Fraction &other){
    Fraction tmp(num);
    return Fraction(tmp + other);
}

Fraction ariel::operator-(const float num, const Fraction &other){
    Fraction tmp(num);
    return Fraction(tmp - other);
}

Fraction ariel::operator/(const float num, const Fraction &other){
    Fraction tmp(num);
    return Fraction(tmp / other);
}

Fraction ariel::operator*(const float num, const Fraction &other){
    Fraction tmp(num);
    return Fraction(tmp * other);
}

// operators adds/substracts 1 pre and post fix
Fraction &Fraction::operator++(){
    this->numerator += this->denominator;
    return *this;
} 

const Fraction Fraction::operator++(int){
    Fraction result(*this);
    ++(*this);
    return result;
} 

Fraction &Fraction::operator--(){
    numerator -= denominator;
    return *this;
}  

const Fraction Fraction::operator--(int){
    Fraction result(*this);
    --(*this);
    return result;
}

// comparison operators
bool Fraction::operator>(const Fraction &other) const{
    return ((this->numerator * other.denominator) > (other.numerator * this->denominator));
}

bool Fraction::operator<(const Fraction &other) const{
    return ((this->numerator * other.denominator) < (other.numerator * this->denominator));
}

bool Fraction::operator>=(const Fraction &other) const{
    return ((this->numerator * other.denominator) >= (other.numerator * this->denominator));
}

bool Fraction::operator<=(const Fraction &other) const{
    return ((this->numerator * other.denominator) <= (other.numerator * this->denominator));
}

bool ariel::operator>(float num, const Fraction &other){
    Fraction tmp(num);
    return tmp > other;
}

bool ariel::operator<(float num, const Fraction &other){
    Fraction tmp(num);
    return tmp < other;
}

bool ariel::operator>= (float num, const Fraction &other){
    Fraction tmp(num);
    return tmp >= other;
}

bool ariel::operator<=(float num, const Fraction &other){
    Fraction tmp(num);
    return tmp <= other;
}

bool ariel::operator>(const Fraction &other, float num){
    Fraction tmp(num);
    return other > tmp;
}    

bool ariel::operator<(const Fraction &other, float num){
    Fraction tmp(num);
    return other < tmp;
}

bool ariel::operator>=(const Fraction &other, float num){
    Fraction tmp(num);
    return other >= tmp;
}

bool ariel::operator<=(const Fraction &other, float num){
    Fraction tmp(num);
    return other <= tmp;
}

bool Fraction::operator==(const Fraction &other) const{
    if((this->numerator == 0) && (other.numerator == 0)){
        return true;
    }else{
        bool b = ((this->getNumerator() == other.getNumerator()) 
            && (this->getDenominator() == other.getDenominator()));
        return b;
    }
}

bool Fraction::operator!=(const Fraction &other) const{
    return !(*this == other);
}

// I/O operators
ostream &ariel::operator<<(ostream& output, const Fraction& other){
     output << other.getNumerator() << "/" << other.getDenominator();
    return output;
}

istream &ariel::operator>> (istream &input, Fraction &other){
    int numerator;
    int denominator;
    int seperator;

    input >> numerator;
    if(input.fail()){
        throw runtime_error("Error in reading input");
    }

    input >> seperator;
    if((input.fail()) || (seperator == 0)){
        throw runtime_error("Error in reading input");
    }

    if(seperator == '/'){
        input >> denominator;
        if((input.fail()) || (denominator == 0)){
            throw runtime_error("Error in reading input");
        }
        Fraction tmp(numerator, denominator);
        other.numerator = tmp.getNumerator();
        other.denominator = tmp.getDenominator();
    }else{
        Fraction tmp(numerator, seperator);
        other.numerator = tmp.getNumerator();
        other.denominator = tmp.getDenominator();
    }
    return input;
}