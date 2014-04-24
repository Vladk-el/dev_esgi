/*
	Vladk
	Theorie
	How to create a public RSA KEY
*/

/*
	Tout d'abord choisissez deux nombres premiers : P et Q.
	On prend P = 53 et Q = 97 pour notre exemple.

	Ensuite, déterminez un nombre N tel que N = P * Q.
	Ici N = 5141.

	Calculons maintenant le nombre M, appelé "indicatrice d'Euler", qui correspond au nombre d'entiers naturels <= à N qui lui osnt premiers.
	M = (P - 1) * (Q - 1)
	Ici M = 4992.

	Il ne nous reste plus qu'à choisir un nombre C, qui doit être premier avec M.
	Ici on prend 7.

	Au final, notre clé est composée de (M, C). 
	Dans notre cas, notr eclé publique est (M = 5141, C = 7).



*/