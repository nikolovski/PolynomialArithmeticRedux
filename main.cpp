#include <iostream>
#include <fstream>
#include <sstream>
#include "Polynomial.h"

using namespace std;
int count_polynomials(string);
void print_header(ofstream&);
int main(int argc,char *argv[]) {
    if(argc!=3) {
        cout<<"Please enter file as an input parameter containing polynomials. It is recommended that the full directory"
                "+ filename + extension is entered and the output file name."<<endl;
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
    ofstream outfile (argv[2]);
    print_header(outfile);
    for (int i = 0; i < poly_count; ++i) {
        outfile<<"Polynomial "<<(i+1)<<":"<<endl;
        outfile<<polynomials[i];
        outfile<<endl<<endl;
    }

    //Polynomial operations
    for (int j = 0; j < poly_count; j+=2) {
        //addition
        outfile<<"Polynomial "<<(j+1)<<" + Polynomial "<<(j+2)<<":"<<endl;
        outfile<<(polynomials[j]+polynomials[j+1]);
        outfile<<endl<<endl;
        //subtraction
        outfile<<"Polynomial "<<(j+1)<<" - Polynomial "<<(j+2)<<":"<<endl;
        outfile<<(polynomials[j]-polynomials[j+1]);
        outfile<<endl<<endl;
        //multiplication
        outfile<<"Polynomial "<<(j+1)<<" * Polynomial "<<(j+2)<<":"<<endl;
        outfile<<(polynomials[j]*polynomials[j+1]);
        outfile<<endl<<endl;
    }
    outfile.close();
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

void print_header(ofstream& out){
    out<<"Polynomial Arithmetic Redux provided by\n"
            "          .--.  ,---.  _______ ,-..-. .-. .---.\n"
            "|\\    /| / /\\ \\ | .-.\\|__   __||(||  \\| |/ .-. )\n"
            "|(\\  / |/ /__\\ \\| `-'/  )| |   (_)|   | || | |(_)\n"
            "(_)\\/  ||  __  ||   (  (_) |   | || |\\  || | | |\n"
            "| \\  / || |  |)|| |\\ \\   | |   | || | |)|\\ `-' /\n"
            "| |\\/| ||_|  (_)|_| \\)\\  `-'   `-'/(  (_) )---'\n"
            "'-'  '-'            (__)         (__)    (_)"<<endl<<endl;
}