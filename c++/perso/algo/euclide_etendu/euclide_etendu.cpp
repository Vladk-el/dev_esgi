/*
	Vladk
	algo
	Extended Euclidean algorithm (PGCD extend)
*/

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char ** argv){
	int a, b, r, rp, rs, u, up, us, v, vp, vs, q;

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

	// Init
	r = a;
	rp = b;
	u = 1;
	v = 0;
	up = 0;
	vp = 1;

	while(rp != 0){
		q = r / rp;

		rs = r;
		us = u;
		vs = v;

		r = rp;
		u = up;
		v = vp;

		rp = rs - (q * rp);
		up = us - (q * up);
		vp = vs - (q * vp);

		cout << "R : " << r << " U : " << u << " V : " << v << endl;
	}

	cout << "FINAL : R : " << r << " U : " << u << " V : " << v << endl;

	return 0;
}























