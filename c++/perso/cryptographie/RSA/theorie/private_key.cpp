/*
	Vladk
	Theorie
	How to create a private RSA KEY
*/

/*
	On part de notre clé publique (M = 5141, C = 7), N = 5141.
	
	Nous avons besoin d'un nombre U tel que C * U + M * V = 1
	Pour le générer, on utilise un outil pratique : bezout.

	Installation : (ne marche pas sous mac)
		cd ~/bin
		mkdir RSA
		cd RSA
		curl http://ftp.sunet.se/pub/gnu/gmp/gmp-4.2.2.tar.gz -o "gmp-4.2.2.tar.gz"
		tar xfz gmp-4.2.2.tar.gz
		cd gmp-4.2.2
		./configure --enable-cxx
		make
		make check
		sudo make install
		cd ..
		rm gmp-4.2.2 gmp-4.2.2.tar.gz
		cd /usr/lib/
		sudo ln -s /usr/local/lib/libgmpxx.so.4 libgmpxx.so.4
		cd ~/RSA
		wget http://tuxweb79.free.fr/Bezout_linux.zip
		unzip Bezout_linux.zip
		cd Bezout
		make
		chmod +x bezout


*/

