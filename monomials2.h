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

string Monomial::print(){
	string s = " ";
	ostringstream oss;
	oss << coeff << 'x'<< '^' << pow;
	s = oss.str();
	return s;
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



class Polynomial{
	public: 
		Polynomial(string s); //Polynomial constructor with string parameter
		string plusMinus(string s); // method that changes all the minus signs to +-
		void buildList(string s); //turns each piece of the string into monomials and put it into the Polynomial
	
		string print(); // method to print a polynomial in readable format
	private:
		list<Monomial> p;
};

Polynomial::Polynomial(string s){
	string s2 = plusMinus(s);
	buildList(s2);
}

string Polynomial::plusMinus(string s){
	string::iterator it;
	for(it = s.begin(); it <s.end(); it++){
		if(*it == '-'){
			s.erase(it+1);
			s.insert(it, '+');
			it++;
		}
	}
	return s;
}

void Polynomial::buildList(string s){
	int x = 0;
	int y = 0;
	while (x !=s.length()){
		if (s.find('+', x) <= s.length() ){
			Monomial m (s.substr(y,s.find(x)));
			p.push_back(m);
			x = s.find('+', x) + 1;
			y = x;
		}
		else {
			x = s.length();
		}	
	}
}

string Polynomial::print(){
	//list<Monomial>::iterator it;
	//it =p.begin();
	string polynomial = "hello";
	//ostringstream oss;
	//oss << *it;
	//for(it = p.begin()+1; it<p.end(); it++){
	//	oss<< '+' << *it;
	//}
	//	polynomial = oss.str();
		return polynomial;
}	

