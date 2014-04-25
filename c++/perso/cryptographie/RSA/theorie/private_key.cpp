/*
	Vladk
	Theorie
	How to create a private RSA KEY
*/

/*
	On part de notre clé publique (M = 5141, C = 7), N = 5141.

	Un mathématicien, du nom d'Etienne Bézout, a démontré que deux nombres a et b sont premiers entre eux, 
	si et seulement s'il existe des solutions u et v telles que 
		a×u+b×v=1 (u et v étant des nombres entiers). 
	Or, on a dit peu avant que C et M devaient être premiers entre eux. 
	Il existe donc deux nombres entiers u et v qui répondent à l'équation.
	
	Nous avons besoin d'un nombre U tel que C * U + M * V = 1 (on ne se servira pas de V)
	Attention : l'algorithme du système RSA a besoin d'un U tel que 2<U<M

	Pour le générer, on utilise un outil pratique : bezout (voir installation plus bas).

	./bezout -rsa 7 4992
	4279

	On retient U = 4279. Notre clé privée est donc : (U = 4279, N = 5141)

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

	Pour ceux qui rencontrent des difficultés, nous allons recoder bezout - rsa par la suite, en c++.

*/

