//Polynomial Arithmetic Project

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <algorithm>
#include "polynomial.h"
//#include "monomials.h"
using namespace std;
	
int main() {
	//Monomial *mpoint;
	//Monomial *npoint;
	Monomial m ("-3x^2");
	Monomial n ("5x^2");
	//mpoint = &m;
	//mpoint = &n;
	/*cout << "coeff = " << m.getCoeff() << endl;
	cout << "pow = " << m.getPow() << endl;
	cout << m.print()<<endl;*/
	//cout << m + n << endl;
	
	Polynomial *ppoint;
	Polynomial *ppoint2;
	Polynomial poly ("5x^2 - 3x^5 + 2x^7 + 7x^7 + 7x^7 - 8x^4 + 5x^12 + 9x^12 + 0x^3");
	Polynomial poly2 ("4x^2 - 3x^5 + 2x^7 + 7x^7 - 8x^4 + 5x^12 ");
	ppoint = &poly;
	ppoint2 = &poly2;
	
	Polynomial poly3 ("5x^2 - 3x^5 + 0x^3");
	Polynomial poly4 ("2x^7 + 7x^7 - 8x^4");
	
	/*cout<<"changing signs"<<endl;
	cout << "original: " << n.print() <<endl;
	cout << "new: ";
	n.changeSign();
	cout << n.print() << endl;*/
	
	cout << "Poly 1: "<<poly.print()<<endl;
	cout<<endl;
	
	cout << "Poly 2: "<<poly2.print()<<endl;
	cout<<endl;
	
	cout << "Poly 3: "<<poly3.print()<<endl;
	cout<<endl;
	
	cout << "Poly 4: "<<poly4.print()<<endl;
	cout<<endl;
	
	cout<<"sum" << endl;
	cout << (poly+poly2).print()<<endl;
	//cout<< (m+n).print() << endl;
	cout<<endl;
	
	cout << "difference" <<endl;
	cout << (poly-poly2).print()<<endl;
	cout<<endl;
	
	cout << "product" <<endl;
	cout << (poly3*poly4).print()<<endl;
}