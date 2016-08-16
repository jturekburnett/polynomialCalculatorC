//Polynomial Arithmetic Project

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <algorithm>
#include "monomials.h"
using namespace std;

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

