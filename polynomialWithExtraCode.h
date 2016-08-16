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

bool compare(Monomial a, Monomial b){
	return (a.getPow() > b.getPow());
}


class Polynomial{
	friend Polynomial operator+(Polynomial &a, Polynomial &b);
	friend Polynomial operator-(Polynomial &a, Polynomial &b);
	//friend Polynomial operator*(Polynomial &a, Polynomial &b);
	//friend Polynomial operator/(Polynomial &a, Polynomial &b);
	public: 
		Polynomial(string s); //Polynomial constructor with string parameter
		list<Monomial> getP();
		void setP(string s);
		void setP(list<Monomial> p2);
		string plusMinus(string s); // method that changes all the minus signs to +-
		void buildList(string s); //turns each piece of the string into monomials and put it into the Polynomial
		void checkP();
		list<Monomial>::iterator it;
		Monomial sum(Monomial a, Monomial b);
		string print(); // method to print a polynomial in readable format
	private:
		list<Monomial> p;
};

//redefining the operators
Polynomial operator+(Polynomial &a, Polynomial &b){
	Monomial m ("0x^0");
	Monomial n ("0x^0 ");
	list<Monomial> c;
	Polynomial polyc ("0x^0");
	list<Monomial>::iterator ita;
	list<Monomial>::iterator itb;
	list<Monomial>::iterator itc;
	
	list<Monomial> ap = a.getP();
	list<Monomial> bp = b.getP();
	itb = bp.begin();
	for(ita = ap.begin(); ita!=ap.end(); ++ita){
		if((*ita).getPow() == (*itb).getPow()){
			m.setCoeff((*ita).getCoeff() + (*itb).getCoeff());
			m.setPow((*ita).getPow());
			c.push_back(m);
			polyc.setP(c);
			itb++;
		}
		
	}
	//cout<<polyc.print()<<endl;
	
	return polyc;
	
			/*while(ita!=ap.end() || itb!=bp.end()){
			if((*ita).getPow() > (*itb).getPow()){
				c.push_back((*ita));
				ita++;
				cout << "a was bigger" << endl;
			}
			else if((*ita).getPow() == (*itb).getPow()){
				m.setCoeff((*ita).getCoeff() + (*itb).getCoeff());
				m.setPow((*ita).getPow());
				c.push_back(m);
				polyc.setP(c);
				itb++;
				ita++;
				//cout << "they were the same" << endl;
			}
			else if((*ita).getPow() < (*itb).getPow()){
				c.push_back((*itb));
				itb++;
				cout << "b was bigger" << endl;
			}
			
			/*if(ita!=ap.end() && itb == bp.end()){
				itb--;
			}
			else if(ita==ap.end() && itb != bp.end()){
				ita--;
			}
		}*/
}


//constructor
Polynomial::Polynomial(string s){
	string s2 = plusMinus(s);
	buildList(s2);
	checkP();
	p.sort(compare);
	//checkP();
}

//getter
list<Monomial> Polynomial::getP(){
	return p;
}

//setters
void Polynomial::setP(string s){
	string s2 = plusMinus(s);
	buildList(s2);
	p.sort(compare);
}
void Polynomial::setP(list<Monomial> p2){
	list<Monomial>::iterator it;
	while(!p.empty()){
		p.pop_front();
	}
	for(it = p2.begin(); it != p2.end(); it++){
		p.push_back((*it));
	}
}

//changing all of the - signs in the string to +-
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

//converting the string to a list of monomials called p
void Polynomial::buildList(string s){
	int x = 0;
	int y = 0;
	while (x !=s.length()){
		Monomial m (s.substr(y,s.find('+', x))); //create a monomial from the substring starting at y and ending at the first plus after x
		p.push_back(m); //push the newly made monomial onto the list p
		if (s.find('+', x) <= s.length() ){
			x = s.find('+', x) + 1; //update x and y to be after the previously used +
			y = x;
		}
		else {
			x = s.length();//exit the loop
		}	
	}

}

//checking for and combining terms with the same powers, also getting rid of zeroes.
void Polynomial::checkP(){
	
	Monomial m ("0x^0");
	list<Monomial> mList;
	list<Monomial>toSum;
	list<Monomial>::iterator it2;
	
	//it = p.begin();
	it2 = p.begin();
	
	for(it = p.begin(); it2!=p.end(); ++it){
		++it2;
		if((*it).getPow() != (*it2).getPow()){
			mList.push_back((*it));

		}
		else{
			Monomial temp ("0x^0");
			temp = sum(temp, (*it));
			while((*it).getPow() == (*it2).getPow()){
				temp = sum(temp, (*it2));
				++it2;
				++it;
			}
			mList.push_back(temp);
			
		}
	}
	
	setP(mList);
	for(it = p.begin(); it!=p.end(); ++it){
		if((*it).getCoeff() == 0){
			it = p.erase(it);
		}
	}
	
	/*it = p.begin();
	while(it!=p.end()){
		temp.setCoeff((*it).getCoeff());
		temp.setPow((*it).getPow());
		++it;
		if(temp.getPow() != (*it).getPow()){
			mList.push_back(temp);
		}
		else{
			toSum.push_back(temp);
			
			
			
		}
		
	}
	setP(mList);

	for(it = p.begin(); it!=p.end(); ++it){
		it2 = it;
		for(++it2; it2!=p.end(); ++it2){
			if((*it).getPow() == (*it2).getPow()){
				cout<<"Hello" <<(*it).print()<<endl;
				m.setCoeff((*it).getCoeff() + (*it2).getCoeff());
				m.setPow((*it).getPow());
				
				p.push_back(m);
				it = p.erase(it);
				it2 = p.erase(it2);
				
			}
		}
	}*/

}

//method used in the check to sum temp with the monomials that have the same power
//can't use the regular monomial + operator because temp does not always have the same power as the other monomials it's being added to
Monomial Polynomial::sum(Monomial a, Monomial b){
	Monomial c ("0x^0");
	c.setCoeff(a.getCoeff()+b.getCoeff());
	c.setPow(b.getPow()); //we want the new monomial's power, not temp's
	cout << c.print() << endl;
	return c;
}
	
	
//printing the polynomial
string Polynomial::print(){

	it =p.begin();
	string polynomial = " ";
	ostringstream oss;
	oss << (*it).print();
	for(++it; it!=p.end(); ++it){
		oss<< " + " << (*it).print();
	}
	//cout << (*it).print() << endl;
		polynomial = oss.str();
		return polynomial;
}	


