#include <iostream>
#include <gmpxx.h>

using namespace std;

int main(int argc, char ** argv){

	string nombre("35");

	mpz_class a(16), b(nombre), c;

	cout << "le nombre a vaut : " << a << endl;
	cout << "le nombre b vaut : " << b << endl;
	cout << "le nombre c vaut : " << c << endl;

}

//g++ -o mpz_class mpz_class.cpp -lgmpxx -lgmp