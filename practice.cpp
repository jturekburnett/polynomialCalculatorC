
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <list>
#include "monomials.h"
using namespace std;

int main(){
	//char c[10] = "5ow is";
	string s = "5x^2 - 3x^5 + 2x^7";
	string::iterator it;
	for(it = s.begin(); it <s.end(); it++){
		if(*it == '-'){
			//cout << '+' << endl;
			s.erase(it+1);
			s.insert(it, '+');
			it++;
			cout << s << endl;
		}
	}
	cout << s.find('-', 0) << endl;
	cout << s.find('+', 0)<<endl;
	cout << s.length() << endl;
//	int y = s.find('+', 0);
//	s.insert(y, '-'.c_str());
//	cout << s << endl;

	int x = 0;
	int y = 0;
	while (x !=s.length()){
		if (s.find('+', x) <= s.length() ){
			cout << '+' << endl;
			//string a = s.substr(y,s.find(x));
			Monomial m (s.substr(y,s.find(x)));
			x = s.find('+', x) + 1;
			y = x;
		}
	//	if (s.find ('-', x) <= s.length() ){
	//		cout << '-' << endl;
	//		x = s.find('-', x) +1;
	//	}
		else {
			x = s.length();
		}
		
	}
	Monomial m(s.substr(0, s.find('+', 0)-1));
	cout << m.print();
	
	//int length = strlen(c);
	//for (int i = 0; i < strlen(s); i++){
		//int n = atoi(s.c_str());
		//cout << n << endl;
	//}
	list<Monomial> L;
	x = 0;
	y = 0;
	while (x !=s.length()){
		if (s.find('+', x) <= s.length() ){
			Monomial m (s.substr(y,s.find(x)));
			L.push_back(m);
			x = s.find('+', x) + 1;
			y = x;

		}
		else {
			x = s.length();
		}
		
	}

}