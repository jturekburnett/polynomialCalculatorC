//Polynomial Arithmetic Project

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <algorithm>
using namespace std;

class Monomial {
	public: 
		Monomial(string s); //Monomial constructor with string parameter
		//getters
		int getCoeff();
		char getVar();
		int getPow();
		//setters
		void setCoeff(int c);
		void setVar(char v);
		void setPow(int p);
		string print(); // method to print a monomial in readable format
	private:
		int coeff; //represents the coefficient of the monomial
		char var; //represents the variable of the monomial
		int pow; //represents the degree of the monomial
};

Monomial::Monomial(string s) {
	int i = s.find('x', 0);
	string temp = s.substr(0, i);//the problem was it needed the c string, not the c++ string
	coeff = atoi(temp.c_str());
	var = 'x';
	pow = atoi (s.substr(i+2, s.size()).c_str());
}

int Monomial::getCoeff(){
	return coeff;
}
	
char Monomial::getVar(){
	return var;
}

int Monomial::getPow(){
	return pow;
}

void Monomial::setCoeff(int c){
	coeff = c;
}

void Monomial::setVar(char v){
	var = v;
}

void Monomial::setPow(int p){
	pow = p;
}

string Monomial::print(){
	string s = " ";
	ostringstream oss;
	oss << coeff << 'x'<< '^' << pow;
	s = oss.str();
	return s;
}
