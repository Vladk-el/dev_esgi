/*
	Vladk
	algo
	Euclidean algorithm (PGCD)
*/

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char ** argv){

	int a, b, r, last;

	if(argc < 3){
		cout << "You must specify at least 2 integer arguments" << endl;
		return 1;
	}

	istringstream s1(argv[1]);
	istringstream s2(argv[2]);

	if (!(s1 >> a) || !(s2 >> b)){
		cout << "You must specify at least 2 INTEGER arguments" << endl;
		return 1;
	}

	if(a < b){
		r = a;
		a = b;
		b = r;
	}

	while(a % b != 0){
		r = a % b;
		a = b; 
		b = r;
	}

	cout << "PGCD of " << argv[1] << " and " << argv[2] << " : " << r << endl;

	return 0;
}