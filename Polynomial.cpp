//
// Created by Martino Nikolovski on 6/28/16.
//

#include <iostream>
#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial() { }

void Polynomial::insert(int coefficient, int power) {
    if(polynomial[power]) polynomial[power]+=coefficient;
    else polynomial[power]=coefficient;
}

Polynomial Polynomial::operator+(const Polynomial &poly) {
    Polynomial sum;
    for(auto this_itr = polynomial.begin(); this_itr!=polynomial.end(); ++this_itr){
        if(!sum[this_itr->first]) sum[this_itr->first]=this_itr->second;
    }
    for(auto poly_itr = poly.polynomial.begin(); poly_itr!=poly.polynomial.end(); ++poly_itr){
        if(!sum[poly_itr->first])sum[poly_itr->first]=poly_itr->second;
        else sum[poly_itr->first]+=poly_itr->second;
    }
    return sum;
}

Polynomial Polynomial::operator-(const Polynomial &poly) {
    Polynomial diff;
    for(auto this_itr = polynomial.begin(); this_itr!=polynomial.end(); ++this_itr){
        if(!diff[this_itr->first]) diff[this_itr->first]=this_itr->second;
    }
    for(auto poly_itr = poly.polynomial.begin(); poly_itr!=poly.polynomial.end(); ++poly_itr){
        if(!diff[poly_itr->first])diff[poly_itr->first]=poly_itr->second;
        else diff[poly_itr->first]-=poly_itr->second;
    }
    return diff;
}

Polynomial Polynomial::operator*(const Polynomial &poly) {
    Polynomial mul;
    for(auto this_itr = polynomial.begin(); this_itr!=polynomial.end(); ++this_itr){
        for(auto poly_itr = poly.polynomial.begin(); poly_itr!=poly.polynomial.end(); ++poly_itr){
            mul.insert(this_itr->second*poly_itr->second,this_itr->first+poly_itr->first);
        }
    }
    return mul;
}

int& Polynomial::operator[](int power){
    return polynomial[power];
}



