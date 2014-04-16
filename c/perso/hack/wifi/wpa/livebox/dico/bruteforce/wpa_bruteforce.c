#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>

char getCurrentChar(int pos, char c);

int main(int argc, char * args[]){
	printf("hello wpa_bruteforce\n");
	int BUF_SIZE = 27, CHAR_SIZE = 16, desc;
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
	char buffer[] = "00000000000000000000000000\n\0";

	if(argc != 2){
		write(STDERR_FILENO, "Only one argument please\n", 25); // sortie d'erreur
		exit(2); // fin du programme
	}

	remove(args[1]);

	desc = open(args[1], O_WRONLY | O_APPEND | O_CREAT, 0777);

	if(desc < 0){
		perror("Erreur d'ouverture du fichier");
		exit(2);
	}

	

	for(a = 0; a < CHAR_SIZE; a++){
		for(b = 0; b < CHAR_SIZE; b++){
			for(c = 0; c < CHAR_SIZE; c++){
				for(d = 0; d < CHAR_SIZE; d++){
					for(e = 0; e < CHAR_SIZE; e++){
						for(f = 0; f < CHAR_SIZE; f++){
							for(g = 0; g < CHAR_SIZE; g++){
								for(h = 0; h < CHAR_SIZE; h++){
									for(i = 0; i < CHAR_SIZE; i++){
										for(j = 0; j < CHAR_SIZE; j++){
											for(k = 0; k < CHAR_SIZE; k++){
												for(l = 0; l < CHAR_SIZE; l++){
													for(m = 0; m < CHAR_SIZE; m++){
														for(n = 0; n < CHAR_SIZE; n++){
															for(o = 0; o < CHAR_SIZE; o++){
																for(p = 0; p < CHAR_SIZE; p++){
																	for(q = 0; q < CHAR_SIZE; q++){
																		for(r = 0; r < CHAR_SIZE; r++){
																			for(s = 0; s < CHAR_SIZE; s++){
																				for(t = 0; t < CHAR_SIZE; t++){
																					for(u = 0; u < CHAR_SIZE; u++){
																						for(v = 0; v < CHAR_SIZE; v++){
																							for(w = 0; w < CHAR_SIZE; w++){
																								for(x = 0; x < CHAR_SIZE; x++){
																									for(y = 0; y < CHAR_SIZE; y++){
																										for(z = 0; z < CHAR_SIZE; z++){
																											write(desc, buffer, BUF_SIZE);
																											buffer[25] = getCurrentChar(z, buffer[25]);
																										}
																										buffer[25] = '0';
																										buffer[24] = getCurrentChar(y, buffer[24]);
																									}
																									buffer[24] = '0';
																									buffer[23] = getCurrentChar(x, buffer[23]);
																								}
																								buffer[23] = '0';
																								buffer[22] = getCurrentChar(w, buffer[22]);
																							}
																							buffer[22] = '0';
																							buffer[21] = getCurrentChar(v, buffer[21]);
																						}
																						buffer[21] = '0';
																						buffer[20] = getCurrentChar(u, buffer[20]);
																					}
																					buffer[20] = '0';
																					buffer[19] = getCurrentChar(t, buffer[19]);
																				}
																				buffer[19] = '0';
																				buffer[18] = getCurrentChar(s, buffer[18]);
																			}
																			buffer[18] = '0';
																			buffer[17] = getCurrentChar(r, buffer[17]);
																		}
																		buffer[17] = '0';
																		buffer[16] = getCurrentChar(q, buffer[16]);
																	}
																	buffer[16] = '0';
																	buffer[15] = getCurrentChar(p, buffer[15]);
																}
																buffer[15] = '0';
																buffer[14] = getCurrentChar(o, buffer[14]);
															}
															buffer[14] = '0';
															buffer[13] = getCurrentChar(n, buffer[13]);
														}
														buffer[13] = '0';
														buffer[12] = getCurrentChar(m, buffer[12]);
													}
													buffer[12] = '0';
													buffer[11] = getCurrentChar(l, buffer[11]);
												}
												buffer[11] = '0';
												buffer[10] = getCurrentChar(k, buffer[10]);
											}
											buffer[10] = '0';
											buffer[9] = getCurrentChar(j, buffer[9]);
										}
										buffer[9] = '0';
										buffer[8] = getCurrentChar(i, buffer[8]);
									}
									buffer[8] = '0';
									buffer[7] = getCurrentChar(h, buffer[7]);
								}
								buffer[7] = '0';
								buffer[6] = getCurrentChar(g, buffer[6]);
							}
							buffer[6] = '0';
							buffer[5] = getCurrentChar(f, buffer[5]);
						}
						buffer[5] = '0';
						buffer[4] = getCurrentChar(e, buffer[4]);
					}
					buffer[4] = '0';
					buffer[3] = getCurrentChar(d, buffer[3]);
				}
				buffer[3] = '0';
				buffer[2] = getCurrentChar(c, buffer[2]);
			}
			buffer[2] = '0';
			buffer[1] = getCurrentChar(b, buffer[1]);
		}
		buffer[1] = '0';
		buffer[0] = getCurrentChar(a, buffer[0]);
	}
	
	close(desc);

	return(0);

}

char getCurrentChar(int pos, char c){
	//printf("%c \n", c);
	if(pos == 9){
		c = c + 8;
	}
	else{
		c = c + 1;
	}
	return c;
}


/*buffer[0] = '0';
	buffer[1] = '0';
	buffer[2] = '0';
	buffer[3] = '0';
	buffer[4] = '0';
	buffer[5] = '0';
	buffer[6] = '0';
	buffer[7] = '0';
	buffer[8] = '0';
	buffer[9] = '0';
	buffer[10] = '0';
	buffer[11] = '0';
	buffer[12] = '0';
	buffer[13] = '0';
	buffer[14] = '0';
	buffer[15] = '0';
	buffer[16] = '0';
	buffer[17] = '0';
	buffer[18] = '0';
	buffer[19] = '0';
	buffer[20] = '0';
	buffer[21] = '0';
	buffer[22] = '0';
	buffer[23] = '0';
	buffer[24] = '0';
	buffer[25] = '0';
	buffer[26] = '\n';
	buffer[27] = '\0';*/




