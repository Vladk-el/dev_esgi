/*
	Vladk
	MPZ
	Simple example of the mpz_fdiv_qr() function, that allows a division and retrieve all the pieces
*/


#include <iostream>
#include <gmpxx.h>

using namespace std;

int main (int argc, char ** argv){

	mpz_class dividende(35), diviseur(15), quotient, reste;

	mpz_fdiv_qr(quotient.get_mpz_t(), reste.get_mpz_t(), dividende.get_mpz_t(), diviseur.get_mpz_t());

	cout << dividende << " = " << quotient << " x " << diviseur;
	cout << " + " << reste << endl;

	return 0;
}