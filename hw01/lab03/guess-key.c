#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/aes.h>
#define KEYSIZE 16
void guess_key(char *input, int t);

int main(){

	unsigned char *p = "255044462d312e350a25d0d4c5d80a34";
	unsigned char *iv = "09080706050403020100A2B2C2D2E2F2";
	unsigned char *c = "d06bf9d0dab8e8ef880660d2af65aa82";
	char guess;
	int end = 1524006529;
	int start = end - 7200;

	for(int i = end; i >= start; i--) {
		guess_key(&guess, i);
		//printf("key=%s\n", guess);
	}
	
	return 0;
}

void guess_key(char *input, int t){
	int i;
	char key[KEYSIZE];

	srand(t); 
	
	for (i = 0; i< KEYSIZE; i++){
		key[i] = rand()%256;
		//printf("%.2x", (unsigned char)key[i]);
  	}

	key[KEYSIZE+1] = '\0';
	input = &key[0];
	//printf("\n");
	printf("input=%.2x\n", (unsigned char*)input);
}
