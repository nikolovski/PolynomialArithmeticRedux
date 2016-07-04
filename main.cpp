#include <iostream>
#include <fstream>
#include <sstream>
#include "Polynomial.h"

using namespace std;
int count_polynomials(string);
void print_header();
int main(int argc,char *argv[]) {
    if(argc!=2) {
        cout<<"Please enter file as an input parameter containing polynomials. It is recommended that the full directory"
                "+ filename + extension"<<endl;
        exit(1);
    }
    string filename= argv[1];
    //Counting the number of polynomials
    int poly_count= count_polynomials(filename);

    //Initializing array of polynomials
    Polynomial *polynomials = new Polynomial[poly_count];
    ifstream infile (filename);
    string current_polynomial;
    int poly_iterator=0;

    //Adding all the polynomials from file to the array of polynomials
    while(getline(infile,current_polynomial)) {
        stringstream ss(current_polynomial);
        Polynomial poly;
        int current_coefficient, current_power;
        while(ss>>current_coefficient>>current_power){
            poly.insert(current_coefficient,current_power);
        }
        polynomials[poly_iterator]=poly;
        poly_iterator++;
    }
    infile.close();

    //Printing polynomials
    print_header();
    for (int i = 0; i < poly_count; ++i) {
        cout<<"Polynomial "<<(i+1)<<":"<<endl;
        cout<<polynomials[i];
        cout<<endl<<endl;
    }

    //Polynomial operations
    for (int j = 0; j < poly_count; j+=2) {
        //addition
        cout<<"Polynomial "<<(j+1)<<" + Polynomial "<<(j+2)<<":"<<endl;
        cout<<(polynomials[j]+polynomials[j+1]);
        cout<<endl<<endl;
        //subtraction
        cout<<"Polynomial "<<(j+1)<<" - Polynomial "<<(j+2)<<":"<<endl;
        cout<<(polynomials[j]-polynomials[j+1]);
        cout<<endl<<endl;
        //multiplication
        cout<<"Polynomial "<<(j+1)<<" * Polynomial "<<(j+2)<<":"<<endl;
        cout<<(polynomials[j]*polynomials[j+1]);
        cout<<endl<<endl;
    }
    return 0;
}
//Overloaded operator<<
ostream& operator<<(ostream &os, const Polynomial &poly) {
    //reverse iteration starting from the larger key value
    for (auto itr = poly.polynomial.rbegin(); itr!=poly.polynomial.rend() ; ++itr) {
        if(itr->second>0) os<<"+";
        if(itr->second==0);
        else if(itr->first==0) os<<itr->second<<" ";
        else os<<itr->second<<"x^"<<itr->first<<" ";
    }
    return os;
}

//Counting polynomials
int count_polynomials(string file){
    int count=0;
    ifstream infile;
    infile.open(file);
    string line;
    while(getline(infile,line)){
        count++;
    }
    infile.close();
    return count;
}

void print_header(){
    cout<<"Polynomial Arithmetic Redux provided by\n"
            "          .--.  ,---.  _______ ,-..-. .-. .---.\n"
            "|\\    /| / /\\ \\ | .-.\\|__   __||(||  \\| |/ .-. )\n"
            "|(\\  / |/ /__\\ \\| `-'/  )| |   (_)|   | || | |(_)\n"
            "(_)\\/  ||  __  ||   (  (_) |   | || |\\  || | | |\n"
            "| \\  / || |  |)|| |\\ \\   | |   | || | |)|\\ `-' /\n"
            "| |\\/| ||_|  (_)|_| \\)\\  `-'   `-'/(  (_) )---'\n"
            "'-'  '-'            (__)         (__)    (_)"<<endl<<endl;
}