//
// Created by Martino Nikolovski on 6/28/16.
//

#ifndef POLYNOMIALARITHMETICREDUX_POLYNOMIAL_H
#define POLYNOMIALARITHMETICREDUX_POLYNOMIAL_H

#include <map>
using namespace std;

class Polynomial{
private:
    std::map<int,int> polynomial;
public:
    Polynomial();
    void insert(int coefficient, int power);
    Polynomial operator+(const Polynomial& poly);
    Polynomial operator-(const Polynomial& poly);
    Polynomial operator*(const Polynomial& poly);
    int& operator[](int power);
    friend ostream& operator<<(ostream& os, const Polynomial& poly);
};

#endif //POLYNOMIALARITHMETICREDUX_POLYNOMIAL_H
